//
// Created by Kishan P Rao on 28/10/18.
//

/**
 * Write a program to convert a given min heap to a max heap
*/

#include <stdio.h>

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void maxHeapify(int a[], int n, int i) {
	int max = i;
	int l = (2 * i) + 1;
	int r = (2 * i) + 2;
	if (l < n && a[l] > a[max]) {
		max = l;
	}
	if (r < n && a[r] > a[max]) {
		max = r;
	}
	if (max != i) {
		swap(&a[i], &a[max]);
		maxHeapify(a, n, max);
	}
}

void minHeapify(int a[], int n, int i) {
	int min = i;
	int l = (2 * i) + 1;
	int r = (2 * i) + 2;
	if (l < n && a[l] < a[min]) {
		min = l;
	}
	if (r < n && a[r] < a[min]) {
		min = r;
	}
	if (min != i) {
		swap(&a[i], &a[min]);
		minHeapify(a, n, min);
	}
}

int main() {
	// int a[] = {1, 2, 2, 3, 4, 5};
	int a[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
	int n = sizeof(a)/sizeof(a[0]); 
	for (int i = (n / 2) - 1; i >= 0; i--) {
		maxHeapify(a, n, i);
	}
	for (int i = 0; i < n; i++) {
		printf("%d\t", a[i]);
	}
	printf("\n");

	for (int i = (n / 2) - 1; i >= 0; i--) {
		minHeapify(a, n, i);
	}
	for (int i = 0; i < n; i++) {
		printf("%d\t", a[i]);
	}
	printf("\n");
	return 0;
}