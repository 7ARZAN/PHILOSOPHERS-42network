/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:52:28 by 7arzan            #+#    #+#             */
/*   Updated: 2023/06/24 20:32:21 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_meals(t_data *data)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	if (!data->philo_eats)
		return (0);
	while (++i < data->number_of_philosophers)
	{
		if (data->philo[i].number_of_meals >= data->philo_eats)
			count++;
		if (count == data->number_of_philosophers)
		{
			data->stat = 2;
			return (1);
		}
	}
	return (0);
}

void	print_die(long time, int id)
{
	printf("\033[1;89m[%ld]	[%d] \033[1;91mdied ☠️\033[0;39m\n", time, id);
}

void	cleaner(t_data *data)
{
	int	i;

	i = 0;
	while (++i <= data->number_of_philosophers)
		pthread_mutex_destroy(&data->mutex[i]);
	i = 0;
	if (data->number_of_philosophers == 1)
		pthread_detach(data->thread[i]);
	else
	{
		while (++i <= data->number_of_philosophers)
			pthread_detach(data->thread[i]);
	}
}

void	checker(t_data *data)
{
	long	time;
	int		i;

	i = -1;
	while (data->stat == 0)
	{
		while (++i < data->number_of_philosophers)
		{
			time = get_time() - data->s_time;
			pthread_mutex_lock(&data->mutex_last_meal);
			if (time - data->philo[i].last_meal > data->time_to_die)
			{
				if (data->stat == 2)
					break ;
				data->stat = 1;
				print_die(time, i + 1);
				break ;
			}
			pthread_mutex_unlock(&data->mutex_last_meal);
		}
		if (data->stat == 2 || data->stat == 1)
			break ;
		i = -1;
	}
	cleaner(data);
}
