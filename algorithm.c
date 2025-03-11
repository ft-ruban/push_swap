#include "header/push_swap.h"

//void push_b()

void sort_three(t_stacks *s)
{
    if(s->array_a[2] < s->array_a[0] || s->array_a[2] < s->array_a[1])
    {
        printf("OUI\n");
        if (s->array_a[0] > s->array_a[1])
            rotate_a(s, s->size_a - 1);
        else
        {
            swap_a(s);
            rotate_a(s, s->size_a -1);
        }
    }
    if (s->array_a[0] > s->array_a[1])
    swap_a(s);
    //-biggest number at the bot
    // swap a if needed
    //profit
}

void step_one (t_stacks *s)
{
    if(s->size_a == 2)
    {  
        if (s->array_a[0] > s->array_a[1])
        {
            swap_a(s);
        }
        exit(0);
    }
    //make a elseif condition + the three sort function if there is only 3 in the stack
    //if 4 num then just push one and do the sort three stuff
    push_b(s);
    push_b(s);
}

int steps_push_swap(t_stacks *stacks)
{
    size_t j;
    
    j = 0;
    while (j < stacks->size_a + 1)
    {
        //printf("DANS STEPS_PUSH_SWAP array_a[%zu] : %d\n", j, stacks->array_a[j]);
        j++;
    }
    j = 0;
    // stacks->array_b[0] = -5;
    // stacks->array_b[1] = -10;
    //reverse_rotate_a (stacks, stacks->size_a - 1);
    //push_b(stacks);
    printf("VALUE OF SIZE_A %zu \n",stacks->size_a);
    sort_three(stacks);
    //step_one(stacks);
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