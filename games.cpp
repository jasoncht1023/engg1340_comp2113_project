#include <iostream>
#include <ctime>
#include <string>
#include <stdlib.h>
#include <iomanip>
#define HEART   "\xE2\x99\xA5"
using namespace std;
void ttt_printwin(){      //input parameters: none, operations: prints the victory symbol, returns: none
cout << "  ___      ___  __     ______  ___________  ______     _______   ___  ___ "  << endl;
cout << "|\"  \\    /\"  ||\" \\   /\" _  \"\\(\"     _   \")/    \" \\   /\"      \\ |\"  \\/\"  | "  << endl;
cout << "\\   \\  //  / ||  | (: ( \\___))__/  \\\\__/// ____  \\ |:        | \\   \\  /  "  << endl;
cout << " \\\\  \\/. ./  |:  |  \\/ \\        \\\\_ /  /  /    ) :)|_____/   )  \\\\  \\/   "  << endl;
cout << "  \\.    //   |.  |  //  \\ _     |.  | (: (____/ //  //      /   /   /    "  << endl;
cout << "   \\\\   /    /\\  |\\(:   _) \\    \\:  |  \\        /  |:  __   \\  /   /     "  << endl;
cout << "    \\__/    (__\\_|_)\\_______)    \\__|   \\\"_____/   |__|  \\___)|___/   "  << endl;
}

void ttt_printlose(){//input parameters: none, operations: prints the lose symbol, returns: none
cout << "  ___        ______    ________  _______  " << endl;
cout << "|\"  |      /    \" \\  /\"       )/\"     \"| " << endl;
cout << "||  |     // ____  \\(:   \\___/(: ______) " << endl;
cout << "|:  |    /  /    ) :)\\___  \\   \\/    |   " << endl;
cout << "\\  |___(: (____/ //  __/  \\\\  // ___)_  " << endl;
cout << "( \\_|:  \\\\        /  /\" \\   :)(:      \"| " << endl;
cout << "\\_______)\\\"_____/  (_______/  \\_______)" << endl;
}

void ttt_printcastle(){//input parameters: none, operations: prints the mysterious castle, returns: none
  cout << "            +"<<endl;
  cout << "            A"<<endl;
  cout << "         __/_\\__"<<endl;
  cout << "        /\\-\'o\'-/\\"<<endl;
  cout << "       _||:<_>:||_"<<endl;
  cout << "      /\\_/=====\\_/\\"<<endl;
  cout << "     _|:_:_[I]_:_:|_"<<endl;
  cout << "  _/::::::::::::::::\\_"<<endl;
  cout << " _/::::::::::::::::::::\\_"<<endl;
  cout << "/::::::::::::::::::::::::\\"<<endl;
  cout << "You arrived at a mysterious castle emmitting a devious aura!" << endl;
  cout << "there seems to be a hooded figure at it's gate." << endl;
  cout << "------------------------------------------------" << endl;
}

void ttt_printlock(){//input parameters: none, operations: prints the hooded figure, returns: none
  cout << "the mysterious man speaks: \"to pass, break the cursed pattern on my face.\"" << endl;
  cout << "            *************"<<endl;
  cout << "           *****     *****"<<endl;
  cout << "          ***           ***"<<endl;
  cout << "         ***   0     0    ***"<<endl;
  cout << "        **                **"<<endl;
  cout << "        **    1  2  3     **                  ____"<<endl;
  cout << "        ***   4  5  6    ***             //////////"<<endl;
  cout << "         **** 7  8  9   ****        ///////////////  "<<endl;
  cout << "        *****         *****    ///////////////////"<<endl;
  cout << "        ******       ******/////////         |  |"<<endl;
  cout << "      *********     ****//////               |  |"<<endl;
  cout << "   *************   **/////*****              |  |"<<endl;
  cout << "  *************** **///***********          *|  |*"<<endl;
  cout << " ************************************    ****| <=>*"<<endl;
  cout << "*********************************************|<===>* "<<endl;
  cout << "*********************************************| <==>*"<<endl;
  cout << "***************************** ***************| <=>*"<<endl;
  cout << "******************************* *************|  |*"<<endl;
  cout << "********************************** **********|  |*  "<<endl;
  cout << "*********************************** *********|  |"<<endl;
}

