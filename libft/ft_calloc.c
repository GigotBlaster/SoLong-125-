/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:21:14 by npetitpi          #+#    #+#             */
/*   Updated: 2023/01/25 14:27:54 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if ((nmemb * size) / size != nmemb)
		return (0);
	p = malloc(nmemb * size);
	if (!p)
		return (p);
	ft_bzero(p, nmemb * size);
	return (p);
}
