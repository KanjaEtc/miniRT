/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:23:43 by adbarth           #+#    #+#             */
/*   Updated: 2025/11/08 12:34:45 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}*/

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (!s[0])
	{
		if ((unsigned char)c == '\0')
			return ((char *)s);
		return (NULL);
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	while (i > 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i--;
	}
	if (s[0] == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
/*
int main()
{
	const char s[] = "Bonjour";
	int c = 300;
	printf("%s\n", ft_strrchr(s, c));
	printf("%s\n", strrchr(s, c));
}*/
