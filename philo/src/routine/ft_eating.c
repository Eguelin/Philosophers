/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:08:42 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/09 16:12:54 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eating(t_philo *philo)
{
	ft_printf("is eating\n", philo);
	gettimeofday(&philo->last_eat, NULL);
	ft_usleep(philo->data->time_to_eat, philo);
	if (ft_is_someone_dead(philo))
		return ;
	philo->nbr_eat++;
}
