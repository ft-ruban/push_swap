#include "header/push_swap.h"
//working in theory

//function seem to be working well, still need to make it smoller + make sure everything is fine.
void assign_target_a(t_stacks *s) //to place into sort_utils whenever u finished
{
    size_t i;
    size_t j;
    int    smallest_number_a;
    size_t biggest_number_b;

    i = 0;
    biggest_number_b = biggest_number_array(s);
    while(i <= s->size_a)
    {
        j = 0;
        smallest_number_a = TRUE;
        while(j < s->size_b)
        {
            if (s->array_b[j] < s->array_a[i] || (s->array_b[j] <= s->array_a[i] && smallest_number_a == TRUE)) //TOCHECK smallest number == true may be unecessary
            {    
                if (!(smallest_number_a == FALSE && s->array_b[j] < s->array_b[s->target_a[i]]))
                {
                    smallest_number_a = FALSE;
                    //printf("je passe ici%zu\n", i);
                    s->target_a[i] = j;
                }
                else if (smallest_number_a == TRUE && s->array_b[j] > s->array_b[s->target_a[i]])
                    s->target_a[i] = j;
            }
            j++;
        }
        if (smallest_number_a == TRUE)
            s->target_a[i] = biggest_number_b;
        i++;
    }
    debug_assign_target(s);
}

size_t biggest_number_array(t_stacks *s)
{
	size_t i;
	size_t result;

	result = 0;
	i = 1;
	while (i < s->size_b)
	{
		if (s->array_b[result] < s->array_b[i])
			result = i;
		i++;
	}
	return (result);
}

void	sort_three(t_stacks *s)
{
	if (s->array_a[2] < s->array_a[0] || s->array_a[2] < s->array_a[1])
	{
		printf("OUI\n");
		if (s->array_a[0] > s->array_a[1])
			rotate_a(s, s->size_a /*- 1*/);
		else
		{
			swap_a(s);
			rotate_a(s, s->size_a /*- 1*/);
		}
	}
	if (s->array_a[0] > s->array_a[1])
		swap_a(s);
}
