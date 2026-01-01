/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralrawaj <ralrawaj@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 12:54:38 by ralrawaj          #+#    #+#             */
/*   Updated: 2026/01/01 12:54:39 by ralrawaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*root(char *buf, int bytes_read, int *i)
{
	static char	*sub_str;
	char		*temp;
	char		*ans;
	int			find_endl;

	temp = join(sub_str, buf);
	if (!temp)
		return (NULL);
	find_endl = check_endl(temp);
	if (find_endl == -1)
	{
		if (!bytes_read)
			return (ans = help_root(i, temp, sub_str), sub_str = NULL, ans);
		free(sub_str);
		sub_str = temp;
		return (NULL);
	}
	if (sub_str)
		free(sub_str);
	sub_str = help_with_endl2(find_endl, temp);
	*i = 0;
	ans = help_with_endl1(find_endl, temp);
	free(temp);
	return (ans);
}

char	*help_root(int *i, char *temp, char *sub_str)
{
	char	*ans;

	*i = 0;
	ans = temp;
	free(sub_str);
	if (ans && ans[0] == '\0')
		return (free(ans), NULL);
	return (ans);
}

int	len(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		;
	return (i);
}

char	*join(char *s1, char *s2)
{
	char	*ans;
	int		num1;
	int		num2;
	int		i;

	if (!s1)
		num1 = 0;
	else
		num1 = len(s1);
	if (!s2)
		num2 = 0;
	else
		num2 = len(s2);
	i = 0;
	ans = malloc(num1 + num2 + 1);
	if (ans == NULL)
		return (NULL);
	while (i++ < num1)
		ans[i - 1] = s1[i - 1];
	i = 0;
	while (i++ < num2)
		ans[i + num1 - 1] = s2[i - 1];
	ans[num1 + num2] = '\0';
	return (ans);
}