void ttt_printgrid(char grid[3][3]){ //input parameters: takes in tic tac toe grid, operations: prints the tic tac toe grid, returns: none
  for (int i = 0; i < 3; ++i){
    for (int j = 0; j < 3; ++j){
      cout << grid[i][j] << " ";
    }
    cout << "" << endl;
  }
}

int ttt_playerdecision(char grid[3][3], char player){ //input parameters: character tic tac toe grid and the position the player decides to place his move
  for (int i = 0; i < 3; ++i){                       // operations:checks if the players placement is valid, if valid then places move, if not then print incorrect input
    for (int j = 0; j < 3; ++j){                      //returns: 1 if move is valid and updated, 0 if not valid
      if (grid[i][j] == player){
        grid[i][j] = 'X';
        return 1;
      }
    }
  }
  cout << "incorrect input" << endl;
  return 0;
}

int ttt_devildecision(char grid[3][3], char devil){       //same as above, except it is for the computer and not the player
  for (int i = 0; i < 3; ++i){
    for (int j = 0; j < 3; ++j){
      if (grid[i][j] == devil){
        grid[i][j] = 'O';
        return 1;
      }
    }
  }
  cout << "incorrect input" << endl;
  return 0;
}

void ttt_update_selectable(char selectable[], char choice){ //input parameters: an array that contains the moves that the computer is able t perform and the choice the computer or player takes, operations: updates the selectable choice, puts an X if the move is already done before, returns: none
  for (int i = 0; i < 9; ++i){
    if (selectable[i] == choice){
      selectable[i] = 'X';
    }
  }
}

int ttt_devils_choice(char selectable[], int size){       //input parameters: the selectable array(defined above and below) and the size of the array, operations: randomly generates an number to be the devils choice, checks if the position has been previous occupied, returns: the computer choice if it is valid
  int choice;
  while(true){
    srand(time(0));
    choice = rand() % 9;
    for (int i = 0; i < size; ++i){
      if (selectable[choice] != 'X'){
      return choice;
      }
    }
  }
}

bool ttt_checkvictory(char grid[3][3], char player){ //input parameters: the grid and the player (meaning the actual player or the demon), operations: defines what it means to win, returns: true if the player acheive any of the below victory cases and false if none of the cases are met
  if (grid[0][0] == player && grid[0][1] == player && grid[0][2] == player){
    return true;
  }
  if (grid[1][0] == player && grid[1][1] == player && grid[1][2] == player){
    return true;
  }
  if (grid[2][0] == player && grid[2][1] == player && grid[2][2] == player){
    return true;
  }
  if (grid[0][0] == player && grid[1][0] == player && grid[2][0] == player){
    return true;
  }
  if (grid[0][1] == player && grid[1][1] == player && grid[2][1] == player){
    return true;
  }
  if (grid[0][2] == player && grid[1][2] == player && grid[2][2] == player){
    return true;
  }
  if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player){
    return true;
  }
  if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player){
    return true;
  }
  return false;
}
int ttt_main(){                       //the main for tic tac toe
  char ttt_grid[3][3] = {'1','2','3','4','5','6','7','8','9'}; //grid for tic tac toe as array
  char devil_selectable[] = {'1','2','3','4','5','6','7','8','9'}; //an array that include all selectable choices, it will be updated everytime a move is made, it is for the reference of the computer
  char con1, con2;
  char playermove;
  int num_selectable = 9;
  ttt_printcastle();
  cout << "press any character to continue > ";
  cin >> con1;
  system("clear");
  ttt_printlock();
  cout << "press any character to continue > ";
  cin >> con2;
  system("clear");
  ttt_printgrid(ttt_grid);
  while (num_selectable >= 0){                //a while loop that keeps going until there are no seleactable choices and a victory or a tie is achieved
    cout << "Your move: ";
    cin >> playermove;
    ttt_playerdecision(ttt_grid, playermove);
    ttt_printgrid(ttt_grid);
    num_selectable -= 1;
    ttt_update_selectable(devil_selectable, playermove);
    if (num_selectable == 0) {
      cout << "it is a tie" << endl;
      return 2;
      break;
    }
    cout << "devils turn!" << endl;
    int num = ttt_devils_choice(devil_selectable, num_selectable);
    ttt_devildecision(ttt_grid, devil_selectable[num]);
    num_selectable -= 1;
    ttt_update_selectable(devil_selectable, devil_selectable[num]);
    ttt_printgrid(ttt_grid);
    if (ttt_checkvictory(ttt_grid, 'X') == true){
      ttt_printwin();
      return 1;
      break;
    }
    if (ttt_checkvictory(ttt_grid, 'O') == true){
      ttt_printlose();
      return 2;
      break;
    }
  }
}

