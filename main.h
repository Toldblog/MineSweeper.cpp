#pragma once
#include <iostream>

constexpr auto ConsoleWidth = 80;;
constexpr auto ConsoleHeight = 35;;

struct CauTrucBang
{

	short SDong = 0;
	short SCot = 0;
	short SSoBom = 0;
	short SSoCo = 0;
	short SSoOOaMo = 0;
};
struct CauTrucO
{
	bool BCoBom = false;
	bool BDaMo = false;
	bool BCamnCo = false;
	short SBomLanCan = 0;
};

//clock_t start = clock()
//clock_t end = clock();
//float time = (float)(end - start);
//gotoXY(ConsoleWidth / 2 - 3, ConsoleHeight / 2 - 5);
//cout << time;