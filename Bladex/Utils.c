
#include "bladex_int.h"


typedef struct {
        int first_element;
        int num_elements;
        unsigned char symbol;
        int next;
} property_tree_node_t;


static void init_properties(void);
static int get_new_property_index(
        property_info_t *properties, char *name, int num
);
static void shift_elements(
        property_info_t *properties, int from, int num_elements
);
static void make_tree(int first, int last);
static void make_sub_tree(int first, int last, int char_index, int *node_index);


property_info_t *property_kinds;

static int need_init_properties = TRUE;
static int root_node[256];
static property_tree_node_t tree_nodes[2000];
static int num_property_kinds = 0;


// address: 0x100190b0
void init_properties() {
        init_entity_properties();
        make_tree(0, num_property_kinds - 1);
        need_init_properties = FALSE;
}


// address: 0x100190d7
int insert_property(
        const char *name, int property_kind, int data_type, int flags,
        PyObject *(*get_func)(PyObject *, char *),
        int (*set_func)(PyObject *, char *, PyObject *)
) {
        int index;
        char *property_name;

        property_name = strdup(name);

        if (num_property_kinds < MAX_PROPERTY_KINDS) {

                index = get_new_property_index(
                        property_kinds, property_name, num_property_kinds
                );

                property_kinds[index].name = property_name;
                property_kinds[index].kind = property_kind;
                property_kinds[index].data_type = data_type;
                property_kinds[index].flags = flags;
                property_kinds[index].get_func = get_func;
                property_kinds[index].set_func = set_func;
                num_property_kinds++;
        }

        return 0;
}


// address: 0x100191e0
int get_new_property_index(property_info_t *properties, char *name, int num) {
        int index, compare_flag;

        index = 0;
        if (num > 0) {
                do {
                        compare_flag = strcmp(name, property_kinds[index].name);
                        index++;
                } while (compare_flag >= 0 && index < num);

                if (compare_flag < 0) {
                        index = index - 1;
                }

                shift_elements(properties, index, num - index);
        }

        return index;
}


// address: 0x100192ab
void shift_elements(property_info_t *properties, int from, int num_elements) {
        int i;

        i = from + num_elements - 1;
        while (i >= from) {
                property_kinds[i + 1] = property_kinds[i];
                i--;
        }
}


// address: 0x100192ff
void make_tree(int first, int last) {
        int i, node_index, cur_element;

        node_index = 0;

        for (i = 0; i < 256; i++)
                root_node[i] = -1;

        for (cur_element = first; cur_element <= last; cur_element++) {
                if (
                        cur_element < last &&
                        (
                                property_kinds[cur_element].name[0] !=
                                property_kinds[cur_element + 1].name[0]
                        )
                ) {
                        root_node[property_kinds[cur_element].name[0]] =
                                node_index;
                        make_sub_tree(first, cur_element, 1, &node_index);
                        first = cur_element + 1;
                } else if (cur_element >= last) {

                        root_node[property_kinds[cur_element].name[0]] =
                                node_index;
                        make_sub_tree(first, cur_element, 1, &node_index);
                }
        }
}


// address: 0x1001940a
void make_sub_tree(int first, int last, int char_index, int *node_index) {
        int cur_node;
        int cur_element;

        cur_element = first;
        while (cur_element <= last) {
                if (
                        cur_element < last &&
                        (
                                property_kinds[cur_element].name[char_index] ==
                                property_kinds[cur_element + 1].name[char_index]
                        )
                ) {
                        cur_element++;

                } else {

                        cur_node = *node_index;
                        tree_nodes[cur_node].first_element = first;
                        tree_nodes[cur_node].num_elements =
                                cur_element - first + 1;

                        tree_nodes[cur_node].symbol =
                                property_kinds[cur_element].name[char_index];
                        (*node_index)++;

                        if (char_index >= 4) {
                                tree_nodes[cur_node].next = 0;
                        } else {
                                if (
                                        (tree_nodes[cur_node].num_elements > 0)
                                         &&
                                        (tree_nodes[cur_node].symbol != '\0')
                                ) {
                                        make_sub_tree(
                                                first, cur_element,
                                                char_index + 1, node_index
                                        );
                                }
                                tree_nodes[cur_node].next = *node_index;
                        }
                        cur_element++;
                        first = cur_element;
                }
        }

        if (char_index < 4) {
                tree_nodes[*node_index].symbol = 255;
                (*node_index)++;
        }
}


// address: 0x10019563
int find_property(property_info_t *properties, const char *name) {
        char cur_char;
        int char_index, node_index, cur_element, i, last;

        if (need_init_properties)
                init_properties();

        node_index = root_node[name[0]];
        char_index = 1;

        if (node_index == -1)
                return -1;

        for (i = char_index; i < 4; i++) {
                cur_char = name[char_index];
                if (cur_char == '\0') {
                        if (tree_nodes[node_index].symbol == '\0')
                                return tree_nodes[node_index].first_element;
                        return -1;
                }

                while (cur_char > tree_nodes[node_index].symbol)
                        node_index = tree_nodes[node_index].next;

                if (cur_char != tree_nodes[node_index].symbol)
                        return -1;

                node_index++;
                char_index++;
        }

        cur_element = tree_nodes[node_index - 1].first_element;
        last = cur_element + tree_nodes[node_index - 1].num_elements;
        cur_char = name[char_index];

        while (cur_element < last) {

                while (cur_char == property_kinds[cur_element].name[char_index]) {
                        if (cur_char == '\0')
                                return cur_element;

                        char_index++;

                        cur_char = name[char_index];
                }

                if (cur_char < property_kinds[cur_element].name[char_index])
                        return -1;

                cur_element++;
        }

        return -1;
}

