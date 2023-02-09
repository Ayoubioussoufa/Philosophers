/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:54:37 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/09 11:54:16 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int main(int ac, char **av)
{
    t_prog	*prog;

	sem_unlink("semaphore");
	if (ac != 6 && ac != 5)
	{
		puterr("Usage: ./philo <number_of_philos> <time_to_die> "
			"<time_to_eat> <time_to_sleep> "
			"[number_of_times_eacih_philosopher_must_eat]\n");
	}
	prog = malloc(sizeof(t_prog));
	if (!prog)
		puterr("Allocation Error!\n");
	prog_init(prog, av, ac);
	ft_sem_init(prog);
	creation_philos(prog);
	free_all(prog);
	return (0);
}