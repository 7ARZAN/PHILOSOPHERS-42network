/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:51:02 by 7arzan            #+#    #+#             */
/*   Updated: 2023/04/25 19:50:53 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_philo
{
	int				id;
	int				eat_count;
	int				left_fork;
	int				right_fork;
	int				*forks;
	int				*stop;
	int				*eat;
	int				*sleep;
	int				*think;
	int				*die;
	int				*eat_count_max;
	int				*eat_count_total;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*print;
	pthread_mutex_t	*fork;
}				t_philo;

void	status(char *str, t_philo *data, int i);
void	take_forks(t_philo *data, int i);
void	eat(t_philo *data, int i);
void	sleeping_thinking(t_philo *data, int i);
int	check_meals(t_philo *philo);
void	cleaner(t_philo *philo);
void	main_checker(t_philo *data);
int	create_mutex(t_philo *philo);
int	create_thread(t_philo *philo);
int	ft_isdigit(int c);
int	ft_atoi(const char *str);
long	get_time(void);
void	mssleep(int time);
int	init(t_philo *data);
int	philosopher_death(t_philo *philo);
int	main(int ac, char **av);

#endif
