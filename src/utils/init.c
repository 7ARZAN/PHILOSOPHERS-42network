/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:14:07 by 7arzan            #+#    #+#             */
/*   Updated: 2023/05/31 19:26:12 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//init function to initialize the data structure and the mutexes and threads and the philos and the forks
//the function returns 0 if everything is ok and -1 if there is an error in the malloc or in the mutex init
//the function also initializes the philos and the forks and the meals and the mutexes and the threads and the init_philo !

int	init(t_list *d)
{
	int	i;

	d->init_philo = 0;
	d->thread = malloc(sizeof(pthread_t *) * (d->num_philos));
	if (!d->thread)
		return (-1);
	pthread_mutex_init(&d->mutex_i, NULL);
	pthread_mutex_init(&d->mutex_msg, NULL);
	pthread_mutex_init(&d->mutex_fork, NULL);
	d->philo = malloc(sizeof(t_philo) * d->num_philos);
	if (!d->philo)
		return (-1);
	d->mutex = malloc(sizeof(pthread_mutex_t) * d->num_philos);
	if (!d->mutex)
		return (-1);
	i = -1;
	while (++i < d->num_philos)
	{
		d->philo[i].num_eats = 0;
		d->philo[i].fork_r = i - 1;
		d->philo[i].fork_l = i;
	}
	d->philo[0].fork_r = d->num_philos - 1;
	return (0);
}
