#include "Header.h"


void gotoxy(short x, short y)
{
	COORD coord = { x, y };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, coord);
}



void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void print_one_org(Organization* ar)
{

	cout << ar->Name << " " << ar->Specialization << " " << ar->Street << " " << ar->House_num << " " << ar->Telephone << endl;

}
void write_org(Organization* ar, int* _size)
{

	ofstream fout;
	fout.open("Org_tel_book.txt", ofstream::out);
	if (!fout.is_open())
	{
		cout << "Error!" << endl;
	}
	else
	{
		for (int i = 0; i < *_size; i++)
		{
			fout.write((char*)&ar[i], sizeof(Organization));
		}
	}
	fout.close();
	cout << "End of write" << endl;
	system("Org_tel_book.txt");
}

void read_org()
{
	int size = 100;
	Organization* ar = new Organization[size];
	ifstream fin;
	fin.open("Org_tel_book.txt");
	if (!fin.is_open())
	{
		cout << "Error" << endl;
	}
	else
	{
		cout << "File open" << endl << endl;
		int i = 0;

		while (fin.read((char*)&ar[i], sizeof(Organization)))
		{
			cout << setw(3) << i + 1 << ")"; print_one_org(&ar[i]);
			i++;
		}
	}
	fin.close();
	cout << endl << "End read" << endl;
}


