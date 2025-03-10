#include "header/push_swap.h"

//void push_b()

int *step_one (int *array_a, int *array_b, int i)
{
    while (i != -1)
    {
        array_b[i] =array_a[i];
        i--;
    }
    return 0;
}

int steps_push_swap(t_stacks *stacks)
{
    size_t j;
    
    j = 0;
    //printf("value of j = %d", j);
    while (j < stacks->size_a + 1)
    {
        //printf("DANS STEPS_PUSH_SWAP array_a[%zu] : %d\n", j, stacks->array_a[j]);
        j++;
    }
    j = 0;
    stacks->array_b[0] = -5;
    stacks->array_b[1] = -10;
    swap_a (stacks);
    printf("VALUE OF SIZE_A %zu \n",stacks->size_a);
    //step_one (array_a, array_b, i);
     while (j < stacks->size_a )
     {
         //printf("APRES SWAP_A array_a[%d] : %d\n", j, stacks->array_a[j]);
         printf("APRES SWAP_A array_a[%zu] : %d\nAPRES SWAP_A array_b[%zu] : %d\n", j, stacks->array_a[j], j, stacks->array_b[j]);
         j++;
     }
    //return (array_a);
    free_struct(stacks);
    return (1);
}