#include "Game.h"



#define _CRT_SECURE_NO_WARNINGS
Game::Game()
{
	end_game_m = false;// начальная инициализация переменых 
	motion = Stop;
	score = 0;
	k_m = 0;
	speed = 200 - k_m * 40;
	lvl_m = 0;
}

void  Game::set_k_lvl(int k, int lvl)
{
	k_m = k;
	speed = 200 - k_m * 40;
	lvl_m = lvl;
}

Game::Game(int k)
{
	end_game_m = false;// начальная инициализация переменых 
	motion = Stop;
	score = 0;
	k_m = k;
	speed = 200 - k_m * 40;
	LVL();
}

void  Game::game_start(int k, int lvl)//обнуление полей данных к стартовым значениям
{
	end_game_m = false;
	motion = Stop;
	score = 0;
	k_m = k;
	lvl_m = lvl;
	speed = 200 - k_m * 40;
	reset_old_frame();
	set_snake_x(get_sz() / 2);
	set_snake_y(get_sz() / 2);
	set_cnt_tail(0);
	LVL();
}

int Game::get_end_game() { return end_game_m; }


int  Game::get_score() { return score; }
int  Game::get_speed() { return speed; }

void  Game::input_keybord() //отслеживание клавиатуры
{
	if (_kbhit()) {
		switch (_getch())
		{
		case 'a':
		case 'A':  motion = Left;
			break;
		case'd':
		case'D':motion = Right;
			break;
		case'w':
		case'W':motion = Up;
			break;
		case's':
		case'S':   motion = Down;
			break;
		case'x':
		case'X': end_game_m = true;
			break;
		}
	}
}

void  Game::game() //  логика игры
{
	get_tail()[0] = get_snake_head();
	for (int i = 1; i < get_cnt_tail(); i++) // перезаполнение масивов с координатами хвоста
	{
		std::swap(get_tail()[i], get_tail()[i - 1]);
	}
	switch (motion)// отслеживание нажатия клавиш
	{
	case Left:
		set_snake_x(get_snake_head().x - 1);
		break;
	case Right:
		set_snake_x(get_snake_head().x + 1);
		break;
	case Up:
		set_snake_y(get_snake_head().y - 1);
		break;
	case Down:
		set_snake_y(get_snake_head().y + 1);
		break;
	}

	if (get_snake_head().x == get_sz() - 1) //логика поведения при столкновении со стеной
		set_snake_x(1);
	else if (get_snake_head().x == 0)
		set_snake_x(get_sz() - 2);
	if (get_snake_head().y == get_sz() - 1)
		set_snake_y(1);
	else if (get_snake_head().y == 0)
		set_snake_y(get_sz() - 2);
	if (get_food().y == get_snake_head().y && get_food().x == get_snake_head().x)
	{
		score++;
		set_food();
		set_cnt_tail(get_cnt_tail() + 1);
	}
	LVL();
}

void Game::show_rez()
{
	gotoxy(0, get_sz() + 1);
	std::cout << "score-->" << score << "\n";
	Sleep(speed);
	printf("control: UP-->W, DOWN-->S, LEFT-->A, RIGHT-->D\n ");
	printf("EXIT--> X ");
}

void Game::show_game()
{
	show_playing_field();
	show_rez();
}

void Game::LVL()
{
	icialize_field0();
	switch (lvl_m)
	{
	case 0: break;
	case 1:
	{icialize_field1(); break; }
	case 2:
	{
		icialize_field2();
		break;
	}
	case 3:
	{icialize_field1();
	icialize_field3();
	break; }
	case 4:
	{icialize_field1();
	icialize_field2();
	icialize_field3();
	break; }
	}

	art_tail();
	if (get_frame()[get_snake_head().y][get_snake_head().x] == ' ')
	{
		art_snake();
	}
	else {
		art_snake();
		end_game_m = true;
	}
	art_food();
}

void Game::game_over()
{
	if (end_game_m)
	{
		gotoxy(get_sz() / 3, get_sz() / 2);
		std::cout << "GAME OVER!!!\n";
		gotoxy(get_sz() / 3, get_sz() / 2 + 1);
		std::cout << "you loozer!!!\n";
		Sleep(1000);
		//break;
	}
	if (get_score() == 10)
	{
		gotoxy(get_sz() / 3, get_sz() / 2);
		std::cout << "score-->" << get_score() << "\n";
		gotoxy(get_sz() / 3, get_sz() / 2 + 1);
		std::cout << "you winer\n";
		Sleep(1000);
		end_game_m = true;// break;
	}
}


