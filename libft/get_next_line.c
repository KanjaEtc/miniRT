/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:59:14 by adbarth           #+#    #+#             */
/*   Updated: 2025/12/11 11:59:24 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_update_stash(char *stash)
{
	char	*new_stash;
	int		n;
	int		len;
	int		i = 0;

	if (!stash)
		return (NULL);
	n = ft_strlen_with_limiter_included(stash, '\n');
	len = ft_strlen_with_limiter_included(stash, '\0');
	new_stash = malloc(sizeof(char) * (len - n + 1));
	if (!new_stash)
		return (free(stash), stash = NULL, NULL);
	while (*stash && stash[n])
		new_stash[i++] = stash[n++];
	new_stash[i] = '\0';
	free(stash);
	stash = NULL;
	return (new_stash);
}

char	*ft_extract_line(char *stash)
{
	char	*line;
	int		n;
	int		i = -1;

	if (!stash || !*stash)
		return (NULL);
	n = ft_strlen_with_limiter_included(stash, '\n');
	line = malloc(sizeof(char) * (n + 1));
	if (!line)
		return (NULL);
	while (stash[++i] && i < n)
		line[i] = stash[i];
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		buf[43];
	char		*line;
	ssize_t		bytes;

	while (!ft_is_in(stash, '\n'))
	{
		bytes = read(fd, buf, 42);
		if (bytes <= 0)
			break ;
		buf[bytes] = '\0';
		stash = ft_strjoin_and_free_s1(stash, buf);
		if (!stash)
			return (NULL);
	}
	if (!stash || !*stash)
		return (free(stash), stash = NULL, NULL);
	line = ft_extract_line(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	stash = ft_update_stash(stash);
	if (!stash)
		return (free(line), NULL);
	return (line);
}

// int	main()
// {
// 	int fd = open("../Makefile", O_RDONLY);
// 	if (fd < 0)
// 		return (1);
// 	char *line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	free(line);
// }
