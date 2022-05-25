/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:44:38 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/22 14:55:43 by ssabbaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack_a)
{
	int	i;

	i = 0;
	if (!stack_a)
		return (1);
	while (stack_a->next)
	{
		if (stack_a->val > stack_a->next->val)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	error_msg(int fd, char *msg, int err_code)
{
	write(fd, msg, ft_strlen(msg));
	exit(err_code);
}

int	check_int(char **arguments)
{
	int	i;

	i = 0;
	while (arguments[i])
	{
		if (ft_atoi(arguments[i]) > 2147483647)
			return (0);
		if (ft_atoi(arguments[i]) < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	nbr_only(char *args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if ((args[i] > '9' || args[i] < '0')
			&& args[i] != '+' && args[i] != ' ' && args[i] != '-')
			return (0);
		if (args[i] == '-' || args[i] == '+')
		{
			if (args[i + 1] == '+' || args[i + 1] == '-' || args[i + 2] == '\0')
				return (0);
		}
		i++;
	}
	return (1);
}
