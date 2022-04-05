#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include "minigame.h"
using namespace std;

/* Hangman game rules: A word will be randomly selected and hidden to the player. The player will only know the total number of characters of the word.
   The player have to guess the full word character by character. When the player gets one character right, the positions where the character is located
   in the actual word will be revealed. When the player guesses the full word within limited number of trials, the game is won. Opposite case otherwise. */
bool game_hangman() {                                   // Function of the mini game hangman. The player has won if true is returned. False will be returned otherwise.
    int i, lineNum;                                     // lineNum will determine the location of the word being selected in the file.
    string word, guess = "", input, used = "";          // word stores the selected word. guess stores the string of player's guess. used stores the used characters.
    char chr;                                           // chr stores the player's character guess each time.
    bool guessed = false;                               // guessed stores the game status.
    ifstream fin;                                       // fin as the file input variable.
    srand(time(NULL));
    lineNum = rand() % 100 + 1;
    fin.open("hangman_wordlist.txt");
    for (i = 1; i <= lineNum; i++) {                    // Input the word for the hangman game depending on the lineNum randomly assigned.
        fin >> word;
    }
    fin.close();
    for (i = 0; i < word.length(); i++) {               // Initialize the guess string.
        guess += '_';
    }
    cout << "Welcome to Hangman!\n" << "Begin your guess by entering alphabet characters(a-z): \n";
    int attempts = word.length() * 2;                   // The number of attempts allowed is the word length times 2.
    while ((guessed == false) && (attempts > 0)) {      // Player will repeatedly input character until the full word is guessed or ran out of attempts.
        cout << endl << guess << " (" << word.length() << " words)" << endl << "You have " << attempts << " more wrong attempts left.\n";
        cout << "List of used character: ";
        for (i = 0; i < used.length(); i++) {
            cout << used[i] << ' ';
        }
        cout << endl;
        cout << "Guess a character: ";
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        getline(cin, input);                            // Get user input of the character guess
        while ((input.length() != 1) || (int(input[0]) < int('a')) || (int(input[0]) > int('z'))) {         // Handling illegal inputs, e.g. non-alphabet characters and string input.
            cout << "Please enter one alphabet character again(a-z): ";
            getline(cin, input);
        }
        chr = input[0];
        if (used.find(chr) == string::npos) {
            used += chr;                                // Update the list of used characters.
        }
        bool found = false;
        for (i = 0; i < word.length(); i++) {           // Find if the actual word contains the input character guess.
            if (chr == word[i]) {
                guess[i] = word[i];                     // Updating the guess string
                found = true;
            }
        }
        if (found == false) {                           // Updating the number of attempts.
            attempts--;
        }
        int count = 0;
        for (i = 0; i < word.length(); i++) {           // Check if the full word is guessed.
            if (guess[i] == '_') {
                count++;
            }
        }
        if (count == 0) {
            guessed = true;
        }
    }
    if (guessed == true) {
        cout << guess << endl;
        cout << "Congratulations! You have won!\n";
        return 1;
    }
    else {
        cout << "You have ran out of attempts\n" << "The answer is: " << word << endl;
        cout << "You have lost 1 health point\n";
        return 0;
    }
}

/* Typing Battle game rules: Five random sentences will be prompted sequentially. The player has to type the exact string provided without time limits.
   The game will be lost and ended immediately if discrepancy is located between the given string and inputted string. */
bool game_typing() {
    int round = 0, i, j, lineNum, sector = 0;        // round stores the current round. lineNum stores the location of input string from the file. sector is used to store the position of the next starting position of input from the file.
    string sentence, input;                          // sentence is the string input from the file. input stores the user typed string.
    bool lost = false;                               // lost is a boolean storing the game status.
    char ws;
    vector<string> sentences;                        // vector sentences stores all the sentences selected randomly to be prompted later (Total 5 strings).
    ifstream fin;
    srand(time(NULL));
    fin.open("typing_strlist.txt");
    for (i = 1; i <= 5; i++) {                       // Extract 1 strings from the file of 100 strings in every 20 strings. i.e. total of 5 strings will be retrieved.
        lineNum = rand() % 20 + 1;
        for (j = 1; j <= lineNum + sector; j++) {
            getline(fin, sentence);
        }
        sentences.push_back(sentence);
        sector = 20 - lineNum;
    }
    fin.close();
    cout << "Welcome to Typing Battle!\n" << "You have to type the given sentence without any discrepancy and press enter. No time limit.\n";
    while ((lost == false) && (round < 5)) {          // Player will be prompted a string to input until all 5 strings are typed correctly or the player makes a mistake.
        cout << '\n' << sentences[round] << '\n';
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        getline(cin, input);
        if (input != sentences[round]) {              // Comparing the user input and the actual sentence
            lost = true;
        }
        round++;
    }
    if (lost == false) {
        cout << endl << "Congratulations! You have won!\n";
        return 1;
    }
    else {
        cout << endl << "Wrong input! You have lost the game.\n";
        cout << "You have lost 1 health point.\n";
        return 0;
    }
}

