#include "app.h"


int main(){
//write recieve programm here

	INIT_Prog();
	u8 data;
	while(1)
	{
		data = app_void_recieve();
		app_void_display(data);	
	}

	return 0;
}


