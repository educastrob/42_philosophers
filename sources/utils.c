/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:20:56 by edcastro          #+#    #+#             */
/*   Updated: 2024/10/23 20:01:23 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

enum e_bool	is_dead(t_philo *philo, enum e_bool set_dead)
{
	enum e_bool	ret;

	pthread_mutex_lock(&philo->data->m_dead);
	if (set_dead)
		philo->data->stop = TRUE;
	ret = philo->data->stop;
	pthread_mutex_unlock(&philo->data->m_dead);
	return (ret);
}

long int	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	msleep(int ms)
{
	long int	time;

	time = timestamp();
	while (timestamp() - time < ms)
		usleep(ms / 10);
}

void	print(t_philo *philo, char *str)
{
	long int	time;

	time = timestamp() - philo->data->t_start;
	if (!is_dead(philo, FALSE))
	{
		pthread_mutex_lock(&(philo->data->m_print));
		printf("%ldms %d %s", time, philo->n, str);
		pthread_mutex_unlock(&(philo->data->m_print));
	}
}

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
