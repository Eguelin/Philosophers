/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:09:18 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/10 14:04:33 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_printf(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->access);
	if (ft_is_someone_dead(philo))
	{
		pthread_mutex_unlock(&philo->data->access);
		return ;
	}
	printf("%ld %d %s", ft_delta_time(philo->data->start), philo->id, str);
	pthread_mutex_unlock(&philo->data->access);
}
