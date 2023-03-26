/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:51:02 by 7arzan            #+#    #+#             */
/*   Updated: 2023/03/26 21:58:41 by 7arzan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_H
# define	PHILO_H

typedef struct	s_vars{
	int	number_of_philosophers;
}	t_vars;

typedef struct	s_philo{
	pthread_mutex_t	t_id;
}	t_philo;

void	connect_philo_with_vars(t_philo *philo, t_vars *vars);
void	ft_print(char *str, long time, int id, pthread_mutex_t *pen);
long	get_time(void);
void	pthread_wait(t_philo *philo);

#endif
