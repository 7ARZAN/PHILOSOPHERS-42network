/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:14:07 by 7arzan            #+#    #+#             */
/*   Updated: 2023/10/20 04:12:46 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//1. the function initializes the mutexes and the threads 
//and the philos and the forks cause of 25 lines of code
void	pthread_init(t_data *data)
{
	pthread_mutex_init(&data->mutex_id, NULL);
	pthread_mutex_init(&data->mutex_write, NULL);
	pthread_mutex_init(&data->mutex_fork, NULL);
}

//1. init function to initialize the data structure 
//and the mutexes and threads and the philos and the forks
//2. the function returns 0 if everything is ok 
//and -1 if there is an error in the malloc or in the mutex init
//3. the function also initializes the philos and the forks 
//and the meals and the mutexes and the threads and the init_philo !

int	init(t_data *data)
{
	int	i;

	data->init = 0;
	data->thread = malloc(sizeof(pthread_t *)
			* (data->number_of_philosophers + 1));
	if (!data->thread)
		return (-1);
	pthread_init(data);
	data->philo = malloc(sizeof(t_philo) * data->number_of_philosophers);
	if (!data->philo)
		return (-1);
	data->mutex = malloc(sizeof(pthread_mutex_t)
			* data->number_of_philosophers);
	if (!data->mutex)
		return (-1);
	i = -1;
	while (++i < data->number_of_philosophers)
	{
		pthread_mutex_init(&data->mutex[i], NULL);
		data->philo[i].number_of_meals = 0;
		data->philo[i].fork_right = i - 1;
		data->philo[i].fork_left = i;
	}
	data->philo[0].fork_right = data->number_of_philosophers - 1;
	return (0);
}
