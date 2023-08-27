/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_birth.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:34:43 by eguelin           #+#    #+#             */
/*   Updated: 2023/08/27 14:02:23 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_birth(t_data *data)
{
	long	i;
	t_philo	*new;

	i = 1;
	new = NULL;
	data->philo = NULL;
	while (i <= data->nbr_philo)
	{
		new = ft_philo_new(i, data);
		if (!new)
		{
			ft_philo_end(&data->philo);
			return (1);
		}
		ft_philo_add(&data->philo, new);
		i++;
	}
	return (0);
}
