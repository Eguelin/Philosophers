/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:58:56 by eguelin           #+#    #+#             */
/*   Updated: 2023/08/28 19:21:21 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->nbr % 2)
	{
		pthread_mutex_lock(&philo->fork);
		printf("%ld %ld has taken a fork\n", ft_time_interval(philo->data->start), \
		philo->nbr);
		pthread_mutex_lock(&philo->next->fork);
		printf("%ld %ld has taken a fork\n", ft_time_interval(philo->data->start), \
		philo->nbr);
		printf("%ld %ld is eating\n", ft_time_interval(philo->data->start), \
		philo->nbr);
		usleep(philo->data->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		printf("%ld %ld is sleeping\n", ft_time_interval(philo->data->start), \
		philo->nbr);
	}
	else
	{
		printf("%ld %ld is sleeping\n", ft_time_interval(philo->data->start), \
		philo->nbr);
		usleep(philo->data->time_to_sleep * 1000);
		pthread_mutex_lock(&philo->fork);
		printf("%ld %ld has taken a fork\n", ft_time_interval(philo->data->start), \
		philo->nbr);
		pthread_mutex_lock(&philo->next->fork);
		printf("%ld %ld has taken a fork\n", ft_time_interval(philo->data->start), \
		philo->nbr);
		printf("%ld %ld is eating\n", ft_time_interval(philo->data->start), \
		philo->nbr);
		usleep(philo->data->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
	}
	return (NULL);
}
// void	ft_odd_philo(t_philo *philo)
// {
// 	struct timeval tv;

// 	gettimeofday(&tv, NULL);
// 	printf("%ld %ld has taken a fork", tv.tv_usec - philo->data->start
// ,philo->nbr);
// }

// void	ft_even_philo(t_philo *philo)
// {
// 	struct timeval tv;

// 	gettimeofday(&tv, NULL);
// 	printf("%ld %ld has taken a fork", tv.tv_usec - philo->data->start
// ,philo->nbr);
// }

// void	*ft_thread(void *philo)
// {
// 	int	odd;

// 	odd = ((t_philo *)philo)->nbr % 2;
// 	if (odd && ((t_philo *)philo)->next->nbr == 1)
// 		ft_odd_philo((t_philo *)philo);
// 	else
// 		ft_even_philo((t_philo *)philo);
// 	return (NULL);
// }

	// timestamp_in_ms X has taken a fork
	// timestamp_in_ms X is eating
	// timestamp_in_ms X is sleeping
	// timestamp_in_ms X is thinking
	// timestamp_in_ms X died
