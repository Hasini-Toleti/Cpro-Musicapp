#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *logfile;

void show_history(){
    char logs[50];
    printf("Showing History\n");
    logfile=fopen("logs.txt","r");
    while(fgets(logs, 50, logfile) != NULL){
        fgets(logs,50,logfile);
        printf("%s",logs);
    }
    fclose(logfile);  
    return;
}


void log_command(char *cmd){
    logfile=fopen("logs.txt","a");
    if (strcmp(cmd,"App exited ")==0){
        fputs(cmd,logfile);
        fputs("\n",logfile);
        fputs("\n\n\nNew Session:\n",logfile);
        fflush(logfile);
        fclose(logfile);
    }
    else{
        fputs(cmd,logfile);
        fputs("\n",logfile);
        fflush(logfile);
        fclose(logfile);
    }
    return;

}


