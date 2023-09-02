/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:07:45 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/02 13:11:25 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_char_to_long(const char *nptr)
{
	size_t	i;
	long	nbr;

	i = 0;
	nbr = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		return (-1);
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
		if (nbr != (((nbr * 10) + (nptr[i] - '0')) / 10))
			return (-1);
		nbr = (nbr * 10) + (nptr[i] - '0');
		i++;
	}
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i])
		return (-1);
	return (nbr);
}
