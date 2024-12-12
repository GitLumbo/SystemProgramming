#include "dictionary.h"
#include <dlfcn.h>
#include <stdio.h>

int main() {
  Dict mydictionary = {0};
  void *handle;
  int (*dict_add)(Dict *, char *, char *);
  int (*dict_remove)(Dict *, char *);
  int (*dict_update)(Dict *, char *, char *);
  char *(*dict_get)(Dict *, char *);
  void (*dict_print)(Dict *);

  handle = dlopen("./libdict.so", RTLD_LAZY);
  dict_add = dlsym(handle, "dict_add");
  dict_remove = dlsym(handle, "dict_remove");
  dict_update = dlsym(handle, "dict_update");
  dict_get = dlsym(handle, "dict_get");
  dict_print = dlsym(handle, "dict_print");
  // add test
  dict_add(&mydictionary, "비트코인", "143,089,000원");
  dict_add(&mydictionary, "이더리움", "5,570,000원");
  dict_add(&mydictionary, "도지코인", "589원");
  dict_print(&mydictionary);

  // update test
  if (dict_update(&mydictionary, "비트코인", "150,000,000원") < 0)
    printf("ERROR!\n");
  dict_print(&mydictionary);

  // remove test
  dict_remove(&mydictionary, "도지코인");
  dict_print(&mydictionary);

  // get test
  printf("이더리움 가격은 %s입니다.\n", dict_get(&mydictionary, "이더리움"));
  dlclose(handle);
  return 0;
}