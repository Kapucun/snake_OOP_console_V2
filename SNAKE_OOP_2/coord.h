#pragma once
#include <conio.h>
#include <windows.h>

class coord
{
public:
    int x;
    int y;
   //конструктор
    coord();

    //деструктор
    ~coord() = default;
    //перемещение курсора по координатам
 void gotoxy(int x, int y);
};

