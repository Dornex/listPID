# listPID
Kernel module that prints information about a process and its children.
for_each_process and list_for_each are two macros, from linux/sched/signal.h and linux/init.h which iterate through lists.

## How to use

<pre>

1. Run make in terminal
2. insmod listing-task.ko processPid=X      |   where X is any PID
3. rmmod listing-task.ko                    |   removes kernel module and calls module_exit
4. dmesg                                    |   shows kernel printk

</pre>

## Informations about processes

1. pid: pid number
2. pname: process name
3. state: -1 unrunnable, 0 runnable, >0 stopped
4. cpu: current running cpu
5. nr_cpus_allowed



