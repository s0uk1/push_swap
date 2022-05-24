/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:03:14 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/24 11:24:05 by ssabbaji         ###   ########.fr       */
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
	else if (stack_size(*a) >= 100 || stack_size(*a) <= 200)
	{
		push_chunk(a, 1);
		sort_more(get_address('b'));
	}
	else if (stack_size(*a) > 200)
	{
		push_chunk(a, 0);
		sort_more(get_address('b'));
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*a;
	t_stack	*b;
	char	*split_str;

	i = 0;
	a = NULL;
	b = NULL;
	fetch_address(&a, &b, 34234);
	if (argc < 2)
		exit(1);
	while (i++ < argc - 1)
		if (argv[i][0] == '\0')
			error_msg(2, "Error\n", 1);
	split_str = ft_join_args(argv, argc);
	if (!nbr_only(split_str))
		return (0);
	argv = ft_split(split_str, ' ');
	free(split_str);
	a = ft_fill_list(argv);
	if (is_sorted(a))
		return (0);
	main_sort(&a);
}
