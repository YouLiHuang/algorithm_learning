#include "hashListMap.h"

Pair *newPair(const int key, char *val)
{
    Pair *p = (Pair *)malloc(sizeof(Pair));
    if (p != NULL)
    {
        p->key = key;
        p->value = val;
        p->node = newNode(p);
        p->node->parent = p;
    }
    return p;
}

/*创建一张哈希表*/
HashlistMap *newHashMap()
{
    HashlistMap *map = (HashlistMap *)malloc(sizeof(HashlistMap));

    for (int i = 0; i < CAPACITY; i++)
    {
        map->Map[i] = NULL;
    }
    map->length = 0;
    return map;
}

/*销毁一张表*/
void deleteHashMap(HashlistMap *map)
{
    for (int i = 0; i < CAPACITY; i++)
    {
        if (map->Map[i] != NULL)
        {
            Node *node = map->Map[i]->node;
            /*释放所有节点*/
            while (node->next != node)
            {
                Node *tmp = node;
                node = node->next;

                Pair *parent = (Pair *)tmp->parent;
                free(parent->value);
                parent->value = NULL;

                free(tmp);
                tmp = NULL;

                free(parent);
                parent = NULL;
            }
            /*尾节点*/
            Pair *parent = (Pair *)node->parent;
            free(parent->value);
            parent->value = NULL;
            free(node);
            node = NULL;
            free(parent);
            parent = NULL;
        }
    }
}

/*销毁一个set*/
void deleteSet(HashSet *hset)
{

    if (hset != NULL)
    {
        if (hset->set != NULL)
        {
            free(hset->set);
            hset->set = NULL;
        }
        free(hset);
        hset = NULL;
    }
}

void put(HashlistMap *map, const int key, char *value)
{
    int index = HASHINDEX(key);
    Pair *entry = newPair(key, value);
    entry->value = (char *)malloc(sizeof(value) + 1);
    strcpy(entry->value, value);
    entry->key = key;

    if (map->Map[index] == NULL)
    {
        map->Map[index] = entry;
        map->length++;
    }
    else
    {
        insertNode(map->Map[index]->node, entry->node);
        map->length++;
    }
}

Pair *get(HashlistMap *map, const int key)
{
    int index = HASHINDEX(key);

    Pair *p = map->Map[index];
    if (p != NULL)
    {
        while (p->key != key)
        {
            Node *node = p->node->next;
            p = (Pair *)node->parent;
        }

        return p;
    }
}

void removePair(HashlistMap *map, const int key)
{
    int index = HASHINDEX(key);

    Pair *p = map->Map[index];
    if (p != NULL)
    {
        while (p->key != key)
        {
            Node *node = p->node->next;
            p = (Pair *)node->parent;
        }

        Node *preNode = p->node->pre;
        Node *node = p->node;
        Node *nextNode = p->node->next;

        /*最后节点*/
        if (node == nextNode)
        {
            preNode->next = preNode;
            node->pre = node;
        }
        /*最初节点*/
        else if (node == preNode)
        {
            map->Map[index] = (Pair *)node->next->parent;
            node->next = node;
            nextNode->pre = nextNode;
        }
        /*中间节点*/
        else
        {

            preNode->next = nextNode;
            nextNode->pre = preNode;
            node->pre = node;
            node->next = node;
        }

        map->length--;
    }
}

HashSet *valueSet(HashlistMap *map)
{

    HashSet *hset = (HashSet *)malloc(sizeof(HashSet));
    char **val = (char **)malloc(sizeof(char *) * map->length);

    static int index;
    /*遍历整张表*/
    for (size_t i = 0; i < CAPACITY; i++)
    {
        Pair *p = map->Map[i];
        if (p != NULL)
        {
            /*获取值*/
            val[index++] = p->value; // 头节点
            /*遍历链表*/
            while (p != p->node->next->parent)
            {
                // 其他节点
                p = p->node->next->parent;
                val[index++] = p->value;
            }
        }
    }

    hset->set = val;
    hset->len = map->length;

    return hset;
}

HashSet *keySet(HashlistMap *map)
{
    HashSet *hset = (HashSet *)malloc(sizeof(HashSet));
    int *val = (int *)malloc(sizeof(int) * map->length);

    static int index;
    /*遍历整张表*/
    for (size_t i = 0; i < CAPACITY; i++)
    {
        Pair *p = map->Map[i];
        if (p != NULL)
        {
            /*获取值*/
            val[index++] = p->key; // 头节点
            /*遍历链表*/
            while (p != p->node->next->parent)
            {
                // 其他节点
                p = p->node->next->parent; // 从节点获取关联的对象
                val[index++] = p->key;
            }
        }
    }

    hset->set = val;
    hset->len = map->length;

    return hset;
}

void printHashList(HashlistMap *map)
{
    for (size_t i = 0; i < CAPACITY; i++)
    {
        if (map->Map[i] != NULL)
        {
            Pair *p = map->Map[i];
            if (p != NULL)
            {

                printf("key : %d --> value : %s \r\n", p->key, p->value); // 其他节点
                /*遍历链表*/
                while (p != p->node->next->parent)
                {
                    // 其他节点
                    p = p->node->next->parent;
                    printf("key : %d --> value : %s \r\n", p->key, p->value);
                }
            }
        }
    }
}

int main()
{

    HashlistMap *listMap = newHashMap();
    put(listMap, 114514, "zhangsan");
    put(listMap, 114614, "lisi");
    put(listMap, 100086, "wangwu");

    // Pair *p = get(listMap, 114614);
    // printf("pairs key: %d -->value : %s\r\n", p->key, p->value);

    printHashList(listMap);
    printf("------remove test-------\r\n");
    removePair(listMap, 114514);
    printHashList(listMap);

    printf("--------value set-------\r\n");
    HashSet *vals = valueSet(listMap);
    char **str = (char **)vals->set;
    for (size_t i = 0; i < vals->len; i++)
    {
        printf("value : %s\r\n", str[i]);
    }
    deleteSet(vals);

    printf("---------key set--------\r\n");
    HashSet *keys = keySet(listMap);
    int *k = (int *)vals->set;
    for (size_t i = 0; i < vals->len; i++)
    {
        printf("key : %d\r\n", k[i]);
    }
    deleteSet(keys);

    deleteHashMap(listMap);

    return -1;
}
