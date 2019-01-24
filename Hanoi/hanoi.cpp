/*1551445 童佳燕 计算机科学与技术1班*/
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include<cstdio>
#include"cmd_console_tools.h"
#include<iomanip>
const int basic_X = 10;
const int basic_Y = 12;
using namespace std;

int sum = 0;//步数
int n;//盘子数量
int pan[3][10];//三根柱子，每根容量为10
char beg, mid, final;



void check()//要求用户输入数据以及输入正确性的检查
{
	int f(char x);
	while (1)
	{
		cout << "请输入汉诺塔的层数（1-10）： ";
		cin >> n;
		if (n > 10 || n < 1 || cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		cout << "请输入起始柱(A-C)：";
		cin >> beg;
		if (beg > 'C' || beg < 'A' || cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		cout << "请输入结束柱（A-C）：";
		cin >> final;
		if (final > 'C' || final < 'A' || cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		break;
	}
	if (f(final) + f(beg) == 1)//通过输入的起始柱和结束柱，判断中间柱
		mid = 'C';
	else if (f(final) + f(beg) == 2)
		mid = 'B';
	else
		mid = 'A';
}

int f(char x)
{
	if (x == 'A')
		return 0;
	else if (x == 'B')
		return 1;
	else
		return 2;
}

void rate(int t)
{
	if (t == 0)
		getchar();
	else if (t == 1)
		Sleep(100);
	else if (t == 2)
		Sleep(80);
	else if (t == 3)
		Sleep(60);
	else if (t == 4)
		Sleep(40);
	else if (t == 5)
		Sleep(20);
}

void print()//输出数组值
{
	cout << setw(7) << "A: ";
	for (int k = 0; k < 10; k++)
	{
		if (pan[0][k] > 0)
			cout << pan[0][k] << " ";
		else
			cout << "  ";
	}
	cout << '\t' << "B: ";
	for (int k = 0; k < 10; k++)
	{
		if (pan[1][k] > 0)
			cout << pan[1][k] << " ";
		else
			cout << "  ";
	}
	cout << '\t' << "C: ";
	for (int k = 0; k < 10; k++)
	{
		if (pan[2][k] > 0)
			cout << pan[2][k] << " ";
		else
			cout << "  ";
	}
	cout << endl;
}


void print2(int y1, int y2, int y3)//输出数组竖式值
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int k = 0; k<10; k++)
	{
		y1--;
		gotoxy(hout, basic_X + 1, y1);//不该把y--以及定位语句放在if语句内！
		if (pan[0][k] > 0)
			cout << pan[0][k];
		else
			cout << "  ";
	}
	for (int k = 0; k<10; k++)
	{
		y2--;
		gotoxy(hout, basic_X + 15, y2);
		if (pan[1][k] > 0)
			cout << pan[1][k];
		else
			cout << "  ";
	}
	for (int k = 0; k<10; k++)
	{
		y3--;
		gotoxy(hout, basic_X + 30, y3);
		if (pan[2][k] > 0)
			cout << pan[2][k];
		else
			cout << "  ";
	}
}

void print_3(int m)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (m)
		gotoxy(hout, basic_X, basic_Y + 14);
	else
		gotoxy(hout, basic_X, basic_Y);
	cout << "=================================" << endl;
	if (m)
		gotoxy(hout, basic_X + 1, basic_Y + 15);
	else
		gotoxy(hout, basic_X, basic_Y + 1);
	cout << "A" << "\t\t" << "B" << "\t\t" << "C" << endl;
	cout << endl;
	gotoxy(hout, 0, basic_Y + 8);
	if (m)
		gotoxy(hout, 0, basic_Y + 19);
	cout << "起始：";
	print();

}

