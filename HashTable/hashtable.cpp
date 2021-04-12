#include "hashtable.h"

int SIZE = 10;																		//버킷의 수
bucket* hashTable = (bucket*)calloc(SIZE, sizeof(struct bucket));					// 할당, 초기화 문제 때문에 calloc 사용

struct node* createNode(int key, int value) {				//hashtable에 집어넣을 때, 메모리를 할당받고, 할당받은 장소에 기본값을 세팅해준다.
	struct node* newNode;									//새롭게 만들어진 노드포인터

	newNode = (struct node*)malloc(sizeof(struct node));	//구조체 노드 사이즈 만큼의 메모리 할당받기

	newNode->key = key;										//기본값 세팅, 유저가 만들고자하는 해싱된 키
	newNode->value = value;									//기본값 세팅, 유저가 넣고 싶은 값 초기화
	newNode->next = NULL;

	return newNode;											//새롭게 만들어진 노드를 호출자에게 반환
}

int hashFunction(int key) {									 //key를 통해 이 노드가 어떤 버켓으로 들어가야하는지 정의해주는 해쉬 함수
	return key % SIZE;                                       //mod 연산, key가 1이면 bucket1로, key가 21이면 bucket1로. 즉, modulo 연산을 하여서 나온 숫자의 bucket에 맵핑하라고 알려주는 해시함수
}

void insert(int key, int value) {							//넣고자하는 키와 값을 받고 해쉬테이블에 넣는 함수
	int hashIndex = hashFunction(key);                      //어디 버켓에 넣어야하는지 알려줌. index를 리턴받아 hashIndex 변수에 저장.

	struct node* newNode = createNode(key, value);          //전달된 key,value 값을 가진 노드를 생성

	//값이 없는 경우
	if (hashTable[hashIndex].count == 0) {					//비어있다
		hashTable[hashIndex].head = newNode;                //새로운 head노드를 새로운 노드로 지정
		hashTable[hashIndex].count = 1;                     //count 1로 설정
	}
	//내가 넣고자 하는 인덱스에 이미 값이 있는 경우
	else {
		newNode->next = hashTable[hashIndex].head;            //새로운 노드의 next포인터를 head로 바꾼다
		hashTable[hashIndex].head = newNode;                  //버켓의 head를 새로운 노드로 바꾼다.
		hashTable[hashIndex].count++;                         //해당 버켓의 노드 count증가
	}
}

void search(int key) {
	int hashIndex = hashFunction(key);                     //해시값 받아오기
	struct node* node = hashTable[hashIndex].head;         //bucket 안에 체이닝된 노드들을 하나하나 비교하면서 찾아야 해서 임시 노드포인터인 node 생성 후 그 버켓의 head 노드를 point

	if (node == NULL) {                                    //head에 아무것도 없음
		printf("\n no key found");
		return;                                            //search 함수를 빠져나감
	}

	while (node != NULL) {
		if (node->key == key) {														 //체이닝된 버켓 안의 노드들을 보면서 만약 key값이 동일한 노드를 찾았을 경우
			printf("key found key = [%d], value = [%d]\n", node->key, node->value);    //출력
			return;
		}
		node = node->next;															 //찾고 있는 노드가 아니라면 다음 노드로 이동
	}
	printf("\n no key found");
	return;																			 //체이닝된 노드를 다찾아봤는데도 해당 key를 가진 node를 못찾았다면 함수를 빠져나감
}

void display() {														  //해시의 현재 상태
	struct node* horse;                                                   //모든 노드의 반복을 위한 임시 노드 카운터 생성
	int i = 0;
	for (i = 0; i < SIZE; i++) {										  //버킷 0번부터 9번까지 반복
		horse = hashTable[i].head;                                        //임시 노드는 버켓의 head부터 시작
		printf("Bucket[%d] : ", i);                                       //몇번 버켓인지 프린트
		while (horse != NULL) {                                           //해당 버켓의 head노드부터 null이 아닐시에
			printf("(key : %d, value : %d) -> ", horse->key, horse->value);
			horse = horse->next;										  //해당 버켓의 다음 노드로 이동
		}
		printf("\n");													  //다음 버켓으로
	}
	printf("\n");
	return;
}