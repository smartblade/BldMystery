
#ifndef OCT_TREE_H

#define OCT_TREE_H


class B_Map;

class B_OctTree
{
public:
    void Build(const B_Map &map, double size);
    int field;
};

#endif /* OCT_TREE_H */
