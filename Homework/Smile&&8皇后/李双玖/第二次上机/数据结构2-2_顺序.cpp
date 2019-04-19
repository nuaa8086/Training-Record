#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int *list;
	int length;
}SqList ;

void ListTraverse(SqList L) {
	printf("\n==========����=============\n");
	for(int i=0; i<L.length; i++) {
		printf("%d ", L.list[i]);
	}
	printf("\n===========================\n\n");
}

int main() {
	
	// ��ʼ�� 
	SqList La, Lb, Lc;
	printf("������A��B���Ա���Ԫ�ظ�����");
	scanf("%d%d", &La.length, &Lb.length);
	La.list = (int*)malloc(sizeof(int) * La.length);
	Lb.list = (int*)malloc(sizeof(int) * Lb.length);
	
	printf("\n�������������A���Ա��е����ݣ�");
	for(int i=0; i<La.length; i++) {
		scanf("%d", &La.list[i]);
	}
	ListTraverse(La);
	
	printf("�������������B���Ա��е����ݣ�");
	for(int i=0; i<Lb.length; i++) {
		scanf("%d", &Lb.list[i]);
	}
	ListTraverse(Lb);
	
	
	// ��A��Bȡ�� 
	int i=0, j=0;
	while(i<La.length && j<Lb.length) {
		if(La.list[i] == Lb.list[j]) {
			i++;
			j++; 
		} 
		else if(La.list[i] < Lb.list[j]) {
			for(int k=i; k<La.length-1; k++) {
				La.list[k] = La.list[k+1];
			}
			La.length--;
		}
		else {
			j++;
		}
	}
	if(i < La.length) {
		La.length = i;
	}
	printf("ȡ��������:\n");
	Lc.list = La.list;
	Lc.length = La.length;
	ListTraverse(Lc);
	
	
	// �������Ա� 
	free(La.list);
	free(Lb.list);
} 






