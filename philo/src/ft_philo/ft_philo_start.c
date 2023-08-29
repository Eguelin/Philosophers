/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:07:22 by eguelin           #+#    #+#             */
/*   Updated: 2023/08/29 18:09:12 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_start(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->data->start)
		;
	gettimeofday(&philo->last_eat, NULL);
	printf("%ld %ld it's time\n", ft_time_interval(philo->data->time_start), \
	philo->id);
	return (NULL);
}
