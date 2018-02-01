# DV1519-Programmering-Cpp
Detta är källkoden vi har gått igenom under lektionerna.

# Snabbreferens
För att få svenska i konsolen lägg till detta i början av main
```cpp
system("chcp 1252 & cls");
```
För att få programmet vänta innan programmet stängs av lägg till detta innan `return 0;` i slutet av main.
```cpp
system("pause");
```
(om det inte funkar lägg till `#include <Windows.h>` högst upp i filen)

För att hitta minnesläckor ska denna funktion anropas på första raden i main detta görs EN gång.
```cpp
_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
```
För att hitta i vilken fil som minnesläckan kommer ifrån så måste du ha detta högst upp i ALLA filer som du använder `new`.
```cpp
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
```

# Användbara länkar
* [C++ Referens Sida](http://en.cppreference.com/)
* [Vad är objektorientering?](http://www.databasteknik.se/webbkursen/oo-grunder/)
* [UML Cheatsheet](http://www.anotherchris.net/wp-content/uploads/2010/01/umlcheatsheet.jpg)
* [Hur Pekare Fungerar](https://www.programiz.com/c-programming/c-pointers)

# Extra
* [Game Programming Patterns](http://gameprogrammingpatterns.com/contents.html)
* [SFML Boilerplate](https://github.com/henrikvik/SFML-Skeleton)
