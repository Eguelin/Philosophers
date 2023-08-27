/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 00:15:14 by eguelin           #+#    #+#             */
/*   Updated: 2023/08/27 13:17:37 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_add(t_philo **philo, t_philo *new)
{
	if (!*philo)
		*philo = new;
	else
	{
		new->next = *philo;
		new->previous = (*philo)->previous;
		(*philo)->previous->next = new;
		(*philo)->previous = new;
	}
}
