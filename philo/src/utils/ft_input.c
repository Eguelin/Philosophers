/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:11:13 by eguelin           #+#    #+#             */
/*   Updated: 2023/07/03 23:47:10 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	ft_char_to_long(const char *nptr);

int	ft_input(int argc, char **argv, t_input *in)
{
	if (argc < 5)
		return (ft_perror("not enough arguments\n", WRONG_FORMAT));
	else if (argc > 6)
		return (ft_perror("too many arguments\n", WRONG_FORMAT));
	in->nbr_philo = ft_char_to_long(argv[1]);
	if (in->nbr_philo <= 0)
		return (ft_perror("nbr_philo", WRONG_ARGUMENTS));
	in->time_to_die = ft_char_to_long(argv[2]);
	if (in->time_to_die <= 0)
		return (ft_perror("time_to_die", WRONG_ARGUMENTS));
	in->time_to_eat = ft_char_to_long(argv[3]);
	if (in->time_to_eat <= 0)
		return (ft_perror("time_to_eat", WRONG_ARGUMENTS));
	in->time_to_sleep = ft_char_to_long(argv[4]);
	if (in->time_to_sleep <= 0)
		return (ft_perror("time_to_sleep", WRONG_ARGUMENTS));
	if (argv[5])
	{
		in->nbr_time_philo_eat = ft_char_to_long(argv[5]);
		if (in->nbr_time_philo_eat < 0)
			return (ft_perror("nbr_time_philo_eat", WRONG_ARGUMENTS));
	}
	in->nbr_time_philo_eat = -1;
	return (0);
}

static long	ft_char_to_long(const char *nptr)
{
	size_t	i;
	long	nbr;

	i = 0;
	nbr = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		return (-1);
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
		if (nbr != (((nbr * 10) + (nptr[i] - '0')) / 10))
			return (-1);
		nbr = (nbr * 10) + (nptr[i] - '0');
		i++;
	}
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i])
		return (-1);
	return (nbr);
}
