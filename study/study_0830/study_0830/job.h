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
		char job1[10] = "Àü»ç";
		char job2[10] = "µµÀû";
		char job3[10] = "¸¶¹ı»ç";
		char name1[16] = "Ãá½ÄÀÌ";
		char name2[16] = "´öÃáÀÌ";
		char name3[16] = "¼øºÀÀÌ";
	};
	

	
	status* player1;
	status* player2;
	status* player3;
	Yourjob yourjob;
 





};

