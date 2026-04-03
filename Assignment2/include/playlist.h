#ifndef _PLAYLIST_H
#define _PLAYLIST_H  1


int playlist_menu();

typedef struct Playlist{
    char song[50];
    int songid;
    struct Playlist *next;
}Playlist;




#endif 
