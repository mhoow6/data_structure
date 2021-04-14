#pragma once
#include <stdio.h>
#include <stdlib.h>
#define CQ_SIZE 4

typedef char element;
typedef struct {
	element queue[CQ_SIZE]; // 1차원 배열 큐 선언
	int front, rear;
} cQueueType;

cQueueType* createQueue();
int isEmpty(cQueueType* cQ); // 원형 큐가 공백인지 확인하는 연산
int isFull(cQueueType* cQ); // 원형 큐가 포화상태인지 확인하는 연산
void enQueue(cQueueType* cQ, element item); // 원형 큐의 rear에 원소를 삽입하는 연산
element deQueue(cQueueType* cQ); // 원형 큐의 front에서 원소를 삭제하고 반환하는 연산
void del(cQueueType* cQ); // 원형 큐의 front에서 원소를 삭제하는 연산
element peek(cQueueType* cQ); // 원형 큐의 가장 앞에 있는 원소를 검색하여 반환하는 연산
void printQ(cQueueType* cQ); // 원형 큐의 내용을 출력하는 연산산

