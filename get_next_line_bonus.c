/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etchipoq <etchipoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:58:45 by etchipoq          #+#    #+#             */
/*   Updated: 2025/11/17 15:31:56 by etchipoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	char		*lonline;

	lonline = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	lonline = read_fil(fd, lonline, buffer[fd]);
	if (!lonline)
	{
		buffer[fd][0] = '\0';
		return (NULL);
	}
	line = ft_line(lonline);
	ft_next(lonline, buffer[fd]);
	free(lonline);
	return (line);
}
