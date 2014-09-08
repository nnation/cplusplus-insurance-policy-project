/*################################################<
>>> *Authors: Nathaniel Nation                  <<<
>>>                                             <<<
>>> Lecture/Tutor: Mr. David White              <<<
***************************************************/


		//**** Menu Implementation File ****//

#include "Menu.h"
#include <windows.h>
#include "dbutility.h"
#include <conio.h>


//function prototypes
void Menustyle(void);
void OptHelp(int opt);

//initialize the default constructor
Menu::Menu()
{
		opt = 0;
   	optdetail = " ";
}//end initialization

//initialize the primary constructor
Menu::Menu(int op, string opd)
{
		opt = op;
   	optdetail = opd;
}//end initialization

//destroy Menu method
Menu::~Menu() {}

//begin excution of getopt method
int Menu::getopt() const {
	return opt;
}//end method

//begin excution of getoptdetail method
string Menu::getoptdetail() const {
	return optdetail;
}//end method


//begin excution of Popumenu method
int Menu::Popumenu(Menu *menu[5])
{
   int cnt;    //declare count
   int choice = 0;  //declare choice
   int response;    //declare response

   clrscr(); //clear screen

   system("color 90");

   //while the count is less than or equal to 5 do the following
   for (cnt = 0; cnt <= 5; cnt++){
      //do a switch on cnt
      switch (cnt) {

   		case 0:       //if case 0 create a new object of Menu and assign it to the menu pointer
         	menu[cnt] = new Menu(1, ". Add a Policy    ");
         	break;
   		case 1:      //if case 1 create a new object of Menu and assign it to the menu pointer
         	menu[cnt] = new Menu(2, ". Delete a Policy ");
         	break;
   		case 2:     //if case 2 create a new object of Menu and assign it to the menu pointer
         	menu[cnt] = new Menu(3, ". Edit a Policy   ");
         	break;

   		case 3:    //if case 3 create a new object of Menu and assign it to the menu pointer
         	menu[cnt] = new Menu(4, ". View a Policy   ");
         	break;

   		case 4:    //if case 4 create a new object of Menu and assign it to the menu pointer
         	menu[cnt] = new Menu(5, ". Exit            ");
         	break;
      }//end switch

   }//end for

   //set color

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 159 );
   DTime(1,24); //show date at location
   TTime(67, 24); //show time at location
   Menustyle();   //display menu style or look

   //header
   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 46 );
   gotoxy(10, 2); cout<<"\\______/\\__/| True Value Insurance Company Ltd |\\__/\\______/";
   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 159 );
   /***
    The following will create the display for the menu
    This also includes the display and color
	***/
   gotoxy( 25, 5); cout<<"Main Menu: ";
   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 46 );
	gotoxy( 25, 7); cout<<"-->1. Add a Policy    ";
   gotoxy( 47,13); cout<<(choice + 1);
   OptHelp(choice);

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 159 );
	gotoxy( 25, 8); cout<<"2. Delete a Policy";
	gotoxy( 25, 9); cout<<"3. Edit a Policy";
	gotoxy( 25,10); cout<<"4. View a Policy";
	gotoxy( 25,11); cout<<"5. Exit";

   gotoxy( 25,13); cout<<"Please enter option: ";