void print_all_org(Organization* ar, int* _size)
{
	SetColor(LightMagenta, Black);
	cout << "Number       Name     Specialization     Street     House number      Telephone" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	SetColor(White, Black);
	for (int i = 0; i < *_size; ++i)
	{

		cout << i + 1 << setw(16) << ar[i].Name << setw(15) << ar[i].Specialization << setw(15) << ar[i].Street << setw(12) << ar[i].House_num << setw(20) << ar[i].Telephone << endl;

	} cout << endl << endl;

}
Organization* del_element_org(Organization*& ar, int* _size)
{
	int num;
	bool key = 1;
	do
	{
		system("cls");
		print_all_org(ar, _size);
		cout << "Choose the number of organisation you want to delete " << endl;
		cin >> num;
		cout << endl;
		if (num - 1 <= *_size && num - 1 >= 0)
		{
			Organization* tmp = new Organization[*_size - 1];
			for (unsigned short i = 0; i < num - 1; ++i)
			{
				tmp[i] = ar[i];
			}
			for (unsigned short i = num - 1; i < *_size - 1; ++i)
			{
				tmp[i] = ar[i + 1];

			}
			delete[]ar;
			ar = tmp;
			*_size -= 1;

			for (int i = 0; i < *_size; ++i)
			{
				cout << tmp[i].Name << endl;

			} cout << '\n';

			cout << "Delete one more? 1 - yes, 0 - no" << endl;
			cin >> key;

		}
		else
		{
			cout << "Error\n";

			cout << "Try again? 1 - yes, 0 - no" << endl;
			cin >> key;
		}
	} while (key);
	return ar;
}
Organization* add_element_org(Organization*& ar, int* _size)
{

	bool key = 1;
	do
	{
		system("cls");
		print_all_org(ar, _size);


		Organization* tmp = new Organization[*_size + 1];

		for (unsigned short i = 0; i < *_size + 1; ++i)
		{
			if (i < *_size)
			{
				tmp[i] = ar[i];
			}
			else
			{
				cout << "Name" << endl;
				cin >> tmp[i].Name;
				cout << "Specialization" << endl;
				cin >> tmp[i].Specialization;
				cout << "Street" << endl;
				cin >> tmp[i].Street;
				cout << "House_num" << endl;
				cin >> tmp[i].House_num;
				cout << "Telephone" << endl;
				cin >> tmp[i].Telephone;
			}
		}

		delete[]ar;
		ar = tmp;
		*_size += 1;

		cout << endl << endl;
		print_all_org(ar, _size);

		cout << "Add one more? 1 - yes, 0 - no" << endl;
		cin >> key;
	} while (key);
	return ar;
}
void write_search_org(Organization* ar, int* _size)
{
	string path = "Org_tel_book_search_sort.txt";
	fstream fs;
	fs.open(path, fstream::out | fstream::app);
	if (!fs.is_open())
	{
		cout << "Error!" << endl;
	}
	else
	{

		cout << "File is open!" << endl << endl;
		fs << ar->Name << " " << ar->Specialization << " " << ar->Street << " " << ar->House_num << " " << ar->Telephone << endl;


		fs.close();
		cout << "End of write" << endl;
		system("Org_tel_book_search_sort.txt");
	}

}
void search_org(Organization*& ar, int* _size)
{
	string str;
	string* pstr = &str;
	long long num;
	long long* pnum = &num;
	int n = 0;
	bool key_1;
	do
	{
		//system("cls");

		cout << " What do you want to search?\n\n1 - Name; 2 - Specialization; 3 - Street; 4 - House number; 5 - Telephone" << endl;
		short key;
		cout << endl;
		cin >> key;
		cout << endl;

		switch (key)
		{
		case 1:
		{
			system("cls");
			cout << "Enter Name" << endl;
			cin >> *pstr;
			for (int i = 0; i < *_size; i++)
			{
				if (ar[i].Name == *pstr)
				{
					cout << endl;
					SetColor(LightMagenta, Black);
					cout << "Such organization exists:" << endl << endl;
					SetColor(White, Black);
					print_one_org(&ar[i]);
					cout << endl;
					cout << "Want to add the result to the file? 1 - yes, 2 - no" << endl << endl;
					int key;
					cin >> key;
					switch (key)
					{
					case 1:
					{
						write_search_org(&ar[i], _size);
					}
					break;
					case 2:
					{
						continue;
					}

					break;
					}
				}
				else
					n++;
			}if (n == *_size)
				cout << "No organization like this exists" << endl;

		}
		break;

		case 2:
		{
			system("cls");
			cout << "Enter Specialization" << endl;
			cin >> *pstr;
			for (int i = 0; i < *_size; i++)
			{
				if (ar[i].Specialization == *pstr)
				{
					cout << endl;
					SetColor(LightMagenta, Black);
					cout << "Such organization exists:" << endl << endl;
					SetColor(White, Black);
					print_one_org(&ar[i]);
					cout << endl;
					cout << "Want to add the result to the file? 1 - yes, 2 - no" << endl << endl;
					int key;
					cin >> key;
					switch (key)
					{
					case 1:
					{
						write_search_org(&ar[i], _size);
					}
					break;
					case 2:
					{
						continue;
					}

					break;
					}
				}
				else
					n++;
			}if (n == *_size)
				cout << "No organization like this exists" << endl;
		}
		break;

		case 3:
		{
			system("cls");
			cout << "Enter Street" << endl;
			cin >> *pstr;
			for (int i = 0; i < *_size; i++)
			{
				if (ar[i].Street == *pstr)
				{
					cout << endl;
					SetColor(LightMagenta, Black);
					cout << "Such organization exists:" << endl << endl;
					SetColor(White, Black);
					print_one_org(&ar[i]);
					cout << endl;
					cout << "Want to add the result to the file? 1 - yes, 2 - no" << endl << endl;
					int key;
					cin >> key;
					switch (key)
					{
					case 1:
					{
						write_search_org(&ar[i], _size);
					}
					break;
					case 2:
					{
						continue;
					}

					break;
					}
				}
				else
					n++;
			}if (n == *_size)
				cout << "No organization like this exists" << endl;
		}
		break;

		case 4:
		{
			system("cls");
			cout << "House number" << endl;
			cin >> *pnum;
			for (int i = 0; i < *_size; i++)
			{
				if (ar[i].House_num == *pnum)
				{
					cout << endl;
					SetColor(LightMagenta, Black);
					cout << "Such organization exists:" << endl << endl;
					SetColor(White, Black);
					print_one_org(&ar[i]);
					cout << endl;
					cout << "Want to add the result to the file? 1 - yes, 2 - no" << endl << endl;
					int key;
					cin >> key;
					switch (key)
					{
					case 1:
					{
						write_search_org(&ar[i], _size);
					}
					break;
					case 2:
					{
						continue;
					}

					break;
					}
				}
				else
					n++;
			}if (n == *_size)
				cout << "No organization like this exists" << endl;
		}
		break;

		case 5:
		{
			system("cls");
			cout << "Telephone" << endl;
			cin >> *pnum;
			for (int i = 0; i < *_size; i++)
			{
				if (ar[i].Telephone == *pnum)
				{
					cout << endl;
					SetColor(LightMagenta, Black);
					cout << "Such organization exists:" << endl << endl;
					SetColor(White, Black);
					print_one_org(&ar[i]);
					cout << endl;
					cout << "Want to add the result to the file? 1 - yes, 2 - no" << endl << endl;
					int key;
					cin >> key;
					switch (key)
					{
					case 1:
					{
						write_search_org(&ar[i], _size);
					}
					break;
					case 2:
					{
						continue;
					}

					break;
					}
				}
				else
					n++;
			}if (n == *_size)
				cout << "No organization like this exists" << endl;
		}
		break;
		}

		cout << "  " << endl;
		cout << "Continue? 1 - yes, 0 - no" << endl;
		cout << endl;
		cin >> key_1;
		system("cls");
	} while (key_1);
}
void write_sort_org(Organization* ar, int* _size)
{
	string path = "Org_tel_book_search_sort.txt";
	fstream fs;
	fs.open(path, fstream::out | fstream::app);
	if (!fs.is_open())
	{
		cout << "Error!" << endl;
	}
	else
	{
		cout << "File is open!" << endl << endl;
		for (int i = 0; i < *_size; ++i)
		{

			fs << i + 1 << setw(16) << ar[i].Name << setw(15) << ar[i].Specialization << setw(15) << ar[i].Street << setw(12) << ar[i].House_num << setw(20) << ar[i].Telephone << endl;

		} cout << endl << endl;


		fs.close();
		cout << "End of write" << endl;
		system("Org_tel_book_search_sort.txt");
	}

}
void sort_org(Organization*& ar, int* _size)
{
	bool key_1;
	do
	{
		cout << " Which parameter would you like to sort?\n\n1 - Name; 2 - Specialization; 3 - Street; 4 - House number; 5 - Telephone" << endl;
		short key;
		cout << endl;
		cin >> key;
		cout << endl;

		switch (key)
		{
		case 1:
		{
			system("cls");
			for (int i = 0; i < *_size; i++)
				for (int j = i + 1; j < *_size; j++)
					if (ar[j].Name < ar[i].Name)
						swap(ar[j], ar[i]);
			SetColor(Red, Black);
			cout << setw(40) << "SORTED" << endl << endl << endl;
			SetColor(White, Black);
			print_all_org(ar, _size);
			cout << endl;
			cout << "Want to add the result to the file? 1 - yes, 2 - no" << endl << endl;
			int key;
			cin >> key;
			switch (key)
			{
			case 1:
			{
				write_sort_org(ar, _size);
			}
			break;
			case 2:
			{
				continue;
			}

			break;
			}
		}
		break;

		case 2:
		{
			system("cls");
			for (int i = 0; i < *_size; i++)
				for (int j = i + 1; j < *_size; j++)
					if (ar[j].Specialization < ar[i].Specialization)
						swap(ar[j], ar[i]);
			SetColor(Red, Black);
			cout << setw(40) << "SORTED" << endl << endl << endl;
			SetColor(White, Black);
			print_all_org(ar, _size);
			cout << endl;
			cout << "Want to add the result to the file? 1 - yes, 2 - no" << endl << endl;
			int key;
			cin >> key;
			switch (key)
			{
			case 1:
			{
				write_sort_org(ar, _size);
			}
			break;
			case 2:
			{
				continue;
			}

			break;
			}
		}
		break;

		case 3:
		{
			system("cls");
			for (int i = 0; i < *_size; i++)
				for (int j = i + 1; j < *_size; j++)
					if (ar[j].Street < ar[i].Street)
						swap(ar[j], ar[i]);
			SetColor(Red, Black);
			cout << setw(40) << "SORTED" << endl << endl << endl;
			SetColor(White, Black);
			print_all_org(ar, _size);
			cout << endl;
			cout << "Want to add the result to the file? 1 - yes, 2 - no" << endl << endl;
			int key;
			cin >> key;
			switch (key)
			{
			case 1:
			{
				write_sort_org(ar, _size);
			}
			break;
			case 2:
			{
				continue;
			}

			break;
			}
		}
		break;

		case 4:
		{
			system("cls");
			for (int i = 0; i < *_size; i++)
				for (int j = i + 1; j < *_size; j++)
					if (ar[j].House_num < ar[i].House_num)
						swap(ar[j], ar[i]);
			SetColor(Red, Black);
			cout << setw(40) << "SORTED" << endl << endl << endl;
			SetColor(White, Black);
			print_all_org(ar, _size);
			cout << endl;
			cout << "Want to add the result to the file? 1 - yes, 2 - no" << endl << endl;
			int key;
			cin >> key;
			switch (key)
			{
			case 1:
			{
				write_sort_org(ar, _size);
			}
			break;
			case 2:
			{
				continue;
			}

			break;
			}
		}
		break;

		case 5:
		{
			system("cls");
			for (int i = 0; i < *_size; i++)
				for (int j = i + 1; j < *_size; j++)
					if (ar[j].Telephone < ar[i].Telephone)
						swap(ar[j], ar[i]);
			SetColor(Red, Black);
			cout << setw(40) << "SORTED" << endl << endl << endl;
			SetColor(White, Black);
			print_all_org(ar, _size);
			cout << endl;
			cout << "Want to add the result to the file? 1 - yes, 2 - no" << endl << endl;
			int key;
			cin >> key;
			switch (key)
			{
			case 1:
			{
				write_sort_org(ar, _size);
			}
			break;
			case 2:
			{
				continue;
			}

			break;
			}
		}
		break;
		}

		cout << "  " << endl;
		cout << "Continue? 1 - yes, 0 - no" << endl;
		cout << endl;
		cin >> key_1;
		system("cls");
	} while (key_1);

}



