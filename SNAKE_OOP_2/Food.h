#pragma once
#include "Snake.h"
//#include "coord.h"
#include <time.h>
#include <iostream>


class Food :  public virtual Snake
{
    coord F_m;

public:
    //�����������
     Food();
     //����� ��������� ���
    void set_food();
// �������� ����� ��������� ��� �� ������� � ������������ ���� � �����
    int check();  
    
    //��������� ��������� ���
    coord get_food();
    //�������� ��������� ��� � ����� ����
    void art_food();
};

