/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarques <ymarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:29:24 by ymarques          #+#    #+#             */
/*   Updated: 2024/01/10 15:57:41 by ymarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_var(size_t *i, size_t *j, size_t *count)
{
	if (i)
		*i = 0;
	*j = 0;
	*count = 0;
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	count;

	fill_var(&i, &j, &count);
	if ((!big || !little) && len == 0)
		return (0);
	if (little[0] == '\0')
		return ((char *)big);
	if (len >= ft_strlen(big))
		len = ft_strlen(big);
	while (big[i] != '\0' && i < len)
	{
		while (little[j] != '\0' && (i + j) < len)
		{
			if (little[j] == big[i + j])
				count++;
			j++;
		}
		if (count == ft_strlen(little))
			return ((char *) &big[i]);
		fill_var(NULL, &j, &count);
		i++;
	}
	return (NULL);
}
