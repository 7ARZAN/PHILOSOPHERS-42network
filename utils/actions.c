/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:02:36 by 7arzan            #+#    #+#             */
/*   Updated: 2023/04/24 10:57:33 by 7arzan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo/philo.h>

//status function to print the status of the philo and the time of the status change 
void	status(char *str, t_philo *data, int i)
{
	long	time;

	pthread_mutex_lock(&data->mutex_write);
	time = get_time() - data->start_time;
	if (i < data->number_of_philosophers && check_eat(data) == 0 && data->stat == 0)
		printf("\033[1;89m[%ld]	[%d] \033[0;39m%s", time, i, str);
	pthread_mutex_unlock(&data->mutex_write);
}

//take forks function to take the forks and print the status of the philo
//if the number of philo is 1 then the philo will die after the time to die
void	take_forks(t_philo *data, int i)
{
	pthread_mutex_lock(&data->mutex[data->philo[i].fork_right]);
	status("\033[1;92mhas taken a fork 🍴\033[0;39m\n", data, i + 1);
	if (data->number_of_philosophers == 1)
		mssleep(data->time_to_die + 1);
	pthread_mutex_lock(&data->mutex[data->philo[i].fork_left]);
	status("\033[1;92mhas taken a fork 🍴\033[0;39m\n", data, i + 1);
}

//eat function to eat and print the status of the philo and unlock the forks after eating
//if the number of philo is 1 then the philo will die after the time to die
void	eat(t_philo *data, int i)
{
	status("\033[1;93mis eating 🍝\033[0;39m\n", data, i + 1);
	data->philo[i].last_eat = get_time();
	mssleep(data->time_to_eat);
	data->eat_count[i]++;
	pthread_mutex_unlock(&data->mutex[data->philo[i].fork_right]);
	pthread_mutex_unlock(&data->mutex[data->philo[i].fork_left])
}

//sleeping_thinking function to sleep and print the status of the philo and think after sleeping
//if the number of philo is 1 then the philo will die after the time to die
void 	sleeping_thinking(t_philo *data, int i)
{
	status("\033[1;94mis sleeping 💤\033[0;39m\n", data, i + 1);
	mssleep(data->time_to_sleep);
	status("\033[1;95mis thinking 🤔\033[0;39m\n", data, i + 1);
}
