/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:52:28 by 7arzan            #+#    #+#             */
/*   Updated: 2023/05/30 21:38:20 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//check if all philo eat or not
//if all philo eat return 1 else return 0
int	check_meals(t_data *data)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	if (!data->philo_eat)
		return (0);
	while (++i < data->number_of_philosophers)
	{
		if (data->time_to_eat == 0)
			count++;
		else
			break ;
	}
	if (count == data->number_of_philosophers)
		return (1);
	return (0);
}

//print dead message !
void	print_dead(long time, int i)
{
	printf("\033[1;89m[%ld]	[%d] \033[1;91mdied ☠️\033[0;39m\n", time, i);
}

//cleaner function to free all mutex and threads !
//if there is only one philo we use pthread_detach to free the thread !
void	cleaner(t_data *data)
{
	int	i;

	i = 0;
	while (++i <= data->number_of_philosophers)
		pthread_mutex_destroy(&data->mutex[i]);
	i = 0;
	if (data->number_of_philosophers == 1)
		pthread_detach(&data->thread[i]);
	else
	{
		while (++i < data->number_of_philosophers)
			pthread_detach(&data->thread[i]);
	}
}

//main checker function to check if all philo eat or not !
//if all philo eat we free all mutex and threads !
//if one philo die we print dead message and free all mutex and threads !
void	main_checker(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		if (data->time_to_eat == 0) //maybe = -1;
			continue ;
		if (data->time_to_die < get_time() - data->philo[i].last_meal)
		{
			print_dead(data->start_time, i + 1);
			cleaner(data);
			break ;
		}
	}
}
