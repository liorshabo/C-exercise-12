#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

#define B1 -1
#define B2 -2
#define B3 -3
#define G 1
#define SIZE 30


struct date {
	int year;
	int day;
	int month;
};

struct seat {
	int row;
	char place;
};

struct pass
{
	char * name;
	date d;
	seat s;
};

pass* initList(int &len);
int add(pass *B, char *name, date y, seat u, int size, int length);
void cancel(pass *C, char *name, int &size);
void printRow(pass *D, pass x, int size);
void printSeat(pass *E, date D, int size);

int main()
{
	pass*p, pe = { 0 };
	seat se;
	date da;
	char str[SIZE];
	int size = 0, length, option, i = 0;
	p = initList(length);
	do
	{
		cout << "if you want to add person press 2\n";
		cout << "if you want to cancel person press 3\n";
		cout << "if you want to print the  row names  for a person press 4\n";
		cout << "if you want to print seat for date press 5\n";
		cout << "if you want to finish enter 6\n";
		cin >> option;
		switch (option)
		{
		case 2:cout << "enter your name\n";
			cin >> str;
			p[i].name = new char[strlen(str) + 1];
			strcpy(p[i].name, str);
			cout << "enter date(enter day,month,year) with 1 line spacebetwen the arguments\n";
			cin >> da.day >> da.month >> da.year;
			cout << " enter seat you want(char and number)\n";
			cin >> se.row >> se.place;
			switch (add(p, str, da, se, length, size))
			{
			case B1:cout << "the place you are look for  is not availiable\n";
				break;
			case B2:cout << "the same name is valid on the plan\n";
				break;
			case B3:cout << "no places on the plan\n";
				break;
			case G:cout << "the system has add you to the passenger\n" << "have a good flighet\n" << "\n";
				break;
			}
			break;
		case 3: cout << "enter person name\n";
			cin >> str;
			p[i].name = new char[strlen(str) + 1];
			strcpy(p[i].name, str);
			void cancel(pass*a, char *name, int &size);
			cout << "the person has deleted from the system" << "\n";
			break;
		case 4: cout << "enter the name of the person\n";
			cin >> str;
			pe.name = new char[strlen(str) + 1];
			strcpy(pe.name, str);
			cout << "enter date(enter day,month,year)\n";
			cin >> pe.d.day >> pe.d.month >> pe.d.year;
			cout << "please enter seat you want\n";
			cin >> pe.s.row >> pe.s.place;
			void printRow(pass*a, pass x, int size);
			break;
		case 5: cout << "enter the date you want to check(enter day,month,year)\n";
			cin >> da.day >> da.month >> da.year;
			void printSeat(pass*a, date d, int size);
			break;
		case 6:
			cout << "you choose to finish the program";
			for (int i = 0; i < length; i++)
			{
				delete p[i].name;
			}
			for (int i = 0; i < length; i++)
			{
				delete p;
			}
			delete pe.name;

		}

	} while (option != 6);
}


pass* initList(int &len)
{
	pass *p;
	cout << "insert a number of length\n";
	cin >> len;
	p = new pass[len];
	return p;
}

int add(pass *B, char *name, date y, seat u, int size, int length)
{
	if (length == size)
		return B3;
	for (int i = 0; i < size; i++)
	{
		if (B[i].d.day == y.day && B[i].d.month == y.month && B[i].d.year == y.year)
			return B1;
		if (!strcmp(B[i].name, name))
			return B2;
	}
	B[size].d = y;
	B[size].s = u;
	B[size].name = new char[strlen(name) + 1];
	strcpy(B[size].name, name);
	size++;
	return G;
}

void cancel(pass *C, char *name, int &size)
{
	for (int i = 0; i < size; i++)
	{
		if (!strcmp(C[i].name, name))
		{
			delete[] C[i].name;
			for (int j = i + 1; j < size; j++)
				C[i] = C[j];
			size--;
		}
	}
}


void printRow(pass *D, pass x, int size)
{
	for (int i = 0; i < size; i++)
		if (D[i].s.row == x.s.row)
			cout << D[i].name;

}


void printSeat(pass *E, date D, int size)
{
	bool flag = false;
	//int cnt = 0;
	for (int i = 0; i < size; i++)
	{
		if (E[i].d.day == D.day && E[i].d.month == D.month && E[i].d.year == D.year)
		{
			cout << E[i].s.row << E[i].s.place;
			flag = true;
			//cnt++;
		}

	}
	if (!flag)
		//if(!cnt)
		cout << "No orders this date\n";
}

