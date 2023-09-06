/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:05:57 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/06 13:58:12 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_dead(t_philo *philo)
{
	if (ft_delta_time(philo->last_eat) < philo->data->time_to_die)
		return (EXIT_SUCCESS);
	pthread_mutex_lock(&philo->data->dead);
	if (!philo->data->is_dead)
	{
		philo->data->is_dead = 1;
		printf("%li %i died\n", ft_delta_time(philo->data->start), philo->id);
	}
	pthread_mutex_unlock(&philo->data->dead);
	return (EXIT_FAILURE);
}
