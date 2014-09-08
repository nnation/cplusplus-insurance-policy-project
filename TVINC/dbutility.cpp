/*################################################<
>>> *Authors: Nathaniel Nation                  <<<
>>>                                             <<<
>>> Lecture/Tutor: Mr. David White              <<<
***************************************************/

     //**** Utility Implimentation File****//

#include "dbutility.h"         //
#include <iostream>            //
#include <iomanip>             //
#include <conio.h>             //
#include <cstring>             ///// Include headers/preprocessors
#include <stdlib.h>            //
#include <windows.h>           //
#include <fstream>             //
#include <time.h>              //


//begin excution of function Poloption
int Poloption( )
{
	int opt; //declare variable to get option
   int key;  // declare variable to hold temp input from user
   int x = 22; // x-axis

   ThemeStyle1( ); // create the theme

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 46 );
   //goto location and display the header
   gotoxy( 30, 2);     cout<<"] Insurance Policy [";

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 159 );

   gotoxy(12, 9);   //goto location and display options
   cout<<"1. Home: [ ]\t  "<<"2. Life: [ ]\t "<<"3. Motor Vehicle: [ ]";

                           //navigation help//
   //////////////////////////////////////////////////////////////////////
   gotoxy(1, 23); cout<<"\314";                                        //
   for (int x_axis = 2; x_axis <= 37; x_axis++) {                      //
   	gotoxy(x_axis,23); cout<<"\315";                                 //
   }                                                                   //
                                                                       //
   gotoxy(38,23); cout<<"\273";                                        //
   gotoxy(2, 24); cout<<"Navigate Using: ->1<<2>>3<-->[ENTER]";        //
   gotoxy(38,24); cout<<"\272";                                        //
   gotoxy(38,25); cout<<"\312";                                        //
   //////////////////////////////////////////////////////////////////////

   gotoxy(x,9);
   cout<<"x";
   opt = 1;    

   //goto location and display exit method
   gotoxy( 34, 13);  cout<<"EXIT -->Esc";

   key = getch();

   while (key != 0xd){

      if (key == 49){

      	if ( x == 37 ){
         gotoxy(x,9);
      	cout<<" ";
         }

         if ( x == 61){
         gotoxy(x,9);
      	cout<<" ";
         }

         x = 22;
   		gotoxy(x,9);
      	cout<<"x";
      	opt = 1;
      }

      if (key == 50){

      	if ( x == 22 ){
         gotoxy(x,9);
      	cout<<" ";
         }

         if ( x == 61){
         gotoxy(x,9);
      	cout<<" ";
         }

         x = 37;
   		gotoxy(x,9);
      	cout<<"x";
      	opt = 2;
      }

      if (key == 51){

      	if ( x == 22 ){
         gotoxy(22,9);
      	cout<<" ";
         }

         if ( x == 37){
         gotoxy(x,9);
      	cout<<" ";
         }

         x = 61;
   		gotoxy(x,9);
      	cout<<"x";
      	opt = 3;
      }

      if (key == 0x1B) {
         opt = 0;
      	break;
      }

      key = getch();
   }

   return opt;
}


