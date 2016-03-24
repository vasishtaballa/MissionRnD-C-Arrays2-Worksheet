/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
int Compare(char *date1, char *date2);

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen)
{
	if (A == NULL || B == NULL)
		return NULL;
	struct transaction *result = (struct transaction *)malloc(sizeof(transaction)*(ALen + BLen));
	int i = 0, j = 0, k = 0, res;
	while (i < ALen && j < BLen)
	{
		res = Compare(A[i].date, B[j].date);
		if (res == 1)
		{
			result[k] = B[j];
			j++;
		}
		else
		{
			result[k] = A[i];
			i++;
		}
		k++;
	}
	if (i >= BLen)
	{
		while (j < BLen)
		{
			result[k] = B[j];
			j++;
			k++;
		}
	}
	if (j >= ALen)
	{
		while (i < ALen)
		{
			result[k] = A[i];
			i++;
			k++;
		}
	}
	return result;
}

int Compare(char *date1, char *date2)
{
	int i;
	for (i = 6; i <= 9; i++)
	{
		if (date1[i] > date2[i])
			return 1;
		else if (date1[i] < date2[i])
			return 2;
	}
	for (i = 3; i <= 4; i++)
	{
		if (date1[i] > date2[i])
			return 1;
		else if (date1[i] < date2[i])
			return 2;
	}
	for (i = 0; i <= 1; i++)
	{
		if (date1[i] > date2[i])
			return 1;
		else if (date1[i] < date2[i])
			return 2;
	}
	return 0;
}