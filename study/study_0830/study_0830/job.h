#pragma once
#
#include "status.h"
class job : public status

{
public:
	void SetCharacter();
	void PickCharacter();

	


private:
	struct Yourjob
	{
		char job1[10] = "����";
		char job2[10] = "����";
		char job3[10] = "������";
		char name1[16] = "�����";
		char name2[16] = "������";
		char name3[16] = "������";
	};
	

	
	status* player1;
	status* player2;
	status* player3;
	Yourjob yourjob;
 





};

