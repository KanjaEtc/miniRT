/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:26:28 by adbarth           #+#    #+#             */
/*   Updated: 2025/11/08 09:51:36 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include "libft.h"

/*size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}*/

static size_t	ft_char_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	j;

	i = ft_char_strlen(dest);
	j = 1;
	dest_len = ft_char_strlen(dest);
	if (size <= dest_len)
		return (ft_strlen(src) + size);
	while (*src && j + dest_len < size)
	{
		dest[i++] = *src++;
		j++;
	}
	dest[i] = '\0';
	return (ft_char_strlen(dest) + ft_strlen(src));
}
/*
int main()
{
	char dest[10] = "hey ";
	const char src[] = "salut!!";
	size_t size = 10;
	//printf("%zu\n", ft_strlcat(dest, src, size));
	printf("%zu\n", strlcat(dest, src, size));
	printf("%s\n", dest);
}*/
