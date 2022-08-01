/**
 *  @file       list_dl.c
 *  @brief      Doubly Linked List structures
 *  @copyright  (c) 2018-Arcelik - All Rights Reserved
 *              Permission to use, reproduce, copy, prepare derivative works,
 *              modify, distribute, perform, display or sell this software and/or
 *              its documentation for any purpose is prohibited without the express
 *              written consent of Arcelik A.S.
 *  @author     Deniz Fer
 *  @date       19.10.2018
 */
#define FILE_LIST_DL_C

/** @addtogroup LIST_DL
 *  @{
 */

/*********************************************************************
 *  INCLUDES
 */
#include "list_dl.h"
//#include "version.h"

/*********************************************************************
 *  LOCAL CONSTANTS
 */

/*********************************************************************
 *  LOCAL TYPEDEFS
 */

/*********************************************************************
 *  LOCAL MACROS
 */

/*********************************************************************
 *  LOCAL VARIABLES
 */

/*********************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 */

/*********************************************************************
 *  INTERFACE FUNCTIONS
 */

void addListdlVersion()
{
    //ADD_RCOS_VERSION("lisdl", "2.0.0")
}


void ldlInsertAfter(tsLdl *list, void *item, void *newItem)
{
    tsLdlItem *liItem, *liNew;

    if (ldlHeadFrom(newItem) == list->head)
    {
        return; // This item is already in the list
    }

    liNew  = (tsLdlItem *)newItem;
    liItem = (tsLdlItem *)item;

    liNew->head = liItem;
    liNew->tail = liItem->tail;

    if (liItem->tail == NULL)
    {
        list->tail = liNew;
    }
    else
    {
        liItem->tail->head = liNew;
    }

    liItem->tail = liNew;
    list->count++;
}

void ldlInsertBefore(tsLdl *list, void *item, void *newItem)
{
    tsLdlItem *liItem, *liNew;

    if (ldlHeadFrom(newItem) == list->head)
    {
        return; // This item is already in the list
    }

    liNew  = (tsLdlItem *)newItem;
    liItem = (tsLdlItem *)item;

    liNew->head = liItem->head;
    liNew->tail = item;

    if (liItem->head == NULL)
    {
        list->head = newItem;
    }
    else
    {
        liItem->head->tail = newItem;
    }

    liItem->head = newItem;
    list->count++;
}

void ldlInsertHead(tsLdl *list, void *newItem)
{
    tsLdlItem *liNew;

    if (ldlHeadFrom(newItem) == list->head)
    {
        return; // This item is already in the list
    }

    liNew = (tsLdlItem *)newItem;

    if (list->head == NULL)
    {
        list->head  = newItem;
        list->tail  = newItem;
        liNew->head = NULL;
        liNew->tail = NULL;
        list->count++;
    }
    else
    {
        ldlInsertBefore(list, list->head, newItem);
    }
}

void ldlInsertTail(tsLdl *list, void *newItem)
{
    if (ldlHeadFrom(newItem) == list->head)
    {
        return; // This item is already in the list
    }

    if (list->tail == NULL)
    {
        ldlInsertHead(list, newItem);
    }
    else
    {
        ldlInsertAfter(list, list->tail, newItem);
    }
}

void ldlDelete(tsLdl *list, void *item)
{
    tsLdlItem *liItem;

    liItem = (tsLdlItem *)item;

    if (ldlHeadFrom(liItem) != list->head)
    {
        return; // This item is not in this list
    }

    if (liItem->head == NULL) // At head
    {
        list->head = liItem->tail;
    }
    else
    {
        liItem->head->tail = liItem->tail;
    }

    if (liItem->tail == NULL) // At tail
    {
        list->tail = liItem->head;
    }
    else
    {
        liItem->tail->head = liItem->head;
    }

    liItem->head = NULL;
    liItem->tail = NULL;
    list->count--;
}

void *ldlPopHead(tsLdl *list)
{
    tsLdlItem *retVal = list->head;

    list->head = retVal->tail;
    list->head->head = NULL;
    retVal->tail = NULL;
    list->count--;

    return retVal;
}

void *ldlPopTail(tsLdl *list)
{
    tsLdlItem *retVal = list->tail;

    list->tail = retVal->head;
    list->tail->tail = NULL;
    retVal->head = NULL;
    list->count--;

    return retVal;
}

void *ldlHeadFrom(void *item)
{
    tsLdlItem *liItem;

    for (liItem = (tsLdlItem *)item; liItem->head != NULL; liItem = liItem->head)
        ;

    return liItem;
}

void *ldlTailFrom(void *item)
{
    tsLdlItem *liItem;

    for (liItem = (tsLdlItem *)item; liItem->tail != NULL; liItem = liItem->tail)
        ;

    return liItem;
}

uint32_t ldlRecount(tsLdl *list)
{
    tsLdlItem *liItem;
    uint32_t count = 0;

    if (list->head != NULL)
    {
        for (count++, liItem = list->head; liItem->tail != NULL; liItem = liItem->tail, count++)
            ;
    }

    return count;
}

void *ldlItemAtIdx(tsLdl *list, uint32_t idx)
{
    if (idx >= list->count)
    {
        return NULL;
    }
    else
    {
        tsLdlItem *liItem;

        for (liItem = list->head; idx--; liItem = liItem->tail)
            ;

        return liItem;
    }
}

uint32_t ldlIdxOfItem(tsLdl *list, void *item)
{
    tsLdlItem *liItem;
    uint32_t idx = 0;

    for (liItem = list->head; liItem != NULL; liItem = liItem->tail)
    {
        if (liItem == item)
        {
            return idx;
        }
        idx++;
    }

    return -1;
}

/*********************************************************************
 *  LOCAL FUNCTIONS
 */

/** @} */
