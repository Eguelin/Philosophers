/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_he_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:05:57 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/08 15:01:13 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_is_he_dead(t_data *data)
{
	int	i;

	i = 0;
	usleep(data->time_to_die * 500);
	while (1)
	{
		pthread_mutex_lock(&data->access);
		if (ft_delta_time(data->philo[i++].last_eat) >= data->time_to_die)
		{
			pthread_mutex_unlock(&data->access);
			pthread_mutex_lock(&data->dead);
			data->one_dead = 1;
			pthread_mutex_unlock(&data->dead);
			printf("%li %i died\n", ft_delta_time(data->start), i);
			return ;
		}
		pthread_mutex_unlock(&data->access);
		if (i == data->nbr_philo)
			i = 0;
		pthread_mutex_lock(&data->access);
		if (data->nbr_philo_eat_max == data->nbr_philo)
			return ((void)pthread_mutex_unlock(&data->access));
		pthread_mutex_unlock(&data->access);
	}
}
