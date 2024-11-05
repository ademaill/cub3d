/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:52:36 by ymarques          #+#    #+#             */
/*   Updated: 2023/11/09 17:37:19 by ymarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*new_s;

	if (!s)
		return (NULL);
	new_s = (char *) malloc((len + 1) * sizeof(char));
	if (!new_s || new_s == NULL)
		return (NULL);
	i = 0;
	while (i < len && start < ft_strlen(s))
	{
		new_s[i] = s[start];
		i++;
		start++;
	}
	new_s[i] = '\0';
	return (new_s);
}