/**********************************************************************/

	//get user response
   response = getch();

   int y_axis = 7;  //declare and set y_axis to 7

   //while responce is not equal to ENTER KEY
   while ( response != 0x0d) {

   	//navigate up if the up or left arrow key is pressed
      if (response == 0x48 || response == 0x4b ) {

         choice--;  //decrement choice

         y_axis--;  //decrement y_axis
         //test if the y_axis is equal to 6
      	if (y_axis == 6) {      //if true
            y_axis = 11;   //set y_axis to 11
            choice = 4;    //set choice to 4
            //reset and display previous option
            SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 159 ); gotoxy( 25, 7); cout<<menu[0]->getopt()<<menu[0]->getoptdetail()<<"   ";
            //set and diplay current option
      		SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 46 ); gotoxy( 25, y_axis); cout<<"-->"<<menu[choice]->getopt()<<menu[choice]->getoptdetail();
         }//end if

         else {
         	//reset and display previous option
         	SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 159 ); gotoxy( 25, y_axis + 1); cout<<menu[choice + 1]->getopt()<<menu[choice + 1]->getoptdetail()<<"   ";
            //set and display current option
         	SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 46 ); gotoxy( 25, y_axis); cout<<"-->"<<menu[choice]->getopt()<<menu[choice]->getoptdetail();
         }//end else

         OptHelp(choice); // call function to give details on choice help
		}//endif

     	//navigate down if the down or right arrow key is pressed
      if (response == 0x50 || response == 0x4d ) {
         choice++;   //increment choice

         y_axis++;   //increment y_axis
         //test if y_axis is equal to 12
      	if (y_axis == 12) {
            y_axis = 7;  //initialize y_axis to 7
            choice = 0;  //initialize choice to 0
            //reset and display previous option
            SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 159 ); gotoxy( 25, 11); cout<<menu[4]->getopt()<<menu[4]->getoptdetail()<<"   ";
            //set and display current option
      		SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 46 ); gotoxy( 25, y_axis); cout<<"-->"<<menu[choice]->getopt()<<menu[choice]->getoptdetail();
         }//end if
         else {
             //reset and display previous option
         	SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 159 ); gotoxy( 25, y_axis - 1); cout<<menu[choice - 1]->getopt()<<menu[choice - 1]->getoptdetail()<<"   ";
            //set and display current option
         	SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 46 ); gotoxy( 25, y_axis); cout<<"-->"<<menu[choice]->getopt()<<menu[choice]->getoptdetail();
         }//end else

         OptHelp(choice);   //call function to give ditails on choice help

      }//endif

      //if the user press f1 return 6 to call the help function
      if ( response == 0x3b)  {
         SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 15 );
      	return 6;
      }//endif

      //if the user press f2 return 7 to call the About us function
      if ( response == 0x3c)  {
         SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 15 );
      	return 7;
      }//endif

      //if the user press f3 call the credits function
      if ( response == 0x3d)  {
         SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 15 );
			return 8;
      }//endif

      //goto location and display option
      gotoxy( 47,13); cout<<(choice + 1);

      response = getch(); //get another response
   }//end while

   //while count is less than 5
   for (cnt = 0; cnt < 5; cnt++) {
      delete menu[cnt];  //delete the menu
   }//end for

   //set text color
   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 15 );

   clrscr();  //clear the screen

   //return choice
   return (choice + 1);
}


