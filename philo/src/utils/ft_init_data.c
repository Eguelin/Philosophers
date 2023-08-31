/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:40:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/08/31 19:37:28 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *i)
{
	(void)i;
	return (NULL);
}

int	ft_init_data(int argc, char **argv, t_data *data)
{
	int	i;

	i = 0;
	if (ft_input(argc, argv, data))
		return (1);
	data->thread = malloc(sizeof(pthread_t) * data->nbr_philo);
	if (!data->thread)
		return (ft_perror(NULL, MALLOC_ERROR));
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nbr_philo);
	if (!data->fork)
		return (free(data->thread), ft_perror(NULL, MALLOC_ERROR));
	data->philo = malloc(sizeof(t_philo) * data->nbr_philo);
	if (!data->philo)
		return (free(data->thread), free(data->thread), \
		ft_perror(NULL, MALLOC_ERROR));
	while (i < data->nbr_philo)
		pthread_mutex_init(&data->fork[i++], NULL);
	while (i)
		pthread_create(&data->thread[--i], NULL, ft_routine, NULL);
	return (0);
}
