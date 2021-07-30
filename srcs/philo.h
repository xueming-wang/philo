/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 13:10:55 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/30 19:09:59 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>

# define FAILURE 1
# define SUCCESS 0

enum philo_status
{
    EAT,
    SLEEP,
    DIE,
    THINK
};

typedef struct s_each_philo
{
    pthread_t philo;  //用于声明线程ID  unsigned long int 
    int        id;
    
}   t_each_philo;

typedef struct s_philo
{
    int nbr_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int time_philo_must_eat;
    long long start_time;
    t_each_philo *each_philo;  //是个数组 表示几个人
    pthread_mutex_t *fork;  //是个数组 互斥锁结构体 是个数组 表示有几把叉子几个锁
}   t_philo;


long	ft_atoi(const char *str);
int     main(int ac,  char **av);
int     init_value(t_philo *philo,char **av);
int	    __exit__(char *msg, t_philo *philo, int ret);
void	*ft_calloc(size_t count, size_t size);

#endif