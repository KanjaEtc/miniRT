/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:44:19 by adbarth           #+#    #+#             */
/*   Updated: 2025/11/08 11:35:54 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*uc_s;

	i = 0;
	uc_s = s;
	while (n--)
	{
		if (uc_s[i] == (unsigned char)c)
			return ((void *)&uc_s[i]);
		i++;
	}
	return (NULL);
}
/*
int main()
{
	const char s[] = "bonjour";
	int c = '\0';
	size_t n = 20;
	if (!ft_memchr(s, c, n))
		printf("ft_memchr return NULL\n");
	else
		printf("%s\n", (char *)ft_memchr(s, c, n));
	if (!memchr(s, c, n))
		printf("memchr return NULL\n");
	else
		printf("%s\n", (char *)memchr(s, c, n));
}*/
