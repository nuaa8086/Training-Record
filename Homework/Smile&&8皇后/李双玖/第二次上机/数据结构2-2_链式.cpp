#include<stdio.h>
#include<stdlib.h>

typedef struct LNode {
	int data;
	LNode *next;
}*LinkList;

//��������
void ListTraverse(LinkList list) {
	printf("\n================����==============\n");
	LNode *p = list->next;
	int i = 1;
	while(p) {
		printf("��%dλֵΪ��%d\n", i, p->data); 
		p = p->next;
		i++;
	}
	printf("==================================\n\n");
};

int main() {
	
	// ��ʼ�� 
	LinkList listA = (LNode*)malloc(sizeof(LNode));
	listA->next = NULL;
	LinkList listB = (LNode*)malloc(sizeof(LNode));
	listB->next = NULL;
	printf("������A��B���Ա���Ԫ�ظ�����");
	scanf("%d%d", &listA->data, &listB->data);
	
	LNode *p, *temp;
	printf("\n�������������A���Ա��е����ݣ�");
	p = listA;
	for(int i=0; i<listA->data; i++) {
		temp = (LNode*)malloc(sizeof(LNode));
		scanf("%d", &temp->data);
		p->next = temp;
		p = p->next;
	}
	p->next = NULL;
	//ListTraverse(listA);
	
	printf("�������������B���Ա��е����ݣ�");
	p = listB;
	for(int i=0; i<listB->data; i++) {
		temp = (LNode*)malloc(sizeof(LNode));
		scanf("%d", &temp->data);
		p->next = temp;
		p = p->next;
	}
	p->next = NULL;
	//ListTraverse(listB);
	
	
	// ��B��Cȡ���� 
	LNode *pA = listA->next, *pB = listB->next;
	LNode *priorA = listA, *priorB = listB;
	while(pA && pB) {
		if(pA->data == pB->data) {
			priorB->next = pB->next;
			free(pB);
			pB = priorB->next;
			
			priorA = pA;
			pA = priorA->next;
		}
		else if(pA->data < pB->data) {
			priorA->next = pA->next;
			free(pA);
			pA = priorA->next;
		}
		else {
			priorB->next = pB->next;
			free(pB);
			pB = priorB->next;
		}
	}
	while(pA) {
		temp = pA;
		pA = pA->next;
		free(pA);
	}
	priorA->next = NULL;
	printf("ȡ��������:\n");
	ListTraverse(listA);
	
	
	// �������� 
	p = listA;
	while(p) {
		temp = p;
		p = p->next;
		free(temp);
	}
	
	p = listB;
	while(p) {
		temp = p;
		p = p->next;
		free(temp);
	}
} 





