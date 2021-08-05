/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 13:10:55 by xuwang            #+#    #+#             */
/*   Updated: 2021/08/05 18:42:04 by xuwang           ###   ########.fr       */
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
# define MICRO_SECOND 400

typedef struct s_each_philo
{
    pthread_t philo;  //线程ID  unsigned long int 
    int         id;  
    int         nbr_eat;
    int         left;
    int         right;
    long long   last_meal; //前一顿饭的时间
    struct s_philo     *info_utils;
}   t_each_philo;

typedef struct s_philo
{
    int             nbr_philo;
    int             time_to_die;  //吃饭间隔时间没吃饭就死  或者程序运行起来
    int             time_to_eat;   //进餐所需时间 要保留两个叉子
    int             time_to_sleep;  // 睡眠花费时间
    int             nbr_philo_must_eat;
    int             nbr_phile_are_eat;
    long long       start_time;
    //t_each_philo    *each_philo;  //是个数组 表示几个人
    pthread_mutex_t *fork;  //是个数组 互斥锁结构体 是个数组 表示有几把叉子几个锁
    pthread_mutex_t mutex; //共同锁
}   t_philo;                 //5个哲学家 --> 5个线程； 5支筷子 --> 5把互斥锁 int left(左手)， right(右手)


long	ft_atoi(const char *str);
int     main(int ac,  char **av);
t_philo *init_value(char **av);
t_each_philo *init_each_philo(int philo_nbr);
int	    __exit__(char *msg, t_each_philo *each_philo, t_philo *philo, int ret);
void	*ft_calloc(size_t count, size_t size);
long long get_time(void);
void    philo_state(t_each_philo *each_philo, int state);
void    *do_philo(void *each_philo);
void   ft_philo(t_each_philo *each_philo);
void    ft_usleep(long long ms);
int     check_died(t_each_philo *each_philo);
// int     check_enough_eat(t_each_philo *each_philo);
int check_enough_eat(t_each_philo *each_philo, t_philo *info);


#endif