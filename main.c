#include "push_swap.h"

int main(int argc, char *argv[])
{
    t_stacks     *stacks;

    stacks = ft_calloc(1, sizeof(t_stacks));
    if (!stacks)
        return (error_message(MALLOC_ERROR, stacks));
    if(argc < 2)
        return (error_message(ARGUMENT_ERROR, stacks));
    error_checker (argv, argc, stacks); 
    //printf("argc = %d\n", argc);
    //printf("array_a = %d\n", stacks->array_a[0]);
    if (!steps_push_swap(stacks))
        return(error_message(5, stacks));
    return (0);
}
//+++radix ++turc
//verifier si deja trié
//si 3 arg le trier directement car sinon ca va faire trop d'iter
//j'ai pas besoin de swap et double swap (swap a si)