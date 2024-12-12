#ifndef DICTIONARY_H
#define DICTIONARY_H
typedef struct {
  char key[100];
  char value[100];
} DictFrame;

typedef struct {
  DictFrame frames[100];
  int size;
} Dict;

/*
Add key-value to Dict
-3: length error / -2: full error / -1: same key error
*/
int dict_add(Dict *dict, char *key, char *value);

/*
Remove key-value from Dict
-3: length error / -1: key not found error
*/
int dict_remove(Dict *dict, char *key);

/*
Update key-value in Dict
-3: length error / -1: key not found error
*/
int dict_update(Dict *dict, char *key, char *value);

/*
Get value from key in Dict
NULL: error
*/
char *dict_get(Dict *dict, char *key);

/*
Print Dictionary
*/
void dict_print(Dict *dict);
#endif