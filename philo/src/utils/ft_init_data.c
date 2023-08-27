/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:40:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/08/27 14:01:49 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_data(int argc, char **argv, t_data *data)
{
	if (ft_input(argc, argv, data))
		return (1);
	data->is_dead = 0;
	data->start = 0;
	if (ft_philo_birth(data))
		return (1);
	return (0);
}
