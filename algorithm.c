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

void assign_target_a(t_stacks *s) //to place into sort_utils whenever u finished
{
    size_t i;
    size_t j;
    int    smallest_number_a;
    size_t biggest_number_b;
    
    i = 0;
    biggest_number_b = biggest_number_array(s);
    printf("BIGGEST NUMBER IS = %zu\n",biggest_number_b);
    while(i < s->size_a)
    {
        j = 0;
        smallest_number_a = 0;
        while(j < s->size_b)
        {
            if (s->array_b[j] < s->array_a[i] && s->array_b[j] > s->array_b[s->target_a[i]])
            {    
                smallest_number_a = 1;
                printf("je passe ici\n");
                s->target_a[i] = j;
            }
            j++;
        }
        i++;
    }
    debug_assign_target(s);
}

void step_two (t_stacks *s)
{
    assign_target_a(s);
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