# listPID
Kernel module that prints information about a process and its children 

## How to use

<pre>

1. Run make in terminal
2. insmod listing-task.ko processPid=X      |   where X is any PID
3. rmmod listing-task.ko                    |   removes kernel module and calls module_exit
4. dmesg                                    |   shows kernel printk

</pre>



