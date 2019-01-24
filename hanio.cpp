/*1551445 ͯ���� �������ѧ�뼼��1��*/
#include<iostream>
#include<iomanip>
#include<Windows.h>
#include <cstdio>
#include <conio.h>
#include <time.h>
using namespace std;
int sum = 0;//����
int n;//��������
int pan[3][10];//�������ӣ�ÿ������Ϊ10
int t;
char show[3];
void rate(int t);
int basic_X = 10;
int basic_Y = 12;//��ĳ��������Ϊ�ο�����߳�����޸���
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
		cout << "���������1-10��  ";
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
		cout << "��������ʼ��A-C: ";
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
		cout << "�����������A-C: ";
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
		cout << "�������ƶ��ٶȣ�0-5����0-���س�������ʾ��1-��ʱ���5-��ʱ��̣�";
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
		cout << "�������Ƿ���ʾ�ڲ�����ֵ��0-������ʾ��1-������ʾ��:";
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
	cout << "��" << begin << "�ƶ���" << final << ",��" << n << "�㣬��ʱ����Ϊ" << t << ((show) ? ",��ʾ�ڲ�����ֵ" : ",����ʾ�ڲ�����ֵ") << endl;	
	gotoxy(hout, basic_X, basic_Y);
	cout << "=================================" << endl;
	gotoxy(hout, basic_X+1, basic_Y+1);
	cout << "A" << "\t\t" << "B" << "\t\t" << "C" << endl;
	cout << endl;

	if (f(final) + f(begin) == 1)//ͨ���������ʼ���ͽ��������ж��м���
		mid = 'C';
	else if (f(final) + f(begin) == 2)
		mid = 'B';
	else
		mid = 'A';

	for (int i = 0; i < n; i++)//Ϊ���飬������������������ֵ
	{
		pan[f(begin)][i] = n - i;
		pan[f(mid)][i] = -1;
		pan[f(final)][i] = -1;
	}

	if ( show[0] == '1')
	{
		gotoxy(hout, 0, 20);
		cout << "��ʼ��";
		print();
	}
	rate(t);
	hanoi(n, begin, mid, final);
	return 0;
}

void hanoi(int n, char A, char B, char C)//��ŵ������
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
void move(int i, char x, char y) //�ƶ�����
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	void gotoxy(HANDLE hout, int x, int y);
	int f(char);
	void print2(int, int, int);
	void print();

	int j = 0, k = 0;//���̲ο� ��ʾ��ջ
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
		cout << "��" << sum << "��" << " ";
		cout << i << '#' << ':' << x << "-->" << y;
		print();
	}
}

int f(char x) //���ά�������������������������ʼ��������Ķ�Ӧ��ϵ
{
	if (x == 'A')
		return 0;
	else if (x == 'B')
		return 1;
	else
		return 2;
}

void print()//�������ֵ
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

void print2(int y1,int y2,int y3)//���������ʽֵ
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int  k = 0; k<10; k++)
	{
		y1--;
		gotoxy(hout, basic_X+1, y1);//���ð�y--�Լ���λ������if����ڣ�
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