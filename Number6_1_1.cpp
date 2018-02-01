/*Создать массив из 10 целых чисел.Заполнить массив случайным образом в диапазоне от - 45 до 45.
Пользуясь указателем(и) на массив целых чисел, посчитать процент положительных и отрицательных элементов массива.*/
#include<iostream>
#include<ctime>
#define SIZE 98
using namespace std;

void GenerateArr(int arr[]);
void PrintArr(int arr[]);
float PercentageNeg(int arr[]);
float PercentagePos(int arr[]);

int main (void) {
	setlocale(LC_ALL, "rus");
	int arr[SIZE];
	float percentPos, percentNeg;
	GenerateArr(arr);
	cout << "Случайный массив:" << endl;
	PrintArr(arr);
	percentNeg = PercentageNeg(arr);
	percentPos = PercentagePos(arr);
	printf("Процент отрицательных: %3.1f%%\n", percentNeg);
	printf("Процент положительных: %3.1f%%\n", percentPos);
	cout << endl;
	system("pause");
}

void GenerateArr(int arr[]) {
	int *ptr=arr;
	srand(time(0));
	for (int i = 0; i < SIZE; i++, ptr++)
		*ptr = rand() % 91-45;
}

void PrintArr(int arr[]) {
	int *ptr = arr;
	int counter=0;
	for (int i = 0; i < SIZE; i++, ptr++) {
		printf("a[%2d]=%2d\t", i, *ptr);
		counter++;
		if (counter % 7 == 0)cout << endl;
	}
	cout << endl;
}

float PercentageNeg(int arr[]) {
	float percent;
	int *ptr=arr;
	int i = 0;
	int counter=0;
	while (i < SIZE) {
		if (*ptr < 0) counter++;
		i++;
		ptr++;
	}
	percent = (float)counter / SIZE;
	percent *= 100;
	percent = round(percent * 10) / 10;
	return percent;
}

float PercentagePos(int arr[]) {
	float percent;
	int *ptr = arr;
	int i = 0;
	int counter = 0;
	while (i < SIZE) {
		if (*ptr > 0) counter++;
		i++;
		ptr++;
	}
	percent = (float)counter / SIZE;
	percent *= 100;
	percent = round(percent * 10) / 10;
	return percent;
}
