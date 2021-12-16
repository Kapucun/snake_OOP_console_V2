#pragma once
#include "field.h"
#include "coord.h"



class Snake :  public virtual field
{
   
    coord head_m;
    coord* tail_m;//[get_sz() / 2 * 10];//??????????
    int cnt_tail;
public:
 //конструктор
    Snake();
//внесение символов головы змеи в игровое поле
    void art_snake();
// изменение значения координаты х змеи
    void set_snake_x(int x);
// изменение значения координаты у змеи
    void set_snake_y(int y);
// изменение счетчика размера хвоста
    void set_cnt_tail(int cnt);
//внесение символов хвоста в игровое поле по определеним координатам
    int art_tail(int i, int j); 
//внесение всех символов хвоста в игровое поле
    void art_tail(); 
//доступ до координат головы змеи
    coord get_snake_head();
//доступ до координат хвоста
    coord* get_tail();
//доступ до счетчика размера хвоста
    int get_cnt_tail();

//деструктор змеи
    ~Snake();
};

