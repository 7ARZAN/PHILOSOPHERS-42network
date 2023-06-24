/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:31:39 by 7arzan            #+#    #+#             */
/*   Updated: 2023/06/24 20:19:36 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//death function checks if any of the philosophers has died
//if so, it prints the time and the philosopher number and returns 1
//if not, it returns 0

// int	death(t_data *data)
// {
// 	int		i;
// 	long	time;
//
// 	i = -1;
// 	while (++i < data->number_of_philosophers)
// 	{
// 		time = get_time() - data->s_time;
// 		if (time - data->philo[i].last_meal > data->time_to_die)
// 		{
// 			printf("[%ld]	[%d] \033[1;91mdied ☠️\033[0;39m\n", time, i + 1);
// 			return (1);
// 		}
// 	}
// 	return (0);
// }

int	routine(t_data *data)
{
	int	i;

	pthread_mutex_lock(&((t_data *)data)->mutex_id);
	i = data->id - 1;
	data->id++;
	pthread_mutex_unlock(&((t_data *)data)->mutex_id);
	if (i % 2 == 0)
		mssleep(data->time_to_eat);
	while (1)
	{
		pthread_mutex_lock(&((t_data *)data)->mutex_fork);
		take_fork((t_data *)data, i);
		pthread_mutex_unlock(&((t_data *)data)->mutex_fork);
		eat((t_data *)data, i);
		ft_sleep((t_data *)data, i);
		if (data->number_of_philosophers % 2 != 0)
			mssleep(data->time_to_eat);
	}
	return (0);
}

void	*philo_routine(void *f)
{
	t_data	*data;

	data = (t_data *)f;
	routine(data);
	return (NULL);
}
