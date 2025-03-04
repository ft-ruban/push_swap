#include "push_swap.h"

int    error_checker_is_digit (char *argv[])
{
    int i;
    int j;

    j = 0;
    i = 1;
    while (argv[i] != 0)
    {
        while(argv[i][j] != 0)
        {
            ft_printf("avant isdigit :%c \n",argv[i][j]);
            if (!ft_isdigit((char)argv[i][j])) //todo libftx function that check if bigger than an int + is there dupli
                return (1);
            j++;
        }
        j = 0;
        i++;
    }
    return (0);
}