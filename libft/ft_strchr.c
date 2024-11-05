/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:17:11 by ymarques          #+#    #+#             */
/*   Updated: 2023/11/08 15:49:42 by ymarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*ps;

	i = 0;
	ps = (char *) s;
	while (ps[i] != '\0')
	{
		if (ps[i] == (char) c)
			return (&ps[i]);
		i++;
	}
	if (ps[i] == '\0' && (char) c == '\0')
		return (&ps[i]);
	return (NULL);
}
