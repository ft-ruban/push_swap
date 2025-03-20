/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:49:33 by ldevoude          #+#    #+#             */
/*   Updated: 2025/03/20 13:50:09 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	push_a(t_stacks *s)
{
	int		buff_target;
	size_t	i;

	s->size_a++;
	buff_target = s->array_b[0];
	i = 0;
	while (i < s->size_b - 1)
	{
		s->array_b[i] = s->array_b[i + 1];
		i++;
	}
	s->array_b[i] = 0;
	s->array_a[s->size_a] = s->array_a[s->size_a - 1];
	i = s->size_a - 1;
	while (i != 0)
	{
		s->array_a[i] = s->array_a[i - 1];
		i--;
	}
	s->array_a[0] = buff_target;
	s->size_b--;
	ft_printf("pa\n");
}

void	push_b(t_stacks *s)
{
	int		buff_target;
	size_t	i;

	s->size_b++;
	buff_target = s->array_a[0];
	i = 0;
	while (i < s->size_a - 1)
	{
		s->array_a[i] = s->array_a[i + 1];
		i++;
	}
	s->array_a[i] = 0;
	s->array_b[s->size_b] = s->array_b[s->size_b - 1];
	i = s->size_b - 1;
	while (i != 0)
	{
		s->array_b[i] = s->array_b[i - 1];
		i--;
	}
	s->array_b[0] = buff_target;
	s->size_a--;
	ft_printf("pb\n");
}