//begin to execute function Menustyle
void Menustyle()
{

   //while y_axis is less that or equal to 11 create a is design
   for (int y_axis = 7; y_axis <= 11; y_axis++) {
   	gotoxy(24, y_axis); cout<<"\307";     gotoxy(48, y_axis); cout<<"\266";
   }//end for

   int x_axis;  //declare a x_axis

   //while cnt is less that or equal to 3 create a is design
   for (int cnt = 1; cnt <= 3; cnt++) {

   	//test if count is equal to 1
   	if (cnt == 1) {
         //while x_axis is less that or equal to 48 create a is design
      	for (x_axis = 24; x_axis <= 48 ; x_axis++) {
             gotoxy(x_axis, 4); cout<<"\315";
         }//end inner for

      }// end if

      //esle test if count is equal to 2
      else if (cnt == 2) {
         //while x_axis is less that or equal to 48 create a is design
      	for (x_axis = 24; x_axis <= 48 ; x_axis++) {
             gotoxy(x_axis, 6); cout<<"\315";
         }// end inner for

      }// end else if

      else {
         //while x_axis is less that or equal to 48 create a is design
      	for (x_axis = 24; x_axis <= 48 ; x_axis++) {
             gotoxy(x_axis, 12); cout<<"\315";
         }//end inner for

      }//end else

   }//end outer for

   gotoxy(24, 4);  cout<<"\311";   gotoxy(48, 4);  cout<<"\273";     //
   gotoxy(24, 5);  cout<<"\272";   gotoxy(48, 5);  cout<<"\272";     //
   gotoxy(24, 6);  cout<<"\314";   gotoxy(48, 6);  cout<<"\271";     /////Create design
   gotoxy(24, 12); cout<<"\310";   gotoxy(48, 12);  cout<<"\274";    //
                                                                     //

   gotoxy(21, 6);  cout<<"\332\304\304";   gotoxy(49, 6);  cout<<"\304\304\277"; // Create design

   //while y_axis is less that or equal to 14 create a is design
   for (int y_axis = 7; y_axis <= 14; y_axis++) {

      gotoxy(21, y_axis);  cout<<"\263";    //
      gotoxy(51, y_axis);  cout<<"\263";    //create display

   }//end for

   //while x_axis is less that or equal to 67 create a is design
   for (x_axis = 8; x_axis <= 67; x_axis++) {

   	gotoxy(x_axis, 15); cout<<"\315";    //
      gotoxy(x_axis, 19); cout<<"\315";    ////create display
      gotoxy(x_axis, 21); cout<<"\315";    //

   }//end for

   //while y_axis is less that or equal to 21 create a is design
   for (int y_axis = 15; y_axis <= 21; y_axis++) {

      gotoxy(7, y_axis);  cout<<"\272";   //
      gotoxy(68, y_axis);  cout<<"\272";  //create display

   }//end for

   gotoxy(21, 15); cout<<"\317";   gotoxy(51, 15);  cout<<"\317"; //
   gotoxy(7, 15);  cout<<"\311";   gotoxy(68, 15);  cout<<"\273"; // create design

   gotoxy(7, 19);  cout<<"\314";   gotoxy(68, 19);  cout<<"\271";   //
   gotoxy(24, 19); cout<<"\313";   gotoxy(49, 19); cout<<"\313";    //
   gotoxy(24, 20);  cout<<"\272";  gotoxy(49, 20);  cout<<"\272";   /////Create design
   gotoxy(7, 21); cout<<"\310";    gotoxy(68, 21);  cout<<"\274";   //
   gotoxy(24, 21); cout<<"\312";    gotoxy(49, 21);  cout<<"\312";  //

   gotoxy(8, 20); cout<<"F1: HELP \235";         //
   gotoxy(25, 20); cout<<"F2: ABOUT US \350";    //// Go to location and display
   gotoxy(50, 20); cout<<"F3: CREDITS \222";     //

}//end function Menustyle



/*Begin excution of OptHelp*/
void OptHelp(int opt)
{
   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 158 );

	switch ( opt ) {   /*do a switch on the option on that user is on
                        and tell them what the option gives*/

   	case 0:    //if case 0 go to location and display

      	gotoxy(8,16); cout<<"This option grant users the ability to \"ADD\"                ";
         gotoxy(8,17); cout<<"a policy to the system whether if it's a Home               ";
         gotoxy(8,18); cout<<", Life or a Motor Vehicle insurance policy.                 ";
      	break;

   	case 1:    //if case 1 go to location and display

      	gotoxy(8,16); cout<<"From this option you can \"DELETE\" a policy from             ";
         gotoxy(8,17); cout<<"the system whether if it's a Home, Life, or a               ";
         gotoxy(8,18); cout<<"Motor Vehicle insurance policy.                             ";
      	break;

   	case 2:    //if case 2 go to location and display

      	gotoxy(8,16); cout<<"This option however gives the user the ability              ";
         gotoxy(8,17); cout<<"to veiw and \"EDIT\" any of the policy whether                ";
         gotoxy(8,18); cout<<",if it's a Home, Life or Motor Vehicle insurance policy.    ";
      	break;

   	case 3:    //if case 3 go to location and display

      	gotoxy(8,16); cout<<"Here you can simply \"VEIW\" an insurance policy              ";
         gotoxy(8,17); cout<<"whether if it's a Home, Life or Motor Vehicle policy.       ";
         gotoxy(8,18); cout<<"                                                            ";
      	break;

   	case 4:    //if case 4 go to location and display

      	gotoxy(8,16); cout<<"                                                            ";
         gotoxy(8,17); cout<<"Close/shutdown the programme!                               ";
         gotoxy(8,18); cout<<"                                                            ";
      	break;

   }//end switch

}//end function OptHelp
