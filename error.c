#include "push_swap.h"



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

int error_message(int code, t_stacks *stacks)
{
    if(stacks)
        free (stacks);
    ft_printfd("ERROR %d\n",code);
    exit(code);
}

int    error_checker (char *argv[], int argc, t_stacks *stacks)
{   
    int     *stack_a;
    size_t  size_stack_a;

    size_stack_a = argc - 2;
    if(error_checker_is_digit(argv))
        error_message(DIGIT_ERROR, stacks);
    if (error_bigger_than_int(argv))
        error_message(INT_SIZED_ERROR, stacks);
    if (argv_to_int_array (argv, argc, &stack_a))
        error_message(MALLOC_ERROR, stacks);
    if (error_duplicate_checker (stack_a, argc - 2))
    {
        free(stack_a);
        error_message(DUPLICATE_ERROR, stacks);
    }
    init_stacks(size_stack_a, stacks, stack_a);
    return(0);
}