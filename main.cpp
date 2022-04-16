#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <fstream>
#include "minigame.h"
#include "minigame2.h"
#define SWORD "\xE2\x9A\x94"
using namespace std;

// Struct for player information
struct Player {
    int hp = 3, iPos, jPos;
    bool hasSkip = false, hasTotem = false, isPranked = false;
};

// Function to print out the maze. m is a 2D dynamic array and is passed to the function by pointer
void printMaze(char **m, int row, int column, int hp) {
    int i, j;
    cout << "Your current HP: " << hp << "\n\n";                // Show player's health
    for (i = 0; i < row; i++) {
        if (i == 0) {
            cout << "Exit <--";
        }
        else {
            cout << "        ";
        }
        for (j = 0; j < column; j++) {
            cout << '|';
            if (m[i][j] == 'g')
                cout << SWORD;
            else if (m[i][j] == '?')
                cout << '?';
            else if (m[i][j] == 'w')
                cout << 'X';
            else if (m[i][j] == 's')
                cout << ' ';
            else
                cout << "*";
        }
        cout << "|\n";
    }
}

// Check whether the player's movement is valid (Invalid move: walk on or across walls, walk across mini game battles or random events)
// Input: pointer of the maze 2D dynamic array m and its respective size row and column, current position of the player iPos and jPos, direction and steps of the player's move
// Return true if the move is invalid (i.e. the path has obstacle), return false otherwise
bool obstacle(char **m, int row, int column, int iPos, int jPos, string direction, int steps) {
    int i, j;
    if (direction == "w") {                             // Case when player moves up
        if (iPos - steps < 0)
            return true;
        if (m[iPos - steps][jPos] == 'w')
            return true;
        for (i = iPos - 1; i > iPos - steps; i--) {
            if (m[i][jPos] != 's')
                return true;
        }
        return false;
    }
    else if (direction == "a") {                        // Case when player moves left
        if (jPos - steps < 0)
            return true;
        if (m[iPos][jPos - steps] == 'w')
            return true;
        for (j = jPos - 1; j > jPos - steps; j--) {
            if (m[iPos][j] != 's')
                return true;
        }
        return false;
    }
    else if (direction == "s") {                        // Case when player moves down
        if (iPos + steps > row - 1)
            return true;
        if (m[iPos + steps][jPos] == 'w')
            return true;
        for (i = iPos + 1; i < iPos + steps; i++) {
            if (m[i][jPos] != 's')
                return true;
        }
        return false;
    }
    else {                                              // Case when player moves right
        if (jPos + steps > column - 1)
            return true;
        if (m[iPos][jPos + steps] == 'w')
            return true;
        for (j = jPos + 1; j < jPos + steps; j++) {
            if (m[iPos][j] != 's')
                return true;
        }
        return false;
    }
}

// Function to print the command list
void printHelp() {
    cout << "Command list:\n";
    cout << "help : Show command list\n";
    cout << "move <direction> <steps> : (direction: w: North a: West s: South d: East, steps: integer value) e.g. move d 3 : move east by 3 steps\n";
    cout << "save : Save the game\n";
    cout << "quit : Quit the game. Execute <save> first if you want to save the progress and exit\n";
}

// Function to call a random mini game battle when the player steps on it
// Return true if the player wins the mini game battle, return false otherwise
bool miniGameBattle() {
    int game;
    srand(time(NULL));
    game = rand() % 7 + 1;
    if (game == 1)
        return game_hangman();
    else if (game == 2)
        return game_typing();
    else if (game == 3)
        return game_battle();
    else if (game == 4)
        return game_number();
    else if (game == 5)
        return game_tictactoe();
    else if (game == 6)
        return game_rockpaperscissors();
    else
        return game_killer();
}

// Function to print out the title to the screen
void printTitle() {
    cout << " ________________________________________________________________________" << endl;
    cout << "| ____  _  _  ____    ____  __  ____   ___   __  ____  ____  ____  __ _  |" << endl;
    cout << "|(_  _)/ )( \\(  __)  (  __)/  \\(  _ \\ / __) /  \\(_  _)(_  _)(  __)(  ( \\ |" << endl;
    cout << "|  )(  ) __ ( ) _)    ) _)(  O ))   /( (_ \\(  O ) )(    )(   ) _) /    / |" << endl;
    cout << "| (__) \\_)(_/(____)  (__)  \\__/(__\\_) \\___/ \\__/ (__)  (__) (____)\\_)__) |" << endl;
    cout << "| __  __  _  _  ___  ____  ____  ___    __  __    __    ____  ____       |" << endl;
    cout << "|(  \\/  )( \\/ )/ __)(_  _)(_  _)/ __)  (  \\/  )  /__\\  (_   )( ___)      |" << endl;
    cout << "| )    (  \\  / \\__ \\  )(   _)(_( (__    )    (  /(__)\\  / /_  )__)       |" << endl;
    cout << "|(_/\\/\\_) (__) (___/ (__) (____)\\___)  (_/\\/\\_)(__)(__)(____)(____)      |" << endl;
    cout << "|________________________________________________________________________|" << endl;
    cout << endl << endl << endl;
}

