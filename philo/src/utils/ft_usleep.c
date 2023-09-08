/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:16:06 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/08 16:21:35 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(int time)
{
	struct timeval	t1;

	gettimeofday(&t1, NULL);
	while (ft_delta_time(t1) < time)
		;
}
