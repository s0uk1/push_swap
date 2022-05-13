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

	i = -1;
	while (arr[++i])
		if (check_num(arr[i]) || (atoi(arr[i]) == -1
				&& strcmp(arr[i], "-1")))
			return (1);
	return (0);
}

int	check_fordup(int *arr, int n, int size)
{
	int	i;
	int	dup;

	i = -1;
	dup = 0;
	while (++i < size)
	{
		if (arr[i] == n)
		{
			if (dup)
				return (1);
			dup++;
		}
	}
	return (0);
}
int	check_duplst(int *arr, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (check_fordup(arr, arr[i], size))
			return (1);
	return (0);
}

void	ft_first_check(int **num_list, int ac, char **av)
{
	int		i;

	(*num_list) = (int *)malloc(sizeof(int) * ac);
	i = -1;
	while (++i < ac)
		(*num_list)[i] = atoi(av[i]);
	if (check_duplst(*num_list, ac))
		error_msg(2, "Error dups detected\n", 1);
}

void	new_stack(t_stack **a, int *num_list)
{
	int	i;
	t_stack	*save;
	t_stack *save_clone;

	i = 0;
	while (arguments[i])
	{
		*a = stack_addback(*a, num_list[i]);
		i++;
	}
	save = *a;
	while (save)
	{
		save_clone = *a;
		while (save_clone)
		{
			if (save->data > save_clone->data)
				save_clone->index++;
			save_clone = save_clone->next;
		}
		save = save->next;
	}
}

int main(int argc, char **argv)
{
	int *num_list;
	t_stack *stack_a;

	argv = ft_aplit(argv, ' ');
	if (argc <= 1)
		printf("invalid number of arguments\n");
	if (nbr_only(argv + 1))
		error_msg(2,"Error\n",1);
	ft_this_check(&num_list, argc - 1, (argv + 1));
	new_stack(&stack_a);
}

int	main(int argc, char *argv[])
{
	char	**arguments;
	char	*args;
	t_stack	*stack_a;

	stack_a = NULL;
	ft_count_args(argc);
	args = ft_join_args(argv, argc);
	if (!ft_check_not_number(args))
		return (0);
	arguments = ft_split(args, ' ');
	if (!ft_check_int(arguments))
		return (0);
	free(args);
	ft_create_stack(&stack_a, arguments);
	free_split(arguments);
	if (!ft_check_double(&stack_a) || !ft_check_sorted(&stack_a))
		return (0);
	ft_sort(&stack_a);
	ft_free(&stack_a);
	return (0);
}
