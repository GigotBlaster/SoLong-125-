/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:23:39 by npetitpi          #+#    #+#             */
/*   Updated: 2023/01/12 15:23:41 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	while (c > 255)
		c = c - 256;
	i = 0;
	while (s[i])
		i++;
	while (&s[i] >= &s[0])
	{
		if (s[i] == c)
			return ((char *)(&s[i]));
		i--;
	}
	return (0);
}
