#include "main.h"
#include "function.h"
#include "console.h"


int main()
{	
	
	resizeConsole(ConsoleWidth, ConsoleHeight); // kich thuoc man hinh console

	SetConsoleTitle(TEXT("MINESWEEPER GAME")); // dat tieu de cho man hinh

	veTittle();
	khoiTao(10, 10, 10);
	Cursor(false); // An con tro
	veTrangThaiChoiGame(1);

	xuLySuKien();
	return 0;
}
