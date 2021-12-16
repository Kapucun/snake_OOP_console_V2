#pragma once
#include "field.h"
#include "coord.h"



class Snake :  public virtual field
{
   
    coord head_m;
    coord* tail_m;//[get_sz() / 2 * 10];//??????????
    int cnt_tail;
public:
 //�����������
    Snake();
//�������� �������� ������ ���� � ������� ����
    void art_snake();
// ��������� �������� ���������� � ����
    void set_snake_x(int x);
// ��������� �������� ���������� � ����
    void set_snake_y(int y);
// ��������� �������� ������� ������
    void set_cnt_tail(int cnt);
//�������� �������� ������ � ������� ���� �� ����������� �����������
    int art_tail(int i, int j); 
//�������� ���� �������� ������ � ������� ����
    void art_tail(); 
//������ �� ��������� ������ ����
    coord get_snake_head();
//������ �� ��������� ������
    coord* get_tail();
//������ �� �������� ������� ������
    int get_cnt_tail();

//���������� ����
    ~Snake();
};

