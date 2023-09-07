/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:08:42 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/07 18:07:07 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eating(t_philo *philo)
{
	ft_printf("is eating\n", philo);
	usleep(philo->data->time_to_eat * 1000);
	philo->nbr_eat++;
	if (ft_is_someone_dead(philo->data) || ft_is_he_dead(philo))
		return ;
	gettimeofday(&philo->last_eat, NULL);
}
