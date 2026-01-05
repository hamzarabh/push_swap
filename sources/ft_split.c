/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrabh <hrabh@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 10:44:35 by hrabh             #+#    #+#             */
/*   Updated: 2026/01/05 10:30:32 by hrabh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_word(char *str)
{
	int	i;
	int	count;

	if (!str)
		return (-1);
	count = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (i == 0 && str[i] != ' ')
			count++;
		if ((str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\0'))
			count++;
		i++;
	}
	return (count);
}

char	*ft_strdup(char *start, char *end)
{
	char	*res;
	size_t	len;
	size_t	i;

	i = 0;
	len = end - start;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	while (start != end)
	{
		res[i] = *start;
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	ft_free_split(char **strs, int j)
{
	while (j > 0)
	{
		j--;
		free(strs[j]);
	}
	free(strs);
}

char	**ft_hard_split(char *str, char **strs, int i, int j)
{
	char	*start;

	start = NULL;
	while (str[i])
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			start = str + i;
		if (start != NULL)
		{
			if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			{
				strs[j] = ft_strdup(start, (str + i + 1));
				if (strs[j] == NULL)
					return (ft_free_split(strs, j), NULL);
				start = NULL;
				j++;
			}
		}
		i++;
	}
	return (strs[j] = NULL, strs);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		len;
	char	**strs;

	if (!str)
		return (NULL);
	len = count_word(str);
	if (len == 0)
	{
		strs = malloc(sizeof(char *));
		if (!strs)
			return (NULL);
		*strs = NULL;
		return (strs);
	}
	strs = malloc(sizeof(char *) * (len + 1));
	if (!strs)
		return (NULL);
	i = 0;
	j = 0;
	return (ft_hard_split(str, strs, i, j));
}
