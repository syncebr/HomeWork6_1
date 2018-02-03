/*Даны два массива, упорядоченных по возрастанию: А[n] и B[m].
Сформируйте массив C[n+m], состоящий из элементов массивов А и В, упорядоченный по возрастанию.
Способ, заключающийся в том, что все скидывается в один массив, а потом сортируется, не подходит!
Массив должен сразу формироваться упорядоченным.*/

#include<iostream>
#include<ctime>

using namespace std;

void GenerateArr(int arr[], int size);
void PrintArr(int arr[], int size, int col);
void SortArr(int arr[], int size);

int main(void) {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	const int SIZE1 = 5;
	const int SIZE2 = 8;
	const int SIZE3 = 13;
	int arr1[SIZE1] = {0}, arr2[SIZE2] = {0}, arr3[SIZE3] = {0};
	int *ptr1, *ptr2, *ptr3,*ptrTmp;
	ptr1 = arr1;
	ptr2 = arr2;
	ptr3 = arr3;
	int col;
	cout << "Сколько элементов отображать в одной строке?    -->";
	cin >> col;
	GenerateArr(arr1, SIZE1);
	SortArr(arr1, SIZE1);
	GenerateArr(arr2, SIZE2);
	SortArr(arr2, SIZE2);
	cout << "первый массив:" << endl;
	PrintArr(arr1, SIZE1, col);
	cout << "второй массив:" << endl;
	PrintArr(arr2, SIZE2, col);
	//склейка массивов пока один из неих не закончится
	while ((ptr1<arr1 + SIZE1) && (ptr2<(arr2 + SIZE2))) {	
		if (*ptr1 <= *ptr2) {
			*ptr3 = *ptr1;
			ptr1++;
		}
		else {
			*ptr3 = *ptr2;
			ptr2++;
		}
		ptr3++;
	}
	//на случай если первым закончился 2 массив
	while (ptr1 <( arr1 + SIZE1)&&ptr3<(arr3+SIZE3)) {
		*ptr3 = *ptr1;
		ptr1++;
		ptr3++;	
	}
	//на случай если первым закончился 1-ймассив
	while (ptr2 < (arr2 + SIZE2) && ptr3<(arr3 + SIZE3)) {
		*ptr3 = *ptr2;
		ptr2++;
		ptr3++;
	}
	cout << "Третий массив:" << endl;
	PrintArr(arr3, SIZE3, col);
	system("pause");
}

void GenerateArr(int arr[], int size) {
	int *ptr = arr;
	for (int i = 0; i < size; i++, ptr++)
		*ptr = rand() % 101;
}

void PrintArr(int arr[], int size, int col) {
	int *ptr = arr;
	int counter = 0;
	for (int i = 0; i < size; i++, ptr++) {
		printf("%2d\t", *ptr);
		counter++;
		if (counter % col == 0)cout << endl;
	}
	cout << endl;
}

void SortArr(int arr[], int size) {
	int tmp, j;
	for (int i = 0; i<size - 1; i++) //i-номер последнего из упорядоченных
	{
		tmp = arr[i + 1]; //сохранить копию вставляемого элемента
		j = i;    //j- индекс элемента, после которого может быть вставка
		while (j >= 0 && arr[j]>tmp)  //пока не найдено место
		{
			arr[j + 1] = arr[j];  //сдвиг элемента вправо
			j--;
		}
		arr[j + 1] = tmp;   //вставка на место
	}
}
