/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:27:05 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/09 19:01:16 by ssabbaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_node {
	int val;
	int index;
	struct s_node *next;
	struct s_node *prev;
}	t_node;


int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	check_dup(int num, int *num_list, int size)
{
	int		i;
	int		check;

	check = 0;
	i = -1;
	while (++i < size)
	{
		if (num_list[i] == num)
		{
			check++;
			if (check > 1)
				return (1);
		}
	}
	return (0);
}

int	check_num(char *str)
{
	int	i;

	i = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		return (0);
	}
}

void	error_msg(int fd, char *msg, int err_code)
{
	write(fd, msg, ft_strlen(msg));
	exit(err_code);
}

int nbr_only(char **arg)
{
	int i;
	
	i = -1;
	while (arg[++i])
	{
		if (ft_atoi(arg[i]) == -1 || check_num(arg[i]))
			return (1);
		return (0);
	}
}

int main(int argc, char **argv)
{
	if (argc < 3)
		return (0);
	if (!nbr_only(argv + 1))
		error_msg(2,"Error",1);

}
