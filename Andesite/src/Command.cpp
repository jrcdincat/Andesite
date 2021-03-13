#include "pch.h"
#include "Command.h"

void JumpCommand::execute(Player player)
{
	std::cout << "Jump" << std::endl;
	// actor.jump();
}

void MoveLeftCommand::execute(Player player)
{
	std::cout << "Move Left" << std::endl;
	// actor.left();
}

void MoveRightCommand::execute(Player player)
{
	std::cout << "Move Right" << std::endl;
	// actor.right();
}


void BiteCommand::execute(Player actor)
{
	std::cout << "Bite" << std::endl;
	// actor.bite();
}