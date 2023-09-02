/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:22:28 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/02 15:05:45 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_clear_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
		pthread_join(data->philo[i++].thread, NULL);
	while (i)
		pthread_mutex_destroy(&data->philo[--i].fork);
	free(data->philo);
	return (0);
}
