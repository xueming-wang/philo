/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:08:00 by xuwang            #+#    #+#             */
/*   Updated: 2021/08/01 19:49:00 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static void  take_fork(t_philo *philo, int i)
{
    int left = i;
    int right = (i + 1) % philo->nbr_philo;  //最后一位的右边叉子就是第0位


    pthread_mutex_lock(&philo->fork[left]); //拿起左手筷子  
        print_state(philo, i, 1);
    pthread_mutex_lock(&philo->fork[right]);
        print_state(philo, i, 1);
    
}

static void putdown_fork(t_philo *philo, int i)
{
    int left = i;
    int right = (i + 1) % philo->nbr_philo;
    
    pthread_mutex_unlock(&philo->fork[right]);
    pthread_mutex_unlock(&philo->fork[left]);
  
}

static void eating(t_philo* philo, int i)
{
    print_state(philo, i, 0);
    philo->each_philo->last_meal = get_time();  //取得最后一顿饭的时间
    ft_usleep(philo->time_to_eat, i);  //吃饭
    philo->nbr_philo_must_eat++;   //吃饭的顿数增加
}

static void sleeping(t_philo* philo, int i)
{
    print_state(philo, i, 2);
    ft_usleep(philo->time_to_sleep, i);
}


void  *philo(void *id, t_philo *philo)
{
    int i  = (int)id;

    //while()
    {
        take_fork(philo, i);
        eating(philo, i);
        putdown_fork(philo, i);
        sleeping(philo, i);
        print_state(philo, i, 3);
        //ft_unsleep();
    }
    
}


