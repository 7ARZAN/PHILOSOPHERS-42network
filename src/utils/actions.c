/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:02:36 by 7arzan            #+#    #+#             */
/*   Updated: 2023/05/31 23:17:57 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	status(char *msg, t_data *data, int i)
{
	long	time;

	pthread_mutex_lock(&data->mutex_write);
	time = get_time() - data->s_time;
	if (i <= data->number_of_philosophers && check_meals(data) == 0 && data->stat == 0)
	{
		printf("\033[1;89m[%ld]	[%d] \033[0;39m%s", time, i, msg);
	}
	pthread_mutex_unlock(&data->mutex_write);
}

void	take_fork(t_data *data, int i)
{
	pthread_mutex_lock(&data->mutex[data->philo[i].fork_right]);
	status("\033[1;92mhas taken a fork 🍴\033[0;39m\n", data, i + 1);
	if (data->number_of_philosophers == 1)
		mssleep(data->time_to_die + 1);
	pthread_mutex_lock(&data->mutex[data->philo[i].fork_left]);
	status("\033[1;92mhas taken a fork 🍴\033[0;39m\n", data, i + 1);
}

void	eat(t_data *data, int i)
{
	status("\033[1;94mis eating 🍝\033[0;39m\n", data, i + 1);
	data->philo[i].number_of_meals++;
	mssleep(data->time_to_eat);
	pthread_mutex_unlock(&data->mutex[data->philo[i].fork_left]);
	pthread_mutex_unlock(&data->mutex[data->philo[i].fork_right]);
	pthread_mutex_lock(&data->mutex_last_meal);
	data->philo[i].last_meal = get_time() - data->s_time;
	pthread_mutex_unlock(&data->mutex_last_meal);
}

void	ft_sleep(t_data *data, int i)
{
	status("\033[1;89mis sleeping 💤\033[0;39m\n", data, i + 1);
	mssleep(data->time_to_sleep);
	status("\033[1;91mis thinking 🤔\033[0;39m\n", data, i + 1);
}
