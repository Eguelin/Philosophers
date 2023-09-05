/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:16:01 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/04 19:31:50 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_perror(const char *s, int error)
{
	write(STDERR_FILENO, "philo: ", 7);
	if (error == WRONG_FORMAT)
	{
		write(STDERR_FILENO, "wrong format: ", 14);
		write(STDERR_FILENO, s, ft_strlen(s));
		write(STDERR_FILENO, "./philo nbr_philo time_to_die time_to_eat "\
		"time_to_sleep [nbr_time_philo_eat]\n", 77);
	}
	else if (error == WRONG_ARGUMENTS)
	{
		write(STDERR_FILENO, "wrong argument: ", 16);
		write(STDERR_FILENO, s, ft_strlen(s));
		write(STDERR_FILENO, ": is not a positive number "\
		"or valid number\n", 43);
	}
	else if (error == MALLOC_ERROR)
		write(STDERR_FILENO, "allocation failure\n", 19);
	else if (error == MUTEX_ERROR || error == FORK_ERROR)
		write(STDERR_FILENO, "mutex failure\n", 14);
	else if (error == THREAD_ERROR)
		write(STDERR_FILENO, "thread failure\n", 15);
	return (1);
}
