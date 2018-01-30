//============================================================================
// Name        : Number6_1_2.cpp
// Author      : grand
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================
/*Дан массив целых чисел (можно ввести значения элементов или задать случайным образом).
 *Пользуясь ДВУМЯ указателями, нужно поменять порядок элементов массива на обратный.*/
#include <iostream>
#include<ctime>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

void GenerateArr(int arr[],int size);
void PrintArr(int arr[],int size);
void ReverseArr(int arr[],int size);

int main(void) {
	const int SIZE=15;
	int arr[SIZE];
	GenerateArr(arr,SIZE);
	cout<<"U'r arr is:"<<endl;
	PrintArr(arr,SIZE);
	ReverseArr(arr,SIZE);
	cout<<endl<<"Reverse array:"<<endl;
	PrintArr(arr,SIZE);
	return 0;
}

void GenerateArr(int arr[],int size){
		int *ptrArr;
		ptrArr=arr;
		srand(time(0));
		for (int i=0;i<size;i++,ptrArr++)
			*ptrArr=rand()%41;
}

void PrintArr(int arr[],int size){
	int *ptrArr;
	int counter=0;
	ptrArr=arr;
	for(int i=0;i<size;i++,ptrArr++){
		printf("a[%2d]=%2d\t",i, *ptrArr);
		counter++;
		if(counter%5==0) cout<<endl;
	}
}

void ReverseArr(int arr[],int size){
	int tmp, *ptrArr, *ptrRevArr;
	ptrArr=arr;
	ptrRevArr=&arr[size-1];
	while(ptrArr != ptrRevArr){
		tmp=*ptrArr;
		*ptrArr=*ptrRevArr;
		*ptrRevArr=tmp;

		ptrArr++;
		ptrRevArr--;
	}
}









