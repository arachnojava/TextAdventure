


#include "Building.h"


Building::Building()
{
	createRooms();
}



void Building::createRooms()
{
	// 00 Parking Lot
	rooms[0].setName("Parking Lot");
	rooms[0].setDescription("The parking lot is the point of your arrival and your departure.");
	rooms[0].setExit(0, 1, "The front door of the building");

	// 01 Lobby
	rooms[1].setName("Lobby");
	rooms[1].setDescription("You're standing in the lobby at the front of the building.");
	rooms[1].setExit(0, 2, "Double doors to the front desk");
	rooms[1].setExit(2, 18, "Elevator to the second floor");
	rooms[1].setExit(4, 0, "Exit to the parking lot");
	rooms[1].setExit(5, 18, "Stairs to the second floor");

	// 02 Front Desk
	rooms[2].setName("Front Desk");
	rooms[2].setDescription("You're hanging out at the front desk.");
	rooms[2].setExit(2, 8, "Into the library");
	rooms[2].setExit(3, 9, "To the hallway near the restrooms");
	rooms[2].setExit(4, 1, "To the front lobby");
	rooms[2].setExit(6, 3, "Toward some classrooms");

	// 03 Hallway 1A
	rooms[3].setName("Hallway (1A)");
	rooms[3].setDescription("You're in a plain-looking hallway in the middle of four classrooms.");
	rooms[3].setExit(1, 5, "Room 1.2 (109?)");
	rooms[3].setExit(2, 2, "Back to the front desk");
	rooms[3].setExit(3, 7, "Room 1.4");
	rooms[3].setExit(5, 6, "Room 1.3");
	rooms[3].setExit(7, 4, "Room 1.1");

	// 04 Room 1.1
	rooms[4].setName("Room 1.1");
	rooms[4].setDescription("You are in a classroom full of junk an deactivated robots.");
	rooms[4].setExit(3, 3, "Back to the hallway");

	// 05 Room 1.2
	rooms[5].setName("Room 1.2");
	rooms[5].setDescription("You are in a large classroom with nice, new furniture.");
	rooms[5].setExit(5, 3, "Back to the hallway");

	// 06 Room 1.3
	rooms[6].setName("Room 1.3");
	rooms[6].setDescription("You're in a pretty ordinary classroom.");
	rooms[6].setExit(1, 3, "Back to the hallway");

	// 07 Room 1.4
	rooms[7].setName("Room 1.4");
	rooms[7].setDescription("You're in a typical, run-of-the-mill classroom.");
	rooms[7].setExit(7, 3, "Back to the hallway");

	// 08 Library
	rooms[8].setName("Library");
	rooms[8].setDescription("You're in the school library.");
	rooms[8].setExit(6, 2, "Back to the front desk");

	// 09 Hallway 1B
	rooms[9].setName("Hallway (1B)");
	rooms[9].setDescription("You're in the hallway near the restrooms.");
	rooms[9].setExit(2, 12, "Continue north down the hallway");
	rooms[9].setExit(3, 11, "Enter the men's restroom");
	rooms[9].setExit(5, 10, "Enter the women's restroom");
	rooms[9].setExit(7, 2, "Back to the front desk");

	// 10 Women's Restroom
	rooms[10].setName("First Floor Women's Restroom");
	rooms[10].setDescription("You're in the women's restroom.");
	rooms[10].setExit(1, 9, "Back out to the hallway");

	// 11 Men's Restroom
	rooms[11].setName("First Floor Men's Restroom");
	rooms[11].setDescription("You're in the men's restroom.");
	rooms[11].setExit(7, 9, "Back out to the hallway");

	// 12 Hallway 1C
	rooms[12].setName("Hallway (1C)");
	rooms[12].setDescription("You're in the hallway outside of the Instructors' Office.");
	rooms[12].setExit(0, 14, "To the student lounge");
	rooms[12].setExit(4, 13, "Enter the Instructors' Office");
	rooms[12].setExit(6, 9, "Continue south down the hallway");

	// 13 Instructors Office
	rooms[13].setName("Instructors' Office");
	rooms[13].setDescription("You're in the Instructors' Office.");
	rooms[13].setExit(0, 12, "Back out to the hallway");

	// 14 Student Lounge
	rooms[14].setName("Student Lounge");
	rooms[14].setDescription("You're in the Student Lounge.");
	rooms[14].setExit(3, 15, "Enter the Dean's Office");
	rooms[14].setExit(4, 12, "Go back down the hall");
	rooms[14].setExit(5, 16, "Room 1.5");
	rooms[14].setExit(6, 17, "Room 1.6");

	// 15 Dean's Office
	rooms[15].setName("Dean's Office");
	rooms[15].setDescription("The dean's office!  This had better be important!");
	rooms[15].setExit(7, 14, "Back to the Student Lounge");

	// 16 Room 1.5
	rooms[16].setName("Room 1.5");
	rooms[16].setDescription("A spacious, clean classroom with an assortment of chairs.");
	rooms[16].setExit(1, 14, "Back to the Student Lounge");

	// 17 Room 1.6
	rooms[17].setName("Room 1.6");
	rooms[17].setDescription("A classroom loaded with computer parts.");
	rooms[17].setExit(2, 14, "Back to the Student Lounge");

	// 18 Hallway 2A
	rooms[18].setName("Hallway (2A)");
	rooms[18].setDescription("You're at an intersection between the stairs, the elevator, and three hallways.");
	rooms[18].setExit(0, 19, "Toward the Admissions Office");
	rooms[18].setExit(2, 1, "Elevator to the first floor");
	rooms[18].setExit(3, 26, "Toward the Computer Lab");
	rooms[18].setExit(5, 1, "Stairs to the first floor");
	rooms[18].setExit(6, 25, "Toward the President's Office");

	// 19 Hallway 2B
	rooms[19].setName("Hallway (2B)");
	rooms[19].setDescription("You're in the hallway outside the Admissions Office.");
	rooms[19].setExit(2, 20, "Enter the Admissions Office");
	rooms[19].setExit(4, 18, "Toward the stairs and elevator");
	rooms[19].setExit(6, 21, "Toward some classrooms");

	// 20 Admissions Office
	rooms[20].setName("Admissions Office");
	rooms[20].setDescription("You're in the Admissions Office.");
	rooms[20].setExit(6, 19, "Back out to the hallway");

	// 21 Hallway 2C
	rooms[21].setName("Hallway (2C)");
	rooms[21].setDescription("You're in a hallway near the second floor classrooms.");
	rooms[21].setExit(0, 22, "Room 207");
	rooms[21].setExit(2, 19, "Toward the Admissions Office");
	rooms[21].setExit(4, 25, "Toward the administrative offices");
	rooms[21].setExit(6, 23, "Room 209");

	// 22 Room 207
	rooms[22].setName("Room 207");
	rooms[22].setDescription("You're in a unique-looking classroom.");
	rooms[22].setExit(4, 21, "Back to the hallway");

	// 23 Room 209
	rooms[23].setName("Room 209");
	rooms[23].setDescription("You're in the school's largest classroom.");
	rooms[23].setExit(2, 21, "Back to the hallway");

	// 24 President's Office
	rooms[24].setName("President's Office");
	rooms[24].setDescription("You're in the president's office.");
	rooms[24].setExit(1, 25, "Back to the hallway");

	// 25 Hallway 2D
	rooms[25].setName("Hallway (2D)");
	rooms[25].setDescription("You're in a hallway near the administrative offices.");
	rooms[25].setExit(0, 21, "Toward the classrooms");
	rooms[25].setExit(5, 24, "President's Office");
	rooms[25].setExit(2, 18, "Toward the stairs and elevator");

	// 26 Hallway 2E
	rooms[26].setName("Hallway (2E)");
	rooms[26].setDescription("You're in a hallway near the computer lab.");
	rooms[26].setExit(0, 27, "Kitchen");
	rooms[26].setExit(2, 30, "Computer Lab");
	rooms[26].setExit(4, 18, "Toward the stairs and elevator");
	rooms[26].setExit(3, 29, "Enter the women's restroom");
	rooms[26].setExit(5, 28, "Enter the men's restroom");

	// 27 Kitchen
	rooms[27].setName("Kitchen");
	rooms[27].setDescription("You're in the kitchen.  What a priviledge!");
	rooms[27].setExit(4, 26, "Back out to the hallway");

	// 28 Men's Restroom 2
	rooms[28].setName("Second Floor Men's Restroom");
	rooms[28].setDescription("You're in the men's restroom.");
	rooms[28].setExit(1, 26, "Back out to the hallway");

	// 29 Women's Restroom 2
	rooms[29].setName("Second Floor Women's Restroom");
	rooms[29].setDescription("You're in the women's restroom.");
	rooms[29].setExit(7, 26, "Back out to the hallway");

	// 30 Computer Lab
	rooms[30].setName("Computer Lab");
	rooms[30].setDescription("You're in the computer lab.");
	rooms[30].setExit(6, 26, "Back out to the hallway");



}


Room Building::getRoom(int roomNum)
{
	return rooms[roomNum];
}

