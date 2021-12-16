#include "Snake.h"
//#include "field.h"
//#include "coord.h"


Snake::Snake() {
    head_m.x = get_sz() / 2;
    head_m.y = get_sz() / 2;
    cnt_tail = 0;
    tail_m = new coord[get_sz() / 2 * 10];
    get_frame()[head_m.y][head_m.x] = 'o';//ĞÈÑÎÂÀÍÈÅ ÃÎËÎÂÛ ÇÌÅÈ â ìàñèâå frame

}

void Snake::art_snake()
{
   
    get_frame()[head_m.y][head_m.x] = 'o';//ĞÈÑÎÂÀÍÈÅ ÃÎËÎÂÛ ÇÌÅÈ â ìàñèâå frame
}




void Snake::set_snake_x(int x)
{
    head_m.x = x;
}
void Snake::set_snake_y(int y)
{
    head_m.y = y;
}



void Snake::set_cnt_tail(int cnt) { cnt_tail = cnt; }

int Snake::art_tail(int i, int j) //ğèñîâàíèå õâîñòà
{
    for (int n = 0; n < get_cnt_tail(); n++)
    {
        
        
        if (get_tail()[n].x == j && get_tail()[n].y == i)
        {
            get_frame()[i][j] = '#';
          return 1;
        }
    }
    return 0;
}

void Snake::art_tail() //ğèñîâàíèå õâîñòà
{
    for (int n = 0; n < get_cnt_tail(); n++)
    {
        get_frame()[get_tail()[n].y][get_tail()[n].x] = '#';

    }
   
}

coord Snake::get_snake_head() { return head_m; }
coord* Snake::get_tail() { return tail_m; }
int Snake::get_cnt_tail() { return cnt_tail; }
Snake::~Snake() { delete[]tail_m; }

