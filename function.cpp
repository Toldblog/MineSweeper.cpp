#include "function.h"
#include "main.h"
#include "console.h"
#include <time.h>
#include <vector>

CauTrucBang CTBang;
vector <vector <CauTrucO> > CTO;
COORD CViTriConTro;

bool BSuDungPhim = false;
bool BTrangThaiDangChoi = false;
short STrangThai = 1;

short ToaDoX;
short ToaDoY;

// dich chuyen bang ra giua man hinh console
void luuToaDoXY()
{
	ToaDoX = (ConsoleWidth / 2) - CTBang.SCot;
	ToaDoY = ((ConsoleHeight - 6 - CTBang.SDong) / 2) + 6;
}

// tao bang bang vector 2 chieu
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
	CViTriConTro = {0, 0};
	BTrangThaiDangChoi = true;
	veBang();

}

// moi lan di chuyen x di 2 o
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
		// Bom tim duoc
	case 9:	Taomauo(toadoXao(Sx), toadoYao(Sy), 12, 15, "B ");
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
	case 13:	Taomauo(toadoXao(Sx), toadoYao(Sy), 12, 14, "F ");

		break;
	case 14:	Taomauo(toadoXao(Sx), toadoYao(Sy), 15, 16, "Fx");
		break;
		// Bom chua tim dc
	case 15:	Taomauo(toadoXao(Sx), toadoYao(Sy), 16, 12, "B ");
		break;
	}
}

