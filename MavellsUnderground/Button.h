#pragma once
#include "Entity.h"


class Button: public Entity
{
	public:
		Button();
		~Button();
        void interact();
		bool active = false;
		int id = 0;

		static int maxId;
};

