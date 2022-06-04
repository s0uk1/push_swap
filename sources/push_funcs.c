/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:35:03 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/23 16:10:58 by ssabbaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrr(int flag)
{
	if (flag)
		ft_putstr("rrr\n");
	rra(0);
	rrb(0);
}

void	pa_done(t_stack **st_a, t_stack **st_b)
{
	int	val;

	val = (*st_b)->val;
	del_fnode(st_b);
	lst_addfr(st_a, val);
}

void	pa(int flag)
{
	t_stack	**st_a;
	t_stack	**st_b;

	st_a = get_address('a');
	st_b = get_address('b');
	if (!*st_b)
		return ;
	if (flag)
		ft_putstr("pa\n");
	pa_done(st_a, st_b);
}

void	pb_done(t_stack **st_a, t_stack **st_b)
{
	int	val;

	val = (*st_a)->val;
	del_fnode(st_a);
	lst_addfr(st_b, val);
}

void	pb(int flag)
{
	t_stack	**st_a;
	t_stack	**st_b;

	st_a = get_address('a');
	st_b = get_address('b');
	if (!*st_a)
		return ;
	if (flag)
		ft_putstr("pb\n");
	pb_done(st_a, st_b);
}
