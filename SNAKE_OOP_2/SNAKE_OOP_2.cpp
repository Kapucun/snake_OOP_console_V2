//ООП С++
//Калифицкий М.О.
/*екзаменационная работа
игра "Питон"
*/
//03.08.2020

#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "coord.h"
#include "field.h"
#include "Food.h"
#include "Snake.h"
#include "Game.h"
#include "start_menu.h"

//#define _CRT_SECURE_NO_WARNINGS

using namespace std;

void RUN()
{
    Game G;
    start_menu SM(G.get_sz());
    do
    {
            SM.show_start_menu();
            G.game_start(SM.get_k(),SM.get_lvl());
            if (SM.get_exit())
                break;
            G.show_game();
     do
     { 
                G.input_keybord();
                G.game();
                G.show_game();
                G.game_over();
                
      } while (!G.get_end_game());
      

    } while (true);
    SM.Good_bye();
    system("pause");
}



int main()
{
    RUN();
    
    return 0;
}









