/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etchipoq <etchipoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:59:35 by etchipoq          #+#    #+#             */
/*   Updated: 2025/11/18 12:59:27 by etchipoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int to_find)
{
	int				i;
	unsigned char	c;

	i = 0;
	c = (unsigned char)to_find;
	while (1)
	{
		if ((unsigned char)str[i] == c)
			return ((char *)&str[i]);
		if (str[i] == '\0')
			break ;
		i++;
	}
	return (NULL);
}

void	*ft_next(char *str, char *buf)
{
	int		i;
	int		len;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (!str[i])
	{
		buf[0] = '\0';
		return (NULL);
	}
	len = 0;
	while (str[i] && len < BUFFER_SIZE)
	{
		buf[len] = str[i];
		len++;
		i++;
	}
	buf[len] = '\0';
	return (NULL);
}

char	*ft_line(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	temp = malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		temp[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		temp[i++] = '\n';
	temp[i] = '\0';
	return (temp);
}

char	*ft_join(char *str, char *str2)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (str[i])
		i++;
	j = 0;
	while (str2[j])
		j++;
	temp = malloc(sizeof(char) * (i + j + 1));
	if (!temp)
		return (free(str), NULL);
	i = -1;
	while (str[++i])
		temp[i] = str[i];
	j = 0;
	while (str2[j])
		temp[i++] = str2[j++];
	temp[i] = '\0';
	return (free(str), temp);
}

char	*read_fil(int fd, char *str, char *buf)
{
	int		byte_read;

	if (!str)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	if (buf[0])
		str = ft_join(str, buf);
	byte_read = 1;
	while (byte_read > 0 && !ft_strchr(str, '\n'))
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read < 0)
			return (free(str), NULL);
		buf[byte_read] = '\0';
		str = ft_join(str, buf);
	}
	return (str);
}
