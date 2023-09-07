/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_odd_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:08:42 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/07 18:14:32 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_odd_philo(t_philo *philo)
{
	while (1)
	{
		ft_sleeping(philo);
		ft_take_fork(philo, philo);
		ft_take_fork(philo, philo->next);
		ft_eating(philo);
		ft_free_fork(philo);
		ft_free_fork(philo->next);
		if (philo->data->nbr_time_philo_eat == philo->nbr_eat \
		|| ft_is_someone_dead(philo->data) || ft_is_he_dead(philo))
			return ;
	}
}
