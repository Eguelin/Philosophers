/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:09:18 by eguelin           #+#    #+#             */
/*   Updated: 2023/09/09 16:13:33 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_putnbr(long n);
static void	ft_putchar(char c);

void	ft_printf(char *str, t_philo *philo)
{
	if (ft_is_someone_dead(philo))
		return ;
	pthread_mutex_lock(&philo->data->access);
	ft_putnbr(ft_delta_time(philo->data->start));
	ft_putchar(' ');
	ft_putnbr(philo->id);
	ft_putchar(' ');
	write(1, str, ft_strlen(str));
	pthread_mutex_unlock(&philo->data->access);
}

static void	ft_putnbr(long n)
{
	int		i;
	char	str[19];

	i = 18;
	if (!n)
		str[i--] = '0';
	while (n)
	{
		str[i--] = n % 10 + '0';
		n *= 0.1;
	}
	write(1, str + (i + 1), 18 - i);
}

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}
