/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:27:05 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/09 16:29:11 by ssabbaji         ###   ########.fr       */
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

int valid_num(char **arg)
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
		error_msg("Error");
	if (!valid_num(argv + 1))
		error_msg("Error");

}
