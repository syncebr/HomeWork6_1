
/*Даны два массива, упорядоченных по возрастанию: А[n] и B[m].
Сформируйте массив C[n+m], состоящий из элементов массивов А и В, упорядоченный по возрастанию.
Способ, заключающийся в том, что все скидывается в один массив, а потом сортируется, не подходит!
Массив должен сразу формироваться упорядоченным.*/

#include<iostream>
#include<ctime>

using namespace std;

void GenerateArr(int arr[],int size);
void PrintArr(int arr[], int size, int col);
void SortArr(int arr[],int size);

int main(void) {
	setlocale(LC_ALL, "rus");
	const int SIZE1 = 5;
	const int SIZE2 = 8;
	const int SIZE3 = SIZE1 + SIZE2;
	int arr1[SIZE1] = {}, arr2[SIZE2] = {}, arr3[SIZE3] = {};
	int *ptr1=arr1,*ptr2=arr2,*ptr3=arr3;
	int col;
	cout << "Сколько элементов отображать в одной строке?    -->";
	cin >> col;
	GenerateArr(arr1, SIZE1);
	GenerateArr(arr2, SIZE2);
	SortArr(arr1, SIZE1);
	SortArr(arr2, SIZE2);
	cout<<"первый массив:"<<endl;
	PrintArr(arr1, SIZE1,col);
	cout << "второй массив:" << endl;
	PrintArr(arr2, SIZE2,col);
	int i = 0;
	while ((ptr1<ptr1+SIZE1)&&(ptr2<ptr2+SIZE2)) {
		//пока не закончится первый(меньший массив)
		if (*ptr1 < *ptr2) {
			*ptr3 = *ptr1;
			ptr1++;
		}
		if (*ptr1 > *ptr2) {
			*ptr3 = *ptr2;
			ptr2++;
		}
		//когда закончился первый массив
		if (ptr1 >= ptr1 + SIZE1) {
			*ptr3 = *ptr2;
		}
		i++;
		ptr3++;
	}
	cout << "Третий массив:" << endl;
	PrintArr(arr3, SIZE3, col);
	system("pause");
}

void GenerateArr(int arr[], int size) {
	int *ptr = arr;
	srand(time(0));
	for (int i = 0; i < size; i++, ptr++)
		*ptr = rand() % 101;
}

void PrintArr(int arr[], int size,int col) {
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
	int tmp,j;
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
