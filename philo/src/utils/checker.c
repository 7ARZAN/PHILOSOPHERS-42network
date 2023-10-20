/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:52:28 by 7arzan            #+#    #+#             */
/*   Updated: 2023/10/20 04:10:58 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//	@brief		:	Check if all philosophers have eaten enough
//	@param data	:	Structure that contains all the data
//	@return		:	1 if all philosophers have eaten enough, 0 otherwise
//	@note		:	Philosopher's number is i + 1 because i starts at 0 !
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

//	@brief		:	Display the status of the philosopher when he dies
void	print_die(long time, int id)
{
	printf("\033[1;89m[%ld]	[%d] \033[1;91mdied ☠️\033[0;39m\n", time, id);
}

//	@brief		:	clear all mutexes and detach all threads
//	@pthread_detach	:	detach a thread from the calling thread
//	@pthread_mutex_destroy	:	destroy a mutex object
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

//	@brief		:	Check if a philosopher is dead
//	@stat		:	0 if no one is dead, 1 if someone is dead, 2 if everyone
//				has eaten enough (if the number of meals is specified)
//	@time		:	Current time minus the start time
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
