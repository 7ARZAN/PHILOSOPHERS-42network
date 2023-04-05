/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:04:24 by 7arzan            #+#    #+#             */
/*   Updated: 2023/04/03 11:57:05 by 7arzan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo/philo.h>

void	init_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->vars->number_of_philosophers)
	{
		philo[i].how_much_times_eat = 0;
		pthread_mutex_init(&philo[i].fork, NULL);
		if (i == philo->vars->number_of_philosophers - 1)
			philo[i].next_fork = &philo[0].fork;
		else
			philo[i].next_fork = &philo[i + 1].fork;
		i++;
	}
}

void	destroy_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->vars->numbrt_of_philosophers)
	{
		pthread_mutex_destroy(&philo[i].fork);
		pthread_detach(philo[i].t_id);
		i++;
	}
	free(philo);
}
