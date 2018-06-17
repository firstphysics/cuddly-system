
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<math.h>
#include <tchar.h>

void startup();
int Attack1(char *p, int *pmov, int *pHP1, int *pHP2, int *pa, int *pb, int *pc, int *pd, int *pe, int arr[640][640]);
int Whole(int *pmov, int *pHP1, int *pHP2, int *pa, int *pb, int *pc, int *pd, int *pe, int arr[640][640]);
int Whole2(int *pmov, int *pHP1, int *pHP2, int *pa, int *pb, int *pc, int *pd, int *pe, int arr[640][640]);
void map(int arr[640][640]);
void end(int *pz);
void landmine(int *pmov, int *pHP1, int *pHP2, int arr[640][640]);
void cure(int *pmov, int arr[640][640]);
void text(int *pmov, int *pHP1, int *pHP2);
int NPC(char *p, int *pmov, int *pHP1, int *pHP2, int *pa, int *pb, int *pc, int *pd, int *pe, int arr[640][640]);
int main()
{
	int iw = 0;
	int mov = 6;
	int HP1 = 3, HP2 = 3;
	int *pHP1 = &HP1, *pHP2 = &HP2;
	int z = 0;
	int *pz = &z;
	char chwhole;
	int a, b, c, d, e;
	int *pa = &a, *pb = &b, *pc = &c, *pd = &d, *pe = &e;
	int *pmov = &mov;
	typedef int arr640_i_t[640];
	arr640_i_t * arr = (arr640_i_t*)malloc(640 * sizeof(arr640_i_t));
	arr[640][640] = {};

	initgraph(900, 640);
	a = 21;
	b = 75;
	c = 21;
	d = 546;
	e = 546;
	startup();

	while (HP1 != 0 && HP2 != 0)
	{
		if (_kbhit())
		{
			chwhole = _getch();
			switch (chwhole)
			{
			case 'v':
				closegraph();
				initgraph(900, 640);
				map(arr);
				Whole(pmov, pHP1, pHP2, pa, pb, pc, pd, pe, arr);
				z = Whole(pmov, pHP1, pHP2, pa, pb, pc, pd, pe, arr);
				clearrectangle(1, 1, 640, 640);
				break;
			case 'b':
				closegraph();
				initgraph(900, 640);
				map(arr);
				Whole2(pmov, pHP1, pHP2, pa, pb, pc, pd, pe, arr);
				z = Whole2(pmov, pHP1, pHP2, pa, pb, pc, pd, pe, arr);
				clearrectangle(1, 1, 640, 640);
				break;

			}

		}
	}



	end(pz);

}


