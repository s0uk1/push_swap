#include <stdio.h>
#include <stdlib.h>

int get_pos(int *arr, int n, int size)
{
	int i;
	int index;

	i = -1;
	while (++i < size)
	{
		if (n == arr[i])
			index = i;
	}
	return (index);
}


int	checkdup(int *arr, int n, int size)
{
	int i;
	int dup;

	i = -1;
	dup = 0;
	while (++i < size)
	{
		if (arr[i] == n)
		{
			if (dup)
				return (1);
			dup++;	
		}
	}
	return (0);
}

int	find(int *arr, int size)
{
	int n;
	int i;

	n = arr[0];
	i = -1;
	while (++i < size)
		if (n > arr[i])
			n = arr[i];
	return (n);
}

int main()
{
	int tab[] = {1, 2 , 3 , 5, 6};
	//int index = get_pos(tab, 3, 4);
	//int index = find(tab, 4);
	int i = -1;
	int flag = 0;
	flag = checkdup(tab, 4, 5);
	printf("%d\n",flag);
}
