/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:44:43 by ymarques          #+#    #+#             */
/*   Updated: 2023/11/08 14:13:43 by ymarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*pdest;
	char	*psrc;

	if (!dest && !src && n > 0)
		return (NULL);
	i = n - 1;
	pdest = (char *) dest;
	psrc = (char *) src;
	if (src < dest)
	{
		while (i >= 0)
		{
			pdest[i] = psrc[i];
			i--;
		}
	}
	else
	{
		i = -1;
		while (++i < (int) n)
			pdest[i] = psrc[i];
	}
	return (dest);
}
