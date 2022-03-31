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

	//Задача 1.
	cout << "Задача 1.\n";
	movies* pf1 = &film1;
	movies* pf2 = &film2;
	movies* pf3 = &film3;
	showMovie(*pf1);
	showMovie(*pf2);
	showMovie(*pf3);
	cout << endl;

	//Задача 2.
	cout << "Задача 2.\nСамый дорогой фильм: " << expensive(*pf1, *pf2, *pf3).title << "\n\n";

	//Задача 3.	
	cout << "Задача 3.\n";
	updateInfo(*pf1);	
	showMovie(*pf1);	

	return 0;
}

//Задача 1.
void showMovie(movies& d) {
	cout << d.title << ", " << d.year << " year, " << d.genre << ", " << d.duration << " minutes, " << d.price << "$. " << endl;
}

//Задача 2.
movies expensive(movies &d1, movies &d2, movies &d3) {
	if (d1.price > d2.price && d1.price > d3.price)
		return  d1;
	if (d2.price > d1.price && d2.price > d3.price)
		return  d2;
	return d3;
}

//Задача 3.
void updateInfo(movies& d) {
	int n;
	cout << "Выберите, какую информацию о фильме хотите обновить:\n";
	cout << "1. Название;" << endl;
	cout << "2. Год выхода;" << endl;
	cout << "3. Жанр;" << endl;
	cout << "4. Продолжительность;" << endl;
	cout << "5. Цена за диск." << endl;
	cout << "Ввод -> ";
	cin >> n;

	switch (n) {
	case 1: cout << "Введите новое название фильма: ";
		cin >> d.title;
		break;
	case 2: cout << "Введите новый год фильма: ";
		cin >> d.year;
		break;
	case 3: cout << "Введите новый жанр фильма: ";
		cin >> d.genre;
		break;
	case 4: cout << "Введите новую продолжительность фильма: ";
		cin >> d.duration;
		break;
	case 5: cout << "Введите новую цену за диск: ";
		cin >> d.price;
		break;
	}
	cout << endl;
}