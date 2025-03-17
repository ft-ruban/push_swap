/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:48:45 by ldevoude          #+#    #+#             */
/*   Updated: 2025/03/17 10:32:36 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */



#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "../libftx/libft.h"
#include "stdio.h" //TORM BFRPUSH
# define TRUE 1
# define FALSE 0
# define MALLOC_ERROR 1
# define ARGUMENT_ERROR 2
# define DIGIT_ERROR 3
# define INT_SIZED_ERROR 4
# define DUPLICATE_ERROR 5
typedef struct s_stacks
{
    size_t     size_a;
    size_t     size_b;
    int        *array_a;
    int        *array_b;
    size_t     *target_a;
    size_t     *target_b;
    int        *move_cost;
    int        *rr;
    int        *rrr;
    //int        median;
} t_stacks;
#endif

int     main                   (int argc, char *argv[]);
void    assign_cost_a          (t_stacks *s);
void    assign_target_a        (t_stacks *s);
size_t  biggest_number_array   (t_stacks *s);
int     error_bigger_than_int  (char *argv[]);
int     error_checker          (char *argv[], int argc, t_stacks *stacks);
int     error_checker_is_digit (char *argv[]);
int     error_duplicate_checker(int *array_a, int size_array_a);
int     error_message          (int code, t_stacks *stacks);
void    free_struct            (t_stacks *s);
void    init_stacks            (size_t size_stack_a, t_stacks *stacks, int *stack_a);
void    move_at_top_then_push  (t_stacks *s, size_t cheapest);
void    push_a                 (t_stacks *s);
void    push_b                 (t_stacks *s);
void    reverse_rotate_a       (t_stacks *s, int index_max);
void    reverse_rotate_ab      (t_stacks *s, int index_max);
void    reverse_rotate_b       (t_stacks *s, int index_max);
void    rotate_a               (t_stacks *s, int index_max);
void    rotate_ab              (t_stacks *s, int index_max);
void    rotate_b               (t_stacks *s, int index_max);
void    rr_rrr_reset           (t_stacks *s);
void    sort_three             (t_stacks *s);
void    step_one               (t_stacks *s);
int     steps_push_swap        (t_stacks *stacks);
void    sub_cost_rr_rrr        (t_stacks *s);
void    swap_a                 (t_stacks *s);
void    swap_b                 (t_stacks *s);
void    target_reset           (t_stacks *s);
size_t  cheapest_move_cost     (t_stacks *s);
void    before_debug           (t_stacks *s);
void    after_debug            (t_stacks *s);
void    debug_assign_target    (t_stacks *s);
