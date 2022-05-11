#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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

void	ft_fill_list(int **num_list, int ac, char **av)
{
	int		i;

	(*num_list) = (int *)malloc(sizeof(int) * ac);
	i = -1;
	while (++i < ac)
		(*num_list)[i] = atoi(av[i]);
	if (check_duplst(*num_list, ac))
		error_msg(2, "Error dups detected\n", 1);
}

int main(int argc, char **argv)
{
	int *stack_a;
	if (argc < 3)
		printf("invalid number of arguments\n");
	if (nbr_only(argv + 1))
		error_msg(2,"Error\n",1);
	ft_fill_list(&stack_a, argc - 1, (argv + 1));	

}