void killer_swap(string & a, string & b){ //input parameter: takes in two elements in the array to be shuffled and swaps it, operations: swaps two elements, returns: non becuase its call by reference
    string temp = a;
    a = b;
    b = temp;
}

void killer_randomise(string array[]){ //input parameters: a string array with elements to be shuffled. operations: take in a random number/index and swaps it with the last elment in the array, returns: none
  for (int i = 4; i > 0; i--){
    int index = rand() % (i+1);
    killer_swap(array[i], array[index]);
  }
}

void killer_printarray(string objects[]){ //input parameter: string object array(either of clothes,location, weapon), operations: prints out the elements in the array, return: none
  for (int i = 0; i < 5; ++i){
    cout << left;
    cout << setw(13) << objects[i];
  }
}
void killer_print_instructions(){ //input parameter: none, operations: prints out instructions, return: none
  cout << "It is a eeriee night, a pitch black sky with freezing winds. A familiar chill ran up sherlock's spine, instictively he knew a bloody murder has undoubting taken place tonight. As he expected, he was called to the police station." << endl;
  cout << "Different from previous cases though, the police cheif told sherlock they had narrowed the suspects down to five people and have already question them for clues" << endl;
    cout << "Each suspect is associated with a location, weapon and clothes" << endl;
  cout << "With the clues from the suspects present, just match the clues with the evidence found from the police report to find the culprit!" << endl;

}
void killer_print_police(){ //function to print police picture
  cout << "          ,"<<endl;
  cout << "     _.-\"` `\'-."<<endl;
  cout << "     \'._ __{}_("<<endl;
  cout << "      |\'--.__\\"<<endl;
  cout << "      (   ^_\\^"<<endl;
  cout << "       |   _ |"<<endl;
  cout << "       )\\___/"<<endl;
  cout << "   .--\'`:._]"<<endl;
  cout << "  /  \\      \'-. "<<endl;
}

void killer_print_fire(){ //function to print out a mushroom cloud and the story of someone blowing the clues up
  cout << "Oh no! Someone blew up the clues!" << endl;
  cout <<"      _.-^^---....,,--       "<<endl;
  cout <<"  _--                  --_  "<<endl;
  cout <<"<                        >)"<<endl;
  cout <<"|                         | "<<endl;
  cout <<"\\._                   _./  "<<endl;
  cout <<"   ```--. . , ; .--\'\'\'       "<<endl;
  cout <<"          | |   |          "<<endl;
  cout <<"       .-=||  | |=-.   "<<endl;
  cout <<"       `-=#$%&%$#=-\'   "<<endl;
  cout <<"          | ;  :|     "<<endl;
  cout <<"_____.,-#%&$@%#&#~,._____"<<endl;
}

