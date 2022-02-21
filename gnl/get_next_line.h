/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:23:16 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/02/21 21:27:31 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

int		ft_strlen(char *str);
int		ft_nchr(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_getline(char *str);
void	ft_getbuffer(char *buffer);
char	*get_next_line(int fd);
#endif
