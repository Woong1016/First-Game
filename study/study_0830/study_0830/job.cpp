#include "job.h"





void job::SetCharacter()
{
	player1 = new status();
	player2 = new status();
	player3 = new status();

	player1->set( 150, 50, 20, 30, 20, 10);
	player2->set( 120, 80, 35, 15, 30, 5);
	player3->set( 70, 130, 60, 10, 15, 30);




	return ;
}




void job::PickCharacter()
{
	player1->print();
	player2->print();
	player3->print();

}
