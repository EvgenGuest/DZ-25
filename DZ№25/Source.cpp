#include<iostream>
#include <string>
using namespace std;

struct movies {
	string title;
	int year;
	string genre;
	int duration;
	int price;
};

void showMovie(movies& d);

movies expensive(movies &d1, movies &d2, movies &d3); 

void updateInfo(movies& d);

int main() {
	setlocale(LC_ALL, "Russian");
		
	movies film1 = { "Mask", 1994, "Comedy", 101, 20 };
	movies film2 = { "Kill Bill", 2003, "Action movie", 111, 9 };
	movies film3 = { "Joker", 2019, "Drama", 122, 30 };

	//������ 1.
	cout << "������ 1.\n";
	movies* pf1 = &film1;
	movies* pf2 = &film2;
	movies* pf3 = &film3;
	showMovie(*pf1);
	showMovie(*pf2);
	showMovie(*pf3);
	cout << endl;

	//������ 2.
	cout << "������ 2.\n����� ������� �����: " << expensive(*pf1, *pf2, *pf3).title << "\n\n";

	//������ 3.	
	cout << "������ 3.\n";
	updateInfo(*pf1);	
	showMovie(*pf1);	

	return 0;
}

//������ 1.
void showMovie(movies& d) {
	cout << d.title << ", " << d.year << " year, " << d.genre << ", " << d.duration << " minutes, " << d.price << "$. " << endl;
}

//������ 2.
movies expensive(movies &d1, movies &d2, movies &d3) {
	if (d1.price > d2.price && d1.price > d3.price)
		return  d1;
	if (d2.price > d1.price && d2.price > d3.price)
		return  d2;
	return d3;
}

//������ 3.
void updateInfo(movies& d) {
	int n;
	cout << "��������, ����� ���������� � ������ ������ ��������:\n";
	cout << "1. ��������;" << endl;
	cout << "2. ��� ������;" << endl;
	cout << "3. ����;" << endl;
	cout << "4. �����������������;" << endl;
	cout << "5. ���� �� ����." << endl;
	cout << "���� -> ";
	cin >> n;

	switch (n) {
	case 1: cout << "������� ����� �������� ������: ";
		cin >> d.title;
		break;
	case 2: cout << "������� ����� ��� ������: ";
		cin >> d.year;
		break;
	case 3: cout << "������� ����� ���� ������: ";
		cin >> d.genre;
		break;
	case 4: cout << "������� ����� ����������������� ������: ";
		cin >> d.duration;
		break;
	case 5: cout << "������� ����� ���� �� ����: ";
		cin >> d.price;
		break;
	}
	cout << endl;
}