/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_odd_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:08:42 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/09 15:07:22 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_odd_philo(t_philo *philo)
{
	if (philo->id != 1 && philo->next->id == 1)
		usleep(philo->data->time_to_sleep * 500);
	gettimeofday(&((t_philo *)philo)->last_eat, NULL);
	while (1)
	{
		ft_sleeping(philo);
		ft_take_fork(philo, philo);
		ft_take_fork(philo, philo->next);
		ft_eating(philo);
		ft_free_fork(philo);
		ft_free_fork(philo->next);
		if (philo->data->nbr_time_philo_eat == philo->nbr_eat \
		|| ft_is_someone_dead(philo))
			return ;
	}
}
