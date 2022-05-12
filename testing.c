#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack{
	int value;
	struct s_stack *next;
}	t_stack;

t_stack *new_node(t_stack **node)
{
	*node = malloc(sizeof(t_stack));
	if (!*node)
		return (NULL);
	return (*node);
}

int main()
{
	t_stack *new;

	new = new_node(&new);
}
