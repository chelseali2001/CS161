Chelsea Li
933-294-417
CS161-020
Assignment 5
2/8/20

Description: 
My program stores a representation of moon rocks in a treasure chest. The user determines the size of the chest and can either add, remove, randomly add, show, move, or edit a moon rock for the treasure chest. The user can also decide where to put the moon rock and decide the attributes for each rock. The attributes of the moon rocks are: name, color, texture, weight, and monetary value. From time to time, NASA might decide to change the value of one of the moon rocks.

Instructions:
1. To compile my program, enter: g++ assign5_treasure.cpp -o a
2. Then to run the program, enter: ./a
3. The user will first enter the number of rows and columns to determine the size of the treasure chest. The user can only enter integers greater than 0.
4. The user will then select an operation from a menu by entering the number that corresponds with the function. For example:
	1) add_rock()
	2) remove_rock()
	Enter 1 to use add_rock() or enter 2 to use remove_rock()
5. The menu will include these options:
	1) Add a moon rock - allows the user to enter a moon rock.
	2) Remove a moon rock - allows the user to remove a moon rock.
	3) Add random moon rock - allows the user to add a random moon rock.
	4) Show moon rock - allows the user to examine the details of a moon rock.
	5) Move moon rock - allows the user to change the location of a moon rock.
	6) Edit moon rock - allows the user to change the attributes of a moon rock.
	7) Quit - allows the user to quit the program.
6. When choosing an operation the user must enter an integer between 1-7.
7. If the treasure chest if full, the program won't let the user use options 1 and 3.
8. If the treasure chest is empty, the program won't let the user use options 2, 4, 5, and 6.
9. If the 1st option is chosen, the user will first be prompted to enter a specifc row and column to add the moon rock. The user must enter an integer that's in bounds and it must be an empty location. Then the user must enter the following attributes about the moon rock: name (string), color (string), texture (string), weight (float), and monetary value (float).
10. If the 2nd option is chosen, the user will first be prompted to enter a specific row and column for an existing moon rock to be removed. The user must enter an integer that's in bounds and it must be a location where there's already a moon rock.
11. If the 3rd option is chosen, the user will be prompted to enter a specific row and column for the program to set a randomly generated moon rock. The user must enter an integer that's in bounds and it must be an empty location.
12. If the 4th option is chosen, the user will be prompted to enter a specific row and column for an existing moon rock. The user must enter an integer that's in bounds and it must be a location where there's already a moon rock.
13. If the 5th option is chosen, the user will first be prompted to enter a specific row and column for an existing moon rock. The user must enter an integer that's in bounds and it must be a location where there's already a moon rock. The user will then be prompted to enter a new row and column so that the chosen moon rock will be moved to that new location. The user must enter an integer that's in bounds and it must be an empty location.
14. If the 6th option is chosen, the user will first be prompted to enter a specific row and column for an existing moon rock. The user must enter an integer that's in bounds and it must be a location where there's already a moon rock. The user will be able to change all of the attributes of the chosen moon rock. 
15. Everytime the user finishes an operation, the program will print out the treasure chest to show its contents.
16. If there is at least one moon rock in the treasure chest, the program will decide whether or not one of the moon rock's monetary value should be changed. The new monetary value of the randomly selected moon rock can range from $50,000-1,500,000.
17. After the contents are shown (along with the new value of one of the rocks if it changed), the program will show the total number of rocks and the total monetary value of the rocks in the treasure chest.

Limitations:
The program doesn't check if the user enters the correct data type for each input. 

Extra Credit:
The 6th option is the extra function. The 6th option allows the user to change the attributes of a moon rock. The user will first be prompted to enter a specific row and column for an existing moon rock. The user must enter an integer that's in bounds and it must be a location where there's already a moon rock. The user will be able to change all of the attributes of the chosen moon rock.

There's also a luck aspect to the game. Every time the user makes a menu choice, the program will decide whether or not it should change the monetary value of a random moon rock (there has to be at least one moon rock in the treasure chest or else there won't be any values to change). If the program decides to change a random moon rock, the program will randomly change its montary value to a number between $50,000-1,500,000.

