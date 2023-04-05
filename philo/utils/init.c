/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:14:07 by 7arzan            #+#    #+#             */
/*   Updated: 2023/04/03 11:55:43 by 7arzan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo/philo.h>

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
	//should passing atoi for all args !
	//number_of_philosophers 1
	//time_to_die 2
	//time to eat 3
	//time to sleep 4
	//then initialization of infinity_loop to 0 !
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
	if ()
		return (-1);
	return (0);
}

char	*init(int ac, char **av, t_vars *vars)
{
	vars->dead = 0;
	vars->exit = 0;
	if (ac < 5 || ac > 6)
		return ("Error : wrong arguments Are u stupid?! ");
	if (init_arguments(av, vars) == -1)
		return ("Error");
	if (check_parameters(vars) == -1)
		return ("Error");
	return (NULL);
}
