/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosohers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:32:13 by edcastro          #+#    #+#             */
/*   Updated: 2024/10/23 20:03:15 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// needs
static void	philo_eat(void *content);
static void	take_fork(void *content);

static void	check_death(void *content)
{
	t_philo	*philo;

	philo = content;
	if ((timestamp() - philo->t_last_eat) >= philo->data->t_die)
	{
		philo->data->dead = TRUE;
		mutex
		print(philo, "died\n");
		return (NULL);
	}
}

static void	philo_life(void *content)
{
	t_philo		*philo;
	pthread_t	death;

	philo = content;
	if (data->t_eat % 2 == 0)
		msleep(data->t_eat / 2);
	while (!is_dead(philo, FALSE))
	{
		pthread_create(death, NULL, &check_death, content);
		take_fork(philo);
		philo_eat(philo);
		pthread_detach(death);
		if (data->n_eat != 0 && data->eat_count == data->n_eat)
			return (NULL);
	}
	return (NULL);
}

enum e_bool	philo_handler(t_data *data)
{
	int	i;
	
	i = 0;
	while (i < data->n_philos)
	{
		if (!philo_init(data, i++))
			return (FALSE);
	}
	i = 0;
	data->t_start = timestamp();
	while (i < data->n_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &philo_life, \
			&(data->philos[i])) != 0)
			return (FALSE);
		i++;
	}
	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
