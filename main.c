#include "header/push_swap.h"

int main(int argc, char *argv[])
{
    t_stacks     *stacks;

    stacks = ft_calloc(1, sizeof(t_stacks));
    if (!stacks)
        return (error_message(MALLOC_ERROR, stacks));
    if(argc < 2)
        return (error_message(ARGUMENT_ERROR, stacks));
    error_checker (argv, argc, stacks); 
    if (!steps_push_swap(stacks))
        return(error_message(5, stacks));
    return (0);
}
//I do turkish
//verifier si deja trié ?