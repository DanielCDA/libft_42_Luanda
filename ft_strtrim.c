/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danagost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 12:32:21 by danagost          #+#    #+#             */
/*   Updated: 2026/08/03 12:32:26 by danagost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_trim_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	return (start);
}

static size_t	ft_trim_end(char const *s1, char const *set, size_t start)
{
	size_t	end;

	if (s1[start] == '\0')
		return (start);
	end = ft_strlen(s1) - 1;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	return (end);
}

static char	*ft_trim_copy(char const *s1, size_t start, size_t end)
{
	char	*str;
	size_t	i;

	if (s1[start] == '\0')
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = malloc(end - start + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		str[i] = s1[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = ft_trim_start(s1, set);
	end = ft_trim_end(s1, set, start);
	return (ft_trim_copy(s1, start, end));
}
