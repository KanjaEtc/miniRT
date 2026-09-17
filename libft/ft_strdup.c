/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:03:00 by adbarth           #+#    #+#             */
/*   Updated: 2025/11/10 07:36:44 by adbarth          ###   ########.fr       */
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

char	*ft_strdup(const char *s)
{
	int		i;
	char	*result;

	i = 0;
	result = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
		return (NULL);
	while (*s)
		result[i++] = *s++;
	result[i] = '\0';
	return (result);
}

/*int main()
{
	const char s[] = "";
	char *ft_output = ft_strdup(s);
	char *output = strdup(s);
	printf("ft = %s\nok = %s\n", ft_output, output);
	free(ft_output);
	free(output);
}*/
