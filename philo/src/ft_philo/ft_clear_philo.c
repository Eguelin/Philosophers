/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:33:29 by eguelin           #+#    #+#             */
/*   Updated: 2023/08/29 18:47:45 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_clear_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_join(philo[i].thread, NULL);
		if (ft_mutex_is_lock(philo[i].fork))
			pthread_mutex_unlock(&philo[i].fork);
		pthread_mutex_destroy(&philo[i].fork);
		i++;
	}
}