void startup()
{
	int i;
	TCHAR HP11[] = _T("RULES");
	TCHAR HP22[] = _T("1.use arrows and w a s d to move the players");
	TCHAR HP33[] = _T("2.use t f g h and i j k l to attack");
	TCHAR HP44[] = _T("3.landmine and first aid kit will appear to ");
	TCHAR HP444[] = _T("   assist you or attack you");
	TCHAR HP55[] = _T("4.every player's initial HP is 3");
	TCHAR HP66[] = _T("5.landmine will minus 2 HP and normal attack will minus 1 HP");
	TCHAR HP77[] = _T("6.press'v'to enter pvp mode and 'b' to enter pve mode");
	outtextxy(500, 80, HP11);
	outtextxy(500, 100, HP22);
	outtextxy(500, 120, HP33);
	outtextxy(500, 140, HP44);
	outtextxy(500, 160, HP444);
	outtextxy(500, 180, HP55);
	outtextxy(500, 200, HP66);
	outtextxy(500, 220, HP77);
	solidcircle(290, 280, 200);
	for (i = 10; i <= 100; i += 10)
	{
		setfillcolor(RED);
		solidcircle(200, 140 + i, 5);
	}
	for (i = 10; i <= 50; i += 10)
	{
		setfillcolor(RED);
		solidcircle(200 + i, 150, 5);
	}
	for (i = 10; i <= 30; i += 10)
	{
		setfillcolor(RED);
		solidcircle(250, 150 + i, 5);
	}
	for (i = 10; i <= 50; i += 10)
	{
		setfillcolor(RED);
		solidcircle(200 + i, 190, 5);
	}//letter 'P'
	for (i = 10; i <= 100; i += 10)
	{
		setfillcolor(BLUE);
		solidcircle(320, 140 + i, 5);
	}
	for (i = 10; i <= 50; i += 10)
	{
		setfillcolor(BLUE);
		solidcircle(320 + i, 240, 5);
	}
	for (i = 10; i <= 100; i += 10)
	{
		setfillcolor(BLUE);
		solidcircle(370, 140 + i, 5);
	}//letter 'U'
	for (i = 10; i <= 100; i += 10)
	{
		setfillcolor(BLUE);
		solidcircle(200, 250 + i, 5);
	}
	for (i = 10; i <= 50; i += 10)
	{
		setfillcolor(BLUE);
		solidcircle(200 + i, 260, 5);
	}
	for (i = 10; i <= 90; i += 10)
	{
		setfillcolor(BLUE);
		solidcircle(250, 260 + i, 5);
	}
	for (i = 10; i <= 50; i += 10)
	{
		setfillcolor(BLUE);
		solidcircle(200 + i, 300, 5);
	}
	for (i = 10; i <= 50; i += 10)
	{
		setfillcolor(BLUE);
		solidcircle(200 + i, 350, 5);
	}//letter 'B'
	for (i = 10; i <= 100; i += 10)
	{
		setfillcolor(RED);
		solidcircle(320, 250 + i, 5);
	}
	for (i = 10; i <= 50; i += 10)
	{
		setfillcolor(RED);
		solidcircle(320 + i, 260, 5);
	}
	for (i = 10; i <= 90; i += 10)
	{
		setfillcolor(RED);
		solidcircle(370, 260 + i, 5);
	}
	for (i = 10; i <= 50; i += 10)
	{
		setfillcolor(RED);
		solidcircle(320 + i, 300, 5);
	}
	RECT r = { -70, 150, 640, 640 };
	drawtext(_T("Press any key to continue!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

}

void map(int arr[640][640])
{
	IMAGE wall, background;
	int i, j, m, q;
	loadimage(&background, L"D:/Cprogram/timg3.jpg", 75, 75);
	for (m = 21, q = 75, i = 0; i <= 7; i++)
	{
		for (j = 0; j <= 7; j++)
		{
			putimage(m + i * q, m + j * q, &background);
		}
	}
	loadimage(&wall, L"D:/Cprogram/timg2.jpg", 75, 75);
	putimage(96, 21, &wall);
	for (i = 95; i <= 170; i++)
	{
		for (j = 21; j <= 95; j++)
		{
			arr[i][j] = 101;
		}
	}
	putimage(96, 171, &wall);
	for (i = 95; i <= 170; i++)
	{
		for (j = 171; j <= 245; j++)
		{
			arr[i][j] = 101;
		}
	}
	putimage(96, 246, &wall);
	for (i = 95; i <= 170; i++)
	{
		for (j = 246; j <= 320; j++)
		{
			arr[i][j] = 101;
		}
	}
	putimage(96, 396, &wall);
	for (i = 95; i <= 170; i++)
	{
		for (j = 396; j <= 470; j++)
		{
			arr[i][j] = 101;
		}
	}
	putimage(96, 471, &wall);
	for (i = 95; i <= 169; i++)
	{
		for (j = 470; j <= 544; j++)
		{
			arr[i][j] = 101;
		}
	}
	putimage(21, 246, &wall);
	for (i = 20; i <= 94; i++)
	{
		for (j = 245; j <= 319; j++)
		{
			arr[i][j] = 101;
		}
	}
	putimage(171, 471, &wall);
	for (i = 170; i <= 245; i++)
	{
		for (j = 470; j <= 544; j++)
		{
			arr[i][j] = 101;
		}
	}
	putimage(171, 546, &wall);
	for (i = 170; i <= 245; i++)
	{
		for (j = 545; j <= 619; j++)
		{
			arr[i][j] = 101;
		}
	}
	putimage(246, 21, &wall);
	for (i = 245; i <= 319; i++)
	{
		for (j = 20; j <= 94; j++)
		{
			arr[i][j] = 101;
		}
	}
	putimage(246, 171, &wall);
	for (i = 245; i <= 319; i++)
	{
		for (j = 170; j <= 244; j++)
		{
			arr[i][j] = 101;
		}
	}
	putimage(246, 321, &wall);
	for (i = 245; i <= 319; i++)
	{
		for (j = 320; j <= 394; j++)
		{
			arr[i][j] = 101;
		}
	}
	putimage(321, 246, &wall);
	for (i = 320; i <= 394; i++)
	{
		for (j = 245; j <= 319; j++)
		{
			arr[i][j] = 101;
		}
	}
	putimage(321, 396, &wall);
	for (i = 320; i <= 394; i++)
	{
		for (j = 395; j <= 469; j++)
		{
			arr[i][j] = 101;
		}
	}
	putimage(321, 546, &wall);
	for (i = 320; i <= 394; i++)
	{
		for (j = 545; j <= 619; j++)
		{
			arr[i][j] = 101;
		}
	}
	putimage(396, 21, &wall);
	for (i = 395; i <= 470; i++)
	{
		for (j = 20; j <= 94; j++)
		{
			arr[i][j] = 101;
		}
	}
	putimage(396, 96, &wall);
	for (i = 395; i <= 470; i++)
	{
		for (j = 95; j <= 169; j++)
		{
			arr[i][j] = 101;
		}
	}
	putimage(471, 96, &wall);
	for (i = 470; i <= 544; i++)
	{
		for (j = 95; j <= 169; j++)
		{
			arr[i][j] = 101;
		}
	}
	putimage(471, 171, &wall);
	for (i = 470; i <= 544; i++)
	{
		for (j = 170; j <= 244; j++)
		{
			arr[i][j] = 101;
		}
	}
	putimage(471, 321, &wall);
	for (i = 470; i <= 544; i++)
	{
		for (j = 320; j <= 394; j++)
		{
			arr[i][j] = 101;
		}
	}
	putimage(471, 396, &wall);
	for (i = 470; i <= 544; i++)
	{
		for (j = 395; j <= 469; j++)
		{
			arr[i][j] = 101;
		}
	}
	putimage(471, 546, &wall);
	for (i = 470; i <= 544; i++)
	{
		for (j = 545; j <= 619; j++)
		{
			arr[i][j] = 101;
		}
	}
	putimage(546, 321, &wall);
	for (i = 545; i <= 619; i++)
	{
		for (j = 320; j <= 395; j++)
		{
			arr[i][j] = 101;
		}
	}
	setfillcolor(BLACK);
	bar(1, 1, 19, 640);
	bar(1, 1, 640, 19);
	bar(621, 1, 640, 640);
	bar(1, 621, 640, 640);
}

void text(int *pmov, int *pHP1, int *pHP2)
{
	TCHAR HP11[] = _T("HP1=");
	TCHAR HP22[] = _T("HP2=");
	TCHAR HP111[6];
	TCHAR HP222[6];
	if (*pmov >= 0)
	{
		wsprintf(HP111, _T("%d"), *pHP1);
		wsprintf(HP222, _T("%d"), *pHP2);

		//char PLAY='PLAY',ER2='ER2',ER1='ER1';
		settextcolor(WHITE);

		outtextxy(700, 80, HP11);
		outtextxy(700, 100, HP22);
		outtextxy(800, 80, HP111);
		outtextxy(800, 100, HP222);
	}
}

int Attack1(char *p, int *pmov, int *pHP1, int *pHP2, int *pa, int *pb, int *pc, int *pd, int *pe, int arr[640][640])
{
	IMAGE img1, img2, bullet;
	IMAGE wall, background;
	IMAGE background1, background2;
	int z = 0;
	int up, dw, lf, rg;
	loadimage(&wall, L"D:/Cprogram/timg2.jpg", 75, 75);
	loadimage(&background, L"D:/Cprogram/timg3.jpg", 75, 75);
	loadimage(&img1, L"D:/Cprogram/timg1.jpg", 75, 75);
	loadimage(&bullet, L"D:/Cprogram/timg4.jpg", 5, 5);
	loadimage(&img2, L"D:/Cprogram/timg1.jpg", 75, 75);
	switch (*p)
	{
	case 't':

		if (20 <= *pa + 10 && *pa + 10 <= 590 && arr[*pa + 37][*pc - 3] <= 98 && *pc - 3 <= 590 && *pc - 3 >= 20 && *pmov % 6 <= 2)
		{
			for (up = 3; 20 <= *pa + 10 && *pa + 10 <= 590 && arr[*pa + 37][*pc - up] <= 98 && *pc - up <= 590 && *pc - up >= 20 && *pmov % 6 <= 2; up++)
			{
				getimage(&background1, *pa + 35, *pc - up - 7, 5, 5);
				putimage(*pa + 35, *pc - up - 2, &bullet);
				Sleep(10);
				putimage(*pa + 35, *pc - up - 2, &background1);
				putimage(*pd, *pe, &img2);
			}
			*pmov += 1;
			if (arr[*pa + 37][*pc - up] == 99)
			{
				*pHP2 = *pHP2 - 1;
			}
		}
		break;
	case 'g':
		if (20 <= *pa + 10 && *pa + 10 <= 590 && arr[*pa + 37][*pc + 3 + 75] <= 98 && *pc + 3 <= 590 && *pc + 3 >= 20 && *pmov % 6 <= 2)
		{
			for (dw = 3; 20 <= *pa + 10 && *pa + 10 <= 590 && arr[*pa + 37][*pc + dw + 75] <= 98 && *pc + dw <= 590 && *pc + dw >= 20 && *pmov % 6 <= 2; dw++)
			{
				getimage(&background1, *pa + 35, *pc + dw + 78, 5, 5);
				putimage(*pa + 35, *pc + dw + 73, &bullet);
				Sleep(10);
				putimage(*pa + 35, *pc + dw + 73, &background1);
				putimage(*pd, *pe, &img2);
			}
			*pmov += 1;

			if (arr[*pa + 37][*pc + dw + 75] == 99)
			{
				*pHP2 = *pHP2 - 1;
			}
		}
		break;
	case 'f':
		if (20 <= *pa - 3 && *pa - 3 <= 590 && arr[*pa - 3][*pc + 37] <= 98 && *pc + 10 <= 590 && *pc + 10 >= 20 && *pmov % 6 <= 2)
		{
			for (lf = 3; 20 <= *pa - lf && *pa - lf <= 590 && arr[*pa - lf][*pc + 37] <= 98 && *pc + 10 <= 590 && *pc + 10 >= 20 && *pmov % 6 <= 2; lf++)
			{
				getimage(&background1, *pa - lf - 7, *pc + 35, 5, 5);
				putimage(*pa - lf - 2, *pc + 35, &bullet);
				Sleep(10);
				putimage(*pa - lf - 2, *pc + 35, &background1);
				putimage(*pd, *pe, &img2);
			}
			*pmov += 1;
			if (arr[*pa - lf][*pc + 37] == 99)
			{
				*pHP2 = *pHP2 - 1;
			}
		}
		break;
	case'h':
		if (20 <= *pa + 3 && *pa + 3 <= 590 && arr[*pa + 3 + 75][*pc + 37] <= 98 && *pc + 10 <= 590 && *pc + 10 >= 20 && *pmov % 6 <= 2)
		{
			for (rg = 3; 20 <= *pa + rg && *pa + rg <= 590 && arr[*pa + rg + 75][*pc + 37] <= 98 && *pc + 10 <= 590 && *pc + 10 >= 20 && *pmov % 6 <= 2; rg++)
			{
				getimage(&background1, *pa + rg + 78, *pc + 35, 5, 5);
				putimage(*pa + rg + 73, *pc + 35, &bullet);
				Sleep(10);
				putimage(*pa + rg + 73, *pc + 35, &background1);
				putimage(*pd, *pe, &img2);
			}
			*pmov += 1;
			if (arr[*pa + rg + 75][*pc + 37] == 99)
			{
				*pHP2 = *pHP2 - 1;
			}
		}
		break;
	case 'i':
		if (20 <= *pd + 10 && *pd + 10 <= 590 && arr[*pd + 37][*pe - 3] <= 98 && *pe - 3 <= 590 && *pe - 3 >= 20 && *pmov % 6 > 2 && *pmov % 6 <= 5)
		{
			for (up = 3; 20 <= *pd + 10 && *pd + 10 <= 590 && arr[*pd + 37][*pe - up] <= 98 && *pe - up <= 590 && *pe - up >= 20 && *pmov % 6 > 2 && *pmov % 6 <= 5; up++)
			{
				getimage(&background1, *pd + 35, *pe - up - 7, 5, 5);
				putimage(*pd + 35, *pe - up - 2, &bullet);
				Sleep(10);
				putimage(*pd + 35, *pe - up - 2, &background1);
				putimage(*pa, *pc, &img1);
			}
			*pmov += 1;
			if (arr[*pd + 37][*pe - up] == 100)
			{
				*pHP1 -= 1;
			}
		}
		break;
	case 'k':
		if (20 <= *pd + 10 && *pd + 10 <= 590 && arr[*pd + 37][*pe + 3 + 75] <= 98 && *pe + 3 <= 590 && *pe + 3 >= 20 && *pmov % 6 > 2 && *pmov % 6 <= 5)
		{
			for (dw = 3; 20 <= *pd + 10 && *pd + 10 <= 590 && arr[*pd + 37][*pe + dw + 75] <= 98 && *pe + dw <= 590 && *pe + dw >= 20 && *pmov % 6 > 2 && *pmov % 6 <= 5; dw++)
			{
				getimage(&background1, *pd + 35, *pe + dw + 78, 5, 5);
				putimage(*pd + 35, *pe + dw + 73, &bullet);
				Sleep(10);
				putimage(*pd + 35, *pe + dw + 73, &background1);
				putimage(*pa, *pc, &img1);
			}
			*pmov += 1;
			if (arr[*pd + 37][*pe + dw + 75] == 100)
			{
				*pHP1 -= 1;
			}
		}
		break;
	case 'j':
		if (20 <= *pd - 3 && *pd - 3 <= 590 && arr[*pd - 3][*pe + 37] <= 98 && *pe + 10 <= 590 && *pe + 10 >= 20 && *pmov % 6 > 2 && *pmov % 6 <= 5)
		{
			for (lf = 3; 20 <= *pd - lf && *pd - lf <= 590 && arr[*pd - lf][*pe + 37] <= 98 && *pe + 10 <= 590 && *pe + 10 >= 20 && *pmov % 6 > 2 && *pmov % 6 <= 5; lf++)
			{
				getimage(&background1, *pd - lf - 7, *pe + 35, 5, 5);
				putimage(*pd - lf - 2, *pe + 35, &bullet);
				Sleep(10);
				putimage(*pd - lf - 2, *pe + 35, &background1);
				putimage(*pa, *pc, &img1);
			}
			*pmov += 1;
			if (arr[*pd - lf][*pe + 37] == 100)
			{
				*pHP1 -= 1;
			}
		}

		break;
	case'l':
		if (20 <= *pd + 3 && *pd + 3 <= 590 && arr[*pd + 75 + 3][*pe + 37] <= 98 && *pe + 10 <= 590 && *pe + 10 >= 20 && *pmov % 6 > 2 && *pmov % 6 <= 5)
		{
			for (rg = 3; 20 <= *pd + rg && *pd + rg <= 590 && arr[*pd + 75 + rg][*pe + 37] <= 98 && *pe + 10 <= 590 && *pe + 10 >= 20 && *pmov % 6 > 2 && *pmov % 6 <= 5; rg++)
			{
				getimage(&background1, *pd + rg + 78, *pe + 35, 5, 5);
				putimage(*pd + rg + 73, *pe + 35, &bullet);
				Sleep(10);
				putimage(*pd + rg + 73, *pe + 35, &background1);
				putimage(*pa, *pc, &img1);
			}
			*pmov += 1;
			if (arr[*pd + 75 + rg][*pe + 37] == 100)         //judge whether the bullet has touched the player
			{
				*pHP1 -= 1;
			}
		}
		break;

	case 'w':
		if (arr[*pa + 37][*pc - 38] == 96)
		{
			*pHP1 += 1;
		}
		if (95 <= *pc && arr[*pa + 37][*pc - 38] <= 98 && *pmov % 6 <= 2)   //judge whether there is obstabcle and is this the turn for player1
		{
			arr[*pa + 37][*pc + 37] = 0;                                //assign 0 to the original place
			putimage(*pa, *pc, &background);                            //Put the background in the original area
			putimage(*pa, *pc - *pb, &img1);                              //Put the image in the target area 
			*pa = *pa;
			*pc = *pc - *pb;
			arr[*pa + 37][*pc + 37] = 100;                              //assign 100 to the new place
			*pmov += 1;
		}
		else
		{
			putimage(*pa, *pc, &img1);
		}
		break;

	case 's':
		if (arr[*pa + 37][*pc + 37 + 75] == 96)
		{
			*pHP1 += 1;
		}
		if (*pc <= 545 && arr[*pa + 37][*pc + 37 + 75] <= 98 && *pmov % 6 <= 2)
		{
			arr[*pa + 37][*pc + 37] = 0;
			clearrectangle(*pa, *pc, *pa + 74, *pc + 74);
			putimage(*pa, *pc, &background);
			putimage(*pa, *pc + *pb, &img1);
			*pa = *pa;
			*pc = *pc + *pb;
			arr[*pa + 37][*pc + 37] = 100;
			*pmov += 1;
		}
		else
		{
			putimage(*pa, *pc, &img1);
		}
		break;

	case 'a':
		if (arr[*pa - 38][*pc + 37] == 96)
		{
			*pHP1 += 1;
		}
		if (95 <= *pa && arr[*pa - 38][*pc + 37] <= 98 && *pmov % 6 <= 2)
		{

			arr[*pa + 37][*pc + 37] = 0;
			clearrectangle(*pa, *pc, *pa + 74, *pc + 74);
			putimage(*pa, *pc, &background);
			putimage(*pa - *pb, *pc, &img1);
			*pa = *pa - *pb;
			*pc = *pc;
			arr[*pa + 37][*pc + 37] = 100;
			*pmov += 1;
		}
		else
		{
			putimage(*pa, *pc, &img1);
		}
		break;

	case 'd':
		if (arr[*pa + 37 + 75][*pc + 37] == 96)
		{
			*pHP1 += 1;
		}
		if (*pa <= 545 && arr[*pa + 37 + 75][*pc + 37] <= 98 && *pmov % 6 <= 2)
		{
			arr[*pa + 37][*pc + 37] = 0;
			clearrectangle(*pa, *pc, *pa + 74, *pc + 74);
			putimage(*pa, *pc, &background);
			putimage(*pa + *pb, *pc, &img1);
			*pa = *pa + *pb;
			*pc = *pc;
			arr[*pa + 37][*pc + 37] = 100;
			*pmov += 1;
		}
		else
		{
			putimage(*pa, *pc, &img1);
		}
		break;
	case 72:
		if (arr[*pd + 37][*pe - 38] == 96)
		{
			*pHP2 += 1;
		}
		if (95 <= *pe && arr[*pd + 37][*pe - 38] <= 98 && *pmov % 6 > 2 && *pmov % 6 <= 5)
		{
			arr[*pd + 37][*pe + 37] = 0;
			clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
			putimage(*pd, *pe, &background);
			putimage(*pd, *pe - *pb, &img2);
			*pd = *pd;
			*pe = *pe - *pb;
			arr[*pd + 37][*pe + 37] = 99;
			*pmov += 1;
		}
		else
		{
			putimage(*pd, *pe, &img2);
		}
		break;

	case 80:
		if (arr[*pd + 37][*pe + 75 + 37] == 96)
		{
			*pHP2 += 1;
		}
		if (*pe <= 545 && arr[*pd + 37][*pe + 37 + 75] <= 98 && *pmov % 6 > 2 && *pmov % 6 <= 5)
		{
			arr[*pd + 37][*pe + 37] = 0;
			clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
			putimage(*pd, *pe, &background);
			putimage(*pd, *pe + *pb, &img2);
			*pd = *pd;
			*pe = *pe + *pb;
			arr[*pd + 37][*pe + 37] = 99;
			*pmov += 1;
		}
		else
		{
			putimage(*pd, *pe, &img2);
		}
		break;

	case 75:
		if (arr[*pd - 38][*pe + 37] == 96)
		{
			*pHP2 += 1;
		}
		if (95 <= *pd && arr[*pd - 38][*pe + 37] <= 98 && *pmov % 6 > 2 && *pmov % 6 <= 5)
		{
			arr[*pd + 37][*pe + 37] = 0;
			clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
			putimage(*pd, *pe, &background);
			putimage(*pd - *pb, *pe, &img2);
			*pd = *pd - *pb;
			*pe = *pe;
			arr[*pd + 37][*pe + 37] = 99;
			*pmov += 1;
		}
		else
		{
			putimage(*pd, *pe, &img2);
		}
		break;

	case 77:
		if (arr[*pd + 37 + 75][*pe + 37] == 96)
		{
			*pHP2 += 1;
		}
		if (*pd <= 545 && arr[*pd + 37 + 75][*pe + 37] <= 98 && *pmov % 6 > 2 && *pmov % 6 <= 5)
		{
			arr[*pd + 37][*pe + 37] = 0;
			clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
			putimage(*pd, *pe, &background);
			putimage(*pd + *pb, *pe, &img2);
			*pd = *pd + *pb;
			*pe = *pe;
			arr[*pd + 37][*pe + 37] = 99;
			*pmov += 1;
		}
		else
		{
			putimage(*pd, *pe, &img2);
		}
		break;
	}

	if (*pHP1 == 0)
	{
		clearrectangle(*pa, *pc, *pa + 75, *pc + 75);
		putimage(*pa, *pc, &background);
		z = 2;
	}

	if (*pHP2 == 0)
	{
		clearrectangle(*pd, *pe, *pd + 75, *pe + 75);
		putimage(*pd, *pe, &background);
		z = 1;

	}
	return z;
}


void landmine(int *pmov, int *pHP1, int *pHP2, int arr[640][640])
{
	IMAGE flame, STORE;
	IMAGE landmine1;
	IMAGE wall, background;
	int i, q;
	loadimage(&wall, L"D:/Cprogram/timg2.jpg", 75, 75);
	loadimage(&background, L"D:/Cprogram/timg3.jpg", 75, 75);
	int wid[10], hei[10];
	loadimage(&flame, L"D:/Cprogram/flame.jpg", 75, 75);
	loadimage(&landmine1, L"D:/Cprogram/timg5.jpg", 75, 75);
	q = *pmov / 12;
	//find the coordinate
	for (i = 0; i <= 9; i++)
	{
		if (i % 2 == 0)
		{
			wid[i] = 3;
		}
		else
		{
			wid[i] = 4;
		}
	}
	for (i = 0; i <= 9; i++)
	{
		if (i % 2 == 0)
		{
			hei[i] = 2;
		}
		else
		{
			hei[i] = 5;
		}
	}

	if (*pmov % 12 == 0)                                                         // put the landmine
	{
		putimage(wid[q] * 75 + 21, hei[q] * 75 + 21, &landmine1);
	}
	if (*pmov % 12 == 11 && *pmov >= 12)                                             //the landmine explodes 
	{

		getimage(&STORE, wid[q] * 75 - 75 + 21, hei[q] * 75 - 75 + 21, 225, 225);
		putimage(wid[q] * 75 - 75 + 21, hei[q] * 75 + 21, &flame);
		putimage(wid[q] * 75 + 75 + 21, hei[q] * 75 + 21, &flame);
		putimage(wid[q] * 75 + 21, hei[q] * 75 - 75 + 21, &flame);
		putimage(wid[q] * 75 + 21, hei[q] * 75 + 75 + 21, &flame);
		Sleep(100);
		putimage(wid[q] * 75 - 75 + 21, hei[q] * 75 - 75 + 21, &STORE);
		putimage(wid[q] * 75 + 21, hei[q] * 75 + 21, &wall);
		if (arr[wid[q] * 75 + 75 + 21 + 37][hei[q] * 75 + 21 + 37] == 99)       //judge whether the bomb attacks the players.
		{
			*pHP2 -= 1;
		}
		if (arr[wid[q] * 75 - 75 + 21 + 37][hei[q] * 75 + 21 + 37] == 99)
		{
			*pHP2 -= 1;
		}
		if (arr[wid[q] * 75 + 21 + 37][hei[q] * 75 + 75 + 21 + 37] == 99)
		{
			*pHP2 -= 1;
		}
		if (arr[wid[q] * 75 + 21 + 37][hei[q] * 75 - 75 + 21 + 37] == 99)
		{
			*pHP2 -= 1;
		}
		if (arr[wid[q] * 75 + 75 + 21 + 37][hei[q] * 75 + 21 + 37] == 100)
		{
			*pHP1 -= 1;
		}
		if (arr[wid[q] * 75 - 75 + 21 + 37][hei[q] * 75 + 21 + 37] == 100)
		{
			*pHP1 -= 1;
		}
		if (arr[wid[q] * 75 + 21 + 37][hei[q] * 75 + 75 + 21 + 37] == 100)
		{
			*pHP1 -= 1;
		}
		if (arr[wid[q] * 75 + 21 + 37][hei[q] * 75 - 75 + 21 + 37] == 100)
		{
			*pHP1 -= 1;
		}

	}
}

void cure(int *pmov, int arr[640][640])
{
	int l;
	int q1;
	int store = 0;
	int sub3[100], sub4[100];
	int i, sub = 0;
	int wid1[10], hei1[10] = {};
	IMAGE bag1;
	IMAGE wall, background;
	loadimage(&wall, L"D:/Cprogram/timg2.jpg", 75, 75);
	loadimage(&background, L"D:/Cprogram/timg3.jpg", 75, 75);
	srand((unsigned)time(NULL));
	for (i = 0; i <= 9; i++)
	{
		wid1[i] = i % 3 + 2;
	}
	//hei1[10] = {};
	q1 = *pmov / 12;
	loadimage(&bag1, L"D:/Cprogram/timg6.jpg", 75, 75);
	for (i = 0; i <= 99; i++)
	{
		sub3[i] = rand() % 8;
	}
	for (i = 0; i <= 99; i++)
	{
		sub4[i] = rand() % 8;
	}                                                    //get the coordinate randomly
	for (l = 0; l <= 9; l++)
	{
		for (i = store; arr[wid1[l] * 75 + 21 + 37][hei1[l] * 75 + 21 + 37] >= 98; i++)
		{
			wid1[l] = sub3[i];
			hei1[l] = sub4[i];
		}
		store = i + 1;
	}
	if (arr[wid1[q1] * 75 + 21 + 37][hei1[q1] * 75 + 21 + 37] <= 97 && *pmov % 12 == 0)       // put the the first aid kit
	{
		putimage(wid1[q1] * 75 + 21, hei1[q1] * 75 + 21, &bag1);
		arr[wid1[q1] * 75 + 21 + 37][hei1[q1] * 75 + 21 + 37] = 96;
		sub = q1;
	}

}

int Whole(int *pmov, int *pHP1, int *pHP2, int *pa, int *pb, int *pc, int *pd, int *pe, int arr[640][640])
{
	IMAGE img1, img2, bullet;
	int z = 0;
	char ch;
	char *p = &ch;
	loadimage(&img1, L"D:/Cprogram/timg1.jpg", 75, 75);
	loadimage(&bullet, L"D:/Cprogram/timg4.jpg", 5, 5);
	loadimage(&img2, L"D:/Cprogram/timg1.jpg", 75, 75);
	solidcircle(3, 3, 2);
	putimage(20, 20, &img1);
	putimage(546, 546, &img2);
	setfillcolor(GREEN);
	bar(1, 1, 19, 640);
	bar(1, 1, 640, 19);
	bar(621, 1, 640, 640);
	bar(1, 621, 640, 640);



	while (*pHP1 != 0 && *pHP2 != 0)
	{
		if (_kbhit())
		{
			ch = _getch();
			Attack1(p, pmov, pHP1, pHP2, pa, pb, pc, pd, pe, arr);
			landmine(pmov, pHP1, pHP2, arr);
			cure(pmov, arr);
			text(pmov, pHP1, pHP2);
		}
	}
	z = Attack1(p, pmov, pHP1, pHP2, pa, pb, pc, pd, pe, arr);

	system("pause");
	return z;
}
int Whole2(int *pmov, int *pHP1, int *pHP2, int *pa, int *pb, int *pc, int *pd, int *pe, int arr[640][640])
{
	IMAGE img1, img2, bullet;
	int z = 0;
	char ch;
	char *p = &ch;
	loadimage(&img1, L"D:/Cprogram/timg1.jpg", 75, 75);
	loadimage(&bullet, L"D:/Cprogram/timg4.jpg", 5, 5);
	loadimage(&img2, L"D:/Cprogram/timg1.jpg", 75, 75);
	solidcircle(3, 3, 2);
	putimage(20, 20, &img1);
	putimage(546, 546, &img2);
	setfillcolor(GREEN);
	bar(1, 1, 19, 640);
	bar(1, 1, 640, 19);
	bar(621, 1, 640, 640);
	bar(1, 621, 640, 640);



	while (*pHP1 != 0 && *pHP2 != 0)
	{
		if (_kbhit())
		{
			ch = _getch();
			NPC(p, pmov, pHP1, pHP2, pa, pb, pc, pd, pe, arr);
			text(pmov, pHP1, pHP2);
		}
	}
	z = NPC(p, pmov, pHP1, pHP2, pa, pb, pc, pd, pe, arr);


	system("pause");
	return z;
}
void end(int *pz)
{
	clearrectangle(1, 1, 640, 640);
	solidcircle(320, 320, 50);

	if (*pz == 1)
	{
		RECT r = { 0, 0, 640, 640 };
		drawtext(_T("PLAYER1 WINS"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	else
	{
		RECT r = { 0, 0, 640, 640 };
		drawtext(_T("PLAYER2 WINS"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	}
	_getch();
	closegraph();
}

int NPC(char *p, int *pmov, int *pHP1, int *pHP2, int *pa, int *pb, int *pc, int *pd, int *pe, int arr[640][640])
{
	int check[10];
	int z = 0;
	IMAGE img1, img2, bullet;
	IMAGE wall, background;
	IMAGE background1, background2;
	int up, dw, lf, rg;
	int i;
	loadimage(&wall, L"D:/Cprogram/timg2.jpg", 75, 75);
	loadimage(&background, L"D:/Cprogram/timg3.jpg", 75, 75);
	loadimage(&img1, L"D:/Cprogram/timg1.jpg", 75, 75);
	loadimage(&bullet, L"D:/Cprogram/timg4.jpg", 5, 5);
	loadimage(&img2, L"D:/Cprogram/timg1.jpg", 75, 75);
	if (*pmov % 6 <= 2)
	{
		switch (*p)
		{
		case 'w':
			if (arr[*pa + 37][*pc - 38] == 96)
			{
				*pHP1 += 1;
			}
			if (95 <= *pc && arr[*pa + 37][*pc - 38] <= 98 && *pmov % 6 <= 2)
			{
				arr[*pa + 37][*pc + 37] = 0;
				clearrectangle(*pa, *pc, *pa + 74, *pc + 74);
				putimage(*pa, *pc, &background);
				putimage(*pa, *pc - *pb, &img1);
				*pa = *pa;
				*pc = *pc - *pb;
				arr[*pa + 37][*pc + 37] = 100;
				*pmov += 1;
			}
			else
			{
				putimage(*pa, *pc, &img1);
			}
			break;

		case 's':
			if (arr[*pa + 37][*pc + 37 + 75] == 96)
			{
				*pHP1 += 1;
			}
			if (*pc <= 545 && arr[*pa + 37][*pc + 37 + 75] <= 98 && *pmov % 6 <= 2)
			{
				arr[*pa + 37][*pc + 37] = 0;
				clearrectangle(*pa, *pc, *pa + 74, *pc + 74);
				putimage(*pa, *pc, &background);
				putimage(*pa, *pc + *pb, &img1);
				*pa = *pa;
				*pc = *pc + *pb;
				arr[*pa + 37][*pc + 37] = 100;
				*pmov += 1;
			}
			else
			{
				putimage(*pa, *pc, &img1);
			}
			break;

		case 'a':
			if (arr[*pa - 38][*pc + 37] == 96)
			{
				*pHP1 += 1;
			}
			if (95 <= *pa && arr[*pa - 38][*pc + 37] <= 98 && *pmov % 6 <= 2)
			{

				arr[*pa + 37][*pc + 37] = 0;
				clearrectangle(*pa, *pc, *pa + 74, *pc + 74);
				putimage(*pa, *pc, &background);
				putimage(*pa - *pb, *pc, &img1);
				*pa = *pa - *pb;
				*pc = *pc;
				arr[*pa + 37][*pc + 37] = 100;
				*pmov += 1;
			}
			else
			{
				putimage(*pa, *pc, &img1);
			}
			break;

		case 'd':
			if (arr[*pa + 37 + 75][*pc + 37] == 96)
			{
				*pHP1 += 1;
			}
			if (*pa <= 545 && arr[*pa + 37 + 75][*pc + 37] <= 98 && *pmov % 6 <= 2)
			{
				arr[*pa + 37][*pc + 37] = 0;
				clearrectangle(*pa, *pc, *pa + 74, *pc + 74);
				putimage(*pa, *pc, &background);
				putimage(*pa + *pb, *pc, &img1);
				*pa = *pa + *pb;
				*pc = *pc;
				arr[*pa + 37][*pc + 37] = 100;
				*pmov += 1;
			}
			else
			{
				putimage(*pa, *pc, &img1);
			}
			break;
		case 't':

			if (20 <= *pa + 10 && *pa + 10 <= 590 && arr[*pa + 37][*pc - 3] <= 98 && *pc - 3 <= 590 && *pc - 3 >= 20 && *pmov % 6 <= 2)
			{
				for (up = 3; 20 <= *pa + 10 && *pa + 10 <= 590 && arr[*pa + 37][*pc - up] <= 98 && *pc - up <= 590 && *pc - up >= 20 && *pmov % 6 <= 2; up++)
				{
					getimage(&background1, *pa + 35, *pc - up - 7, 5, 5);
					putimage(*pa + 35, *pc - up - 2, &bullet);
					Sleep(10);
					putimage(*pa + 35, *pc - up - 2, &background1);
					putimage(*pd, *pe, &img2);
				}
				*pmov += 1;
				if (arr[*pa + 37][*pc - up] == 99)
				{
					*pHP2 -= 1;
				}
			}
			break;
		case 'g':
			if (20 <= *pa + 10 && *pa + 10 <= 590 && arr[*pa + 37][*pc + 3 + 75] <= 98 && *pc + 3 <= 590 && *pc + 3 >= 20 && *pmov % 6 <= 2)
			{
				for (dw = 3; 20 <= *pa + 10 && *pa + 10 <= 590 && arr[*pa + 37][*pc + dw + 75] <= 98 && *pc + dw <= 590 && *pc + dw >= 20 && *pmov % 6 <= 2; dw++)
				{
					getimage(&background1, *pa + 35, *pc + dw + 78, 5, 5);
					putimage(*pa + 35, *pc + dw + 73, &bullet);
					Sleep(10);
					putimage(*pa + 35, *pc + dw + 73, &background1);
					putimage(*pd, *pe, &img2);
				}
				*pmov += 1;

				if (arr[*pa + 37][*pc + dw + 75] == 99)
				{
					*pHP2 -= 1;
				}
			}
			break;
		case 'f':
			if (20 <= *pa - 3 && *pa - 3 <= 590 && arr[*pa - 3][*pc + 37] <= 98 && *pc + 10 <= 590 && *pc + 10 >= 20 && *pmov % 6 <= 2)
			{
				for (lf = 3; 20 <= *pa - lf && *pa - lf <= 590 && arr[*pa - lf][*pc + 37] <= 98 && *pc + 10 <= 590 && *pc + 10 >= 20 && *pmov % 6 <= 2; lf++)
				{
					getimage(&background1, *pa - lf - 7, *pc + 35, 5, 5);
					putimage(*pa - lf - 2, *pc + 35, &bullet);
					Sleep(10);
					putimage(*pa - lf - 2, *pc + 35, &background1);
					putimage(*pd, *pe, &img2);
				}
				*pmov += 1;
				if (arr[*pa - lf][*pc + 37] == 99)
				{
					*pHP2 -= 1;
				}
			}
			break;
		case'h':
			if (20 <= *pa + 3 && *pa + 3 <= 590 && arr[*pa + 3 + 75][*pc + 37] <= 98 && *pc + 10 <= 590 && *pc + 10 >= 20 && *pmov % 6 <= 2)
			{
				for (rg = 3; 20 <= *pa + rg && *pa + rg <= 590 && arr[*pa + rg + 75][*pc + 37] <= 98 && *pc + 10 <= 590 && *pc + 10 >= 20 && *pmov % 6 <= 2; rg++)
				{
					getimage(&background1, *pa + rg + 78, *pc + 35, 5, 5);
					putimage(*pa + rg + 73, *pc + 35, &bullet);
					Sleep(10);
					putimage(*pa + rg + 73, *pc + 35, &background1);
					putimage(*pd, *pe, &img2);
				}
				*pmov += 1;
				if (arr[*pa + rg + 75][*pc + 37] == 99)
				{
					*pHP2 -= 1;
				}
			}
			break;
		}
	}
	if (*pmov % 6 == 3)
	{

		if (*pa == *pd && *pc <= *pe)
		{
			for (check[0] = 0, i = 0; i <= (*pe - *pc) / 75; i += 75)
			{
				if (arr[*pd + 37][*pe + 37 - i] > 100)
				{
					check[0] = 1;
				}
				else
				{
					check[0] = check[0];
				}
			}                             //check whether there is obstacle between two players

			if (arr[*pd + 37 - 75][*pe + 37] < 100 && *pd>2 * 75 + 21)
			{
				check[1] = 1;
			}
			else
			{
				check[1] = 0;
			}
			if (arr[*pd + 37 + 75][*pe + 37] < 100 && *pd < 620 - 2 * 75)
			{
				check[2] = 1;
			}
			else
			{
				check[2] = 0;
			}
			if (arr[*pd + 37][*pe + 37 + 75] < 100 && *pe < 620 - 2 * 75)
			{
				check[3] = 1;
			}
			else
			{
				check[3] = 0;
			}
			if (check[0] == 1)
			{
				for (up = 3; 20 <= *pd + 10 && *pd + 10 <= 590 && arr[*pd + 37][*pe - up] <= 98 && *pe - up <= 590 && *pe - up >= 20 && *pmov % 6 > 2 && *pmov % 6 <= 5; up++)
				{
					getimage(&background1, *pd + 35, *pe - up - 7, 5, 5);
					putimage(*pd + 35, *pe - up - 2, &bullet);
					Sleep(10);
					putimage(*pd + 35, *pe - up - 2, &background1);
					putimage(*pa, *pc, &img1);
				}
				*pmov += 1;
				if (arr[*pd + 37][*pe - up] == 100)
				{
					*pHP1 -= 1;
				}
			}
			else
			{
				if (check[1] == 1)
				{
					arr[*pd + 37][*pe + 37] = 0;
					clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
					putimage(*pd, *pe, &background);
					putimage(*pd - *pb, *pe, &img2);
					*pd = *pd - *pb;
					*pe = *pe;
					arr[*pd + 37][*pe + 37] = 99;
					*pmov += 1;
				}
				else
				{
					if (check[2] == 1)
					{
						arr[*pd + 37][*pe + 37] = 0;
						clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
						putimage(*pd, *pe, &background);
						putimage(*pd + *pb, *pe, &img2);
						*pd = *pd + *pb;
						*pe = *pe;
						arr[*pd + 37][*pe + 37] = 99;
						*pmov += 1;
					}
					else
					{
						if (check[3] == 1)
						{
							arr[*pd + 37][*pe + 37] = 0;
							clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
							putimage(*pd, *pe, &background);
							putimage(*pd, *pe + *pb, &img2);
							*pd = *pd;
							*pe = *pe + *pb;
							arr[*pd + 37][*pe + 37] = 99;
							*pmov += 1;
						}
						else
						{
							if (*pe >= 95)
							{
								arr[*pd + 37][*pe + 37] = 0;
								clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
								putimage(*pd, *pe, &background);
								putimage(*pd, *pe - *pb, &img2);
								*pd = *pd;
								*pe = *pe - *pb;
								arr[*pd + 37][*pe + 37] = 99;
								*pmov += 1;
							}
							else
							{
								arr[*pd + 37][*pe + 37] = 0;
								clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
								putimage(*pd, *pe, &background);
								putimage(*pd, *pe + *pb, &img2);
								*pd = *pd;
								*pe = *pe + *pb;
								arr[*pd + 37][*pe + 37] = 99;
								*pmov += 1;
							}
						}
					}
				}
			}
		}
		if (*pa == *pd && *pc > *pe)
		{
			for (check[0] = 0, i = 0; i <= (*pc - *pe) / 75; i += 75)
			{
				if (arr[*pd + 37][*pe + 37 + i] > 100)
				{
					check[0] = 1;
				}
				else
				{
					check[0] = check[0];
				}
			}

			if (arr[*pd + 37 - 75][*pe + 37] < 100 && *pd>2 * 75 + 21)
			{
				check[1] = 1;
			}
			else
			{
				check[1] = 0;
			}
			if (arr[*pd + 37 + 75][*pe + 37] < 100 && *pd < 620 - 2 * 75)
			{
				check[2] = 1;
			}
			else
			{
				check[2] = 0;
			}
			if (arr[*pd + 37][*p + 37 + 75] < 100 && *pe < 620 - 2 * 75)
			{
				check[3] = 1;
			}
			else
			{
				check[3] = 0;
			}
			if (check[0] == 1)
			{
				for (dw = 3; 20 <= *pd + 10 && *pd + 10 <= 590 && arr[*pd + 37][*pe + dw + 75] <= 98 && *pe + dw <= 590 && *pe + dw >= 20 && *pmov % 6 > 2 && *pmov % 6 <= 5; dw++)
				{
					getimage(&background1, *pd + 35, *pe + dw + 78, 5, 5);
					putimage(*pd + 35, *pe + dw + 73, &bullet);
					Sleep(10);
					putimage(*pd + 35, *pe + dw + 73, &background1);
					putimage(*pa, *pc, &img1);
				}
				*pmov += 1;
				if (arr[*pd + 37][*pe + dw + 75] == 100)
				{
					*pHP1 -= 1;
				}
			}
			else
			{
				if (check[1] == 1)
				{
					arr[*pd + 37][*pe + 37] = 0;
					clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
					putimage(*pd, *pe, &background);
					putimage(*pd - *pb, *pe, &img2);
					*pd = *pd - *pb;
					*pe = *pe;
					arr[*pd + 37][*pe + 37] = 99;
					*pmov += 1;
				}
				else
				{
					if (check[2] == 1)
					{
						arr[*pd + 37][*pe + 37] = 0;
						clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
						putimage(*pd, *pe, &background);
						putimage(*pd + *pb, *pe, &img2);
						*pd = *pd + *pb;
						*pe = *pe;
						arr[*pd + 37][*pe + 37] = 99;
						*pmov += 1;
					}
					else
					{
						if (check[3] == 1)
						{
							arr[*pd + 37][*pe + 37] = 0;
							clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
							putimage(*pd, *pe, &background);
							putimage(*pd, *pe + *pb, &img2);
							*pd = *pd;
							*pe = *pe + *pb;
							arr[*pd + 37][*pe + 37] = 99;
							*pmov += 1;
						}
						else
						{
							if (*pe >= 95)
							{
								arr[*pd + 37][*pe + 37] = 0;
								clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
								putimage(*pd, *pe, &background);
								putimage(*pd, *pe - *pb, &img2);
								*pd = *pd;
								*pe = *pe - *pb;
								arr[*pd + 37][*pe + 37] = 99;
								*pmov += 1;
							}
							else
							{
								arr[*pd + 37][*pe + 37] = 0;
								clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
								putimage(*pd, *pe, &background);
								putimage(*pd, *pe + *pb, &img2);
								*pd = *pd;
								*pe = *pe + *pb;
								arr[*pd + 37][*pe + 37] = 99;
								*pmov += 1;
							}
						}
					}
				}
			}
		}
		if (*pc == *pe && *pa >= *pd)
		{
			for (check[0] = 0, i = 0; i <= (*pa - *pd) / 75; i += 75)
			{
				if (arr[*pd + 37 + i][*pe + 37] > 100)
				{
					check[0] = 1;
				}
				else
				{
					check[0] = check[0];
				}
			}

			if (arr[*pd + 37 - 75][*pe + 37] < 100 && *pd>2 * 75 + 21)
			{
				check[1] = 1;
			}
			else
			{
				check[1] = 0;
			}
			if (arr[*pd + 37 + 75][*pe + 37] < 100 && *pd < 620 - 2 * 75)
			{
				check[2] = 1;
			}
			else
			{
				check[2] = 0;
			}
			if (arr[*pd + 37][*pe + 37 + 75] < 100 && *pe < 620 - 2 * 75)
			{
				check[3] = 1;
			}
			else
			{
				check[3] = 0;
			}
			if (check[0] == 1)
			{
				for (rg = 3; 20 <= *pd + rg && *pd + rg <= 590 && arr[*pd + 75 + rg][*pe + 37] <= 98 && *pe + 10 <= 590 && *pe + 10 >= 20 && *pmov % 6 > 2 && *pmov % 6 <= 5; rg++)
				{
					getimage(&background1, *pd + rg + 78, *pe + 35, 5, 5);
					putimage(*pd + rg + 73, *pe + 35, &bullet);
					Sleep(10);
					putimage(*pd + rg + 73, *pe + 35, &background1);
					putimage(*pa, *pc, &img1);
				}
				*pmov += 1;
				if (arr[*pd + 75 + rg][*pe + 37] == 100)
				{
					*pHP1 -= 1;
				}
			}
			else
			{
				if (check[1] == 1)
				{
					arr[*pd + 37][*pe + 37] = 0;
					clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
					putimage(*pd, *pe, &background);
					putimage(*pd - *pb, *pe, &img2);
					*pd = *pd - *pb;
					*pe = *pe;
					arr[*pd + 37][*pe + 37] = 99;
					*pmov += 1;
				}
				else
				{
					if (check[2] == 1)
					{
						arr[*pd + 37][*pe + 37] = 0;
						clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
						putimage(*pd, *pe, &background);
						putimage(*pd + *pb, *pe, &img2);
						*pd = *pd + *pb;
						*pe = *pe;
						arr[*pd + 37][*pe + 37] = 99;
						*pmov += 1;
					}
					else
					{
						if (check[3] == 1)
						{
							arr[*pd + 37][*pe + 37] = 0;
							clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
							putimage(*pd, *pe, &background);
							putimage(*pd, *pe + *pb, &img2);
							*pd = *pd;
							*pe = *pe + *pb;
							arr[*pd + 37][*pe + 37] = 99;
							*pmov += 1;
						}
						else
						{
							if (*pe >= 95)
							{
								arr[*pd + 37][*pe + 37] = 0;
								clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
								putimage(*pd, *pe, &background);
								putimage(*pd, *pe - *pb, &img2);
								*pd = *pd;
								*pe = *pe - *pb;
								arr[*pd + 37][*pe + 37] = 99;
								*pmov += 1;
							}
							else
							{
								arr[*pd + 37][*pe + 37] = 0;
								clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
								putimage(*pd, *pe, &background);
								putimage(*pd, *pe + *pb, &img2);
								*pd = *pd;
								*pe = *pe + *pb;
								arr[*pd + 37][*pe + 37] = 99;
								*pmov += 1;
							}
						}
					}
				}
			}
		}
		if (*pc == *pe && *pa < *pd)
		{
			for (check[0] = 0, i = 0; i <= (*pd - *pa) / 75; i += 75)
			{
				if (arr[*pd + 37 - i][*pe + 37] > 100)
				{
					check[0] = 1;
				}
				else
				{
					check[0] = check[0];
				}
			}

			if (arr[*pd + 37 - 75][*pe + 37] < 100 && *pd>2 * 75 + 21)
			{
				check[1] = 1;
			}
			else
			{
				check[1] = 0;
			}
			if (arr[*pd + 37 + 75][*pe + 37] < 100 && *pd < 620 - 2 * 75)
			{
				check[2] = 1;
			}
			else
			{
				check[2] = 0;
			}
			if (arr[*pd + 37][*pe + 37 + 75] < 100 && *pe < 620 - 2 * 75)
			{
				check[3] = 1;
			}
			else
			{
				check[3] = 0;
			}
			if (check[0] == 1)
			{
				for (lf = 3; 20 <= *pd - lf && *pd - lf <= 590 && arr[*pd - lf][*pe + 37] <= 98 && *pe + 10 <= 590 && *pe + 10 >= 20 && *pmov % 6 > 2 && *pmov % 6 <= 5; lf++)
				{
					getimage(&background1, *pd - lf - 7, *pe + 35, 5, 5);
					putimage(*pd - lf - 2, *pe + 35, &bullet);
					Sleep(10);
					putimage(*pd - lf - 2, *pe + 35, &background1);
					putimage(*pa, *pc, &img1);
				}
				*pmov += 1;
				if (arr[*pd - lf][*pe + 37] == 100)
				{
					*pHP1 -= 1;
				}
			}
			else
			{
				if (check[1] == 1)
				{
					arr[*pd + 37][*pe + 37] = 0;
					clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
					putimage(*pd, *pe, &background);
					putimage(*pd - *pb, *pe, &img2);
					*pd = *pd - *pb;
					*pe = *pe;
					arr[*pd + 37][*pe + 37] = 99;
					*pmov += 1;
				}
				else
				{
					if (check[2] == 1)
					{
						arr[*pd + 37][*pe + 37] = 0;
						clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
						putimage(*pd, *pe, &background);
						putimage(*pd + *pb, *pe, &img2);
						*pd = *pd + *pb;
						*pe = *pe;
						arr[*pd + 37][*pe + 37] = 99;
						*pmov += 1;
					}
					else
					{
						if (check[3] == 1)
						{
							arr[*pd + 37][*pe + 37] = 0;
							clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
							putimage(*pd, *pe, &background);
							putimage(*pd, *pe + *pb, &img2);
							*pd = *pd;
							*pe = *pe + *pb;
							arr[*pd + 37][*pe + 37] = 99;
							*pmov += 1;
						}
						else
						{
							if (*pe >= 95)
							{
								arr[*pd + 37][*pe + 37] = 0;
								clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
								putimage(*pd, *pe, &background);
								putimage(*pd, *pe - *pb, &img2);
								*pd = *pd;
								*pe = *pe - *pb;
								arr[*pd + 37][*pe + 37] = 99;
								*pmov += 1;
							}
							else
							{
								arr[*pd + 37][*pe + 37] = 0;
								clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
								putimage(*pd, *pe, &background);
								putimage(*pd, *pe + *pb, &img2);
								*pd = *pd;
								*pe = *pe + *pb;
								arr[*pd + 37][*pe + 37] = 99;
								*pmov += 1;
							}
						}
					}
				}
			}
		}
		else
		{
			if (arr[*pd + 37][*pe + 37 - 75] < 100 && *pe < 620 - 2 * 75)
			{
				check[0] = 1;
			}
			else
			{
				check[0] = 0;
			}
			if (arr[*pd + 37 - 75][*pe + 37] < 100 && *pd>2 * 75 + 21)
			{
				check[1] = 1;
			}
			else
			{
				check[1] = 0;
			}
			if (arr[*pd + 37 + 75][*pe + 37] < 100 && *pd < 620 - 2 * 75)
			{
				check[2] = 1;
			}
			else
			{
				check[2] = 0;
			}
			if (arr[*pd + 37][*pe + 37 + 75] < 100 && *pe < 620 - 2 * 75)
			{
				check[3] = 1;
			}
			else
			{
				check[3] = 0;
			}
			if (check[0] == 1)
			{
				arr[*pd + 37][*pe + 37] = 0;
				clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
				putimage(*pd, *pe, &background);
				putimage(*pd, *pe - *pb, &img2);
				*pd = *pd;
				*pe = *pe - *pb;
				arr[*pd + 37][*pe + 37] = 99;
				*pmov += 1;
			}
			else
			{
				if (check[1] == 1)
				{
					arr[*pd + 37][*pe + 37] = 0;
					clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
					putimage(*pd, *pe, &background);
					putimage(*pd - *pb, *pe, &img2);
					*pd = *pd - *pb;
					*pe = *pe;
					arr[*pd + 37][*pe + 37] = 99;
					*pmov += 1;
				}
				else
				{
					if (check[2] == 1)
					{
						arr[*pd + 37][*pe + 37] = 0;
						clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
						putimage(*pd, *pe, &background);
						putimage(*pd + *pb, *pe, &img2);
						*pd = *pd + *pb;
						*pe = *pe;
						arr[*pd + 37][*pe + 37] = 99;
						*pmov += 1;
					}
					else
					{
						if (check[3] == 1)
						{
							arr[*pd + 37][*pe + 37] = 0;
							clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
							putimage(*pd, *pe, &background);
							putimage(*pd, *pe + *pb, &img2);
							*pd = *pd;
							*pe = *pe + *pb;
							arr[*pd + 37][*pe + 37] = 99;
							*pmov += 1;
						}
						else
						{
							if (95 <= *pe && arr[*pd + 37][*pe - 38] <= 98 && *pmov % 6 > 2 && *pmov % 6 <= 5)
							{
								arr[*pd + 37][*pe + 37] = 0;
								clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
								putimage(*pd, *pe, &background);
								putimage(*pd, *pe - *pb, &img2);
								*pd = *pd;
								*pe = *pe - *pb;
								arr[*pd + 37][*pe + 37] = 99;
								*pmov += 1;
							}
							else
							{
								if (*pe <= 545 && arr[*pd + 37][*pe + 37 + 75] <= 98 && *pmov % 6 > 2 && *pmov % 6 <= 5)
								{
									arr[*pd + 37][*pe + 37] = 0;
									clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
									putimage(*pd, *pe, &background);
									putimage(*pd, *pe + *pb, &img2);
									*pd = *pd;
									*pe = *pe + *pb;
									arr[*pd + 37][*pe + 37] = 99;
									*pmov += 1;
								}
								else
								{
									if (95 <= *pd && arr[*pd - 38][*pe + 37] <= 98 && *pmov % 6 > 2 && *pmov % 6 <= 5)
									{
										arr[*pd + 37][*pe + 37] = 0;
										clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
										putimage(*pd, *pe, &background);
										putimage(*pd - *pb, *pe, &img2);
										*pd = *pd - *pb;
										*pe = *pe;
										arr[*pd + 37][*pe + 37] = 99;
										*pmov += 1;
									}
									else
									{
										if (*pd <= 545 && arr[*pd + 37 + 75][*pe + 37] <= 98 && *pmov % 6 > 2 && *pmov % 6 <= 5)
										{
											arr[*pd + 37][*pe + 37] = 0;
											clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
											putimage(*pd, *pe, &background);
											putimage(*pd + *pb, *pe, &img2);
											*pd = *pd + *pb;
											*pe = *pe;
											arr[*pd + 37][*pe + 37] = 99;
											*pmov += 1;
										}
									}
								}
							}
						}
					}
				}
			}



		}
		Sleep(1000);

	}
	if (*pmov % 6 == 4)
	{

		if (*pa == *pd && *pc <= *pe)
		{
			for (check[0] = 0, i = 0; i <= (*pe - *pc) / 75; i += 75)
			{
				if (arr[*pd + 37][*pe + 37 - i] > 100)
				{
					check[0] = 1;
				}
				else
				{
					check[0] = check[0];
				}
			}                             //check whether there is obstacle between two players

			if (arr[*pd + 37 - 75][*pe + 37] < 100 && *pd>2 * 75 + 21)
			{
				check[1] = 1;
			}
			else
			{
				check[1] = 0;
			}
			if (arr[*pd + 37 + 75][*pe + 37] < 100 && *pd < 620 - 2 * 75)
			{
				check[2] = 1;
			}
			else
			{
				check[2] = 0;
			}
			if (arr[*pd + 37][*pe + 37 + 75] < 100 && *pe < 620 - 2 * 75)
			{
				check[3] = 1;
			}
			else
			{
				check[3] = 0;
			}
			if (check[0] == 1)
			{
				for (up = 3; 20 <= *pd + 10 && *pd + 10 <= 590 && arr[*pd + 37][*pe - up] <= 98 && *pe - up <= 590 && *pe - up >= 20 && *pmov % 6 > 2 && *pmov % 6 <= 5; up++)
				{
					getimage(&background1, *pd + 35, *pe - up - 7, 5, 5);
					putimage(*pd + 35, *pe - up - 2, &bullet);
					Sleep(10);
					putimage(*pd + 35, *pe - up - 2, &background1);
					putimage(*pa, *pc, &img1);
				}
				*pmov += 1;
				if (arr[*pd + 37][*pe - up] == 100)
				{
					*pHP1 -= 1;
				}
			}
			else
			{
				if (check[1] == 1)
				{
					arr[*pd + 37][*pe + 37] = 0;
					clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
					putimage(*pd, *pe, &background);
					putimage(*pd - *pb, *pe, &img2);
					*pd = *pd - *pb;
					*pe = *pe;
					arr[*pd + 37][*pe + 37] = 99;
					*pmov += 1;
				}
				else
				{
					if (check[2] == 1)
					{
						arr[*pd + 37][*pe + 37] = 0;
						clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
						putimage(*pd, *pe, &background);
						putimage(*pd + *pb, *pe, &img2);
						*pd = *pd + *pb;
						*pe = *pe;
						arr[*pd + 37][*pe + 37] = 99;
						*pmov += 1;
					}
					else
					{
						if (check[3] == 1)
						{
							arr[*pd + 37][*pe + 37] = 0;
							clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
							putimage(*pd, *pe, &background);
							putimage(*pd, *pe + *pb, &img2);
							*pd = *pd;
							*pe = *pe + *pb;
							arr[*pd + 37][*pe + 37] = 99;
							*pmov += 1;
						}
						else
						{
							if (*pe >= 95)
							{
								arr[*pd + 37][*pe + 37] = 0;
								clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
								putimage(*pd, *pe, &background);
								putimage(*pd, *pe - *pb, &img2);
								*pd = *pd;
								*pe = *pe - *pb;
								arr[*pd + 37][*pe + 37] = 99;
								*pmov += 1;
							}
							else
							{
								arr[*pd + 37][*pe + 37] = 0;
								clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
								putimage(*pd, *pe, &background);
								putimage(*pd, *pe + *pb, &img2);
								*pd = *pd;
								*pe = *pe + *pb;
								arr[*pd + 37][*pe + 37] = 99;
								*pmov += 1;
							}
						}
					}
				}
			}
		}
		if (*pa == *pd && *pc > *pe)
		{
			for (check[0] = 0, i = 0; i <= (*pc - *pe) / 75; i += 75)
			{
				if (arr[*pd + 37][*pe + 37 + i] > 100)
				{
					check[0] = 1;
				}
				else
				{
					check[0] = check[0];
				}
			}

			if (arr[*pd + 37 - 75][*pe + 37] < 100 && *pd>2 * 75 + 21)
			{
				check[1] = 1;
			}
			else
			{
				check[1] = 0;
			}
			if (arr[*pd + 37 + 75][*pe + 37] < 100 && *pd < 620 - 2 * 75)
			{
				check[2] = 1;
			}
			else
			{
				check[2] = 0;
			}
			if (arr[*pd + 37][*p + 37 + 75] < 100 && *pe < 620 - 2 * 75)
			{
				check[3] = 1;
			}
			else
			{
				check[3] = 0;
			}
			if (check[0] == 1)
			{
				for (dw = 3; 20 <= *pd + 10 && *pd + 10 <= 590 && arr[*pd + 37][*pe + dw + 75] <= 98 && *pe + dw <= 590 && *pe + dw >= 20 && *pmov % 6 > 2 && *pmov % 6 <= 5; dw++)
				{
					getimage(&background1, *pd + 35, *pe + dw + 78, 5, 5);
					putimage(*pd + 35, *pe + dw + 73, &bullet);
					Sleep(10);
					putimage(*pd + 35, *pe + dw + 73, &background1);
					putimage(*pa, *pc, &img1);
				}
				*pmov += 1;
				if (arr[*pd + 37][*pe + dw + 75] == 100)
				{
					*pHP1 -= 1;
				}
			}
			else
			{
				if (check[1] == 1)
				{
					arr[*pd + 37][*pe + 37] = 0;
					clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
					putimage(*pd, *pe, &background);
					putimage(*pd - *pb, *pe, &img2);
					*pd = *pd - *pb;
					*pe = *pe;
					arr[*pd + 37][*pe + 37] = 99;
					*pmov += 1;
				}
				else
				{
					if (check[2] == 1)
					{
						arr[*pd + 37][*pe + 37] = 0;
						clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
						putimage(*pd, *pe, &background);
						putimage(*pd + *pb, *pe, &img2);
						*pd = *pd + *pb;
						*pe = *pe;
						arr[*pd + 37][*pe + 37] = 99;
						*pmov += 1;
					}
					else
					{
						if (check[3] == 1)
						{
							arr[*pd + 37][*pe + 37] = 0;
							clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
							putimage(*pd, *pe, &background);
							putimage(*pd, *pe + *pb, &img2);
							*pd = *pd;
							*pe = *pe + *pb;
							arr[*pd + 37][*pe + 37] = 99;
							*pmov += 1;
						}
						else
						{
							if (*pe >= 95)
							{
								arr[*pd + 37][*pe + 37] = 0;
								clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
								putimage(*pd, *pe, &background);
								putimage(*pd, *pe - *pb, &img2);
								*pd = *pd;
								*pe = *pe - *pb;
								arr[*pd + 37][*pe + 37] = 99;
								*pmov += 1;
							}
							else
							{
								arr[*pd + 37][*pe + 37] = 0;
								clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
								putimage(*pd, *pe, &background);
								putimage(*pd, *pe + *pb, &img2);
								*pd = *pd;
								*pe = *pe + *pb;
								arr[*pd + 37][*pe + 37] = 99;
								*pmov += 1;
							}
						}
					}
				}
			}
		}
		if (*pc == *pe && *pa >= *pd)
		{
			for (check[0] = 0, i = 0; i <= (*pa - *pd) / 75; i += 75)
			{
				if (arr[*pd + 37 + i][*pe + 37] > 100)
				{
					check[0] = 1;
				}
				else
				{
					check[0] = check[0];
				}
			}

			if (arr[*pd + 37 - 75][*pe + 37] < 100 && *pd>2 * 75 + 21)
			{
				check[1] = 1;
			}
			else
			{
				check[1] = 0;
			}
			if (arr[*pd + 37 + 75][*pe + 37] < 100 && *pd < 620 - 2 * 75)
			{
				check[2] = 1;
			}
			else
			{
				check[2] = 0;
			}
			if (arr[*pd + 37][*pe + 37 + 75] < 100 && *pe < 620 - 2 * 75)
			{
				check[3] = 1;
			}
			else
			{
				check[3] = 0;
			}
			if (check[0] == 1)
			{
				for (rg = 3; 20 <= *pd + rg && *pd + rg <= 590 && arr[*pd + 75 + rg][*pe + 37] <= 98 && *pe + 10 <= 590 && *pe + 10 >= 20 && *pmov % 6 > 2 && *pmov % 6 <= 5; rg++)
				{
					getimage(&background1, *pd + rg + 78, *pe + 35, 5, 5);
					putimage(*pd + rg + 73, *pe + 35, &bullet);
					Sleep(10);
					putimage(*pd + rg + 73, *pe + 35, &background1);
					putimage(*pa, *pc, &img1);
				}
				*pmov += 1;
				if (arr[*pd + 75 + rg][*pe + 37] == 100)
				{
					*pHP1 -= 1;
				}
			}
			else
			{
				if (check[1] == 1)
				{
					arr[*pd + 37][*pe + 37] = 0;
					clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
					putimage(*pd, *pe, &background);
					putimage(*pd - *pb, *pe, &img2);
					*pd = *pd - *pb;
					*pe = *pe;
					arr[*pd + 37][*pe + 37] = 99;
					*pmov += 1;
				}
				else
				{
					if (check[2] == 1)
					{
						arr[*pd + 37][*pe + 37] = 0;
						clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
						putimage(*pd, *pe, &background);
						putimage(*pd + *pb, *pe, &img2);
						*pd = *pd + *pb;
						*pe = *pe;
						arr[*pd + 37][*pe + 37] = 99;
						*pmov += 1;
					}
					else
					{
						if (check[3] == 1)
						{
							arr[*pd + 37][*pe + 37] = 0;
							clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
							putimage(*pd, *pe, &background);
							putimage(*pd, *pe + *pb, &img2);
							*pd = *pd;
							*pe = *pe + *pb;
							arr[*pd + 37][*pe + 37] = 99;
							*pmov += 1;
						}
						else
						{
							if (*pe >= 95)
							{
								arr[*pd + 37][*pe + 37] = 0;
								clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
								putimage(*pd, *pe, &background);
								putimage(*pd, *pe - *pb, &img2);
								*pd = *pd;
								*pe = *pe - *pb;
								arr[*pd + 37][*pe + 37] = 99;
								*pmov += 1;
							}
							else
							{
								arr[*pd + 37][*pe + 37] = 0;
								clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
								putimage(*pd, *pe, &background);
								putimage(*pd, *pe + *pb, &img2);
								*pd = *pd;
								*pe = *pe + *pb;
								arr[*pd + 37][*pe + 37] = 99;
								*pmov += 1;
							}
						}
					}
				}
			}
		}
		if (*pc == *pe && *pa < *pd)
		{
			for (check[0] = 0, i = 0; i <= (*pd - *pa) / 75; i += 75)
			{
				if (arr[*pd + 37 - i][*pe + 37] > 100)
				{
					check[0] = 1;
				}
				else
				{
					check[0] = check[0];
				}
			}

			if (arr[*pd + 37 - 75][*pe + 37] < 100 && *pd>2 * 75 + 21)
			{
				check[1] = 1;
			}
			else
			{
				check[1] = 0;
			}
			if (arr[*pd + 37 + 75][*pe + 37] < 100 && *pd < 620 - 2 * 75)
			{
				check[2] = 1;
			}
			else
			{
				check[2] = 0;
			}
			if (arr[*pd + 37][*pe + 37 + 75] < 100 && *pe < 620 - 2 * 75)
			{
				check[3] = 1;
			}
			else
			{
				check[3] = 0;
			}
			if (check[0] == 1)
			{
				for (lf = 3; 20 <= *pd - lf && *pd - lf <= 590 && arr[*pd - lf][*pe + 37] <= 98 && *pe + 10 <= 590 && *pe + 10 >= 20 && *pmov % 6 > 2 && *pmov % 6 <= 5; lf++)
				{
					getimage(&background1, *pd - lf - 7, *pe + 35, 5, 5);
					putimage(*pd - lf - 2, *pe + 35, &bullet);
					Sleep(10);
					putimage(*pd - lf - 2, *pe + 35, &background1);
					putimage(*pa, *pc, &img1);
				}
				*pmov += 1;
				if (arr[*pd - lf][*pe + 37] == 100)
				{
					*pHP1 -= 1;
				}
			}
			else
			{
				if (check[1] == 1)
				{
					arr[*pd + 37][*pe + 37] = 0;
					clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
					putimage(*pd, *pe, &background);
					putimage(*pd - *pb, *pe, &img2);
					*pd = *pd - *pb;
					*pe = *pe;
					arr[*pd + 37][*pe + 37] = 99;
					*pmov += 1;
				}
				else
				{
					if (check[2] == 1)
					{
						arr[*pd + 37][*pe + 37] = 0;
						clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
						putimage(*pd, *pe, &background);
						putimage(*pd + *pb, *pe, &img2);
						*pd = *pd + *pb;
						*pe = *pe;
						arr[*pd + 37][*pe + 37] = 99;
						*pmov += 1;
					}
					else
					{
						if (check[3] == 1)
						{
							arr[*pd + 37][*pe + 37] = 0;
							clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
							putimage(*pd, *pe, &background);
							putimage(*pd, *pe + *pb, &img2);
							*pd = *pd;
							*pe = *pe + *pb;
							arr[*pd + 37][*pe + 37] = 99;
							*pmov += 1;
						}
						else
						{
							if (*pe >= 95)
							{
								arr[*pd + 37][*pe + 37] = 0;
								clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
								putimage(*pd, *pe, &background);
								putimage(*pd, *pe - *pb, &img2);
								*pd = *pd;
								*pe = *pe - *pb;
								arr[*pd + 37][*pe + 37] = 99;
								*pmov += 1;
							}
							else
							{
								arr[*pd + 37][*pe + 37] = 0;
								clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
								putimage(*pd, *pe, &background);
								putimage(*pd, *pe + *pb, &img2);
								*pd = *pd;
								*pe = *pe + *pb;
								arr[*pd + 37][*pe + 37] = 99;
								*pmov += 1;
							}
						}
					}
				}
			}
		}
		else
		{
			if (arr[*pd + 37][*pe + 37 - 75] < 100 && *pe < 620 - 2 * 75)
			{
				check[0] = 1;
			}
			else
			{
				check[0] = 0;
			}
			if (arr[*pd + 37 - 75][*pe + 37] < 100 && *pd>2 * 75 + 21)
			{
				check[1] = 1;
			}
			else
			{
				check[1] = 0;
			}
			if (arr[*pd + 37 + 75][*pe + 37] < 100 && *pd < 620 - 2 * 75)
			{
				check[2] = 1;
			}
			else
			{
				check[2] = 0;
			}
			if (arr[*pd + 37][*pe + 37 + 75] < 100 && *pe < 620 - 2 * 75)
			{
				check[3] = 1;
			}
			else
			{
				check[3] = 0;
			}
			if (check[0] == 1)
			{
				arr[*pd + 37][*pe + 37] = 0;
				clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
				putimage(*pd, *pe, &background);
				putimage(*pd, *pe - *pb, &img2);
				*pd = *pd;
				*pe = *pe - *pb;
				arr[*pd + 37][*pe + 37] = 99;
				*pmov += 1;
			}
			else
			{
				if (check[1] == 1)
				{
					arr[*pd + 37][*pe + 37] = 0;
					clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
					putimage(*pd, *pe, &background);
					putimage(*pd - *pb, *pe, &img2);
					*pd = *pd - *pb;
					*pe = *pe;
					arr[*pd + 37][*pe + 37] = 99;
					*pmov += 1;
				}
				else
				{
					if (check[2] == 1)
					{
						arr[*pd + 37][*pe + 37] = 0;
						clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
						putimage(*pd, *pe, &background);
						putimage(*pd + *pb, *pe, &img2);
						*pd = *pd + *pb;
						*pe = *pe;
						arr[*pd + 37][*pe + 37] = 99;
						*pmov += 1;
					}
					else
					{
						if (check[3] == 1)
						{
							arr[*pd + 37][*pe + 37] = 0;
							clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
							putimage(*pd, *pe, &background);
							putimage(*pd, *pe + *pb, &img2);
							*pd = *pd;
							*pe = *pe + *pb;
							arr[*pd + 37][*pe + 37] = 99;
							*pmov += 1;
						}
						else
						{
							if (95 <= *pe && arr[*pd + 37][*pe - 38] <= 98 && *pmov % 6 > 2 && *pmov % 6 <= 5)
							{
								arr[*pd + 37][*pe + 37] = 0;
								clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
								putimage(*pd, *pe, &background);
								putimage(*pd, *pe - *pb, &img2);
								*pd = *pd;
								*pe = *pe - *pb;
								arr[*pd + 37][*pe + 37] = 99;
								*pmov += 1;
							}
							else
							{
								if (*pe <= 545 && arr[*pd + 37][*pe + 37 + 75] <= 98 && *pmov % 6 > 2 && *pmov % 6 <= 5)
								{
									arr[*pd + 37][*pe + 37] = 0;
									clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
									putimage(*pd, *pe, &background);
									putimage(*pd, *pe + *pb, &img2);
									*pd = *pd;
									*pe = *pe + *pb;
									arr[*pd + 37][*pe + 37] = 99;
									*pmov += 1;
								}
								else
								{
									if (95 <= *pd && arr[*pd - 38][*pe + 37] <= 98 && *pmov % 6 > 2 && *pmov % 6 <= 5)
									{
										arr[*pd + 37][*pe + 37] = 0;
										clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
										putimage(*pd, *pe, &background);
										putimage(*pd - *pb, *pe, &img2);
										*pd = *pd - *pb;
										*pe = *pe;
										arr[*pd + 37][*pe + 37] = 99;
										*pmov += 1;
									}
									else
									{
										if (*pd <= 545 && arr[*pd + 37 + 75][*pe + 37] <= 98 && *pmov % 6 > 2 && *pmov % 6 <= 5)
										{
											arr[*pd + 37][*pe + 37] = 0;
											clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
											putimage(*pd, *pe, &background);
											putimage(*pd + *pb, *pe, &img2);
											*pd = *pd + *pb;
											*pe = *pe;
											arr[*pd + 37][*pe + 37] = 99;
											*pmov += 1;
										}
									}
								}
							}
						}
					}
				}
			}



		}
		Sleep(1000);

	}
	if (*pmov % 6 == 5)
	{

		if (*pa == *pd && *pc <= *pe)
		{
			for (check[0] = 0, i = 0; i <= (*pe - *pc) / 75; i += 75)
			{
				if (arr[*pd + 37][*pe + 37 - i] > 100)
				{
					check[0] = 1;
				}
				else
				{
					check[0] = check[0];
				}
			}                             //check whether there is obstacle between two players

			if (arr[*pd + 37 - 75][*pe + 37] < 100 && *pd>2 * 75 + 21)
			{
				check[1] = 1;
			}
			else
			{
				check[1] = 0;
			}
			if (arr[*pd + 37 + 75][*pe + 37] < 100 && *pd < 620 - 2 * 75)
			{
				check[2] = 1;
			}
			else
			{
				check[2] = 0;
			}
			if (arr[*pd + 37][*pe + 37 + 75] < 100 && *pe < 620 - 2 * 75)
			{
				check[3] = 1;
			}
			else
			{
				check[3] = 0;
			}
			if (check[0] == 1)
			{
				for (up = 3; 20 <= *pd + 10 && *pd + 10 <= 590 && arr[*pd + 37][*pe - up] <= 98 && *pe - up <= 590 && *pe - up >= 20 && *pmov % 6 > 2 && *pmov % 6 <= 5; up++)
				{
					getimage(&background1, *pd + 35, *pe - up - 7, 5, 5);
					putimage(*pd + 35, *pe - up - 2, &bullet);
					Sleep(10);
					putimage(*pd + 35, *pe - up - 2, &background1);
					putimage(*pa, *pc, &img1);
				}
				*pmov += 1;
				if (arr[*pd + 37][*pe - up] == 100)
				{
					*pHP1 -= 1;
				}
			}
			else
			{
				if (check[1] == 1)
				{
					arr[*pd + 37][*pe + 37] = 0;
					clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
					putimage(*pd, *pe, &background);
					putimage(*pd - *pb, *pe, &img2);
					*pd = *pd - *pb;
					*pe = *pe;
					arr[*pd + 37][*pe + 37] = 99;
					*pmov += 1;
				}
				else
				{
					if (check[2] == 1)
					{
						arr[*pd + 37][*pe + 37] = 0;
						clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
						putimage(*pd, *pe, &background);
						putimage(*pd + *pb, *pe, &img2);
						*pd = *pd + *pb;
						*pe = *pe;
						arr[*pd + 37][*pe + 37] = 99;
						*pmov += 1;
					}
					else
					{
						if (check[3] == 1)
						{
							arr[*pd + 37][*pe + 37] = 0;
							clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
							putimage(*pd, *pe, &background);
							putimage(*pd, *pe + *pb, &img2);
							*pd = *pd;
							*pe = *pe + *pb;
							arr[*pd + 37][*pe + 37] = 99;
							*pmov += 1;
						}
						else
						{
							if (*pe >= 95)
							{
								arr[*pd + 37][*pe + 37] = 0;
								clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
								putimage(*pd, *pe, &background);
								putimage(*pd, *pe - *pb, &img2);
								*pd = *pd;
								*pe = *pe - *pb;
								arr[*pd + 37][*pe + 37] = 99;
								*pmov += 1;
							}
							else
							{
								arr[*pd + 37][*pe + 37] = 0;
								clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
								putimage(*pd, *pe, &background);
								putimage(*pd, *pe + *pb, &img2);
								*pd = *pd;
								*pe = *pe + *pb;
								arr[*pd + 37][*pe + 37] = 99;
								*pmov += 1;
							}
						}
					}
				}
			}
		}
		if (*pa == *pd && *pc > *pe)
		{
			for (check[0] = 0, i = 0; i <= (*pc - *pe) / 75; i += 75)
			{
				if (arr[*pd + 37][*pe + 37 + i] > 100)
				{
					check[0] = 1;
				}
				else
				{
					check[0] = check[0];
				}
			}

			if (arr[*pd + 37 - 75][*pe + 37] < 100 && *pd>2 * 75 + 21)
			{
				check[1] = 1;
			}
			else
			{
				check[1] = 0;
			}
			if (arr[*pd + 37 + 75][*pe + 37] < 100 && *pd < 620 - 2 * 75)
			{
				check[2] = 1;
			}
			else
			{
				check[2] = 0;
			}
			if (arr[*pd + 37][*p + 37 + 75] < 100 && *pe < 620 - 2 * 75)
			{
				check[3] = 1;
			}
			else
			{
				check[3] = 0;
			}
			if (check[0] == 1)
			{
				for (dw = 3; 20 <= *pd + 10 && *pd + 10 <= 590 && arr[*pd + 37][*pe + dw + 75] <= 98 && *pe + dw <= 590 && *pe + dw >= 20 && *pmov % 6 > 2 && *pmov % 6 <= 5; dw++)
				{
					getimage(&background1, *pd + 35, *pe + dw + 78, 5, 5);
					putimage(*pd + 35, *pe + dw + 73, &bullet);
					Sleep(10);
					putimage(*pd + 35, *pe + dw + 73, &background1);
					putimage(*pa, *pc, &img1);
				}
				*pmov += 1;
				if (arr[*pd + 37][*pe + dw + 75] == 100)
				{
					*pHP1 -= 1;
				}
			}
			else
			{
				if (check[1] == 1)
				{
					arr[*pd + 37][*pe + 37] = 0;
					clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
					putimage(*pd, *pe, &background);
					putimage(*pd - *pb, *pe, &img2);
					*pd = *pd - *pb;
					*pe = *pe;
					arr[*pd + 37][*pe + 37] = 99;
					*pmov += 1;
				}
				else
				{
					if (check[2] == 1)
					{
						arr[*pd + 37][*pe + 37] = 0;
						clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
						putimage(*pd, *pe, &background);
						putimage(*pd + *pb, *pe, &img2);
						*pd = *pd + *pb;
						*pe = *pe;
						arr[*pd + 37][*pe + 37] = 99;
						*pmov += 1;
					}
					else
					{
						if (check[3] == 1)
						{
							arr[*pd + 37][*pe + 37] = 0;
							clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
							putimage(*pd, *pe, &background);
							putimage(*pd, *pe + *pb, &img2);
							*pd = *pd;
							*pe = *pe + *pb;
							arr[*pd + 37][*pe + 37] = 99;
							*pmov += 1;
						}
						else
						{
							if (*pe >= 95)
							{
								arr[*pd + 37][*pe + 37] = 0;
								clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
								putimage(*pd, *pe, &background);
								putimage(*pd, *pe - *pb, &img2);
								*pd = *pd;
								*pe = *pe - *pb;
								arr[*pd + 37][*pe + 37] = 99;
								*pmov += 1;
							}
							else
							{
								arr[*pd + 37][*pe + 37] = 0;
								clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
								putimage(*pd, *pe, &background);
								putimage(*pd, *pe + *pb, &img2);
								*pd = *pd;
								*pe = *pe + *pb;
								arr[*pd + 37][*pe + 37] = 99;
								*pmov += 1;
							}
						}
					}
				}
			}
		}
		if (*pc == *pe && *pa >= *pd)
		{
			for (check[0] = 0, i = 0; i <= (*pa - *pd) / 75; i += 75)
			{
				if (arr[*pd + 37 + i][*pe + 37] > 100)
				{
					check[0] = 1;
				}
				else
				{
					check[0] = check[0];
				}
			}

			if (arr[*pd + 37 - 75][*pe + 37] < 100 && *pd>2 * 75 + 21)
			{
				check[1] = 1;
			}
			else
			{
				check[1] = 0;
			}
			if (arr[*pd + 37 + 75][*pe + 37] < 100 && *pd < 620 - 2 * 75)
			{
				check[2] = 1;
			}
			else
			{
				check[2] = 0;
			}
			if (arr[*pd + 37][*pe + 37 + 75] < 100 && *pe < 620 - 2 * 75)
			{
				check[3] = 1;
			}
			else
			{
				check[3] = 0;
			}
			if (check[0] == 1)
			{
				for (rg = 3; 20 <= *pd + rg && *pd + rg <= 590 && arr[*pd + 75 + rg][*pe + 37] <= 98 && *pe + 10 <= 590 && *pe + 10 >= 20 && *pmov % 6 > 2 && *pmov % 6 <= 5; rg++)
				{
					getimage(&background1, *pd + rg + 78, *pe + 35, 5, 5);
					putimage(*pd + rg + 73, *pe + 35, &bullet);
					Sleep(10);
					putimage(*pd + rg + 73, *pe + 35, &background1);
					putimage(*pa, *pc, &img1);
				}
				*pmov += 1;
				if (arr[*pd + 75 + rg][*pe + 37] == 100)
				{
					*pHP1 -= 1;
				}
			}
			else
			{
				if (check[1] == 1)
				{
					arr[*pd + 37][*pe + 37] = 0;
					clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
					putimage(*pd, *pe, &background);
					putimage(*pd - *pb, *pe, &img2);
					*pd = *pd - *pb;
					*pe = *pe;
					arr[*pd + 37][*pe + 37] = 99;
					*pmov += 1;
				}
				else
				{
					if (check[2] == 1)
					{
						arr[*pd + 37][*pe + 37] = 0;
						clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
						putimage(*pd, *pe, &background);
						putimage(*pd + *pb, *pe, &img2);
						*pd = *pd + *pb;
						*pe = *pe;
						arr[*pd + 37][*pe + 37] = 99;
						*pmov += 1;
					}
					else
					{
						if (check[3] == 1)
						{
							arr[*pd + 37][*pe + 37] = 0;
							clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
							putimage(*pd, *pe, &background);
							putimage(*pd, *pe + *pb, &img2);
							*pd = *pd;
							*pe = *pe + *pb;
							arr[*pd + 37][*pe + 37] = 99;
							*pmov += 1;
						}
						else
						{
							if (*pe >= 95)
							{
								arr[*pd + 37][*pe + 37] = 0;
								clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
								putimage(*pd, *pe, &background);
								putimage(*pd, *pe - *pb, &img2);
								*pd = *pd;
								*pe = *pe - *pb;
								arr[*pd + 37][*pe + 37] = 99;
								*pmov += 1;
							}
							else
							{
								arr[*pd + 37][*pe + 37] = 0;
								clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
								putimage(*pd, *pe, &background);
								putimage(*pd, *pe + *pb, &img2);
								*pd = *pd;
								*pe = *pe + *pb;
								arr[*pd + 37][*pe + 37] = 99;
								*pmov += 1;
							}
						}
					}
				}
			}
		}
		if (*pc == *pe && *pa < *pd)
		{
			for (check[0] = 0, i = 0; i <= (*pd - *pa) / 75; i += 75)
			{
				if (arr[*pd + 37 - i][*pe + 37] > 100)
				{
					check[0] = 1;
				}
				else
				{
					check[0] = check[0];
				}
			}

			if (arr[*pd + 37 - 75][*pe + 37] < 100 && *pd>2 * 75 + 21)
			{
				check[1] = 1;
			}
			else
			{
				check[1] = 0;
			}
			if (arr[*pd + 37 + 75][*pe + 37] < 100 && *pd < 620 - 2 * 75)
			{
				check[2] = 1;
			}
			else
			{
				check[2] = 0;
			}
			if (arr[*pd + 37][*pe + 37 + 75] < 100 && *pe < 620 - 2 * 75)
			{
				check[3] = 1;
			}
			else
			{
				check[3] = 0;
			}
			if (check[0] == 1)
			{
				for (lf = 3; 20 <= *pd - lf && *pd - lf <= 590 && arr[*pd - lf][*pe + 37] <= 98 && *pe + 10 <= 590 && *pe + 10 >= 20 && *pmov % 6 > 2 && *pmov % 6 <= 5; lf++)
				{
					getimage(&background1, *pd - lf - 7, *pe + 35, 5, 5);
					putimage(*pd - lf - 2, *pe + 35, &bullet);
					Sleep(10);
					putimage(*pd - lf - 2, *pe + 35, &background1);
					putimage(*pa, *pc, &img1);
				}
				*pmov += 1;
				if (arr[*pd - lf][*pe + 37] == 100)
				{
					*pHP1 -= 1;
				}
			}
			else
			{
				if (check[1] == 1)
				{
					arr[*pd + 37][*pe + 37] = 0;
					clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
					putimage(*pd, *pe, &background);
					putimage(*pd - *pb, *pe, &img2);
					*pd = *pd - *pb;
					*pe = *pe;
					arr[*pd + 37][*pe + 37] = 99;
					*pmov += 1;
				}
				else
				{
					if (check[2] == 1)
					{
						arr[*pd + 37][*pe + 37] = 0;
						clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
						putimage(*pd, *pe, &background);
						putimage(*pd + *pb, *pe, &img2);
						*pd = *pd + *pb;
						*pe = *pe;
						arr[*pd + 37][*pe + 37] = 99;
						*pmov += 1;
					}
					else
					{
						if (check[3] == 1)
						{
							arr[*pd + 37][*pe + 37] = 0;
							clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
							putimage(*pd, *pe, &background);
							putimage(*pd, *pe + *pb, &img2);
							*pd = *pd;
							*pe = *pe + *pb;
							arr[*pd + 37][*pe + 37] = 99;
							*pmov += 1;
						}
						else
						{
							if (*pe >= 95)
							{
								arr[*pd + 37][*pe + 37] = 0;
								clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
								putimage(*pd, *pe, &background);
								putimage(*pd, *pe - *pb, &img2);
								*pd = *pd;
								*pe = *pe - *pb;
								arr[*pd + 37][*pe + 37] = 99;
								*pmov += 1;
							}
							else
							{
								arr[*pd + 37][*pe + 37] = 0;
								clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
								putimage(*pd, *pe, &background);
								putimage(*pd, *pe + *pb, &img2);
								*pd = *pd;
								*pe = *pe + *pb;
								arr[*pd + 37][*pe + 37] = 99;
								*pmov += 1;
							}
						}
					}
				}
			}
		}
		else
		{
			if (arr[*pd + 37][*pe + 37 - 75] < 100 && *pe < 620 - 2 * 75)
			{
				check[0] = 1;
			}
			else
			{
				check[0] = 0;
			}
			if (arr[*pd + 37 - 75][*pe + 37] < 100 && *pd>2 * 75 + 21)
			{
				check[1] = 1;
			}
			else
			{
				check[1] = 0;
			}
			if (arr[*pd + 37 + 75][*pe + 37] < 100 && *pd < 620 - 2 * 75)
			{
				check[2] = 1;
			}
			else
			{
				check[2] = 0;
			}
			if (arr[*pd + 37][*pe + 37 + 75] < 100 && *pe < 620 - 2 * 75)
			{
				check[3] = 1;
			}
			else
			{
				check[3] = 0;
			}
			if (check[0] == 1)
			{
				arr[*pd + 37][*pe + 37] = 0;
				clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
				putimage(*pd, *pe, &background);
				putimage(*pd, *pe - *pb, &img2);
				*pd = *pd;
				*pe = *pe - *pb;
				arr[*pd + 37][*pe + 37] = 99;
				*pmov += 1;
			}
			else
			{
				if (check[1] == 1)
				{
					arr[*pd + 37][*pe + 37] = 0;
					clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
					putimage(*pd, *pe, &background);
					putimage(*pd - *pb, *pe, &img2);
					*pd = *pd - *pb;
					*pe = *pe;
					arr[*pd + 37][*pe + 37] = 99;
					*pmov += 1;
				}
				else
				{
					if (check[2] == 1)
					{
						arr[*pd + 37][*pe + 37] = 0;
						clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
						putimage(*pd, *pe, &background);
						putimage(*pd + *pb, *pe, &img2);
						*pd = *pd + *pb;
						*pe = *pe;
						arr[*pd + 37][*pe + 37] = 99;
						*pmov += 1;
					}
					else
					{
						if (check[3] == 1)
						{
							arr[*pd + 37][*pe + 37] = 0;
							clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
							putimage(*pd, *pe, &background);
							putimage(*pd, *pe + *pb, &img2);
							*pd = *pd;
							*pe = *pe + *pb;
							arr[*pd + 37][*pe + 37] = 99;
							*pmov += 1;
						}
						else
						{
							if (95 <= *pe && arr[*pd + 37][*pe - 38] <= 98 && *pmov % 6 > 2 && *pmov % 6 <= 5)
							{
								arr[*pd + 37][*pe + 37] = 0;
								clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
								putimage(*pd, *pe, &background);
								putimage(*pd, *pe - *pb, &img2);
								*pd = *pd;
								*pe = *pe - *pb;
								arr[*pd + 37][*pe + 37] = 99;
								*pmov += 1;
							}
							else
							{
								if (*pe <= 545 && arr[*pd + 37][*pe + 37 + 75] <= 98 && *pmov % 6 > 2 && *pmov % 6 <= 5)
								{
									arr[*pd + 37][*pe + 37] = 0;
									clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
									putimage(*pd, *pe, &background);
									putimage(*pd, *pe + *pb, &img2);
									*pd = *pd;
									*pe = *pe + *pb;
									arr[*pd + 37][*pe + 37] = 99;
									*pmov += 1;
								}
								else
								{
									if (95 <= *pd && arr[*pd - 38][*pe + 37] <= 98 && *pmov % 6 > 2 && *pmov % 6 <= 5)
									{
										arr[*pd + 37][*pe + 37] = 0;
										clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
										putimage(*pd, *pe, &background);
										putimage(*pd - *pb, *pe, &img2);
										*pd = *pd - *pb;
										*pe = *pe;
										arr[*pd + 37][*pe + 37] = 99;
										*pmov += 1;
									}
									else
									{
										if (*pd <= 545 && arr[*pd + 37 + 75][*pe + 37] <= 98 && *pmov % 6 > 2 && *pmov % 6 <= 5)
										{
											arr[*pd + 37][*pe + 37] = 0;
											clearrectangle(*pd, *pe, *pd + 74, *pe + 74);
											putimage(*pd, *pe, &background);
											putimage(*pd + *pb, *pe, &img2);
											*pd = *pd + *pb;
											*pe = *pe;
											arr[*pd + 37][*pe + 37] = 99;
											*pmov += 1;
										}
									}
								}
							}
						}
					}
				}
			}



		}
		Sleep(1000);

	}
	if (*pHP1 == 0)
	{
		clearrectangle(*pa, *pc, *pa + 75, *pc + 75);
		putimage(*pa, *pc, &background);
		z = 2;
	}

	if (*pHP2 == 0)
	{
		clearrectangle(*pd, *pe, *pd + 75, *pe + 75);
		putimage(*pd, *pe, &background);
		z = 1;

	}
	return z;
}
