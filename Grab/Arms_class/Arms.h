/* Define a class object for the arms.



*/

class Arms
{
public:
	Arms(int ID, int foldPos);//, int openPos, int grabPos);
	~Arms();
	// series of functions needed; bool only to return if all is OK
	bool fold();
	// bool open();
	// bool grab();


private: 
	int _ID;			// ID of dynamixel servo
	int _foldPos;		// position for folding arms 
	int _openPos;		// position for opening (to set in Dynamixel.moveSpeed(ID,pos,speed))		
	int _grabPos;		// *
	int _speed;			// set the dynamixel speed 0-1023
}; 