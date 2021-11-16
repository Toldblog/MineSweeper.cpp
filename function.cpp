#include "function.h"
#include "main.h"
#include "console.h"
#include <time.h>
#include <vector>

CauTrucBang CTBang;
vector <vector <CauTrucO> > CTO;
COORD CViTriConTro;

bool BSuDungPhim = false;

short ToaDoX;
short ToaDoY;

void luuToaDoXY()
{
	ToaDoX = (ConsoleWidth / 2) - CTBang.SCot;
	ToaDoY = ((ConsoleHeight - 6 - CTBang.SDong) / 2) + 6;
}
void taoMang2ChieuDong()
{
	
	CTO.resize(CTBang.SDong);
	for (int i = 0; i < CTBang.SDong; ++i)
	{
		CTO[i].resize(CTBang.SCot);
	}
}

void khoiTao(short SDong, short SCot, short SSoBom)
{
	CTBang.SDong = SDong;
	CTBang.SCot = SCot;
	CTBang.SSoBom = SSoBom;
	CTBang.SSoCo = 0;
	CTBang.SSoOOaMo = 0;
	taoMang2ChieuDong();
	taoBomNgauNhien();
	luuToaDoXY();
	veBang();

}

short toadoXao(short Sx)
{
	return (Sx * 2 + ToaDoX );
}

short toadoYao(short Sy)
{
	return (Sy + ToaDoY);
}

void veO(short Sx, short Sy, short So)
{
	switch (So)
	{
	case 0:	Taomauo(toadoXao(Sx), toadoYao(Sy), 0, 10, "  ");
		break;
	case 1:	Taomauo(toadoXao(Sx), toadoYao(Sy), 9, 15, "1 ");
		break;
	case 2:	Taomauo(toadoXao(Sx), toadoYao(Sy), 2, 15, "2 ");
		break;
	case 3:	Taomauo(toadoXao(Sx), toadoYao(Sy), 12, 15, "3 ");
		break;
	case 4:	Taomauo(toadoXao(Sx), toadoYao(Sy), 1, 15, "4 ");
		break;
	case 5:	Taomauo(toadoXao(Sx), toadoYao(Sy), 4, 15, "5 ");
		break;
	case 6:	Taomauo(toadoXao(Sx), toadoYao(Sy), 2, 15, "6 ");
		break;
	case 7:	Taomauo(toadoXao(Sx), toadoYao(Sy), 0, 15, "7 ");
		break;
	case 8:	Taomauo(toadoXao(Sx), toadoYao(Sy), 13, 15, "8 ");
		break;
		// Bom
	case 9:	Taomauo(toadoXao(Sx), toadoYao(Sy), 12, 14, "B ");
		break;
		//o chan mau xam
	case 10:	Taomauo(toadoXao(Sx), toadoYao(Sy), 0, 8, "  ");
		break;
		//o le mau trang
	case 11:	Taomauo(toadoXao(Sx), toadoYao(Sy), 0, 7, "  ");
		break;
		// con tro
	case 12:	Taomauo(toadoXao(Sx) + 1 , toadoYao(Sy), 0, 11, " ");
		break;
		// X cam co
	case 13:	Taomauo(toadoXao(Sx), toadoYao(Sy), 12, 14, "P ");

		break;
	case 14:	Taomauo(toadoXao(Sx), toadoYao(Sy), 15, 16, "Px ");
		break;
	case 15:	Taomauo(toadoXao(Sx), toadoYao(Sy), 12, 14, "  ");
		break;
	}
}

void veBang()
{
	for (int i = 0; i < CTBang.SDong; ++i)
	{
		for (int j = 0; j < CTBang.SCot; ++j)
		{
			if (CTO[i][j].BCamnCo) veO(j, i, 13); // cam co
			else if (CTO[i][j].SBomLanCan) veO(j, i, CTO[i][j].SBomLanCan); // ve o so
			else if (CTO[i][j].BDaMo) veO(j, i, 0); // o rong
		

			else if ((i + j) % 2 == 0) veO(j, i, 10); // o chan
			else veO(j, i, 11); // o le

			if (BSuDungPhim == true) veO(CViTriConTro.X, CViTriConTro.Y, 12);
			
		}
	}
}

void taoBomNgauNhien()
{
	srand(time(NULL));
	short SSoBom = CTBang.SSoBom;
	short Si, Sj; //i la dong, j la cot
	while (SSoBom > 0)
	{
		Si = rand() % CTBang.SDong;
		Sj = rand() % CTBang.SCot;
		if (CTO[Si][Sj].BCoBom == true)
			continue;
		CTO[Si][Sj].BCoBom = true;
		--SSoBom;
	}
}

void xuatBom()
{
	for (int i = 0; i < CTBang.SDong; i++)
	{
		for (int j = 0; j < CTBang.SCot; j++)
		{
			if(CTO[i][j].BCoBom == true) cout << "1" << " ";
			if (CTO[i][j].BCoBom == false) cout << "0" << " ";
		}
		cout << endl;
	}
}

void X(short SX, short SY) // Cam co
{
	if (CTO[SX][SY].BDaMo == false)
	{
		if(CTO[SX][SY].BCamnCo == true)
		{
			CTO[SX][SY].BCamnCo = false;
			--CTBang.SSoCo;
		}
		else
		{
			CTO[SX][SY].BCamnCo = true;
			++CTBang.SSoCo;
		}
	}
	veBang();
}

short demBomLanCan(short SX, short SY)
{
	short SDem = 0;
	for (int i = SX - 1; i <= SX + 1; ++i)
	{
		for (int j = SY - 1; j <= SY + 1; ++j)
		{
			if (i < 0 || i >= CTBang.SDong || j < 0 || j >= CTBang.SCot || (i == SX && j == SY)) continue;
			if (CTO[i][j].BCoBom) ++SDem;
		}
	}
	return SDem;
}

