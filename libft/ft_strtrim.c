/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:18:34 by adbarth           #+#    #+#             */
/*   Updated: 2025/11/10 08:12:29 by adbarth          ###   ########.fr       */
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

static char	*ft_trim(char *result, char const *s1, int start, int end)
{
	int	i;

	i = 0;
	while (start < end)
		result[i++] = s1[start++];
	result[i] = '\0';
	return (result);
}

static size_t	ft_is_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*result;

	i = 0;
	j = 0;
	k = ft_strlen(s1);
	result = NULL;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_is_set(s1[i], set))
		i++;
	while (ft_is_set(s1[k - 1], set))
	{
		j++;
		k--;
	}
	if (i == ft_strlen(s1))
		j = 0;
	result = malloc(sizeof(char) * (ft_strlen(s1) - j - i + 1));
	if (!result)
		return (NULL);
	return (ft_trim(result, s1, i, k));
}
/*
int main()
{
	char const s1[] = "gfgfgfgg";
	char const set[] = "6";
	char *output = ft_strtrim(s1, set);
	if (!output)
		printf("null\n");
	else
		printf("%s\n", output);
	free(output);
}*/
