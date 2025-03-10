/*sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.*/

#include "push_swap.h"
// 5 4 9 1 2 3
// 4 5 9 1 2 3
//TOKNOW YOU CAN PLACE JUST WHAT YOU NEED FROM STRUCT INSIDE PARAMETERS (stonk)
void swap_a (t_stacks *s)
{
    //TODO nothing if there is only one or no elements.
    int buff;

    buff = s->array_a[0];
    s->array_a[0] = s->array_a[1]; 
    s->array_a[1] = buff;
    return;
}

void swap_b (t_stacks *s)
{
    //TODO nothing if there is only one or no elements.
    int buff;

    buff = s->array_b[0];
    s->array_b[0] = s->array_b[1]; 
    s->array_b[1] = buff;
    return;
}

void swap_ab (t_stacks *s)
{
    //TODO nothing if there is only one or no elements.
    int buff;

    buff = s-> array_b[0];
    s->array_b[0] = s->array_b[1]; 
    s->array_b[1] = buff;
    buff = s->array_a[0];
    s->array_a[0] = s->array_a[1]; 
    s->array_a[1] = buff;
    return;
}
