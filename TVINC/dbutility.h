/*################################################<
>>> *Authors: Nathaniel Nation                  <<<
>>>                                             <<<
>>> Lecture/Tutor: Mr. David White              <<<
***************************************************/

					//**** Utility Header ****//
#include <cstring>

//fuction that select a policy type and return it
int Poloption( void );

//fuction that control string input without numbers at a given location on screen
string STinGinput( int x, int y, int strlenght);

//fuction that control string inputs, any charactor and numbers at a given location on screen
string STinGinput2( int x, int y, int strlenght);

//fuction that controls inputs to be integers only at a given location on screen and return it
int Intinput( int x, int y, int Maxstrlenght);

//fuction that controls inputs to be double only at a given location on screen and return it
double Doubleinput( int x, int y, int Maxstrlenght);

//fuction that controls inputs to be long only at a given location on screen and return it
long Longinput( int x, int y, int Maxstrlenght);

//fuction that assigns yes/no at a given location on screen and return it
string YesNo( int x, int y);

//fuction that create a display theme
void ThemeStyle1( void );

//fuction that convert string data to char
char *convertStringToChar(const string &str);

//fuction that display help
void helpFile(void);

//fuction that shows the credit
void Credit(void);

//fuction that tells about the software
void AboutUs(void);

///fuction that display a startup screen
void Startup( void );

//fuction that display a shutdown screen
void Shutdown( void );

//function Dtime
void DTime(int x, int y);

//function TTime
void TTime(int x, int y);

//function navigation 
void naviHelp( void );
