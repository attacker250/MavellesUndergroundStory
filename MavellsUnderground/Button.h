#pragma once
#include "Entity.h"


class Button: public Entity
{
	public:
		Button();
        void interact();
		bool active = false;
};

