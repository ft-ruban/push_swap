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
 
void assign_cost_a(t_stacks *s)
{
    unsigned long i;
    int j;

    j = s->size_a;
    i = 0;
    while (i <= s->size_a / 2)
    {
        if (s->target_a[i] <= s->size_b / 2)
        {
            s->move_cost[i] = i + s->target_a[i];
            printf("VALEUR DE MOVE_COST A %d \n", s->move_cost[i]);
            //i++;
        }
        else
        {
            s->move_cost[i] =  s->size_a - s->array_a[i];
            printf("VALEUR DE MOVE_COST A %d \n", s->move_cost[i]);
        }
        // printf("VALEUR DE MOVE_COST %d \n", s->move_cost[i]);
        i++;
    }
    if (s->size_a % 2 != 0)
    {
        while (i <= s->size_a)
        {
            s->move_cost[i] = (s->size_a - i) + s->target_a[i] + 1;
            printf("Valeur de i : %zu s->size_a %zu + target_a %zu\n", i, s->size_a, s->target_a[i]);
            printf("VALEUR DE MOVE_COST %d \n", s->move_cost[i]);
            i++;
        }
    } 
    else
    { 
        s->move_cost[i] = (s->size_a - i) + s->target_a[i];
        printf("Valeur de i : %zu s->size_a %zu + target_a %zu\n", i, s->size_a, s->target_a[i]);
        printf("VALEUR DE MOVE_COST %d \n", s->move_cost[i]);
        i++;
        while (i <= s->size_a)
        {
            s->move_cost[i] = (s->size_a - i) + s->target_a[i] + 1;
            printf("Valeur de i : %zu s->size_a %zu + target_a %zu\n", i, s->size_a, s->target_a[i]);
            printf("VALEUR DE MOVE_COST %d \n", s->move_cost[i]);
            i++;
        }
    }

}



// void assign_cost_a(t_stacks *s)
// {
//     unsigned long i;
//     int j;

//     j = s->size_a;
//     i = 0;
//     while (i < s->size_a / 2)
//     {
//         s->move_cost[i] = i + s->target_a[i];
//         printf("VALEUR DE MOVE_COST %d \n", s->move_cost[i]);
//         i++;
//     }
//     while (i < s->size_a)
//     {
//         s->move_cost[i] = (i - s->size_a) * -1 + s->target_a[i];
//         printf("VALEUR DE MOVE_COST %d \n", s->move_cost[i]);
//         i++;
//     }
// }

void step_two (t_stacks *s)
{
    //TODO while loop until size_a == 3
    //also a function that will reset the targets maybe
    assign_target_a(s);
    assign_cost_a(s);
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