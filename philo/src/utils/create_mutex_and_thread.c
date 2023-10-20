/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mutex_and_thread.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:04:24 by 7arzan            #+#    #+#             */
/*   Updated: 2023/10/20 04:11:21 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//	@brief		:	Create mutexes
int	create_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		if (pthread_mutex_init(&data->mutex[i], NULL) != 0)
			return (-1);
	}
	return (0);
}

//	@brief		:	Create threads
int	create_thread(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		pthread_mutex_lock(&data->mutex_last_meal);
		data->philo[i].last_meal = 0;
		pthread_mutex_unlock(&data->mutex_last_meal);
		if (pthread_create(&data->thread[i], NULL,
				&philo_routine, (void *)data) != 0)
			return (-1);
	}
	return (0);
}
