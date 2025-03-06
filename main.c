#include "push_swap.h"

//TOASK if an user put -0 does it mean 0?
//TODO min val must be able to sort 100 random num in fewer than 700 operations
//MAX val 500 random numbers that should be no more than 5500 operations

//TOREM instructions doivent être separées par un ’\n’ et rien d’autre
//TOREM at first the first arg should be at the top then the smallest num

//TODORN check if there is any duplicates

// int argv_to_int_array(char *argv[], int argc, int **array_a)
// {
//     int i;
//     int j;
//     int a;

//     i = 1;
//     j = 0;
//     a = 0;
//     *array_a = malloc((argc - 1) * sizeof(int));
//     if (!array_a)
//         return (1);
//     while(argv[i] != 0)
//     {
//             (*array_a)[a] = ft_atoi(argv[i]);
//             printf("DANS FILL_ARRAY array_a[%d] : %d\n", a, (*array_a)[a]);
//             a++;
//             i++;
            
//     }
//     return 0;
// }

int *algo_step_one(int *array_a, int i)
{
    while (i >= 0)
    {
        printf("DANS algo_step_one array_a[%d] : %d\n", i, array_a[i]);
        //printf("array_a[%d] : %d\n",i ,array_a[i]);
        i--;
    }
    return (array_a);
}

int main(int argc, char *argv[])
{
    int i;

    i = argc - 2;
    int *array_a = NULL;
    //char *array_b;
    //ft_printf("flagcon : %s",array_a);
    //array_a = NULL;
    if(argc < 2) //if no param are specified program must not display anything and give the prompt back
        return (error_message(1));
    if (error_checker (argv)) //error can be : some args arent int, some arg are bigger than an int and /or there are duplicates.
        return (error_message(2)); // - et + et "" donnent resultat 0
    if (argv_to_int_array (argv, argc, &array_a))
    { 
        ft_printf("Erreur dans fill_array_a\n");
        return (error_message(3));
    }
    printf("argc = %d\n", argc);
    if (error_duplicate_checker (array_a, argc - 2))
        return (error_message(4));//TODO free array_a
    printf("array_a = %d\n", array_a[0]);
    while (i >= 0)
    {
        printf("DANS MAIN array_a[%d] : %d\n", i, array_a[i]);
        //printf("array_a[%d] : %d\n",i ,array_a[i]);
        i--;
    }
    i = argc - 2; //TORM WITH TEST ABOVE
    array_a = algo_step_one(array_a, i);
    return (0);
}
//+++radix ++turc
//verifier si deja trié
//si 3 arg le trier directement car sinon ca va faire trop d'iter
//j'ai pas besoin de swap et double swap (swap a si)