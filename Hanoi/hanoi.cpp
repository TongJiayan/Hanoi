/*1551445 ͯ���� �������ѧ�뼼��1��*/
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

int sum = 0;//����
int n;//��������
int pan[3][10];//�������ӣ�ÿ������Ϊ10
char beg, mid, final;



void check()//Ҫ���û����������Լ�������ȷ�Եļ��
{
	int f(char x);
	while (1)
	{
		cout << "�����뺺ŵ���Ĳ�����1-10���� ";
		cin >> n;
		if (n > 10 || n < 1 || cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		cout << "��������ʼ��(A-C)��";
		cin >> beg;
		if (beg > 'C' || beg < 'A' || cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		cout << "�������������A-C����";
		cin >> final;
		if (final > 'C' || final < 'A' || cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		break;
	}
	if (f(final) + f(beg) == 1)//ͨ���������ʼ���ͽ��������ж��м���
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


void print2(int y1, int y2, int y3)//���������ʽֵ
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int k = 0; k<10; k++)
	{
		y1--;
		gotoxy(hout, basic_X + 1, y1);//���ð�y--�Լ���λ������if����ڣ�
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
	cout << "��ʼ��";
	print();

}

void draw()//����������
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
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
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
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


void move(int i, char x, char y, int pace, int leap, int t, int m) //�ƶ�����//mֵ�Ƿ�Ҫ�ƶ�ͼ��
{//��ŵ������paceָ�Ƿ��ӡ����   //leapָ�ڲ������沽�����ʾ��tָ�Ƿ���Ҫ��ʱ���Լ���ӡ��ʽ
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
		cout << "��" << setw(4) << sum << "�� " << '(' << setw(2) << i << "):" << x << "-->" << y;
		if (!leap)
			cout << endl;
	}
	else
		cout << i << '#' << ':' << x << "-->" << y << endl;
	if (leap)
	{
		int j = 0, k = 0;//���̲ο� ��ʾ��ջ
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


void hanoi(int n, char A, char B, char C, int pace, int leap, int t, int m)//��ŵ������paceָ�Ƿ��ӡ����
{                                                 //leapָ�ڲ������沽�����ʾ��tָ�Ƿ���Ҫ��ʱ���Լ���ӡ��ʽ
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
	cout << "�����س�������...";
	while (_getch() != '\r');
}

void basic_inner()
{
	check();
	hanoi(n, beg, mid, final, 1, 0, -1, 0);
	cout << endl;
	cout << "�����س�������...";
	while (_getch() != '\r');
}

void show_inner()
{
	check();
	for (int i = 0; i <10; i++)//Ϊ���飬������������������ֵ//!!!!
	{
		pan[f(beg)][i] = n - i;
		pan[f(mid)][i] = -1;
		pan[f(final)][i] = -1;
	}
	system("cls");
	system("mode con cols=100");
	cout << "��   ʼ��          ";
	print();
	hanoi(n, beg, mid, final, 1, 1, -1, 0);
	cout << endl;
	cout << "�����س�������...";
	while (_getch() != '\r');
}

void show_2(int m)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int t;
	check();
	while (1)
	{
		cout << "�������ƶ��ٶȣ�0-5����0-���س�������ʾ��1-��ʱ���5-��ʱ��̣�";
		cin >> t;
		if (cin.fail() || t < 0 || t > 5)
		{
			cin.clear();
			cin.ignore();
			continue;
		}
		break;
	}
	for (int i = 0; i < 10; i++)//Ϊ���飬������������������ֵ
	{
		pan[f(beg)][i] = n - i;
		pan[f(mid)][i] = -1;
		pan[f(final)][i] = -1;
	}
	system("cls");
	gotoxy(hout, 0, 0);
	cout << "��" << beg << "�ƶ���" << final << ",��" << n << "�㣬��ʱ����Ϊ" << t << endl;
	print_3(m);
	rate(t);
	print2(basic_Y, basic_Y, basic_Y);
	hanoi(n, beg, mid, final, 1, 1, t, m);
	system("cls");
	system("mode con cols=100");
	cout << endl;
	cout << "���س�������...";
	while (_getch() != '\r');
}

void draw_2()
{
	check();
	draw();
	draw_pan();
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(hout, 0, 28);
	cout << "�����س�������...";
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
	cout << "�����س�������...";
	while (_getch() != '\r');
}

void aotu()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	check();
	int t;
	while (1)
	{
		cout << "�������ƶ��ٶȣ�0-5����0-���س�������ʾ��1-��ʱ���5-��ʱ��̣�";
		cin >> t;
		if (cin.fail() || t < 0 || t > 5)
		{
			cin.clear();
			cin.ignore();
			continue;
		}
		break;
	}
	for (int i = 0; i < 10; i++)//Ϊ���飬������������������ֵ
	{
		pan[f(beg)][i] = n - i;
		pan[f(mid)][i] = -1;
		pan[f(final)][i] = -1;
	}
	draw();
	draw_pan();
	gotoxy(hout, 0, 0);
	cout << "��" << beg << "�ƶ���" << final << ",��" << n << "�㣬��ʱ����Ϊ" << t << endl;
	print_3(1);
	rate(t);
	print2(basic_Y + 14, basic_Y + 14, basic_Y + 14);
	hanoi(n, beg, mid, final, 1, 1, t, 1);
	cout << endl;
	cout << "�����س�������...";
	while (_getch() != '\r');
}

void game()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	check();
	draw();
	draw_pan();
	for (int i = 0; i < 10; i++)//Ϊ���飬������������������ֵ
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
		cout << "�������ƶ������ţ�������ʽ��AC A���˵������Ƶ�C����";
		cout << "     ";
		gotoxy(hout, 51, 29);
		char c[2];
		for (int i = 0; i < 2; i++)
			cin >> c[i];
		int j = 0, k = 0;//���̲ο� ��ʾ��ջ
		while (pan[f(c[0])][j] != -1 && j < n)
			j++;
		while (pan[f(c[1])][k] != -1 && k < n)
			k++;
		if (pan[f(c[0])][j - 1] > pan[f(c[1])][k - 1] && pan[f(c[1])][k - 1]>0)
		{

			cout << "����ѹС�̣��Ƿ��ƶ���";
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
		j = 0, k = 0;//���̲ο� ��ʾ��ջ
		while (pan[f(beg)][j] != -1 && j < n)
			j++;
		while (pan[f(final)][k] != -1 && k < n)
			k++;
		if (j == 0 && k == n)
		{
			cout << "��Ϸ������" << endl;
			break;
		}

	}
	cout << "�����س�������...";
	while (_getch() != '\r');
}

int main()
{
	int choice = 1;
	while (choice != 0)
	{
		system("cls");
		cout << "-------------------------------------------------" << endl;
		cout << "1.������\n2.�����⣨������¼��\n3.�ڲ�������ʾ������" << endl;
		cout << "4.�ڲ�������ʾ������+����\n5.ͼ�ν�-Ԥ��-������Բ��" << endl;
		cout << "6.ͼ�ν�-Ԥ��-����ʼ���ϻ�n������\n7.ͼ�ν�-Ԥ��-��һ���ƶ�" << endl;
		cout << "8.ͼ�ν�-�Զ��ƶ��汾\n9.ͼ�ν�-��Ϸ�汾\n0.�˳�" << endl;
		cout << "---------------------------------------------------\n[��ѡ��0-9]" << endl;
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
			cout << "�����س�������...";
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