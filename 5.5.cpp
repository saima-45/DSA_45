#include <iostream>
#include <string>
using namespace std;

struct Song {
    string title;
    Song* next;
    Song* prev;

    Song(string t) : title(t), next(nullptr), prev(nullptr) {}
};

class Playlist {
private:
    Song* head;
    Song* tail;
    Song* current;

public:
    Playlist() : head(nullptr), tail(nullptr), current(nullptr) {}

    void addSong(string title) {
        Song* newSong = new Song(title);
        if (!head) {
            head = tail = current = newSong;
        } else {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
        cout << "🎶 Added: " << title << endl;
    }

    void removeSong(string title) {
        Song* temp = head;
        while (temp) {
            if (temp->title == title) {
                if (temp == head) head = temp->next;
                if (temp == tail) tail = temp->prev;
                if (temp->prev) temp->prev->next = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
                if (temp == current) current = temp->next ? temp->next : temp->prev;
                delete temp;
                cout << "🗑️ Removed: " << title << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "⚠️ Song not found: " << title << endl;
    }

    void playNext() {
        if (current && current->next) {
            current = current->next;
            cout << "▶️ Now Playing: " << current->title << endl;
        } else {
            cout << "⏭️ No next song available." << endl;
        }
    }

    void playPrevious() {
        if (current && current->prev) {
            current = current->prev;
            cout << "⏮️ Now Playing: " << current->title << endl;
        } else {
            cout << "⏮️ No previous song available." << endl;
        }
    }

    void showCurrent() {
        if (current)
            cout << "🎧 Currently Playing: " << current->title << endl;
        else
            cout << "🔇 Playlist is empty." << endl;
    }
};

int main() {
    Playlist myPlaylist;

    myPlaylist.addSong("Bohemian Rhapsody");
    myPlaylist.addSong("Imagine");
    myPlaylist.addSong("Hotel California");

    myPlaylist.showCurrent();
    myPlaylist.playNext();
    myPlaylist.playNext();
    myPlaylist.playPrevious();

    myPlaylist.removeSong("Imagine");
    myPlaylist.showCurrent();

    return 0;
}
