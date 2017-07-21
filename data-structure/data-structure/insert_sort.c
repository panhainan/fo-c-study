#include<stdio.h>
typedef int ElemType;

void sheel_insert_sort(ElemType A[], int n) {
	int i, j, dk;
	for (dk = n / 2; dk >= 1; dk = dk / 2) {
		for (i = dk + 1; i <= n; ++i) {
			if (A[i] < A[i - dk]) {
				A[0] = A[i];
				for (j = i - dk; j > 0 && A[0] < A[j]; j -= dk)
					A[j + dk] = A[j];
				A[j + dk] = A[0];
			}
		}
	}
}

void half_insert_sort(ElemType A[], int n) {
	int i, j, low, high, mid;
	for (i = 2; i <= n; i++) {
		A[0] = A[i];
		low = 1;
		high = i - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (A[mid] > A[0])
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (j = i - 1; j >= high + 1; --j)
			A[j + 1] = A[j];
		A[high + 1] = A[0];
	}
}
void direct_insert_sort(ElemType A[],int n) {
	int i, j, compare_times=0;
	for (i = 2; i <= n; i++) {
		compare_times++;
		if (A[i] < A[i - 1]) {
			A[0] = A[i];
			for (j = i - 1; A[0] < A[j]; --j) {
				A[j + 1] = A[j];
				compare_times++;
			}
			A[j + 1] = A[0];
		}
	}
	printf("\ncompare_times=%d\n", compare_times);
};
void main() {
	ElemType arr[9] = {0,21,32,46,40,80,69,90,94}; 
	ElemType arr1[9] = { 0,32,40,21,46,69,94,90,80};
	int length = 8;
	//direct_insert_sort(arr1, length);
	//half_insert_sort(arr1, length);
	sheel_insert_sort(arr1, length);
	for (int i = 1; i <= length; i++){
		printf("%d\t", arr1[i]);
	}
	
};