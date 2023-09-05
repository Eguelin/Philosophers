/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:40:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/05 15:10:00 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_r(void *arg)
{
	return (arg);
}

int	ft_init_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL, \
		ft_r, (void *)&data->philo[i]))
			return (ft_free_all(THREAD_ERROR, data->nbr_philo, i + 1, data));
		i++;
	}
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
