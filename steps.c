/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:08:28 by ldevoude          #+#    #+#             */
/*   Updated: 2025/03/20 16:04:21 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	step_three(t_stacks *s)
{
	size_t	cheapest;

	while (s->size_b != 0)
	{
		find_target_a(s);
		move_at_top_b_then_push(s);
	}
	cheapest = cheapest_number(s);
	if (cheapest <= s->size_a / 2)
	{
		while (cheapest != 0)
		{
			rotate_a(s, s->size_a);
			cheapest--;
		}
	}
	else
	{
		while (cheapest != s->size_a)
		{
			reverse_rotate_a(s, s->size_a);
			cheapest++;
		}
	}
}

void	step_two(t_stacks *s)
{
	size_t	cheapest;

	while (s->size_a != 3)
	{
		assign_target_a(s, 0, 0, TRUE);
		assign_cost_a(s);
		sub_cost_rr_rrr(s);
		cheapest = cheapest_move_cost(s);
		move_at_top_then_push(s, cheapest);
		rr_rrr_reset(s);
		target_reset(s);
	}
	sort_three(s);
	after_debug(s);
	step_three(s);
}

void	step_one(t_stacks *s)
{
	if (s->size_a == 2)
	{
		if (s->array_a[0] > s->array_a[1])
			swap_a(s);
		exit(0);
	}
	else if (s->size_a == 3)
		sort_three(s);
	else if (s->size_a == 4)
	{
		push_b(s);
		sort_three(s);
	}
	else
	{
		push_b(s);
		push_b(s);
		step_two(s);
	}
}

//TODO check if at some point it can fail
int	steps_push_swap(t_stacks *stacks)
{
	before_debug(stacks);
	step_one(stacks);
	after_debug(stacks);
	free_struct(stacks);
	exit(0);
}
