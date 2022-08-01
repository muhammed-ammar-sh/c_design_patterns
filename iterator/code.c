/// @brief      List item structure
/// @details    Place as object heading
typedef struct _tsLdlItem
{
    struct _tsLdlItem *head; ///< Previous item in list
    struct _tsLdlItem *tail; ///< Next item in list
} tsLdlItem;

/// @brief      List structure
typedef struct
{
    tsLdlItem *head; ///< First item in list
    tsLdlItem *tail; ///< Last item in list
    uint32_t count;  ///< Item count for checking
} tsLdl;

typedef struct
{
    tsLdl *list;
    tsLdlItem *currentItem;
} list_iterator;

void Iterator_Init(list_iterator *iterator, tsLdl *list)
{
    iterator->list        = list;
    iterator->currentItem = list->head;
    for (int i = 0; i <= list->count / 2; i++)
        iterator->currentItem = iterator->currentItem->tail;
}

tsLdlItem *Iterator_Next(list_iterator *iterator)
{
    iterator->currentItem = iterator->currentItem->tail->tail;
    return iterator->currentItem;
}

bool Iterator_Done(list_iterator *iterator)
{
    return iterator->currentItem == NULL;
}

list_iterator iterator;
Iterator_Init(&iterator, &my_list);

for (tsLdlItem *item = Iterator_Next(&iterator); !Iterator_Done(&iterator); item = Iterator_Next(&iterator))
{
    item = Iterator_Next(&iterator);
}
