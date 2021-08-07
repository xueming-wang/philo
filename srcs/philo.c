/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:08:00 by xuwang            #+#    #+#             */
/*   Updated: 2021/08/07 16:47:16 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void  philo_eat(t_each_philo *each_philo)
{
    const int left = each_philo->id - 1;
    const int right = each_philo->id % each_philo->info_utils->nbr_philo;

    if ((each_philo->id - 1) % 2 == 0) // 问题所在在这， 你要计算的是 数组的当前位置 而不是 philo id
    {
        pthread_mutex_lock(&each_philo->info_utils->fork[right]); //拿起左手筷子
        philo_state(each_philo, 1);  //打印拿起筷子
        pthread_mutex_lock(&each_philo->info_utils->fork[left]); //拿起右手筷子
        philo_state(each_philo, 1);  //打印拿起筷子
    }
    else
    {
        pthread_mutex_lock(&each_philo->info_utils->fork[left]); //拿起右手筷子
        philo_state(each_philo, 1);  //打印拿起筷子
        pthread_mutex_lock(&each_philo->info_utils->fork[right]); //拿起左手筷子
        philo_state(each_philo, 1);  //打印拿起筷子
    }
}


void ft_philo(t_each_philo *each_philo)
{
    const int    left = each_philo->id - 1;
    const int    right = each_philo->id % each_philo->info_utils->nbr_philo;

    philo_eat(each_philo);  //拿起筷子
    philo_state(each_philo, 0); //打印吃饭状态
    each_philo->last_meal = get_time();
    each_philo->nbr_eat++;   //吃饭的顿数增加
    ft_usleep(each_philo->info_utils->time_to_eat);  //usleep吃饭时间
    if ((each_philo->id - 1) % 2 == 0) //这里也是需要的是当前数组 而不是id
    {
        pthread_mutex_unlock(&each_philo->info_utils->fork[left]); //放下筷子
        pthread_mutex_unlock(&each_philo->info_utils->fork[right]);//放下筷子
    }
    else
    {
        pthread_mutex_unlock(&each_philo->info_utils->fork[right]);//放下筷子
        pthread_mutex_unlock(&each_philo->info_utils->fork[left]); //放下筷子
    }
}

static void sleeping(t_each_philo *each_philo)
{
    if (each_philo->info_utils->check_died != 1)
    {  
        philo_state(each_philo, 2); // 打印睡觉状态
        ft_usleep(each_philo->info_utils->time_to_sleep); // 睡觉
    }   
}

void  *do_philo(void *each_philo)
{
    while (check_died(each_philo) && !check_enough_eat(each_philo, ((t_each_philo*)each_philo)->info_utils))
    {   
        ft_philo(each_philo);//当前这个人用的所有信息
        sleeping(each_philo);
        philo_state(each_philo, 3);   //打印思考状态
    } 
    return (NULL);
}