//INDIVIDIALS!!!



void print_one_ind(Individual* ar)
{

	cout << ar->Name << " " << ar->Surname << " " << ar->Street << " " << ar->House_num << " " << ar->Telephone << endl;
}
void print_all_ind(Individual* ar, int* _size)
{
	SetColor(LightMagenta, Black);
	cout << "Number       Name       Surname          Street     House number      Telephone" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	SetColor(White, Black);
	for (int i = 0; i < *_size; ++i)
	{

		cout << i + 1 << setw(16) << ar[i].Name << setw(15) << ar[i].Surname << setw(15) << ar[i].Street << setw(12) << ar[i].House_num << setw(20) << ar[i].Telephone << endl;

	} cout << endl << endl;
}
void write_ind(Individual* ar, int* _size)
{

	ofstream fout;
	fout.open("Ind_tel_book.txt", ofstream::out);
	if (!fout.is_open())
	{
		cout << "Error!" << endl;
	}
	else
	{
		for (int i = 0; i < *_size; i++)
		{
			fout.write((char*)&ar[i], sizeof(Individual));
		}
	}
	fout.close();
	cout << "End of write" << endl;
	system("Ind_tel_book.txt");
}

void read_ind()
{
	int size = 100;
	Individual* ar = new Individual[size];
	ifstream fin;
	fin.open("Ind_tel_book.txt");
	if (!fin.is_open())
	{
		cout << "Error" << endl;
	}
	else
	{
		cout << "File open" << endl << endl;
		int i = 0;

		while (fin.read((char*)&ar[i], sizeof(Individual)))
		{
			cout << setw(3) << i + 1 << ")"; print_one_ind(&ar[i]);
			i++;
		}
	}
	fin.close();
	cout << endl << "End read" << endl;
}


