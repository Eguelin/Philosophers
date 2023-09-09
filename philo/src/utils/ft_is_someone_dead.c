/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_someone_dead.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:59:36 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/09 14:21:43 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_someone_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead);
	if (philo->data->one_dead)
	{
		pthread_mutex_unlock(&philo->data->dead);
		return (EXIT_FAILURE);
	}
	if (ft_delta_time(philo->last_eat) >= philo->data->time_to_die)
	{
		philo->data->one_dead = 1;
		printf("%li %i died\n", ft_delta_time(philo->data->start), philo->id);
		pthread_mutex_unlock(&philo->data->dead);
		return (EXIT_FAILURE);
	}
	pthread_mutex_unlock(&philo->data->dead);
	return (EXIT_SUCCESS);
}
