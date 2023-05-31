/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 02:08:52 by elakhfif          #+#    #+#             */
/*   Updated: 2023/05/31 19:29:51 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	main(int argc, char **argv)
{
	int		i;
	t_list	*d;

	if (argc != 5 && argc != 6)
	{
		write(1, "Invalid number of Arguments\n", 28);
		return (0);
	}
	i = 1;
	d = malloc(sizeof(t_list));
	if (!d)
		return (0);
	while (i != argc)
	{
		if (check_num_arg(argv[i], i, d) < 0)
			return (0);
		i++;
	}
	if (start_simulation(d) != 0)
		return (-1);
	return (0);
}
