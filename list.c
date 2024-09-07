#include "../utils/common.h"
#include "list.h"

List *newList()
{
    List *list = (List *)malloc(sizeof(List));
    list->length = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

Node *newNode(void * parent)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->index = 0;
    node->next = node;
    node->pre = node;
    node->parent = parent;
    return node;
}

void deleteList(List *list)
{
    Node *p = list->head;
    while (p != NULL)
    {
        if (p == list->tail)
        {
            free(p);
            p = NULL;
            break;
        }
        Node *tmp = p;
        p = p->next;
        free(tmp);
        tmp = NULL;
    }

    list->head = NULL;
    list->tail = NULL;
    free(list);
}

void addNodeIndex(List *list, Node *node, int index)
{

    Node *p = list->head;
    while (p->index != index)
    {
        p = p->next;
    }
    node->next = p->next;
    node->pre = p;
    p->next->pre = node;
    p->next = node;
    /*更新索引*/
    while (p != list->tail)
    {
        p->next->index++;
        p = p->next;
    }

    list->length++;
}

void removeNode(List *list, Node *node, int index)
{
    Node *p = list->head;
    while (p->index != index)
    {
        p = p->next;
    }

    p->pre->next = p->next;
    p->next->pre = p->pre;

    /*更新索引*/
    Node *tmp = p;
    while (tmp != list->tail)
    {
        tmp->next->index--;
        tmp = tmp->next;
    }
    tmp = NULL;

    p->next = p;
    p->pre = p;
    list->length--;
}

Node *accessNode(List *list, int index)
{
    Node *p = list->head;
    while (p->index != index)
    {
        p = p->next;
    }
    return p;
}

void addNode(List *list, Node *node)
{
    if (list->length == 0)
    {
        list->head = node;
        list->tail = node;
        node->next = node;
        node->pre = node;
        node->index = 0;
    }
    else
    {
        list->tail->next = node;
        node->next = list->head;
        node->pre = list->tail;
        list->tail = node;

        /*更新索引*/
        node->index = node->pre->index + 1;
    }
    list->length++;
}

void insertNode(Node *head, Node *node)
{
    head->next = node;
    node->pre = head;
    node->next = node;
}