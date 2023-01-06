#include"Queue.h"



//��ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_head = pq->_tail = NULL;
}


//���ٶ���
void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_head;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur=next
	}
	pq->_head = pq->_tail = NULL;
}
//��β��
void QueuePush(Queue* pq, QDataType x);
//��ͷ��
void QueuePop(Queue* pq);
//��ȡ��ͷ������
QDataType QueueFront(Queue* pq);
//��ȡ��β������
QDataType QueueTail(Queue* pq);
//����1�ǿգ�����0�Ƿǿ�
int QueueEmpty(Queue* pq);