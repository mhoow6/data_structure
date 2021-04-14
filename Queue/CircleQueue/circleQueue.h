#pragma once
#include <stdio.h>
#include <stdlib.h>
#define CQ_SIZE 4

typedef char element;
typedef struct {
	element queue[CQ_SIZE]; // 1���� �迭 ť ����
	int front, rear;
} cQueueType;

cQueueType* createQueue();
int isEmpty(cQueueType* cQ); // ���� ť�� �������� Ȯ���ϴ� ����
int isFull(cQueueType* cQ); // ���� ť�� ��ȭ�������� Ȯ���ϴ� ����
void enQueue(cQueueType* cQ, element item); // ���� ť�� rear�� ���Ҹ� �����ϴ� ����
element deQueue(cQueueType* cQ); // ���� ť�� front���� ���Ҹ� �����ϰ� ��ȯ�ϴ� ����
void del(cQueueType* cQ); // ���� ť�� front���� ���Ҹ� �����ϴ� ����
element peek(cQueueType* cQ); // ���� ť�� ���� �տ� �ִ� ���Ҹ� �˻��Ͽ� ��ȯ�ϴ� ����
void printQ(cQueueType* cQ); // ���� ť�� ������ ����ϴ� �����

