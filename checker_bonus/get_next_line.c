/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:03:35 by heljary           #+#    #+#             */
/*   Updated: 2024/12/10 20:55:10 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*rd_line(int fd, char *str, char *buffer)
{
	ssize_t	nbytes;
	char	*temp;

	nbytes = read(fd, buffer, BUFFER_SIZE);
	while (nbytes > 0)
	{
		buffer[nbytes] = '\0';
		if (!str)
			str = ft_strdup("");
		temp = ft_strjoin(str, buffer);
		free(str);
		if (!temp)
			return (NULL);
		str = temp;
		if (ft_strchr(str, '\n'))
			break ;
		nbytes = read(fd, buffer, BUFFER_SIZE);
	}
	if (nbytes < 0)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	return (str);
}

static char	*find_newline(char *line)
{
	int		i;
	char	*remainder;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	remainder = ft_strdup(line + i + 1);
	if (!remainder || *remainder == '\0')
	{
		free(remainder);
		remainder = NULL;
	}
	line[i + 1] = '\0';
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = rd_line(fd, str, buffer);
	free(buffer);
	if (!line)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = find_newline(line);
	return (line);
}
