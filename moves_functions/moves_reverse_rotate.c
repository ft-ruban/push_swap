/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:41:52 by ldevoude          #+#    #+#             */
/*   Updated: 2025/03/20 13:42:11 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	reverse_rotate_a(t_stacks *s, int index_max)
{
	int	buff;
	int	i;

	buff = s->array_a[index_max - 1];
	i = index_max - 1;
	while (i != 0)
	{
		s->array_a[i] = s->array_a[i - 1];
		i--;
	}
	s->array_a[0] = buff;
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_stacks *s, int index_max)
{
	int	buff;
	int	i;

	buff = s->array_b[index_max - 1];
	i = index_max - 1;
	while (i != 0)
	{
		s->array_b[i] = s->array_b[i - 1];
		i--;
	}
	s->array_b[0] = buff;
	ft_printf("rrb\n");
}

void	reverse_rotate_ab(t_stacks *s, int index_max)
{
	int	buff;
	int	i;

	buff = s->array_a[index_max - 1];
	i = index_max - 1;
	while (i != 0)
	{
		s->array_a[i] = s->array_a[i - 1];
		i--;
	}
	s->array_a[0] = buff;
	buff = s->array_b[s->size_b - 1];
	i = s->size_b - 1;
	while (i != 0)
	{
		s->array_b[i] = s->array_b[i - 1];
		i--;
	}
	s->array_b[0] = buff;
	ft_printf("rrr\n");
}
