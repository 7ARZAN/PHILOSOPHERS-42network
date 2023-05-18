/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:03:02 by 7arzan            #+#    #+#             */
/*   Updated: 2023/05/18 02:12:56 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	check_arguments(char *args, int position, t_philo *data)
{
	int	i;

	i = ft_atoi(args);
	if (!i || i < 0 || (position == 1 && i > 200) || (position == 2 && i < 60)
		|| (position == 3 && i < 60) || (position == 4 && i < 60))
	{
		free(data);
		printf("Error: Invalid argument\n");
		return (-1);
	}
	else
	{
		if (position == 1)
			data->number_of_philosophers = i;
		else if (position == 2)
			data->time_to_die = i;
		else if (position == 3)
			data->time_to_eat = i;
		else if (position == 4)
			data->time_to_sleep = i;
		else if (position == 5)
			data->number_of_times_each_philosopher_must_eat = i;
		return (i);
	}
}

int	simulation(t_philo *data)
{
	pthread_mutex_init(&data->mutex_last_meal, NULL);
	pthread_mutex_init(&data->mutex_stat, NULL);
	data->stat = 0;
	data->id = 1;
	if (init_philo(data) == -1)
		return (-1);
	if (create_mutex(data) == -1)
		return (-1);
	data->start_time = get_time();
	if (create_thread(data) == -1)
		return (-1);
	data->init = 1;
	checker(data);
	return (0);
}
