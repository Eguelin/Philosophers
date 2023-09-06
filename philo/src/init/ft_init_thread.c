/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:40:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/06 13:02:52 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_r(void *arg)
{
	return (arg);
}

int	ft_init_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL, \
		ft_r, (void *)&data->philo[i]))
			return (ft_free_all(THREAD_ERROR, data->nbr_philo, i + 1, data));
		i++;
	}
	return (EXIT_SUCCESS);
}
