#include "field.h"



field::field() : sz_m(25)
{

	old_frame_m = new char* [sz_m];
	for (int i = 0; i < sz_m; i++)
		old_frame_m[i] = new char[sz_m];
		frame_m = new char* [sz_m];
	for (int i = 0; i < sz_m; i++)
		frame_m[i] = new char[sz_m];
}

int field::get_sz() { return sz_m; }
char** field::get_frame() { return frame_m; }
char** field::get_Old_frame() { return old_frame_m; }

field::~field()
{
	for (int i = 0; i < sz_m; i++)
		delete[] old_frame_m[i];
	delete[] old_frame_m;
	for (int i = 0; i < sz_m; i++)
		delete[] frame_m[i];
	delete[] frame_m;
}

void field::reset_old_frame()
{
	for (int i = 0; i < sz_m; i++)
		for (int j = 0; j < sz_m; j++)
			old_frame_m[i][j] = ' ';
}

void field::icialize_field0() // игровое поле
{
	frame_m[0][0] = 218;// 201;//углы рамки
	frame_m[0][sz_m - 1] = 191;// 187;
	frame_m[sz_m - 1][0] = 192;// 200;
	frame_m[sz_m - 1][sz_m - 1] = 217;// 188;

	for (int i = 1; i < sz_m - 1; i++)
	{
		frame_m[i][0] = 179;// 186; //боковые рамки
		frame_m[i][sz_m - 1] = 179;// 186;
		for (int j = 1; j < sz_m - 1; j++)
		{
			frame_m[0][j] = 196;// 205;// верхн€€ и нижн€€ рамки
			frame_m[sz_m - 1][j] = 196;// 205;
			frame_m[i][j] = ' ';
		}
	}
}

void field::icialize_field1() // игровое поле
{
	frame_m[1][1] = 201;//углы рамки
	frame_m[1][sz_m - 2] = 187;
	frame_m[sz_m - 2][1] = 200;
	frame_m[sz_m - 2][sz_m - 2] = 188;

	for (int i = 2; i < sz_m - 2; i++)
	{
		if (i<sz_m / 4 || i>sz_m - (sz_m / 4))
		{
			frame_m[i][1] = 186; //боковые рамки
			frame_m[i][sz_m - 2] = 186;
		}
	}
	for (int j = 2; j < sz_m - 2; j++)
	{
		if (j<sz_m / 4 || j>sz_m - (sz_m / 4))
		{
			frame_m[1][j] = 205;// 205;// верхн€€ и нижн€€ рамки
			frame_m[sz_m - 2][j] = 205;// 205;
		}
	}
}

void field::icialize_field2() {
	for (int i = sz_m / 4; i < sz_m - (sz_m / 4); i++)
	{
		if (i > sz_m / 4 && i < sz_m / 4 * 2 || i > sz_m - (sz_m / 4 * 2) && i < sz_m - (sz_m / 4))
		{
			frame_m[i][1] = 186; //боковые рамки
			frame_m[i][sz_m - 2] = 186;
		}
	}
	for (int j = sz_m / 4; j < sz_m - (sz_m / 4); j++)
	{
		if (j > sz_m / 4 && j < sz_m / 4 * 2 || j > sz_m - (sz_m / 4 * 2) && j < sz_m - (sz_m / 4))
		{
			frame_m[1][j] = 205;// 205;// верхн€€ и нижн€€ рамки
			frame_m[sz_m - 2][j] = 205;// 205;
		}
	}
}
void field::icialize_field3()
{
	for (int j = sz_m / 4; j < sz_m - (sz_m / 4); j++)
	{
		frame_m[sz_m / 2 + 1][j] = 205;// 205;// верхн€€ и нижн€€ рамки
	}
}

void field::icialize_field4() {}

void field::show_playing_field() // игровое поле
{
	for (int i = 0; i < sz_m; i++)// вывод  масива frame на екран и потом вывод мен€ющихс€ значений
	{
		for (int j = 0; j < sz_m; j++)
		{
			if (frame_m[i][j] != old_frame_m[i][j])
			{
				gotoxy(j, i);
				std::cout << frame_m[i][j];
				old_frame_m[i][j] = frame_m[i][j];
			}
		}
	}
	gotoxy(0, sz_m + 1);
}

