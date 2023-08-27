/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:18:04 by eguelin           #+#    #+#             */
/*   Updated: 2023/08/27 14:00:38 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_end(t_philo **philo)
{
	t_philo	*tmp;

	if (*philo)
		(*philo)->previous->next = NULL;
	while (*philo)
	{
		// pthread_join((*philo)->thread, NULL);
		pthread_mutex_destroy(&(*philo)->fork);
		tmp = *philo;
		*philo = (*philo)->next;
		free(tmp);
	}
}
