/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:41:06 by dmadelei          #+#    #+#             */
/*   Updated: 2020/12/01 17:37:39 by dmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*read_in_buffer (int fd, long len_buf, char **ostatok, int *key);
char	*ft_strjoin(char *s1, char *s2);
char	*create_buf(long len_buf);
size_t	ft_strlen(const char *s);
int		cheak_file_descriptor_and_buf(long len_buf, int fd);
int		get_next_line(int fd, char **line);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*chek_remain(char *ostatoc, char **result);
char	*ft_strcpy(char *dst, char *src);
#endif
