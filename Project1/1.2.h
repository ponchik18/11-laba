//1.2.h   ���������� � ������������ � ���������� ��������� + ����������� ��������� �������
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<locale>
#define CLEAN system("cls"); // �������� �������
#define ClEANCONSOLE cin.clear(); cin.ignore(32767, '\n');
#define PAUSE system("pause");
using namespace std;

template<typename T>
T getValue(T& b)
{
	while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
	{
		cin >> b;

		if (cin.fail()) // ���� ���������� ���������� ��������� ���������,
		{
			cin.clear(); // �� ���������� cin � '�������' ����� ������
			cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
			cout << endl << "������, ���������� ��� ���: ";
		}
		else // ���� �� ������, �� ���������� a
			return b;
	}
}
extern void DeleteInfoAboutStedent();
extern void PrintInfoAboutStudent();
extern void CinInfoAboutStudent();
extern void menu();
extern void InfoAboutBestStudent();
extern void SortStudent();