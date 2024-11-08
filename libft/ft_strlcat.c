/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:50:38 by ymarques          #+#    #+#             */
/*   Updated: 2023/11/08 14:24:03 by ymarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ldst;
	size_t	lsrc;

	if ((!dst || !src) && size == 0)
		return (0);
	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	if (size == 0)
		return (lsrc);
	i = 0;
	if (ldst >= size)
		return (size + lsrc);
	while (src[i] != '\0' && (i + ldst) < size - 1)
	{
		dst[ldst + i] = src[i];
		i++;
	}
	dst[i + ldst] = '\0';
	return (ldst + lsrc);
}
