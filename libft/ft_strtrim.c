/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:23:34 by ymarques          #+#    #+#             */
/*   Updated: 2023/11/07 16:14:59 by ymarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*new_s;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (is_in_set(s1[i], set))
		i++;
	while (is_in_set(s1[j], set) && j >= i)
		j--;
	new_s = (char *) malloc((j - i + 2) * sizeof(char));
	if (!new_s || new_s == NULL)
		return (NULL);
	k = 0;
	while (k <= j - i)
	{
		new_s[k] = s1[i + k];
		k++;
	}
	new_s[k] = '\0';
	return (new_s);
}
