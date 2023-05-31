/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 02:08:52 by elakhfif          #+#    #+#             */
/*   Updated: 2023/05/31 23:15:51 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	main(int ac, char **av)
{
	int		i;
	t_data	*data;

	if (ac != 5 && ac != 6)
	{
		write(1, "Invalid number of Arguments\n", 28);
		return (0);
	}
	i = 1;
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	while (i != ac)
	{
		if (check_number_of_args(av[i], i, data) < 0)
			return (0);
		i++;
	}
	if (simulation(data) != 0)
		return (-1);
	return (0);
}
