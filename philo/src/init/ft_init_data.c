/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:40:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/02 15:57:10 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_data(int argc, char **argv, t_data *data)
{
	int	i;

	i = 0;
	if (ft_input(argc, argv, data))
		return (1);
	data->philo = malloc(sizeof(t_philo) * data->nbr_philo);
	if (!data->philo)
		return (ft_perror(NULL, MALLOC_ERROR));
	while (i < data->nbr_philo)
		ft_init_philo(data, i++);
	gettimeofday(&data->start, NULL);
	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_create(&data->philo[i].thread, NULL, ft_routine, \
		(void *)&data->philo[i]);
		i++;
	}
	return (0);
}
