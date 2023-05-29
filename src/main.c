/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 02:08:52 by elakhfif          #+#    #+#             */
/*   Updated: 2023/05/18 02:09:25 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int ac, char **av)
{
	t_philo	*data;

	if (ac < 5 || ac > 6)
	{
		printf("Error: Invalid number of arguments\n");
		return (-1);
	}
	data = malloc(sizeof(t_philo));
	if (!data)
		return (-1);
	if (check_arguments(av[1], 1, data) == -1)
		return (-1);
	if (check_arguments(av[2], 2, data) == -1)
		return (-1);
	if (check_arguments(av[3], 3, data) == -1)
		return (-1);
	if (check_arguments(av[4], 4, data) == -1)
		return (-1);
	if (argc == 6)
	{
		if (check_arguments(av[5], 5, data) == -1)
			return (-1);
	}
	else
		data->number_of_times_each_philosopher_must_eat = -1;
	if (simulation(data) == -1)
		return (-1);
	return (0);
}