Individual* del_element_ind(Individual*& ar, int* _size)
{
	int num;
	bool key = 1;
	do
	{
		print_all_ind(ar, _size);
		cout << "Choose the number of individual you want to delete " << endl;
		cin >> num;
		cout << endl;
		if (num - 1 <= *_size && num - 1 >= 0)
		{
			Individual* tmp = new Individual[*_size - 1];
			for (unsigned short i = 0; i < num - 1; ++i)
			{
				tmp[i] = ar[i];
			}
			for (unsigned short i = num - 1; i < *_size - 1; ++i)
			{
				tmp[i] = ar[i + 1];

			}
			delete[]ar;
			ar = tmp;
			*_size -= 1;

			for (int i = 0; i < *_size; ++i)
			{
				cout << tmp[i].Name << endl;

			} cout << '\n';

			cout << "Delete one more? 1 - yes, 0 - no" << endl;
			cin >> key;

		}
		else
		{
			cout << "Error\n";

			cout << "Try again? 1 - yes, 0 - no" << endl;
			cin >> key;
		}
	} while (key);
	return ar;
}
Individual* add_element_ind(Individual*& ar, int* _size)
{

	bool key = 1;
	do
	{
		system("cls");
		print_all_ind(ar, _size);

		Individual* tmp = new Individual[*_size + 1];

		for (unsigned short i = 0; i < *_size + 1; ++i)
		{
			if (i < *_size)
			{
				tmp[i] = ar[i];
			}
			else
			{
				cout << "Name" << endl;
				cin >> tmp[i].Name;
				cout << "Specialization" << endl;
				cin >> tmp[i].Surname;
				cout << "Street" << endl;
				cin >> tmp[i].Street;
				cout << "House_num" << endl;
				cin >> tmp[i].House_num;
				cout << "Telephone" << endl;
				cin >> tmp[i].Telephone;
			}
		}

		delete[]ar;
		ar = tmp;
		*_size += 1;

		cout << endl << endl;
		for (int i = 0; i < *_size; ++i)
		{
			cout << tmp[i].Name << endl;

		} cout << '\n';

		cout << "Add one more? 1 - yes, 0 - no" << endl;
		cin >> key;
	} while (key);
	return ar;
}


