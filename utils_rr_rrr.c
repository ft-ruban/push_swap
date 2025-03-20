/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rr_rrr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:52:03 by ldevoude          #+#    #+#             */
/*   Updated: 2025/03/20 15:15:40 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	rr_rrr_reset(t_stacks *s)
{
	size_t	i;

	i = 0;
	while (i <= s->size_a)
	{
		s->rr[i] = 0;
		s->rrr[i] = 0;
		i++;
	}
}

void	sub_cost_rrr(t_stacks *s, size_t i, size_t counter_a, size_t counter_b)
{
	while (i <= s->size_a)
	{
		if (s->target_a[i] >= s->size_b / 2)
		{
			counter_a = i;
			counter_b = s->target_a[i];
			while (counter_a != s->size_a && counter_b != s->size_b)
			{
				s->move_cost[i] -= 1;
				s->rrr[i] += 1;
				counter_a++;
				counter_b++;
			}
		}
		i++;
	}
}

size_t	sub_cost_rr(t_stacks *s, size_t i, size_t counter_a, size_t counter_b)
{
	while (i <= s->size_a / 2)
	{
		if ((s->target_a[i] > 0 && s->target_a[i] <= s->size_b / 2)
			|| s->target_a[i] <= i)
		{
			counter_a = i;
			counter_b = s->target_a[i];
			while (counter_a != 0 && counter_b != 0)
			{
				s->move_cost[i] -= 1;
				s->rr[i] += 1;
				counter_a--;
				counter_b--;
			}
		}
		i++;
	}
	return (i);
}

void	sub_cost_rr_rrr(t_stacks *s)
{
	size_t	i;
	size_t	counter_a;
	size_t	counter_b;

	counter_a = 0;
	counter_b = 0;
	i = 1;
	i = sub_cost_rr(s, i, counter_a, counter_b);
	sub_cost_rrr(s, i, counter_a, counter_b);
}
