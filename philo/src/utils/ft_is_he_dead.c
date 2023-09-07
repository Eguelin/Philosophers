/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_he_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:05:57 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/06 16:56:21 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_he_dead(t_philo *philo)
{
	if (ft_delta_time(philo->last_eat) < philo->data->time_to_die)
		return (EXIT_SUCCESS);
	pthread_mutex_lock(&philo->data->dead);
	philo->data->one_dead = 1;
	pthread_mutex_unlock(&philo->data->dead);
	printf("%li %i died\n", ft_delta_time(philo->data->start), philo->id);
	return (EXIT_FAILURE);
}
