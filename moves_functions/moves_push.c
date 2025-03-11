/*pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time.*/

#include "../header/push_swap.h"
// 5 4 9 1 2 3 a
// -5 -10 b
// -5 5 4 9 1 2 3 a RES
// -10 b RES
//size_a = 5
//TODO test those whenever you can because I cant be sure yet of how efficient it would be
void push_a(t_stacks *s)
{
    int buff_target;
    int buff_sort;
    size_t i;

    buff_target = s->array_b[0];
    i = 0;
    while (i < s->size_a - 1) //unsure about the logic here bleh
    {
        s->array_b[i] = s->array_b[i+1];
        i++;
    }
    s->array_b[i] = 0;
    buff_sort = s->array_a[0];
    
    //s->array_a[1] = buff_sort;
    while (i != 0) //unsure about the logic here bleh
    {
        s->array_a[i] = s->array_a[i-1];
        i--;
    }
    s->array_a[0] = buff_target;
    ft_printf("pa\n");
}
void push_b(t_stacks *s)
{
    int buff_target;
    int buff_sort;
    size_t i;

    buff_target = s->array_a[0];
    i = 0;
    while (i < s->size_a - 1) //unsure about the logic here bleh
    {
        s->array_a[i] = s->array_a[i+1];
        i++;
    }
    s->array_a[i] = 0;
    buff_sort = s->array_b[0];
    while (i != 0) //unsure about the logic here bleh
    {
        s->array_b[i] = s->array_b[i-1];
        i--;
        printf("I = %zu\narray_b[%zu] %d\narray_b[%zu] %d\n", i, i - 1, s->array_b[i-1], i, s->array_b[i]);
    }
    s->array_b[0] = buff_target;
    ft_printf("pb\n");
}