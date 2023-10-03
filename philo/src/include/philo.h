/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 05:37:41 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/03 15:27:46 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				number_of_meals;
	long			last_meal;
	int				fork_left;
	int				fork_right;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				init;
	int				stat;
	int				id;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				philo_eats;
	t_philo			*philo;
	pthread_t		*thread;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	mutex_last_meal;
	pthread_mutex_t	mutex_stat;
	pthread_mutex_t	mutex_id;
	pthread_mutex_t	mutex_write;
	pthread_mutex_t	mutex_fork;
	long			s_time;
}					t_data;

int					death(t_data *data);
int					main(int ac, char **av);
int					ft_atoi(const char *str);
int					check_meals(t_data *data);
int					create_thread(t_data *data);
int					create_mutex(t_data *data);
int					init(t_data *data);
long				get_time(void);
void				status(char *msg, t_data *data, int i);
void				take_fork(t_data *data, int i);
void				eat(t_data *data, int i);
void				ft_sleep(t_data *data, int i);
void				mssleep(int condition);
void				checker(t_data *data);
void				*philo_routine(void *f);
void				cleaner(t_data *data);
void				print_die(long time, int id);
int					check_number_of_args(char *args, int pos, t_data *data);
int					simulation(t_data *data);

#endif
