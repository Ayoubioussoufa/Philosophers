/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:51:51 by aybiouss          #+#    #+#             */
/*   Updated: 2023/01/26 11:51:51 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar_fd(str[i++], fd);
}

int	main(int ac, char **av)
{
	t_prog	*prog;

	if (ac != 6 && ac != 5)
	{
		printf("Usage: ./philo <number_of_philos> <time_to_die> "
			"<time_to_eat> <time_to_sleep> "
			"[number_of_times_eacih_philosopher_must_eat]\n");
		return (1);
	}
	if (av[1][0] == '0' && av[1][1] == '\0')
		return (0);
	if (av[5] && av[5][0] == '0' && av[5][1] == '\0')
		return (0);
	prog = malloc(sizeof(t_prog));
	if (!prog)
		return (1);
	prog_init(prog, av, ac);
	if (!mutex_init(prog) && !creation_philos(prog))
		;
		// join_free(prog);
	return (0);
}
