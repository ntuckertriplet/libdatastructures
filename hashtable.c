#include <stdlib.h>
#include <string.h>

#include "hashtable.h"

#define INITIAL_CAPACITY 16
#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

static uint64_t hash_key(const void *key)
{
    uint64_t hash = FNV_OFFSET;
    for (const char *p = key; *p; p++)
    {
        hash ^= (uint64_t)(unsigned char)(*p);
        hash *= FNV_PRIME;
    }
    return hash;
}

hashtable *init_table()
{
    hashtable *created = malloc(sizeof(hashtable));
    created->capacity = INITIAL_CAPACITY;
    created->data = malloc(sizeof(void *) * created->capacity);
    return created;
}

tableitem *_create_item(void *key, void *value, size_t key_size, size_t value_size)
{
    tableitem *to_add = malloc(sizeof(tableitem));
    to_add->key = malloc(key_size);
    to_add->value = malloc(value_size);
    memcpy(to_add->key, key, key_size);
    memcpy(to_add->value, value, value_size);
}

void hash_add_item(hashtable *table, void *key, void *value, size_t key_size, size_t value_size)
{
    tableitem *to_add = _create_item(key, value, key_size, value_size);
    // TODO add to table
}

void hash_destroy(hashtable *table)
{
    for (int i = 0; i < table->capacity; i++)
    {
        if (table->data[i] != NULL && table->data[i]->key != NULL)
        {
            free(table->data[i]->key);
        }
    }

    free(table->data);
    free(table);
}

void *hash_get(hashtable *table, const void *key, int (*compar)(const void *, const void *))
{
    uint64_t hash = hash_key(key);
    size_t index = (size_t)(hash & (uint64_t)(table->capacity - 1));

    while (table->data[index]->key != NULL)
    {
        if ((*compar)(key, table->data[index]->key) == 0)
        {
            return table->data[index]->value;
        }

        index++;
        if (index >= table->capacity)
        {
            index = 0;
        }
    }

    return NULL;
}
