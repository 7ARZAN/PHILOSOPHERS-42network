/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_wait.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:05:33 by 7arzan            #+#    #+#             */
/*   Updated: 2023/03/26 21:07:30 by 7arzan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	pthread_wait(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->vars->number_of_philosophers)
	{
		pthread_join(philo[i].t_id, NULL);
		i++;
	}
}