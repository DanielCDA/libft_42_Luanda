/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danagost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:01:03 by danagost          #+#    #+#             */
/*   Updated: 2026/07/30 16:01:05 by danagost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_val;
	unsigned char		*dest_val;

	if (dest == NULL || src == NULL)
		return (dest);
	if (dest == src || n == 0)
		return (dest);
	src_val = (unsigned char *)src;
	dest_val = (unsigned char *)dest;
	if (dest < src)
	{
		while (n--)
			*dest_val++ = *src_val++;
	}
	else
	{
		dest_val = (unsigned char *)dest + n - 1;
		src_val = (unsigned char *)src + n - 1;
		while (n--)
			*dest_val-- = *src_val--;
	}
	return (dest);
}
