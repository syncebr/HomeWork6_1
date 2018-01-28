/*
 * number1.cpp
 * Дан массив целых чисел (можно ввести значения элементов или задать случайным образом).
 * Воспользовавшись указателями, поменяйте местами элементы массива с четными и нечетными индексами
 * (т.е. те элементы массива, которые стоят на четных местах, поменяйте с элементами,
 * которые стоят на нечетных местах).
 */
#include<iostream>
#include<stdlib.h>
using namespace std;

void GenerateArr(int arr[],int size);
void PrintArr(int arr[],int size);
void SwapNumbers(int arr[],int size);

int main(void){
	const int SIZE=14;
	int arr[SIZE]={};
	GenerateArr(arr,SIZE);
	cout<<"Случайный массив:"<<endl;
	PrintArr(arr,SIZE);
	SwapNumbers(arr,SIZE);
	cout<<"Измененный массив:"<<endl;
	PrintArr(arr,SIZE);
	return 0;
}

void GenerateArr(int arr[],int size){
	//заполнение массива
	srand(time(0));
	int *ptr;
	ptr=arr;
		for (int i=0;i<size;i++,ptr++){
			*ptr=rand()%16;
		}
}
void PrintArr(int arr[],int size){
	int *ptr;
	ptr=arr;
		for (int i=0;i<size;i++,ptr++){
			cout<<*ptr<<"\t";
		}
	cout<<endl;
}

void SwapNumbers(int arr[],int size){
	if (size^1) size--;
	//меняем местами четные и нечетные
	int *swapPtr;
	swapPtr=arr;
	for (int i=0;i<size;i+=2,swapPtr+=2){
			int tmp=*swapPtr;
			*swapPtr=*(swapPtr+1);
			*(swapPtr+1)=tmp;
		}
}
