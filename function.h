#include<Windows.h>
#include <stdlib.h> 
#include <time.h>
#include <stdio.h>
#include <fstream>
#include "main.h"
#include <vector>

using namespace std;

int getTime(fileTime t);
template<typename T>
void HoanVi(T& a, T& b);

void constructRanking(vector<fileTime>& arr);

void writeFileRanking(vector<fileTime> arr);

void readFileRanking(vector<fileTime>& arr);

void printRanking(vector<fileTime> arr);


void luuToaDoXY();
void taoMang2ChieuDong();
void veKhung();
void khoiTao(short SDong, short SCot, short SSoBom);
short toadoXao(short Sy);
short toadoYao(short Sy);
void veO(short Sx, short Sy, short So);
void veBang();
void taoBomNgauNhien();
void X(short SX, short SY);
short demBomLanCan(short SX, short SY);
void moO(short SX, short SY);
void Z(short SX, short SY);
void WIN();
void LOSE();
void veTittle();
void veTrangThaiChoiGame();
void veMenuChinh();
void veMenuChonCapDo();
void xuLyPhim(KEY_EVENT_RECORD key);
void xuLySuKien();