void draw()//画三根柱子
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	setconsoleborder(hout, 100, 35);
	int X = 5;
	for (int i = 0; i < 3; i++)
	{
		showch(hout, X + i * 30, 15, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 20);
		Sleep(50);
	}
	for (int j = 15; j >2; j--)
	{
		showch(hout, X + 10, j, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
		Sleep(50);
		showch(hout, X + 40, j, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
		Sleep(50);
		showch(hout, X + 70, j, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
		Sleep(50);
	}
	showch(hout, 0, 28, ' ', 0, 7, 1);
}

void draw_pan()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	for (int j = 14, p = n; p> 0; j--, p--)
	{
		showch(hout, (15 + 30 * f(beg) - p), j, ' ', p, p, 2 * p + 1);
		Sleep(50);
	}
	showch(hout, 0, 33, ' ', 0, 7, 1);
}

void move_pan(int p, char x, char y, int j, int k, int t)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int s = 15 - j; s > 2; s--)
	{
		showch(hout, 15 + 30 * f(x) - p, s - 1, ' ', p, p, p * 2 + 1);
		if (s < 15 - j)
		{
			showch(hout, 15 + 30 * f(x), s, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
			showch(hout, 15 + 30 * f(x) - p, s, ' ', 0, 7, p);
			showch(hout, 15 + 30 * f(x) + 1, s, ' ', 0, 7, p);
		}
		if (t == 0)
			Sleep(50);
		else
			rate(t);
	}
	int q = ((f(x) > f(y)) ? (-1) : 1);
	for (int i = 15 + 30 * f(x) - p; i != 15 + 30 * f(y) - p; i += q)
	{
		showch(hout, i + q, 2, ' ', p, p, p * 2 + 1);
		if (q == 1)
			showch(hout, i, 2, ' ', 0, 7, 1);
		else
			showch(hout, i + 2 * p, 2, ' ', 0, 7, p * 2 + 1);
		if (t == 0)
			Sleep(50);
		else
			rate(t);
	}
	for (int w = 3; w <14 - k; w++)
	{
		showch(hout, 15 + 30 * f(y) - p, w, ' ', p, p, p * 2 + 1);
		if (w >3)
			showch(hout, 15 + 30 * f(y), w - 1, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
		else
			showch(hout, 15 + 30 * f(y), w - 1, ' ', 0, 7, 1);
		showch(hout, 15 + 30 * f(y) - p, w - 1, ' ', 0, 7, p);
		showch(hout, 15 + 30 * f(y) + 1, w - 1, ' ', 0, 7, p);
		if (t == 0)
			Sleep(50);
		else
			rate(t);
	}
	showch(hout, 0, 28, ' ', 0, 7, 1);
}


void move(int i, char x, char y, int pace, int leap, int t, int m) //移动过程//m值是否要移动图形
{//汉诺塔过程pace指是否打印步数   //leap指内部数组随步骤的显示，t指是否需要延时，以及打印竖式
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (t >= 0)
		rate(t);
	sum++;
	if (pace)
	{
		if (t >= 0)
			gotoxy(hout, 0, basic_Y + 8);
		if (m)
			gotoxy(hout, 0, basic_Y + 19);
		cout << "第" << setw(4) << sum << "步 " << '(' << setw(2) << i << "):" << x << "-->" << y;
		if (!leap)
			cout << endl;
	}
	else
		cout << i << '#' << ':' << x << "-->" << y << endl;
	if (leap)
	{
		int j = 0, k = 0;//过程参考 提示，栈
		while (pan[f(x)][j] != -1 && j < n)
			j++;
		while (pan[f(y)][k] != -1 && k < n)
			k++;
		pan[f(y)][k] = pan[f(x)][j - 1];
		pan[f(x)][j - 1] = -1;
		print();
		if (t >= 0)
			if (m)
			{
				print2(basic_Y + 14, basic_Y + 14, basic_Y + 14);
				move_pan(i, x, y, j - 1, k - 1, t);//////
			}
			else
				print2(basic_Y, basic_Y, basic_Y);
	}

}


void hanoi(int n, char A, char B, char C, int pace, int leap, int t, int m)//汉诺塔过程pace指是否打印步数
{                                                 //leap指内部数组随步骤的显示，t指是否需要延时，以及打印竖式
	if (n == 1)
		move(n, A, C, pace, leap, t, m);
	else
	{
		hanoi(n - 1, A, C, B, pace, leap, t, m);
		move(n, A, C, pace, leap, t, m);
		hanoi(n - 1, B, A, C, pace, leap, t, m);
	}
}



void basic()
{
	check();
	hanoi(n, beg, mid, final, 0, 0, -1, 0);
	cout << endl;
	cout << "，按回车键继续...";
	while (_getch() != '\r');
}

void basic_inner()
{
	check();
	hanoi(n, beg, mid, final, 1, 0, -1, 0);
	cout << endl;
	cout << "，按回车键继续...";
	while (_getch() != '\r');
}

void show_inner()
{
	check();
	for (int i = 0; i <10; i++)//为数组，即各柱子盘子数赋初值//!!!!
	{
		pan[f(beg)][i] = n - i;
		pan[f(mid)][i] = -1;
		pan[f(final)][i] = -1;
	}
	system("cls");
	system("mode con cols=100");
	cout << "起   始：          ";
	print();
	hanoi(n, beg, mid, final, 1, 1, -1, 0);
	cout << endl;
	cout << "，按回车键继续...";
	while (_getch() != '\r');
}

void show_2(int m)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int t;
	check();
	while (1)
	{
		cout << "请输入移动速度（0-5），0-按回车单步演示，1-延时最长，5-延时最短：";
		cin >> t;
		if (cin.fail() || t < 0 || t > 5)
		{
			cin.clear();
			cin.ignore();
			continue;
		}
		break;
	}
	for (int i = 0; i < 10; i++)//为数组，即各柱子盘子数赋初值
	{
		pan[f(beg)][i] = n - i;
		pan[f(mid)][i] = -1;
		pan[f(final)][i] = -1;
	}
	system("cls");
	gotoxy(hout, 0, 0);
	cout << "从" << beg << "移动到" << final << ",共" << n << "层，延时设置为" << t << endl;
	print_3(m);
	rate(t);
	print2(basic_Y, basic_Y, basic_Y);
	hanoi(n, beg, mid, final, 1, 1, t, m);
	system("cls");
	system("mode con cols=100");
	cout << endl;
	cout << "按回车键继续...";
	while (_getch() != '\r');
}

