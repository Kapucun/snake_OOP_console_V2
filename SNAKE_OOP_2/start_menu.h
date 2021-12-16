#pragma once
#include "field.h"
class start_menu
{
    int k_m = 0;
    int lvl_m = 0;
    char YesNo_m = ' ';
    char** title_m;
    int sz_m;
    bool exit_m; 

public:
    //конструктор
    start_menu(int sz);
    //создание и вывод на екран логотипа
    void Title();
    //анимация логотипа
    void anim_title();
   //вывод на екран стартового меню
    void show_start_menu();
    // доступ до данных поля к
    int get_k();
    // доступ до данных поля lvl
    int get_lvl();
    //доступ до данных поля exit
    bool get_exit();
    //деструктор стартового меню
    ~start_menu() ;
    //перемещает курсор по координатам
    void gotoxy(int x, int y); 
    // прощается програма
    void Good_bye();
    //вывод на екран логотипа
    void show_title();
    
};

