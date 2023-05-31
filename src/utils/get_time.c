/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:07:51 by 7arzan            #+#    #+#             */
/*   Updated: 2023/06/01 00:20:02 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//get_time function 
//return time in milliseconds
long	get_time(void)
{
	struct timeval	time;
	int		ret;

	ret = gettimeofday(&time, NULL);
	if (ret == -1)
		return (-1);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

//mssleep function
//time in milliseconds
void	mssleep(int time)
{
	long	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
}
