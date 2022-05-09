#include <stdio.h>
#include <stdlib.h>
typedef char element;
typedef struct LinkedDequeNode {
	element data;
	struct LinkedDequeNode* llink, * rlink;
} DQNode;
typedef struct LinkedDeque {
	DQNode* front, * rear;
} LinkedDeque;

LinkedDeque* createLinkedDeque(void) {
	LinkedDeque* LDQ = (LinkedDeque*)malloc(sizeof(LinkedDeque));
	if (LDQ != NULL) {
		LDQ->front = NULL;
		LDQ->rear = NULL;
	}
	return LDQ;
}
void insertFront(LinkedDeque* LDQ, element item) {
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
	newNode->data = item;
	if (LDQ->front == NULL) {
		LDQ->front = newNode;
		LDQ->rear = newNode;
		newNode->llink = NULL;
		newNode->rlink = NULL;
	}
	else {
		newNode->llink = NULL;
		newNode->rlink = LDQ->front;
		LDQ->front->llink = newNode;
		LDQ->front = newNode;
	}
}
void insertRear(LinkedDeque* LDQ, element item) {
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
	newNode->data = item;
	if (LDQ->front == NULL) {
		LDQ->front = newNode;
		LDQ->rear = newNode;
	}
	else {
		newNode->rlink = NULL;
		newNode->llink = LDQ->rear;
		LDQ->rear->rlink = newNode;
		LDQ->rear = newNode;
	}

}
element deleteFront(LinkedDeque* LDQ) {
	DQNode* delNode = LDQ->front;
	element delItem;
	if (LDQ->front == NULL) {
		printf("Deque empty\n");
	}
	else {
		delItem = delNode->data;
		if (LDQ->front->rlink == NULL)
		{
			LDQ->front = NULL;
			LDQ->rear = NULL;
		}
		else {
			LDQ->front = delNode->rlink;
			LDQ->front->llink = NULL;
		}
	}
	free(delNode);
	return delItem;
}
element deleteRear(LinkedDeque* LDQ) {
	DQNode* delNode = LDQ->rear;
	element delItem;
	if (LDQ->front == NULL) {
		printf("Deque empty\n");
	}
	else {
		delItem = delNode->data;
		if (LDQ->rear->llink == NULL)
		{
			LDQ->front = NULL;
			LDQ->rear = NULL;
		}
		else {
			LDQ->rear = delNode->llink;
			LDQ->rear->rlink = NULL;
		}
	}
	free(delNode);
	return delItem;
}
void printDeque(LinkedDeque* LDQ) {
	DQNode* p = LDQ->front;
	while (p) {
		printf("%3c", p->data);
		p = p->rlink;
	}
	printf("\n\n");
} 

int main()
{
	LinkedDeque* LDQ = createLinkedDeque();
	element data;
	insertFront(LDQ, 'A');		printDeque(LDQ);
	insertFront(LDQ, 'B');		printDeque(LDQ);
	insertFront(LDQ, 'C');		printDeque(LDQ);
	data = deleteFront(LDQ);	printDeque(LDQ);
	data = deleteRear(LDQ);		printDeque(LDQ);
	insertRear(LDQ, 'D');		printDeque(LDQ);
	insertFront(LDQ, 'E');		printDeque(LDQ);
	insertFront(LDQ, 'F');		printDeque(LDQ);

	return 1;

}