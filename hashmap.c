#include "../utils/common.h"

#define CAPACITY 100

typedef struct pair
{
    int key;
    char *value;
} pair;

typedef struct HashMap
{
    pair *Map[CAPACITY];
} HashMap;

/*哈希键/值/键值对集合*/
typedef struct HashSet
{
    void *set;
    int len;
} HashSet;

int HashFunc(int key)
{
    return key % CAPACITY;
}

/*创建一张哈希表*/
HashMap *newHashMap()
{
    HashMap *map = malloc(sizeof(HashMap));

    for (int i = 0; i < CAPACITY; i++)
    {
        map->Map[i] = NULL;
    }

    return map;
}

/*销毁一张表*/
void deleteHashMap(HashMap *map)
{
    for (int i = 0; i < CAPACITY; i++)
    {
        if (map->Map[i] != NULL)
        {
            free(map->Map[i]->value);
            free(map->Map[i]);
        }
    }
}

const char *get(HashMap *map, const int key)
{
    int index = HashFunc(key);
    if (map->Map[index] != NULL)
    {
        return map->Map[index]->value;
    }
}

void put(HashMap *map, const int key, const char *value)
{
    int index = HashFunc(key);
    pair *entry = (pair *)malloc(sizeof(pair));
    entry->value = (char *)malloc(sizeof(value) + 1);
    strcpy(entry->value, value);
    entry->key = key;

    if (map->Map[index] == NULL)
    {
        map->Map[index] = entry;
    }
}

void removeHash(HashMap *map, const int key)
{
    int index = HashFunc(key);
    if (map->Map[index] != NULL)
    {
        free(map->Map[index]->value);
        map->Map[index]->value = NULL;
        free(map->Map[index]);
        map->Map[index] = NULL;
    }
}

HashSet *pairSet(HashMap *map)
{
    int len = 0;
    for (int i = 0; i < CAPACITY; i++)
    {
        if (map->Map[i] != NULL)
            len++;
    }
    HashSet *hset = (HashSet *)malloc(sizeof(HashSet));

    pair *entry = (pair *)malloc(sizeof(pair) * len);
    for (int i = 0; i < CAPACITY; i++)
    {
        static int index = 0;
        if (map->Map[i] != NULL)
        {
            entry[index].key = map->Map[i]->key;
            entry[index].value = map->Map[i]->value;
        }
    }

    hset->set = entry;
    hset->len = len;
}

HashSet *keySet(HashMap *map)
{
    int len = 0;
    for (int i = 0; i < CAPACITY; i++)
    {
        if (map->Map[i] != NULL)
            len++;
    }
    HashSet *hset = (HashSet *)malloc(sizeof(HashSet));

    int *entry = (int *)malloc(sizeof(int) * len);
    int index = 0;
    for (int i = 0; i < CAPACITY; i++)
    {

        if (map->Map[i] != NULL)
        {
            entry[index++] = map->Map[i]->key;
        }
    }

    hset->set = entry;
    hset->len = len;

    return hset;
}

HashSet *valueSet(HashMap *map)
{
    int len = 0;
    for (int i = 0; i < CAPACITY; i++)
    {
        if (map->Map[i] != NULL)
            len++;
    }
    HashSet *hset = (HashSet *)malloc(sizeof(HashSet));

    char **entry = malloc(sizeof(char *) * len);
    int index = 0;
    for (int i = 0; i < CAPACITY; i++)
    {

        if (map->Map[i] != NULL)
        {
            entry[index++] = map->Map[i]->value;
        }
    }

    hset->set = entry;
    hset->len = len;

    return hset;
}

void HashtoString(HashMap *map)
{
    printf("HashMap : \r\r");
    for (int i = 0; i < CAPACITY; i++)
    {
        if (map->Map[i] != NULL)
        {
            char *str = malloc(sizeof(char) * 100);
            sprintf(str, "key : %d --> value :", map->Map[i]->key);
            strcat(str, map->Map[i]->value);
            printf(str);
            printf("\r\n");
        }
    }
}

int main()
{

    HashMap *map = newHashMap();

    put(map, 114514, "zhangsan");
    put(map, 100086, "lisi");
    put(map, 135790, "wangwu");
    /*打印哈希表 */
    HashtoString(map);
    printf("删除成员\r\n");
    removeHash(map, 114514);
    printf("删除后哈希表：\r\n");
    HashtoString(map);

    HashSet *val = valueSet(map);
    printf("遍历键值\r\n");
    char **str = (char **)val->set;
    for (size_t i = 0; i < val->len; i++)
    {
        printf("value is : %s\r\n", str[i]);
    }

    free(val->set);

    HashSet *keys = keySet(map);
    printf("遍历键\r\n");
    int *p = (int *)keys->set;
    for (size_t i = 0; i < keys->len; i++)
    {
        printf("key: %d\r\n", p[i]);
    }
    free(keys->set);

    deleteHashMap(map);

    return -1;
}