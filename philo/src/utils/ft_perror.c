/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:16:01 by eguelin           #+#    #+#             */
/*   Updated: 2023/08/31 18:10:28 by eguelin          ###   ########lyon.fr   */
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
	return (1);
}
