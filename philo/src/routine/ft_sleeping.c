/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleeping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:08:42 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/08 16:21:44 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleeping(t_philo *philo)
{
	ft_printf("is sleeping\n", philo);
	ft_usleep(philo->data->time_to_sleep);
	// usleep(philo->data->time_to_sleep * 1000);
	ft_printf("is thinking\n", philo);
}
