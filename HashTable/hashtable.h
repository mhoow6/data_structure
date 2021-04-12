#include <stdio.h>
#include <stdlib.h>

/*
 * �ؽ� ���̺�
 * ������ ���� ���� ������ ����� �ڸ��� �����Ǵ� �ڷᱸ��
 * ã�� ������ -> �ؽ��Լ� -> Ű�� -> ������
 * 
 * �ؽ� ���̺��� Bucket(���� �����Ͱ� ���� �ڷᱸ���� ũ��)��
 * �Ҽ��̾�� �ϰ�, 2�� �ŵ��������� �ϸ� �� �� -> ���� ������ �ʱ� ����
 */

struct node {
	int key;
	int value;
	struct node* next; //���������,���� ��ũ (ü�̴� �Ҷ� ���� ��尡 ������� �˷���)
};

struct bucket {
	struct node* head; //������ ���� ó����带 ����Ű�� head
	int count; //���Ͼȿ� ��� ��尡 ���ִ��� �˷��ִ� count
};

struct node* createNode(int key, int value);

int hashFunction(int key);

void insert(int key, int value);

void search(int key);

void display();


