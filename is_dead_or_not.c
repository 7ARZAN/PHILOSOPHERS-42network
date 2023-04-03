/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead_or_not.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:52:28 by 7arzan            #+#    #+#             */
/*   Updated: 2023/04/03 10:58:07 by 7arzan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			//i should print died and time of death !
			pthread_mutex_lock(&philo[i].vars->t_pen);
			break ;
		}
}
