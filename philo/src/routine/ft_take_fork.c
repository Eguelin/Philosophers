/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:08:42 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/07 18:15:13 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_fork(t_philo *philo, t_philo *philo_fork)
{
	while (1)
	{
		pthread_mutex_lock(&philo_fork->fork);
		if (!philo_fork->lock)
		{
			philo_fork->lock = 1;
			pthread_mutex_unlock(&philo_fork->fork);
			ft_printf("has taken a fork\n", philo);
			return ;
		}
		pthread_mutex_unlock(&philo_fork->fork);
		if (ft_is_someone_dead(philo->data) || ft_is_he_dead(philo))
			return ;
	}
}
