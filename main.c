/*
 * name.c
 *
 *  Created on: 7 дек. 2017 г.
 *      Author: jake
 */

#include <unistd.h>
#include <stdio.h>

void printProc(int n)
{ printf("I'm Process %d (pid %d; ppid %d)\n", n++, getpid(), getppid());}

int main (void) {
        pid_t p2=1,p3=1,p4=1,p5=1,p6=1; // тип для возвращаемого PID
        int n=1;
        printProc(n);
        p2 = fork();
        if (p2 ==0)	{printProc(n);p4 = fork();}
        else { wait(p2); p3 = fork();}
        if (p3 ==0) {
        	printProc(n);
        	p5 = fork();
        	p6 = fork();}

        	if (p5 ==0) printProc(n);
        	if (p6 ==0) { wait (p5);printProc(n);}
        return 0;

}

