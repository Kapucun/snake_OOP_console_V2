#include "Food.h"


  
   Food::Food()
   {
       F_m.x = 0;
       F_m.y = 0;
      
    }

int Food::check() // проверка чтобы появление еды не совпало с координатами змеи 
    {

           if (get_frame()[F_m.y][F_m.x]==' ')
            {return 1;}
           else
        return 0;
    }


    void Food::set_food()
    {
        srand(time(nullptr));
        do
        {
            F_m.x = 1 + rand() % (get_sz() - 2);
            F_m.y = 1 + rand() % (get_sz() - 2);

        } while (!(check()));
        get_frame()[F_m.y][F_m.x] = '@';//РИСОВАНИЕ ЕДЫв масиве frame
    }
    void Food::art_food()
    {
        if (check())
        {
            get_frame()[F_m.y][F_m.x] = '@';;
        }
        else {
            set_food();
            
        }
       
       }


    

    coord Food::get_food() { return F_m; }



