#include "push_swap.h"

void    init_stacks(size_t size_stack_a, t_stacks *s, int *stack_a)
{
    size_t i;

    i = 0;
    s->size_a  = size_stack_a;
    s->size_b  = size_stack_a; //maybe 0?
    s->array_a = ft_calloc(size_stack_a, sizeof(int));
    s->array_b = ft_calloc(size_stack_a, sizeof(int));
    s->target_a = ft_calloc(size_stack_a, sizeof(int));
    s->target_b = ft_calloc(size_stack_a, sizeof(int));
    s->move_cost = ft_calloc(size_stack_a, sizeof(int));
    s->rr = ft_calloc(size_stack_a, sizeof(int));
    s->rrr = ft_calloc(size_stack_a, sizeof(int));
     if (!s->array_a ||!s->array_b||!s->target_a||!s->target_b||!s->move_cost
        ||!s->rr||!s->rrr)
    {
        free(stack_a);
        free_struct(s);
    }
    while (i < size_stack_a)
    {
        s->array_a[i] = stack_a[i];
        i++;
    }
    free (stack_a);
}

void free_struct(t_stacks *s)
{
    if (s->array_a)
        free(s->array_a);
    if (s->array_b)
        free(s->array_b);
    if (s->target_a)
        free(s->target_a);
    if (s->target_b)
        free(s->target_b);
    if (s->move_cost)
        free(s->move_cost);
    if (s->rr)
        free(s->rr);
    if (s->rrr)
        free(s->rrr);
    error_message(13, s);
}