// muc do uu tien khi ve bang
// 1	cam co	
// 2	o co so
// 3	o rong 
// 4	o chan, o le
void veBang()
{
	for (int i = 0; i < CTBang.SDong; ++i)
	{
		for (int j = 0; j < CTBang.SCot; ++j)
		{
			// cam co
			if (CTO[i][j].BCamnCo) veO(j, i, 13);
			// ve o co so
			else if (CTO[i][j].SBomLanCan) veO(j, i, CTO[i][j].SBomLanCan); 
			// o rong
			else if (CTO[i][j].BDaMo) veO(j, i, 0); 
		
			// o chan
			else if ((i + j) % 2 == 0) veO(j, i, 10); 
			// o le
			else veO(j, i, 11); 

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

// cam co (phim X)
void X(short SX, short SY) 
{
	// kiem tra o do la o chua mo
	if (CTO[SX][SY].BDaMo == false)
	{
		// huy cam co
		if(CTO[SX][SY].BCamnCo == true)
		{
			CTO[SX][SY].BCamnCo = false;
			--CTBang.SSoCo;
		}
		// cam co
		else
		{
			CTO[SX][SY].BCamnCo = true;
			++CTBang.SSoCo;
		}
	}
	veBang();
}

// ham cap nhat so bom lan can cua 1 o -> vector 2 chieu CTO[i][j]
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

// mo o co 3 loai (o co bom, o co so, o rong)
void moO(short SX, short SY)
{
	// kiem tra o do phai la o chua mo va chua cam co
	if (!CTO[SX][SY].BDaMo && !CTO[SX][SY].BCamnCo)
	{
		// mo o
		CTO[SX][SY].BDaMo = true;
		// neu mo ngay o co bom -> thua
		if (CTO[SX][SY].BCoBom)
		{
			veO(SY, SX, 15);
			LOSE();
			exit(0);
		}
		else
		{
			++CTBang.SSoOOaMo;
			// kiem tra xung quang o co bom k
			short SSoBomLanCan = demBomLanCan(SX, SY);
			// o co so
			if (SSoBomLanCan)
			{
				CTO[SX][SY].SBomLanCan = SSoBomLanCan;
			}
			// o rong
			else 
			{
				// thuat toan loang
				//	(SX-1,SY-1)		(SX-1,SY)		(SX-1,SY+1)	
				// 
				//	(SX,SY-1)		(SX,SY)			(SX,SY+1)
				// 
				//	(SX+1,SY-1)		(SX+1,SY)		(SX+1,SY+1)

				for (int i = SX - 1; i <= SX + 1; ++i)
				{
					for (int j = SY - 1; j <= SY + 1; ++j)
					{
						// kiem tra xem o do co nam trong bang k?
						if (i < 0 || i >= CTBang.SDong || j < 0 || j >= CTBang.SCot || (i == SX && j == SY)) continue;
						// goi de quy
						moO(i, j);
					}
				}
			}
		}
	}
}

// mo o (phim Z)
void Z(short SX, short SY)
{
	// kiem tra o do k phai la do da mo va o do chua cam co -> mo o
	if (!CTO[SX][SY].BDaMo && !CTO[SX][SY].BCamnCo)
	{
		moO(SX, SY);
		//cap nhat ve lai bang
		if (BTrangThaiDangChoi)
		{
			if (CTBang.SSoOOaMo + CTBang.SSoBom == CTBang.SCot * CTBang.SDong)
			{
				WIN();
			}
		}
		veBang();
	}
}

void WIN()
{
	BTrangThaiDangChoi = false;
	STrangThai = 2;
	deleteRow(7, 1);
	veTrangThaiChoiGame();
}

void LOSE()
{
	for (int i = 0; i < CTBang.SDong; ++i)
	{
		for (int j = 0; j < CTBang.SCot; ++j)
		{
			if (CTO[i][j].BCamnCo && CTO[i][j].BCoBom)
				veO(j, i, 9);
			else if (CTO[i][j].BCamnCo && !CTO[i][j].BCoBom)
				veO(j, i, 14);
			else if (!CTO[i][j].BDaMo && CTO[i][j].BCoBom)
				veO(j, i, 15);
		}
	}
	BTrangThaiDangChoi = false;
	STrangThai = 3;
	deleteRow(7, 1);
	veTrangThaiChoiGame();
}

// ham xu ly phim tu ban phim do nguoi dung nhap vao
void xuLyPhim(KEY_EVENT_RECORD key)
{
	if (key.bKeyDown) // co nhan phim
	{
		switch (key.wVirtualKeyCode)
		{
		case VK_UP:
			if (BTrangThaiDangChoi)
			{
				BSuDungPhim = true;
				CViTriConTro.Y = ((CViTriConTro.Y == 0) ? CTBang.SDong - 1 : CViTriConTro.Y - 1);
				veBang();
			}
			break;
		case VK_DOWN:
			if (BTrangThaiDangChoi)
			{
				BSuDungPhim = true;
				CViTriConTro.Y = ((CViTriConTro.Y == CTBang.SDong - 1) ? 0 : CViTriConTro.Y + 1);
				veBang();
			}
			break;
		case VK_LEFT:
			if (BTrangThaiDangChoi)
			{
				BSuDungPhim = true;
				CViTriConTro.X = ((CViTriConTro.X == 0) ? CTBang.SCot - 1 : CViTriConTro.X - 1);
				veBang();
			}
			break;
		case VK_RIGHT:
			if (BTrangThaiDangChoi)
			{
				BSuDungPhim = true;
				CViTriConTro.X = ((CViTriConTro.X == CTBang.SCot - 1) ? 0 : CViTriConTro.X + 1);
				veBang();
			}
			break;
		case VK_RETURN:
			
			break;
		case VK_ESCAPE:
			
			break;
			// Z
		case 0x5A:
			if (BTrangThaiDangChoi)
			{
				Z(CViTriConTro.Y, CViTriConTro.X);
			}
			break;
			// X
		case 0x58:
			if (BTrangThaiDangChoi)
			{
				X(CViTriConTro.Y, CViTriConTro.X); // CTO la bang 2 chieu tao tu dong(y) den cot(x) 
			}
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
	for (i = 0; i < ConsoleWidth; ++i)
	{
		printf("%c", 45);
	}
	Taomauo(ConsoleWidth / 2 - 8 , 2, 6, 0, "MINESWEEPER GAME \n");
	cout  << endl;
	setColor(7);
	setBackgroundColor(0);
	for (i = 0; i < ConsoleWidth; ++i)
	{
		printf("%c", 45);
	}
}

void veTrangThaiChoiGame()
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
	else if (STrangThai == 2)
	{
		setColor(6); // status win
		for (int i = 0; i <= ConsoleWidth/2 -3 ; ++i)
		{
			cout << " ";
		}
		cout << "WIN";
	}
	else if (STrangThai == 3)
	{
		setColor(4); // status lose
		for (int i = 0; i <= ConsoleWidth/2 - 4; ++i)
		{
			cout << " ";
		}
		cout << "LOSE";
	}
	setColor(7);
}
