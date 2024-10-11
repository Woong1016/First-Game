#pragma once
#include "Singleton.h"

class Amgona : public Singleton<Amgona>
{
public:

    int num;
    int PlusOne(int input) { return ++input; }

};

