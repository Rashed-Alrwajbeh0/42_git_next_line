/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralrawaj <ralrawaj@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 12:54:27 by ralrawaj          #+#    #+#             */
/*   Updated: 2026/01/01 13:17:53 by ralrawaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*help_with_endl1(int idx, char *buf)
{
	char	*ans;
	int		i;

	i = -1;
	ans = malloc(idx + 2);
	if (!ans)
		return (NULL);
	while (++i <= idx)
		ans[i] = buf[i];
	ans[i] = '\0';
	return (ans);
}

char	*help_with_endl2(int idx, char *buf)
{
	int		i;
	int		j;
	char	*ans;

	i = len(buf);
	j = 0;
	ans = malloc(i - idx);
	if (!ans)
		return (NULL);
	while (++idx < i)
		ans[j++] = buf[idx];
	ans[j] = '\0';
	return (ans);
}

int	check_endl(char *buf)
{
	int	j;
	int	i;

	i = 0;
	j = len(buf);
	while (i < j)
	{
		if (buf[i] == 10)
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	char	*temp;
	char	*ans;
	int		bytes_that_read;
	int		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ans = NULL;
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	i = 1;
	while (i)
	{
		bytes_that_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_that_read == -1)
			return (free(temp), NULL);
		if (!bytes_that_read)
			return (free(temp), root(NULL, 0, &i));
		temp[bytes_that_read] = '\0';
		ans = root(temp, bytes_that_read, &i);
	}
	free(temp);
	return (ans);
}
