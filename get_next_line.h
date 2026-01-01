/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralrawaj <ralrawaj@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 12:54:31 by ralrawaj          #+#    #+#             */
/*   Updated: 2026/01/01 12:54:32 by ralrawaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

char	*get_next_line(int fd);
char	*join(char *s1, char *s2);
int		len(char *str);
char	*root(char *buf, int bytes_read, int *i);
char	*help_with_endl1(int idx, char *buf);
char	*help_root(int *i, char *temp, char *sub_str);
char	*help_with_endl2(int idx, char *buf);
int		check_endl(char *buf);
#endif
