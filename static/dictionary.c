#include "dictionary.h"
#include <stdio.h>
#include <string.h>

static int find_empty_index(Dict *dict, char *key) {
  int empty = -1;
  for (int i = 0; i < 100; ++i) {
    if (empty == -1 && !strlen(dict->frames[i].key))
      empty = i;
    if (strcmp(dict->frames[i].key, key) == 0)
      return -1;
  }
  if (empty == -1)
    return -2;
  return empty;
}
static int find_key_index(Dict *dict, char *key) {
  for (int i = 0; i < 100; ++i)
    if (strcmp(dict->frames[i].key, key) == 0) {
      return i;
    }
  return -1;
}
// -3: length error / -2: full error / -1: same key error
int dict_add(Dict *dict, char *key, char *value) {
  if (strlen(key) > 100 || strlen(value) > 100)
    return -3;

  int index;
  if ((index = find_empty_index(dict, key)) < 0)
    return index;

  strcpy(dict->frames[index].key, key);
  strcpy(dict->frames[index].value, value);
  return 0;
}

// -3: length error / -1: key not found error
int dict_remove(Dict *dict, char *key) {
  if (strlen(key) > 100)
    return -3;

  int index;
  if ((index = find_key_index(dict, key)) < 0)
    return index;

  strcpy(dict->frames[index].key, "");
  strcpy(dict->frames[index].value, "");
  return 0;
}

// -3: length error / -1: key not found error
int dict_update(Dict *dict, char *key, char *value) {
  if (strlen(key) > 100 || strlen(value) > 100)
    return -3;

  int index;
  if ((index = find_key_index(dict, key)) < 0)
    return index;

  strcpy(dict->frames[index].value, value);
  return 0;
}

// NULL: error
char *dict_get(Dict *dict, char *key) {
  if (strlen(key) > 100)
    return NULL;

  int index;
  if ((index = find_key_index(dict, key)) < 0)
    return NULL;

  return dict->frames[index].value;
}

void dict_print(Dict *dict) {
  printf("{");
  for (int i = 0; i < 100; ++i)
    if (strlen(dict->frames[i].key))
      printf("\"%s\": \"%s\", ", dict->frames[i].key, dict->frames[i].value);
  printf("\b\b}\n");
}