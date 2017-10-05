#include "stdio.h"
#include <cstdlib>

#include "GameActor.h"
#include "Monster.h"

char* Monster::getName()
{
    char *name;

    sprintf(name, "Monster %d", idNumber);

    return name;
}


void Monster::setIDNumber(int idn)
{
    idNumber = idn;
}


int Monster::chooseMove()
{
    int action = rand() % 100;
    int move;

    if (action >= 0 && action < 45)
        move = Monster::ATTACKING;
    else if (action >= 45 && action < 90)
        move = Monster::WAITING;
    else
        move = Monster::HEALING;

    return move;
}