void moO(short SX, short SY)
{
	if (!CTO[SX][SY].BDaMo && !CTO[SX][SY].BCamnCo)
	{
		CTO[SX][SY].BDaMo = true;
		if (CTO[SX][SY].BCoBom)
		{
			exit(0);
		}
		else
		{
			++CTBang.SSoOOaMo;
			short SSoBomLanCan = demBomLanCan(SX, SY);
			if (SSoBomLanCan)
			{
				CTO[SX][SY].SBomLanCan = SSoBomLanCan;
			}
			else {
				for (int i = SX - 1; i <= SX + 1; ++i)
				{
					for (int j = SY - 1; j <= SY + 1; ++j)
					{
						if (i < 0 || i >= CTBang.SDong || j < 0 || j >= CTBang.SCot || (i == SX && j == SY)) continue;
						moO(i, j);
					}
				}
			}
		}
	}
}

void Z(short SX, short SY)
{
	if (!CTO[SX][SY].BDaMo && !CTO[SX][SY].BCamnCo)
	{
		moO(SX, SY);
		veBang();
	}
}


void xuLyPhim(KEY_EVENT_RECORD key)
{
	if (key.bKeyDown) // co nhan phim
	{
		switch (key.wVirtualKeyCode)
		{
		case VK_UP:
			BSuDungPhim = true;
			CViTriConTro.Y = ((CViTriConTro.Y == 0) ? CTBang.SDong - 1 : CViTriConTro.Y - 1);
				veBang();
			break;
		case VK_DOWN:
			BSuDungPhim = true;
			CViTriConTro.Y = ((CViTriConTro.Y == CTBang.SDong - 1) ? 0 : CViTriConTro.Y + 1);
			veBang();
			break;
		case VK_LEFT:
			BSuDungPhim = true;
			CViTriConTro.X = ((CViTriConTro.X == 0) ? CTBang.SCot - 1 : CViTriConTro.X - 1);
			veBang();
			break;
		case VK_RIGHT:
			BSuDungPhim = true;
			CViTriConTro.X = ((CViTriConTro.X == CTBang.SCot-1) ? 0 : CViTriConTro.X + 1);
			veBang();
			break;
		case VK_RETURN:
			
			break;
		case VK_ESCAPE:
			
			break;
			// Z
		case 0x5A:
			Z(CViTriConTro.Y, CViTriConTro.X);
			break;
			// X
		case 0x58:
			X(CViTriConTro.Y, CViTriConTro.X); // CTO la bang 2 chieu tao tu dong(y) den cot(x) 
			break;
		}
	}
}

void xuLySuKien()
{
	while (1)
	{
		DWORD DWNumberOffEvents = 0; // DWORD: so nguyen k dau 32bits
		DWORD DWNumberOfEventSRead = 0; // so luong su kien da doc

		HANDLE HConsoleInput = GetStdHandle(STD_INPUT_HANDLE); // thiet bi dau vao
		GetNumberOfConsoleInputEvents(HConsoleInput, &DWNumberOffEvents); //truyen vao con tro den kieu DWORD(LPDWORD)

		if (DWNumberOffEvents)
		{
			INPUT_RECORD* IREventBuffer = new INPUT_RECORD[DWNumberOffEvents]; //con tro EventBuffer
			ReadConsoleInput(HConsoleInput, IREventBuffer, DWNumberOffEvents, &DWNumberOfEventSRead);// Dat cac su kien duoc luu tru vao con tro

			//chay vong lap doc su kien
			for (DWORD i = 0; i < DWNumberOffEvents; i++)
			{
				if (IREventBuffer[i].EventType == KEY_EVENT) // SUkienphim
				{
					xuLyPhim(IREventBuffer[i].Event.KeyEvent);
				}
				//else if (IREventBuffer[i].EventType == MOUSE_EVENT)
				//{

				//}
			}
		}
	}
}

void veTittle()
{
	short i;
	for (i = 0; i <= ConsoleWidth; ++i)
	{
		printf("%c", 45);
	}
	Taomauo(ConsoleWidth / 2 - 8 , 2, 6, 0, "MINESWEEPER GAME \n");
	cout  << endl;
	setColor(7);
	setBackgroundColor(0);
	for (i = 0; i <= ConsoleWidth; ++i)
	{
		printf("%c", 45);
	}
}

void veTrangThaiChoiGame(short STrangThai)
{
	setBackgroundColor(0);
	Taomauo(1, 5, 15, 0, "MAP");
	setBackgroundColor(0);
	cout << ": " << CTBang.SDong << " x " << CTBang.SCot << endl;
	Taomauo(1, 6, 15, 0, "BOM");
	setBackgroundColor(0);
	cout << ": ";
	setColor(4);
	cout << CTBang.SSoBom << endl; 

	setColor(15); // set status playing
	if (STrangThai == 1)
	{
		for (int i = 0; i <= ConsoleWidth - 17; ++i)
		{
			cout << " ";
		}
		cout << "STATUS: PLAYING";
	}
	setColor(6); // status win
	if (STrangThai == 2)
	{
		for (int i = 0; i <= ConsoleWidth/2 -3 ; ++i)
		{
			cout << " ";
		}
		cout << "WIN";
	}
	setColor(4); // status lose
	if (STrangThai == 3)
	{
		for (int i = 0; i <= ConsoleWidth/2 - 4; ++i)
		{
			cout << " ";
		}
		cout << "LOSE";
	}
	setColor(7);
}
