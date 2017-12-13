/*
 * name.c
 *
 *  Created on: 7 дек. 2017 г.
 *      Author: jake
 */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>


 int main(int argc, char **argv)
  {
	 char n[]="1";
	 pid_t p2,p3,p4,p5,p6;

	 char *arg[] = {"child","1",0};

	 printf("parent (pid %d - ppid %d)\n", getpid(),getppid());

	 if ((p2=fork()) ==0){
		 p4=fork(); // создание 4 процесса под вторым
		 if (p4 > 1) waitpid(p4); // 2 процесс ждет завершения 4
		 if (execv(arg[0], arg)==-1) perror("exec failed");}

	 if ((p3=fork()) ==0)
	 {
		 p5=fork(); // создание 5 процесса под 3
		 if (p5 > 1) {
			 waitpid(p5); // 3 процесс ждет завершения 5
		 	 p6=fork(); // создание 6 процесса под 3
		 	 if (p6 > 1) waitpid(p6);} // 3 процесс ждет завершения 6
		 if (execv(arg[0], arg)==-1) perror("exec failed");
	 }

	 if (p2>1) waitpid(p2); // 1 процесс ждет завершения 2
	 if (p3>1) waitpid(p3); // 1 процесс ждет завершения 3
	 return 0;
}
