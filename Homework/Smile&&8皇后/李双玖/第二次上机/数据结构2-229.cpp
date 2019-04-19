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
	printf("������A��B��C���Ա���Ԫ�ظ�����");
	scanf("%d%d%d", &La.length, &Lb.length, &Lc.length);
	La.list = (int*)malloc(sizeof(int) * La.length);
	Lb.list = (int*)malloc(sizeof(int) * Lb.length);
	Lc.list = (int*)malloc(sizeof(int) * Lc.length);
	
	printf("\n�������������A���Ա��е����ݣ�");
	for(int i=0; i<La.length; i++) {
		scanf("%d", &La.list[i]);
	}
	//ListTraverse(La);
	
	printf("�������������B���Ա��е����ݣ�");
	for(int i=0; i<Lb.length; i++) {
		scanf("%d", &Lb.list[i]);
	}
	//ListTraverse(Lb);
	
	printf("�������������C���Ա��е����ݣ�");
	for(int i=0; i<Lc.length; i++) {
		scanf("%d", &Lc.list[i]);
	}
	//ListTraverse(Lc);
	
	
	// ��B��Cȡ����������������B�� 
	int i=0, j=0;
	while(i<Lb.length && j<Lc.length) {
		if(Lb.list[i] == Lc.list[j]) {
			i++;
			j++; 
		} 
		else if(Lb.list[i] < Lc.list[j]) {
			for(int k=i; k<Lb.length-1; k++) {
				Lb.list[k] = Lb.list[k+1];
			}
			Lb.length--;
		}
		else {
			j++;
		}
	}
	if(i < Lb.length) {
		Lb.length = i;
	}
	printf("B��Cȡ��������:\n");
	ListTraverse(Lb);
	
	
	// ��A�У���A��B�Ľ���ɾȥ 
	i=0, j=0;
	while(i<La.length && j<Lb.length) {
		if(La.list[i] == Lb.list[j]) {
			for(int k=i; k<La.length-1; k++) {
				La.list[k] = La.list[k+1];
			}
			La.length--;
		} 
		else if(La.list[i] < Lb.list[j]) {
			i++;
		}
		else {
			j++;
		}
	}
	printf("��A����ɾȥA��B��������:\n");
	ListTraverse(La);
	
	
	// �������Ա� 
	free(La.list);
	free(Lb.list);
	free(Lc.list);
} 






