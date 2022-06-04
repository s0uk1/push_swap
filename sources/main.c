/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:03:14 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/28 14:34:19 by ssabbaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	main_sort(t_stack **a)
{
	if (stack_size(*a) < 3)
		sort_two(a);
	else if (stack_size(*a) == 3)
		sort_three(a);
	else if (stack_size(*a) <= 5)
		sort_five(a);
	else if (stack_size(*a) >= 100 && stack_size(*a) <= 200)
	{
		push_chunk(a, 1);
		sort_more(get_address('b'));
	}
	else
	{
		push_chunk(a, 0);
		sort_more(get_address('b'));
	}
}

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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**arguments;
	char	*split_str;

	a = NULL;
	b = NULL;
	fetch_address(&a, &b, 34234);
	first_check(argc, argv);
	split_str = ft_join_args(argv, argc);
	if (!nbr_only(split_str))
		return (free(split_str), err_msg(), 0);
	arguments = ft_split(split_str, ' ');
	free(split_str);
	if (!ft_fill_list(arguments, &a) || !check_int(argv))
	{
		free_av(arguments);
		freeall(69);
		return (err_msg(), 0);
	}
	free_av(arguments);
	if (is_sorted(a))
		return (freeall(69), 0);
	main_sort(&a);
	freeall(69);
}
