/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:23:35 by npetitpi          #+#    #+#             */
/*   Updated: 2023/01/12 15:23:37 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	size_l;
	size_t	count;

	size_l = ft_strlen(little);
	if (!size_l)
		return ((char *)(big));
	count = 0;
	while (*big && size_l <= len && count < len)
	{
		if (*big == *little)
		{
			if (ft_strncmp(big, little, size_l) == 0 \
				&& size_l <= len - count)
				return ((char *)big);
		}
		big++;
		count++;
	}
	return (0);
}
