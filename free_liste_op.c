#include "corewar.h"

void	free_liste_op(char ***tab)
{
	int i;

	i = 0;
	if (tab && tab[0])
	{
		while (i < NB_OP)
		{
			free_line(&tab[0][i]);
			i++;
		}
	}
	if (tab[0])
	free(tab[0]);
	tab[0] = NULL;

}
