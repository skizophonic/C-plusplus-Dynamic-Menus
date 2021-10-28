# C-plusplus-Dynamic-Menus

C++ "infinite" dynamic menus for console applications.

It allows to create "unending" menus and sub-menus.
It follows a logic similar to linked lists. The main class BaseMenu contains the core methods. 
A sub-menu is created by extending the BaseMenu class and implementing load() and printOptions() methods (overriding).
When a sub-menu is created, it is also created a pointer to the previous menu thus allowing navigation. 
An implementation can be done by file inclusion and method invocation within load() method.