int killer_main(){ //main for the killer games
  srand(time(NULL));
  //arrays for the clues
  string people[5] = {"count", "dutches", "solomon", "ted", "escobar"};
  string clothes[5] = {"uniform", "tuxedo", "cloak", "hoodie", "raincoat"};
  string location[5] = {"cementary", "school", "castle", "hospital", "museum"};
  string weapon[5] = {"poisen", "glock16", "chainsaw", "katana", "brick"};
  //get shuffled arrays
  killer_randomise(clothes);
  killer_randomise(location);
  killer_randomise(weapon);
  //print instructions
  killer_print_instructions();
  cout << "press any character to continue >";
  char next;
  cin >> next;
  system("clear");
  //print the shuffled clues
  killer_printarray(people);
  cout << "" << endl;
  cout << setw(13) << "-----" << setw(13) << "-------" << setw(13) << "-------" << setw(13) << "---" << setw(13) << "-------" << endl;
  killer_printarray(clothes);
  cout << "" << endl;
  killer_printarray(location);
  cout << "" << endl;
  killer_printarray(weapon);
  cout << "" << endl;
  //get random killer
  int killer = rand()%5;
  cout << "---------------------------------------------" << endl;
  cout << "have you finish examining the clues sherlock?" << endl;
  cout << "press any character to continue >";
  char next1;
  cin >> next1;
  system("clear");
  killer_print_fire();
  cout << "press any character to continue >";
  char next2;
  cin >> next2;
  system("clear");
  killer_print_police();
  cout << "the police report came in!" << endl;
  cout << "----------------------------" << endl;
  cout << "The location of death is at " << location[killer] << ". Though examination of the dead body, the object used for murder was found to be a " << weapon[killer] << ". In the CCTV, we saw a figure wearing " << clothes[killer] << "." <<endl;
  cout << "Who is the killer?(count/dutches/solomon/ted/escobar): ";
  string guess;
  //get player guess
  cin >> guess;
  //check if the guess is right
  if (guess == people[killer]){
    cout << "Splendid, the culprit is behind bars! Well done sherlock!" << endl;
    return 1;
  }
  else{
    cout << "No, you caught an innocent person...the culprit will now go on to murder more people." << endl;
    return 0;
  }
}

void number_printcrystal(){ //no input parameters, no return, function to print out a globe
  cout << "              *    .    " << endl;
  cout << "      \'  +   ___    @    ." << endl;
  cout << "          .-\" __\"-.   + "  << endl;
  cout << "  *      /:.\'`__`\'.\\       \'" << endl;
  cout << "      . |:: .\'_ `. :|   *" << endl;
  cout << " @      |:: \'._\' : :| ." << endl;
  cout << "    +    \\:\'.__.\' :/       \'" << endl;
  cout << "          /`-...-\'\\  \'   +" << endl;
  cout << " '       /         \\   .    @" << endl;
  cout << "   *     `-.,___,.-\'" << endl;
}

void number_instructions(){
  cout << "destinated number" << endl;
  cout << "Instructions: In this game, you have six guesses to find your" << endl;
  cout << "destinated number which is within the range 0 - 99. Each time" << endl;
  cout << "you guess a number, unless the number guessed is your destinated" << endl;
  cout << "number, the fairy will tell you if the number you guessed " << endl;
  cout << "is larger or smaller than you destined number." << endl;
}
int number_main(){
  //get a random number from the range 0 - 99
  srand(time(0));
  int destinated_num = rand() % 100;
  number_instructions();
  //for loop that give 7 chances to the player to guess the answer
  for (int i = 0; i < 7; ++i){
    number_printcrystal();
    //get guess
    int guess;
    cout << "-----------------------------------------" << endl;
    cout << "Reach deep into your soul for the answer: ";
    cin >> guess;
    //check if guess is larger, smaller or equal to answer
    if (guess > destinated_num){
      cout << "Your destined number is smaller than what you guessed!" << endl;
    }
    if (guess < destinated_num){
      cout << "Your destined number is larger than what you guessed!" << endl;
    }
    if (guess == destinated_num){
      cout << "-----------------------------------------" << endl;
      cout << "You found your destinated number! Luck shall company your side!" << endl;
      return 1;
      break;
    }
    if (guess != destinated_num &&  i == 6){
      cout << "-----------------------------------------" << endl;
      cout << "You future is shrouded with mystery, help old ladies across the street for better luck..." << endl;
    }
  }
  return 0;
}

