/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:09:58 by 7arzan            #+#    #+#             */
/*   Updated: 2023/04/03 11:54:26 by 7arzan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo/philo.h>

void	ft_print(char *str, long time, int id, pthread_mutex_t *pen)
{
	pthread_mutex_lock(pen);
	printf(str, time, id);
	pthread_mutex_unlock(pen);
}
