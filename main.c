#include "push_swap.h"

//TODO min val must be able to sort 100 random num in fewer than 700 operations
//MAX val 500 random numbers that should be no more than 5500 operations

//TOREM instructions doivent être separées par un ’\n’ et rien d’autre
//TOREM at first the first arg should be at the top then the smallest num



int    error_checker (char *array_a, char *argv[])
{   
    ft_printf("%s = argv \n", argv[0]);
    ft_printf("%s = array_a\n", array_a);
    //above = tests bellow = checker en theorie j'ai meme pas besoin de array_a
    if(error_checker_is_digit(argv))
        return (1);
    
    //if no int(FAIT), bigger than an int, andor duplicates
    return(0);
}

int main(int argc, char *argv[])
{
    char array_a[24] = "slt";
    //char *array_b;

    //array_a = NULL;
    if(argc < 2) //TODO if no param are specified program must not display anything and give the prompt back
    {
        ft_printf("Insert at least an arg dumbass AND DELETE BEFORE PUSH");  //TORM
        return (1);
    }
    if (error_checker (array_a, argv)) //TODO in case of error it must display ERROR followed by a '\n' on the std error 
    //error can be some args arent int, some arg are bigger than an int and /or there are duplicates.
    {
        ft_printf("ERREUR SUPPRIME MOI BLBLBLBL");
        return(2);
    }  

    //radix ++turc
    ft_printfd("PAS ERROR(bravo...\n");
    return (0);
}