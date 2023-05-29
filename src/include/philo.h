/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:51:02 by 7arzan            #+#    #+#             */
/*   Updated: 2023/05/29 01:51:56 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_H
# define PHILO_H

# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_philo{
    int                fork_left;
    int                fork_right;
}    t_philo;


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
int	simulation(t_philo *data);
int	check_arguments(char *args, int position, t_philo *data);
int	main(int ac, char **av);

#endif
