/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:39:02 by ajubert           #+#    #+#             */
/*   Updated: 2017/01/05 16:58:40 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

static void	get_nb_char(int n, int *size, int base)
{
	while (n > 0)
	{
		n /= base;
		*size = *size + 1;
	}
}

static char	*exception(int n, char *result, int base)
{
	int		size;

	size = 0;
	if (n == 0)
	{
		result = (char*)malloc(2);
		if (!result)
			return (NULL);
		result[0] = '0';
		result[1] = 0;
		return (result);
	}
	if (n == -2147483647 - 1)
	{
		get_nb_char(n, &size, base);
		result = (char*)malloc(size);
		if (!result)
			return (NULL);
		result = ft_strcpy(result, "-2147483648");
		return (result);
	}
	return (0);
}

static void	if_n_negative(int *n, int *is_negative, int *size)
{
	if (*n < 0)
	{
		*n = *n * -1;
		(*is_negative)++;
		(*size)++;
	}
}

char		*ft_itoa_base(int n, int base)
{
	int		i;
	int		is_negative;
	int		size;
	char	*result;

	i = 1;
	is_negative = 0;
	size = 0;
	result = NULL;
	if (n == 0 || n == -2147483647 - 1)
		return (exception(n, result, base));
	if_n_negative(&n, &is_negative, &size);
	get_nb_char(n, &size, base);
	result = (char*)malloc(size + 1);
	if (!result)
		return (NULL);
	result[size] = 0;
	while (n > 0)
	{
		if (n % base < 10)
			result[size - i] = n % base + '0';
		else
			result[size - 1] = 10 - n % base + 'a';
		n /= base;
		i++;
	}
	result[0] = (is_negative == 1) ? '-' : result[0];
	return (result);
}
