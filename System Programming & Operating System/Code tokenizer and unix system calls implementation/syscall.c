#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<pwd.h>
#include<unistd.h>
#include<sys/wait.h>
#include<dirent.h>

pid_t gpid;

int isInteger(char *s) {
	for(int i=0; s[i] != '\0'; i++) {
		if(!isdigit(s[i]))
			return 0;
	}
	return 1;
}


void ps() {
	DIR *dirp;
	dirp = opendir("/proc/");
	if(dirp == NULL) {
		printf("Failed to open proc directory\n");
		exit(0);
	}
	else {
		struct dirent *entry;
		printf("\nCurrently Running Processes\npid\tpname\tpstatus\n");
		while( (entry = readdir(dirp)) != NULL ) {
			if(isInteger(entry->d_name)) {
				FILE *fp;
				char path[1024];
				strcpy(path, "/proc/");
				strcat(path, entry->d_name);
				strcat(path, "/stat");
				fp = fopen(path, "r");
				char *line;
				size_t len = 0;
				getline(&line, &len, fp);
				int pid, ppid, pgid, session;
				char name[10], status;
				sscanf(line, "%d %s %c %d %d %d", &pid, name, &status, &ppid, &pgid, &session);
				if(session == gpid) {
					printf("%d\t%s\t%c\n", pid, name, status);
				}
			}
		}
		closedir(dirp);
	}
}



void main() {
	printf("Getting currently running process ids : \n");
	gpid = getppid();
	printf("\n\nExecuting ps system call before forking...\n");
	ps();
	printf("\n\nExecuting fork system call...\n");
	pid_t k = fork();
	if(k == 0) {
		printf("\n\nInside child Process...\n");
		printf("\n\nExecuting ps system call inside child process\n");
		ps();
		printf("\n\nExecuting exec ls system call...\n");
		execlp("/bin/ls", "ls", NULL);
	}
	else {
		printf("\n\nInside parent process...\n");
		printf("\n\nExecuting wait system call..\n");
		k = wait(NULL);
		printf("\n\nChild process fininshed...\n");
		printf("\n\nExecuting ps system call inside parent process\n");
		ps();
	}	
}
