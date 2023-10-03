/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_living.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:12:36 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/02 16:47:11 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_whach(void *arg)
{
	t_data	*d;

	d = (t_data *)arg;
	while (1)
	{
		usleep(100);
		sem_wait(d->a_clock);
		if ((ft_get_t() - d->clock) >= d->t_d)
		{
			sem_wait(d->print);
			printf(R"%lu %i died\n"W, ft_get_t() - d->time, d->p_n + 1);
			exit(1);
		}
		sem_post(d->a_clock);
		sem_wait(d->n_eat);
		if (d->e_n == d->nt_me)
		{
			sem_post(d->fork);
			sem_post(d->fork);
			exit(0);
		}
		sem_post(d->n_eat);
	}
	return (0);
}

void	ft_eat(t_data *d)
{
	sem_wait(d->fork);
	sem_wait(d->print);
	printf("%lu %i has taken a fork\n", ft_get_t() - d->time, d->p_n + 1);
	sem_post(d->print);
	sem_wait(d->fork);
	sem_wait(d->print);
	printf("%lu %i has taken a fork\n", ft_get_t() - d->time, d->p_n + 1);
	printf("%lu %i is eating\n", ft_get_t() - d->time, d->p_n + 1);
	sem_post(d->print);
	sem_wait(d->a_clock);
	d->clock = ft_get_t();
	sem_post(d->a_clock);
	sem_wait(d->n_eat);
	d->e_n += 1;
	sem_post(d->n_eat);
	ft_usleep(d->t_e);
	sem_post(d->fork);
	sem_post(d->fork);
}

void	ft_live(t_data *d)
{
	if (d->p_n % 2 != 0)
		ft_usleep(50);
	while (1)
	{
		ft_eat(d);
		sem_wait(d->print);
		printf("%lu %i is sleeping\n", ft_get_t() - d->time, d->p_n + 1);
		sem_post(d->print);
		ft_usleep(d->t_s);
		sem_wait(d->print);
		printf("%lu %i is thinking\n", ft_get_t() - d->time, d->p_n + 1);
		sem_post(d->print);
	}
}
