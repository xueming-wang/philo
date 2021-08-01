/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 13:10:43 by xuwang            #+#    #+#             */
/*   Updated: 2021/08/01 19:46:58 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	_free_(void *philo)
{
	if (philo)
		free(philo);
	philo = NULL;
}

int	__exit__(char *msg, t_philo *philo, int ret)
{
	if (msg)
		printf("%s\n", msg);
	if (philo)
	{
		if (philo->each_philo)
			_free_(philo->each_philo);
		if (philo->fork)
			_free_(philo->fork);
		_free_(philo);
	}
	exit(ret);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (ptr)
		memset(ptr, 0, count * size);
	return (ptr);
}

long	ft_atoi(const char *str)
{
	int		signe;
	long	res;

	signe = 1;
	res = 0;
	while (*str && ((*str >= '\t' && *str <= '\r') || (*str == ' ')))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe = -1;
		++str;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		res = res * 10 + *str - '0';
		++str;
	}
	return (res * signe);
}

void ft_usleep(long long ms, int i)
{
	const long long start = get_time();
	while (get_time() - start < ms)
		unsleep(MICRO_SECOND);
}


//个程序都有同样的选项
/*philo 4 310 200 200
number_of_philosophers  //哲学家的数量，也是叉子的数量
time_to_die  //以毫秒为单位，如果哲学家在开始他的最后一餐或模拟开始后没有开始吃“死亡时间”毫秒，它就会死亡
time_to_eat //以毫秒为单位，是哲学家进餐所需的时间。 在此期间，他将需要保留两个叉子。
time_to_sleep //以毫秒为单位，是哲学家将花费睡眠的时间。
number_of_times_each_philosopher_must_eat //参数是可选的，如果所有哲学家至少在什么时间内吃运行，如果没有吃就停止。 如果未选择 就只在哲学家死亡时停止。*/


// 打印的状态不应与其他哲学家的状态打乱或交织在一起。
// • 哲学家的死亡与打印其死亡的时间之间不能超过 10 毫秒。
// • 再次重申，哲学家应该避免死亡！

// 每个哲学家之间有一个叉子，因此如果他们是多个哲学家，那么每个哲学家的左右都会有一个叉子。
// • 为避免哲学家复制分叉，您应该为每个分叉状态使用互斥锁来保护分叉状态。
// • 每个哲学家都应该是一个线程。

// pthread_mutex_init(); 创建锁头  
// pthread_create();  创建线程
// pthread_create();  
//  pthread_mutex_lock();  拿走叉子锁上锁头
//    
//     pthread_mutex_unlock();  放下叉子就是解锁
//     pthread_join(ptid1,NULL);  //阻挡线程结束 挂起进程
//     pthread_join(ptid2,NULL);  
//     pthread_mutex_destroy(&(cnt.lock)); 
/*
-void * memset(void *s, int c, size_t n) 作用是将某一块内存中的内容全部设置为指定的值
-int pthread_create(pthread_t*restrict tidp,const pthread_attr_t *restrict_attr,void*（*start_rtn)(void*),void *restrict arg); 返回0，否则返回出错编号
第一个参数为指向线程标识符的指针。
　　第二个参数用来设置线程属性。
　　第三个参数是线程运行函数的起始地址。
　　最后一个参数是运行函数的参数。
-int pthread_join(pthread_t thread, void **retval) 子线程合入主线程，主线程阻塞等待子线程结束，然后回收子线程资源。
thread: 线程标识符，即线程ID（哪个人），标识唯一线程。retval: 用户定义的指针，用来存储被等待线程的返回值。0代表成功。 失败，返回的则是错误号
-int pthread_detach(pthread_t tid); 线程与子线程分离，子线程结束后，资源自动回收。#include <pthread.h> tid：线程标识符 返回零
在子线程中加入代码
pthread_detach(pthread_self()) 
或者父线程调用 
pthread_detach(thread_id)（非阻塞，可立即返回） 
这将该子线程的状态设置为detached,则该线程运行结束后会自动释放所有资源。
-pthread_mutex_init()函数是以动态方式创建互斥锁的，参数attr指定了新建互斥锁的属性。如果参数attr为NULL，则使用默认的互斥锁属性，
-gettimeofday(struct  timeval*tv,struct  timezone *tz)函数来得到时间。它的精度可以达到微妙 或者为执行计时，
timezone 参数若不使用则传入NULL即可。
    而结构体timeval的定义为：
struct timeval{
    long int tv_sec; // 秒数
    long int tv_usec; // 微秒数
}
*/