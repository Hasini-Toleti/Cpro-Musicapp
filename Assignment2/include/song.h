#ifndef _SONG_H
#define _SONG_H  1

typedef struct Song{
    char songname[50];
    int songid;
    struct Song *next; 
}Song;


int songs_menu();
Song* initialize_songlibrary();
void list_songs();
Song* get_song(int);



#endif
