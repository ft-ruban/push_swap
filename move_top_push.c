/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_top_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:19:36 by ldevoude          #+#    #+#             */
/*   Updated: 2025/03/20 16:48:59 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	move_top_push_b(t_stacks *s, size_t counter_b)
{
	if (counter_b <= s->size_b / 2 && counter_b != 0)
	{
		while (counter_b != 0)
		{
			rotate_b(s);
			counter_b--;
		}
	}
	else if (counter_b > s->size_b / 2 && counter_b != s->size_b + 1)
	{
		while (counter_b != s->size_b)
		{
			reverse_rotate_b(s, s->size_b);
			counter_b++;
		}
	}
}

void	move_top_push_a(t_stacks *s, size_t counter_a)
{
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
}

void	move_at_top_then_push(t_stacks *s, size_t cheapest)
{
	size_t	counter_a;
	size_t	counter_b;

	counter_a = cheapest;
	counter_b = s->target_a[cheapest];
	while (s->rr[cheapest] != 0)
	{
		rotate_ab(s, s->size_a);
		s->rr[cheapest] -= 1;
		counter_a--;
		counter_b--;
	}
	while (s->rrr[cheapest] != 0)
	{
		reverse_rotate_ab(s, s->size_a);
		s->rrr[cheapest] -= 1;
		counter_a++;
		counter_b++;
	}
	if (counter_a != 0 && counter_a != s->size_a + 1)
		move_top_push_a(s, counter_a);
	if (counter_b != 0 && counter_b != s->size_b + 1)
		move_top_push_b(s, counter_b);
	push_b(s);
}
