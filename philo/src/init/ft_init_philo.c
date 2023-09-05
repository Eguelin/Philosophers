/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:19:41 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/05 15:04:32 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].lock = 0;
		data->philo[i].nbr_eat = 0;
		if (pthread_mutex_init(&data->philo[i].fork, NULL))
			return (ft_free_all(FORK_ERROR, i + 1, 0, data));
		data->philo[i].data = data;
		if (i == data->nbr_philo - 1)
			data->philo[i].next = &data->philo[0];
		else
			data->philo[i].next = &data->philo[i + 1];
		i++;
	}
	return (EXIT_SUCCESS);
}
