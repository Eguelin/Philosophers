/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:40:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/05 15:11:29 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_data(int argc, char **argv, t_data *data)
{
	if (ft_input(argc, argv, data))
		return (EXIT_FAILURE);
	data->is_die = 0;
	if (pthread_mutex_init(&data->access, NULL))
		return (ft_perror(NULL, MUTEX_ERROR));
	if (pthread_mutex_init(&data->die, NULL))
		return (ft_free_all(MUTEX_ERROR, 0, 0, data));
	data->philo = malloc(data->nbr_philo * sizeof(pthread_mutex_t));
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

// typedef struct s_data
// {
// 	int				nbr_philo;
// 	int				time_to_die;
// 	int				time_to_eat;
// 	int				time_to_sleep;
// 	int				nbr_time_philo_eat;
// 	int				is_die;
// 	pthread_mutex_t	access;
// 	pthread_mutex_t	die;
// 	struct timeval	start;
// 	struct s_philo	*philo;
// }	t_data;

// typedef struct s_philo
// {
// 	int				id;
// 	int				lock;
// 	int				nbr_eat;
// 	pthread_mutex_t	fork;
// 	struct timeval	last_eat;
// 	struct s_philo	*next;
// 	struct s_data	*data;
// 	pthread_t		thread;
// }	t_philo;
