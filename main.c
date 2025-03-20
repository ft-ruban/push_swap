/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:54:11 by ldevoude          #+#    #+#             */
/*   Updated: 2025/03/20 17:54:51 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;

	stacks = ft_calloc(1, sizeof(t_stacks));
	if (!stacks)
		return (error_message(MALLOC_ERROR, stacks));
	if (argc < 2)
		return (error_message(ARGUMENT_ERROR, stacks));
	error_checker(argv, argc, stacks);
	if (!steps_push_swap(stacks))
		return (error_message(5, stacks));
	return (0);
}
