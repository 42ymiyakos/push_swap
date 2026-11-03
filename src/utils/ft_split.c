/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiyakos <ymiyakos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:38:00 by ymiyakos          #+#    #+#             */
/*   Updated: 2026/11/03 15:35:22 by ymiyakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// libft の ft_split ("3 2 1" 形式の引数を分割)

#include "push_swap.h"
#include <stdlib.h>

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s)
			++count;
		while (*s && *s != c)
			++s;
	}
	return (count);
}

static char	*dup_word(char const *s, char c)
{
	char	*word;
	size_t	len;
	size_t	i;

	len = 0;
	while (s[len] && s[len] != c)
		++len;
	word = malloc((len + 1) * sizeof(*word));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		++i;
	}
	word[len] = '\0';
	return (word);
}

void	free_split(char **ss)
{
	size_t	i;

	if (ss == NULL)
		return ;
	i = 0;
	while (ss[i] != NULL)
	{
		free(ss[i]);
		++i;
	}
	free(ss);
}

static int	fill_words(char const *s, char c, char **ss)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s)
		{
			ss[i] = dup_word(s, c);
			if (ss[i] == NULL)
				return (0);
			++i;
			while (*s && *s != c)
				++s;
		}
	}
	ss[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ss;

	if (s == NULL)
		return (NULL);
	ss = malloc((count_words(s, c) + 1) * sizeof(*ss));
	if (ss == NULL)
		return (NULL);
	if (!fill_words(s, c, ss))
	{
		free_split(ss);
		return (NULL);
	}
	return (ss);
}
