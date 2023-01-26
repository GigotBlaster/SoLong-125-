/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:22:40 by npetitpi          #+#    #+#             */
/*   Updated: 2023/01/12 15:22:41 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const void	*s;
	void		*d;

	if (src < dest && dest < src + n)
	{
		while (n--)
		{
			d = dest + n;
			s = src + n;
			*(char *)d = *(char *)s;
		}
		return (d);
	}
	return (ft_memcpy(dest, src, n));
}
