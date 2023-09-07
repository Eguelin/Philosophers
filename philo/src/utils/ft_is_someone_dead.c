/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_someone_dead.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:59:36 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/07 16:40:03 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_someone_dead(t_data *data)
{
	pthread_mutex_lock(&data->dead);
	if (data->one_dead)
	{
		pthread_mutex_unlock(&data->dead);
		return (EXIT_FAILURE);
	}
	pthread_mutex_unlock(&data->dead);
	return (EXIT_SUCCESS);
}
