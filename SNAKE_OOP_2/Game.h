#pragma once

#include <windows.h>
#include <conio.h>
#include "Food.h"



#define _CRT_SECURE_NO_WARNINGS




class Game :  public virtual Food
{
    bool end_game_m = false;
    enum muve { Stop, Left, Right, Up, Down };
    muve motion;
    int score;
    int speed;
    int k_m;
    int lvl_m;
   
public:

//конструктор
    Game();
//изменение скорости и уровня
    void set_k_lvl(int k, int lvl);
//конструктор с заданой скоростью
    Game(int k);
//обнуление полей данных к стартовым значениям
    void game_start(int k, int lvl);
// доступ значения end_game
    int get_end_game();
//доступ значения score
    int get_score();
//доступ значения speed
    int get_speed();
//отслеживание клавиатуры
    void input_keybord();
//формирования уровня
    void LVL();
//  логика игры
    void game(); 
//отображение результата и управления
    void show_rez();
//отображение всего поля игры
    void show_game();
//отображение на экране результата игры
    void game_over();
//деструктор
    ~Game()=default;
};