void rps_instructions(){   //input parameter and return none, fucntion prints instruction of rock paper scissor
  cout << "You encountered a demon of a forgotten past" << endl;
  cout << "Your old mage companion tells you that the demons only battle with symbols" << endl;
  cout << "The symbols are rock paper and scissors" << endl;
  cout << "Wait...that is just a game of rock paper scissors!" << endl;
  cout << "Winning the demon in one game of rock paper scissors will decrease the health of the demon by 1" << endl;
  cout << "To aid you battle, the mage gives you the sword of power" << endl;
  cout << "It will be automatically activated when you acheive two consecutive attacks on the demon" << endl;
  cout << "The sword will decrease the demons health by 1"<< endl;
  cout << "The first one to have it's health depleted will lose!" << endl;
}
void rps_printmonster(int num_hearts){ //input parameter is health of demon and return none, fucntion prints the demon and its health
  cout <<"  ,    ,    /\\   /\\ " << endl;
  cout <<" /( /\\ )\\  _\\ \\_/ /_ " << endl;
  cout <<" \\______/  \\|0   0|/ " << endl;
  cout <<"   _\\/_   _(_  ^  _)_ " << endl;
  cout <<"  ( () ) /`\\|V\"\"\"V|/`\\ " << endl;
  cout <<"    {}   \\  \\_____/  / " << endl;
  cout <<"    ()   /\\   )=(   /\\ " << endl;
  cout <<"    {}  /  \\_/\\=/\\_/  \\ " << endl;
  cout <<"---------------------" << endl;
  cout << "HEALTH: ";
  for (int i = 0; i <= num_hearts ; ++i){
    if (i == num_hearts){
      cout << HEART << endl;
    }
    else{
      cout << HEART << "  " ;
    }
  }
}

void rps_printhero(int num_hearts){ //input parameter is the health of hero and return none, fucntion prints the hero
  cout << "|\\             // " << endl;
  cout << " \\\\           _!_     " << endl;
  cout << "  \\\\         /___\\    " << endl;
  cout << "   \\\\        [+++]     "  <<endl;
  cout << "    \\\\    _ _\\^^^/_ _   "<<endl;
  cout << "     \\\\/ (    \'-\'  ( )   "<<endl;
  cout << "     /( \\/ | {&}   /\\ \\  "<<endl;
  cout << "       \\  / \\     / _> )   "<<endl;
  cout << "        \"`   >:::;-'`""'-.   "<<endl;
  cout << "            /:::/         \\   "<<endl;
  cout << "           /  /||   {&}   |   "<<endl;
  cout << "          (  / (\\         /   "<<endl;
  cout << "          / /   \\'-.___.-'  "<<endl;
  cout << "        _/ /     \\ \\   "<<endl;
  cout << "      /___|    /___|      "<<endl;
  cout <<"---------------------" << endl;
  cout << "HEALTH: ";
  for (int i = 0; i <= num_hearts ; ++i){
    if (i == num_hearts){
      cout << HEART << endl;
    }
    else{
      cout << HEART << "  " ;
    }
  }
}
void rps_print_special_attack(){//input parameter and return none, fucntion prints the sword of power when activated
cout << "      /\\   " << endl;
cout << "     // \\" << endl;
cout << "     || |" << endl;
cout << "     || |" << endl;
cout << "     || |" << endl;
cout << "     || |" << endl;
cout << "     || |" << endl;
cout << "  __ || | __" << endl;
cout << " /___||_|___\\" << endl;
cout << "      ww" << endl;
cout << "      MM" << endl;
cout << "     _MM_" << endl;
cout << "    (&<>&)" << endl;
cout << "     ~~~~" << endl;
cout << "YOU USED SPECAIL ATTACK: SWORD OF POWER!" << endl;
}
void rps_printwin(){//input parameter and return none, fucntion prints victory sign
cout << "  ___      ___  __     ______  ___________  ______     _______   ___  ___ "  << endl;
cout << "|\"  \\    /\"  ||\" \\   /\" _  \"\\(\"     _   \")/    \" \\   /\"      \\ |\"  \\/\"  | "  << endl;
cout << "\\   \\  //  / ||  | (: ( \\___))__/  \\\\__/// ____  \\ |:        | \\   \\  /  "  << endl;
cout << " \\\\  \\/. ./  |:  |  \\/ \\        \\\\_ /  /  /    ) :)|_____/   )  \\\\  \\/   "  << endl;
cout << "  \\.    //   |.  |  //  \\ _     |.  | (: (____/ //  //      /   /   /    "  << endl;
cout << "   \\\\   /    /\\  |\\(:   _) \\    \\:  |  \\        /  |:  __   \\  /   /     "  << endl;
cout << "    \\__/    (__\\_|_)\\_______)    \\__|   \\\"_____/   |__|  \\___)|___/   "  << endl;
}

