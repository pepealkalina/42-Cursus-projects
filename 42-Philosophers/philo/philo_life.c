/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:47:57 by preina-g          #+#    #+#             */
/*   Updated: 2023/07/24 15:20:21 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_philo(t_data *data, t_philo *philo, int id)
{
	philo->p_id = id;
	philo->last_meal = 0;
	philo->left_fork = id;
	philo->rigth_fork = (id + 1) % data->n_philo;
	philo->data = data;
	philo->is_eating = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(philo->is_eating, NULL))
		return;
}

/*ft_init()
	init al the philo variables and threads
*/
int	ft_init(t_data *data)
{
	int	i;

	data->philo = (t_philo **)malloc(data->n_philo * sizeof(t_philo*));
	if (!data->philo)
		return (FALSE);
	i = -1;
	if (ft_init_mutex(data) == FALSE)
		exit(printf("malloc arrer"));
	while (++i < data->n_philo)
	{
		data->philo[i] = (t_philo *)malloc(sizeof(t_philo));
		ft_init_philo(data, data->philo[i], i);
	}
	ft_start(data);
	return (TRUE);
}

/*
ft_init_mutex

--init mutex variables for after use.
	-philo left an right forks
	-is_eating bool
	-print_msg for printing messaghes with a thread
--pthread_mutex_init()
	-return 0 if it was successfull
	-return other values if it wasn't successfull
*/
int	ft_init_mutex(t_data *data)
{
	int	i;
	int	np;

	i = -1;
	np = data->n_philo;
	data->fork = (pthread_mutex_t *)malloc(np * sizeof(pthread_mutex_t));
	if (!data->fork)
		return (FALSE);
	while (++i < data->n_philo)
	{
		//data->fork[i] = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		//if (!data->fork[i])
			//return (FALSE);
		if (pthread_mutex_init(&data->fork[i], NULL))
			return (FALSE);
	}
	data->print_msg = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(data->print_msg, NULL))
		return (FALSE);
	return (TRUE);
}


void	ft_philo_is_eating(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->fork[philo->left_fork]);
	ft_print_msg(data, "take left fork", philo->p_id);
	pthread_mutex_lock(&data->fork[philo->rigth_fork]);
	ft_print_msg(data, "take right fork", philo->p_id);
	pthread_mutex_lock(philo->is_eating);
	ft_print_msg(data, "is eating", philo->p_id);
	philo->last_meal = ft_get_timestamp();
	pthread_mutex_unlock(philo->is_eating);
	usleep(data->eat_time);
	philo->times_eat++;
	pthread_mutex_unlock(&data->fork[philo->left_fork]);
	ft_print_msg(data, "left left fork", philo->p_id);
	pthread_mutex_unlock(&data->fork[philo->rigth_fork]);
	ft_print_msg(data, "left right fork", philo->p_id);

}

void	*ft_start_r(void *v_philo)
{
	t_philo	*philo;

	philo = (t_philo *)v_philo;
	if (philo->p_id % 2)
	{
		ft_print_msg(philo->data, "is thinking", philo->p_id);
		usleep(15000);
	}
	while (philo->data->dead == FALSE)
	{
		ft_philo_is_eating(philo);
		ft_print_msg(philo->data, "is sleeping", philo->p_id);
		usleep(philo->data->sleep_time);
		ft_print_msg(philo->data, "is thinking", philo->p_id);
	}
	return (NULL);
}

void	ft_routine_finish(t_data *data)
{
	int		i;
	t_philo	**philo;

	philo = data->philo;
	usleep(data->die_time);
	while (data->dead == FALSE)
	{
		i = -1;
		while (++i < data->n_philo && data->dead == FALSE)
		{
			pthread_mutex_lock(philo[i]->is_eating);
			if ((ft_get_timestamp() - philo[i]->last_meal) >= data->die_time)
			{
				ft_print_msg(data, "is dead", i);
				data->dead = TRUE;
			}
			pthread_mutex_unlock(philo[i]->is_eating);
		}
		if (data->dead == FALSE)
			break ;
		while (data->eat_time != -1 && i < data->n_philo && \
				data->philo[i]->times_eat >= data->eat_time)
			i++;
		if (i == data->n_philo)
			data->dead = TRUE;
	}
}

int	ft_start(t_data *data)
{
	int		i;
	t_philo **philo;

	philo = data->philo;	
	i = 0;
	data->dead = FALSE;
	while (i < data->n_philo)
	{
		if (pthread_create(&philo[i]->thread, NULL, ft_start_r, philo[i]))
			return (FALSE);
		i++;
	}
	ft_routine_finish(data);
	return (TRUE);
}
