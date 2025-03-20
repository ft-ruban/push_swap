/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:52:29 by ldevoude          #+#    #+#             */
/*   Updated: 2025/03/20 13:53:45 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
//TODO NORME
void	rotate_a(t_stacks *s, int index_max)
{
	int	buff[index_max];
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++i < index_max)
		buff[j++] = s->array_a[i];
	buff[j] = s->array_a[0];
	i = 0;
	j = -1;
	while (++j < index_max)
		s->array_a[j] = buff[i++];
	ft_printf("ra\n");
}

void	rotate_b(t_stacks *s)
{
	int		buff[s->size_b];
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (++i < s->size_b)
		buff[j++] = s->array_b[i];
	buff[j] = s->array_b[0];
	i = 0;
	j = -1;
	while (++j < s->size_b)
		s->array_b[j] = buff[i++];
	ft_printf("rb\n");
}

void	rotate_ab(t_stacks *s, int index_max)
{
	int	buff[index_max];
	int	buff_b[s->size_b];
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++i < index_max)
		buff[j++] = s->array_a[i];
	buff[j] = s->array_a[0];
	i = 0;
	j = -1;
	while (++j < index_max)
		s->array_a[j] = buff[i++];
	i = 0;
	j = 0;
	while ((size_t)++i < s->size_b)
		buff_b[j++] = s->array_b[i];
	buff_b[j] = s->array_b[0];
	i = 0;
	j = -1;
	while ((size_t)++j < s->size_b)
		s->array_b[j] = buff_b[i++];
	ft_printf("rr\n");
}
