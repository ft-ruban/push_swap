/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:16:45 by ldevoude          #+#    #+#             */
/*   Updated: 2025/03/20 16:41:47 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	move_at_top_b_then_push(t_stacks *s)
{
	size_t	counter_a;

	counter_a = s->target_b[0];
	if (counter_a <= s->size_a / 2 && counter_a != 0)
	{
		while (counter_a != 0)
		{
			rotate_a(s, s->size_a);
			counter_a--;
		}
	}
	else if (counter_a > s->size_a / 2 && counter_a != s->size_a + 1)
	{
		while (counter_a != s->size_a)
		{
			reverse_rotate_a(s, s->size_a);
			counter_a++;
		}
	}
	s->target_b[0] = 0;
	push_a(s);
}

void	find_target_a(t_stacks *s, size_t i, size_t min_coordinate,
		size_t target)
{
	while (i <= s->size_a)
	{
		if (s->array_a[i] > s->array_b[0])
		{
			target = 1;
			s->target_b[0] = i;
			while (i <= s->size_a)
			{
				if ((s->array_a[i] < s->array_a[s->target_b[0]])
					&& (s->array_a[i] > s->array_b[0]))
				{
					s->target_b[0] = i;
				}
				i++;
			}
		}
		else
		{
			if (s->array_a[min_coordinate] > s->array_a[i])
				min_coordinate = i;
		}
		i++;
	}
	if ((target == 0))
		s->target_b[0] = min_coordinate;
}
