/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:27:05 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/22 17:49:34 by ssabbaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define BUFFER_SIZE 10

typedef struct s_stack{
	int				val;
	int				index;
	struct s_stack	*next;
}	t_stack;

// fetching stack addresses 

t_stack	**get_address(int c);
t_stack	**fetch_address(t_stack **a, t_stack **b, int c);
int		free_everything(int XD);

// finding indexes 

void	indexate(t_stack **a);
int		indexx_of(t_stack *head, int val);

// sorting small number of args

void	sort_three(t_stack **head);
int		get_nnode(int index, t_stack **head);
void	sv_helper(t_stack **head);
void	sort_five(t_stack **a);
void	sort_two(t_stack **a);

// parsing tools

void	error_msg(int fd, char *msg, int err_code);
int		check_num(char *str);
int		ft_isdigit(int c);
int		nbr_only(char *args);
int		check_int(char **arguments);
int		is_sorted(t_stack *stack_a);
// stack to linked list

t_stack	*ft_fill_list(char **av);
void	new_node(t_stack **stack, int val);

// dunno what to name these even

int		stack_size(t_stack *lst);
int		check_biggest(t_stack *head);
int		check_smallest(t_stack *head);

// swapping functions 

t_stack	*sb_done(t_stack **head);
t_stack	*sa_done(t_stack **head);
void	sb(int flag);
void	sa(int flag);
void	ss(void);
t_stack	*rra_done(t_stack **head);
t_stack	*rb_done(t_stack **head);
t_stack	*ra_done(t_stack **head);
t_stack	*rrb_done(t_stack **head);
void	rb(int flag);
void	ra(int flag);
void	rr(void);
void	rrb(int flag);
void	rra(int flag);

// push functions with rrr included 

void	pa_done(t_stack **st_a, t_stack **st_b);
void	pb_done(t_stack **st_a, t_stack **st_b);
void	pa(void);
void	pb(void);
void	rrr(void);

// linked list manipulation 

void	lst_addfr(t_stack **head, int val);
void	del_fnode(t_stack **head);
void	del_last(t_stack **head);

// join args

int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_join_args(char *argv[], int argc);

// split

char	**ft_split(char const *s, char c);

// sort more

void	sm_helper(t_stack **head);
void	sort_more(t_stack **b);
void	push_chunk(t_stack **head, int div);
void	push_smol(t_stack **head, int hold, int chonk, int div);
int		hold_vals(t_stack *iter, int *hold_first, int *hold_second, int div);

// additional tools

int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(const char *str);
int		ft_putstr(char *str);
char	*ft_strdup(char *str);
char	*get_next_line(int fd);

#endif
