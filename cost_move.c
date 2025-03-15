#include "header/push_swap.h"

//TODO make those functions lighter and check for ways to improve them.

void assign_cost_a(t_stacks *s)
{
    unsigned long i;

    i = 0;
    while (i <= s->size_a / 2) // ok
    {
        if (s->target_a[i] <= s->size_b / 2 || s->target_a[i] <= i)
        {
            s->move_cost[i] = i + s->target_a[i];
            printf("VALEUR DE MOVE_COST A %d \n", s->move_cost[i]);
            //i++;
        }
        else
        {
            s->move_cost[i] =  i + (s->size_b - s->target_a[i]);//s->size_a - s->size_b - s->target_a[i];//s->target_a[i] - 1;
            printf("VALEUR DE MOVE_COST A %d \n", s->move_cost[i]);
        }
        // printf("VALEUR DE MOVE_COST %d \n", s->move_cost[i]);
        i++;
    }
    //printf("EXITING THE GOOD PART\n");
    if (s->size_a % 2 != 0) //je suis golmon, je ne passe pas ici pendant mon debbug car je peux pas passer la condition
    {
        printf("NOUS PASSONS ICI POUR %zu\n", i);
        while (i <= s->size_a)
        {
            if (s->target_a[i] <= s->size_b / 2)
            {
                s->move_cost[i] = (s->size_a - i) + s->target_a[i];
            }
            else
            {
                s->move_cost[i] = (s->size_a - i) + (s->size_b - s->target_a[i]);
            }
            printf("Valeur de i : %zu s->size_a %zu + target_a %zu\n", i, s->size_a, s->target_a[i]);
            printf("VALEUR DE MOVE_COST %d \n", s->move_cost[i]);
            i++;
        }
    } 
    else
    { 
        while (i < s->size_a)
        {
            if(s->target_a[i] < s->size_b / 2 )
                s->move_cost[i] = (s->size_a - i) + s->target_a[i];
            else
                s->move_cost[i] = (s->size_a - i) + s->size_b - s->target_a[i]; 
            printf("Valeur de i : %zu s->size_a %zu + target_a %zu\n", i, s->size_a, s->target_a[i]);
            printf("VALEUR DE MOVE_COST %d \n", s->move_cost[i]);
            i++;
        }
    }
    // printf("je sors\n");

}

void sub_cost_rr_rrr(t_stacks *s)
{
    unsigned long i;
    size_t counter_a;
    size_t counter_b;

    i = 1;
    while (i <= s->size_a / 2)
    {
        if(s->target_a[i] > 0 && s->target_a[i] <= s->size_b / 2)
        {
            counter_a = i;
            counter_b = s->target_a[i];
            printf("test");
            while (counter_a != 0 && counter_b != 0)
            {
                s->move_cost[i] -= 1;
                s->rr[i] += 1;
                counter_a--;
                counter_b--;
            }
        }
        else if (s->target_a[i] <= i) //additionnal condition to handle rare case when b is too smoll maybe I will have to do it when it come to a too?
        {
            counter_a = i;
            counter_b = s->target_a[i];
            while(counter_a != 0 && counter_b != 0)
            {
                s->move_cost[i] -= 1;
                s->rr[i] += 1;
                counter_a--;
                counter_b--;
            }
        }
        //printf("je sors\n");
        i++;
    }
    printf("je sors\n");
    while(i <= s->size_a)
    {
        printf("i dans second while %zu\n", i);
        if(s->target_a[i] >= s->size_b / 2)
        {
            counter_a = i;
            counter_b = s->target_a[i];
            while(counter_a != s->size_a  && counter_b != s->size_b)
            {
                printf("counter_a = %zu \n counter_b = %zu \n s->move_cost[%zu] = %d\n", counter_a, counter_b, i, s->move_cost[i]);
                s->move_cost[i] -= 1;
                s->rrr[i] += 1;
                counter_a++;
                counter_b++;
            }
        }
        i++;
    }
    i = 0;
    while (i < s->size_a)
        {
            printf("VALEUR DE MOVE_COST [%lu] %d \n", i, s->move_cost[i]);
            i++;
        }
}