/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:24:05 by ldevoude          #+#    #+#             */
/*   Updated: 2025/03/20 16:24:05 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int	find_target(t_stacks *s, size_t i, size_t j, int smallest_number_a)
{
	while (j < s->size_b)
	{
		if (s->array_b[j] < s->array_a[i] || (s->array_b[j] <= s->array_a[i]
				&& smallest_number_a == TRUE))
		{
			if (!(smallest_number_a == FALSE
					&& s->array_b[j] < s->array_b[s->target_a[i]]))
			{
				smallest_number_a = FALSE;
				s->target_a[i] = j;
			}
			else if (smallest_number_a == TRUE
				&& s->array_b[j] > s->array_b[s->target_a[i]])
				s->target_a[i] = j;
		}
		j++;
	}
	return (smallest_number_a);
}

void	assign_target_a(t_stacks *s, size_t i, size_t j, int smallest_number_a)
{
	size_t	biggest_number_b;

	biggest_number_b = biggest_number_array(s);
	while (i <= s->size_a)
	{
		j = 0;
		smallest_number_a = TRUE;
		smallest_number_a = find_target(s, i, j, smallest_number_a);
		if (smallest_number_a == TRUE)
			s->target_a[i] = biggest_number_b;
		i++;
	}
}

size_t	biggest_number_array(t_stacks *s)
{
	size_t	i;
	size_t	result;

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
		if (s->array_a[0] > s->array_a[1])
			rotate_a(s, s->size_a);
		else
		{
			swap_a(s);
			rotate_a(s, s->size_a);
		}
	}
	if (s->array_a[0] > s->array_a[1])
		swap_a(s);
}
