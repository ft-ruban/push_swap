#include "push_swap.h"

int    is_bigger_than_int (char *argv[])
{
    int i;
    int j;

    j = 0;
    i = 1;
    while (argv[i] != 0)
    {
        while(argv[i][j] != 0)
        {
            ft_printf("avant isintsized :%s \n",argv[i]);
            if (ft_isintsized(argv[i])) //todo libftx function that check if bigger than an int + is there dupli
            {   
                ft_printf("do I pass?\n");
                return (1);
            }
            j++;
        }
        j = 0;
        i++;
    }
    return (0);
}

int    error_checker_is_digit (char *argv[])
{
    int i;
    int j;

    j = 0;
    i = 1;
    while (argv[i] != 0)
    {
        if (argv[i][j] == '-')
            j++;
        while(argv[i][j] != 0)
        {
            ft_printf("avant isdigit :%c \n",argv[i][j]);
            if (!ft_isdigit((char)argv[i][j]))
                return (1);
            j++;
        }
        j = 0;
        i++;
    }
    return (0);
}
int    error_checker (char *argv[])
{   
    ft_printf("%s = argv \n", argv[0]);
    //above = tests bellow = checker en theorie j'ai meme pas besoin de array_a
    if(error_checker_is_digit(argv))
        return (1);
    if (is_bigger_than_int(argv))
        return (1);
    //if no int(FAIT), bigger than an int(DONE),= manque duplicates
    return(0);
}