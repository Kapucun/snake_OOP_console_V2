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
    //�����������
    start_menu(int sz);
    //�������� � ����� �� ����� ��������
    void Title();
    //�������� ��������
    void anim_title();
   //����� �� ����� ���������� ����
    void show_start_menu();
    // ������ �� ������ ���� �
    int get_k();
    // ������ �� ������ ���� lvl
    int get_lvl();
    //������ �� ������ ���� exit
    bool get_exit();
    //���������� ���������� ����
    ~start_menu() ;
    //���������� ������ �� �����������
    void gotoxy(int x, int y); 
    // ��������� ��������
    void Good_bye();
    //����� �� ����� ��������
    void show_title();
    
};