void draw_2()
{
	check();
	draw();
	draw_pan();
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(hout, 0, 28);
	cout << "，按回车键继续...";
	while (_getch() != '\r');
}

void first()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	check();
	draw();
	draw_pan();
	move_pan(1, beg, mid, n - 1, -1, 1);
	gotoxy(hout, 0, 33);
	cout << "，按回车键继续...";
	while (_getch() != '\r');
}

void aotu()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	check();
	int t;
	while (1)
	{
		cout << "请输入移动速度（0-5），0-按回车单步演示，1-延时最长，5-延时最短：";
		cin >> t;
		if (cin.fail() || t < 0 || t > 5)
		{
			cin.clear();
			cin.ignore();
			continue;
		}
		break;
	}
	for (int i = 0; i < 10; i++)//为数组，即各柱子盘子数赋初值
	{
		pan[f(beg)][i] = n - i;
		pan[f(mid)][i] = -1;
		pan[f(final)][i] = -1;
	}
	draw();
	draw_pan();
	gotoxy(hout, 0, 0);
	cout << "从" << beg << "移动到" << final << ",共" << n << "层，延时设置为" << t << endl;
	print_3(1);
	rate(t);
	print2(basic_Y + 14, basic_Y + 14, basic_Y + 14);
	hanoi(n, beg, mid, final, 1, 1, t, 1);
	cout << endl;
	cout << "，按回车键继续...";
	while (_getch() != '\r');
}

void game()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	check();
	draw();
	draw_pan();
	for (int i = 0; i < 10; i++)//为数组，即各柱子盘子数赋初值
	{
		pan[f(beg)][i] = n - i;
		pan[f(mid)][i] = -1;
		pan[f(final)][i] = -1;
	}
	print_3(1);
	print2(basic_Y + 14, basic_Y + 14, basic_Y + 14);
	while (1)
	{
		gotoxy(hout, 0, 29);
		cout << "请输入移动的柱号（命令形式：AC A顶端的盘子移到C）：";
		cout << "     ";
		gotoxy(hout, 51, 29);
		char c[2];
		for (int i = 0; i < 2; i++)
			cin >> c[i];
		int j = 0, k = 0;//过程参考 提示，栈
		while (pan[f(c[0])][j] != -1 && j < n)
			j++;
		while (pan[f(c[1])][k] != -1 && k < n)
			k++;
		if (pan[f(c[0])][j - 1] > pan[f(c[1])][k - 1] && pan[f(c[1])][k - 1]>0)
		{

			cout << "大盘压小盘，非法移动！";
			Sleep(500);
			gotoxy(hout, 0, 30);
			cout << "                                 ";
			continue;
		}
		if (c[0] == c[1])
			continue;
		else
		{
			int b = pan[f(c[0])][j - 1];
			move(b, c[0], c[1], 1, 1, 0, 1);
		}
		j = 0, k = 0;//过程参考 提示，栈
		while (pan[f(beg)][j] != -1 && j < n)
			j++;
		while (pan[f(final)][k] != -1 && k < n)
			k++;
		if (j == 0 && k == n)
		{
			cout << "游戏结束！" << endl;
			break;
		}

	}
	cout << "，按回车键继续...";
	while (_getch() != '\r');
}

int main()
{
	int choice = 1;
	while (choice != 0)
	{
		system("cls");
		cout << "-------------------------------------------------" << endl;
		cout << "1.基本解\n2.基本解（步数记录）\n3.内部数组显示（横向）" << endl;
		cout << "4.内部数组显示（纵向+横向）\n5.图形解-预备-画三个圆柱" << endl;
		cout << "6.图形解-预备-在起始柱上画n个盘子\n7.图形解-预备-第一次移动" << endl;
		cout << "8.图形解-自动移动版本\n9.图形解-游戏版本\n0.退出" << endl;
		cout << "---------------------------------------------------\n[请选择0-9]" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			break;
		case 1:
			basic();
			break;
		case 2:
			sum = 0;
			basic_inner();
			break;
		case 3:
			sum = 0;
			show_inner();
			break;
		case 4:
			sum = 0;
			show_2(0);
			break;
		case 5:
			draw();
			cout << "，按回车键继续...";
			while (_getch() != '\r');
			break;
		case 6:
			draw_2();
			break;
		case 7:
			sum = 0;
			first();
			break;
		case 8:
			sum = 0;
			aotu();
			break;
		case 9:
			sum = 0;
			game();
			break;
		}
	}
	return 0;
}