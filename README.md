# ENGG1340/COMP2113 Group Project Proposal (Group 30)
 
## 1. Group members
CHENG HIN YEE (3035781988) (FrancisCheng123)

CHAN HIN TING (3035928299) (jasoncht1023)
 
## 2. Introduction to the game
#### Game title: The forgotten mystic maze 
 
 
#### Game description:
The player will move in a maze. Besides the walls that the player cannot walk through, the maze contains two elements, which are mini game battles and random events. Players will encounter mini game battles to progress through the maze. If they lose the battle, they will lose a point of health. For the random events, the game will generate events randomly, which contain both positive and negative effects to the game progress. Examples of random events contain giving the player an item to skip one mini game, teleporting the player back to the spawn and restoring 1 health point.
 
#### Game rules:
The game contains 3 levels of difficulty with different maze sizes. The player could choose one of the difficulties to begin the game. In all levels of difficulty, the player will have 3 health points. Players have to step on mini game battle or the random event cells in the maze instead of walking across them if they are in the player's moving path. When players lose a mini game battle, they will lose a health point. When the player has 0 health points, the game is lost. The random event generator will give the player a random effect. Both mini game battles and random event generators are not compulsory if they are not in the path of solving the maze. Players will win the stage if they reach the ending point of the maze with at least 1 HP.
 
## 3. Feature overview
 
### → Special features
 
When the player steps on the random event the player will have a chance to receive a special item and if the player steps on a minigame he has to complete the minigame in order to progress through the maze. The player will have a health count and if he loses the minigames, the health will be reduced and if the player loses all his health, he will die and its game over.

List of mini game battles that players may face (chosen randomly in the game):
1. Hangman
2. Typing Battle
3. Mini Battle
4. Killer
5. Tic Tac Toe
6. Guessing number
7. Rock Paper Scissors

List of random events that players may face (chosen randomly in the game):
1. Teleport the player back to the spawn
2. Prompt another mini game battle
3. Blessing (Nothing happens)
4. Giving an item to players for skipping one mini game battle
5. Giving an item to players for restoring 1 HP when the player dies
6. Restore 1 HP if the player is not full health
7. Mysterious event (A prank, only will trigger once and will not re-appear after that)
 
### → Coding requirements
 
##### 1. Generation of random game sets or events:

Randomness is a big part of the game. Firstly, all the mini game battles and random events are randomly selected from the lists shown above. Also in each mini game battles, there are random elements that could keep the games refreshing and not repetitive. For example, in Typing Battle, the sentences are randomly inputted from the file so that the player will not have to type the same sentences every time. Also, in Killer, the clues will be randomly changed so that players will have different experience every time. 
    
##### 2. Data structures for storing game status:

We mainly used arrays for storing the game status. For example, the main stage of the game, which is a maze, will be a 2D array. For the Typing Battle mini game, we used a vector to store the string input from the file. Moreover, we declared self-defined data structures using struct. We used struct to store all the status of the player, including health, position, whether the player has certain items and so on.
		
##### 3. Dynamic memory management:

We used 3 dynamic arrays to store 3 maze templates for the mazes of the corresponding difficulty. One of the mazes will be copied to the main maze that is used in the main game after the player has decided the difficulty. All 3 dynamic arrays will be deleted to free memory space after the main game maze is confirmed. Also, the main game maze is a dynamic 2D array since the size of the maze is not known until the player chooses the diffculty. In addition, we used vector in the Typing Battle mini game, which automatically allocate memory for storing data.
 
##### 4. File input/output (e.g. for loading/saving game status):

The Hangman and Typing Battle mini game rely on external text file included in the folder for string input. For hangman, a random word will be read from "hangman_wordlist.txt" for the player to guess. For Typing Battle, several strings will be read from "typing_strlist.txt". Moreover, The player can save down its progress halfway through the game in case the player wishes to leave in the middle of the game. The game will return to its original progress with the same tools, same position of minigames, same health and position after a while if the player loads the game next time. The player can save the game in the middle of the game by the "save" command, which all essential game status will be outputted to a .txt game save file. The player can choose to start a new game or load the previous saved game in the game title menu. 
 
##### 5. Program codes in multiple files:

Functions will be stored in different files and accessed by the main file through different .cpp files and .h files to increase modularity. In our game, we put our mini games in two .cpp files, namely minigame1.cpp and minigame2.cpp so that we have work concurrently to increase efficiency. The functions in minigame1.cpp and minigame2.cpp are called and used in the main.cpp file, which is the main game.

## 4. Compilation, execution and testing instructions

#### Important: The project should be compiled and ran in the HKU CS Academy server because some characters in the game may not able to be shown on the Windows platform. Using the X2Go client is recommended.

#### 1. Compilation:
The project should be downloaded via Github with .zip file to the CS server or directly cloned to the server. Then, go the the folder position using linux terminal and execute "$make fm_maze". Makefile will automatically compile all essential source codes and generate fm_maze, which is the main game.

#### 2. Execution:
In the same folder, execute "$./fm_maze" to run the game.

#### 3. Testing:
Tester could test the game following the game instructions. In the menu, the player can choose to read game instructions before jumping into the actual game. During the actual game, the player can type "help" (without the double quotation mark) and enter to show the command list. All available commands will be shown. We provided some sample game save files in the engg1340_comp2113_project/sample_game_saves folder. To use them, rename one of the sample game save file to "gamesave.txt" (without the double quotation mark) and move it to engg1340_comp2113_project main folder. Then, run the game and select load game save in the title page. The game save file must be unique.
