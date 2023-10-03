/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:35:33 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/09/26 12:20:45 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(size_t t)
{
	size_t	start;

	start = ft_get_t();
	while ((ft_get_t() - start) < t)
		usleep(500);
}

void	*ft_born(void *arg)
{
	t_phi	*f;

	f = (t_phi *)arg;
	f->f1 = f->p_n;
	if (f->p_n == f->d->n_f - 1)
		f->f2 = 0;
	else
		f->f2 = f->p_n + 1;
	if (f->p_n == f->d->n_f)
		ft_whach(f);
	if (f->p_n % 2 == 0 && f->p_n != f->d->n_f)
		ft_live(f);
	else if (f->p_n % 2 != 0 && f->p_n != f->d->n_f)
	{
		usleep((10) * 1000);
		ft_live(f);
	}
	free (f);
	return (0);
}

void	ft_mutex_init(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->n_f)
		pthread_mutex_init(&d->fork[i++], NULL);
	pthread_mutex_init(&d->ded, NULL);
	pthread_mutex_init(&d->eat, NULL);
	pthread_mutex_init(&d->print, NULL);
	pthread_mutex_init(&d->get_t, NULL);
}

void	ft_mutex_destroy(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->n_f)
		pthread_mutex_destroy(&d->fork[i++]);
	pthread_mutex_destroy(&d->ded);
	pthread_mutex_destroy(&d->eat);
	pthread_mutex_destroy(&d->print);
	pthread_mutex_destroy(&d->get_t);
}

int	ft_thread(t_data *d)
{
	int		i;
	t_phi	*f;

	ft_mutex_init(d);
	i = 0;
	while (i <= d->n_f)
	{
		f = (t_phi *) malloc (sizeof(t_phi));
		f->p_n = i;
		f->d = d;
		if (pthread_create(&d->phi[i++], NULL, &ft_born, f) != 0)
			return (1);
	}
	i = 0;
	while (i <= d->n_f)
	{
		if (pthread_join(d->phi[i++], NULL) != 0)
			return (1);
	}
	ft_mutex_destroy(d);
	return (0);
}
