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

void	ft_fill_list(int **num_list, char **av)
{
	int		i;
	int 	c;
	t_stack	*a;

	i = 0;
	a = NULL;
	while (av[i])
		new_node(&a, atoi(av[i++]));
	c = stack_size(a);
	printf("%d",c);
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




int main(int argc, char **argv)
{
	int *stack_a;
	char *split_str;
	t_stack *a;

	// char **arr = ft_split("5", ' ');
	// while (*arr)
	// 	printf("%s\n", *arr++);
	int i = 0;
	if (argc < 2)
		exit(1);
	while (i++ < argc - 1)
		if (argv[i][0] == '\0')
			exit(printf("XD\n"));
	split_str = ft_join_args(argv,argc);
	if (nbr_only(argv + 1))
		error_msg(2,"Error\n",1);
	printf("%s\n", split_str);
	argv = ft_split(split_str, ' ');
	ft_fill_list(&stack_a,  argv);	

}