// Function to print victory message if the player solves the maze
void printWin(){
cout << "  ___      ___  __     ______  ___________  ______     _______   ___  ___ "  << endl;
cout << "|\"  \\    /\"  ||\" \\   /\" _  \"\\(\"     _   \")/    \" \\   /\"      \\ |\"  \\/\"  | "  << endl;
cout << "\\   \\  //  / ||  | (: ( \\___))__/  \\\\__/// ____  \\ |:        | \\   \\  /  "  << endl;
cout << " \\\\  \\/. ./  |:  |  \\/ \\        \\\\_ /  /  /    ) :)|_____/   )  \\\\  \\/   "  << endl;
cout << "  \\.    //   |.  |  //  \\ _     |.  | (: (____/ //  //      /   /   /    "  << endl;
cout << "   \\\\   /    /\\  |\\(:   _) \\    \\:  |  \\        /  |:  __   \\  /   /     "  << endl;
cout << "    \\__/    (__\\_|_)\\_______)    \\__|   \\\"_____/   |__|  \\___)|___/   "  << endl;
}

// Function to print victory message if the player dies
void printLose(){
cout << "  ___        ______    ________  _______  " << endl;
cout << "|\"  |      /    \" \\  /\"       )/\"     \"| " << endl;
cout << "||  |     // ____  \\(:   \\___/(: ______) " << endl;
cout << "|:  |    /  /    ) :)\\___  \\   \\/    |   " << endl;
cout << "\\  |___(: (____/ //  __/  \\\\  // ___)_  " << endl;
cout << "( \\_|:  \\\\        /  /\" \\   :)(:      \"| " << endl;
cout << "\\_______)\\\"_____/  (_______/  \\_______)" << endl;
}

