#pragma once
#include <conio.h>
#include <windows.h>

class coord
{
public:
    int x;
    int y;
   //�����������
    coord();

    //����������
    ~coord() = default;
    //����������� ������� �� �����������
 void gotoxy(int x, int y);
};

