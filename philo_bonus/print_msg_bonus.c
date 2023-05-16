/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:53:20 by aybiouss          #+#    #+#             */
/*   Updated: 2023/05/15 16:22:52 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <string.h>

void    print_msg(t_philo *philo, char *msg)
{
    if (!philo->prog->finish)
		printf("%lli ms| Philo %i %s\n", current_time(philo),
			philo->id + 1, msg);
}

void	puterr(char *err)
{
	write(2, err, ft_strlen(err));
	exit(1); //SHOULDNt EXIT HERE
}
