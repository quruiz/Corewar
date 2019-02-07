/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit_trim.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/05 18:21:13 by quruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 18:55:40 by quruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int		i;
	int		nb_words;

	i = 0;
	nb_words = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c)
			nb_words++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (nb_words);
}

char		**ft_strsplit_trim(char const *s, char c)
{
	char	**split;
	char	*tmp;
	int		i;
	int		cursor;
	int		nb_words;

	i = 0;
	cursor = 0;
	nb_words = count_words(s, c);
	if (!(split = (char **)ft_memalloc(sizeof(char *) * (nb_words + 1))))
		return (NULL);
	while (i < nb_words)
	{
		tmp = ft_strchr(s + cursor, c);
		if (!tmp)
			tmp = ft_strchr(s + cursor, '\0');
		cursor = (tmp - s);
		tmp = ft_strsub(s, cursor, (tmp - (s + cursor)));
		split[i] = ft_strtrim(tmp);
		free(tmp);
		while (s[cursor] && s[cursor] == c)
			cursor++;
		i++;
	}
	return (split);
}
