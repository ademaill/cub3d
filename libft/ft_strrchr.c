/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:54:07 by ymarques          #+#    #+#             */
/*   Updated: 2023/11/09 17:49:39 by ymarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*ps;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	ps = (char *) s;
	j = i;
	while (j >= 0)
	{
		if (ps[j] == (char) c)
			return (&ps[j]);
		j--;
	}
	return (NULL);
}
