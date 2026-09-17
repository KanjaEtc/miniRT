/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbarth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:59:40 by adbarth           #+#    #+#             */
/*   Updated: 2025/12/11 11:59:57 by adbarth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_gnl_bis(char **stash, char **buf, char **line);
char	*ft_end(char **stash, char **buf, char *line);
int		ft_save_buf_in_stash(char **stash, char *buf);
char	*ft_free(char **buf, char **stash, char **line);
char	*ft_newline_in_buf(char **stash, char **buf, char *line);
char	*ft_strrdup(char *s, char c);
char	*ft_strndup(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);

#endif