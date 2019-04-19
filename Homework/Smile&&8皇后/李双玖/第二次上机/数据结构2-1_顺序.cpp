#include<stdio.h>
#include<stdlib.h>

int main() {
	
	int n = 0;
	int *L = (int*)malloc(sizeof(int)*100);

	for(int i=0; i<10; i++)
	{
		L[i]=rand()%10; 
	} printf("初始化前：\n");
	for(int i=0; i<10; i++) printf("%d ", L[i]);
	int j = 0;
	int temp = 0;
	for(int i=1; i<10; i++) {
		for(j=i; j>0 && L[j-1] > L[j]; j--) {
			temp = L[j-1];
			L[j-1] = L[j];
			L[j] = temp;
		}
	}
	printf("\n初始化后：\n");
	for(int i=0; i<10; i++) printf("%d ", L[i]);
	free(L);
} 
