/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:56:45 by eguelin           #+#    #+#             */
/*   Updated: 2023/08/29 18:52:34 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		pthread_mutex_init(&philo[i].fork, NULL);
		pthread_create(&philo[i].thread, NULL, ft_philo_start, \
		(void *)(&philo[i]));
		i++;
	}
}
