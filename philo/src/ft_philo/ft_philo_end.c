/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:18:04 by eguelin           #+#    #+#             */
/*   Updated: 2023/08/28 19:28:09 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_end(t_philo **philo)
{
	t_philo	*tmp;
	long	i;

	i = 10;
	if (*philo)
		(*philo)->previous->next = NULL;
	while (i--)
		pthread_join((*philo)->thread, NULL);
	while (*philo)
	{
		pthread_mutex_destroy(&(*philo)->fork);
		tmp = *philo;
		*philo = (*philo)->next;
		free(tmp);
	}
}
