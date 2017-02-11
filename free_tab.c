#include "corewar.h"

void	free_tab(t_op_ft **tab, int size)
{
	int i;

	i = 0;
	if (tab && tab[0])
	{
		while (i < size)
		{
			free_line(&tab[0][i].str);
			free_line(&tab[0][i].ft);
			i++;
		}
	}
	if (tab[0])
	free(tab[0]);
	tab[0] = NULL;

}
