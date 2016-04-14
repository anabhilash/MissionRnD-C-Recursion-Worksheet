/*

	You have N steps to climb .
	You can either take one step or two steps at a time .
	You need to find the total number of ways you can reach N steps .

	Example : For N=4 , You can either reach 4 steps in following ways
	->1111
	->112
	->121
	->211
	->22
	So total number of ways is 5

	Input : A Integer denoting N (number of steps )
	Output : Return an Integer denoting the number of ways to reach N steps

	Example Input : get_steps(5)
	Example Output : Returns 8

	Note : Test Cases would be small <25.

*/
#include "stdafx.h"

void countN(int sum, int temp, int *count)
{
	if (temp == sum && sum != 0)
		(*count) = (*count) + 1;
	else
	{
		if (sum - temp > 2)
		{
			countN(sum, temp + 1, count);
			countN(sum, temp + 2, count);
		}
		else if (!(sum - temp ^ 1))
		{
			(*count) = (*count) + 1;
		}
		else if (!(sum - temp ^ 2))
		{
			(*count) = (*count) + 2;
		}

	}
}
int  get_steps(int s)
{
	
	int count = 0;
	countN(s, 0, &count);
	return count;
}