/* Mini battle game rules: The player will encounter one of the three enemies, which has different names and total HP.
   The player has to defeat the enemy to proceed, meaning enemy HP <= 0. The player will lose if player HP <= 0.
   Enemy moves will be randomly generated from: 1. Attack(Deal 20HP to the player)  2. Reflect(Cancel the player's attack and reflect 10HP damage)  3. Heal(Restore 20HP) */
bool game_battle() {
    int enemyHP, playerHP = 100, enemyMove, playerMove, enemyMaxHP;  // Variables to store the HP value and the moves of the player and the enemy.
    string enemyName;                                                // enemyName stores the string of the enemy name.
    bool charged = false;                                            // charged stores whether the player charged the attack.
    srand(time(NULL));
    int enemy = rand() % 3 + 1;                                      // The value of integer enemy determines which enemy the player encounters.
    if (enemy == 1) {
        enemyName = "Goblin King";
        enemyHP = 80;
        enemyMaxHP = 80;
    }
    else if (enemy == 2) {
        enemyName = "Necromancer";
        enemyHP = 100;
        enemyMaxHP = 100;
    }
    else {
        enemyName = "Dark Knight";
        enemyHP = 120;
        enemyMaxHP = 120;
    }
    cout << "You have encountered a " << enemyName << "!\n" << "Defeat him to proceed.\n" << "He will always move first.\n";
    while ((enemyHP > 0) && (playerHP > 0)) {            // The game progress round by round and end when one of the party dies(HP <= 0).
        cout << endl;
        cout << "Enemy: " << enemyName << ' ' << "HP: " << enemyHP << " / " << enemyMaxHP << endl;
        cout << "Your HP: " << playerHP << " / 100" << endl;
        cout << "Choose your action(1-4): 1. Attack  2. Charge  3. Heal  4. Check action descriptions\n";
        cin >> playerMove;                               // Input the move from the player.
        cout << endl;
        enemyMove = rand() % 3 + 1;                      // Randomly generate enemy's move.
        if (playerMove != 4) {                           // Execute enemy's move if the player chose to action.
            if (enemyMove == 1) {
                cout << enemyName << " has attacked you. You have lost 20 HP.\n";
                playerHP -= 20;
            }
            else if (enemyMove == 2) {
                cout << enemyName << " has entered guard status. Your attack will be reflected.\n";
            }
            else {                                       // Heal mechanism: Restore 20HP each time but the HP cannot exceed maximum HP.
                if (enemyHP <= enemyMaxHP - 20) {
                    cout << enemyName << " has healed. He restored 20HP.\n";
                    enemyHP += 20;
                }
                else if (enemyHP < enemyMaxHP) {
                    cout << enemyName << " has healed. He restored 10HP.\n";
                    enemyHP += 10;
                }
                else {
                    cout << enemyName << " has healed. But He didn't restored any HP.\n";
                }
            }
        }
        if (playerHP > 0) {                            // Execute player's move if the player is not dead from the previous enemy's attack.
            if (playerMove == 1) {
                if (enemyMove == 2) {
                    cout << "Your attack is reflected. You lost 10HP.\n";
                    playerHP -= 10;
                }
                else {
                    if (charged == true) {
                        cout << "You attacked " << enemyName << ". He lost 50 HP.\n";
                        enemyHP -= 50;
                        charged = false;
                    }
                    else {
                        cout << "You attacked " << enemyName << ". He lost 20 HP.\n";
                        enemyHP -= 20;
                    }
                }
            }
            else if (playerMove == 2) {
                if (enemyMove == 10) {
                    cout << enemyName << " has attacked you. You fail to charge your attack.\n";
                }
                else {
                    cout << "You have successfully charged your attack. You will deal 2.5x damage than normal in your next attack.\n";
                    charged = true;
                }
            }
            else if (playerMove == 3) {
                if (playerHP <= 80) {
                    cout << "You have healed 20HP.\n";
                    playerHP += 20;
                }
                else if (playerHP < 100) {
                    cout << "You have healed 10HP.\n";
                    enemyHP += 10;
                }
                else {
                    cout << "You have healed 0HP as you have already reached full health. Bad move!\n";
                }
            }
            else {              // Description of player's move
                cout << "1. Attack: You will deal 20 damage to the enemy. The damage will be multiplied by 2.5 time if you charged your attack.\n";
                cout << "2. Charge: You will deal 2.5x damage to the enemy in your next attack.\n";
                cout << "3. Heal: Restore your HP by 20.\n";
            }
        }
    }
    if (enemyHP < 0) {          // Change the HP of the player or the enemy to 0 if the HP value is lower than 0.
        enemyHP = 0;
    }
    if (playerHP < 0) {
        playerHP = 0;
    }
    cout << endl;
    cout << "Enemy: " << enemyName << ' ' << "HP: " << enemyHP << " / " << enemyMaxHP << endl;
    cout << "Your HP: " << playerHP << " / 100" << endl;
    if (enemyHP <= 0) {
        cout << "\nVictory! You have defeated the " << enemyName << ".\n";
        return 1;
    }
    else {
        cout << "\nYou have been defeated by the " << enemyName << ".\n";
        cout << "You have lost 1 health point.\n";
        return 0;
    }
}
