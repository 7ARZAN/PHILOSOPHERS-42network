/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:31:39 by 7arzan            #+#    #+#             */
/*   Updated: 2023/05/31 23:18:27 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//death function checks if any of the philosophers has died
//if so, it prints the time and the philosopher number and returns 1
//if not, it returns 0

int	death(t_data *data)
{
	int		i;
	long	time;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		time = get_time() - data->s_time;
		if (time - data->philo[i].last_meal > data->time_to_die)
		{
			if (data->stat == 0)
			{
				data->stat = 1;
				printf("[%ld]	[%d] \033[1;91mdied ☠️\033[0;39m\n", time, i + 1);
			}
			return (1);
		}
	}
	return (0);
}

int	routine(t_data *data)
{
	int	i;

	pthread_mutex_lock(&((t_data *)data)->mutex_id);
	i = data->id - 1;
	data->id++;
	pthread_mutex_unlock(&((t_data *)data)->mutex_id);
	if (i % 2 == 0)
		mssleep(data->time_to_eat / 2);
	while (data->stat == 0 || death(data) == 0)
	{
		pthread_mutex_lock(&((t_data *)data)->mutex_fork);
		take_fork((t_data *)data, i);
		pthread_mutex_unlock(&((t_data *)data)->mutex_fork);
		eat((t_data *)data, i);
		ft_sleep((t_data *)data, i);
		if (data->number_of_philosophers % 2 != 0)
			mssleep(data->time_to_sleep / 3);
	}
	return (0);
}

void	*philo_routine(void *f)
{
	t_data	*data;

	data = (t_data *)f;
	while (data->init == 0)
		usleep(10);
	if (routine(data) == -1)
		return (NULL);
	return (NULL);
}
