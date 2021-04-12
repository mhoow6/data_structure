#include "hashtable.h"

int SIZE = 10;																		//��Ŷ�� ��
bucket* hashTable = (bucket*)calloc(SIZE, sizeof(struct bucket));					// �Ҵ�, �ʱ�ȭ ���� ������ calloc ���

struct node* createNode(int key, int value) {				//hashtable�� ������� ��, �޸𸮸� �Ҵ�ް�, �Ҵ���� ��ҿ� �⺻���� �������ش�.
	struct node* newNode;									//���Ӱ� ������� ���������

	newNode = (struct node*)malloc(sizeof(struct node));	//����ü ��� ������ ��ŭ�� �޸� �Ҵ�ޱ�

	newNode->key = key;										//�⺻�� ����, ������ ��������ϴ� �ؽ̵� Ű
	newNode->value = value;									//�⺻�� ����, ������ �ְ� ���� �� �ʱ�ȭ
	newNode->next = NULL;

	return newNode;											//���Ӱ� ������� ��带 ȣ���ڿ��� ��ȯ
}

int hashFunction(int key) {									 //key�� ���� �� ��尡 � �������� �����ϴ��� �������ִ� �ؽ� �Լ�
	return key % SIZE;                                       //mod ����, key�� 1�̸� bucket1��, key�� 21�̸� bucket1��. ��, modulo ������ �Ͽ��� ���� ������ bucket�� �����϶�� �˷��ִ� �ؽ��Լ�
}

void insert(int key, int value) {							//�ְ����ϴ� Ű�� ���� �ް� �ؽ����̺� �ִ� �Լ�
	int hashIndex = hashFunction(key);                      //��� ���Ͽ� �־���ϴ��� �˷���. index�� ���Ϲ޾� hashIndex ������ ����.

	struct node* newNode = createNode(key, value);          //���޵� key,value ���� ���� ��带 ����

	//���� ���� ���
	if (hashTable[hashIndex].count == 0) {					//����ִ�
		hashTable[hashIndex].head = newNode;                //���ο� head��带 ���ο� ���� ����
		hashTable[hashIndex].count = 1;                     //count 1�� ����
	}
	//���� �ְ��� �ϴ� �ε����� �̹� ���� �ִ� ���
	else {
		newNode->next = hashTable[hashIndex].head;            //���ο� ����� next�����͸� head�� �ٲ۴�
		hashTable[hashIndex].head = newNode;                  //������ head�� ���ο� ���� �ٲ۴�.
		hashTable[hashIndex].count++;                         //�ش� ������ ��� count����
	}
}

void search(int key) {
	int hashIndex = hashFunction(key);                     //�ؽð� �޾ƿ���
	struct node* node = hashTable[hashIndex].head;         //bucket �ȿ� ü�̴׵� ������ �ϳ��ϳ� ���ϸ鼭 ã�ƾ� �ؼ� �ӽ� ����������� node ���� �� �� ������ head ��带 point

	if (node == NULL) {                                    //head�� �ƹ��͵� ����
		printf("\n no key found");
		return;                                            //search �Լ��� ��������
	}

	while (node != NULL) {
		if (node->key == key) {														 //ü�̴׵� ���� ���� ������ ���鼭 ���� key���� ������ ��带 ã���� ���
			printf("key found key = [%d], value = [%d]\n", node->key, node->value);    //���
			return;
		}
		node = node->next;															 //ã�� �ִ� ��尡 �ƴ϶�� ���� ���� �̵�
	}
	printf("\n no key found");
	return;																			 //ü�̴׵� ��带 ��ã�ƺôµ��� �ش� key�� ���� node�� ��ã�Ҵٸ� �Լ��� ��������
}

void display() {														  //�ؽ��� ���� ����
	struct node* horse;                                                   //��� ����� �ݺ��� ���� �ӽ� ��� ī���� ����
	int i = 0;
	for (i = 0; i < SIZE; i++) {										  //��Ŷ 0������ 9������ �ݺ�
		horse = hashTable[i].head;                                        //�ӽ� ���� ������ head���� ����
		printf("Bucket[%d] : ", i);                                       //��� �������� ����Ʈ
		while (horse != NULL) {                                           //�ش� ������ head������ null�� �ƴҽÿ�
			printf("(key : %d, value : %d) -> ", horse->key, horse->value);
			horse = horse->next;										  //�ش� ������ ���� ���� �̵�
		}
		printf("\n");													  //���� ��������
	}
	printf("\n");
	return;
}