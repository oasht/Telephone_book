#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include<io.h>
#include<fstream>
#include<string>
#include <MMSystem.h>
#pragma comment (lib, "winmm")
using namespace std;
struct Organization
{
	string Name;
	string Specialization;
	string Street;
	int House_num;
	long long Telephone;


};

struct Individual
{
	string Name;
	string Surname;
	string Street;
	int House_num;
	long long Telephone;
};


void gotoxy(short x, short y);
enum ConsoleColor
{
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue,
	LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
void SetColor(int text, int background = Black);
void print_one_org(Organization* ar);
void write_org(Organization* ar, int* _size);
void read_org();
void print_all_org(Organization* ar, int* _size);
Organization* del_element_org(Organization*& ar, int* _size);
Organization* add_element_org(Organization*& ar, int* _size);
void write_search_org(Organization* ar, int* _size);
void search_org(Organization*& ar, int* _size);
void write_sort_org(Organization* ar, int* _size);
void sort_org(Organization*& ar, int* _size);
void print_one_ind(Individual* ar);
void print_all_ind(Individual* ar, int* _size);
void write_ind(Individual* ar, int* _size);
void read_ind();
Individual* del_element_ind(Individual*& ar, int* _size);
Individual* add_element_ind(Individual*& ar, int* _size);
void write_search_ind(Individual* ar, int* _size);
void search_ind(Individual*& ar, int* _size);
void write_sort_ind(Individual* ar, int* _size);
void sort_ind(Individual*& ar, int* _size);



