/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:03:04 by educastro         #+#    #+#             */
/*   Updated: 2024/10/22 18:42:48 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

enum e_bool	philo_init(t_data *data, int i)
{
	philo->philos[i].n = i + 1;
	philo->philos[i].data = data;
	philo->philos[i].eat_count = 0;
	philo->philos[i].t_last_eat = 0;
	philo->philos[i].fork_right = NULL;
	if (pthread_mutex_init(&(data->philos[i].fork_left), NULL) != 0)
		return (FALSE);
	if (pthread_mutex_init(&(data->philos[i].m_eat), NULL) != 0)
		return (FALSE);
	if (i == data->n_philo - 1)
		data->philos[i].fork_right = &(data->philos[0].fork_left);
	else
		data->philos[i].fork_right = &(data->philos[i + 1].fork_left);
	return (TRUE);
}

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
	// philo_handler(&data);
	free_all(&data);
	return (EXIT_SUCCESS);
}
