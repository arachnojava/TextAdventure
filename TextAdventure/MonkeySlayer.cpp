
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>

#include "Building.h"
#include "Player.h"

// Symbolic constants
#define INV_CANNON         0
#define INV_PUMPKIN        1
#define INV_HARPOON        2

#define NUM_OBJECTIVES     4
#define OBJ_FOUND_CANNON   0
#define OBJ_FOUND_SHAMU    1
#define OBJ_DEFEATED_SHAMU 2
#define OBJ_ESCAPED        3


// Function prototypes
void showTitle();
void showMenu();
void showCompass();
char getInput();
void processInput();
void look();
void walk();
void pickUp();
void attack();
void listInventory();
void listObjectives();
int countCompletedObjectives();

// Variable declarations
int inventory[3];  // Cannon, PMDs, harpoons
int objectives[NUM_OBJECTIVES]; // Found cannon, found Shamu, defeated Shamu, escaped.
int enemyPresent = 10;
Player player;
Building building;




void showTitle()
{
  cout << "======================================================================\n";
  cout << "     __    __      ________  ___   ___  ___   ___   ________  __    ___\n";
  cout << "    /__|  /__|    /_______/ /__|  /__/ /__/ _/__/  /_______/ /__/  /__/\n";
  cout << "   /___|_/___|   /__/ /__/ /___| /__/ /__/_/__/   /__/__    /__/__/__/\n";
  cout << "  /__________|  /__/ /__/ /____|/__/ /______/    /_____/   /________/\n";
  cout << " /__/ |_/ |__| /__/_/__/ /__/|____/ /__/ \\__\\   /__/____     /__/\n";
  cout << "/__/  |/  |__|/_______/ /__/ |___/ /__/   \\__\\ /_______/    /__/\n";
  cout << "\n";
  cout << " ______    _           ________    _     _    _______    ______     _ \n";
  cout << "|  ____|  | |         |  ____  |  | |   | |  |  _____|  | ___  |   | |\n";
  cout << "| |       | |         | |    | |  | |   | |  | |        | |  | |   | |\n";
  cout << "| |       | |         | |    | |  | |   | |  | |        | |  | |   | |\n";
  cout << "| |____   | |         | |____| |  | |___| |  | |___     | |__| |   | |\n";
  cout << "|____  |  | |         |  ____  |  |__   __|  |  ___|    |  _   /   | |\n";
  cout << "     | |  | |         | |    | |     | |     | |        | | \\ \\    | |\n";
  cout << "     | |  | |         | |    | |     | |     | |        | |  \\ \\   |_|\n";
  cout << " ____| |  | |______   | |    | |     | |     | |_____   | |   \\ \\   _ \n";
  cout << "|______|  |________|  |_|    |_|     |_|     |_______|  |_|    \\_\\ |_|\n\n";
  cout << "======================================================================\n\n";
  cout << "Monkey Slayer              No monkeys, biological or corporate, were  \n";
  cout << "v1.0 Beta                  harmed in the making of this game.         \n";
  cout << "By Michael Henson                                                     \n\n";
  cout << "Your school has been taken over by a black-hearted creature known as  \n";
  cout << "Shamu the Portly Monkey.  Secretly working for a competing institution,\n";
  cout << "he and his band of Portly Underlings (PUs) seek to destroy the school \n";
  cout << "by implementing ridiculous policies and illogical degree requirements.\n";
  cout << "You, brave player, are the only one who cares enough to stop them.     \n\n";
  cout << "======================================================================" << endl;


}

void showMenu()
{
	cout << "\n----------\n ACTIONS:\n----------\n";
	cout << " 1.  Look   \t 4.  Inventory\n";
	cout << " 2.  Walk   \t 5.  Objectives\n";
	cout << " 3.  Attack \t Q.  Quit \n";
}


void showPlayerInfo()
{
    cout << " Player Health:  " << player.getHealth() << endl;
    cout << " Completed " << countCompletedObjectives();
    cout << " out of " << NUM_OBJECTIVES << " objectives.\n";
}

char getInput()
{
	char input;

	cout << "\nEnter an option:  ";
	cin >> input;

	return input;
}


void processInput(char input)
{
	switch(input)
	{
		case '1':  look();
			       break;
		case '2':  walk();
			       break;
		case '3':  attack();
			       break;
		case '4':  listInventory();
			       break;
		case '5':  listObjectives();
			       break;
		default:  cout << "What are you talking about?  '" << input << "' is not an option!\nPay attention!\n";
			      break;
	}
}

void buildInterface()
{
    cout << "\n======================================================================\n";
    cout << building.getRoom(player.getCurrentRoom()).getName() << "\n\n";
    showPlayerInfo();

}


void look()
{
	system("cls");
    cout << "----------------------------------------------------------------------\n";
	cout << "LOOK:\n\n";
    cout << "Location:  " << building.getRoom(player.getCurrentRoom()).getName() << "\n\n";
	cout << building.getRoom(player.getCurrentRoom()).getDescription();

	cout << "\n\n";
}


