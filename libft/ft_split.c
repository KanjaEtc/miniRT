/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:08:19 by adbarth           #+#    #+#             */
/*   Updated: 2025/11/08 16:46:05 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_sep(char d, char *sep)
{
	int	i;

	if (!sep)
		return (0);
	if (d == '\0')
		return (1);
	i = -1;
	while (sep[++i])
	{
		if (d == sep[i])
			return (1);
	}
	return (0);
}

static char	*ft_strdup_len(char const *s, char *sep)
{
	int		i;
	int		length;
	char	*string;

	if (!s || !sep)
		return (NULL);
	i = 0;
	length = 0;
	while (s[length] && !ft_is_sep(s[length], sep))
		length++;
	string = malloc(sizeof(char) * (length + 1));
	if (!string)
		return (NULL);
	while (i < length)
	{
		string[i] = s[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

static int	ft_count_words(char const *s, char *sep)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	if (!s || !sep)
		return (0);
	while (s[i])
	{
		if (!ft_is_sep(s[i], sep) && ft_is_sep(s[i + 1], sep))
			word++;
		i++;
	}
	return (word);
}

static void	*ft_free(char **result, int count)
{
	int	i;

	i = 0;
	while (count--)
		free(result[i++]);
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char *sep)
{
	int		i;
	int		count;
	char	**result;

	if (!s || !sep)
		return (NULL);
	i = 0;
	count = 0;
	result = malloc(sizeof(char *) * (ft_count_words(s, sep) + 1));
	if (!result)
		return (ft_free(result, count));
	while (s[i])
	{
		if (!ft_is_sep(s[i], sep))
		{
			result[count++] = ft_strdup_len(&s[i], sep);
			if (!result[count - 1])
				return (ft_free(result, count));
			while (!ft_is_sep(s[i], sep))
				i++;
		}
		else
			i++;
	}
	return (result[count++] = NULL, result);
}
/*
int main()
{
	int i = 0;
	char c = ' ';
	char const s[] = "salut salut";
	char **result = ft_split(s, c);
	if (!result)
			printf("null");
	else
	{
		while (result[i])
			printf("%s\n", result[i++]);
	}
	for (int j = 0 ; j < i ; j++)
		free(result[j]);
	free(result);
}*/
