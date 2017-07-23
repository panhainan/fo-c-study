#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
//πÈ≤¢≈≈–Ú
merge(ElemType A[], int low, int mid, int high,int length) {
	ElemType *B = (ElemType *)malloc((length + 1) * sizeof(ElemType));
	int i, j, k;
	for (k = low; k <= high; k++) {
		B[k] = A[k];
	}
	for (i = low, j = mid + 1, k = i; i <= mid&&j <= high; k++) {
		if (B[i] <= B[j])
			A[k] = B[i++];
		else
			A[k] = B[j++];
	}
	while (i <= mid)
		A[k++] = B[i++];
	while (j <= high)
		A[k++] = B[j++];

	
}
void merge_sort(ElemType A[], int low, int high,int length) {
	if (low < high) {
		int mid = (low + high) / 2;
		merge_sort(A, low, mid,  length);
		merge_sort(A, mid + 1, high,  length);
		merge(A, low, mid, high, length);
		for (int i = 1; i <= length; i++) {
			printf("%d, ", A[i]);
		}
		printf("\n");
	}
}
void main() {
	int length = 7;
	ElemType E[8] = { 0,49,38,65,97,76,13,27 };
	for (int i = 1; i <= length; i++) {
		printf("%d, ", E[i]);
	}
	printf("(≈≈–Ú«∞£©\n");
	merge_sort(E, 1, 7, 7);
	for (int i = 1; i <= length; i++) {
		printf("%d, ", E[i]);
	}
	printf("(≈≈–Ú∫Û£©\n");
}