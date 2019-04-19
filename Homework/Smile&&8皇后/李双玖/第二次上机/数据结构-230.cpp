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
	LinkList listC = (LNode*)malloc(sizeof(LNode));
	listC->next = NULL;
	printf("������A��B��C���Ա���Ԫ�ظ�����");
	scanf("%d%d%d", &listA->data, &listB->data, &listC->data);
	
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
	
	printf("�������������C���Ա��е����ݣ�");
	p = listC;
	for(int i=0; i<listC->data; i++) {
		temp = (LNode*)malloc(sizeof(LNode));
		scanf("%d", &temp->data);
		p->next = temp;
		p = p->next;
	}
	p->next = NULL;
	//ListTraverse(listC);
	
	
	// ��B��Cȡ�����������������B�� 
	LNode *pB = listB->next, *pC = listC->next;
	LNode *priorB = listB, *priorC = listC;
	while(pC && pB) {
		if(pB->data == pC->data) {
			priorB = pB;
			pB = priorB->next;
			priorC = pC;
			pC = priorC->next;
		}
		else if(pB->data < pC->data) {
			priorB->next = pB->next;
			free(pB);
			pB = priorB->next;
		}
		else {
			priorC = pC;
			pC = priorC->next;
		}
	}
	while(pB) {
		temp = pB;
		pB = pB->next;
		free(pB);
	}
	priorB->next = NULL;
	printf("B��Cȡ��������:\n");
	ListTraverse(listB);
	
	
	// ��A�У�ɾȥ������B��C�����е���
	LNode *pA = listA->next, *priorA = listA;
	pB = listB->next, priorB = listB; 
	while(pA && pB) {
		if(pA->data == pB->data) {
			priorA->next = pA->next;
			free(pA);
			pA = priorA->next;
		}
		else if(pA->data > pB->data) {
			priorB = pB;
			pB = priorB->next;
		}
		else {
			priorA = pA;
			pA = priorA->next;
		}
	}
	printf("Aɾȥ��������:\n");
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
	p = listC;
	while(p) {
		temp = p;
		p = p->next;
		free(temp);
	}
} 





