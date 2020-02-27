/******************************************************************************
** Program: assign2_game.cpp
** Author: Chelsea Li
** Date: 01/19/2020
** Description: This program is a text adventure game.
** Input: Integers.
** Output: A message/new path and a random number of points earned or lost.
*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	bool done = false;

	do {
		// I assume choice is between 1 and 3.
		// So a unsigned short int (min 0, max 65,535) is sufficient.
		unsigned short int choice = 0;

		// I assume gain, lose, and score is between -100 and 100.
		// So a signed short int (min -32,768, max 32,767) is sufficient.
		signed short int gain = 0, lose = 0, score = 0;
		
		srand(time(NULL));

		//Path 1: Fork road.
		cout << "Welcome to Candy Land! You have 0 points." <<endl
			<< "You are at a fork road: Do you:" <<endl
			<< "(1) Take the right path." <<endl
			<< "(2) Take the left path." <<endl;

		bool correct = false;

		while (!correct) {
			cin >> choice;

			if (choice == 1 || choice == 2) {
				correct = true;
			} else {
				cout << "Error: invalid input, try again." <<endl;
			}
		}

		if (choice == 1) {
			gain = (rand() % 10) + 1;
			score += gain;

			//Path 2: The old man.
			cout << "You gain " << gain << " points for a score of " << score << " points." <<endl
				<< "\nYou encounter an old man. Do you:" <<endl
				<< "(1) Ignore him and keep walking." <<endl
				<< "(2) Ask him where you can find the sacred candy gem." <<endl
				<< "(3) Steal his money." <<endl;

			cin >> choice;

			if (choice == 1) {
				gain = rand() % 6;
				score += gain;

				//Path 3: Temple and rundown house.
				cout << "You gain " << gain << " points for a score of " << score << " points." <<endl
					<< "\nYou encounter a temple and a rundown house. Do you enter: " <<endl
					<< "(1) The temple." <<endl
					<< "(2) The rundown house." <<endl;

				cin >> choice;

				if (choice == 1) {
					gain = (rand() % 10) + 1;
					score += gain;

					//Path 4: Trapped in temple.
					cout << "You gain " << gain << " points for a score of " << score << " points." <<endl
						<< "\nThe door closes behind you. You see a lever, a window, and a door. Do you:" <<endl
						<< "(1) Pull the lever." <<endl
						<< "(2) Try to escape through the window." <<endl
						<< "(3) Go through the door." <<endl;

					cin >> choice;

					if (choice == 1) {
						lose = (rand() % 20) + 15;
						score -= lose;

						//Path 5:  Water flowing in room.
						cout << "You lose " << lose << " points for a score of " << score << " points." <<endl
							<< "\nWater starts flowing into the room." <<endl
							<< "There's no way for you to escape." <<endl;
					} else if (choice == 2) {
						lose = (rand() % 20) + 15;
						score -= lose;

						//Path 5: Falling through a trap door.
						cout << "You lose " << lose << " points for a score of " << score << " points." <<endl
							<< "\nYou walk towards the window and fall through a trap door." <<endl
							<< "There's no way for you to escape." <<endl;
					} else if (choice == 3) {
						lose = (rand() % 20) + 15;
						score -= lose;

						//Path 5: Trapped in room.
						cout << "You lose " << lose << " points for a score of " << score << " points." <<endl
							<< "\nYou go through the door, but the door shuts behind you." <<endl
							<< "There's no way for you to escape." <<endl;
					} else {
						//Invalid choice.
						cout << "That is not a valid choice." <<endl;

						return 1;
					}
				} else if (choice == 2) {
					gain = (rand() % 10) + 1;
					score += gain;

					//Path 4: Red or blue door.
					cout << "You gain " << gain << " points for a score of " << score << " points." <<endl
						<< "\nYou see a red door and a blue door. Do you:" <<endl
						<< "(1) Open the red door." <<endl
						<< "(2) Open the blue door." <<endl;

					cin >> choice;

					if (choice == 1) {
						gain = (rand() % 20) + 15;
						score += gain;

						//Path 5: Rare candy.
						cout << "You gain " << gain << " points for a score of " << score << " points." <<endl
							<< "\nYou find a lot of rare candy." <<endl
							<< "You bring the candy back home to eat." <<endl;
					} else if (choice == 2) {
						gain = (rand() % 100) + 50;
						score += gain;

						//Path 5: Sacred candy gem.
						cout << "You gain " << gain << " points for a score of " << score << " points." <<endl
							<< "\nYou find the sacred candy gem!" <<endl;
					} else {
						//Invalid choice
						cout << "That is not a valid choice." <<endl;

						return 1;
					}
				}
			} else if (choice == 2) {
				gain = (rand() % 10) + 1;
				score += gain;

				//Path 3: Riddle.
				cout << "You gain " << gain << " points for a score of " << score << " points." <<endl
					<< "\nYou ask the old man where you can find the sacred candy gem." <<endl
					<< "Turns out the old man is a wizard and gives you a riddle." <<endl
					<< "If you answer correctly then he can summon the gem for you." <<endl
					<< "There will be consquences if you don't." <<endl
					<< "The riddle is:\n" <<endl
					<< "I can fly but I am not a bird," <<endl
					<< "I am colorful but I am not a rainbow," <<endl
					<< "I am beautiful and social but I am not a person." <<endl
					<< "What am I?\n" <<endl
					<< "You answer:" <<endl
					<< "(1) A butterfly." <<endl
					<< "(2) A dragon." <<endl;

				cin >> choice;

				if (choice == 1) {
					gain = (rand() % 100) + 50;
					score += gain;

					//Path 4: Sacred candy gem.
					cout << "You gain " << gain << " points for a score of " << score << " points." <<endl
						<< "\nYou got the answer right!" <<endl
						<< "The wizard summoned the sacred candy gem for you." <<endl;
				} else if (choice = 2) {
					lose = (rand() % 20) + 15;
					score -= lose;

					//Path 4: Getting vaporized.
					cout <<	"You lose " << lose << " points for a score of " << score << " points." <<endl
						<< "\nYou got the wrong answer" <<endl
						<< "The wizard vaporized you." <<endl;
				} else {
					//Invalid choice.
					cout << "That is not a valid choice." <<endl;

					return 1;
				}
			} else if (choice == 3) {
				lose = (rand() % 20) + 15;
				score -= lose;

				//Path 3: Getting caught.
				cout << "You lose " << lose << " points for a score of " << score << " points." <<endl
					<< "\nThe old man caught you." <<endl
					<< "Turns out he's a wizard and he vaporized you." <<endl;
			} else {
				//Invalid choice.
				cout << "That is not a valid choice." <<endl;

				return 1;
			}
		} else if (choice == 2) {
			gain = (rand() % 10) + 1;
			score += gain;

			//Path 2: Rundown house.
			cout << "You gain " << gain << " points for a score of " << score << " points." <<endl
				<< "\nYou see a rundown house. Do you:" <<endl
				<< "(1) Enter the house." <<endl
				<< "(2) Walk past the house." <<endl;

			cin >> choice;

			if (choice == 1) {
				gain = (rand() % 10) + 1;
				score += gain;

				//Path 3: Red door or blue door.
				cout << "You gain " << gain << " points for a score of " << score << " points." <<endl
					<< "\nYou see a red door and a blue door. Do you:" <<endl
					<< "(1) Open the red door." <<endl
					<< "(2) Open the blue door." <<endl;

				cin >> choice;	

				if (choice == 1) {
					gain = (rand() % 20) + 15;
					score += gain;

					//Path 4: Rare candy.
					cout << "You gain " << gain << " points for a score of " << score << " points." <<endl
						<< "\nYou find a lot of rare candy." <<endl
						<< "You bring the candy back home to eat." <<endl;
				} else if (choice == 2) {
					gain = (rand() % 100) + 50;
					score += gain;

					//Path 4: Sacred candy gem.
					cout << "You gain " << gain << " points for a score of " << score << " points." <<endl
						<< "\nYou find the sacred candy gem!" <<endl;
				} else {
					//Invalid choice.
					cout << "That is not a valid choice." <<endl;

					return 1;
				}		
			} else if (choice == 2) {
				lose = (rand() % 20) + 15;
				score -= lose;

				//Path 3: Candy woods.
				cout << "You lose " << lose << " points for a score of " << score << " points." <<endl
					<< "\nYou stumbled into the candy woods." <<endl
					<< "A gummy bear chases you out of Candy Land." <<endl;
			} else {
				//Invalid choice.
				cout << "That is not a valid choice." <<endl;

				return 1;
			}
		} else {
			//Invalid choice.
			cout << "That is not a valid choice." <<endl;

			return 1;
		}

		//The end.
		cout << "\nThe end! Your final score is " << score << " point(s)." <<endl;

		//Play again?
		cout << "\nDo you want to play again? (1-yes, 2-no) " <<endl;

		cin >> choice;

		if (choice == 1) {
			correct = true;
		} else if (choice == 2) {
			return 1;
		} else {
			cout << "Error: invalid input." <<endl;
			return 1;
		}
	
		cout <<endl;
	} while (done == 0);

	return 0;
} 
