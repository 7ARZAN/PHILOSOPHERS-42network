/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:31:39 by 7arzan            #+#    #+#             */
/*   Updated: 2023/05/30 21:42:46 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//philosopher_death function checks if any of the philosophers has died
//if so, it prints the time and the philosopher number and returns 1
//if not, it returns 0

int	philosopher_death(t_data *data)
{
	int	i;
	long	time;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		time = get_time() - data->start_time;
		if (time - data->philo[i].last_meal > data->time_to_die)
		{
			pthread_mutex_lock(&data->mutex_write);
			printf("[%ld]	[%d] \033[1;91mdied ☠️\033[0;39m\n", time, i + 1);
			return (1);
		}
	}
	return (0);
}

int	routine(t_data *data)
{
	int	i;

	pthread_mutex_lock(&((t_data *)data)->mutex_i);
	i = data->id - 1;
	data->id++;
	pthread_mutex_unlock(&((t_data *)data)->mutex_i);
	if (i % 2 == 0)
		mssleep(data->time_to_eat / 2);
	while (data->stat == 0 && philosopher_death(data) == 0)
	{
		pthread_mutex_lock(&((t_data *)data)->mutex_forks);
		take_forks((t_data *)data, i);
		pthread_mutex_unlock(&((t_data *)data)->mutex_forks);
		eat((t_data *)data, i);
		mssleep(data->time_to_sleep);
		if (data->number_of_philosophers % 2 != 0)
			mssleep(data->time_to_sleep / 3);
	}
	return (0);
}

void	*philo_routine(void *f)
{
	t_data	*data;

	data = (t_data *)f;
	while (data->init_philo == 0)
	{
		usleep(10);
	}
	if (routine(data) == -1)
		return (NULL);
	return (NULL);
}
