/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<stdlib.h>
bool stringComp(char *date, char *temp);

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) 
{
	/*int i, date1, month1, year1, count = 0;
	int *datesArr = (int *)malloc(sizeof(int)* len);
	int *monthsArr = (int *)malloc(sizeof(int)* len);
	int *yearsArr = (int *)malloc(sizeof(int)* len);
	date1 = (date[0] - '0') * 10 + (date[1] - '0');
	month1 = (date[3] - '0') * 10 + (date[4] - '0');
	year1 = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + date[9] - '0';
	for (i = 0; i < len; i++)
	{
		char *temp = Arr[i].date;
		datesArr[i] = (temp[0] - '0') * 10 + (temp[1] - '0');
		monthsArr[i] = (temp[3] - '0') * 10 + (temp[4] - '0');
		yearsArr[i] = (temp[6] - '0') * 1000 + (temp[7] - '0') * 100 + (temp[8] - '0') * 10 + temp[9] - '0';
	}
	for (i = 0; i < len; i++)
	{
		if (year1 - yearsArr[i] < 0)
			count++;
		else if (year1 - yearsArr[i] == 0)
		{
			if (month1 - monthsArr[i] < 0)
				count++;
			else if (month1 - monthsArr[i] == 0)
			{
				if (date1 - datesArr[i] < 0)
					count++;
			}
		}
	}
	return count;*/
	int i = 0, date1, month1, year1, count = 0;
	int *datesArr = (int *)malloc(sizeof(int)* len);
	int *monthsArr = (int *)malloc(sizeof(int)* len);
	int *yearsArr = (int *)malloc(sizeof(int)* len);
	date1 = (date[0] - '0') * 10 + (date[1] - '0');
	month1 = (date[3] - '0') * 10 + (date[4] - '0');
	year1 = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + date[9] - '0';
	for (i = 0; i < len; i++)
	{
		char *temp = Arr[i].date;
		datesArr[i] = (temp[0] - '0') * 10 + (temp[1] - '0');
		monthsArr[i] = (temp[3] - '0') * 10 + (temp[4] - '0');
		yearsArr[i] = (temp[6] - '0') * 1000 + (temp[7] - '0') * 100 + (temp[8] - '0') * 10 + temp[9] - '0';
	}
	i = 0;
	while (year1 > yearsArr[i])
	{
		i++;
		if (i > len)
			return 0;
	}
	if (year1 == yearsArr[i])
	{
		while (month1 > monthsArr[i])
			i++;
	}
	if (month1 == monthsArr[i])
	{
		while (date1 > datesArr[i])
			i++;
	}
	if ((i == 0) && stringComp(date,Arr[i+1].date))
	{
		return len - 1;
	}
	else if (i == 0)
		return 0;
	else
		return len - i - 1;
}

bool stringComp(char *date, char *temp)
{
	int len1, len2, k = 0;
	for (len1 = 0; date[len1] != '\0'; len1++);
	for (len2 = 0; temp[len2] != '\0'; len2++);
	for (int i = 0; i < len1; i++)
	{
		if (date[i] == temp[i])
			k++;
	}
	if (k == len1 && k == len2)
		return false;
	else
		return true;
}