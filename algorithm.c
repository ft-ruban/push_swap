/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:16:45 by ldevoude          #+#    #+#             */
/*   Updated: 2025/03/20 14:53:19 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

size_t cheapest_move_cost(t_stacks *s)
 {
    size_t i;
    size_t result;

    i = 1;
    result = 0;
    while (i < s->size_a)
    {
        if (s->move_cost[i] < s->move_cost[result])
            result = i;
        i++;
    }
    return (result);
 }

 
void move_at_top_then_push (t_stacks *s, size_t cheapest)
{
    size_t counter_a;
    size_t counter_b;

    counter_a = cheapest;
    counter_b = s->target_a[cheapest];
    while (s->rr[cheapest] != 0)
    {
        rotate_ab(s, s->size_a);
        s->rr[cheapest] -= 1;
        //cheapest--;
        counter_a--;
        counter_b--;
    }
    while (s->rrr[cheapest] != 0)
    {
        reverse_rotate_ab(s, s->size_a);
        s->rrr[cheapest] -= 1;
        //cheapest++;
        counter_a++;
        counter_b++;
    }

    if (counter_a <= s->size_a / 2 && counter_a != 0)
    {
        while (counter_a != 0)
        {
           rotate_a(s, s->size_a);
           counter_a--;
        }
    }
    else if (counter_a > s->size_a / 2 && counter_a != s->size_a + 1)
    {
        while(counter_a != s->size_a /*+ 1*/)
        {
            reverse_rotate_a(s, s->size_a);
            counter_a++;
        }
    }
    if (counter_b <= s->size_b / 2 && counter_b != 0)
    {
        while (counter_b != 0)
        {
            rotate_b(s);
            counter_b--;
        }
    }
    else if (counter_b > s->size_b / 2 && counter_b != s-> size_b + 1) //not sure about the half part of the condition
    {
        while(counter_b != s->size_b /*+ 1*/)
        {
            reverse_rotate_b(s, s->size_b);
            counter_b++;
        }
    }
    push_b(s);
}

void find_target_a(t_stacks *s)
{
    size_t i;
    size_t min_coordinate;
    size_t target;

    //printf("je passe ici");
    target = 0;
    min_coordinate = 0;
    i = 0;
    while (i <= s->size_a)
    {
        if (s->array_a[i] > s->array_b[0])
        {
            target = 1;
            s->target_b[0] = i;
            while (i <= s->size_a)
            {
                if ((s->array_a[i] < s->array_a[s->target_b[0]]) && (s->array_a[i] > s->array_b[0]))
                {
                    s->target_b[0] = i;
                }
                i++;
            }
        }
        else
        {
            if(s->array_a[min_coordinate] > s->array_a[i])
                min_coordinate = i;
        }
        i++;
    }
    if ((target == 0))
        s->target_b[0] = min_coordinate;
}

void move_at_top_b_then_push(t_stacks *s)
{
    size_t counter_a;

    counter_a = s->target_b[0];

    if (counter_a <= s->size_a / 2 && counter_a != 0)
    {
        while (counter_a != 0)
        {
           rotate_a(s, s->size_a);
           counter_a--;
        }
    }
    else if (counter_a > s->size_a / 2 && counter_a != s->size_a + 1)
    {
        while(counter_a != s->size_a /*+ 1*/)
        {
            reverse_rotate_a(s, s->size_a);
            counter_a++;
        }
    }
    s->target_b[0] = 0;
    push_a(s);
}
size_t cheapest_number(t_stacks *s)
{
    size_t i;
    size_t result;

    result = 0;
    i = 0;
    while (i < s->size_a)
    {
        if (s->array_a[result] > s->array_a[i])
        {
            result = i;
        }
        i++;
    }
    return (result);
}