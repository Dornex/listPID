#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>


int main() {
	pid_t pid = fork();
	if(pid < 0)
		return errno;
	else if(pid == 0) {
		printf("Child #1 PID: %d\n", getpid());
		pid_t pid2 = fork();

		if(pid2 < 0)
			return errno;
		else if(pid2 == 0) {

			pid_t pid3 = fork();

			if(pid3 < 0)
				return errno;
			else if(pid3 == 0) {
				printf("Child #3 PID: %d\n", getpid());
				while(1);
			}
			else {
				printf("Child #2 PID: %d\n", getpid());
				wait(NULL);
			}
			
		}
		else {
			wait(NULL);
		}
	}
	else {
		printf("Process PID: %d\n", getpid());
		wait(NULL);
	}
	return 0;
}
