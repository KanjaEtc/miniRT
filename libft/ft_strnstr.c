/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:41:36 by adbarth           #+#    #+#             */
/*   Updated: 2025/11/10 07:58:09 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s2[0])
		return ((char *)s1);
	i = 0;
	j = 0;
	while (s1[j])
	{
		k = j;
		while (s1[j] == s2[i] && j < n)
		{
			if (!s2[i + 1])
				return ((char *)&s1[k]);
			j++;
			i++;
		}
		j = ++k;
		i = 0;
	}
	return (NULL);
}
/*
int main()
{
	const char s1[] = "gfewixcvbnn"; 
	const char s2[] = "xcvb";
	size_t n = 3;
	if (ft_strnstr(s1, s2, n))
		printf("%s\n", ft_strnstr(s1, s2, n));
	else
		printf("(null)\n");
	if (strnstr(s1, s2, n))
		printf("%s\n", strnstr(s1, s2, n));
	else
		printf("(null)\n");
}*/
