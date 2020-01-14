#include <linux/init.h>
#include <linux/sched.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched/signal.h>

MODULE_AUTHOR("Dorneanu Eduard-Gabriel & Bazavan Cristian-Valeriu");
MODULE_DESCRIPTION("Search for process by a given PID and show children using DFS");
MODULE_VERSION("1.00000");

int processPid = 0;
module_param(processPid, int, 0);

void dfs(struct task_struct *task)
{	
	struct task_struct *next_task;
	struct list_head *list;

	/* Print each child information and call recursive DFS*/
	list_for_each(list, &task->children) {
		next_task = list_entry(list, struct task_struct, sibling);
		printk(KERN_INFO "[pid: %d] pname: %s [state: %ld]\n", next_task->pid, next_task->comm, next_task->state);
		dfs(next_task);
	}	
}

int listing_tasks_init(void)
{
	struct task_struct *task;

	printk(KERN_INFO "Loading module\n");
		
	/* Search for process by given PID parameter*/
	for_each_process(task) {
		if(task->pid == processPid)
			break;
	}

	/* Print informations about process and iterate over children using DFS*/
	printk(KERN_INFO "Found parent! \n[pid: %d] pname: %s [state: %ld]\n", task->pid, task->comm, task->state);
	dfs(task);
	return 0;
}

void listing_tasks_exit(void)
{
	printk(KERN_INFO "Removing module\n");
}

module_init(listing_tasks_init);
module_exit(listing_tasks_exit);
