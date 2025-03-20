/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_between_arrays.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:45:44 by ldevoude          #+#    #+#             */
/*   Updated: 2025/03/20 13:46:52 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	swap_a(t_stacks *s)
{
	int	buff;

	buff = s->array_a[0];
	s->array_a[0] = s->array_a[1];
	s->array_a[1] = buff;
	ft_printf("sa\n");
}

void	swap_b(t_stacks *s)
{
	int	buff;

	buff = s->array_b[0];
	s->array_b[0] = s->array_b[1];
	s->array_b[1] = buff;
	ft_printf("sb\n");
}

void	swap_ab(t_stacks *s)
{
	int	buff;

	buff = s->array_b[0];
	s->array_b[0] = s->array_b[1];
	s->array_b[1] = buff;
	buff = s->array_a[0];
	s->array_a[0] = s->array_a[1];
	s->array_a[1] = buff;
	ft_printf("ss\n");
}
