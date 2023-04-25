/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:07:51 by 7arzan            #+#    #+#             */
/*   Updated: 2023/04/20 13:45:32 by 7arzan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo/philo.h>

//get_time function 
//return time in milliseconds
long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_sec / 1000);
}

//mssleep function
//time in milliseconds
void	mssleep(int time)
{
	long	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(time / 2);
}
