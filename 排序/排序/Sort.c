#include"Sort.h"

void PrintArrway(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}
}


//插入排序
void InsertSort(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			//判断end后一个如果小于end，end后一个被end覆盖，指针后移
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
			a[end + 1] = tmp;
		}
	}
	PrintArrway(a, n);
}

//希尔排序
void ShellSort(int* a, int n)
{
	assert(a);
	int gap = n;
	while (gap != 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				//判断end后第3个如果小于end，end后第3个被end覆盖，指针后移
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
				a[end + gap] = tmp;
			}
		}
	}
	PrintArrway(a, n);
}

//选择排序
void SelectSort(int* a, int n);

//堆排序
void ADjustDown(int* a, int n, int root);
void HeapSort(int* a, int n);

//冒泡排序
void BubbleSort(int* a, int n);

//快速排序 递归实现
//快速排序 hoare版本
int PartSort1(int* a, int left, int right);
//快速排序 挖坑法
int PartSort2(int* a, int left, int right);
//快速排序 前后指针法
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);

//快速排序非递归实现
void QuickSortNonR(int* a, int left, int right);

//归并排序 递归实现
void MergerSort(int* a, int n);
//归并排序 非递归实现
void MergeSortNonR(int* a, int n);

//计数排序
void CountSort(int* a, int n);
