/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
int compare(char *date1, char *date2);
void add(struct transaction date, transaction *res, int q);

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) 
{
	if (A == NULL || B == NULL)
		return NULL;
	struct transaction *res;
	int p, j, q = 0;
	res = (struct transaction *)malloc(sizeof(transaction));
	int i, date1, month1, year1, count = 0;
	for (i = 0; i < ALen; i++)
	{
		for (j = 0; j < BLen; j++)
		{
			p = compare(A[i].date, B[j].date);
			if (p == 2)
				break;
			else if (p == 0)
			{
				add(A[i], res, q);
				q++;
			}
		}
	}
	if (q == 0)
		return NULL;
	else
		return res;
}

int compare(char *date1, char *date2)
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

void add(struct transaction date, transaction *res,int q)
{
	res[q] = date;
}