#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "push_swap.h"

void	error_msg(int fd, char *msg, int err_code)
{
	write(fd, msg, strlen(msg));
	exit(err_code);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	check_num(char *str)
{
	int	i;

	i = -1;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (1);
	return (0);
}

int	nbr_only(char **arr)
{
	int	i;

	i = 0;
	while (i++)
		if (check_num(arr[i]) || (atoi(arr[i]) == -1
					&& strcmp(arr[i], "-1")))
			return (1);
	return (0);
}

int	stack_size(t_stack *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
// 6 2 3 4
void	new_node(t_stack **stack,int val)
{
	t_stack *new;
	t_stack *tmp;
	int c;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->val = val;
	new->next = NULL;
	if(!(*stack))
	{
		*stack = new;
		return;
	}
	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->val == val)
			exit(printf("dup"));
		tmp = tmp->next;
	}
	tmp->next = new;
}

void	put_lst(t_stack *lst)
{
	while (lst)
	{
		printf("%d\n",lst->val);
		lst = lst->next;
	}
}

t_stack **fetch_address(t_stack **a, t_stack **b, int c)
{
	static t_stack	**a_address;
	static t_stack	**b_address;
	static int		k;

	if (!k++)
	{
		a_address = a;
		b_address = b;
	}
	if (c == 'a')
		return (a_address);
	return (b_address);
}

t_stack	*ft_fill_list(char **av)
{
	int		i;
	int 	c;
	t_stack	*a;

	i = 0;
	a = NULL;
	while (av[i])
		new_node(&a, atoi(av[i++]));
	return (a);
}

int    ft_strlen(char *str)
{
	int    i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}


char    *ft_strjoin(char *s1, char *s2)
{
	int        i;
	int        j;
	char    *str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		if (!s1)
			exit(1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!str)
		exit(1);
	i = -1;
	j = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

char    *ft_join_args(char *argv[], int argc)
{
	char    *args;
	int        i;

	i = 1;
	args = NULL;
	while (i < argc)
	{
		args = ft_strjoin(args, argv[i++]);
		args = ft_strjoin(args, " ");
	}
	return (args);
}



static char	**ft_malloc_free(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	ft_get_nbstrs(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*create_sep_word(char *res, char const *s, int j, int word_len)
{
	int	i;

	i = 0;
	while (word_len > 0)
	{
		res[i] = s[j - word_len];
		i++;
		word_len--;
	}
	res[i] = '\0';
	return (res);
}

static char	**ft_split2(char **word, char const *s, char c, int num)
{
	int	i;
	int	j;
	int	word_len;

	i = 0;
	j = 0;
	word_len = 0;
	while (s[j] && i < num)
	{
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
		{
			j++;
			word_len++;
		}
		word[i] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!(word[i]))
			return (ft_malloc_free(word));
		create_sep_word(word[i], s, j, word_len);
		word_len = 0;
		i++;
	}
	word[i] = NULL;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**word;
	int		num;

	if (s == NULL)
		return (NULL);
	num = ft_get_nbstrs(s, c);
	word = (char **)malloc(sizeof(char *) * (num + 1));
	if (!word)
		return (NULL);
	ft_split2(word, s, c, num);
	return (word);
}

t_stack **get_address(int c)
{
	if (c == 'a')
		return (fetch_address(NULL, NULL, 'a'));
	return (fetch_address(NULL, NULL, 'b'));
}

void f()
{
	put_lst(*get_address('a'));
}

void	swap(int *a, int*b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	*sort_tab(int *tab, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		if (tab[i] > tab[j])
		{
			swap(&tab[i], &tab[j]);
			i = 0;
		}
		i++;
	}
	return (tab);
}

int	index_of(int *tab, int val)
{
	int i;

	i = 0;
	while (1)
	{
		if (tab[i] == val)
			return (i);
		i++;
	}
	return (0);
}

t_stack *indexate(t_stack **st, int *tab, int size)
{
	int i;
	t_stack	*tmp;

	i = 0;
	tmp = *st;
	while (tmp)
	{
		tmp->val = index_of(tab , tmp->val);
		tmp = tmp->next;
	}
	return (*st);
}

int	*stack_to_arr(int *tab,t_stack *st)
{
	int	i;
	int len; 

	i = 0;
	len = stack_size(st);
	tab = (int *)malloc(sizeof(int) * len);
	while(st != NULL)
	{
		tab[i++] = st->val;
		st = st->next;
	}
	return (tab);
}

void	del_fnode(t_stack **head)
{
	t_stack *tmp;

	tmp = *head;
	*head = (*head)->next;
	free (tmp);
}

void	del_last(t_stack **head)
{
	t_stack *tmp;
	t_stack *node;

	tmp = *head;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	node = tmp->next;
	tmp->next = NULL;
	free(node);
}


void	lst_addfr(t_stack **head, int val)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));

	new->val = val;
	new->next = *head;
	*head = new;
}
t_stack *rrb_done(t_stack **head)
{
	int val;
	t_stack *current;
	t_stack *next;


	current = *head;
	next = current->next;
	while (next != NULL)
	{
		current = next;
		next = current->next;
	}
	val = current->val;
	del_last(head);
	lst_addfr(head, val);
	return (*head);
}


