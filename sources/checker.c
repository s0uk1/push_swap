/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 17:25:35 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/23 16:08:04 by ssabbaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	exec(char *operation)
{
	if (!ft_strcmp(operation, "sa\n"))
		sa(0);
	else if (!ft_strcmp(operation, "sb\n"))
		sb(0);
	else if (!ft_strcmp(operation, "ss\n"))
		ss();
	else if (!ft_strcmp(operation, "pa\n"))
		pa(0);
	else if (!ft_strcmp(operation, "pb\n"))
		pb(0);
	else if (!ft_strcmp(operation, "ra\n"))
		ra(0);
	else if (!ft_strcmp(operation, "rb\n"))
		rb(0);
	else if (!ft_strcmp(operation, "rr\n"))
		rr();
	else if (!ft_strcmp(operation, "rra\n"))
		rra(0);
	else if (!ft_strcmp(operation, "rrb\n"))
		rrb(0);
	else if (!ft_strcmp(operation, "rrr\n"))
		rrr();
	else
		return (0);
	return (1);
}

static void	check(t_stack *a)
{
	char	*lel;
	t_stack	*b;

	b = *get_address('b');
	lel = "kys";
	while (lel)
	{
		lel = get_next_line();
		if (lel)
			if (!exec(lel))
				error_msg(2, "Error\n", 1);
	}
	if (is_sorted(a) && !b)
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
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
	check(a);
	return (0);
}
