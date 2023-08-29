/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:33:21 by eguelin           #+#    #+#             */
/*   Updated: 2023/08/29 18:48:01 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_clear_data(t_data *data)
{
	ft_clear_philo(data, data->philo);
	free(data->philo);
	if (ft_mutex_is_lock(data->access))
		pthread_mutex_unlock(&data->access);
	pthread_mutex_destroy(&data->access);
	if (ft_mutex_is_lock(data->is_dead))
		pthread_mutex_unlock(&data->is_dead);
	pthread_mutex_destroy(&data->is_dead);
	return (0);
}
