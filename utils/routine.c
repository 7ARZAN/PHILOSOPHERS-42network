/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:31:39 by 7arzan            #+#    #+#             */
/*   Updated: 2023/04/20 13:42:15 by 7arzan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo/philo.h>

//philosopher_death function checks if any of the philosophers has died
//if so, it prints the time and the philosopher number and returns 1
//if not, it returns 0

int	philosopher_death(t_philo *philo)
{
	int	i;
	long	time;

	i = 0;
	while (i < philo->vars->num_of_philo)
	{
		time = get_time() - philo[i].last_eat;
		if (time > philo->vars->time_to_die)
		{
			pthread_mutex_lock(&philo->vars->print);	
			printf("[%ld]	[%d] \033[1;91mdied ☠️\033[0;39m\n", time, i + 1);
			return (1);
		}
		i++;
	}
	return (0);
}

//functions needed
//int routine
//void *philo routine
