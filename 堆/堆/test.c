#include"Heap.h"







int main()
{
	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	Heap hp;
	LessHeapInit(&hp, a, sizeof(a) / sizeof(HPDataType));
	LessHeapPush(&hp, 16);
	HeapDown(&hp);
	for (int i = 0; i < hp._size; i++)
	{
		printf("%d\n", hp._a[i]);
	}
	return 0;
}