#include "main.h"
#include "function.h"
#include "console.h"


int main()
{	
	SetConsoleTitle(TEXT("MINESWEEPER GAME")); // dat tieu de cho man hinh

	resizeConsole(ConsoleWidth, ConsoleHeight); // kich thuoc man hinh console

	veTittle();

	Cursor(false); // An con tro


	//khoiTao(10, 10, 4);
	
	//veTrangThaiChoiGame();
	
	//xuLySuKien();

	return 0;
}
