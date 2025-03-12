#include "header/push_swap.h"

void debug_assign_target(t_stacks *s)
{
    size_t i;
    // size_t j;

    i = 0;
    while(i < s->size_a)
    {
        printf("Valeur de target_a[%zu] : %zu\n", i, s->target_a[i]);
        i++;
    }
}

void before_debug(t_stacks *s)
{
    size_t j;
    
    j = 0;
    while (j < s->size_a)
    {
        printf("DANS STEPS_PUSH_SWAP array_a[%zu] : %d\n", j, s->array_a[j]);
        j++;
    }
    printf("VALUE OF SIZE_A %zu \n",s->size_a);
}
void after_debug(t_stacks *s)
{
    size_t j;

    j = 0;
    printf("VALUE OF SIZE_A = %zu \n",s->size_a);
     while (j < s->size_a )
     {
         //printf("APRES SWAP_A array_a[%d] : %d\n", j, stacks->array_a[j]);
         printf("APRES STEPS array_a[%zu] : %d\n", j, s->array_a[j]);
         j++;
     }
     j = 0;
     printf("VALUE OF SIZE_B = %zu \n",s->size_b);
     while (j < s->size_b)
     {
        printf("APRES STEPS array_b[%zu] : %d\n",j, s->array_b[j]);
        j++;
     }
}