void	rrb(int flag)
{
	t_stack **st;
	st = get_address('b');
	if (flag)
		printf("rrb\n");
	rrb_done(st);
}



t_stack *rra_done(t_stack **head)
{
	int val;
	t_stack *current;
	t_stack *next;


	current = *head;
	next = current->next;
	while (next != NULL)
	{
		current = next;
		next = current->next;
	}
	val = current->val;
	del_last(head);
	lst_addfr(head, val);
	return (*head);
}


void	rra(int flag)
{
	t_stack **st;
	st = get_address('a');
	if (flag)
		printf("rra\n");
	rra_done(st);
}

void	rrr()
{
	printf("rrr\n");
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

void	pa()
{
	t_stack **st_a;
	t_stack **st_b;

	st_a = get_address('a');
	st_b = get_address('b');
	printf("pa\n");
	pa_done(st_a, st_b);
}


void	pb_done(t_stack **st_a, t_stack **st_b)
{
	int	val;

	val = (*st_a)->val;
	del_fnode(st_a);
	lst_addfr(st_b, val);
}

void	pb()
{
	t_stack **st_a;
	t_stack **st_b;

	st_a = get_address('a');
	st_b = get_address('b');
	printf("pb\n");
	pb_done(st_a, st_b);
}



t_stack	*sb_done(t_stack **head)
{
	int	tmp;

	tmp = (*head)->val;
	(*head)->val = (*head)->next->val;
	(*head)->next->val = tmp;
	return (*head);
}


void	sb(int flag)
{
	t_stack **st;
	st = get_address('b');
	if (flag)
		printf("sb\n");
	*st = sb_done(st);
}




t_stack	*sa_done(t_stack **head)
{
	int	tmp;

	tmp = (*head)->val;
	(*head)->val = (*head)->next->val;
	(*head)->next->val = tmp;
	return (*head);
}


void	sa(int flag)
{
	t_stack **st;
	st = get_address('a');
	if (flag)
		printf("sa\n");
	*st = sa_done(st);
}

void	ss()
{
	printf("ss\n");
	sa(0);
	sb(0);
}

t_stack *rb_done(t_stack **head)
{
	t_stack *current;
	t_stack *tmp;
	t_stack *fml;

	current = *head;
	tmp = current;
	fml = current->next;
	while (current->next != NULL)
	{
		tmp = current;
		current = current->next;
	}
	current->next = (*head);
	(*head)->next = NULL;
	*head = fml;
	return (*head);
}

void	rb(int flag)
{
	t_stack **st;

	st = get_address('b');
	if (flag)
		printf("rb\n");
	*st = rb_done(st);
}


t_stack *ra_done(t_stack **head)
{
	t_stack *current;
	t_stack *tmp;
	t_stack *fml;

	current = *head;
	tmp = current;
	fml = current->next;
	while (current->next != NULL)
	{
		tmp = current;
		current = current->next;
	}
	current->next = (*head);
	(*head)->next = NULL;
	*head = fml;
	return (*head);
}

void	ra(int flag)
{
	t_stack **st;

	st = get_address('a');
	if (flag)
		printf("ra\n");
	*st = ra_done(st);
}


void	rr()
{
	printf("rr\n");
	ra(0);
	rb(0);
}


int get_nnode(int index, t_stack **head)
{
	int c;
	t_stack	*curr;

	c = 0;
	curr = *head;
	while (curr != NULL)
	{
		if (c == index)
			return (curr->val);
		c++;
		curr = curr->next;
	}
	return (0);
}

void	sort_three(t_stack **head)
{
	int f_val;
	int s_val;
	int t_val;

	f_val = get_nnode(0, head);
	s_val = get_nnode(1, head);
	t_val = get_nnode(2, head);
	if (f_val > s_val && s_val < t_val && f_val < t_val)
		sa(1);
	else if (f_val > s_val && s_val > t_val && f_val > t_val)
	{
		sa(1);
		rra(1);
	}
	else if (f_val > s_val && f_val > t_val && s_val < t_val)
		ra(1);
	else if (f_val < s_val && t_val > f_val && s_val > t_val)
	{
		sa(1);
		ra(1);

	}
	else if (f_val > t_val && s_val > f_val && s_val > f_val)
		rra(1);
}

int	check_smallest(t_stack *head)
{
	int min;

	min = head->val;
	while (head != NULL)
	{
		if (head->val < min)
			min = head->val;
		head = head->next;
	}
	return (min);
}

int	indexx_of(t_stack *head, int val)
{
	int i;

	i = 0;
	while (head != NULL)
	{
		if (head->val == val)
			return (i);
		head = head->next;
		i++;
	}
	return (0);
}
void	sv_helper(t_stack **head)
{
	int size;
	int smallest;
	int x;

	if ( indexx_of(*head,smallest) < size / 2 )
		x = 1;
	smallest = check_smallest(*head);
	size = stack_size(*head);
	while ((*head)->val != smallest)
	{
		if (x)
			ra(1);
		else
			rra(1);
	}
	pb();
}
void	sort_five(t_stack **a)
{

	while (stack_size(*a) != 3)
		sv_helper(a);
	sort_three(a);
	while (*get_address('b'))
		pa();
}

void	sort_more(t_stack **a)
{
	while (*get_address('a'))
		sv_helper(a);
	while (*get_address('b'))
		pa();
}


void	divide_into_chunks(t_stack **head, int *hold_first, int *hold_second)
{

	hold_first = -1;
	while (*head)
	{
		if ((*head)->val < 19)
			if (hold_first == -1)
				hold_first = (*head)->val;
		if ((*head)->val < 19)
			hold_second = (*head)->val;
		*head = (*head)->next;
	}
	printf("XD %d\n",hold_second);
}

void	push_chunk(t_stack **head)
{
	int hold_first;
	int hold_second;

	while (*head)
	{
		(divide_into_chunks(*head, &hold_first, &hold_second))

	}
}
void	indexxate(t_stack **a)
{
	t_stack *a_clone;
	t_stack *head;

	head = *get_address('a');
	while (head)
	{
		head->index = 0;
		a_clone = *a;
		while (a_clone)
		{
			if ((head)->val > a_clone->val)
			{
				head->index++;
			}
			a_clone = a_clone->next;
		}
		head = head->next;
	}
	head = *get_address('a');
	while (head)
	{
		head->val = head->index;
		head = head->next;
	}
}

int main(int argc, char **argv)
{
	int	*tab;
	t_stack *a;
	t_stack *b;
	char *split_str;

	a = NULL;
	b = NULL;
	fetch_address(&a, &b, 34234);
	int i = 0;
	if (argc < 2)
		exit(1);
	while (i++ < argc - 1)
		if (argv[i][0] == '\0')
			exit(printf("XD\n"));
	split_str = ft_join_args(argv,argc);
	if (nbr_only(argv + 1))
		error_msg(2,"Error\n",1);
	argv = ft_split(split_str, ' ');
	a = ft_fill_list(argv);	
	tab = stack_to_arr(tab,*get_address('a'));
	tab = sort_tab(tab,4);
	// int j = 0;
	// while(j < 4)
	// {
	// 	printf("%d\n",tab[j]);
	// 	j++;
	// } 
	//f();
	put_lst(*get_address('a'));
	//ra();
	//sa();
	printf("----------\n");
	//	sa(1);
	//printf("a:\n");
	//sort_five(get_address('a'));
	//sort_three(&a);
	indexxate(&a);
	//sort_more(get_address('a'));
	//printf("x %d\n",a->index);
	put_lst(*get_address('a'));

	divide_into_chunks(&a);
	printf("----------\n");
	//	if (stack_size == 2)
	//	{
	//		if (is_sorted)
	//			return ;
	//		else 
	//			sa();
	//	}
	//	if (stack_size == 3)
}
