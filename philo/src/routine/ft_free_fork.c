/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:08:42 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/08 16:21:48 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	philo->lock = 0;
	pthread_mutex_unlock(&philo->fork);
}
