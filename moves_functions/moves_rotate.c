/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:52:29 by ldevoude          #+#    #+#             */
/*   Updated: 2025/03/20 17:51:56 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	rotate_a(t_stacks *s, int index_max)
{
	int	buff;
	int	i;

	buff = s->array_a[0];
	i = 0;
	while (i != index_max - 1)
	{
		s->array_a[i] = s->array_a[i + 1];
		i++;
	}
	s->array_a[i] = buff;
	ft_printf("ra\n");
}

void	rotate_b(t_stacks *s)
{
	int		buff;
	size_t	i;

	buff = s->array_b[0];
	i = 0;
	while (i != s->size_b - 1)
	{
		s->array_b[i] = s->array_b[i + 1];
		i++;
	}
	s->array_b[i] = buff;
	ft_printf("rb\n");
}

void	rotate_ab(t_stacks *s, size_t index_max)
{
	int		buff;
	size_t	i;

	buff = s->array_a[0];
	i = 0;
	while (i != index_max - 1)
	{
		s->array_a[i] = s->array_a[i + 1];
		i++;
	}
	s->array_a[i] = buff;
	buff = s->array_b[0];
	i = 0;
	while (i != s->size_b - 1)
	{
		s->array_b[i] = s->array_b[i + 1];
		i++;
	}
	s->array_b[i] = buff;
	ft_printf("rr\n");
}
