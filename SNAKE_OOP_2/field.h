#pragma once
#include <iostream>
#include "coord.h"

class field :   public virtual coord  ///public virtual Game ,
{
   //снимок поля
        char** old_frame_m;
        //игровое поле
        char** frame_m;
        //размер поля
        int sz_m;

    public:
        //конструктор
        field();
        //получение  размера поля
        int get_sz();
        //получение адреса масива поля
        char** get_frame();
        //получение адреса масива снимка поля
        char** get_Old_frame();
        //деструктор
        ~field();
        // сброс снимка поля
        void reset_old_frame();
        //инициализациия масива поля рамки
        void icialize_field0(); // игровое поле
        //инициализациия масива поля дополнительние углы
        void icialize_field1();
        //инициализациия масива поля дополнительние рамки
        void icialize_field2();
        //инициализациия масива поля дополнительние линия посредине
        void icialize_field3();
        //незаполненая инициализация
        void icialize_field4();

        //вывод игрового поля на екран
        void show_playing_field(); // игровое поле
};