string STinGinput( int x, int y, int Maxstrlenght)
{
	int stringlength = Maxstrlenght, cnt, gt;
   char name[50] = {NULL}, temp[50] = {NULL}, res;
   string strReturn;

   gotoxy(x,y);
   res = (char)getch();
   cnt =0;
   gt = x;
   while (res != '\r'){

      if ((res >= 97 && res <= 122) || (res >= 65 && res <= 95) || res == '\b'){

   		if (cnt < stringlength && res != '\b' && !(res == 57) ){

         	gotoxy(gt,y);
      		cout<<res;
         	temp[0] = res;
         	strcat(name,temp);
         	cnt++;
         	gt++;
      	}

      	if (res == '\b'){
         	if ((gt - 1) != 1 && cnt != 0){
         		gt--;
         		gotoxy(gt,y);
      			cout<<" ";
         		gotoxy(gt - 1,y);
         		name[cnt - 1] = '\0';
         		cnt--;
         	}
      	}
      }
      res = (char)getch();
   }

   strReturn = name;

   return strReturn;
}
string STinGinput2( int x, int y, int Maxstrlenght){

	int stringlength = Maxstrlenght, cnt, gt;
   char name[50] = {NULL}, temp[50] = {NULL}, res;
   string strReturn;

   gotoxy(x,y);
   res = (char)getch();
   cnt =0;
   gt = x;
   while (res != '\r'){

   		if (cnt < stringlength && res != '\b' && !(res == 57) ){

         	gotoxy(gt,y);
      		cout<<res;
         	temp[0] = res;
         	strcat(name,temp);
         	cnt++;
         	gt++;
      	}

      	if (res == '\b'){
         	if ((gt - 1) != 1 && cnt != 0){
         		gt--;
         		gotoxy(gt,y);
      			cout<<" ";
         		gotoxy(gt - 1,y);
         		name[cnt - 1] = '\0';
         		cnt--;
         	}
      	}
      res = (char)getch();
   }

   strReturn = name;

   return strReturn;

}
string YesNo( int x, int y) {

	string answer;
   int res;

   gotoxy( x, y);
   cout<<"x";
   answer = "Yes";

   res = getch();

   while (res != 0xd) {

      if (res == 0x4b || res == 0x48 ) {
         gotoxy(x + 6, y);
         cout<<" ";

      	answer = "Yes";
         gotoxy(x, y);
         cout<<"x";
      }

      if (res == 0x4d || res == 0x50 ) {
         gotoxy(x, y);
         cout<<" ";

         answer = "No";
         gotoxy(x + 6, y);
         cout<<"x";
      }

      res = getch();
   }

	return answer;
}


int Intinput( int x, int y, int Maxstrlenght)
{
	int stringlength = Maxstrlenght, cnt, gt;
   string inputStr, temp;
   char res;
   const char *inputPtr;
   int InReturn;

   gotoxy(x,y);
   res = (char)getch();
   cnt =0;
   gt = x;
   while (res != '\r'){

      if ((res >= 48 && res <= 57) || res == '\b'){

   		if (cnt < stringlength && res != '\b' ){

         	gotoxy(gt,y);
      		cout<<res;
         	temp = res;
         	inputStr.append(temp);
         	cnt++;
         	gt++;
      	}

      	if (res == '\b') {
         	if ((gt - 1) != 1 && cnt != 0){
         		gt--;
         		gotoxy(gt,y);
      			cout<<" ";
         		gotoxy(gt - 1,y);
         		inputStr.insert((cnt + 1) - 1, '\0');
         		cnt--;
         	}
      	}
      }
      res = (char)getch();
   }

   inputPtr = inputStr.c_str( );   //convert string to char*
   InReturn = atoi(inputPtr);      //convert char* to int
   return InReturn;
}


double Doubleinput( int x, int y, int Maxstrlenght)
{
	int stringlength = Maxstrlenght, cnt, gt;
   string inputStr, temp;
   char res;
   const char * inputPtr;
   double DubReturn;

   gotoxy(x,y);
   res = (char)getch();
   cnt =0;
   gt = x;
   while (res != '\r'){

      if ((res >= 48 && res <= 57) || res == 46 || res == '\b'){

   		if (cnt < stringlength && res != '\b'){

         	gotoxy(gt,y);
      		cout<<res;
         	temp = res;
         	inputStr.append(temp);
         	cnt++;
         	gt++;
      	}

      	if (res == '\b'){
         	if ((gt - 1) != 1 && cnt != 0){
         		gt--;
         		gotoxy(gt,y);
      			cout<<" ";
         		gotoxy(gt - 1,y);
         		inputStr.insert((cnt + 1) - 1, '\0');
         		cnt--;
         	}
      	}
      }
      res = (char)getch();
   }

   inputPtr = inputStr.c_str( );   //convert string to char*
   DubReturn = atof(inputPtr);     //convert char* to double
   return DubReturn;
}


