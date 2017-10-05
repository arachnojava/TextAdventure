#include "GameActor.h"

class Monster : public GameActor
{
public:
    virtual char* getName();
    void setIDNumber(int idn);
    virtual int chooseMove();

    static const int WAITING = 0;
    static const int ATTACKING = 1;
    static const int HEALING = 2;

private:
    int idNumber;

};

