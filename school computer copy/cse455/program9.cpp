#include <iostream>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

int Numbers [1000];

class Sort
{
public:
	void PrintArray(int* array, int n);
	void QuickSort(int* array, int startIndex, int endIndex);
	int SplitArray(int* array, int pivotValue, int startIndex, int endIndex);
	void swap(int &a, int &b);
	int Bubble();
};

void Sort::swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void Sort::PrintArray(int* array, int n)
{
    int i;
      
    for( i = 0; i < n; i++) cout<<array[i]<<'\t';
}

void Sort::QuickSort(int* array, int startIndex, int endIndex)
{
    int pivot = array[startIndex];
    int splitPoint;
     
    if(endIndex > startIndex)
    {
        splitPoint = SplitArray(array, pivot, startIndex, endIndex);
        array[splitPoint] = pivot;
        QuickSort(array, startIndex, splitPoint-1);
        QuickSort(array, splitPoint+1, endIndex);
    }
}

int Sort::SplitArray(int* array, int pivot, int startIndex, int endIndex)
{
    int leftBoundary = startIndex;
    int rightBoundary = endIndex;
     
    while(leftBoundary < rightBoundary)
    {
         while( pivot < array[rightBoundary]
                && rightBoundary > leftBoundary)
         {
              rightBoundary--;
         }
         swap(array[leftBoundary], array[rightBoundary]);
          
         while( pivot >= array[leftBoundary]
                && leftBoundary < rightBoundary)
         {
              leftBoundary++;
         }
         swap(array[rightBoundary], array[leftBoundary]);
    }
    return leftBoundary;
}

int Sort::Bubble()
{
	int i, j;
	int temp = 0;
	int num;

	srand(time(NULL));
    
	for(i = 0; i < 50; i++)
	{

		for (j = 0; j < 50-1; j++)
        {
            if (Numbers[j] > Numbers[j+1])
			{
				temp = Numbers[j];
				Numbers[j] = Numbers[j+1];
				Numbers[j+1] = temp;
			}
        }
	}

	for (i = 0; i < 50; i++)
	{
		cout << Numbers[i] << '\t';
	}
}

int main()
{
	Sort sort;
	int num;
	for (int i = 0; i < 1000; i++)
	{
		num = rand() %9000 + 1000;
		Numbers[i] = num;
	}

	sort.QuickSort(Numbers,0,1000 - 1);
	sort.PrintArray(Numbers, 1000);

	cout << endl << endl;

	sort.Bubble();

	cout << endl << endl;
}
