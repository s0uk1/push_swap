#include "../includes/push_swap.h"
t_stack	**fetch_address(t_stack **a, t_stack **b, int c)
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

t_stack	**get_address(int c)
{
	if (c == 'a')
		return (fetch_address(NULL, NULL, 'a'));
	return (fetch_address(NULL, NULL, 'b'));
}
