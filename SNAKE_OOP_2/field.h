#pragma once
#include <iostream>
#include "coord.h"

class field :   public virtual coord  ///public virtual Game ,
{
   //������ ����
        char** old_frame_m;
        //������� ����
        char** frame_m;
        //������ ����
        int sz_m;

    public:
        //�����������
        field();
        //���������  ������� ����
        int get_sz();
        //��������� ������ ������ ����
        char** get_frame();
        //��������� ������ ������ ������ ����
        char** get_Old_frame();
        //����������
        ~field();
        // ����� ������ ����
        void reset_old_frame();
        //�������������� ������ ���� �����
        void icialize_field0(); // ������� ����
        //�������������� ������ ���� �������������� ����
        void icialize_field1();
        //�������������� ������ ���� �������������� �����
        void icialize_field2();
        //�������������� ������ ���� �������������� ����� ���������
        void icialize_field3();
        //������������ �������������
        void icialize_field4();

        //����� �������� ���� �� �����
        void show_playing_field(); // ������� ����
};

