/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:08:42 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/26 18:35:50 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_start_routine(void *philo)
{
	if (!((t_philo *)philo)->data->nbr_time_philo_eat)
	{
		gettimeofday(&((t_philo *)philo)->last_eat, NULL);
		while (!ft_is_someone_dead(philo))
			;
		return (NULL);
	}
	if (((t_philo *)philo)->id >> 0 & 1)
		ft_odd_philo(((t_philo *)philo));
	else
		ft_even_philo(((t_philo *)philo));
	return (NULL);
}
