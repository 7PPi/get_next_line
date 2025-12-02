/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etchipoq <etchipoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:59:31 by etchipoq          #+#    #+#             */
/*   Updated: 2025/11/18 13:00:26 by etchipoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# ifndef FD_MAX
#  define FD_MAX 1024
# endif
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*read_fil(int fd, char *str, char *buf);
char	*ft_join(char *str, char *str2);
char	*ft_line(char *str);
void	*ft_next(char *str, char *buf);
char	*ft_strchr(const char *str, int to_find);

#endif
