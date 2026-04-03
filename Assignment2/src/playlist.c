#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <playlist.h>
#include <album.h>
#include <song.h>

Playlist *playlist=NULL;
Playlist *cur=NULL;



void list_playlist(){
    Playlist *temp=playlist;
    int count=1;
    if(temp==NULL){
        printf("No Songs in playlist\n");
    }
    while(temp){
        printf("%d. %s\n",count,temp->song);
        temp=temp->next;
        count++;
    }
}

void play_songs(){
    if(cur==NULL) cur=playlist;
    if(cur!=NULL){
        printf("Playing: \n");
        printf("%s",cur->song);
    }
    else{
        printf("No songs in the playlist\n");
    }
}

void prev_song(){
    //loop trough playlist where next elem is cur 
    //move cur to prev and print
    //if fist elem is being played print loop to last song
    //if no song is playing print no song
    Playlist *prev = playlist;
    Playlist *end = playlist;

    if (cur) {
        if (cur == playlist) {
            while (end->next != NULL) {
                end = end->next;
            }
            cur = end;
            play_songs();
        }
        else {
            while (prev != NULL && prev->next != cur) {
                prev = prev->next;
            }

            if (prev) {
                cur = prev;
                play_songs();
            }
        }
    }

    else {
        printf("No song is being played currently");
    }
}

void next_song(){
    if(cur){
        cur=cur->next;
        if(cur==NULL)cur=playlist;
        play_songs();
    }
    else{
        printf("Song is not being played right now");
    }
}

void add_song_byname(char *songname){
    Playlist *end=playlist;
   
    Playlist *p=malloc(sizeof(Playlist));
    strcpy(p->song,songname);
    p->next=NULL;

    if((playlist==NULL)){
        playlist=p;
    }
    else{
        while(end->next!=NULL){
        end=end->next;
        }
        end->next=p;
        end=end->next;
    } 
}

void add_song() {
    int songno;
    Song *songlibrary = initialize_songlibrary();
    list_songs();
    printf("Enter Song to be added: ");
    scanf("%d", &songno);
    if(songno==10){songno=1010;}
    else{songno += 100;}

    Song *temp = songlibrary;
    while (temp) {
        if (temp->songid == songno) {
            add_song_byname(temp->songname);//,songno);
            printf("Song Added\n");
            return;
        }
        temp = temp->next;
    }

    printf("Song not found\n");
}

void del_song(){
    //if first set playlist to next and then delete current
    //otherwise set next of prev element to curren element next and then del curr
    int pos;
    list_playlist();
    printf("Enter song number to remove: ");
    scanf("%d", &pos);

    if(playlist == NULL){
        printf("Playlist is empty\n");
        return;
    }

    Playlist *del = playlist;
    Playlist *prev = NULL;

    int count = 1;

    while(del){
        if(count == pos){
            // delete this node
            if(prev == NULL){
                // deleting head
                playlist = del->next;
            } else {
                prev->next = del->next;
            }
            free(del);
            printf("Song removed!\n");
            return;
        }
        //move to next song 
        //before moving to next song store current elemnt as previous song
        prev = del;
        del = del->next;
        count++;
    }

    printf("Invalid song number\n");
}


void add_album(){
    // get album name
    // check if album is there and get songs into a linked list
    //loop through linked list and and add to playlist
    int albumno,albumid;
    char s[50];
    char path[80]="./albums/";

    

    list_albums();
    printf("Enter Album Number: ");
    scanf("%d",&albumno);
    albumid=albumno+100;
    sprintf(s,"a%d",albumid);
    strcat(path,s);
    strcat(path,".txt");
    FILE *f=fopen(path,"r");
    if (f){
        while(fgets(s,50,f)){
            add_song_byname(s);
        }
        fclose(f);
    }
}


int playlist_menu(){
    printf("\nPLAYLIST MENU\n");
    printf("-----------------\n");
    printf("1.Play songs\n");
    printf("2.List songs\n");
    printf("3.Previous song\n");
    printf("4.Next song\n");
    printf("5.Add song\n");
    printf("6.Remove song\n");
    printf("7.Add Album\n");
    printf("Enter number: ");
    int n;
    scanf("%d",&n);
    
    

    switch(n) {
        case 1:
            play_songs();
            break;
        case 2:
            list_playlist();
            break;
        case 3:
            prev_song();
            break;
        case 4:
            next_song();
            break;
        case 5:
            add_song();
            break;
        case 6:
            del_song();
            break;
        case 7:
            add_album();
            break;
    }
    return 0;
}

