#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct tableitem
{
    void *key;
    void *value;
} tableitem;

typedef struct hashtable
{
    unsigned capacity;
    unsigned count;
    struct tableitem **data;
} hashtable;

hashtable *init_table();
void hash_add_item(hashtable *table, void *key, void *value, size_t key_size, size_t value_size);
void hash_destroy(hashtable *table);
void *hash_get(hashtable *table, const void *key, int (*compar)(const void *, const void *));

#endif