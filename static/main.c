#include "dictionary.h"
#include <stdio.h>

int main() {
  Dict mydictionary = {0};
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
  return 0;
}