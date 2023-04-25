/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:51:02 by 7arzan            #+#    #+#             */
/*   Updated: 2023/04/24 11:15:25 by 7arzan           ###   ########.fr       */
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
	struct timeval	start;
	struct timeval	end;
}				t_philo;

int				ft_atoi(const char *str);
int				ft_isdigit(int c);


#endif
