#include"Sort.h"

//����
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


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
void SelectSort(int* a, int n)
{
	assert(a);

	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int maxi = begin;
		int mini = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
	PrintArrway(a, n);
}

//������

//�Ѷ����µ���
void ADjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
	
}

//���������
void HeapRiseSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		ADjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		ADjustDown(a, end, 0);
		end--;
	}
	PrintArrway(a, n);
}

//ð������
void BubbleSort(int* a, int n)
{
	int end = n;
	while (end >= 0)
	{
		int exchange = 0;
		for (int i = 1; i < end; i++)
		{
			if (a[i-1] > a[i])
			{
				Swap(&a[i-1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			break;
		}
		end--;
	}
	PrintArrway(a, n);
}

//�������� �ݹ�ʵ��
//�������� hoare�汾


//ȡǰ�к�������ȡ��С���м�������±�
int GetMidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
	else
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
}

int PartSort1(int* a, int begin, int end)
{
	//����ȡ����ĩβ������
	int midIndex = GetMidIndex(a, begin, end);
	Swap(&a[end], &a[midIndex]);

	//ȡĩβ������Ϊ�Ƚϵ�key
	int ketindex = end;

	while (begin < end)
	{
		while (begin < end && a[begin] <= a[ketindex])
		{
			++begin;
		}
		while (begin < end && a[end] >= a[ketindex])
		{
			--end;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[ketindex]);

	return begin;
}
//�������� �ڿӷ�
int PartSort2(int* a, int left, int right);
//�������� ǰ��ָ�뷨
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right)
{
	assert(a);
	if (left < right)
	{
		int div = PartSort1(a, left, right);
		//�ֳ� [left , div - 1] �� [div + 1 , right]

		PrintArrway(a, 10);
		printf("\n");
		printf("[%d,%d]%d[%d,%d]\n", a[left], a[div - 1], div, a[div + 1], a[right]);

		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
}

//��������ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right);

//�鲢���� �ݹ�ʵ��
void MergerSort(int* a, int n);
//�鲢���� �ǵݹ�ʵ��
void MergeSortNonR(int* a, int n);

//��������
void CountSort(int* a, int n);
