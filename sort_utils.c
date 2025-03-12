#include "header/push_swap.h"
//working in theory
size_t biggest_number_array(t_stacks *s)
{
	size_t i;
	size_t result;

	result = 0;
	i = 1;
	while (i < s->size_b)
	{
		if (s->array_b[result] < s->array_b[i])
			result = i;
		i++;
	}
	return (result);
}

void	sort_three(t_stacks *s)
{
	if (s->array_a[2] < s->array_a[0] || s->array_a[2] < s->array_a[1])
	{
		printf("OUI\n");
		if (s->array_a[0] > s->array_a[1])
			rotate_a(s, s->size_a - 1);
		else
		{
			swap_a(s);
			rotate_a(s, s->size_a - 1);
		}
	}
	if (s->array_a[0] > s->array_a[1])
		swap_a(s);
}
