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

void step_two (t_stacks *s)
{
    size_t cheapest;
    //TODO while loop until size_a == 3
    //also a function that will reset the targets maybe
    assign_target_a(s);
    assign_cost_a(s); //maybe if else condition depending of if even or odd?
    sub_cost_rr_rrr(s); //sub the actual cost depending of if we need to do rr/rrr
    cheapest = cheapest_move_cost(s);
    printf("RESULTAT DE CHEAPEST : %zu\n", cheapest);
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