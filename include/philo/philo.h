/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:51:02 by 7arzan            #+#    #+#             */
/*   Updated: 2023/04/18 11:29:33 by 7arzan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_vars{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
	int	dead;
	long	start;
}	t_vars;

typedef struct	s_philo{
	pthread_t	t_id;
	pthread_mutex_t fork;
	pthread_mutex_t *next_fork;
	t_vars		*vars;
	int		id;
	long		last_meal;
	int		meals;
}	t_philo;

void		connect_philo_with_vars(t_philo *philo, t_vars *vars);
void		ft_print(char *str, long time, int id, pthread_mutex_t *pen);
long		get_time(void);
void		pthread_wait(t_philo *philo);
void		is_dead(t_philo *philo);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void		init_mutex(t_philo *philo);
void		destroy_mutex(t_philo *philo);
void 		pthread_wait(t_philo *philo);
static int 	init_arguments(char **av, t_vars *vars);
static int 	check_parameters(t_vars *vars);
char 		*init(int ac, char **av, t_vars *vars);

#endif
