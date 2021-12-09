#pragma once
#include <iostream>
#include <fstream>

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
struct fileTime
{
	int min;
	int sec;
};
