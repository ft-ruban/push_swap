#include "header/push_swap.h"

void    init_stacks(size_t size_stack_a, t_stacks *s, int *stack_a)
{
    size_t i;

    i = 0;
    s->size_a  = size_stack_a;
    s->size_b  = 0; //maybe 0?
    s->array_a = ft_calloc(size_stack_a + 1, sizeof(int));
    s->array_b = ft_calloc(size_stack_a + 1, sizeof(int));
    s->target_a = ft_calloc(size_stack_a + 1, sizeof(size_t));
    s->target_b = ft_calloc(size_stack_a + 1, sizeof(size_t));
    s->move_cost = ft_calloc(size_stack_a + 1, sizeof(int));
    s->rr = ft_calloc(size_stack_a + 1, sizeof(int));
    s->rrr = ft_calloc(size_stack_a + 1, sizeof(int));
     if (!s->array_a ||!s->array_b||!s->target_a||!s->target_b||!s->move_cost
        ||!s->rr||!s->rrr)
    {
        free(stack_a);
        free_struct(s);
    }
    while (i < size_stack_a) //create leaks when =<
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
    if(s)
        free (s);
    exit(0);
    error_message(13, s);
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

void target_reset(t_stacks *s)
{
    size_t i;

    i = 0;
    while (i <= s->size_a)
    {
        s->target_a[i] = 0;
        i++;
    }
}