#include "push_swap.h"

//TOASK if an user put -0 does it mean 0?
//TODO min val must be able to sort 100 random num in fewer than 700 operations
//MAX val 500 random numbers that should be no more than 5500 operations

//TOREM instructions doivent être separées par un ’\n’ et rien d’autre
//TOREM at first the first arg should be at the top then the smallest num

//TODORN check if there is any duplicates

int fill_array_a(char *argv[], int argc, int **array_a)
{
    int i;
    int j;
    int a;

    i = 1;
    j = 0;
    a = 0;
    *array_a = malloc((argc - 1) * sizeof(int));
    while(argv[i] != 0)
    {
            (*array_a)[a] = ft_atoi(argv[i]);
            printf("DANS FILL_ARRAY array_a[%d] : %d\n", a, (*array_a)[a]);
            a++;
            i++;
            
    }
    //TODO function to check if two same num?
    return 0;
}

int main(int argc, char *argv[])
{
    int i;

    i = argc - 2;
    int *array_a = NULL;
    //char *array_b;
    ft_printf("flagcon : %s",array_a);
    //array_a = NULL;
    if(argc < 2) //if no param are specified program must not display anything and give the prompt back
    {
        ft_printf("Insert at least an arg dumbass AND DELETE BEFORE PUSH");  //TORM
        return (1);
    }
    if (error_checker (argv)) //error can be : some args arent int, some arg are bigger than an int and /or there are duplicates.
    {
        //TODO error function ERROR + \n
        return(2);
    }
     //HERE
    if (fill_array_a (argv, argc, &array_a))
    { 
        ft_printf("Erreur dans fill_array_a");
        return (3);
    }
    printf("argc = %d\n", argc);
    printf("array_a = %d\n", array_a[0]);
    while (i >= 0)
    {
        printf("DANS MAIN array_a[%d] : %d\n", i, array_a[i]);
        //printf("array_a[%d] : %d\n",i ,array_a[i]);
        i--;
    }
    return (0);
}
//+++radix ++turc