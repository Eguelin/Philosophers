/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:20:52 by eguelin           #+#    #+#             */
/*   Updated: 2023/08/28 18:38:22 by eguelin          ###   ########lyon.fr   */
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
	int				is_dead;
	struct timeval	start;
	pthread_mutex_t	access;
	struct s_philo	*philo;
}	t_data;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	fork;
	long			nbr;
	long			last_eat;
	int				fork_access;
	struct s_data	*data;
	struct s_philo	*next;
	struct s_philo	*previous;
}	t_philo;

////////// [ philo ] //////////
void	ft_philo_add(t_philo **philo, t_philo *new);
int		ft_philo_birth(t_data *data);
void	ft_philo_end(t_philo **philo);
t_philo	*ft_philo_new(long nbr, t_data *data);

////////// [ thread ] //////////
void	*ft_thread(void *arg);

////////// [ utils ] //////////
int		ft_init_data(int argc, char **argv, t_data *data);
int		ft_input(int argc, char **argv, t_data *data);
int		ft_perror(const char *s, int error);
size_t	ft_strlen(const char *s);
long	ft_time_interval(struct timeval start);

#endif
