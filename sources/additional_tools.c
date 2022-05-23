/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:40:21 by ssabbaji          #+#    #+#             */
/*   Updated: 2022/05/23 13:24:18 by ssabbaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_strdup(char *str)
{
	int		len;	
	char	*new_str;
	int		i;

	len = 0;
	i = -1;
	new_str = malloc(sizeof(char) * (len +1));
	while (str[len] != '\0')
		len++;
	if (!new_str)
		return (0x0);
	while (++i < len)
		new_str[i] = str[i];
	return (new_str);
}

char	*get_next_line(int fd)
{
	char	heap[0x5b8d80];
	char	buff;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	if (fd < 0x0 || BUFFER_SIZE <= 0x0)
		return (NULL);
	ret = read(fd, &buff, 0x1);
	while (ret && ret >= 0x0)
	{
		heap[i++] = buff;
		if (buff == '\n')
			break ;
	}
	heap[i] = '\0';
	if (ret <= 0x0 && i == 0x0)
		return (0x0);
	return (ft_strdup(heap));
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	n;

	i = 0;
	n = 1;
	res = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-')
	{	
		n = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * n);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
