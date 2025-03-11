#include "header/push_swap.h"

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