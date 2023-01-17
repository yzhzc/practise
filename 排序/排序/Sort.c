#include"Sort.h"

void PrintArrway(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}
}


//��������
void InsertSort(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			//�ж�end��һ�����С��end��end��һ����end���ǣ�ָ�����
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

//ϣ������
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
				//�ж�end���3�����С��end��end���3����end���ǣ�ָ�����
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

//ѡ������
void SelectSort(int* a, int n);

//������
void ADjustDown(int* a, int n, int root);
void HeapSort(int* a, int n);

//ð������
void BubbleSort(int* a, int n);

//�������� �ݹ�ʵ��
//�������� hoare�汾
int PartSort1(int* a, int left, int right);
//�������� �ڿӷ�
int PartSort2(int* a, int left, int right);
//�������� ǰ��ָ�뷨
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);

//��������ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right);

//�鲢���� �ݹ�ʵ��
void MergerSort(int* a, int n);
//�鲢���� �ǵݹ�ʵ��
void MergeSortNonR(int* a, int n);

//��������
void CountSort(int* a, int n);
