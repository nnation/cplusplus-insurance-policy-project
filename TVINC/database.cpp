/*################################################<
>>> *Authors: Nathaniel Nation                  <<<
>>>                                             <<<
>>> Lecture/Tutor: Mr. David White              <<<
***************************************************/

					//**** Main Driver ****//

#include "Insurpolicy.h"            //
#include "Lifeinsurpolicy.h"        //
#include "Homeinsurpolicy.h"        //
#include "MVinsurpolicy.h"          //  Include all
#include "Menu.h"                   //
#include "dbutility.h"              //    preprocessors
#include <windows.h>                //
                                    //
#include <iostream>                 //
#include <fstream>                  //
#include <conio.h>                  //

//using namespace std;


//Begin excution of function main
int main()
{
	Menu *menuPtr[5];   //declare an array of pointer of class type Menu
   Menu menu;          //declare an object of the class type Menu

   Insurpolicy *Bpolicy;  //declare a pointer to the base class

   Homeinsurpolicy HCpolicy;         //declare an object of the class type Homeinsurpolicy
   Homeinsurpolicy blankHCpolicy;    //declare an object of the class type Homeinsurpolicy for initializing objects of its type to blank
   fstream HomeFile ("HomeFile.txt", ios::in | ios::out | ios::binary);   //create a file for storing home insurance

   Lifeinsurpolicy LCpolicy;        //declare an object of the class type Lifeinsurpolicy
   Lifeinsurpolicy blankLCpolicy;   //declare an object of the class type Lifeinsurpolicy for initializing objects of its type to blank
   fstream LifeFile("LifeFile.txt", ios::in | ios::out | ios::binary);    //create a file for storing life insurance

   MVinsurpolicy   MVCpolicy;       //declare an object of the class type MVinsurpolicy
   MVinsurpolicy   blankMVCpolicy;  //declare an object of the class type MVinsurpolicy for initializing objects of its type to blank
   fstream MVFile ("MVFile.txt", ios::in | ios::out | ios::binary);  //create a file for storing motor vehicle insurance

   int Option;  //Menu selection/option
   int Polopt;  //policy selection/option

   Startup( );  //call a function to display boot up screen

   //exit program if fstream cannot open file
   if (!HomeFile)
   {
   	cerr << "HomeFile File could not be opened."<<endl;  //display error
      exit (1);
   }// end if

   //exit program if fstream cannot open file
   if (!LifeFile)
   {
   	cerr << "LifeFile File could not be opened."<<endl;  //display error
      exit (1);
   }// end if

   //exit program if fstream cannot open file
   if (!MVFile)
   {
   	cerr << "MVFile File could not be opened."<<endl;  //display error
      exit (1);
   }//end if

   system("title True Value Insurance Company Ltd.");  //programme title

   Option = menu.Popumenu(menuPtr);   //call function to get user option

   //while the option is not 5, do the following
   while (Option != 5) {

      //do a case on the option
   	switch (Option) {

      	case 1:           //Add policy

               // call a function to get the policy option that the user wants and set it to Polopt
               Polopt = Poloption();
               //do a case on the Polopt
               switch(Polopt) {
						case 1:                               //if 1 add home policy
                     HCpolicy.AddHomeDisplayScreen( );  //Create display screen
                     HCpolicy.addPolicy(HomeFile);      //call object method to add policy and send the home file to it
                     HCpolicy = blankHCpolicy;          //then initialize the object to be blank
                  	break;

						case 2:                              //if 2 add life policy
                     LCpolicy.AddLifeDisplayScreen( ); //Create display screen
                     LCpolicy.addPolicy(LifeFile);     //call object method to add policy and send the life file to it
                     LCpolicy = blankLCpolicy;         //then initialize the object to be blank
                  	break;

						case 3:                             //if 3 add motor vehicle policy
                     MVCpolicy.AddMotovDisplayScreen( ); //Create display screen
                     MVCpolicy.addPolicy(MVFile);        //call object method to add policy and send the motor vehicle file to it
                     MVCpolicy = blankMVCpolicy;         //then initialize the object to be blank
                  	break;

               }// end switch

         	break;

      	case 2: 				//Delete policy

         		// call a function to get the policy option that the user wants and set it to Polopt
               Polopt = Poloption();
               //do a case on the Polopt
               switch(Polopt) {
						case 1:                            //if 1 delete home policy
                  	HCpolicy.DeleteHome(HomeFile);  //call object method to delete policy and send the home file to it
                     HCpolicy = blankHCpolicy;       //then initialize the object to be blank
                  	break;

						case 2:                           //if 2 delete life policy
                     LCpolicy.DeleteLife(LifeFile); //call object method to delete policy and send the life file to it
                     LCpolicy = blankLCpolicy;      //then initialize the object to be blank
                  	break;

						case 3:                           //if 3 delete a motor vehicle policy
                     MVCpolicy.DeleteMotov(MVFile); //call object method to delete policy and send the motor vehicle file to it
                     MVCpolicy = blankMVCpolicy;    //then initialize the object to be blank
                  	break;

               }// end switch

         	break;

      	case 3: 				//Edit policy

         		// call a function to get the policy option that the user wants and set it to Polopt
               Polopt = Poloption();
               //do a case on the Polopt
               switch(Polopt) {
						case 1:                             //if 1 edit home policy
                     HCpolicy.EditPolicy( HomeFile ); //call object method to edit policy and send the home file to it
                  	break;

						case 2:                             //if 2 edit life policy
                     LCpolicy.EditPolicy( LifeFile ); //call object method to edit policy and send the life file to it
                  	break;

						case 3:                            //if 3 edit motor vehicle policy
                  	MVCpolicy.EditPolicy( MVFile ); //call object method to edit policy and send the motor vehicle file to it
                  	break;

               }// end switch

         	break;

      	case 4:           //View policy

         		// call a function to get the policy option that the user wants and set it to Polopt
               Polopt = Poloption();
               //do a case on the Polopt
               switch(Polopt) {

						case 1:                         //if 1 view home policy

                  	Bpolicy = &HCpolicy;         //point the base class to the child class home

                     /*call the view method inside the child object to get policy to view
                       if it return a zero then dont enter the if statment
                     */
                     if ( HCpolicy.ViewHome(HomeFile) != 0 ){
                                                        //if not equal to 0
                        ThemeStyle1( );     //create screen theme
                  		Bpolicy->Insurpolicy::Display( ); //display the base class data
                  		Bpolicy->Display( );              //display the child class data
                     }//end if
                     gotoxy( 25, 22); system("PAUSE");
                  	break;

						case 2:                        //if 2 view life policy
                  	Bpolicy = &LCpolicy;        //point the base class to the child class life

                     /*call the view method inside the child object to get policy to view
                       if it return a zero then dont enter the if statment
                     */
                     if ( LCpolicy.ViewLife(LifeFile) != 0 ){
                                                     //if not equal to 0
                        ThemeStyle1( );             //create screen theme
                  		Bpolicy->Insurpolicy::Display( );  //display the base class data
                  		Bpolicy->Display( );               //display the child class data
                     }//end if
                     gotoxy( 25, 22); system("PAUSE");
                  	break;

						case 3:                     //if 3 view motor vehicle policy

                  	Bpolicy = &MVCpolicy;    //point the base class to the child class motor vehicle

                     /*call the view method inside the child object to get policy to view
                       if it return a zero then dont enter the if statment
                     */
                     if ( MVCpolicy.ViewMotov(MVFile) != 0 ){
                                                //if not equal to 0
                        ThemeStyle1( );        //create screen theme
                  		Bpolicy->Insurpolicy::Display( );   //display the base class data
                  		Bpolicy->Display( );                //display the child class data
                     } //end if
                     gotoxy( 25, 24); system("PAUSE");
                  	break;

               }// end switch

         	break;

         case 6:
         	helpFile();  //function calls the help
         	break;

         case 7:
            AboutUs();  //function tell about the program
         	break;

         case 8:
            Credit();  //function gives credit to the programmers
         	break;

         default :
         	cout<<"\a\a\a";  //sound the system alarm to notify wrong input

      }//end switch

      Option = menu.Popumenu(menuPtr);  //call function to get user option

   }//end while

   Shutdown( );  //display a shutdown screen
   
   return 0;  //the function has run successfully

}//end function main
