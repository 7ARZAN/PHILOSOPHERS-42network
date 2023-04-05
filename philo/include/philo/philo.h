/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:51:02 by 7arzan            #+#    #+#             */
/*   Updated: 2023/04/04 12:13:56 by 7arzan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PHILO_H
# define	PHILO_H

typedef struct	s_vars{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	long		start;
	int		dead;
	int		i;
	int		infinity_loop;
	int		exit;
	int		//number of times philosophers must eat
	pthread_mutex_t	t_pen;
}	t_vars;

typedef struct	s_philo{
	pthread_mutex_t	t_id;
	pthread_mutex_t	fork;
	pthread_mutex_t	*next_fork;
	t_vars		*vars;
	int		how_much_times_eat;
	long		last_time_eat;
	int		id;
}	t_philo;

void	connect_philo_with_vars(t_philo *philo, t_vars *vars);
void	ft_print(char *str, long time, int id, pthread_mutex_t *pen);
long	get_time(void);
void	pthread_wait(t_philo *philo);
void	is_dead(t_philo *philo);
void	destroy_mutex(t_philo *philo);
void	init_mutex(t_philo *philo);
char	*init(int ac, char **av, t_vars *vars);
int	ft_atoi(const char *str);
int	ft_isdigit(int i);

#endif
