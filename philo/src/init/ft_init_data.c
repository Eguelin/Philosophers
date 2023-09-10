/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:40:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/10 13:10:48 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_data(int argc, char **argv, t_data *data)
{
	if (ft_input(argc, argv, data))
		return (EXIT_FAILURE);
	data->one_dead = 0;
	if (pthread_mutex_init(&data->access, NULL))
		return (ft_perror(NULL, MUTEX_ERROR));
	if (pthread_mutex_init(&data->dead, NULL))
		return (ft_free_all(MUTEX_ERROR, 0, 0, data));
	data->philo = malloc(data->nbr_philo * sizeof(t_philo));
	if (!data->philo)
		return (ft_free_all(MALLOC_ERROR, 0, 0, data));
	if (ft_init_philo(data))
		return (EXIT_FAILURE);
	pthread_mutex_lock(&data->access);
	if (ft_init_thread(data))
		return (EXIT_FAILURE);
	gettimeofday(&data->start, NULL);
	pthread_mutex_unlock(&data->access);
	return (EXIT_SUCCESS);
}
