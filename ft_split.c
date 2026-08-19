/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danagost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 10:11:33 by danagost          #+#    #+#             */
/*   Updated: 2026/08/06 10:11:37 by danagost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_getword(char const *s, char c, size_t *start)
{
	char	*result;
	size_t	len;
	size_t	i;

	len = 0;
	while (s[*start + len] && s[*start + len] != c)
		len++;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s[*start] && s[*start] != c)
	{
		result[i] = s[*start];
		i++;
		(*start)++;
	}
	result[i] = '\0';
	return (result);
}

static void	ft_freearray(char **result, size_t i)
{
	while (i > 0)
	{
		free(result[i - 1]);
		i--;
	}
	free(result);
}

static size_t	ft_countwords(char const *s, char c)
{
	size_t	cont;
	size_t	i;

	cont = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			cont++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (cont);
}

static int	ft_fill_split(char **result, char const *s, char c, size_t posicao)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < posicao)
	{
		while (s[j] && s[j] == c)
			j++;
		result[i] = ft_getword(s, c, &j);
		if (!result[i])
		{
			ft_freearray(result, i);
			return (0);
		}
		i++;
	}
	result[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	posicao;

	if (!s)
		return (NULL);
	posicao = ft_countwords(s, c);
	result = (char **)malloc(sizeof(char *) * (posicao + 1));
	if (!result)
		return (NULL);
	if (!ft_fill_split(result, s, c, posicao))
		return (NULL);
	return (result);
}
