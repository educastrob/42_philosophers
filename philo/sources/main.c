/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:03:04 by educastro         #+#    #+#             */
/*   Updated: 2024/10/25 16:02:50 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int ac, char **av)
{	
	t_data	data;

	if (ac != 5 && ac != 6)
		return (EXIT_FAILURE);
	if (!init_data(&data, av))
	{
		if (data.philos != NULL)
			free(data.philos);
		return (EXIT_FAILURE);
	}
	philo_handler(&data);
	free_all(&data);
	return (EXIT_SUCCESS);
}
