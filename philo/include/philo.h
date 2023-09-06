/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:20:52 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/06 13:57:36 by eguelin          ###   ########lyon.fr   */
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
	MUTEX_ERROR,
	MALLOC_ERROR,
	FORK_ERROR,
	THREAD_ERROR
}	t_error;

typedef struct s_data
{
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_time_philo_eat;
	int				is_dead;
	pthread_mutex_t	access;
	pthread_mutex_t	dead;
	struct timeval	start;
	struct s_philo	*philo;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				lock;
	int				nbr_eat;
	pthread_mutex_t	fork;
	struct timeval	last_eat;
	struct s_philo	*next;
	struct s_data	*data;
	pthread_t		thread;
}	t_philo;

////////// [ clear ] //////////
int		ft_free_all(int error, int n_fork, int n_thread, t_data *data);

////////// [ init ] //////////
int		ft_init_data(int argc, char **argv, t_data *data);
int		ft_init_philo(t_data *data);
int		ft_init_thread(t_data *data);

////////// [ parsing ] //////////
int		ft_input(int argc, char **argv, t_data *data);

////////// [ routine ] //////////

////////// [ utils ] //////////
int		ft_atoi(const char *nptr);
long	ft_delta_time(struct timeval t1);
int		ft_is_dead(t_philo *philo);
int		ft_perror(const char *s, int error);
size_t	ft_strlen(const char *s);

#endif
