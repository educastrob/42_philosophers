/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:32:13 by edcastro          #+#    #+#             */
/*   Updated: 2024/10/25 19:48:38 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*check_death(void *content);
static void	*philo_life(void *content);
static void	take_fork(t_philo *philo);
static void	philo_eat(t_philo *philo);

enum e_bool	philo_handler(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
		if (!philo_init(data, i++))
			return (FALSE);
	i = 0;
	data->t_start = timestamp();
	while (i < data->n_philo)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &philo_life,
				&(data->philos[i])) != 0)
			return (FALSE);
		i++;
	}
	i = 0;
	while (i < data->n_philo)
		if (pthread_join(data->philos[i++].thread, NULL) != 0)
			return (FALSE);
	return (TRUE);
}

static void	*philo_life(void *content)
{
	t_philo		*philo;
	pthread_t	death;

	philo = content;
	if (philo->n % 2 == 0)
		msleep(philo->data->t_eat / 10);
	while (!is_dead(philo, FALSE))
	{
		pthread_create(&death, NULL, check_death, content);
		take_fork(philo);
		philo_eat(philo);
		pthread_detach(death);
		if (philo->data->n_eat != 0 && philo->eat_count == philo->data->n_eat)
			return (NULL);
	}
	return (NULL);
}

static void	*check_death(void *content)
{
	t_philo	*philo;

	philo = content;
	msleep(philo->data->t_die);
	pthread_mutex_lock(&philo->m_eat);
	if ((timestamp() - philo->t_last_eat) >= philo->data->t_die)
	{
		if (philo->data->n_eat != 0 && philo->eat_count == philo->data->n_eat)
			return (NULL);
		pthread_mutex_unlock(&philo->m_eat);
		print(philo, "died\n");
		is_dead(philo, TRUE);
		return (NULL);
	}
	pthread_mutex_unlock(&philo->m_eat);
	return (NULL);
}

static void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork_l));
	print(philo, "has taken a fork\n");
	if (philo->data->n_philo == 1)
	{
		msleep(philo->data->t_die * 2);
		return ;
	}
	pthread_mutex_lock((philo->fork_r));
	print(philo, "has taken a fork\n");
}

static void	philo_eat(t_philo *philo)
{
	print(philo, "is eating\n");
	pthread_mutex_lock(&(philo->m_eat));
	philo->t_last_eat = timestamp();
	philo->eat_count++;
	pthread_mutex_unlock(&(philo->m_eat));
	msleep(philo->data->t_eat);
	pthread_mutex_unlock((philo->fork_r));
	pthread_mutex_unlock(&(philo->fork_l));
	print(philo, "is sleeping\n");
	msleep(philo->data->t_sleep);
	print(philo, "is thinking\n");
}
