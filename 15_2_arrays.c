//
// Created by Kishan P Rao on 28/10/18.
//

/**
 * Write a program that will take two arrays as input from the user, sort them using the insertion sort and then merge them into single resultant sorted array. The merging should be done only after sorting and the merging should be done in optimal fashion
*/

#include <stdio.h>

void insSort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

void merge(int a1[], int a2[], int res[], int n, int m) {
	int size = n + m;
	int p1 = 0, p2 = 0;
	int i = 0;
	while (p1 < n && p2 < m) {
		if (a1[p1] <= a2[p2]) {
			res[i] = a1[p1++];
		} else {
			res[i] = a2[p2++];
		}
		i++;
	}
	while (p1 < n) {
		res[i++] = a1[p1++];
	}
	while (p2 < m) {
		res[i++] = a2[p2++];
	}
}

int main() {
	int m, n;
	scanf("%d", &n);
	scanf("%d", &m);
	int a1[n], a2[m], res[n + m];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a1[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &a2[i]);
	}
	insSort(a1, n);
	insSort(a2, m);
	for (int i = 0; i < n; i++) {
		printf("%d\t", a1[i]);
	}
	printf("\n");
	for (int i = 0; i < m; i++) {
		printf("%d\t", a2[i]);
	}
	printf("\n");
	merge(a1, a2, res, n, m);
	for (int i = 0; i < n + m; i++) {
		printf("%d\t", res[i]);
	}
	printf("\n");
	return 0;
}