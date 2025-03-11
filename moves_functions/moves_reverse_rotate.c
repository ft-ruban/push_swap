/*rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time.*/

#include "../header/push_swap.h"
// 5 4 9 1 2 3 a
// -5 -10 b
// 3 5 4 9 1 2 ares
// -10 -5 bres

void reverse_rotate_a(t_stacks *s, int index_max)
{
    int     buff[index_max];
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (++j <= index_max)
        buff[j] = s->array_a[i++];
    buff[0] = s->array_a[index_max];
    i = 0;
    j = -1;
    while (++j <= index_max)
        s->array_a[j] = buff[i++];
    ft_printf("rra\n");
}
void reverse_rotate_b(t_stacks *s, int index_max)
{
    int     buff[index_max];
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (++j <= index_max)
        buff[j] = s->array_b[i++];
    buff[0] = s->array_b[index_max];
    i = 0;
    j = -1;
    while (++j <= index_max)
        s->array_b[j] = buff[i++];
    ft_printf("rrb\n");
}
void reverse_rotate_ab(t_stacks *s, int index_max)
{
    int     buff[index_max];
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (++j <= index_max)
        buff[j] = s->array_a[i++];
    buff[0] = s->array_a[index_max];
    i = 0;
    j = -1;
    while (++j <= index_max)
        s->array_a[j] = buff[i++];
    i = 0;
    j = 0;
    while (++j <= index_max)
        buff[j] = s->array_b[i++];
    buff[0] = s->array_b[index_max];
    i = 0;
    j = -1;
    while (++j <= index_max)
        s->array_b[j] = buff[i++];
    ft_printf("rrr\n");
}