/* Format of the save file:
<difficulty>
<maze top left corner> ..........
........... <maze bottom right corner>
<player.iPos> <player.jPos> <player.hp> <player.hasSkip> <player.hasTotem>  <player.isPranked>
*/
// notation of the maze array: 'g' == mini game battle, '?' == random event, 's' == space, 'w' == wall, 'p' == player
int main() {
    int i, j, difficulty, steps, iMazeSize, jMazeSize;
    char reply;                                             // Stores player's instruction throughout the game
    string direction;
    bool won = false, quit = false;                         // quit stores whether the player volunteerily quits the game
    string command;
    Player player;                                          // player object for storing player's status
    // mazeTemp1, mazeTemp2 and mazeTemp3 are dynamic arrays for storing maze template and will be copied to the actual game maze depending on what difficulty the player chooses
    char * mazeTemp1 = new char [50] {'s', 's', 'g', 's', 's', 'w', 's', 's', '?', 's', 's', 'w', 'w', 'w', 'g', 'w', 's', 'w', 'w', 's', 's', 'w', 's', '?', 's', 'w', 's', 'g', 'w', 'g', 'w', 'w', 's', 'w', 's', 'w', 'w', 's', 'w', 's', '?', 's', 's', 'w', '?', 's', 's', 's', 'w', 'p'};
    char * mazeTemp2 = new char [91] {'g', 's', 's', '?', 'w', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 'w', 's', 'g', 's', 'w', 'w', 'w', 'w', 'w', 'w', 's', 's', 'w', 'w', 'w', 's', 's', 'g', '?', 'w', '?', 's', 'w', 's', 'g', 's', 's', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 's', 'w', 's', '?', 'w', 's', 'w', '?', 's', 'g', 's', 's', 's', 'g', 'w', '?', 's', 'w', '?', 'w', 's', 'w', 's', 'w', 's', 'w', 'w', 'w', 's', 'g', 's', 's', 's', 's', 'w', '?', 'w', 's', 's', 'g', 's', 'p'};
    char * mazeTemp3 = new char [150] {'s', 'g', 's', 's', 'g', 's', 'g', 'w', 's', 's', 's', 's', '?', 's', 's', 'g', 'w', 'w', 'w', 'w', 'w', 's', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 's', 's', 's', 'g', 's', 's', 'w', '?', 'w', '?', 's', 's', 'w', 's', 's', 'g', 's', 'w', 'w', 'w', 's', 'w', 'g', 'w', 's', 'w', 's', 'w', 's', 'w', 'w', 's', 's', 's', 'w', 's', 'w', 's', 'w', 'g', 'w', 'g', 's', 's', 'w', '?', 'w', 'w', '?', 'w', 's', 'w', '?', 'w', 's', 'w', 'w', 'w', 's', 'w', 's', '?', 'w', 'w', 'w', '?', 'w', 's', 'w', 's', 'w', '?', 'w', 's', 'w', 's', 's', 's', 's', 's', 's', 'w', 's', 's', 'g', 'w', 's', 's', 'g', 'w', 's', 's', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 's', 'w', 's', 'w', 'w', 'w', 's', 's', 's', 's', 'g', 's', 's', 's', 's', '?', 'w', 's', 's', 'g', 's', 'p'};
    printTitle();
    cout << "Please select: 1. Start New Game 2: Load previous game 3: Game introduction\nYour choice: ";
    cin >> reply;
    cin.ignore(256, '\n');
    while ((reply < '1') || (reply > '3')) {                            // Rejecting invalid input
        cout << "Invalid option. Please enter either 1, 2 or 3: ";
        cin >> reply;
        cin.ignore(256, '\n');
    }
    if (reply == '3') {                                     // Printing game introduction
        cout << "Welcome to the forgotten mystic maze! You will go on an adventure in a maze\n";
        cout << "You will have total of 3 health point(HP). When it reaches 0, the adventure is failed\n";
        cout << "You have to reach to the end point before you ran out of HP\n";
        cout << "The maze basically has 4 elements:\n";
        cout << "1. " << SWORD << ": You will encounter a battle of a mini game. Win the mini game to continue. If you lose, you will lose 1 HP\n";
        cout << "2. ?: You will encounter a random event. Anything could happen ^_^\n";
        cout << "3. X: They are walls of the maze which you cannot go through\n";
        cout << "4. *: The current position of you\n";
        cout << "You can always type the \"help\" command during the game to see the command list. Enjoy your adventure!\n\n";
        cout << "Please select: 1. Start New Game 2: Load previous game\nYour choice: ";
        cin >> reply;
        cin.ignore(256, '\n');
        while ((reply < '1') || (reply > '2')) {            // Starting the game
            cout << "Invalid option. Please enter either 1 or 2: ";
            cin >> reply;
            cin.ignore(256, '\n');
        }
    }
    if (reply == '2') {                                     // Read the game difficulty from previous saved game file
        ifstream fin;
        fin.open("gamesave.txt");
        if (fin.fail()) {
            cout << "Fail to locate the save fail. Please restart the game.\n";
        }
        else {
            fin >> difficulty;
        }
    }
    else {                                                  // Ask user to input the desired difficulty when starting a new game
        cout << "Please choose the game difficulty according to maze size (length x width)\n";
        cout << "1: Easy(5 x 10) 2: Normal(7 x 13) 3: Hard(10 x 15). Your choice: ";
        cin >> difficulty;
    }
    if (difficulty == 1) {
        iMazeSize = 5;
        jMazeSize = 10;
    }
    else if (difficulty == 2) {
        iMazeSize = 7;
        jMazeSize = 13;
    }
    else {
        iMazeSize = 10;
        jMazeSize = 15;
    }
    char **maze = new char *[iMazeSize];                    // Declare a 2D dynamic array for storing the actual game maze
    for (i = 0; i < iMazeSize; i++) {
        maze[i] = new char [jMazeSize];
    }
    if (reply == '2') {                                     // Read in the maze progress and game status from the game save file
        ifstream fin;
        fin.open("gamesave.txt");
        fin >> difficulty;
        for (i = 0; i < iMazeSize; i++) {
            for (j = 0; j < jMazeSize; j++) {
                fin >> maze[i][j];
            }
        }
        fin >> player.iPos >> player.jPos >> player.hp >> player.hasSkip >> player.hasTotem >> player.isPranked;
        cout << "Loaded previous game.\n\n";
    }
    else {                                                  // Copy the maze template to the actual maze according to the game difficulty when starting a new game
        if (difficulty == 1) {
            int index = 0;
            for (i = 0; i < iMazeSize; i++) {
                for (j = 0; j < jMazeSize; j++) {
                    maze[i][j] = mazeTemp1[index];
                    index++;
                }
            }
        }
        else if (difficulty == 2) {
            int index = 0;
            for (i = 0; i < iMazeSize; i++) {
                for (j = 0; j < jMazeSize; j++) {
                    maze[i][j] = mazeTemp2[index];
                    index++;
                }
            }
        }
        else {
            int index = 0;
            for (i = 0; i < iMazeSize; i++) {
                for (j = 0; j < jMazeSize; j++) {
                    maze[i][j] = mazeTemp3[index];
                    index++;
                }
            }
        }
        player.iPos = iMazeSize - 1;                            // Initializing player's starting position
        player.jPos = jMazeSize - 1;
    }
    delete(mazeTemp1);                                          // Delete the maze templates to free the memory
    delete(mazeTemp2);
    delete(mazeTemp3);
    printHelp();
    while ((player.hp > 0) && (won == false)) {                 // Run the game, until the player dies
        cout << endl;
        printMaze(maze, iMazeSize, jMazeSize, player.hp);
        cout << "Enter <help> for command list. Please input your command: ";   // Prompt the user for command
        cin >> command;
        while ((command != "help") && (command != "move") && (command != "save") && (command != "quit")) {      // Rejecting invalid command
            cout << "Invalid command! Please enter your command again or enter <help> for the command list: ";
            cin.ignore(256, '\n');
            cin >> command;
        }
        if (command == "help") {
            cin.ignore(256, '\n');
            printHelp();
        }
        else if (command == "move") {
            cin >> direction >> steps;
            cin.ignore(256, '\n');
            while (((direction != "w") && (direction != "a") && (direction != "s") && (direction != "d")) || (steps < 1)) {     // Rejecting invalid move command
                cout << "Invalid direction or steps. Please enter the direction and steps again(<direction> <steps>): ";
                cin.ignore(256, '\n');
                cin >> direction >> steps;
            }
            if (obstacle(maze, iMazeSize, jMazeSize, player.iPos, player.jPos, direction, steps) == true) {         // Check if the move is valid
                cout << "There is an obstacle between you and your destination!\n";
            }
            else {                                              // Execute the move
                maze[player.iPos][player.jPos] = 's';
                if (direction == "w") {
                    player.iPos = player.iPos - steps;
                }
                else if (direction == "a") {
                    player.jPos = player.jPos - steps;
                }
                else if (direction == "s") {
                    player.iPos = player.iPos + steps;
                }
                else {
                    player.jPos = player.jPos + steps;
                }
            }
            if (maze[player.iPos][player.jPos] == 'g') {            // Prompt a mini game battle when the player steps on a mini game battle
                if (player.hasSkip == true) {                       // Check if the player can skip the mini game
                    cout << "You have a charm to skip the battle. Use it now? (Y/N): ";
                    cin >> reply;
                    cin.ignore(256, '\n');
                    while ((reply != 'Y') && (reply != 'N')) {      // Ask whether the player wants to skip the mini game
                        cout << "You have a charm to skip the battle. Use it now? (Y/N): ";
                        cin >> reply;
                        cin.ignore(256, '\n');
                    }
                    if (reply == 'Y') {
                        player.hasSkip = false;
                        cout << "You have skipped the battle\n";
                    }
                    else {                                          // Execute the game if the player does not skip the game
                        cout << endl;
                        if (miniGameBattle() == 0) {
                            player.hp--;                            // Reduce player's hp by 1 if the player loses the game
                        }
                    }
                }
                else {                                              // Execute the game if the player cannot skip the game
                    cout << endl;
                    if (miniGameBattle() == 0) {
                        player.hp--;                                // Reduce player's hp by 1 if the player loses the game
                    }
                }
                maze[player.iPos][player.jPos] = 'p';               // Clear the mini game in the game
            }
            else if (maze[player.iPos][player.jPos] == '?') {       // Prompt a random event when the player steps on a random event
                int randEvent;
                srand(time(NULL));
                if (player.isPranked == false) {                    // Possible to prank the player if the player is not pranked. Prank only works for once.
                    randEvent = rand() % 7 + 1;
                }
                else {
                    randEvent = rand() % 6 + 1;
                }
                if (randEvent == 1) {                               // Random event 1: Teleporting the player back to the starting point
                    cout << "You have been pulled to a portal! It teleported you to the starting point of the maze.\n";
                    maze[player.iPos][player.jPos] = 's';
                    player.iPos = iMazeSize - 1;
                    player.jPos = jMazeSize - 1;
                    maze[player.iPos][player.jPos] = 'p';
                }
                else if (randEvent == 2) {                          // Random event 2: Prompt another mini game battle
                    cout << "You have ran into a battle!\n\n";
                    if (player.hasSkip == true) {
                        player.hasSkip = false;
                        cout << "You have a charm to skip the battle. Use it now? (Y/N): ";
                        cin >> reply;
                        cin.ignore(256, '\n');
                        while ((reply != 'Y') && (reply != 'N')) {
                            cout << "You have a charm to skip the battle. Use it now? (Y/N): ";
                            cin >> reply;
                            cin.ignore(256, '\n');
                        }
                        if (reply == 'Y') {
                            player.hasSkip = false;
                            cout << "You have skipped the battle\n";
                        }
                        else {
                            cout << endl;
                            if (miniGameBattle() == 0) {
                                player.hp--;
                            }
                        }
                    }
                    else {
                        cout << endl;
                        if (miniGameBattle() == 0) {
                            player.hp--;
                        }
                    }
                    maze[player.iPos][player.jPos] = 'p';
                }
                else if (randEvent == 3) {                 // Random event 3: Nothing happens
                    cout << "You received blessing from the Angel of Luck\n";
                    cout << "You feel much more confident in winning the game!\n";
                    maze[player.iPos][player.jPos] = 'p';
                }
                else if (randEvent == 4) {                 // Random event 4: Give item for skipping one mini game
                    cout << "You have found a charm which can let you skip one mini game battle.\n";
                    cout << "You can choose whether to use it before mini game battles\n";
                    player.hasSkip = true;
                    maze[player.iPos][player.jPos] = 'p';
                }
                else if (randEvent == 5) {                // Random event 5: Give item for reviving the player when dies
                    cout << "You have found a totem which will restore 1 HP when you die.\n";
                    cout << "The totem will be automatically consumed when your HP drops to 0\n";
                    player.hasTotem = true;
                    maze[player.iPos][player.jPos] = 'p';
                }
                else if (randEvent == 6) {               // Random event 6: Restore 1 HP if HP is not full
                    cout << "Blessing from goddess of victory falls upon you\n";
                    if (player.hp == 3) {
                        cout << "You have restored 1 HP but you are already full HP :(\n";
                    }
                    else {
                        cout << "You have restored 1 HP.\n";
                        player.hp++;
                    }
                    maze[player.iPos][player.jPos] = 'p';
                }
                else {                                   // Random event 7: Prank the player that the game is crashing
                    cout << "The game ran into fatal error. The save file is corrupted. Forcing the game to shut down...\n";
                    this_thread::sleep_for(chrono::milliseconds(5000));
                    cout << "Haha just kidding. Resuming the game.\n";
                    player.isPranked = true;
                    maze[player.iPos][player.jPos] = 'p';
                }
            }
            else {
                maze[player.iPos][player.jPos] = 'p';
            }
            if ((player.hp == 0) && (player.hasTotem == true)) {        // Automatically revive the player if the player dies and has reviving totem item. Consume the item afterwards
                cout << "You died. You see Grim Reaper dragging your soul out of your body.\n";
                cout << "The totem of undying creates a shield, driving the Grim Reaper away and heals you.\n";
                cout << "The totem disappears and you have restored 1 HP.\n";
                player.hp++;
                player.hasTotem = false;
            }
            if ((player.iPos == 0) && (player.jPos == 0) && (player.hp > 0)) {
                won = true;
            }
        }
        else if (command == "save") {                   // Save the maze progress and game status into a text file
            cin.ignore(256, '\n');
            ofstream fout;
            fout.open("gamesave.txt");
            fout << difficulty << endl;
            for (i = 0; i < iMazeSize; i++) {
                for (j = 0; j < jMazeSize; j++) {
                    if (j < jMazeSize - 1) {
                        fout << maze[i][j] << ' ';
                    }
                    else {
                        fout << maze[i][j];
                    }
                }
                fout << endl;
            }
            fout << player.iPos << ' ' << player.jPos << ' ' << player.hp << ' ' << player.hasSkip << ' ' << player.hasTotem << ' ' << player.isPranked;
            fout.close();
            cout << "Your game progress is saved. It is safe to close the game now.\n";
        }
        else {                                      // Quit the game
            cin.ignore(256, '\n');
            cout << "All unsaved progress will be lost. Confirm quitting the game? (Y/N): ";
            cin >> reply;
            if (reply == 'Y') {
                quit = true;
                player.hp = 0;
            }
            cin.ignore(256, '\n');
        }
    }
    if ((won == true) && (quit == false)){
        printWin();
        cout << endl << "Great job adventurer. You have solved the maze.\n";
    }
    if ((won == false) && (quit == false)){
        printLose();
        cout << endl << "Why do we fall?\nBecause we can learn to pick ourselves up.\n";
        cout << "This is not the end. A new adventure is ready for you anytime.\n";
    }
    cout << "Press Enter to close the game...\n";
    cin.get();
    return 0;

}
