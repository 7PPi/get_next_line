/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etchipoq <etchipoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:58:45 by etchipoq          #+#    #+#             */
/*   Updated: 2025/11/17 15:31:58 by etchipoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*lonline;

	lonline = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lonline = read_fil(fd, lonline, buffer);
	if (!lonline)
	{
		buffer[0] = '\0';
		return (NULL);
	}
	line = ft_line(lonline);
	ft_next(lonline, buffer);
	free(lonline);
	return (line);
}