void walk()
{
	int dir = 9;

	cout << "----------------------------------------------------------------------\n";
	cout << "WALK:\n\n";

	showCompass();

	for (int i = 0; i < Room::NUM_EXITS; i++)
	{
		if (building.getRoom(player.getCurrentRoom()).getExitRoom(i) != -1)
		{
			cout << i << ".  ";
			cout << building.getRoom(player.getCurrentRoom()).getExitDescription(i);
			cout << endl;
		}
	}

	cout << "9.  Stay here.";
	cout << endl;

	cout << "\nWalk where?  ";
	cin >> dir;

	if (dir == 9) return;

	// TODO:  Make sure the player can't leave the building until 
    //        Shamu is defeated!
    if (dir >= 0 && dir <= 8 && building.getRoom(player.getCurrentRoom()).getExitRoom(dir) != -1)
		player.setCurrentRoom(building.getRoom(player.getCurrentRoom()).getExitRoom(dir));
	else
		cout << "You can't go that way!\n\n";

	//cout << "\n\n";
	system("cls");
}


int countCompletedObjectives()
{
    int count = 0;

    for (int i = 0; i < NUM_OBJECTIVES; i++)
    {
        if (objectives[i])
            count++;
    }

    return count;
}

void listObjectives()
{
    cout << "\n----------------------------------------------------------------------\n";
	cout << "OBJECTIVES:\n\n";
    
    if (objectives[OBJ_FOUND_CANNON])
        cout << "  COMPLETE:  You have found the Pumpkin Cannon.\n";
    else
        cout << "INCOMPLETE:  You must find the Pumpkin Cannon.\n";

    if (objectives[OBJ_FOUND_SHAMU])
        cout << "  COMPLETE:  You have already run into Shamu.\n";
    else
        cout << "INCOMPLETE:  You must find Shamu.\n";

    if (objectives[OBJ_DEFEATED_SHAMU])
        cout << "  COMPLETE:  You have defeated Shamu.\n";
    else
        cout << "INCOMPLETE:  You must defeat Shamu.\n";

    cout << "INCOMPLETE:  You must escape the building after defeating Shamu.\n";
    cout << "----------------------------------------------------------------------\n";

    cout << endl;

}

void attack()
{
	if (enemyPresent > 0)
	{
		int attackValue = rand() % 100;
		if (attackValue > 50)
		{
			cout << "You defeated a PU.\n";
			enemyPresent--;

			int itemDropped = rand() % 3;
			if (itemDropped == INV_CANNON)
			{
				if (inventory[INV_CANNON] != 1)
				{
					inventory[INV_CANNON] = 1;
					cout << "You got the pumpkin cannon!";
					objectives[INV_CANNON] = 1;
				}
				else 
					itemDropped = INV_PUMPKIN;
			}
			
			
			if (itemDropped == INV_PUMPKIN)
			{
    			inventory[INV_PUMPKIN]++;
				cout << "You got a Pumpkin of Mass Destruction.";
			}
			else if (itemDropped == INV_HARPOON)
			{
    			inventory[INV_HARPOON]++;
				cout << "You got a harpoon.";
			}
			

		}
		else
		{
			cout << "You attack the PU and miss!\n";
		}
	}
	else
	{
	    cout << "----------------------------------------------------------------------\n";
	    cout << "Unable to stand it any longer, you throw a small object at the\n";
	    cout << "instructor.  It does 0 points of damage, but you feel better anyway.\n";
	    cout << "\n\n";
	}
}

void listInventory()
{
	cout << "INVENTORY:\n\n";
	if (inventory[INV_CANNON] == 1)	cout << "Pumpkin Cannon\n";
	cout << inventory[INV_PUMPKIN] << " Pumpkins of Mass Destruction\n";
	cout << inventory[INV_HARPOON] << " Harpoons\n";
}


void showCompass()
{
	cout << "Directions:";

	cout << endl << "\t-----\n\t";
		
	if (building.getRoom(player.getCurrentRoom()).getExitRoom(1) != -1)
		cout << "1 ";
	else 
		cout << "  ";

	if (building.getRoom(player.getCurrentRoom()).getExitRoom(2) != -1)
		cout << "2 ";
	else 
		cout << "  ";

	if (building.getRoom(player.getCurrentRoom()).getExitRoom(3) != -1)
		cout << "3 ";
	else 
		cout << "  ";

	cout << endl << "\t";

	if (building.getRoom(player.getCurrentRoom()).getExitRoom(0) != -1)
		cout << "0 ";
	else 
		cout << "  ";

	cout << "* ";

	if (building.getRoom(player.getCurrentRoom()).getExitRoom(4) != -1)
		cout << "4 ";
	else 
		cout << "  ";

	cout << endl << "\t";

	if (building.getRoom(player.getCurrentRoom()).getExitRoom(7) != -1)
		cout << "7 ";
	else 
		cout << "  ";

	if (building.getRoom(player.getCurrentRoom()).getExitRoom(6) != -1)
		cout << "6 ";
	else 
		cout << "  ";

	if (building.getRoom(player.getCurrentRoom()).getExitRoom(5) != -1)
		cout << "5 ";
	else 
		cout << "  ";

	cout << "\n\t-----" << endl;


}


void main()
{
	int done = 0;
	char input;

	player.setCurrentRoom(1);

	showTitle();

	while (done == 0)
	{
		buildInterface();

        // Show menu
		showMenu();

		// Get input
		input = getInput();	

		if (input == 'Q' || input == 'q')
		{
			// Prompt for confirmation
			char reallyQuit = 'n';
			cout << "Are you sure you want to quit? (y/n)  ";
			cin >> reallyQuit;

			// If the user really wants to quit, then we're done.
			if (reallyQuit == 'y' || reallyQuit == 'Y')
				done = 1;
		}
		else
		{
			// Process input
			processInput(input);
		}
	}

}


