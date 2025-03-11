#include "../header/push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
// rr : ra and rb at the same time.

// 5 4 9 1 2 3 a
// 4 9 1 2 3 5 res

//STATUS: COMPLETE + VALGRIND 100%

void rotate_a(t_stacks *s, int index_max)
{
    int     buff[index_max];
    int     i;
    int     j;

    i = 0;
    j = 0;

    while (++i <= index_max)
        buff[j++] = s->array_a[i];
    buff[j] = s->array_a[0];
    i = 0;
    j = -1;
    while (++j <= index_max)
        s->array_a[j] = buff[i++];
    ft_printf("ra\n");
}

void rotate_b(t_stacks *s, int index_max)
{
    int     buff[index_max];
    int     i;
    int     j;

    i = 0;
    j = 0;

    while (++i <= index_max)
        buff[j++] = s->array_b[i];
    buff[j] = s->array_b[0];
    i = 0;
    j = -1;
    while (++j <= index_max)
        s->array_b[j] = buff[i++];
    ft_printf("rb\n");
}
void rotate_ab(t_stacks *s, int index_max)
{
    int     buff[index_max];
    int     i;
    int     j;

    i = 0;
    j = 0;

    while (++i <= index_max)
        buff[j++] = s->array_a[i];
    buff[j] = s->array_a[0];
    i = 0;
    j = -1;
    while (++j <= index_max)
        s->array_a[j] = buff[i++];
    i = 0;
    j = 0;
    while (++i <= index_max)
        buff[j++] = s->array_b[i];
    buff[j] = s->array_b[0];
    i = 0;
    j = -1;
    while (++j <= index_max)
        s->array_b[j] = buff[i++];
    ft_printf("rr\n");
}

