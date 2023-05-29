/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:31:39 by 7arzan            #+#    #+#             */
/*   Updated: 2023/05/29 18:47:04 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//philosopher_death function checks if any of the philosophers has died
//if so, it prints the time and the philosopher number and returns 1
//if not, it returns 0

int	philosopher_death(t_data *data)
{
	int	i;
	long	time;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		time = get_time() - data->start_time;
		if (time - data->philo[i].last_meal > data->time_to_die)
		{
			pthread_mutex_lock(&philo->vars->print);	
			printf("[%ld]	[%d] \033[1;91mdied ☠️\033[0;39m\n", time, i + 1);
			return (1);
		}
	}
	return (0);
}
