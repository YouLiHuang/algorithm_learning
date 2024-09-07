#ifndef __LIST__H_
#define __LIST__H_

typedef struct Node
{
    int index;
    void *parent;
    struct Node *next;
    struct Node *pre;
} Node;

typedef struct List
{
    int length;
    struct Node *head;
    struct Node *tail;
} List;

List *newList();
Node *newNode(void *parent);
void deleteList(List *list);
/*尾部加入*/
void addNode(List *list, Node *node);
void addNodeIndex(List *list, Node *node, int index);
void insertNode(Node *head, Node *node);
Node *accessNode(List *list, int index);
void removeNode(List *list, Node *node, int index);



#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
}
#endif

#endif
