#include "../header/push_swap.h"
// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
// rr : ra and rb at the same time.

// 5 4 9 1 2 3 a
// 3 2 1 9 4 5 res

//STATUS: COMPLETE + VALGRIND 100%
//Nevermind I am an idiot.

// void rotate_a(t_stacks *s, int index_max)
// {
//     int     buff[index_max];
//     int     i;
//     int     j;

//     j = -1;
//     i = -1;
//     while (++i <= index_max)
//         buff[i] = s->array_a[i];
//     i--;
//     while (++j <= index_max)
//         s->array_a[j] = buff[i--];
// }

// void rotate_b(t_stacks *s, int index_max)
// {
//     int     buff[index_max];
//     int     i;
//     int     j;

//     j = -1;
//     i = -1;
//     while (++i <= index_max)
//         buff[i] = s->array_b[i];
//     i--;
//     while (++j <= index_max)
//         s->array_b[j] = buff[i--];
// }

// void rotate_ab(t_stacks *s, int index_max)
// {
//     int     buff[index_max];
//     int     i;
//     int     j;

//     j = -1;
//     i = -1;
//     while (++i <= index_max)
//         buff[i] = s->array_a[i];
//     i--;
//     while (++j <= index_max)
//         s->array_a[j] = buff[i--];
//     j = -1;
//     i = -1;
//     while (++i <= index_max)
//         buff[i] = s->array_b[i];
//     i--;
//     while (++j <= index_max)
//         s->array_b[j] = buff[i--];
// }
