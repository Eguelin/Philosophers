/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:20:52 by eguelin           #+#    #+#             */
/*   Updated: 2023/07/03 23:34:09 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
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

typedef struct s_input
{
	long	nbr_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_time_philo_eat;
}	t_input;

typedef struct s_philo
{
}	t_philo;

////////// [ utils ] //////////
int		ft_input(int argc, char **argv, t_input *in);
int		ft_perror(const char *s, int error);
size_t	ft_strlen(const char *s);

#endif
