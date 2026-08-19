/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danagost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 10:55:10 by danagost          #+#    #+#             */
/*   Updated: 2026/08/10 10:55:14 by danagost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;
	size_t			i;

	if (!s)
		return (NULL);
	str = (unsigned char *) s;
	ch = (unsigned char) c;
	i = 0;
	while (n)
	{
		if (str[i] == ch)
			return (&str[i]);
		i++;
		n--;
	}
	return (NULL);
}
