/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:11:13 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/07 14:33:46 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_input(int argc, char **argv, t_data *data)
{
	if (argc < 5)
		return (ft_perror("not enough arguments\n", WRONG_FORMAT));
	else if (argc > 6)
		return (ft_perror("too many arguments\n", WRONG_FORMAT));
	data->nbr_philo = ft_atoi(argv[1]);
	if (data->nbr_philo <= 0)
		return (ft_perror("nbr_philo", WRONG_ARGUMENTS));
	data->time_to_die = ft_atoi(argv[2]);
	if (data->time_to_die <= 0)
		return (ft_perror("time_to_die", WRONG_ARGUMENTS));
	data->time_to_eat = ft_atoi(argv[3]);
	if (data->time_to_eat <= 0)
		return (ft_perror("time_to_eat", WRONG_ARGUMENTS));
	data->time_to_sleep = ft_atoi(argv[4]);
	if (data->time_to_sleep <= 0)
		return (ft_perror("time_to_sleep", WRONG_ARGUMENTS));
	if (argv[5])
	{
		data->nbr_time_philo_eat = ft_atoi(argv[5]);
		if (data->nbr_time_philo_eat < 0)
			return (ft_perror("nbr_time_philo_eat", WRONG_ARGUMENTS));
		return (0);
	}
	data->nbr_time_philo_eat = -1;
	return (0);
}
