/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:11:55 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/05 14:28:03 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_free_all(int error, int n_fork, int n_thread, t_data *data)
{
	int	i;

	i = 0;
	while (n_fork > i)
		pthread_mutex_destroy(&data->philo[i++].fork);
	i = 0;
	if (n_thread && error == THREAD_ERROR)
	{
		data->is_die = 1;
		pthread_mutex_unlock(&data->access);
	}
	while (n_thread > i)
		pthread_join(data->philo[i++].thread, NULL);
	pthread_mutex_destroy(&data->access);
	if (error == 0 || error >= MALLOC_ERROR)
		pthread_mutex_destroy(&data->die);
	if (error == 0 || error >= FORK_ERROR)
		free(data->philo);
	if (error >= FORK_ERROR)
		return (ft_perror(NULL, error));
	return (EXIT_SUCCESS);
}
