/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:45:27 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/10 18:51:41 by ssabbaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	arraymin_pos(int *list, int size)
{
	int i;
	int j;
	int pos;

	i = -1;
	pos = 0;
	j = list[0];
	while (++i < size)
	{
		if (j > list[i])
			pos = i;
	}
	return (pos);
}

int arraymax_pos(int *list, int size)
{
	int i;
	int j;
	int pos;

	i = -1;
	pos = 0;
	j = list[0];
	while (++i < size)
	{
		if (j < list[i])
		{
			j = list[i];
			pos = i;
		}
	}
	return (pos);
}

int	arrmax(int *list, int size)
{
	int n;
	int i;

	i = -1;
	n = arr[0];
	while (++i < size)
	{
		if (n < list[i])
			n = list[i];
	}
	return (n);
}

int	arrmin(int *list, int size)
{
	int n;
	int i;

	i = -1;
	n = arr[0];
	while (++i < size)
	{
		if (n > list[i])
			n = list[i];
	}
	return (n);
}

int	get_pos(int *list, int n, int size)
{
	int i;
	int index;
	
	i = -1;
	while (++i < size)
	{
		if (n == list[i])
			index = i;
	}	
	return (index);
}

int	is_sorted(int *stack, int size)
{
	int i;

	i = 0;
	while(i < size - 1)
	{
		if (stack[i] < stack[i + 1])
			i++;
		else 
			return (0);
	}
	return (1);
}


int	is_revsorted(int *stack, int size)
{
	int i;

	i = 0;
	while(i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			i++;
		else 
			return (0);
	}
	return (1);
}

int check_fordup(int *list, int n, int size)
{
	int i;
	int dup;

	i = -1;
	j = 0;
	while (++i < size)
	{
		j = i + 1;
		if (list[i] == list[j])
			return (1);
	}
	return (0);
}
