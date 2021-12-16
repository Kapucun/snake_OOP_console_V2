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

//�����������
    Game();
//��������� �������� � ������
    void set_k_lvl(int k, int lvl);
//����������� � ������� ���������
    Game(int k);
//��������� ����� ������ � ��������� ���������
    void game_start(int k, int lvl);
// ������ �������� end_game
    int get_end_game();
//������ �������� score
    int get_score();
//������ �������� speed
    int get_speed();
//������������ ����������
    void input_keybord();
//������������ ������
    void LVL();
//  ������ ����
    void game(); 
//����������� ���������� � ����������
    void show_rez();
//����������� ����� ���� ����
    void show_game();
//����������� �� ������ ���������� ����
    void game_over();
//����������
    ~Game()=default;
};