void rps_printlose(){//input parameter and return none, fucntion prints lose sign
cout << "  ___        ______    ________  _______  " << endl;
cout << "|\"  |      /    \" \\  /\"       )/\"     \"| " << endl;
cout << "||  |     // ____  \\(:   \\___/(: ______) " << endl;
cout << "|:  |    /  /    ) :)\\___  \\   \\/    |   " << endl;
cout << "\\  |___(: (____/ //  __/  \\\\  // ___)_  " << endl;
cout << "( \\_|:  \\\\        /  /\" \\   :)(:      \"| " << endl;
cout << "\\_______)\\\"_____/  (_______/  \\_______)" << endl;
}

char rps_devils_choice(){//input parameter none, fucntion takes random computer choice of either rock paper or scissor, return: the choice of the computer
  srand(time(0));
  int choice = rand() % 3;
  if (choice == 0){
    return 'r';
  }
  if (choice == 1){
    return 'p';
  }
  if (choice == 2){
    return 's';
  }
}

string rps_your_choice(){//input parameter none, fucntion gets the choice of the player, returns the choice of the player
  string choice;
  cout << "Choose your holy hand sign!(rock/paper/scissor): ";
  cin >> choice;
  return choice;
}

string rps_who_wins(char devil, string hero){ //input parameter takes in the user and computer input and return the winner of each round, fucntion defines whether the computer of the player wins under different cases in rock paper scissors
  if (devil == 'r' && hero == "rock"){
    return "tie";
  }
  if (devil == 's' && hero == "scissor"){
    return "tie";
  }
  if (devil == 'p' && hero == "paper"){
    return "tie";
  }
  if (devil == 'r' && hero == "scissor"){
    return "devil";
  }
  if (devil == 'r' && hero == "paper"){
    return "hero";
  }
  if (devil == 's' && hero == "rock"){
    return "hero";
  }
  if (devil == 's' && hero == "paper"){
    return "devil";
  }
  if (devil == 'p' && hero == "rock"){
    return "devil";
  }
  if (devil == 'p' && hero == "scissor"){
    return "hero";
  }
}

int rps_main(){ //main for rock paper scissors
  rps_instructions();
  //health of players
  int special = 0;
  int hero_health = 5;
  int devil_health = 5;
  //while loop to keep going until the health drops to 0
  while (hero_health > 0 && devil_health > 0){
    char enemy = rps_devils_choice();
    string you = rps_your_choice();
    string result = rps_who_wins(enemy, you);

    if (result == "tie"){
      cout << "The devil used the same holy sign!" << endl;
    }
    if (result == "devil"){
      hero_health -= 1;
      special = 0;
      cout << "You used the wrong sign! Concentrate into the cosmos for the right answer!" << endl;
    }
    if (result == "hero"){
      devil_health -= 1;
      special += 1;
      cout << "You hurt the devil!" << endl;
    }
    //if two consecutive attacks further decrease health of computer by 1
    if (special == 2){
      rps_print_special_attack();
      special = 0;
      devil_health -= 1;
    }
    if (hero_health > 0 && devil_health > 0){
      rps_printmonster(devil_health - 1);
      rps_printhero(hero_health - 1);
    }
    if (devil_health <= 0){
      rps_printwin();
      return 1;
    }
    if (hero_health <= 0){
      rps_printlose();
      return 0;
    }
  }
}
int main(){
  rps_main();

}
