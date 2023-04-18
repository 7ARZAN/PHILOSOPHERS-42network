/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:14:07 by 7arzan            #+#    #+#             */
/*   Updated: 2023/04/18 11:12:04 by 7arzan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo/philo.h"

static int	init_arguments(char **av, t_vars *vars)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
			if (!ft_isdigit(av[i][j++]))
				return (-1);
		i++;
	}
	vars->number_of_philosophers = ft_atoi(av[1]);
	vars->time_to_die = ft_atoi(av[2]);
	vars->time_to_eat = ft_atoi(av[3]);
	vars->time_to_sleep = ft_atoi(av[4]);
	vars->infinity_loop = 0;
	if (av[5] == NULL)
	{
		vars->infinity_loop = 1;
		vars->number_of_times_each_philosopher_must_eat = 0;
	}
	else
		vars->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	return (0);
}

static int	check_parameters(t_vars *var)
{
	if (var->number_of_philosophers <= 1 || var->number_of_philosophers > 200
			|| var->time_to_die < 60 || var->time_to_eat < 60)
		return (-1);
	return (0);
}

char	*init(int ac, char **av, t_vars *vars)
{
	vars->dead = 0;
	vars->exit = 0;
	if (ac < 5 || ac > 6)
		return ("Error: Wrong number of arguments");
	if (init_arguments(av, vars) == -1)
		return ("Error: Wrong arguments");
	if (check_parameters(vars) == -1)
		return ("Error: Wrong parameters");
	return (NULL);
}
