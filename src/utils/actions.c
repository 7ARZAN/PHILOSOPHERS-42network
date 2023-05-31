/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:02:36 by 7arzan            #+#    #+#             */
/*   Updated: 2023/05/31 19:21:47 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	w_status(char *s, t_list *d, int i)
{
	long	time;

	pthread_mutex_lock(&d->mutex_msg);
	time = calc_time() - d->s_time;
	if (i <= d->num_philos && check_eats(d) == 0 && d->stat == 0)
	{
		printf("\033[1;89m[%ld]	[%d] \033[0;39m%s", time, i, s);
	}
	pthread_mutex_unlock(&d->mutex_msg);
}

void	ft_take_fork(t_list *d, int i)
{
	pthread_mutex_lock(&d->mutex[d->philo[i].fork_r]);
	w_status("\033[1;92mhas taken a fork 🍴\033[0;39m\n", d, i + 1);
	if (d->num_philos == 1)
		ft_usleep(d->time_die + 1);
	pthread_mutex_lock(&d->mutex[d->philo[i].fork_l]);
	w_status("\033[1;92mhas taken a fork 🍴\033[0;39m\n", d, i + 1);
}

void	ft_eat(t_list *d, int i)
{
	w_status("\033[1;94mis eating 🍝\033[0;39m\n", d, i + 1);
	d->philo[i].num_eats++;
	ft_usleep(d->time_eat);
	pthread_mutex_unlock(&d->mutex[d->philo[i].fork_l]);
	pthread_mutex_unlock(&d->mutex[d->philo[i].fork_r]);
	pthread_mutex_lock(&d->mutex_last_eat);
	d->philo[i].last_eat = calc_time() - d->s_time;
	pthread_mutex_unlock(&d->mutex_last_eat);
}

void	ft_sleep(t_list *d, int i)
{
	w_status("\033[1;89mis sleeping 💤\033[0;39m\n", d, i + 1);
	ft_usleep(d->time_sleep);
	w_status("\033[1;91mis thinking 🤔\033[0;39m\n", d, i + 1);
}
