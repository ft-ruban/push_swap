#include "push_swap.h"

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
    int j;
    
    j = stacks->size_a;
    while (j >= 0)
    {
        //printf("DANS STEPS_PUSH_SWAP array_a[%d] : %d\n", j, stacks->array_a[j]);
        j--;
    }
    j = stacks->size_a;
    free_struct(stacks);
    //step_one (array_a, array_b, i);
    // while (j >= 0)
    // {
    //     printf("APRES STEP_ONE array_a[%d] : %d\n APRES STEP_ONE array_b[%d] : %d\n", j, array_a[j], j, array_b[j]);
    //     j--;
    // }
    //return (array_a);
    return (1);
}