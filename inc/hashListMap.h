#ifndef HASHLISTMAP_H
#define HASHLISTMAP_H
/*字符型哈希表*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "list.h"

#define CAPACITY 100
#define HASHINDEX(key) (key % CAPACITY)

typedef struct Pair
{
    int key;
    char *value;
    Node *node;
} Pair;
/*链表型哈希表*/
typedef struct HashlistMap
{
    int length;
    Pair *Map[CAPACITY];
} HashlistMap;

/*哈希键/值/键值对集合*/
typedef struct HashSet
{
    void *set;
    int len;
} HashSet;

Pair *newPair(const int key, char *val);
HashlistMap *newHashMap();
void deleteHashMap(HashlistMap *map);
void deleteSet(HashSet *hset);
void put(HashlistMap *map, const int key, char *value);
Pair *get(HashlistMap *map, const int key);
void removePair(HashlistMap *map, const int key);
HashSet *valueSet(HashlistMap *map);
HashSet *keySet(HashlistMap *map);

#endif