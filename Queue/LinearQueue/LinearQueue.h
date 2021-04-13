#pragma once
#include <stdio.h>
#include <stdlib.h>
#define Q_SIZE 100

typedef char element;

typedef struct {
	element queue[Q_SIZE];
	int front, rear;
} QueueType;

QueueType* createQueue();
int isEmpty(QueueType* Q);
void enQueue(QueueType* Q, element item);
element deQueue(QueueType* Q);
void del(QueueType* Q);
element peek(QueueType* Q);
void printQ(QueueType* Q);


