#include "LinearQueue.h"

QueueType* createQueue() {
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = -1;
	Q->rear = -1;
	return Q;
}

int isEmpty(QueueType* Q) {
	if (Q->front == Q->rear) {
		printf("\n Queue is Empty! \n");
		return 1;
	}
	else return 0;
}

int isFull(QueueType* Q) {
	if (Q->rear == Q_SIZE - 1) {
		printf("\n Queue is Full! \n");
		return 1;
	}
	else return 0;
}

void enQueue(QueueType* Q, element item) {
	if (isFull(Q))
		exit(1);
	else {
		Q->rear++;
		Q->queue[Q->rear] = item;
	}
}

element deQueue(QueueType* Q) {
	if (isEmpty(Q))
		exit(1);
	else {
		Q->front++;
		return Q->queue[Q->front];
	}
}

void del(QueueType* Q) {
	if (isEmpty(Q))
		exit(1);
	else
		Q->front++;
}

// 큐의 가장 앞에 있는 원소를 검색하여 반환하는 연산
element peek(QueueType* Q) {
	if (isEmpty(Q))
		exit(1);
	else
		return Q->queue[Q->front + 1];
}

void printQ(QueueType* Q) {
	int i;
	printf(" Queue: [");
	for (i = Q->front + 1; i <= Q->rear; i++)
		printf("%3c", Q->queue[i]);
	printf(" ] \n");
}