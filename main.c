#include "push_swap.h"

//TOASK if an user put -0 does it mean 0?
//TODO min val must be able to sort 100 random num in fewer than 700 operations
//MAX val 500 random numbers that should be no more than 5500 operations

//TOREM instructions doivent être separées par un ’\n’ et rien d’autre
//TOREM at first the first arg should be at the top then the smallest num

//TODORN check if there is any duplicates

int fill_array_a(char argv*[], int argc. array_a)
{

}

int main(int argc, char *argv[])
{
    char array_a[24] = "slt";
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
        ft_printf("ERREUR SUPPRIME MOI BLBLBLBL");
        //TODO error function ERROR + \n
        return(2);
    }
    if (fill_array_a (argv, argc, array_a))
    { 
        //ERROR
        ft_printf("Erreur dans fill_array_a");
        return (3);
    }
    //+++radix ++turc
    ft_printfd("SUITE WIP (NO ERROR YET)\n");
    return (0);
}