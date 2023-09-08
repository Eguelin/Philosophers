/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:20:52 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/08 15:27:23 by eguelin          ###   ########lyon.fr   */
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
	int				one_dead;
	int				nbr_philo_eat_max;
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
void	ft_eating(t_philo *philo);
void	ft_even_philo(t_philo *philo);
void	ft_free_fork(t_philo *philo);
void	ft_odd_philo(t_philo *philo);
void	ft_sleeping(t_philo *philo);
void	*ft_start_routine(void *philo);
void	ft_take_fork(t_philo *philo, t_philo *philo_fork);

////////// [ utils ] //////////
int		ft_atoi(const char *nptr);
long	ft_delta_time(struct timeval t1);
void	ft_is_he_dead(t_data *data);
int		ft_is_someone_dead(t_data *data);
int		ft_perror(const char *s, int error);
void	ft_printf(char *str, t_philo *philo);
size_t	ft_strlen(const char *s);
void	ft_usleep(int time);

#endif
