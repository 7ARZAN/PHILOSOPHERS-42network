/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead_or_not.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:52:28 by 7arzan            #+#    #+#             */
/*   Updated: 2023/04/03 11:56:34 by 7arzan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo/philo.h>

void	check_if_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].vars->number_of_philosophers)
	{
		if ((get_time() - philo[i].vars->start) - philo[i].last_time_eat
				>= philo[i].last_time_eat + philo.[i].vars->time_to_die)
		{
			philo[i].vars->dead = 1;
			ft_print("%ld %d died\n", (get_time() - philo[i].vars->start),
					philo[i].id, &philo[i].vars->t_pen);
			pthread_mutex_lock(&philo[i].vars->t_pen);
			break ;
		}
		if (philo[i].vars->exit == philo[i].vars->number_of_philosophers)
			break ;
		i++;
		if (philo[i].vars->number_of_philosophers == i)
			i = 0;
	}
}
