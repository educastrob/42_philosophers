/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:03:04 by educastro         #+#    #+#             */
/*   Updated: 2024/10/23 19:18:15 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
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
