// Lab.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <Windows.h>
#include <locale.h>

using namespace std;

bool Upper(char a)
{
	char Upper[] = "��������������������������������";
	for (int i = 0; i < strlen(Upper); i++)
	{
		if (a == Upper[i])
		{
			return true;
		}
		else
		{
			continue;
		}
	}
	return false;
}
bool isVowel(char a)
{
	char Vowel[] = "������������������";
	for (int i = 0; i < strlen(Vowel); i++)
	{
		if (a == Vowel[i])
		{
			return true;
		}
		else
		{
			continue;
		}
	}
	return false;
}

bool isNotVowel(char a)
{
	char NotVowel[] = "����������������������������������������������";
	for (int i = 0; i < strlen(NotVowel); i++)
	{
		if (a == NotVowel[i])
		{
			return true;
		}
		else
		{
			continue;
		}
	}
	return false;
}


void readFromFile(string* &a, int &N)
{
	N = 0;
	cout << "������� ��� �����: ";
	string filePath;
	cin >> filePath;
	ifstream file(filePath);
	if (file.is_open())
	{
		string word;
		while (file >> word)
		{
			N++;
			string* c = new string[N];
			for (int i = 0; i != (N - 1); i++)
			{
				c[i] = a[i];
			}
			c[N - 1] = word;
			delete[] a;
			a = c;
		}
		file.close();
		cout << "���� ������" << endl;
	}
	else cout << "���� �� ������!";
	for (int i = 0; i < N; i++)
		cout << a[i] + " ";
	cout << "\n";
}

void sortByVowel(string* &a, int &N)
{
	for (int i = 0; i != N; i++) if (isVowel(tolower(a[i][0]))) cout << a[i] << endl;
}

void sortByNotVowel(string* &a, int &N)
{
	for (int i = 0; i != N; i++) if (isNotVowel(tolower(a[i][0]))) cout << a[i] << endl;
}

void sortByUpper(string* &a, int &N)
{
	for (int i = 0; i != N; i++) {
		if (Upper(a[i][0])) cout << a[i] << endl;
	}
}

void printArray(string* a, int N)
{
	for (int i = 0; i != N; i++) {
		cout << a[i] << endl;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N = 0;
	string* a = NULL;
	while (true) {
		int command;
		cout << "1. �������� ����\n";
		cout << "2. ������� ����� � ��������� �����\n";
		cout << "3. ������� ����� � ������� �����\n";
		cout << "4. ������� ����� � ��������� �����\n";
		cout << "5. �����\n";
		cin >> command;
		if (command == 1)
		{
			readFromFile(a, N);
		}
		else if (command == 2)
		{
			sortByUpper(a, N);
		}
		else if (command == 3)
		{
			sortByVowel(a, N);
		}
		else if (command == 4)
		{
			sortByNotVowel(a, N);
		}
		else if (command == 5)
		{
			break;
		}
	}
	return 0;
}