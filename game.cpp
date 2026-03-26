#include <iostream>
using namespace std;

#define SIZE 10

struct Player {
    int playerID;
    string username;
    int score;
    int rank;
    int next;
};

Player table[SIZE];

// Initialize table
void init() {
    for(int i = 0; i < SIZE; i++) {
        table[i].playerID = -1;
        table[i].next = -1;
    }
}

// Hash function
int hashFunc(int id) {
    return id % SIZE;
}

// Insert player
void insertPlayer() {
    Player p;
    cout << "Enter PlayerID Username Score Rank: ";
    cin >> p.playerID >> p.username >> p.score >> p.rank;
    p.next = -1;

    int index = hashFunc(p.playerID);

    if(table[index].playerID == -1) {
        table[index] = p;
    } else {
        int i = index;

        while(table[i].next != -1)
            i = table[i].next;

        int j;
        for(j = 0; j < SIZE; j++) {
            if(table[j].playerID == -1)
                break;
        }

        if(j == SIZE) {
            cout << "Table Full!\n";
            return;
        }

        table[j] = p;
        table[i].next = j;
    }

    cout << "Player Added!\n";
}

// Search player
void searchPlayer() {
    int id;
    cout << "Enter Player ID: ";
    cin >> id;

    int index = hashFunc(id);

    if(table[index].playerID == -1) {
        cout << "Not Found\n";
        return;
    }

    int i = index;
    while(i != -1) {
        if(table[i].playerID == id) {
            cout << "\nPlayer Found:\n";
            cout << "ID: " << table[i].playerID
                 << " Name: " << table[i].username
                 << " Score: " << table[i].score
                 << " Rank: " << table[i].rank << endl;
            return;
        }
        i = table[i].next;
    }

    cout << "Not Found\n";
}

// Display table
void display() {
    cout << "\nLeaderboard (Hash Table):\n";
    for(int i = 0; i < SIZE; i++) {
        cout << i << " -> ";
        if(table[i].playerID != -1) {
            cout << table[i].playerID << " (" << table[i].next << ")";
        }
        cout << endl;
    }
}

int main() {
    init();

    int choice;
    do {
        cout << "\n1.Insert Player\n2.Search Player\n3.Display\n4.Exit\nChoice: ";
        cin >> choice;

        switch(choice) {
            case 1: insertPlayer(); break;
            case 2: searchPlayer(); break;
            case 3: display(); break;
        }

    } while(choice != 4);

    return 0;
}
