/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:58:42 by aybiouss          #+#    #+#             */
/*   Updated: 2023/05/17 18:04:37 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	res;
	int					sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res = res + str[i++] - 48;
		if (res > LLONG_MAX && sign > 0)
			return (-1);
		else if (res > LLONG_MAX && sign < 0)
			return (0);
	}
	return (res * sign);
}

t_prog	*prog_init(t_prog *prog, char **av, int ac)
{
	prog->numberofphilos = ft_atoi(av[1]);
	prog->timetodie = ft_atoi(av[2]);
	prog->timetoeat = ft_atoi(av[3]);
	prog->timetosleep = ft_atoi(av[4]);
	prog->all_ate = 0;
	prog->finish = 0;
	prog->creation_time = 0;
	if (ac == 6)
		prog->numberofeat = atoi(av[5]);
	else
		prog->numberofeat = 9999;
	if (prog->numberofphilos == -1 || prog->timetodie == -1
		|| prog->timetoeat == -1 || prog->timetosleep == -1
		|| prog->numberofeat == -1)
		return (NULL);
	prog->philo = malloc(sizeof(t_philo) * prog->numberofphilos);
	prog->forks = malloc(sizeof(pthread_mutex_t) * prog->numberofphilos);
	if (!prog->philo || !prog->forks)
		return (NULL);
	return (prog);
}
