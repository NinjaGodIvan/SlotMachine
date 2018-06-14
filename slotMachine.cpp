#include <iostream>
#include <cstdlib>
using namespace std;

//Player's info
struct Player{
    
    string name; //Player's name
    int points = 0; //Every player starts with zero points
};

void rules();
int pointAccumulator(int []);
bool isDone(Player [], int);

int main() {
    
    rules();
    cout <<"Press enter to continue";
    cin.get();
    
    cout << endl;
    
    int players;
    string NAME;
    
    //Asks users for amount of players
    cout <<"Select the amount of players: ";
    cin >> players;
    
    Player person[players];
    
    //Asks users for names
    for(int i = 0; i < players; i++){
        
        cin.ignore();
        
        cout <<"Enter player " << i + 1 <<"'s name: ";
        getline(cin, NAME);
        
        person[i].name = NAME;
    }
    
    int slotMachine[3]; //slot machine containing three numbers containing 1's and 2's
    bool gameOver = false; //gameOver does end when true
    int playerTurn = 1; //initializes to player 1's turn
    
    //Slot Machine System
    while(!gameOver){
        
        //Displays the player scoreboard
        cout <<"SCORES\n";
        for(int i = 0; i < players; i++)
            cout << person[i].name <<": " << person[i].points <<" points\n";
        
        cout << endl;
        
        srand(time(NULL));
        
        //Randomly generates three numbers
        for(int i = 0; i < 3; i++)
            slotMachine[i] = rand() % 2 + 1;
        
        cout <<"It's " << person[playerTurn - 1].name <<"'s turn\n";
        cout <<"Press enter to spin\n";
        cin.get();
        
        //Adds 5 points if a player gets all same numbets
        person[playerTurn-1].points += pointAccumulator(slotMachine);
        
        //Displays player's numbers
        cout << person[playerTurn - 1].name << "'s values:\n";
        for(int i = 0; i < 3; i++)
            cout << slotMachine[i] << " ";
        
        cout << endl << endl;
        
        //Game stops when a player reaches 20 points
        gameOver = isDone(person, playerTurn);
        
        //If the last player finished their turn, then return back to player 1's turn
        if(playerTurn == players)
            playerTurn = 1;
        else
            playerTurn++;
        
    }
    
    //Displays final player scoreboard
    cout <<"FINAL SCORES\n";
    for(int k = 0; k < players; k++)
        cout << person[k].name <<": " << person[k].points <<" points\n";
    
    cout << endl;
    
    //Displays the winner
    for(int k = 0; k < players; k++){
        
        if(person[k].points == 30){
            cout << person[k].name << " wins!\n";
            break;
        }
    }
    
    return 0;
}

//Diplays rules
void rules(){
    
    cout <<"Welcome to the Slot Machine!\n";
    cout <<"1. There will be 3 random numbers\n";
    cout <<"2. To score points, all numbers from every slot must be the same (5 points)\n";
    cout <<"3. To win, you must score 30 points\n";
    
}

//Adds zero or five points
int pointAccumulator(int slot[]){
    
    if(slot[0] == slot [1] && slot[0] == slot[2])
        return 5; //returns 5 if there are three same numbers
    else
        return 0; //otherwise return no points
    
}

//Checks if any player reaches 30 points
bool isDone(Player person[], int player){
    
    if(person[player - 1].points == 30)
        return true;  //true once player accumulates 30 points
    else
        return false; //otherwise game continues
    
}
