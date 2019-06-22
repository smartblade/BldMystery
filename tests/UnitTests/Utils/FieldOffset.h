#ifndef FIELD_OFFSET_H

#define FIELD_OFFSET_H

static void *FieldOffset(size_t offset)
{
    return (void *)offset;
}

#define EXPECT_OFFSET_EQ(clsname, field, offset) \
{\
    clsname *o = NULL; \
    EXPECT_EQ(&o->field, FieldOffset(offset)); \
}

#endif /* FIELD_OFFSET_H */
