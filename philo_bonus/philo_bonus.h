/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:39:51 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/02 16:35:56 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <signal.h>
# include <semaphore.h>

# define W "\033[0m"
# define R "\033[91m"
# define G "\033[92m"

typedef struct s_data
{
	int				ok;
	int				n_f;
	long			t_d;
	long			t_e;
	long			t_s;
	int				nt_me;
	long			time;
	long			clock;
	int				*pid;
	sem_t			*fork;
	sem_t			*print;
	sem_t			*n_eat;
	sem_t			*a_clock;
	int				p_n;
	int				e_n;

}				t_data;

/*MAIN*/
int			main(int argc, char **argv);
int			ft_set_pid(t_data *d);
long int	ft_atoi(char *s);
long int	ft_get_t(void);

/*ERROR*/
int			ft_error_spe(int argc, char **argv);
int			ft_char_check(char *s);

/*PROCESS*/
int			ft_proces(t_data *d);
int			ft_thread_init(t_data *d);
void		ft_finish(t_data *d);
void		ft_usleep(size_t t);

/*LIVING*/
void		ft_live(t_data *d);
void		ft_eat(t_data *d);
void		*ft_whach(void *arg);
#endif