/*
 * child.c
 */
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	printf("children (pid %d - ppid %d)\n", getpid(),getppid());
	return 0;
}

