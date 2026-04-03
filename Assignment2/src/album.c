#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<album.h>
#include<logs.h>
#include<song.h>

int albumid=101;

int create_album(){
    char s[60];
    char albid[100];
    char path[80]="./albums/";
    printf("Enter Album Name: ");
    scanf("%s",s);
    

    FILE *f1=fopen("./albums/albumlist.txt","a");
    sprintf(albid,"%d",albumid);
    strcat(albid," ");
    strcat(albid,s);
    strcat(albid,"\n");
    fputs(albid,f1);
    fclose(f1);

    sprintf(albid,"a%d",albumid);
    strcat(path,albid);
    strcat(path,".txt");
    FILE *f=fopen(path,"a");
    fclose(f);

    albumid++;
    return 1;
}

int list_albums(){
    char albums[50];
    int count=1;
    int found=0;
    FILE *f=fopen("./albums/albumlist.txt","r");
    if(f!=NULL){
        while(fgets(albums,20,f)!=NULL){
            char *albumname=strchr(albums,' ');
            if(albumname){
                printf("%d. %s",count,albumname+1);
                count++;
                found = 1;
            }
        }
    }
    if(found==0){
        printf("No albums exist\n");
    }
return 1;}

void view_songalbum(){
    char s[60];
    int albumno;
    char path[80]="./albums/";
    char songs[5];
    int found=0;

    list_albums();
    printf("Enter album number: ");
    scanf("%d",&albumno);

    int albumid=albumno+100;
    sprintf(s,"a%d",albumid);
    strcat(path,s);
    strcat(path,".txt");
    FILE *f=fopen(path,"r");
    if(f){
        while(fgets(songs,5,f)!=NULL){
            printf("%s",songs);
            found=1;
        }
        fclose(f);
        if (!found) {
            printf("No songs in album\n");
        }
    }
    else{
        printf("Album does not exist\n");
    }
}

void add_songalbum(){
    int albumno,songno;
    char s[60];
    char path[80]="./albums/";
    list_albums();
    printf("Enter Album Number: ");
    scanf("%d",&albumno);
    list_songs();
    printf("Enter Song number to be added: ");
    scanf("%d",&songno);
    Song *song=get_song(songno);

    int albumid=albumno+100;
    sprintf(s,"a%d",albumid);
    strcat(path,s);
    strcat(path,".txt");

    FILE *f=fopen(path,"a");
    fputs(song->songname,f);
    fputs("\n",f);

    fclose(f);
}

void del_songalbum(){
    AlbumSong *head=NULL;
    AlbumSong *end=NULL;
    int albumno;
    char s[50];
    char song[50];
    char path[80]="./albums/";

    list_albums();
    printf("Enter Album Number: ");
    scanf("%d",&albumno);
    int albumid=albumno+100;
    sprintf(s,"a%d",albumid);
    strcat(path,s);
    strcat(path,".txt");
    FILE *f=fopen(path,"r");

    if (f){
        while(fgets(song,50,f)){
            AlbumSong *m=malloc(sizeof(AlbumSong));
            strcpy(m->song,song);
            m->next=NULL;

            if(head==NULL)head=m;
            if(end) end->next=m;
            end=m;
        }
        fclose(f);
        AlbumSong *temp=head;
        while(temp){
            printf("%s",temp->song);
            temp=temp->next;
        }
        printf("Enter Song to be deleted: ");
        scanf("%s",s);
        AlbumSong *cur,*prev;
        int found=0;
        prev=NULL;
        cur=head;
        while(cur){
            if(strcmp(cur->song,s)){
                if(prev){
                    prev->next=cur->next;
                    free(cur);
                }
                else{
                    head=cur->next;
                    free(cur);

                }
                found=1;
                break;
            }
            else{
                prev=cur;
                cur=cur->next;
            }
        }
        
        if(found==1){
            FILE *f=fopen(path,"w");

            cur=head;
            while(cur){
                fputs(cur->song,f);
                fputs("\n",f);
                
                cur=cur->next;
            }
            fclose(f);
        }
    }
    else{
        printf("Song doesnt exist\n");
    }
}


int albums_menu(){
    printf("\nALBUM MENU\n");
    printf("------------\n");
    printf("1.Create Album\n");
    printf("2.List Albums\n");
    printf("3.View Songs in Album\n");
    printf("4.Add Songs to Album\n");
    printf("5.Delete songs in Album\n");
    printf("Enter Number: ");
    int n;
    scanf("%d",&n);
    
    
    switch (n)
    {
    case 1:
        create_album();
        log_command("Album created ");
        break;
    
    case 2:
        list_albums();
        log_command("Albums listed ");
        break;
    
    case 3:
        view_songalbum();
        log_command("Songs viewed in album ");
        break;

    case 4:
        add_songalbum();
        log_command("Song added to album ");
        break;

    case 5:
        del_songalbum();
        log_command("Song deleted from album ");
        break;
    }


return 0;

}