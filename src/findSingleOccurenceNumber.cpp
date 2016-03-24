/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/
#include<stdio.h>
int * mergesort(int *a, int i, int j);
int * merge(int *a, int i, int j);

int findSingleOccurenceNumber(int *A, int len) 
{
	if (A == NULL)
		return -1;
	int i, p = 0;
	mergesort(A, 0, len - 1);
	for (i = 0; i < len; i = i + 3)
	{
		if (A[i] == A[i + 2])
			p = 0;
		else
		{
			p = i;
			break;
		}
	}
	return A[p];
}

int * mergesort(int *a, int i, int j)
{
	int k, mid = 0;
	if (i >= j)
		return a;
	mid = (i + j) / 2;
	mergesort(a, i, mid);
	mergesort(a, mid + 1, j);
	merge(a, i, j);
	return a;
}
int * merge(int *a, int i, int j)
{
	int k, b[100], mid, l, p;
	p = i;
	mid = (i + j) / 2;
	k = mid + 1;
	l = i;
	while (i <= mid && k <= j)
	{
		if (a[i] >= a[k])
			b[l++] = a[i++];
		else
			b[l++] = a[k++];
	}
	if (i > mid)
	{
		for (; k <= j;)
			b[l++] = a[k++];
	}
	else if (k > j)
	{
		for (; i <= mid;)
			b[l++] = a[i++];
	}
	for (l = p; l <= j; l++)
		a[l] = b[l];
	return a;
}