/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_tools_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 13:27:16 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/28 13:27:58 by ssabbaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_av(char **arguments)
{
	int	i;

	i = 0;
	while (arguments[i])
	{
		free(arguments[i]);
		i++;
	}
	free(arguments);
}

void	first_check(int argc, char **av)
{
	int	i;

	i = 0;
	if (argc < 2)
		exit(1);
	while (i++ < argc - 1)
		if (av[i][0] == '\0')
			err_msg();
}