long Longinput( int x, int y, int Maxstrlenght)
{
	int stringlength = Maxstrlenght, cnt, gt;
   string inputStr, temp;
   char res;
   const char * inputPtr;
   double LonReturn;

   gotoxy(x,y);
   res = (char)getch();
   cnt =0;
   gt = x;
   while (res != '\r'){

      if ((res >= 48 && res <= 57) || res == '\b'){

   		if (cnt < stringlength && res != '\b'){

         	gotoxy(gt,y);
      		cout<<res;
         	temp = res;
         	inputStr.append(temp);
         	cnt++;
         	gt++;
      	}

      	if (res == '\b'){
         	if ((gt - 1) != 1 && cnt != 0){
         		gt--;
         		gotoxy(gt,y);
      			cout<<" ";
         		gotoxy(gt - 1,y);
         		inputStr.insert((cnt + 1) - 1, '\0');
         		cnt--;
         	}
      	}
      }
      res = (char)getch();
   }

   inputPtr = inputStr.c_str( );  //convert string to char*
   LonReturn = atol(inputPtr);    //convert char* to long
   return LonReturn;
}


//begin excution of function ThemeStyle
void ThemeStyle1( ) {

   int cnt; //declare count variable

	clrscr();  //clear screen

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 159 );

   for (cnt = 0; cnt < 80; cnt++){
   	cout<<"\315";
   }//end for

   gotoxy(1,1); cout<<"\311";
   gotoxy(80,1); cout<<"\273";

   for (cnt = 1; cnt < 25; cnt++){
      gotoxy(1, cnt + 1);
   	cout<<"\272";

      gotoxy(80, cnt + 1);
   	cout<<"\272";
   }//end for

   gotoxy(1, 25);
   for (cnt = 0; cnt < 80; cnt++){
   	cout<<"\315";
   }//end for

   gotoxy(1,25);  cout<<"\310";
   gotoxy(80,25); cout<<"\274";

   gotoxy(1, 3); cout<<"\314";
   for (cnt = 0; cnt < 79; cnt++){
   	cout<<"\315";
   }//end for
   gotoxy(80, 3); cout<<"\271";
   gotoxy(2, 2);
   for (cnt = 0; cnt < 78; cnt++){
   	cout<<"\262";
   }//end for

								//Date display in style//
   //////////////////////////////////////////////////////////////////////
   DTime( 66, 4); //show Today's date at location                      //
                                                                       //
   gotoxy(65, 3); cout<<"\313";                                        //
   gotoxy(65, 4); cout<<"\272";                                        //
   gotoxy(65, 5); cout<<"\310";                                        //
   gotoxy(80, 5); cout<<"\271";                                        //
                                                                       //
   for (int x_axis = 66; x_axis <= 79; x_axis++ ) {                    //
   	gotoxy(x_axis, 5); cout<<"\315";                                 //
   }                                                                   //
   //////////////////////////////////////////////////////////////////////


}//end function ThemeStyle1


char *convertStringToChar(const string &str)
{
	char *retPtr(new char[str.length() + 1]);

	strcpy(retPtr, str.c_str());

	return retPtr;
}



