#include "corewar.h"

void	free_split(char ***str, int size)
{
	int i;

	i = 0;
	if (str && str[0])
	{
		while (i < size)
		{
			free_line(&str[0][i]);
			i++;
		}
	}
	if (str[0])
		free(str[0]);
	str[0] = NULL;

}
