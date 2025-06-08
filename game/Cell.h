#pragma once
#include "Enums.h"
#include "raylib.h"


class Cell
{
private:
	int x, y;
	mapType type;
	Texture2D tex{};
	bool isCanWalk;
public:
	void use()
	{
		switch (type)
		{
		case mapType::HEAL:
			break;
		case mapType::ENEMY:
			break;
		}
		type = mapType::AIR;
		tex = "air";
	}
};