void write_search_ind(Individual* ar, int* _size)
{
	string path = "Ind_tel_book_search_sort.txt";
	fstream fs;
	fs.open(path, fstream::out | fstream::app);
	if (!fs.is_open())
	{
		cout << "Error!" << endl;
	}
	else
	{

		cout << "File is open!" << endl << endl;
		fs << ar->Name << " " << ar->Surname << " " << ar->Street << " " << ar->House_num << " " << ar->Telephone << endl;


		fs.close();
		cout << "End of write" << endl;
		system("Ind_tel_book_search_sort.txt");
	}
}


void search_ind(Individual*& ar, int* _size)
{
	string str;
	string* pstr = &str;
	long long num;
	long long* pnum = &num;
	int n = 0;
	bool key_1;
	do
	{


		cout << " What do you want to search?\n\n1 - Name; 2 - Surname; 3 - Street; 4 - House number; 5 - Telephone" << endl;
		short key;
		cout << endl;
		cin >> key;
		cout << endl;

		switch (key)
		{
		case 1:
		{
			system("cls");
			cout << "Enter Name" << endl;
			cin >> *pstr;
			for (int i = 0; i < *_size; i++)
			{
				if (ar[i].Name == *pstr)
				{
					cout << endl;
					SetColor(LightMagenta, Black);
					cout << "Such an individual exists:" << endl << endl;
					SetColor(White, Black);
					print_one_ind(&ar[i]);
					cout << endl;
					cout << "Want to add the result to the file? 1 - yes, 2 - no" << endl << endl;
					int key;
					cin >> key;
					switch (key)
					{
					case 1:
					{
						write_search_ind(&ar[i], _size);
					}
					break;
					case 2:
					{
						continue;
					}

					break;
					}

				}
				else
					n++;
			}if (n == *_size)
				cout << "No individual like this exists" << endl;
		}
		break;

		case 2:
		{
			system("cls");
			cout << "Enter Specialization" << endl;
			cin >> *pstr;
			for (int i = 0; i < *_size; i++)
			{
				if (ar[i].Surname == *pstr)
				{
					SetColor(LightMagenta, Black);
					cout << "Such an individual exists:" << endl << endl;
					SetColor(White, Black);
					print_one_ind(&ar[i]);
					cout << endl;
					cout << "Want to add the result to the file? 1 - yes, 2 - no" << endl << endl;
					int key;
					cin >> key;
					switch (key)
					{
					case 1:
					{
						write_search_ind(&ar[i], _size);
					}
					break;
					case 2:
					{
						continue;
					}

					break;
					}
				}
				else
					n++;
			}if (n == *_size)
				cout << "No individual like this exists" << endl;
		}
		break;

		case 3:
		{
			system("cls");
			cout << "Enter Street" << endl;
			cin >> *pstr;
			for (int i = 0; i < *_size; i++)
			{
				if (ar[i].Street == *pstr)
				{
					SetColor(LightMagenta, Black);
					cout << "Such an individual exists:" << endl << endl;
					SetColor(White, Black);
					print_one_ind(&ar[i]);
					cout << endl;
					cout << "Want to add the result to the file? 1 - yes, 2 - no" << endl << endl;
					int key;
					cin >> key;
					switch (key)
					{
					case 1:
					{
						write_search_ind(&ar[i], _size);
					}
					break;
					case 2:
					{
						continue;
					}

					break;
					}
				}
				else
					n++;
			}if (n == *_size)
				cout << "No individual like this exists" << endl;
		}
		break;

		case 4:
		{
			system("cls");
			cout << "House number" << endl;
			cin >> *pnum;
			for (int i = 0; i < *_size; i++)
			{
				if (ar[i].House_num == *pnum)
				{
					SetColor(LightMagenta, Black);
					cout << "Such an individual exists:" << endl << endl;
					SetColor(White, Black);
					print_one_ind(&ar[i]);
					cout << endl;
					cout << "Want to add the result to the file? 1 - yes, 2 - no" << endl << endl;
					int key;
					cin >> key;
					switch (key)
					{
					case 1:
					{
						write_search_ind(&ar[i], _size);
					}
					break;
					case 2:
					{
						continue;
					}

					break;
					}
				}
				else
					n++;
			}if (n == *_size)
				cout << "No individual like this exists" << endl;
		}
		break;

		case 5:
		{
			system("cls");
			cout << "Telephone" << endl;
			cin >> *pnum;
			for (int i = 0; i < *_size; i++)
			{
				if (ar[i].Telephone == *pnum)
				{
					SetColor(LightMagenta, Black);
					cout << "Such an individual exists:" << endl << endl;
					SetColor(White, Black);
					print_one_ind(&ar[i]);
					cout << endl;
					cout << "Want to add the result to the file? 1 - yes, 2 - no" << endl << endl;
					int key;
					cin >> key;
					switch (key)
					{
					case 1:
					{
						write_search_ind(&ar[i], _size);
					}
					break;
					case 2:
					{
						continue;
					}

					break;
					}
				}
				else
					n++;
			}if (n == *_size)
				cout << "No individual like this exists" << endl;
		}
		break;
		}

		cout << "  " << endl;
		cout << "Continue? 1 - yes, 0 - no" << endl;
		cout << endl;
		cin >> key_1;
		system("cls");
	} while (key_1);
}


