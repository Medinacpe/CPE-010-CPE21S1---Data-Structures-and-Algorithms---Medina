#include <iostream>
#include <string>
#include "playlist_LL.h"

int main() {

    // create a playlist using our linked list
    playList<std::string>* playlist = nullptr;

    pllInsertEnd(std::string("Hanngang Kailan"), &playlist);
    pllInsertEnd(std::string("Beer"), &playlist);
    pllInsertEnd(std::string("Multo"), &playlist);

    std::cout << "Initial Playlist\n";
    pllTraverse(playlist);


    
    // add song to front
    std::cout << "Adding \"Pasilyo\" to the head\n";
    pllInsertHead(std::string("Pasilyo"), &playlist);
    pllTraverse(playlist);


    std::cout << std::endl; //spacing


    // add to end
    std::cout << "Adding \"Just the Way You Are\" to the end\n";
    pllInsertEnd(std::string("Just the Way You Are"), &playlist);
    pllTraverse(playlist);


    std::cout << std::endl; //spacing


    // insert after a specified song
    playList<std::string>* current = playlist;
    while(current->data != "Beer"){
        current = current->next;
    }
    std::cout << "Inserting \"From the Start\" right after \"Beer\"\n";
    pllGeneralInsertion(std::string("From the Start"), current);
    pllTraverse(playlist);


    std::cout << std::endl; //spacing


    // remove a song
    std::cout << "Removing \"Multo\"\n";
    pllDelete(std::string("Multo"), &playlist);
    pllTraverse(playlist);


    std::cout << std::endl; //spacing


    // show next and previous functions
    std::cout << "Now Playing: " << playlist->data << "\n";

    playList<std::string>* nowPlaying = playlist;

    nowPlaying = pllNext(nowPlaying);
    std::cout << "Next -> " << nowPlaying->data << "\n";

    nowPlaying = pllNext(nowPlaying);
    std::cout << "Next -> " << nowPlaying->data << "\n";

    nowPlaying = pllPrev(nowPlaying);
    std::cout << "Previous -> " << nowPlaying->data << "\n";


    std::cout << std::endl; //spacing


    // shows list loops
    std::cout << "\nGo through the entire playlist and loop back:\n";
    playList<std::string>* walker = playlist;
    for(int i = 0; i < 6; i++){
        std::cout << walker->data << " -> ";
        walker = pllNext(walker);
    }

    return 0;
}