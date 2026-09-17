/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:31:54 by adbarth           #+#    #+#             */
/*   Updated: 2025/11/08 16:48:15 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill_result(char *result, long int nb, int size)
{
	while (nb > 0)
	{
		result[size--] = '0' + nb % 10;
		nb /= 10;
	}
	return (result);
}

static int	ft_size(long int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	nb;
	int			size;
	int			neg;
	char		*result;

	nb = n;
	size = ft_size(nb);
	neg = 0;
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	result[size--] = '\0';
	if (nb == 0)
		result[size] = '0';
	if (nb < 0)
	{
		neg = 1;
		nb = -nb;
	}
	result = ft_fill_result(result, nb, size);
	if (neg)
		result[0] = '-';
	return (result);
}
/*
int main()
{
	int n = -2147483648;
	char *output = ft_itoa(n);
	printf("%s\n", output);
	free(output);
}*/
