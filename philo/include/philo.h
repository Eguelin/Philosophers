/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:20:52 by eguelin           #+#    #+#             */
/*   Updated: 2023/08/31 19:33:39 by eguelin          ###   ########lyon.fr   */
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
	long			nbr_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nbr_time_philo_eat;
	pthread_mutex_t	*fork;
	pthread_t		*thread;
	struct s_philo	*philo;
}	t_data;

typedef struct s_philo
{
	long			id;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

////////// [ utils ] //////////
int		ft_clear_data(t_data *data);
int		ft_init_data(int argc, char **argv, t_data *data);
int		ft_input(int argc, char **argv, t_data *data);
int		ft_mutex_is_lock(pthread_mutex_t mutex);
int		ft_perror(const char *s, int error);
size_t	ft_strlen(const char *s);
long	ft_time_interval(struct timeval start);

#endif
