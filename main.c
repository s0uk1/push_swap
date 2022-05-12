/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:33:02 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/12 14:17:11 by ssabbaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_struct	*stack_a;
	
	if (argc < 3)
		printf("invalid number of arguments\n");
	if (nbr_only(argv + 1))
		error_msg(2,"Error\n",1);
	if (is_sorted(stack_a))
		ft_putstr("The stack is already sorted\n");
	
}
