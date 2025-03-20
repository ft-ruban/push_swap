#include "header/push_swap.h"

//TODO make those functions lighter and check for ways to improve them.

size_t assign_cost_a_first_half(t_stacks *s, size_t i)
{
    while (i <= s->size_a / 2)
    {
        if (s->target_a[i] <= s->size_b / 2 || s->target_a[i] <= i)
            s->move_cost[i] = i + s->target_a[i];
        else
            s->move_cost[i] =  i + (s->size_b - s->target_a[i]);
        i++;
    }

    return (i);
}

void assign_cost_a_second_half_odd(t_stacks *s, size_t i)
{
        while (i <= s->size_a)
        {
            if (s->target_a[i] <= s->size_b / 2)
            {
                s->move_cost[i] = (s->size_a - i) + s->target_a[i];
            }
            else
            {
                s->move_cost[i] = (s->size_a - i) + (s->size_b - s->target_a[i]);
            }
            i++;
        }
}
void assign_cost_a_second_half_even(t_stacks *s, size_t i)
{
    while (i < s->size_a)
    {
        if(s->target_a[i] < s->size_b / 2 )
            s->move_cost[i] = (s->size_a - i) + s->target_a[i];
        else
            s->move_cost[i] = (s->size_a - i) + s->size_b - s->target_a[i]; 
        i++;
    }
}


void assign_cost_a(t_stacks *s)
{
    size_t i;

    i = 0;
    i = assign_cost_a_first_half(s,i);
    if (s->size_a % 2 != 0)
        assign_cost_a_second_half_odd(s,i);
    else
        assign_cost_a_second_half_even(s,i);
}



