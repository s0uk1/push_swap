/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:33:02 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/14 14:06:55 by ssabbaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int *stack_a;
	char *split_str;
	t_stack *a;

	int i = 0;
	if (argc < 2)
		exit(1);
	while (i++ < argc - 1)
		if (argv[i][0] == '\0')
			exit(ft_printf("XD\n"));
	split_str = ft_join_args(argv,argc);
	if (nbr_only(argv + 1))
		error_msg(2,"Error\n",1);
	argv = ft_split(split_str, ' ');
	ft_fill_list(&a, argv);
}
