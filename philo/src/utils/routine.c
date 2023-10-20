/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:31:39 by 7arzan            #+#    #+#             */
/*   Updated: 2023/10/20 04:19:12 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//	@brief		:	routine of the philosopher
//routine is the function that will be executed by the thread
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

//	@brief		:	Philosopher routine
//here we create the thread and we call the routine function
void	*philo_routine(void *f)
{
	t_data	*data;

	data = (t_data *)f;
	routine(data);
	return (NULL);
}
