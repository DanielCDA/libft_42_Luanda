/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danagost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 11:35:26 by danagost          #+#    #+#             */
/*   Updated: 2026/07/30 11:35:28 by danagost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	strl;
	size_t	i;

	if (!src)
		return (0);
	strl = ft_strlen(src);
	if (size == 0)
		return (strl);
	i = 0;
	if (!dst)
		return (strl);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (strl);
}
