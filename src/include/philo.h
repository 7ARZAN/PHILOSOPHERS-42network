/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:51:02 by 7arzan            #+#    #+#             */
/*   Updated: 2023/05/30 21:58:26 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int		num_of_meals;
	int		last_meal;
	int		fork_left;
	int		fork_right;
	struct s_data	*data;
}    t_philo;

typedef struct s_data
{	int				init_philo;
	int				stat;
	int				id;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				philo_eat;
	t_philo			*philo;
	pthread_t	*thread;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	mutex_last_meal;
	pthread_mutex_t	mutex_stat;
	pthread_mutex_t	mutex_i;
	pthread_mutex_t	mutex_write;
	pthread_mutex_t	mutex_forks;
	long			start_time;

}	t_data;

int	check_meals(t_data *data);
void	status(char *str, t_data *data, int i);
void	take_forks(t_data *data, int i);
void	eat(t_data *data, int i);
void	sleeping_thinking(t_data *data, int i);
void	cleaner(t_data *data);
void	main_checker(t_data *data);
int	create_mutex(t_data *data);
int	create_thread(t_data *data);
int	ft_isdigit(int c);
int	ft_atoi(const char *str);
long	get_time(void);
void	mssleep(int time);
int	init(t_data *data);
int	philosopher_death(t_data *data);
int	simulation(t_data *data);
int	check_arguments(char *args, int position, t_data *data);
void	print_dead(long time, int i);
int	routine(t_data *data);
void	*philo_routine(void *f);
int	main(int ac, char **av);

#endif
