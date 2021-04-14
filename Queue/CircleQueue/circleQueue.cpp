#include "circleQueue.h"

cQueueType* createQueue() {
	cQueueType* cQ;
	cQ = (cQueueType*)malloc(sizeof(cQueueType));
	cQ->front = 0; // 원형 큐의 front 초기값 설정
	cQ->rear = 0; // 원형 큐의 rear 초기값 설정
	return cQ;
}

int isEmpty(cQueueType* cQ) {
	if (cQ->front == cQ->rear) {
		printf("\n Circular Queue is empty! \n");
		return 1;
	}
	else return 0;
}

int isFull(cQueueType* cQ) {
	if ((cQ->rear+1) % CQ_SIZE == cQ->front ) {
		printf("\n Queue is Full! \n");
		return 1;
	}
	else return 0;
}

void enQueue(cQueueType* cQ, element item) {
	if (isFull(cQ))
		exit(1);
	else {
		cQ->rear = (cQ->rear + 1) % CQ_SIZE;
		cQ->queue[cQ->rear] = item;
	}
}

element deQueue(cQueueType* cQ) {
	if (isEmpty(cQ))
		exit(1);
	else {
		cQ->front = (cQ->front + 1) % CQ_SIZE;
		return cQ->queue[cQ->front];
	}
}

void del(cQueueType* cQ) {
	if (isEmpty(cQ))
		exit(1);
	else
		cQ->front = (cQ->front + 1) % CQ_SIZE;
}

element peek(cQueueType* cQ) {
	if (isEmpty(cQ))
		exit(1);
	else
		return cQ->queue[(cQ->front + 1) % CQ_SIZE];
}

void printQ(cQueueType* cQ) {
	int i, first, last;
	first = (cQ->front + 1) % CQ_SIZE;
	last = (cQ->rear + 1) % CQ_SIZE;
	printf("Circular Queue: [");
	i = first;
	while (i != last) {
		printf("%3c", cQ->queue[i]);
		i = (i + 1) % CQ_SIZE;
	}
	printf(" ] \n");
}