/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:48:45 by ldevoude          #+#    #+#             */
/*   Updated: 2025/03/06 17:49:44 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */



#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "libftx/libft.h"
#include "stdio.h" //TORM BFRPUSH
# define TRUE 1
# define FALSE 0

typedef struct s_stack_node
{
    int     value;
    int     index;
    int     cost;
    int     above_average;
    int     cheaper;
    struct s_stack_node *target_node;
    struct s_stack_node *next;
    struct s_stack_node *prev;
} t_stack_node;
#endif

int     main(int argc, char *argv[]);
int     error_duplicate_checker(int *array_a, int size_array_a);
int     error_checker (char *argv[]);
int     error_checker_is_digit (char *argv[]);
int     error_message(int code);
int     *step_one (int *array_a, int *array_b, int i);
int     *steps_push_swap(int *array_a, int i);
int     error_bigger_than_int (char *argv[]);