//Credit function
void Credit(void)
{
	clrscr(); //clear the screen

	gotoxy(18,  9); cout<<"|*************| Credit |*****************|";
	gotoxy(18, 10); cout<<" |                                      |";
	gotoxy(18, 11); cout<<" |    Nathaniel N. Nation               |";
	gotoxy(18, 12); cout<<" |    Kevin Johnson             9811279 |";
	gotoxy(18, 13); cout<<" |                                      |";
	gotoxy(18, 14); cout<<" |   Tutor: Mr. David W. White          |";
	gotoxy(18, 15); cout<<"|****************************************|";

	getch();
} //end function Credit
//About function
void AboutUs(void)
{
   clrscr(); //clear the screen

   gotoxy(4,  9);cout<<"|****************************| About Us |********************************|";
	gotoxy(4, 10);cout<<" |                                                                      |";
	gotoxy(4, 11);cout<<" |      True Value Insurance Company Limited version 1.0                |";
	gotoxy(4, 12);cout<<" |        [Build 20] for Windows(r)XP,Windows(r)Vista.                  |";
	gotoxy(4, 13);cout<<" |             Copyright(c)2009.Alrights reserved.                      |";
	gotoxy(4, 14);cout<<" |      This system inclusive of its functions, ease of use             |";
	gotoxy(4, 15);cout<<" |and delightful menus are sole property of True Value Management Team. |";
	gotoxy(4, 16);cout<<" |                                                                      |";
	gotoxy(4, 17);cout<<"|************************************************************************|";

   getch();
}// end function About Us
//Help File function
void helpFile(void)
{
	clrscr(); //clear the screen
   
	gotoxy(7,1);cout << "*******************************************************************";
	gotoxy(7,2);cout << " * *                                                           * *";
	gotoxy(7,3);cout << " * Welcome to the True Value Insurance Company Limited Help file * ";
	gotoxy(7,4);cout << " * *                                                           * *";
	gotoxy(7,5);cout << "******************************************************************* ";

	gotoxy(14,7);cout<< "-                 Instructions                -";

	gotoxy(1, 9);cout<< " + The Basics                                  ";
	gotoxy(1, 10);cout<< " -Start the Program by Clicking on the TRUE VALUE COMPANY Icon ";

	gotoxy(1, 12);cout<< " -Select the Insurance Policy type by pressing the ENTER KEY  ";

	gotoxy(1,14);cout<< " - The System presents the user with a display menu to do the following:   ";
	gotoxy(1,15);cout<<"  1. Add a Policy ";
	gotoxy(1,16);cout<<"When this option is selected,The system prompts the user to enter the type of";
	gotoxy(1,17);cout<<"insurance Policy to add.";
	gotoxy(1,18);cout<<"After the relevant information is added the system prompts user to to either";
	gotoxy(1,19);cout<<"save or discard the information.";

	gotoxy(1,21);cout<<"  2. Delete a Policy ";
	gotoxy(1,22);cout<<"When this option is selected, The system prompts the user to enter the";
	gotoxy(1,23);cout<<"Policy number of the file to be deleted.";
	gotoxy(1,24);cout<<"The requested information is then retrieved from the data file. ";
	gotoxy(1,25);cout<<"User is then asked to confirm whether to delete the Insurance Policy Record";
	gotoxy(1,26);cout<<"from file.";
	gotoxy(1,27);cout<<"If confirmation is recieved the file is then removed else system exits and";
	gotoxy(1,28);cout<<"returns to main menu.";

   gotoxy(1,30);cout<<"  3. Edit a Policy ";
	gotoxy(1,31);cout<<"When this option is selected, The system prompts the user to enter the Policy";
	gotoxy(1,32);cout<<"number of the file to be edited. ";
	gotoxy(1,33);cout<<"The requested information is then retrieved from the data file. ";
	gotoxy(1,34);cout<<"The system then allows for the editing of the infomation then asks for";
	gotoxy(1,35);cout<<"confirmation to save changes. ";
	gotoxy(1,36);cout<<"If confirmation is recieved the changes will then be saved, if not system exits";
	gotoxy(1,37);cout<<"and returns to main menu. ";

	gotoxy(1,39);cout<<"  4. View a Policy ";
	gotoxy(1,40);cout<<"When this option is selected, The system prompts the user to enter the Policy";
	gotoxy(1,41);cout<<"number of the file to be viewed.";
	gotoxy(1,42);cout<<"The requested information is then retrieved from the data file and is displayed";
	gotoxy(1,43);cout<<"on the screen. ";

   getch();
}//End function help
//begin excution of function startup
void Startup( )
{
   /*
   	This function creates a display for starting up the software
   */

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 15 );

	gotoxy(10,  9);cout<<"      True Value Insurance Company Limited version 1.0       ";
	gotoxy(10, 10);cout<<"        [Build 20] for Windows(r)XP,Windows(r)Vista.         ";
	gotoxy(10, 11);cout<<"             Copyright(c)2009.Alrights reserved.             ";

   for (int x_axis = 14; x_axis <= 65; x_axis++) {
       gotoxy(x_axis, 13);  cout<<"\304";
       gotoxy(x_axis, 15);  cout<<"\304";

   }

	gotoxy(13, 13);  cout<<"\332";       gotoxy(66, 13);  cout<<"\277";
   gotoxy(13, 14);  cout<<"\263";       gotoxy(66, 14);  cout<<"\263";
   gotoxy(13, 15);  cout<<"\300";       gotoxy(66, 15);  cout<<"\331";
   for (int load = 14; load <= 65; load++) {
   	Sleep(100);
      gotoxy(load , 14); cout<<"\333";
      //gotoxy(load , 14); cout<<"\262";
   }//end for

}//end function start up
//begin excution of function shutdown
void Shutdown( )
{
   /*
   	This function creates a display for shuting down the software
   */

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 8 );

	gotoxy(10,  9);cout<<"      True Value Insurance Company Limited version 1.0       ";
	gotoxy(10, 10);cout<<"        [Build 20] for Windows(r)XP,Windows(r)Vista.         ";
	gotoxy(10, 11);cout<<"             Copyright(c)2009.Alrights reserved.             ";
	gotoxy(10, 12);cout<<"                       Shuting down....                      ";

   for (int x_axis = 14; x_axis <= 65; x_axis++) {
       gotoxy(x_axis, 13);  cout<<"\304";
       gotoxy(x_axis, 15);  cout<<"\304";
   }//end for

	gotoxy(13, 13);  cout<<"\332";       gotoxy(66, 13);  cout<<"\277";
   gotoxy(13, 14);  cout<<"\263";       gotoxy(66, 14);  cout<<"\263";
   gotoxy(13, 15);  cout<<"\300";       gotoxy(66, 15);  cout<<"\331";
   for (int load = 14; load <= 65; load++) {
      gotoxy(load , 14); cout<<"\333";
   }//end for

   for (int load = 65; load >= 14; load--) {
      Sleep(100);
      gotoxy(load , 14); cout<<" ";
   }//end for
}//end function shutdown
//begin function Dtime
void DTime(int x, int y)
{
  char datebuf[9];  // declare an array of char to store value for date

  _strdate(datebuf);
  gotoxy(x, y); cout<<"Date: "<<datebuf; //display date

}//end function Dtime
//begin function TTime
void TTime(int x, int y)
{
  char timebuf[9];  //declare an array of char to store values for time

  _strtime(timebuf);
  gotoxy( x, y); cout<<"Time: "<<timebuf; //display time

}//end function TTime

void naviHelp( ) {

                           //navigation help//
   //////////////////////////////////////////////////////////////////////
   gotoxy(1, 23); cout<<"\314";                                        //
   for (int x_axis = 2; x_axis <= 42; x_axis++) {                      //
   	gotoxy(x_axis,23); cout<<"\315";                                 //
   }                                                                   //
                                                                       //
   gotoxy(43,23); cout<<"\273";                                        //
   gotoxy(2, 24); cout<<"Navigate Using: ->>ARROW KEYS<<-->[ENTER]";   //
   gotoxy(43,24); cout<<"\272";                                        //
   gotoxy(43,25); cout<<"\312";                                        //
   //////////////////////////////////////////////////////////////////////
}
