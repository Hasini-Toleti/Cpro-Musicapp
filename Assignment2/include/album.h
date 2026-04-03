#ifndef _ALBUM_H
#define _ALBUM_H  1

int albums_menu();
int list_albums();

typedef struct AlbumSong{
    char song[50];
    struct AlbumSong *next;
}AlbumSong;


typedef struct Album{
    char albumname[50];
    int albumid;
    AlbumSong *albumsong;
    struct Album *next; 
}Album;



#endif 