/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:29:53 by adbarth           #+#    #+#             */
/*   Updated: 2025/11/10 07:28:29 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*uc_s;

	uc_s = s;
	while (n--)
		*uc_s++ = (unsigned char)c;
	return (s);
}
/*
int main()
{
	char s[] = "salut";
	int c = 'h';
	size_t n = 5;
	printf("%s\n%s\n", (char *)ft_memset(s, c, n), (char *)memset(s, c, n));
}*/
