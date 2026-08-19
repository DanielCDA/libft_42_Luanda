/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danagost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 15:56:51 by danagost          #+#    #+#             */
/*   Updated: 2026/08/18 09:16:49 by danagost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	numlen(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	len;
	long	nb;

	len = numlen(n);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	nb = n;
	if (nb == 0)
		s[0] = '0';
	if (n < 0)
	{
		s[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		len--;
		s[len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (s);
}
