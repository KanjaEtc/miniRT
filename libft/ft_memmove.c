/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:36:58 by adbarth           #+#    #+#             */
/*   Updated: 2025/11/10 07:27:13 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*uc_src;
	unsigned char		*uc_dest;

	uc_src = src;
	uc_dest = dest;
	if (!dest && !src)
		return (NULL);
	if (!n)
		return (dest);
	if (uc_src < uc_dest)
	{
		while (n--)
			uc_dest[n] = uc_src[n];
	}
	else
	{
		while (n--)
			*uc_dest++ = *uc_src++;
	}
	return (dest);
}
/*
int main()
{
	const char src[] = "bonjour";
	//char dest[] = "salut";
	char *dest = (char *)src + 3;
	size_t n = 3;
	char *output = (char *)memmove(dest, src, n);
	if (output)
		printf("%s\n", output);
	else
		printf("null\n");
}*/
