/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:12:06 by achansar          #+#    #+#             */
/*   Updated: 2023/03/14 15:12:12 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*char_b;

	char_b = (char *) b;
	if (len < 1)
		return (b);
	i = 0;
	while (i < len)
	{
		char_b[i] = c;
		i++;
	}
	return (b);
}

static char	*ft_split_gnl(char *full)
{
	int		i;
	int		j;
	char	*left;

	if (!full)
		return (NULL);
	i = 0;
	while (full[i])
	{
		if (full[i++] == '\n')
			break ;
	}
	left = malloc(sizeof(char) * (ft_strlen_gnl(full + i) + 1));
	if (!left)
		return (ft_free_all_gnl(0, &full));
	j = 0;
	while (full[i])
		left[j++] = full[i++];
	left[j] = '\0';
	ft_free_all_gnl(0, &full);
	return (left);
}

static char	*ft_readline(int fd, char *save)
{
	int		byte_read;
	char	*buff;

	byte_read = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (!save)
	{
		save = malloc(sizeof(char) * 1);
		if (!save)
			return (ft_free_all_gnl(buff, 0));
		save[0] = '\0';
	}
	ft_memset(buff, '\0', BUFFER_SIZE + 1);
	while (ft_isin(buff, '\n') && byte_read > 0)
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read == -1)
			return (ft_free_all_gnl(buff, &save));
		buff[byte_read] = '\0';
		save = ft_strjoin_gnl(save, buff);
	}
	free (buff);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX
		|| BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	save = ft_readline(fd, save);
	if (!save)
		return (NULL);
	line = ft_strdup_nl(save);
	if (!line)
		return (NULL);
	save = ft_split_gnl(save);
	if (!save || !line)
		return (ft_free_all_gnl(line, &save));
	return (line);
}
