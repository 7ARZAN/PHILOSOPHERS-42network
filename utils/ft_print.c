/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:09:58 by 7arzan            #+#    #+#             */
/*   Updated: 2023/04/18 11:07:54 by 7arzan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(char *str, long time, int id, pthread_mutex_t *pen)
{
	pthread_mutex_lock(pen);
	printf("%ld %d %s\n", time, id, str);
	pthread_mutex_unlock(pen);
}
