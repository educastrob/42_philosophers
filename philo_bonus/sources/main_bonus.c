/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:57:14 by educastro         #+#    #+#             */
/*   Updated: 2024/10/27 16:04:42 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
		return (EXIT_FAILURE);
	if (!init_data(&data, argv))
	{
		if (data.philos != NULL)
			free(data.philos);
		return (EXIT_FAILURE);
	}
	philo_handler(&data);
	free_all(&data);
	return (EXIT_SUCCESS);
}
