/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:40:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/08/29 18:42:20 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_data(int argc, char **argv, t_data *data)
{
	data->start = 0;
	data->dead = 0;
	if (ft_input(argc, argv, data))
		return (1);
	data->philo = malloc(sizeof(t_philo) * data->nbr_philo);
	if (!data->philo)
		return (1);
	ft_init_philo(data, data->philo);
	pthread_mutex_init(&data->access, NULL);
	pthread_mutex_init(&data->is_dead, NULL);
	gettimeofday(&data->time_start, NULL);
	data->start = 1;
	return (0);
}
