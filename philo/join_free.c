/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:29:39 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/31 14:29:39 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_prog(t_prog *prog)
{
	int	i;

	i = 0;
	if (pthread_mutex_destroy(&prog->finish_lock) != 0)
	{
		ft_putstr_fd("Mutex destroy failed\n", 2);
		return ;
	}
	if (pthread_mutex_destroy(&prog->eat_lock) != 0)
	{
		ft_putstr_fd("Mutex destroy failed\n", 2);
		return ;
	}
	if (pthread_mutex_destroy(&prog->all_aate) != 0)
	{
		ft_putstr_fd("Mutex destroy failed\n", 2);
		return ;
	}
	if (pthread_mutex_destroy(&prog->finished) != 0)
	{
		ft_putstr_fd("Mutex destroy failed\n", 2);
		return ;
	}
	if (pthread_mutex_destroy(&prog->died) != 0)
	{
		ft_putstr_fd("Mutex destroy failed\n", 2);
		return ;
	}
	while (i < prog->numberofphilos)
	{
		if (pthread_mutex_destroy(&prog->forks[i++]) != 0)
		{
			ft_putstr_fd("Mutex destroy failed\n", 2);
			return ;
		}
	}
	free(prog->forks);
	free(prog);
}

void	join_free(t_prog *prog)
{
	// int	i;

	// i = 0;
	// while (i < prog->numberofphilos)
	// {
	// 	if (pthread_join(prog->philo[i++].thread, NULL) != 0)
	// 	{
	// 		ft_putstr_fd("Error Couldn't join thread\n", 2);
	// 		return ;
	// 	}
	// }
	// printf("wfwefwefwef???*-***\n");
	free(prog->philo);
	free_prog(prog);
}
