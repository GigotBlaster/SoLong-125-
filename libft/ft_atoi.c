/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:21:06 by npetitpi          #+#    #+#             */
/*   Updated: 2023/01/12 15:21:08 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		neg;
	int		ret;

	i = 0;
	neg = 1;
	ret = 0;
	while (nptr[i] == ' ' || nptr[i] == '\r' || nptr[i] == '\t' \
	|| nptr[i] == '\v' || nptr[i] == '\n' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		ret = ret * 10 + (nptr[i] - 48);
		i++;
	}
	return (ret * neg);
}
