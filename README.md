# ENGG1340/COMP2113 Group Project Proposal (Group 30)
 
## 1. Group members
CHENG HIN YEE (3035781988)

CHAN HIN TING (3035928299)
 
## 2. Introduction to the game
#### Game title: The forgotten mystic maze 
 
 
#### Game description:
The player will move in a maze. Besides the walls that the player cannot walk through, the maze contains two elements, which are mini game battles and random events. Players will encounter mini game battles to progress through the maze. If they lose the battle, they will lose a point of health. For the random events, the game will generate events randomly, which contain both positive and negative effects to the game progress. Examples of random events contain giving the player an item to skip one mini game, teleporting the player back to the spawn and restoring 1 health point.
 
#### Game rules:
The player will have 3 health points. When players lose a mini game battle, they will lose a health point. When the player has 0 health points, the game is lost and the player has to restart at the beginning. The random event generator will give the player a random effect. Both mini game battles and random event generators are not compulsory if they are not in the path of solving the maze. Players will win the stage if they reach the ending point of the maze.
 
## 3. Feature overview
 
### → Special features
 
When the player steps on the random event the player will have a chance to receive a special item and if the player steps on a minigame he has to complete the minigame in order to progress through the maze. The player will have a health bar and if he loses the minigames, the health will be reduced and if the player loses all his health, he will die and its game over.
 
### → Coding requirements
 
1. Generation of random game sets or events:

The random appearance of mini games in random locations in the maze
Random Tools will be dropped in random events
Randomness will also be present inside minigames (for example, rock paper scissors)
 
    
2. Data structures for storing game status:

We will mainly use arrays for storing the game status. For example, the main stage of the game, which is a maze, will be a 2D array. Moreover, we may declare self-defined data structures using struct. For example, using struct data type to store health and position of the player.
	
	
3. Dynamic memory management:

We will implement dynamic memory management by using pointers. For example, accessing a variable's access by '&' and point to the actually data by using '*'. Below are some functions for memory management that we might use in our game implementation.
	-malloc()
	-calloc()
	-realloc()
	-free()
 
4. File input/output (e.g., for loading/saving game status):

The player can save down its progress halfway through the game in case the player wishes to leave in the middle of the game. The game will return to its original progress with the same tools, same position of minigames, same health and position after a while if the player loads the game next time.
 
5. Program codes in multiple files:

Functions will be stored in different files and accessed by the main file through different .cpp files and .h files to increase modularity.
