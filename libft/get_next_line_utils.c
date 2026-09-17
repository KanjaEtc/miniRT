/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:59:33 by adbarth           #+#    #+#             */
/*   Updated: 2025/12/11 11:59:35 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl_free(char **buf, char **stash, char **line)
{
	free(*buf);
	free(*line);
	if (stash)
	{
		if (*stash)
			free(*stash);
		*stash = NULL;
	}
	return (NULL);
}

char	*ft_gnl_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*output;

	i = -1;
	len = 0;
	while (s1 && s1[len])
		len++;
	while (s2 && s2[++i])
		len++;
	output = malloc(sizeof(char) * (len + 1));
	if (!output)
		return (NULL);
	i = 0;
	j = -1;
	while (s1 && s1[++j])
		output[i++] = s1[j];
	j = -1;
	while (s2 && s2[++j])
		output[i++] = s2[j];
	output[i] = '\0';
	return (output);
}

char	*ft_strndup(char *s, char c)
{
	size_t	i;
	int		newline;
	char	*output;

	i = 0;
	newline = 2;
	while (s && s[i] && s[i] != c)
		i++;
	if (s && s[i] != c)
		newline = 1;
	output = malloc(sizeof(char) * (i + newline));
	if (!output)
		return (NULL);
	i = -1;
	while (s && s[++i] && s[i] != c)
		output[i] = s[i];
	if (newline == 2)
		output[i++] = c;
	output[i] = '\0';
	return (output);
}

char	*ft_strrdup(char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*output;

	i = 0;
	j = 0;
	len = 0;
	while (s && s[i] && s[i] != c)
		i++;
	while (s && s[len])
		len++;
	len -= i;
	output = malloc(sizeof(char) * (len + 1));
	if (!output)
		return (NULL);
	if (s && s[i] == c)
		i++;
	while (s && s[i])
		output[j++] = s[i++];
	output[j] = '\0';
	return (output);
}
/*
//int main()
//{
//	//char *s1;
//	//int i = 0;
//	//s1 = malloc(6);
//	//for (i = 0 ; i < 5 ; i++)
//	//	s1[i] = 'a';
//	//s1[i] = '\0';	
//	char s2[] = "qwerty";
//	char *line1, *line2;
//	
//	line1 = ft_strndup(s2, '\n');
//	printf("%s", line1);
//	free(line1);
//	
//	line2 = ft_strrdup(s2, '\n');
//	printf("%s", line2);
//	free(line2);
//	
//	//line3 = ft_strjoin(s1, s2);
//	//printf("%s", line3);
//	//free(line3);
//
//	//free(s1);
//}*/