### IY453 Milestone 1

| Assessment Details | Please Complete All Details |
| ------------------ | --------------------------- |
| Group              | 453 A                       |
| Module Title       | C++                         |
| Assessment Type    | Stage 1                     |
| Module Tutor Name  | Mustafa Ghashim             |
| Student ID Number  | P488221                     |
| Date of Submission |                             |
| Word Count         |                             |

- [x] *I confirm that this assignment is my own work. Where I have referred to academic sources, I have provided in-text citations and included the sources in
  the final reference list.*

- [x] *Where I have used AI, I have cited and referenced appropriately.

### Introduction

In this project, I am developing a text-based adventure game where the player, through his choice, approaches certain endings. The goal of the game is to lead the player to the logical end: victory or defeat. At the beginning of the game, the player enters a name, which is later mentioned in dialogues with non-player characters(npc). The game will include a system of stats and loot: items will affect stats, such as attack, defense, or health. Loot will be dropped due to defeating monsters, solving any logical problems. It is also planned to create a system of points that are added for defeating monsters and solving puzzles; points will be shown at the end of the game, to show the player’s score. Also, player’s results during the game will be saved, while it is not clear what it will look like: as an auto-save or through the menu.

The combat mechanics will be based on randomness and dropping items. The player's damage is set by a certain range: for example, initially he will have from 5 to 10 damage per attack, and after finding an object, such as a sword, the damage will increase to 7-12 attack units. In addition to combat, the player will have the choice to avoid battle through a stealth check: it will be the same as the damage system. For example, if 6 to 10 drops, the escape is successfully triggered; if less, the mob either attacks first, thereby gaining an advantage, or by dealing the first blow, the damage will be increased. Thus, the player gets a choice: to get loot from defeated mobs, thereby increasing the chance of success of the passage, or to pass quickly, but with a lower chance of success.

This project consists of several steps. Stage 1 - at this stage, you need to decide what the game will look like, and describe it in the introduction, then create an input/output/process table and create the first sketches of the algorithm for this game. The next step is to implement the code: write the basic functions, and if the code was taken from other programs, you need to refer to it. Stage 3 is the stage where you need to make a test of the received program, that is, describe the tests that were performed and add screenshots that prove the correctness of the code. At Stage 4, the final review of this project is performed, that is, the last week when you can change something before handing it over.

### Functional Requirements

1) Start game

System should begin the new game and give basic stats of the player.

2) Player’s input

System should ask the name of the player, and then use it in dialogues with NPC.

3) Story twists

System should give to player plot scenes where he should choice one of the options, where each choice changes the end.

4) Player stats

System should always collect and save player’s stats.

5) Loot

System should give loots after each fight with mobs or solving puzzles, also they should store in inventory and approve player’s stats.

6) Combat system

System should realize fight with mobs: player’s damage depends on the number which taken randomly from the certain diapason.

7) Enemy damage

System should support different diapasons of the damage to different types of enemies (example: goblin 3-6, dragon 10-15)

8) Stealth escape mechanic

System should give opportunity to player to escape the fight, if value bigger than value of mob the fight successfully escaped, if not mob attack first or have boost in first attack.

9) Puzzle

System should give different puzzles, where the reward will be progression in plot, giving good loot or scores.

10) Score system

Scores should be given by solving puzzles or beating mobs, at the end system shows
total scores.

11) NPC

Player should communicate with NPCs where they will help to achieve the best result,
player will have two options how to answer them, based on his chose NPC will help or no.

12) Save game

System should save the progress of the player such as loot, stats, scenes. The format will be auto saving or through menu (will be decided later).

13) Load game

System should give a choice to begin  from the start or continue with the saved results.

14) Input validation

System should checks the valid of the input, if it is not correct say what the problem and ask to do it until the input becomes correct.

### Input Process Output Table

| Feature / Task             | Inputs                 | Processing (what the system does)                                                           | Outputs                                  |
| -------------------------- | ---------------------- | ------------------------------------------------------------------------------------------- | ---------------------------------------- |
| Start program              | None (program launch)  | Initialise game variables (default stats, empty inventory, score); show main menu           | Main menu displayed                      |
| Display main menu          | User menu choice (1-3) | Validate input is an integer in range; route to selected option                             | Next screen shown                        |
| New game                   | User confirms new game | Reset progress                                                                              | Ask for player's name                    |
| Enter name                 | Player's name          | Save name                                                                                   | Intro text shown with player name        |
| Story scenes: show choices | None                   | Display scene text; display two options (1/2)                                               | Scene text + 2 options displayed         |
| Choose option              | User's choice          | Update scene according to player's choise                                                   | Next scene displayed                     |
| NPC dialogue               | User choice(1 or 2)    | Update scene according to user's input                                                      | NPC's dialogue, updated story            |
| Enemy                      | none                   | Create enemy stats; offer fight or escape                                                   | Enemy encountered + 'Fight/Escape' shown |
| Fighr(player atack)        | none                   | Generate players damage, minus from enemies HP                                              | Damage, mob's HP shown                   |
| Fight (enemy atack)        | None                   | Generate mobs damage, minus from hero's HP                                                  | Damage taken, updated player's HP        |
| Stealth escape etempt      | User choice Escape     | generate number, if its more then mob's stat skip mob, if not enemy has advantage in attack | Escape Success or fight                  |
| Win combat                 | None                   | if mob's HP <= 0, got an iten, continue journey                                             | loot received, stats updated, next scene |
| Puzzle                     | User's answer          | Check the answer, if correct got item and progress in plot, else going to bad scenario      | Puzzle result                            |
| End game                   | none                   | When player's HP <= 0 or he beated the finall boss                                          | Ending text, final sore                  |
| save game                  | User's choice or none  | Write progress(stats, inventory, scene) to file                                             | "Game saved"                             |
| Load game                  | User's choice continue | Read saved file, and continue process                                                       | Saved scene                              |
| Input validation           | Any Invalid input      | Detect Invalid input, ask to write again untill its correct                                 | Error message , "try again"              |
