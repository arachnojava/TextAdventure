#include <cstring>



/********************************************************************
 */
class RoomExit
{
public:
	RoomExit()
	{
		room = -1;
		description = new char[80];
	}

	int room;
	char *description;
};




/********************************************************************
 */
class Room
{

public:

	static const int NUM_EXITS = 8;


	/****************************************************************
	 * Sets the name of this room.
	 */
	void setName(char *n)
	{
		name = new char[80];
		strcpy(name, n);
	}


	/****************************************************************
	 * Sets the description of this room.
	 */
	void setDescription(char *d)
	{
		description = new char[80];
		strcpy(description, d);
	}


	/****************************************************************
	 * Returns the name of this room.
	 */
	char* getName()
	{
		return name;
	}


	/****************************************************************
	 * Returns the description of this room.
	 */
	char* getDescription()
	{
		return description;
	}


	/*******************************************************************
	 * Creates an exit from this room.
	 */
	void setExit(int exitNum, int roomNum, char* exitDesc)
	{
		exits[exitNum].room = roomNum;
		strcpy(exits[exitNum].description, exitDesc);
	}


	/*******************************************************************
	 * Returns the room number to which an exit leads.
	 */
	int getExitRoom(int exitNum)
	{
		return exits[exitNum].room;
	}


	/*******************************************************************
	 * Returns a description of an exit.
	 */
	char *getExitDescription(int exitNum)
	{
		return exits[exitNum].description;
	}


private:

	char *name;
	char *description;
	RoomExit exits[NUM_EXITS];
};



/********************************************************************
 */
class Building
{

public:
	static const int NUM_ROOMS = 31;
	Building();
	Room getRoom(int roomNum);


private:
	void createRooms();
	Room rooms[NUM_ROOMS];


};




/*
First Floor Rooms:
00 Parking Lot
01 Lobby
02 Front Desk
03 Hallway 1A
04 Room 1.1
05 Room 1.2
06 Room 1.3
07 Room 1.4
08 Library
09 Hallway 1B
10 Women's Restroom 1
11 Men's Restroom 1
12 Hallway 1C
13 Instructors' Office
14 Student Lounge
15 Dean's Office
16 Room 1.5
17 Room 1.6

Second Floor Rooms:
18 Hallway 2A
19 Hallway 2B
20 Admissions Office
21 Hallway 2C
22 Room 2.1
23 Room 2.2
24 President's Office
25 Hallway 2D
26 Hallway 2E
27 Kitchen
28 Men's Restroom 2
29 Women's Restroom 2
30 Computer Lab

*/
