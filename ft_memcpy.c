/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danagost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:48:35 by danagost          #+#    #+#             */
/*   Updated: 2026/07/30 14:48:38 by danagost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*srch;
	unsigned char		*dstch;

	if (dst == NULL || src == NULL)
		return (dst);
	srch = (const unsigned char *)src;
	dstch = (unsigned char *)dst;
	while (n--)
	{
		*dstch++ = *srch++;
	}
	return (dst);
}
