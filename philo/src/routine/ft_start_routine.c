/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:08:42 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/07 18:15:00 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_start_routine(void *philo)
{
	pthread_mutex_lock(&((t_philo *)philo)->data->access);
	pthread_mutex_unlock(&((t_philo *)philo)->data->access);
	gettimeofday(&((t_philo *)philo)->last_eat, NULL);
	if (((t_philo *)philo)->id >> 0 & 1)
		ft_odd_philo(((t_philo *)philo));
	else
		ft_even_philo(((t_philo *)philo));
	return (NULL);
}
