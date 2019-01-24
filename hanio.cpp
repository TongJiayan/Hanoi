/*1551445 童佳燕 计算机科学与技术1班*/
#include<iostream>
#include<iomanip>
#include<Windows.h>
#include <cstdio>
#include <conio.h>
#include <time.h>
using namespace std;
int sum = 0;//步数
int n;//盘子数量
int pan[3][10];//三根柱子，每根容量为10
int t;
char show[3];
void rate(int t);
int basic_X = 10;
int basic_Y = 12;//以某个对象作为参考，提高程序可修改性
int main()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	void print();
	void gotoxy(HANDLE hout, int x, int y);
	int f(char);
	void hanoi(int, char, char, char);	
	void rate(int);

	system("cls");
	system("mode con cols=100");

	char begin, mid, final;
	
	while (1)
	{
		cout << "请输入层数1-10：  ";
		cin >> n;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
		}
		else if (n < 10 && n>1)
			break;
	}
	while (1)
	{
		cout << "请输入起始柱A-C: ";
		cin >> begin;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
		}
		else if (begin <='C' && begin>='A')
			break;
	}
	while (1)
	{
		cout << "请输入结束柱A-C: ";
		cin >> final;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
		}
		else if (final <= 'C' && final >= 'A')
			break;
	}
	while (1)
	{
		cout << "请输入移动速度（0-5），0-按回车单步演示，1-延时最长，5-延时最短：";
		cin >> t;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
		}
		else if (t>=0&&t<=5)
			break;
	}
	while (1)
	{
		cout << "请输入是否显示内部数组值（0-代表不显示，1-代表显示）:";
		cin >> show;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
		}
		else if ((show[0] == '0' || show[0]=='1')&&show[1]=='-')
			break;
	}
	system("cls");
	cout << "从" << begin << "移动到" << final << ",共" << n << "层，延时设置为" << t << ((show) ? ",显示内部数组值" : ",不显示内部数组值") << endl;	
	gotoxy(hout, basic_X, basic_Y);
	cout << "=================================" << endl;
	gotoxy(hout, basic_X+1, basic_Y+1);
	cout << "A" << "\t\t" << "B" << "\t\t" << "C" << endl;
	cout << endl;

	if (f(final) + f(begin) == 1)//通过输入的起始柱和结束柱，判断中间柱
		mid = 'C';
	else if (f(final) + f(begin) == 2)
		mid = 'B';
	else
		mid = 'A';

	for (int i = 0; i < n; i++)//为数组，即各柱子盘子数赋初值
	{
		pan[f(begin)][i] = n - i;
		pan[f(mid)][i] = -1;
		pan[f(final)][i] = -1;
	}

	if ( show[0] == '1')
	{
		gotoxy(hout, 0, 20);
		cout << "起始：";
		print();
	}
	rate(t);
	hanoi(n, begin, mid, final);
	return 0;
}

void hanoi(int n, char A, char B, char C)//汉诺塔过程
{
	void move(int, char, char);
	if (n == 1)
	{
		rate(t);
		sum++;
		move(n, A, C);		
	}
	else
	{
		hanoi(n - 1, A, C, B);
		rate(t);
		sum++;
		move(n, A, C);		
		hanoi(n - 1, B, A, C);
	}
}
void move(int i, char x, char y) //移动过程
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	void gotoxy(HANDLE hout, int x, int y);
	int f(char);
	void print2(int, int, int);
	void print();

	int j = 0, k = 0;//过程参考 提示，栈
	while (pan[f(x)][j] != -1 && j < n)
		j++;
	while (pan[f(y)][k] != -1 && k < n)
		k++;
	pan[f(y)][k] = pan[f(x)][j - 1];
	pan[f(x)][j - 1] = -1;

	print2(basic_Y, basic_Y, basic_Y);

	if (show[0] == '1')
	{
		gotoxy(hout, 0, basic_Y+8);
		cout << "第" << sum << "步" << " ";
		cout << i << '#' << ':' << x << "-->" << y;
		print();
	}
}

int f(char x) //与二维数组结合起来，方便了输入的起始柱与数组的对应关系
{
	if (x == 'A')
		return 0;
	else if (x == 'B')
		return 1;
	else
		return 2;
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

void rate(int t)
{
	if (t == 0)
		getchar();
	else if (t == 1)
		Sleep(1000);
	else if (t == 2)
		Sleep(800);
	else if (t == 3)
		Sleep(600);
	else if (t == 4)
		Sleep(400);
	else if (t == 5)
		Sleep(200);
}

void gotoxy(HANDLE hout, int X, int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

void print2(int y1,int y2,int y3)//输出数组竖式值
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int  k = 0; k<10; k++)
	{
		y1--;
		gotoxy(hout, basic_X+1, y1);//不该把y--以及定位语句放在if语句内！
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