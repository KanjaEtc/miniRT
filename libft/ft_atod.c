/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:02:54 by adbarth           #+#    #+#             */
/*   Updated: 2025/11/08 11:11:01 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(const char *s)
{
	int		i;
	double	n;
	double	neg;
	double	dec;

	i = 0;
	n = 0;
	neg = 1;
	dec = 10;
	if (!s)
		return (0);
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			neg = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = n * 10 + s[i] - '0';
		i++;
	}
	if (s[i] == '.')
	{
		i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			n += (s[i] - '0') / (1 * dec);
			i++;
			dec *= 10;
		}
	}
	return (n * neg);
}

// int main()
// {
// 	const char s[] = "		\n-10.23";
// 	printf("ft = %f\n", ft_atod(s));
// }
