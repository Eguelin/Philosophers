/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_interval.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:49:31 by eguelin           #+#    #+#             */
/*   Updated: 2023/08/28 17:52:27 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_time_interval(struct timeval start)
{
	struct timeval	tv;
	long			sec;
	long			usec;

	gettimeofday(&tv, NULL);
	sec = (tv.tv_sec - start.tv_sec) * 1000;
	usec = (tv.tv_usec - start.tv_usec) / 1000;
	return (sec + usec);
}
