/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danagost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 17:28:18 by danagost          #+#    #+#             */
/*   Updated: 2026/07/31 17:28:22 by danagost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*resul;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	resul = malloc(sizeof(char) * (len +1));
	if (!resul)
		return (NULL);
	i = 0;
	while (i < len)
	{
		resul[i] = f(i, s[i]);
		i++;
	}
	resul[i] = '\0';
	return (resul);
}
