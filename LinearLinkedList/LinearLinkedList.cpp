#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* 단순 연결 리스트
* 노드가 하나의 링크 필드에 의해서 다음 노드와 연결되는 구조
* 
* 1. 노드
* <data, link> 단위 구조의 메모리 블럭
*/

// 단순 연결 리스트의 노드 구조 정의
typedef struct ListNode {
	char data[10];
	struct ListNode* link;
} listNode;

// 연결 리스트를 가리키는 헤드 노드의 구조 정의
typedef struct {
	listNode* head;
} linkedList_h;


linkedList_h* createLinkedList_h(void);
void addLastNode(linkedList_h* L, const char* x);
void deleteLastNode(linkedList_h* L);
void freeLinkedList_h(linkedList_h* L);
void printList(linkedList_h* L);

int main()
{
	linkedList_h* L;
	L = createLinkedList_h();
	printf("(1) 공백리스트 생성하기! \n");
	printList(L);
	getchar();

	printf("(2) 리스트에 3개의 노드를 추가하기! \n");
	addLastNode(L, "월");
	addLastNode(L, "수");
	addLastNode(L, "금");
	printList(L);
	getchar();

	printf("(3) 리스트 마지막에 노드 한 개 추가하기! \n");
	addLastNode(L, "일");
	printList(L);
	getchar();

	printf("(4) 마지막 노드 삭제하기! \n");
	deleteLastNode(L);
	printList(L);
	getchar();

	printf("(5) 리스트 공간을 해제하여, 공백 리스트로 만들기! \n");
	freeLinkedList_h(L);
	printList(L);
	getchar();

	return 0;
}

// 공백 연결 리스트 생성 함수
linkedList_h* createLinkedList_h(void) {
	linkedList_h* L;

	// 헤드 노드에 필요한 메모리를 할당받고 그 주소를 L에게 저장
	L = (linkedList_h*)malloc(sizeof(linkedList_h));

	// 공백 연결 리스트이므로 NULL을 설정
	L->head = NULL;

	return L;
}

// 리스트의 마지막 노드 삽입 연산
void addLastNode(linkedList_h* L, const char* x) {
	listNode* newNode;
	listNode* p;
	
	// 삽입할 새 노드의 메모리를 할당받고 그 주소를 newNode에 저장
	newNode = (listNode*)malloc(sizeof(listNode));
	
	// 새 노드의 데이터 필드에 x 저장
	strcpy_s(newNode->data, x);

	// 새 노드의 주소 필드는 아무도 가리키지 않는다
	newNode->link = NULL;

	// 현재 연결 리스트가 공백인 경우
	if (L->head == NULL) {

		L->head = newNode;	// 새 노드의 메모리 주소를 헤드 노드에 저장
		return;				// 함수 종료
	}

	// 헤드노드가 가리키는 주소값(노드의 주소)을 p에 저장
	// 결국 p는 노드를 의미함
	p = L->head;

	/* 재귀적인 의미로 받아들여야 이해하기 편함 */

	// 새 노드의 주소필드가 누군가 가리키고 있으면
	while (p->link != NULL)
		// 연결된 노드의 주소값을 노드에 저장한다.
		p = p->link;		

	// 노드의 주소필드가 NULL일 경우 (아무도 가리키지 않을 경우)
	// 새 노드의 주소를 저장함
	p->link = newNode;

	/*****************************************/
}

// 리스트의 마지막 노드 삭제 연산
void deleteLastNode(linkedList_h* L) {
	listNode* previous;
	listNode* current;

	if (L->head == NULL) return;			// 공백 연결 리스트인 경우 삭제 연산 중단

	if (L->head->link == NULL)				// 노드의 주소필드가 NULL일경우(연결리스트의 노드가 하나일경우)
	{
		free(L->head);						// 첫 번째 노드의 메모리를 해제
		L->head = NULL;						// 헤드 노드를 아무도 가리키지 않게 함
		return;
	}
	else
	{
		previous = L->head;
		current = L->head->link;
		
		// 현재 노드의 주소필드가 누군가 가리키고 있으면
		while (current->link != NULL) {
			previous = current;				// 현재 노드를 previous에 저장
			current = current->link;		// 다음 노드를 current에 저장
		}
		free(current);						// 다음 노드 메모리 해제
		previous->link = NULL;				// 다음 노드의 메모리가 없어졌으므로, 현재 노드의 주소필드도 NULL을 가리키게 함
	}
}

// 연결 리스트 전체 메모리 해제 연산
void freeLinkedList_h(linkedList_h* L) {
	listNode* p;

	// head 노드의 값이 NULL이 될 때까지
	while (L->head != NULL) {
		// 첫 번째 노드를 가리키는 주소를 p에 저장
		p = L->head;

		// 헤드 노드와 첫 번째로 가까운 노드의 주소 필드를 헤드 노드에 저장
		// 즉, 두 번째 노드의 주소를 헤드 노드에 저장
		L->head = L->head->link;

		// 첫 번째 노드의 메모리 해제
		free(p);

		// 첫 번째 노드가 없어졌으므로 p는 NULL을 가리켜야함
		p = NULL;
	}
}

// 노드 순서대로 리스트를 출력하는 연산
void printList(linkedList_h* L) {
	listNode* p;
	printf("L = (");

	// 첫 번째 노드의 주소를 p에 저장
	p = L->head;

	/* 연결리스트가 끝날 때까지 탐색해서 data 출력 */
	// p가 아무도 안 가리킬때까지
	while (p != NULL)
	{
		// 첫 번째 노드의 데이터를 출력
		printf("%s", p->data);

		// p에 다음 노드의 주소 저장
		p = p->link;

		// 마지막 노드가 아니면
		if (p != NULL)
			printf("%s", ", "); // 쉼표 출력
	}
	printf(") \n");
}