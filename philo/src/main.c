/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:15:09 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/08 13:51:40 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (ft_init_data(argc, argv, &data))
		return (1);
	ft_is_he_dead(&data);
	return (ft_free_all(EXIT_SUCCESS, data.nbr_philo, data.nbr_philo, &data));
}
