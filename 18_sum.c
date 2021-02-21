#include <stdio.h>
#include <stdlib.h>

int binSearch(int a[], int l, int r, int key) {
	if (l > r) {
		return -1;
	}
	int m = l + (r - l) / 2;
	if (key > a[m]) {
		return binSearch(a, m + 1, r, key);
	} else if (key < a[m]) {
		return binSearch(a, l, m - 1, key);
	}
	return m;
}
void merge(int a[], int l, int mid, int r) {
	int n = (mid + 1) - l;
	int m = r - mid;
	int p1 = 0, p2 = 0;
	int a1[n], a2[m];
	for (int i = 0; i < n; i++) {
		a1[i] = a[i + l];
	}
	for (int i = 0; i < m; i++) {
		a2[i] = a[i + (mid + 1)];
	}
	int i = l;
	while (p1 < n && p2 < m) {
		if (a1[p1] <= a2[p2]) {
			a[i] = a1[p1++];
		} else {
			a[i] = a2[p2++];
		}
		i++;
	}
	while (p1 < n) {
		a[i++] = a1[p1++];
	}
	while (p2 < m) {
		a[i++] = a2[p2++];
	}
}

void mSortRec(int a[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mSortRec(a, l, m);
		mSortRec(a, m + 1, r);
		merge(a, l, m, r);
	}
}

void mSort(int a[], int n) {
	mSortRec(a, 0, n);
}
int main() {
	int n;
	printf("Enter the number of elements\n");
	scanf("%d", &n);
	int a[n];
	printf("Enter the elements\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	mSort(a, n);
	for (int i = 0; i < n; i++) {
		printf("%d\t", a[i]);
	}
	printf("\n");
	// int x = 12;
	int x;
	printf("Enter x value\n");
	scanf("%d", &x);
	int found = 0;
	for (int i = 0; i < n; i++) {
		int diff = abs(x - a[i]);
		if (binSearch(a, 0, n - 1, diff) != -1) {
			found = 1;
			break;
		}
	}
	if (found) {
		printf("Found sum!\n");
	} else {
		printf("Not found.\n");
	}
	return 0;
}
