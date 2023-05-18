/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:14:07 by 7arzan            #+#    #+#             */
/*   Updated: 2023/05/18 02:12:19 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

//init function to initialize the data structure and the mutexes and threads and the philos and the forks
//the function returns 0 if everything is ok and -1 if there is an error in the malloc or in the mutex init
//the function also initializes the philos and the forks and the meals and the mutexes and the threads and the init_philo !
int	init(t_philo *data)
{
	int	i;

	i = 0;
	data->init_philo = 0;
	data->thread = malloc(sizeof(pthread_t) * data->number_of_philosophers);
	if (!data->thread)
		return (-1);
	pthread_mutex_init(&data->mutex_i, NULL);
	pthread_mutex_init(&data->mutex_write, NULL);
	pthread_mutex_init(&data->mutex_forks, NULL);
	data->philo = malloc(sizeof(t_philo) * data->number_of_philosophers);
	if (!data->philo)
		return (-1);
	data->mutex = malloc(sizeof(pthread_mutex_t) * data->number_of_philosophers);
	if (!data->mutex)
		return (-1);
	i = -1;
	while (++i < data->number_of_philosophers)
	{
		data->philo[i].meals = 0;
		data->philo[i].forks = i - 1;
		data->philo[i].forks2 = i;
	}
	data->philo[0].forks = data->number_of_philosophers - 1;
	return (0);
}
