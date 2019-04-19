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
	
	
	// ��ʼ�����ϲ�����
	LNode *pA = listA->next, *pB = listB->next;
	LNode *priorA = listA;
	while(pA && pB) {
		if(pA->data > pB->data) {
			priorA->next = pB;
			listB->next = pB->next;
			pB->next = pA;
			priorA = pB;
			pB = listB->next;
		}
		else {
			priorA = pA;
			pA = pA->next;
		}
	}
	if(pB) {
		priorA->next = pB;
		listB->next = NULL;
	}
	free(listB);
	
	
	// ��ʼ����
	p = listA->next;
	listA->next = NULL;
	while(p) {
		temp = p;
		p = p->next;
		temp->next = listA->next;
		listA->next = temp;
	} 
	ListTraverse(listA);
	
	
	// �������� 
	p = listA;
	while(p) {
		temp = p;
		p = p->next;
		free(temp);
	}
} 





