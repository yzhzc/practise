#include"Queue.h"



//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_head = pq->_tail = NULL;
}


//销毁队列
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
//入尾队
void QueuePush(Queue* pq, QDataType x);
//队头出
void QueuePop(Queue* pq);
//读取队头的数据
QDataType QueueFront(Queue* pq);
//读取队尾的数据
QDataType QueueTail(Queue* pq);
//返回1是空，返回0是非空
int QueueEmpty(Queue* pq);