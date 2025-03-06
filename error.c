#include "push_swap.h"

int error_message(int code)
{
    ft_printfd("ERROR %d\n",code);
    return (code);
}

int error_duplicate_checker(int *array_a, int size_array_a)
{
    int buffer;
    int i;
    int j;

    i = 0;
    while (i != size_array_a + 1)
    {
        j = i + 1;
        buffer = array_a[i];
        while ( j != size_array_a + 1)
        {
            if (buffer == array_a[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int    error_bigger_than_int (char *argv[])
{
    int i;
    int j;

    j = 0;
    i = 1;
    while (argv[i] != 0)
    {
        while(argv[i][j] != 0)
        {
            if (ft_isintsized(argv[i]))   
                return(1);
            j++;
        }
        j = 0;
        i++;
    }
    return(0);
}

int    error_checker_is_digit (char *argv[])
{
    int i;
    int j;

    j = 0;
    i = 1;
    while (argv[i] != 0)
    {
        if (argv[i][j] == '-' && argv[i][j+1] != '\0')
            j++;
        if (argv[i][j] == '\0')
            return (1);
        while(argv[i][j] != 0)
        {
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
    if(error_checker_is_digit(argv))
        return (1);
    if (error_bigger_than_int(argv))
        return (1);
    return(0);
}