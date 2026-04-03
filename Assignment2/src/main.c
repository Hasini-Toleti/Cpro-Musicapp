#include <stdio.h>
#include <stdlib.h>
#include <album.h>
#include <logs.h>
#include <playlist.h>
#include <song.h>



int main_menu(){
    printf("\n\nMAIN MENU\n");
    printf("------------\n");
    printf("1.Songs Library\n");
    printf("2.Albums\n");
    printf("3.Playlists\n");
    printf("4.History\n");
    printf("5.Exit\n");
    printf("Enter number: ");
    int n;
    scanf("%d",&n);
    log_command("Main Menu ");
    return n;
}
int main(){
    int n;

    initialize_songlibrary();

    while(1){
        n=main_menu();

        switch(n) {
            case 1:
                log_command("Songs Menu ");
                songs_menu();
                break;
            case 2:
                log_command("Albums Menu ");
                albums_menu();
                break;
            case 3:
                log_command("Playlist Menu ");
                playlist_menu();
                break;
            case 4:
                log_command("History accessed ");
                show_history();
                break;
            case 5:
                log_command("App exited ");
                printf("Exiting...");
                return 0;
                break;
            default:
                printf("Invalid Input\n");
                break;
                
        }
    }
}
