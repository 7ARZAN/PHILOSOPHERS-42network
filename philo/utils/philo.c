/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:44:18 by 7arzan            #+#    #+#             */
/*   Updated: 2023/04/04 12:04:23 by 7arzan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo/philo.h>

void	philo_actions(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->fork);
	ft_print("%ld %d has taken a fork\n", (get_time()
				- philosopher->vars->start), philosopher->id,
			&philosopher->vars->t_pen);
	pthread_mutex_lock(&philosopher->next_fork);
	ft_print("%ld %d has taken a fork\n", (get_time()
				- philosopher->vars->start), philosopher->id,
			&philosopher->vars->t_pen);
	ft_print("%ld %d is eating\n", (get_time() - philosopher->vars->start),
			philosopher->id, &philosopher->vars->t_pen);
	philosopher->last_time_eat = get_time() - philosopher->vars->start;
	usleep(philosopher->vars->time_to_eat * 1000);
	pthread_mutex_unlock(&philosopher->fork);
	pthread_mutex_unlock(&philosopher->next_fork);
	ft_print("%ld %d is sleeping\n", (get_time() - philosopher->vars->start),
			philosopher->id, &philosopher->vars->t_pen);
	usleep(philosopher->vars->time_to_sleep * 1000);
	ft_print("%ld %d is thinking\n", (get_time() - philosopher->vars->start),
			philosopher->id, &philosopher->vars->t_pen);
}

static void	*philosopher(void *philo_info)
{
	t_philo	*philosopher;

	philosophr = (t_philo *)philo_info;
	while ()
		philo_actions(philosopher);
	philosopher->vars->exit++;
	return (NULL);
}

int	create_philosophers(t_vars *vars, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < vars->number_of_philosophers)
	{
		philo[i].id = i + 1;
		usleep(100);
		if (pthread_create(&philo[i].t_id, NULL, philosopher, &philo[i]) != 0)
			return (-1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	char	*bug;
	t_vars	vars;
	t_philo	*philo;

	i = 0;
	bug = init(ac, av, &vars);
	if (bug)
		return (printf("%s", bug), 1);
	philo = malloc(sizeof(t_philo) * (vars.number_of_philosophers));
	vars.start = get_time();
	connect_philo_with_vars(philo, &vars);
	init_mutex(philo);
	if (create_philosophers(&vars, philo))
		return (printf("ERROR : can't create a thread\n"), 1);
	is_dead(philo);
	destroy_mutex(philo);
	return (0);
}
