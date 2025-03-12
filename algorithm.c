#include "header/push_swap.h"

//void push_b()



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
        push_b(s);
        push_b(s);
        //step_two;
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