void write_sort_ind(Individual* ar, int* _size)
{
	string path = "Ind_tel_book_search_sort.txt";
	fstream fs;
	fs.open(path, fstream::out | fstream::app);
	if (!fs.is_open())
	{
		cout << "Error!" << endl;
	}
	else
	{
		cout << "File is open!" << endl << endl;
		for (int i = 0; i < *_size; ++i)
		{

			fs << i + 1 << setw(16) << ar[i].Name << setw(15) << ar[i].Surname << setw(15) << ar[i].Street << setw(12) << ar[i].House_num << setw(20) << ar[i].Telephone << endl;

		} cout << endl << endl;


		fs.close();
		cout << "End of write" << endl;
		system("Ind_tel_book_search_sort.txt");
	}

}



void sort_ind(Individual*& ar, int* _size)
{
	bool key_1;
	do
	{
		cout << " Which parameter would you like to sort?\n\n1 - Name; 2 - Surname; 3 - Street; 4 - House number; 5 - Telephone" << endl;
		short key;
		cout << endl;
		cin >> key;
		cout << endl;

		switch (key)
		{

		case 1:
		{system("cls");
		for (int i = 0; i < *_size; i++)
			for (int j = i + 1; j < *_size; j++)
				if (ar[j].Name < ar[i].Name)
					swap(ar[j], ar[i]);
		SetColor(Red, Black);
		cout << setw(40) << "SORTED" << endl << endl << endl;
		SetColor(White, Black);
		print_all_ind(ar, _size);
		cout << endl;
		cout << "Want to add the result to the file? 1 - yes, 2 - no" << endl << endl;
		int key;
		cin >> key;
		switch (key)
		{
		case 1:
		{
			write_sort_ind(ar, _size);
		}
		break;
		case 2:
		{
			continue;
		}

		break;
		}
		}
		break;

		case 2:
		{system("cls");
		for (int i = 0; i < *_size; i++)
			for (int j = i + 1; j < *_size; j++)
				if (ar[j].Surname < ar[i].Surname)
					swap(ar[j], ar[i]);
		SetColor(Red, Black);
		cout << setw(40) << "SORTED" << endl << endl << endl;
		SetColor(White, Black);
		print_all_ind(ar, _size);
		cout << endl;
		cout << "Want to add the result to the file? 1 - yes, 2 - no" << endl << endl;
		int key;
		cin >> key;
		switch (key)
		{
		case 1:
		{
			write_sort_ind(ar, _size);
		}
		break;
		case 2:
		{
			continue;
		}

		break;
		}
		}
		break;

		case 3:
		{system("cls");
		for (int i = 0; i < *_size; i++)
			for (int j = i + 1; j < *_size; j++)
				if (ar[j].Street < ar[i].Street)
					swap(ar[j], ar[i]);
		SetColor(Red, Black);
		cout << setw(40) << "SORTED" << endl << endl << endl;
		SetColor(White, Black);
		print_all_ind(ar, _size);
		cout << endl;
		cout << "Want to add the result to the file? 1 - yes, 2 - no" << endl << endl;
		int key;
		cin >> key;
		switch (key)
		{
		case 1:
		{
			write_sort_ind(ar, _size);
		}
		break;
		case 2:
		{
			continue;
		}

		break;
		}
		}
		break;

		case 4:
		{system("cls");
		for (int i = 0; i < *_size; i++)
			for (int j = i + 1; j < *_size; j++)
				if (ar[j].House_num < ar[i].House_num)
					swap(ar[j], ar[i]);
		SetColor(Red, Black);
		cout << setw(40) << "SORTED" << endl << endl << endl;
		SetColor(White, Black);
		print_all_ind(ar, _size);
		cout << endl;
		cout << "Want to add the result to the file? 1 - yes, 2 - no" << endl << endl;
		int key;
		cin >> key;
		switch (key)
		{
		case 1:
		{
			write_sort_ind(ar, _size);
		}
		break;
		case 2:
		{
			continue;
		}

		break;
		}
		}
		break;

		case 5:
		{system("cls");
		for (int i = 0; i < *_size; i++)
			for (int j = i + 1; j < *_size; j++)
				if (ar[j].Telephone < ar[i].Telephone)
					swap(ar[j], ar[i]);
		SetColor(Red, Black);
		cout << setw(40) << "SORTED" << endl << endl << endl;
		SetColor(White, Black);
		print_all_ind(ar, _size);
		cout << endl;
		cout << "Want to add the result to the file? 1 - yes, 2 - no" << endl << endl;
		int key;
		cin >> key;
		switch (key)
		{
		case 1:
		{
			write_sort_ind(ar, _size);
		}
		break;
		case 2:
		{
			continue;
		}

		break;
		}
		}
		break;
		}

		cout << "  " << endl;
		cout << "Continue? 1 - yes, 0 - no" << endl;
		cout << endl;
		cin >> key_1;
		system("cls");
	} while (key_1);
}
