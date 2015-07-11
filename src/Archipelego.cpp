//============================================================================
// Name        : Archipelego.cpp
// Author      : Sam Gonshaw
// Version     :
// Copyright   : 
// Description : Hello World in C, Ansi-style
//============================================================================

#include "Archipelego.h"
#include "GameScreen.h"



int main(void)
{
		GameScreen* gs = new GameScreen(DEFAULT_HEIGHT,DEFAULT_WIDTH,std::time(0));
		std::cout << "Done!";
}
