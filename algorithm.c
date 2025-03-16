#include "header/push_swap.h"

// typedef struct s_stacks
// {
//     size_t     size_a;
//     size_t     size_b;
//     int        *array_a;
//     int        *array_b;
//     size_t     *target_a;
//     size_t     *target_b;
//     int        *move_cost;
//     int        *rr;
//     int        *rrr;
//     //int        median;
// } t_stacks;
 

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
            rotate_b(s, s->size_b);
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
    // while(counter_a != 0 && counter_a < s->size_a && counter_b < s->size_b && counter_b != 0 )
    // {
        
    //     if (counter_a != 0)
    //     {
    //         if (counter_a <= s->size_a / 2)
    //             {
    //                 while (counter_a != 0)
    //                 {
    //                    rotate_a(s, s->size_a);
    //                    counter_a--;
    //                 }
    //             }
    //         else
    //             {
    //                 while (counter_a != size_)
    //             }
    //     }
    // }
}

void rr_rrr_reset(t_stacks *s)
{
    size_t i;

    i = 0;
    while (i <= s->size_a)
    {
        s->rr[i] = 0;
        s->rrr[i] = 0;
        i++;
    }
}

void step_two (t_stacks *s)
{
    size_t cheapest;
    //TODO while loop until size_a == 3
    //also a function that will reset the targets maybe
    while(s->size_a != 3)
    {
        assign_target_a(s);
        assign_cost_a(s); //maybe if else condition depending of if even or odd?
        sub_cost_rr_rrr(s); //sub the actual cost depending of if we need to do rr/rrr
        cheapest = cheapest_move_cost(s);
        printf("RESULTAT DE CHEAPEST : %zu\n", cheapest);
        move_at_top_then_push(s, cheapest);
        rr_rrr_reset(s);
        //remettre a 0 les rr rrr etc etc :>
        after_debug(s);
    }

}

void step_one (t_stacks *s)
{
    if(s->size_a == 2)
    {  
        if (s->array_a[0] > s->array_a[1])
            swap_a(s);
        exit(0);
    }
    else if(s->size_a == 3)
        sort_three(s);
    else if(s->size_a == 4)
    {
        push_b(s);
        sort_three(s);
        //TODO function to handle that specific case
    }
    else
    {
        // push_b(s);
        // push_b(s);
        // push_b(s);
        // push_b(s);
        //  push_b(s);
        //  push_b(s);
        push_b(s);
        push_b(s);
        step_two(s);
    }
}

int steps_push_swap(t_stacks *stacks)
{
    before_debug(stacks);
    step_one(stacks);
    after_debug(stacks);
    free_struct(stacks);
    return (1);
}