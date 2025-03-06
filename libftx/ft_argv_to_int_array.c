#include "libft.h"

int	argv_to_int_array(char *argv[], int argc, int **array_a)
{
	int i;
	int j;
	int a;

	i = 1;
	j = 0;
	a = 0;
	*array_a = malloc((argc - 1) * sizeof(int));
	if (!array_a)
		return (1);
	while (argv[i] != 0)
	{
		(*array_a)[a] = ft_atoi(argv[i]);
		a++;
		i++;
	}
	return (0);
}