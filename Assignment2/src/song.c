#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<song.h>
#include<logs.h>

Song *songlibrary;

Song* initialize_songlibrary(){
    Song *end;
    Song *s;

    s=malloc(sizeof(Song));
    strcpy(s->songname,"Blinding Lights");
    s->songid=101;
    s->next=NULL;
    songlibrary=s;
    end=s;

    s=malloc(sizeof(Song));
    strcpy(s->songname,"Shape of You");
    s->songid=102;
    s->next=NULL;

    end->next=s;
    end=s;

    s=malloc(sizeof(Song));
    strcpy(s->songname,"Starboy");
    s->songid=103;
    s->next=NULL;

    end->next=s;
    end=s;

    s=malloc(sizeof(Song));
    strcpy(s->songname,"Tum Hi Ho");
    s->songid=104;
    s->next=NULL;

    end->next=s;
    end=s;

    s=malloc(sizeof(Song));
    strcpy(s->songname,"Naatu Naatu");
    s->songid=105;
    s->next=NULL;

    end->next=s;
    end=s;

    s=malloc(sizeof(Song));
    strcpy(s->songname,"Bohemian Rhapsody");
    s->songid=106;
    s->next=NULL;

    end->next=s;
    end=s;

    s=malloc(sizeof(Song));
    strcpy(s->songname,"Hotel California");
    s->songid=107;
    s->next=NULL;

    end->next=s;
    end=s;

    s=malloc(sizeof(Song));
    strcpy(s->songname,"About Damn Time");
    s->songid=108;
    s->next=NULL;

    end->next=s;
    end=s;

    s=malloc(sizeof(Song));
    strcpy(s->songname,"Rowdy Baby");
    s->songid=109;
    s->next=NULL;

    end->next=s;
    end=s;

    s=malloc(sizeof(Song));
    strcpy(s->songname,"Save Your Tears");
    s->songid=1010;
    s->next=NULL;

    end->next=s;
    end=s;
return songlibrary;}


void list_songs(){
    int count=1;
    Song *s;

    s=songlibrary;
    while(s){
        printf("%d. %s\n",count,s->songname);
        s=s->next;
        count++;
    }
}

Song* get_song(int num){
    int count=1;
    Song *temp=songlibrary;
    while(temp!=NULL){
        if(count==num){
            return temp;
        }
        temp=temp->next;
        count++;
    }
    return NULL;
}


void load_song(){
    int num;
    char path[80]="./songs/";
    char detail[100];
    char songid[100];

    list_songs();
    printf("Enter the song number: ");
    scanf("%d",&num);
    printf("\n\n");

    Song *song=get_song(num);
    if(song){
        strcat(path,"s");
        sprintf(songid,"%d",song->songid);
        strcat(path,songid);
        strcat(path,".txt");
        FILE *f=fopen(path,"r");
        if(f){
            while(fgets(detail,100,f)!=NULL){
                printf("%s",detail);
            }
        }
        else{
            printf("Invalid File\n");
        }
    }
    else{
        printf("Invalid Number\n");
    }
}



int songs_menu(){
    printf("\nSONG MENU\n");
    printf("------------\n");
    printf("1.Load Song\n");
    printf("2.List Songs\n");
    printf("Enter number: ");
    int n;
    scanf("%d",&n);
    
    switch (n)
    {
    case 1:
        load_song();
        log_command("Songs loaded ");
        
        break;
    case 2:
        list_songs();
        log_command("Songs listed ");
        break;
    }




return 0;
}



