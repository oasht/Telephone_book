#include "Header.h"
void main()
{
	int size = 5;
	int* psize = &size;
	int k = 1;
	char en = 0;

	Organization o1 = { "Mercedes", "Cars", "Lenina", 43, 74959865027 };
	Organization o2 = { "Pepsi", "Drinks", "Mira", 34, 74957469365 };
	Organization o3 = { "Moment", "Glue", "Letnyaya", 55, 73912647389 };
	Organization o4 = { "Evian", "Water", "Vzletnaya", 71, 74063487659 };
	Organization o5 = { "Malboro", "Tobacco", "Pobedy", 28, 74567982086 };

	Individual i1 = { "Petr", "Petrov", "Bryanskaya", 7, 79023569865 };
	Individual i2 = { "Ivan", "Ivanov", "Leningradskaya", 4, 79856749836 };
	Individual i3 = { "Olga", "Sidorova", "Kutuzovskaya", 15, 79988779377 };
	Individual i4 = { "Anton", "Suvorov", "Alekseeva", 13, 79670987676 };
	Individual i5 = { "Yulia", "Sinitsina", "Verkhnyaya", 4, 79856749836 };


	Organization* org_ar = new Organization[*psize]{ o1, o2, o3, o4, o5 };
	Individual* ind_ar = new Individual[*psize]{ i1, i2, i3, i4, i5 };



	do
	{
		cout << endl;
		if (en == 80)
		{
			k++;
			if (k == 4)
				k = 1;
		}
		if (en == 72)
		{
			k--;
			if (k == 0)
				k = 3;
		}
		if (en == 13)
		{
			system("cls");
			if (k == 1)
			{
				k = 0;
				do
				{
					cout << endl;
					if (en == 80)
					{
						k++;
						if (k == 9)
							k = 1;
					}
					if (en == 72)
					{
						k--;
						if (k == 0)
							k = 7;
					}
					if (en == 13)
					{
						system("cls");
						if (k == 1)
						{
							print_all_org(org_ar, psize);
							Sleep(6000);
						}
						system("cls");
						if (k == 2)
						{
							write_org(org_ar, psize);

						}

						system("cls");
						if (k == 3)
						{
							read_org();
							Sleep(6000);
						}
						system("cls");
						if (k == 4)
						{
							add_element_org(org_ar, psize);


						}
						system("cls");
						if (k == 5)
						{
							del_element_org(org_ar, psize);


						}
						system("cls");
						if (k == 6)
						{
							sort_org(org_ar, psize);


						}
						system("cls");
						if (k == 7)
						{
							search_org(org_ar, psize);

						}
						system("cls");
						if (k == 8)
						{
							gotoxy(35, 10);
							SetColor(Red, Black);
							cout << "Ciao!!" << endl;

							Sleep(2000);

						}
						system("cls");
					}
					gotoxy(28, 0);
					SetColor(11);
					cout << "Choose action:" << endl << endl;;
					SetColor(7);
					if (k == 1)
						SetColor(13);
					gotoxy(30, 2);
					cout << "1. Print" << endl;
					SetColor(7);

					if (k == 2)
						SetColor(13);
					gotoxy(30, 3);
					cout << "2. Record " << endl;
					SetColor(7);
					if (k == 3)
						SetColor(13);
					gotoxy(30, 4);
					cout << "3. Read " << endl;
					SetColor(7);
					if (k == 4)
						SetColor(13);
					gotoxy(30, 5);
					cout << "4. Add " << endl;
					SetColor(7);
					if (k == 5)
						SetColor(13);
					gotoxy(30, 6);
					cout << "5. Delete " << endl;
					SetColor(7);
					if (k == 6)
						SetColor(13);
					gotoxy(30, 7);
					cout << "6. Sort " << endl;
					SetColor(7);

					if (k == 7)
						SetColor(13);
					gotoxy(30, 8);
					cout << "7. Search" << endl;
					SetColor(7);

					if (k == 8)
						SetColor(13);
					gotoxy(30, 9);
					cout << "8. Exit " << endl;
					SetColor(7);
				} while (en = _getch());
			}
			system("cls");
			if (k == 2)
			{
				k = 0;
				do
				{

					cout << endl;
					if (en == 80)
					{
						k++;
						if (k == 9)
							k = 1;
					}
					if (en == 72)
					{
						k--;
						if (k == 0)
							k = 7;
					}
					if (en == 13)
					{
						system("cls");
						if (k == 1)
						{
							print_all_ind(ind_ar, psize);
							Sleep(6000);
						}
						system("cls");
						if (k == 2)
						{
							write_ind(ind_ar, psize);

						}

						system("cls");
						if (k == 3)
						{
							read_org();
							Sleep(6000);
						}
						system("cls");
						if (k == 4)
						{
							add_element_ind(ind_ar, psize);


						}
						system("cls");
						if (k == 5)
						{
							del_element_ind(ind_ar, psize);


						}
						system("cls");
						if (k == 6)
						{
							sort_ind(ind_ar, psize);


						}
						system("cls");
						if (k == 7)
						{
							search_ind(ind_ar, psize);

						}
						system("cls");
						if (k == 8)
						{
							gotoxy(35, 10);
							SetColor(Red, Black);
							cout << "Ciao!!" << endl;
							Sleep(2000);


						}system("cls");

					}
					gotoxy(28, 0);
					SetColor(11);
					cout << "Choose action:" << endl << endl;;
					SetColor(7);
					if (k == 1)
						SetColor(13);
					gotoxy(30, 2);
					cout << "1. Print" << endl;
					SetColor(7);

					if (k == 2)
						SetColor(13);
					gotoxy(30, 3);
					cout << "2. Record " << endl;
					SetColor(7);
					if (k == 3)
						SetColor(13);
					gotoxy(30, 4);
					cout << "3. Read " << endl;
					SetColor(7);
					if (k == 4)
						SetColor(13);
					gotoxy(30, 5);
					cout << "4. Add " << endl;
					SetColor(7);
					if (k == 5)
						SetColor(13);
					gotoxy(30, 6);
					cout << "5. Delete " << endl;
					SetColor(7);
					if (k == 6)
						SetColor(13);
					gotoxy(30, 7);
					cout << "6. Sort " << endl;
					SetColor(7);

					if (k == 7)
						SetColor(13);
					gotoxy(30, 8);
					cout << "7. Search" << endl;
					SetColor(7);

					if (k == 8)
						SetColor(13);
					gotoxy(30, 9);
					cout << "8. Exit " << endl;
					SetColor(7);
				} while (en = _getch());

			}
			system("cls");
			if (k == 3)
			{
				gotoxy(35, 10);
				SetColor(Red, Black);
				cout << "Ciao!!" << endl;
				SetColor(White, Black);
				Sleep(2000);
				break;

			}
			system("cls");
		}
		gotoxy(15, 0);
		SetColor(11);
		cout << "Make your choice to see the list of contacts" << endl << endl;;
		SetColor(7);
		if (k == 1)
			SetColor(13);
		gotoxy(25, 2);
		cout << "1. Organizations" << endl;
		SetColor(7);

		if (k == 2)
			SetColor(13);
		gotoxy(25, 3);
		cout << "2. Individuals " << endl;
		SetColor(7);
		if (k == 3)
			SetColor(13);
		gotoxy(25, 4);
		cout << "3. Exit " << endl;
		SetColor(7);
	} while (en = _getch());

}
