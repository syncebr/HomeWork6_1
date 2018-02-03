/*Сформировать двумерный массив из 4 строк и 5 столбцов,
заполнив его случайными числами от -10 до 10. Распечатать исходный массив. 
Затем заполнить все четные строки нулями и опять распечатать преобразованный массив. 
Использовать указатели!*/

#include<iostream>
#include<ctime>
#define ROW 4
#define COL 5
using namespace std;

void GenerateArr(int arr[]);
void PrintArr(int arr[]);

int main(void) {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int arr[ROW][COL];
	GenerateArr(arr[0]);
	cout << "Ваш массив" << endl;
	PrintArr(arr[0]);
	int *ptr;
	ptr = arr[1];
	while (ptr < arr[0] + ROW*COL) {
		int counter = 0;
		while (counter < COL) {
			*ptr = 0;
			counter++;
			ptr++;
		}
		ptr +=COL;
	}
	cout << endl << "Новый массив:" << endl;
	PrintArr(arr[0]);
	system("pause");
}

void GenerateArr(int arr[]) {
	int *ptr = arr;
	for (int i = 0; i <ROW*COL; i++, ptr++)
		*ptr = rand() % 21-10;
}

void PrintArr(int arr[]) {
	int *ptr = arr;
	int counter = 0;
	for (int i = 0; i < ROW*COL; i++, ptr++) {
		printf("%2d\t", *ptr);
		counter++;
		if (counter % COL == 0)cout << endl;
	}
	cout << endl;
}
