#include "util.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* misc. utility functions */

char *read_file(const char *src) {
  FILE *fp = fopen(src, "rb");
  if (!fp)
    return NULL;

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  char *buffer = (char *)malloc(size + 1);
  if (!buffer)
    return NULL;

  fread(buffer, 1, size, fp);
  buffer[size] = '\0';
  fclose(fp);
  return buffer;
}

/* logging utility */

int g_log(g_log_level level, const char *restrict format, ...) {
  if (level > g_log_current_level || level == g_log_none)
    return 0;

  va_list args;

  switch (level) {
  case g_log_error:
    printf("[ERR]  ");
    break;
  case g_log_warning:
    printf("[WARN] ");
    break;
  case g_log_info:
    printf("[INFO] ");
    break;
  default:
    break;
  }

  va_start(args, format);
  int len = vprintf(format, args);
  va_end(args);
  return len;
}

/* g_dynarr implementation */

#define dynarr_len 8

void g_dynarr_double(g_dynarr *arr);

void g_dynarr_init(g_dynarr *arr, const u64 size) {
  arr->len = 0;
  arr->cap = dynarr_len;
  arr->size = size;
  arr->data = malloc(arr->cap * arr->size);
  if (!arr->data) {
    // TODO, better error handling?
    fprintf(stderr, "Failed to allocate memory to dynarr!\n");
    return;
  }
}

void *g_dynarr_get(g_dynarr *arr, const int index) {
  if (index >= arr->len || index < 0) {
    fprintf(stderr, "Invalid index!\n");
    return NULL;
  }
  return (char *)arr->data + index * arr->size;
}

void g_dynarr_set(g_dynarr *arr, const int index, void *data) {
  if (index < 0) {
    fprintf(stderr, "Invalid index!\n");
    return;
  }
  if (index >= arr->cap) {
    arr->cap *= 2;
  }
  memcpy((char *)arr->data + index * arr->size, data, arr->size);
}

void g_dynarr_push(g_dynarr *arr, void *data) {
  if (arr->len == arr->cap) {
    g_dynarr_double(arr);
    if (!arr->data)
      return; // TODO this is so vague, need better error handling
  }
  memcpy((char *)arr->data + arr->len * arr->size, data, arr->size);
  arr->len++;
}

void *g_dynarr_pop(g_dynarr *arr) {
  if (arr->len == 0) {
    fprintf(stderr, "Underflow.\n");
    return NULL;
  }
  arr->len--;
  return (char *)arr->data + arr->len * arr->size;
}

void g_dynarr_double(g_dynarr *arr) {
  arr->cap *= 2;
  arr->data = realloc(arr->data, arr->cap * arr->size);
  if (!arr->data) {
    fprintf(stderr, "Failed to reallocate memory for dynamic array\n");
    return;
  }
}

void g_dynarr_free(g_dynarr *arr) {
  if (arr->data)
    free(arr->data);
}

/* g_hmap implementation (TODO) */

#define hash_multiplier 17

u64 hash(const char *key, u64 cap) {
  u64 hash = 0;
  while (*key)
    hash = (hash * hash_multiplier) + (*key++);
  return hash % cap;
}
