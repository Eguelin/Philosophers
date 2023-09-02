/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:40:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/02 17:12:03 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_philo(t_data *data, int i)
{
	data->philo[i].id = i + 1;
	pthread_mutex_init(&data->philo[i].fork, NULL);
	data->philo[i].lock = 0;
	data->philo[i].data = data;
	if (i == data->nbr_philo - 1)
		data->philo[i].next = &data->philo[1];
	else
		data->philo[i].next = &data->philo[i + 1];
}
