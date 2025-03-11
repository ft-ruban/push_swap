#include "header/push_swap.h"

//void push_b()



void step_one (t_stacks *s)
{
    if(s->size_a == 2)
    {  
        if (s->array_a[0] > s->array_a[1])
            swap_a(s);
        exit(0);
    }
    else if(s->size_a == 3)
        sort_three(s);
    else if(s->size_a == 4)
    {
        push_b(s);
        sort_three(s);
        //TODO function to handle that specific case
    }
    else
    {
        push_b(s);
        push_b(s);
        //step_two;
    }
}

int steps_push_swap(t_stacks *stacks)
{
    size_t j;
    
    j = 0;
    while (j < stacks->size_a)
    {
        printf("DANS STEPS_PUSH_SWAP array_a[%zu] : %d\n", j, stacks->array_a[j]);
        j++;
    }
    j = 0;
    printf("VALUE OF SIZE_A %zu \n",stacks->size_a);
    step_one(stacks);
    printf("VALUE OF SIZE_A = %zu \n",stacks->size_a);
     while (j < stacks->size_a )
     {
         //printf("APRES SWAP_A array_a[%d] : %d\n", j, stacks->array_a[j]);
         printf("APRES STEPS array_a[%zu] : %d\n", j, stacks->array_a[j]);
         j++;
     }
     j = 0;
     printf("VALUE OF SIZE_B = %zu \n",stacks->size_b);
     while (j < stacks->size_b)
     {
        printf("APRES STEPS array_b[%zu] : %d\n",j, stacks->array_b[j]);
        j++;
     }
    //return (array_a);
    free_struct(stacks);
    return (1);
}