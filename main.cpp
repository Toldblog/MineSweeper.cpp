#include "main.h"
#include "function.h"
#include "console.h"


int main()
{	
	Cursor(false); // An con tro
	resizeConsole(ConsoleWidth, ConsoleHeight); // kich thuoc man hinh console

	SetConsoleTitle(TEXT("Game Do Min")); // dat tieu de cho man hinh
	//dayne
	veTittle();
	khoiTao(9, 9, 10);
	veTrangThaiChoiGame(1);

	
	
	xuLySuKien();
	return 0;
}