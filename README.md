# 2024 System Programming Project(CSE3209)
202402-CSE3209-002 시스템 프로그래밍 강의에서 수행된 프로젝트입니다.
Static Library와 Shared Library를 통해 Staic Linking과 Runtime Linking을 수행하는 내용을 포함합니다.

C언어에서 Python의 Dictionary구조를 구현해 key-value쌍을 추가/업데이트/제거/value 얻기를 수행할 수 있습니다.

### 💻 개발환경
OS: Ubuntu 22.04.5 LTS
Compiler: GCC 11.4.0

### 🌳 레포지토리 구조
```
📂 /
├── 📂 static/
│   ├── 📄 main.c
│   ├── 📄 dictionary.c
│   ├── 📄 dictionary.h
│   ├── 📄 dictionary.o
│   ├── 📄 libdict.a
│   └── ⚙️ main_static
├── 📂 dynamic/
│   ├── 📄 main.c
│   ├── 📄 dictionary.c
│   ├── 📄 dictionary.h
│   ├── 📄 dictionary.o
│   ├── 📄 libdict.so
│   └── ⚙️ main_dynamic
├── 📄 README.md
```

### 📓 코드 설명
이 라이브러리를 사용하는 방법은 다음과 같습니다.

#### 📙 Static Library
---
**1. 헤더파일 포함**
```C
#include "dictionary.h"
```
**2. 구조체 정의**
```C
Dict mydictionary = {0};
```
**3. 함수 사용**
```C
/* Dictionary에 key-value쌍을 추가하는 함수
return -3: key-value 길이 Error(최대 길이 100자) 
return -2: Dictionary 가득 참 Error(최대 key-value쌍 100개)
return -1: 같은 key추가 Error */
int dict_add(Dict *dict, char *key, char *value);

/* Dictionary에 key에 해당하는 key-value쌍을 지우는 함수
return -3: key 길이 Error(최대 길이 100자) 
return -1: key 미존재 Error */
int dict_remove(Dict *dict, char *key);

/* Dictionary에 key에 해당하는 value를 update하는 함수
return -3: key-value 길이 Error(최대 길이 100자) 
return -1: key 미존재 Error */
int dict_update(Dict *dict, char *key, char *value);

/* Dictionary에 key에 해당하는 value를 return 함수
return NULL: key 길이 Error(최대 길이 100자) 혹은 key 미존재 Error */
char *dict_get(Dict *dict, char *key);

/* Dictionary를 출력하는 함수 */
void dict_print(Dict *dict);
```
**4. 예제코드**
```C
dict_add(&mydictionary, "비트코인", "143,089,000원");
dict_print(&mydictionary);
dict_update(&mydictionary, "비트코인", "150,000,000원")
dict_remove(&mydictionary, "비트코인")
```
**5. 빌드방법**
```bash
$ gcc -static -o main_static -L. main.c -ldict
```


#### 📘 Dynamic Library(Runtime Linking)
---
**1. 헤더파일 포함**
```C
#include "dictionary.h"
```
**2. 구조체 정의**
```C
Dict mydictionary = {0};
```
**3. 런타임 링킹**
```C
// dl라이브러리를 통해 불러오기
#include <dlfcn.h>
handle = dlopen("./libdict.so", RTLD_LAZY);
dict_add = dlsym(handle, "dict_add");
dict_remove = dlsym(handle, "dict_remove");
dict_update = dlsym(handle, "dict_update");
dict_get = dlsym(handle, "dict_get");
dict_print = dlsym(handle, "dict_print");

// 사용 방법은 "Static Library / 3. 함수 사용"과 동일

dlclose(handle); // 사용 후 종료
```
**4. 예제코드**<br>
"Static Library / 4. 예제코드"과 동일<br>
**5. 빌드방법**
```bash
$ gcc -rdynamic -o main_dynamic main.c -ldl
```
