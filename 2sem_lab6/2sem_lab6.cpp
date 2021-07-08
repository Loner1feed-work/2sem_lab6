#include <fstream>
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <string>
using namespace std;


struct Student {
	string name;
	int groupNumber;
	int grades[3];
	int stypendy;
};
void task1Med() {

	cout << "Задание 1 средний уровень" << endl;


	Student students[3], outer;

	//заполнение массива структур
	for (int i = 0; i < 3; i++) {
		students[i].name = "name_" + to_string(i+1);
		students[i].groupNumber = i + 1;
		for (int j = 0; j < 3; j++) {
			students[i].grades[j] = rand() / 1000 + 1;
		}
		students[i].stypendy = rand() / 10;
	}

	ofstream file("../task1Med.bin", ios::binary | ios::out);
	ifstream file2("../task1Med.bin", ios::binary | ios::out);

	int y = 10;

	int x;

	//file.write((char*)&students[1].name, sizeof students[1].name);
	for (int i = 0; i < 3; i++) {
		file.write((char*)&students[i], sizeof students[i]);
	}
	file.close();

	//Вывод данных о студентах с положительными оценками (большк 10 баллов)
	for (int i = 0; i < 3; i++) {
		bool goodGrade = true;

		for (int j = 0; j < 3; j++) {
			if (students[i].grades[j] > 10) {
				goodGrade = true;
			}
			else {
				goodGrade = false;
			}
		}

		if (goodGrade) {
			//students[i].name = "name_" + to_string(i + 1);
			cout << students[i].name << endl;
			students[i].groupNumber = i + 1;
			cout << students[i].groupNumber << endl;
			for (int j = 0; j < 3; j++) {
				//students[i].grades[j] = rand() / 1000 + 1;
				cout << students[i].grades[j] << endl;
			}
			//students[i].stypendy = rand() / 10;
			cout << students[i].stypendy << endl;
			cout << endl;
		}
	}


	
}


struct Item {
	string name;
	int price;
	int amount;
};
void task2Med() {

	cout << "Задание 2 средний уровень" << endl;


	Item goods[3];

	//заполнение массива структур
	for (int i = 0; i < 3; i++) {
		goods[i].name = "name_" + to_string(i + 1);
		goods[i].price = rand();
		goods[i].amount = rand() / 100;
	}

	ofstream file("../task2Med.bin", ios::binary | ios::out);
	for (int i = 0; i < 3; i++) {
		file.write((char*)&goods[i], sizeof goods[i]);
	}

	int allSumPrice = 0;
	int avg = 0;

	for (int i = 0; i < 3; i++) {
		allSumPrice += goods[i].price * goods[i].amount;
		avg += goods[i].price;
	}

	avg /= 3;

	cout << "all summ: " << allSumPrice << endl;
	cout << "average price: " << avg << endl;
}


struct Item2 {
	string name;
	int price;
	string unit;
};
void task3Med() {

	cout << "Задание 3 средний уровень" << endl;


	Item2 items[3];
	int max;

	ofstream file("../task3Med.bin", ios::binary);

	//Заполнение массива структур
	for (int i = 0; i < 3; i++)
	{
		items[i].name = "name_" + to_string(i + 1);
		items[i].price = rand();
		items[i].unit = "unit_" + to_string(i + 1);
	}

	for (int i = 0; i < 3; i++)
	{
		file.write((char*)&items[i], sizeof items[i]);
	}

	max = items[0].price;
	for (int i = 0; i < 3; i++)
	{
		if (max < items[i].price) {
			max = items[i].price;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (max == items[i].price) {
			cout << "name: " << items[i].name << endl;
			cout << "price: " << items[i].price << endl;
			cout << "unit: " << items[i].unit << endl;
		}
	}

}


int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	task1Med();
	task2Med();
	cout << endl;
	task3Med();
}
