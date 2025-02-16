#ifndef smv_gcodepp_util_h
#define smv_gcodepp_util_h

#include <stdint.h>

typedef uint16_t u16;
typedef uint64_t u64;
typedef int64_t i64;
typedef double f64;

/* g_dynarr - dynamic array helper */

typedef struct g_dynarr {
  void *data;
  u64 len;
  u64 cap;
  u64 size;
} g_dynarr;

// this essentially does nothing
// eye candy
#define g_dynarr(type) g_dynarr

void g_dynarr_init(g_dynarr *arr, const u64 size);
void *g_dynarr_get(g_dynarr *arr, const int index);
void g_dynarr_set(g_dynarr *arr, const int index, void *data);
void g_dynarr_push(g_dynarr *arr, void *data);
void *g_dynarr_pop(g_dynarr *arr);
void g_dynarr_free(g_dynarr *arr);

/* g_linkedlist - simple linked list (TODO) */

// typedef struct g_linkedlist {
//   void *data;
//   struct g_linkedlist *next;
//   struct g_linkedlist *last;
// } g_linkedlist;

/* g_map - quick hashmap implementation (TODO) */

// typedef struct g_hmap_pair {
//   char *key;
//   void *value;
// } g_hmap_pair;

// typedef g_dynarr g_hmap;

// void g_hmap_init(g_hmap *map);
// void g_hmap_double(g_hmap *map);
// void g_hmap_set(g_hmap *map, const char *key, void *value);
// void g_hmap_get(g_hmap *map, const char *key);
// void g_hmap_delete(g_hmap *map, const char *key);
// void g_hmap_free(g_hmap *map);

#endif
