/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:03:02 by 7arzan            #+#    #+#             */
/*   Updated: 2023/06/04 05:00:14 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_number_of_args(char *args, int pos, t_data *data)
{
	int	nofp;

	nofp = ft_atoi(args);
	if (!nofp || nofp < 0 || (pos == 1 && nofp > 200) || (pos == 2 && nofp < 60)
		|| (pos == 3 && nofp < 60) || (pos == 4 && nofp < 60))
	{
		free(data);
		write(1, "\033[0;101mError: Invalid Arguments\033[0m\n", 39);
		return (-1);
	}
	else
	{
		if (pos == 1)
			data->number_of_philosophers = nofp;
		if (pos == 2)
			data->time_to_die = nofp;
		if (pos == 3)
			data->time_to_eat = nofp;
		if (pos == 4)
			data->time_to_sleep = nofp;
		if (pos == 5)
			data->philo_eats = nofp;
		return (nofp);
	}
}

int	simulation(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->mutex_last_meal);
	pthread_mutex_lock(&data->mutex_stat);
	pthread_mutex_init(&data->mutex_last_meal, NULL);
	pthread_mutex_init(&data->mutex_stat, NULL);
	data->stat = 0;
	data->id = 1;
	if (init(data) == -1)
		return (-1);
	if (create_mutex(data) == -1)
		return (-1);
	data->s_time = get_time();
	if (create_thread(data) == -1)
		return (-1);
	data->init = 1;
	checker(data);
	pthread_mutex_destroy(&data->mutex_last_meal);
	pthread_mutex_destroy(&data->mutex_stat);
	return (0);
}
