/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:32:58 by adbarth           #+#    #+#             */
/*   Updated: 2025/11/10 07:08:50 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*uc_dest;
	const unsigned char	*uc_src;

	if (!dest && !src)
		return (NULL);
	if (!n)
		return (dest);
	uc_dest = dest;
	uc_src = src;
	while (n--)
		*uc_dest++ = *uc_src++;
	return (dest);
}
/*
int main()
{
	char dest[20] = "salut";
	const char src[] = "bonjour";
	size_t n = 3;
	char *output = (char *)memcpy(dest, src, n);
	if (output)
		printf("%s\n", output);
	else
		printf("null\n");
}*/
