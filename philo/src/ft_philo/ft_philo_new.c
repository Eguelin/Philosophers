/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 23:21:04 by eguelin           #+#    #+#             */
/*   Updated: 2023/08/27 15:17:14 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_philo_new(long nbr, t_data *data)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	pthread_mutex_init(&philo->fork, NULL);
	philo->nbr = nbr;
	philo->last_eat = 0;
	philo->fork_access = 0;
	philo->data = data;
	philo->next = philo;
	philo->previous = philo;
	// pthread_create(&philo->thread, NULL, ft_thread, (void*)philo)
	return (philo);
}
