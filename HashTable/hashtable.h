#include <stdio.h>
#include <stdlib.h>

/*
 * 해시 테이블
 * 원소의 값에 의해 원소의 저장될 자리가 결정되는 자료구조
 * 찾는 데이터 -> 해시함수 -> 키값 -> 데이터
 * 
 * 해시 테이블의 Bucket(실제 데이터가 들어가는 자료구조의 크기)는
 * 소수이어야 하고, 2의 거듭제곱으로 하면 안 됨 -> 골고루 퍼지지 않기 때문
 */

struct node {
	int key;
	int value;
	struct node* next; //노드포인터,다음 링크 (체이닝 할때 다음 노드가 어딨는지 알려줌)
};

struct bucket {
	struct node* head; //버켓의 제일 처음노드를 가리키는 head
	int count; //버켓안에 몇개의 노드가 들어가있는지 알려주는 count
};

struct node* createNode(int key, int value);

int hashFunction(int key);

void insert(int key, int value);

void search(int key);

void display();


