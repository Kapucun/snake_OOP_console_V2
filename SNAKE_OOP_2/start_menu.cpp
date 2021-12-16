#include "start_menu.h"

start_menu::start_menu(int sz) {
	k_m = 0;
	lvl_m = 0;
	YesNo_m = ' ';
	title_m = new char* [9];
	for (int i = 0; i < 9; i++)
		title_m[i] = new char[59];
	exit_m = false;
	sz_m = sz;
}

void start_menu::Title()
{

	strcpy_s(title_m[0], 59, "  / $$$$$$                      / $$");
	strcpy_s(title_m[1], 59, " / $$__  $$                     | $$");
	strcpy_s(title_m[2], 59, " | $$  \\__/ /$$$$$$$   / $$$$$$ | $$  /$$/  $$$$$$");
	strcpy_s(title_m[3], 59, " |  $$$$$$ | $$__  $$ |____   $$| $$ /$$/  /$$__  $$");
	strcpy_s(title_m[4], 59, " \\____   $$| $$  \\ $$   /$$$$$$$| $$$$$$/ | $$$$$$$$");
	strcpy_s(title_m[5], 59, " / $$  \\ $$| $$  | $$  /$$__  $$| $$_  $$ | $$_____/");
	strcpy_s(title_m[6], 59, " |  $$$$$$/| $$  | $$ | $$$$$$$ | $$ \\  $$|  $$$$$$$");
	strcpy_s(title_m[7], 59, "  \\______/ |__/  |__ / \\_______/|__ / \\__ /\\_______/");
	strcpy_s(title_m[8], 59, "                                                         ");
	show_title();
}

void start_menu::show_title() {
	gotoxy(0, 0);
	for (int i = 0; i < 9; i++)
	{
		std::cout << title_m[i] << "\n";
	}
}

void start_menu::anim_title()
{
	for (int j = 0; j < 9; j++)
	{
		gotoxy(0, 0);
		for (int i = 0; i < 8; i++)
		{
			std::cout << title_m[i] << "\n";
			strcpy_s(title_m[i], 59, title_m[i + 1]);
		}
		Sleep(200);
	}
}

void start_menu::show_start_menu()
{
	exit_m = false;
	system("cls");
	Title();
	show_title();
	gotoxy(sz_m / 3, sz_m / 2 + 2);
	printf("you play y/n\n");
	gotoxy(sz_m / 3, sz_m / 2 + 3);
	std::cin >> YesNo_m;
	switch (YesNo_m)
	{
	case 'Y':
	case 'y':
		gotoxy(sz_m / 3, sz_m / 2 + 4);
		printf("select speed 0-4\n");
		gotoxy(sz_m / 3, sz_m / 2 + 5);
		std::cin >> k_m;
		gotoxy(sz_m / 3, sz_m / 2 + 6);
		printf("select level 0-4\n");
		gotoxy(sz_m / 3, sz_m / 2 + 7);
		std::cin >> lvl_m;
		anim_title();
		system("cls");
		break;
	case 'n':
	case 'N': exit_m = true;
		break;

	default: std::cout << "Error!!!!   select again \n";
		break;
	}
}

int start_menu::get_k() { return k_m; }
int start_menu::get_lvl() { return lvl_m; }
bool start_menu::get_exit() { return exit_m; }


start_menu::~start_menu() {
	for (int i = 0; i < 9; i++)
		delete[] title_m[i];
	delete[]title_m;
}

void start_menu::gotoxy(int x, int y)
{
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

void start_menu::Good_bye()
{
	gotoxy(sz_m / 3, sz_m / 2 + 4);
	std::cout << "good bye!!!\n";
}