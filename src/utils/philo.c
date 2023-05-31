/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:03:02 by 7arzan            #+#    #+#             */
/*   Updated: 2023/05/31 19:31:22 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	check_num_arg(char *num_arg, int pos, t_list *d)
{
	int	n;

	n = ft_atoi(num_arg);
	if (!n || n < 0 || (pos == 1 && n > 200) || (pos == 2 && n < 60)
		|| (pos == 3 && n < 60) || (pos == 4 && n < 60))
	{
		free(d);
		write(1, "Numero incorrecto.\n", 20);
		return (-1);
	}
	else
	{
		if (pos == 1)
			d->num_philos = n;
		if (pos == 2)
			d->time_die = n;
		if (pos == 3)
			d->time_eat = n;
		if (pos == 4)
			d->time_sleep = n;
		if (pos == 5)
			d->philo_eats = n;
		return (n);
	}
}

static	int	start_simulation(t_list *d)
{
	pthread_mutex_init(&d->mutex_last_eat, NULL);
	pthread_mutex_init(&d->mutex_stat, NULL);
	d->stat = 0;
	d->id = 1;
	if (init_values(d) == -1)
		return (-1);
	if (create_mutex(d) == -1)
		return (-1);
	d->s_time = calc_time();
	if (create_thread(d) == -1)
		return (-1);
	d->init_philo = 1;
	main_checker(d);
	return (0);
}
