#pragma once
#include "Snake.h"
//#include "coord.h"
#include <time.h>
#include <iostream>


class Food :  public virtual Snake
{
    coord F_m;

public:
    //конструктор
     Food();
     //смена координат еды
    void set_food();
// проверка чтобы появление еды не совпало с координатами змеи и рамок
    int check();  
    
    //получение координат еды
    coord get_food();
    //внесение координат еды в масив поля
    void art_food();
};

