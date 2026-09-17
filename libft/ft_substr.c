/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:59:10 by adbarth           #+#    #+#             */
/*   Updated: 2025/11/10 08:18:26 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*size_t	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}*/

static char	*ft_corner_case(char *result)
{
	result = malloc(sizeof(char));
	if (!result)
		return (NULL);
	result[0] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	new_start;
	size_t	size;
	char	*result;

	i = 0;
	new_start = start;
	result = NULL;
	if (!s)
		return (NULL);
	if (!s[0] || new_start >= ft_strlen(s))
		return (ft_corner_case(result));
	if (len >= ft_strlen(s) + 1 - start)
		size = ft_strlen(s) + 1 - start;
	else
		size = len + 1;
	result = malloc(sizeof(char) * size);
	if (!result)
		return (NULL);
	while (s[new_start] && i < len)
		result[i++] = s[new_start++];
	result[i] = '\0';
	return (result);
}

/*int main()
{
	char const s[] = "hola";
	unsigned int start = 0;
	size_t len = 3;
	char *ft_output = ft_substr(s, start, len);
	if (ft_output)
		printf("%s\n", ft_output);
	else
		printf("null\n");
	free(ft_output);
}*/
