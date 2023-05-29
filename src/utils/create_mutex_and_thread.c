/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mutex_and_thread.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:04:24 by 7arzan            #+#    #+#             */
/*   Updated: 2023/05/29 18:29:56 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//create mutex for each philo and for the data
int	create_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		if (pthread_mutex_init(&data->philo[i], NULL) != 0)
			return (-1);
	}
	return (0);
}

//create thread for each philo and start the routine for each philo
//lock the mutex for the last_meal and set it to 0 for each philo 
//unlock the mutex for the last_meal and start the routine for each philo
int	create_thread(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		pthread_mutex_lock(&data->philo[i].mutex_last_meal);
		data->philo[i].last_meal = 0;
		pthread_mutex_unlock(&data->philo[i].mutex_last_meal);
		if (pthread_create(&data->philo[i], NULL, &routine, (void *)data) != 0)
			return (-1);
	}
	return (0);
}
