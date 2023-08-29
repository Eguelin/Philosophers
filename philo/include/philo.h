/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:20:52 by eguelin           #+#    #+#             */
/*   Updated: 2023/08/29 18:46:42 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef enum e_error
{
	WRONG_FORMAT,
	WRONG_ARGUMENTS,
	MALLOC_ERROR
}	t_error;

typedef struct s_data
{
	int				start;
	int				dead;
	long			nbr_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nbr_time_philo_eat;
	struct s_philo	*philo;
	pthread_mutex_t	is_dead;
	pthread_mutex_t	access;
	struct timeval	time_start;
}	t_data;

typedef struct s_philo
{
	long			id;
	pthread_t		thread;
	pthread_mutex_t	fork;
	struct timeval	last_eat;
	struct s_data	*data;
}	t_philo;

////////// [ philo ] //////////
void	ft_clear_philo(t_data *data, t_philo *philo);
void	ft_init_philo(t_data *data, t_philo *philo);
void	*ft_philo_start(void *arg);

////////// [ utils ] //////////
int		ft_clear_data(t_data *data);
int		ft_init_data(int argc, char **argv, t_data *data);
int		ft_input(int argc, char **argv, t_data *data);
int		ft_mutex_is_lock(pthread_mutex_t mutex);
int		ft_perror(const char *s, int error);
size_t	ft_strlen(const char *s);
long	ft_time_interval(struct timeval start);

#endif
