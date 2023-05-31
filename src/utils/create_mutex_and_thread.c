/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mutex_and_thread.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:04:24 by 7arzan            #+#    #+#             */
/*   Updated: 2023/05/31 19:23:56 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	create_mutex(t_list *d)
{
	int	i;

	i = -1;
	while (++i < d->num_philos)
	{
		if (pthread_mutex_init(&d->mutex[i], NULL) != 0)
			return (-1);
	}
	return (0);
}

int	create_thread(t_list *d)
{
	int	i;

	i = -1;
	while (++i < d->num_philos)
	{
		pthread_mutex_lock(&d->mutex_last_eat);
		d->philo[i].last_eat = 0;
		pthread_mutex_unlock(&d->mutex_last_eat);
		if (pthread_create(&d->thread[i], NULL, &philo_routine, (void *)d) != 0)
			return (-1);
	}
	return (0);
}
