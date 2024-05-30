/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:44:26 by preina-g          #+#    #+#             */
/*   Updated: 2023/07/24 13:29:24 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, const char **argv)
{
	t_data	*philo_data;

	philo_data = (t_data *)malloc(sizeof(t_data));

	if (argc == 5 || argc == 6)
	{
		if (ft_arg_parser(argv, philo_data) == FALSE)
			exit(printf("Error! The arguments are not integers\n"));
		else
			if (!ft_init(philo_data))
				exit(printf("Error"));
	}
	else
		printf("Error! Wrong input, there is a usage:\n\t ./philo [num_philo] [die_time] [eat_time] \
[sleep_time] (Optional)[n_times_each_philosopher_must_eat]\n");
}
