/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:33:02 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/11 17:09:12 by ssabbaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_struct	*a;
	t_struct	*b;
	
	if (argc < 3)
		printf("invalid number of arguments\n");
	if (nbr_only(argv + 1))
		error_msg(2,"Error\n",1);
	a.size = argc - 1;
	ft_fill_list(&a.stack, a.size, (argv + 1));
	ft_fill_list(&b.stack, 0, 0);
}



