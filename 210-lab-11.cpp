// Keshav Yanamandra
// COMSC-210-5293, Fall 2026
// Lab 11

#include <iostream>
#include <string>

using namespace std;

//stores soccer player name, goals for each game and other information
struct Player {
    string name; //name of the soccer player
    int jersey; //jersey number
    int games; // number of games played
    int *goals; // dynamic array pointer

};

//prototypes
void inputPlayer(Player*);
void displayPlayer(Player*);

int main() {

    int teamSize;

    cout << "How many players in the team: ";
    cin >> teamSize;
    cin.ignore();

    //create the dynamic array of players in the team
    Player *team = nullptr;
    team = new Player[teamSize];

    //inpute all the players in the team
    for (int i = 0; i < teamSize; i++) {
        cout << endl;
        cout << "Player #" << i + 1 << endl;
        inputPlayer(&team[i]);
    }
    
    //I forgot to delete before
    delete [] team;

    return 0;
}

void inputPlayer(Player *sptr) {
    cout << "Name: ";
    getline(cin, sptr->name);

        cout << "Jersey number: ";
    cin >> sptr->jersey;

    cout << "Matches played: ";
    cin >> sptr->games;

    // dynamic array for this players goals - we need goals for each game and this was confusing for me
    sptr->goals = new int[sptr->games];

    for (int i = 0; i < sptr->games; i++) {
        cout << "Goals in match " << i << ": ";
        cin >> sptr->goals[i];
    }

}