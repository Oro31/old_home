/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:13:34 by rvalton           #+#    #+#             */
/*   Updated: 2019/09/19 18:49:23 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_sep(char c, char *charset)
{
	int i;

	i = 0;
	while (*(charset + i) != '\0')
	{
		if (c == *(charset + i))
			return (1);
		i++;
	}
	return (0);
}

int		word_count(char *str, char *charset)
{
	int i;
	int c;
	int wc;

	wc = 0;
	c = 0;
	i = 0;
	while (*(str + i) != '\0')
	{
		if (!is_sep(*(str + i), charset))
			c++;
		else if (c > 0 && is_sep(*(str + i), charset))
		{
			wc++;
			c = 0;
		}
		i++;
	}
	if (c > 0)
		wc++;
	return (wc);
}

char	*start_word(char *str, char *charset, int nbword)
{
	int i;

	if (!is_sep(*str, charset))
		nbword--;
	i = 1;
	while (nbword > 0 && *(str + i) != '\0')
	{
		if (is_sep(*(str + i - 1), charset) && !is_sep(*(str + i), charset))
			nbword--;
		i++;
	}
	return (str + i - 1);
}

int		wl(char *str, char *charset, int nbword)
{
	int		i;
	char	*start;

	start = start_word(str, charset, nbword);
	i = 0;
	while (*(start + i))
	{
		if (is_sep(*(start + i), charset))
			return (i);
		i++;
	}
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		i;
	int		j;
	int		nbword;

	nbword = word_count(str, charset);
	if (!(split = malloc(sizeof(char *) * (nbword + 1))))
		return (0);
	i = 0;
	while (i < nbword)
	{
		if (!(split[i] = malloc(sizeof(char) * (wl(str, charset, i + 1) + 1))))
			return (0);
		j = -1;
		while (++j < wl(str, charset, i + 1))
		{
			split[i][j] = *(start_word(str, charset, i + 1) + j);
		}
		split[i][j] = '\0';
		i++;
	}
	split[i] = NULL;
	return (split);
}
