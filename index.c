int 	fet_index(int *tab, int val, int size)
{
	int i;
	
	i = 0;
	while (i < size)
	{
		if (tab[i] == val)
			return (i);
		i++;
	}
	return (0);
}


// t_stack	*index_of(t_stack *st)
// {
// 	while (st != NULL)
// 	{
// 		st->index = fet_index(st->val);
// 		st = st->next;
// 	}

// }


t_stack *indexate(t_stack *st, int *tab, int size)
{
	int i;

	i = 0;
	while (i <  size)
	{
		st->val = tab[i++];
		st = st->next;
	}
	// while (st != NULL)
	// {
	// 	st->index = fet_index(tab ,st->val,size);
	// 	st = st->next;
	// 	printf("owo %d\n",st->val);
	// }
	return (st);
}

