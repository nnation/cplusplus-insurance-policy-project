/*################################################<
>>> *Authors: Nathaniel Nation                  <<<
>>>                                             <<<
>>> Lecture/Tutor: Mr. David White              <<<
***************************************************/

					//**** Menu Header ****//

#ifndef MENU_H
#define MENU_H

#include <cstring>         //
#include <iostream>        //include directives/preprocessor
//create a class for the menu
class Menu{
   private:
		int opt;       //declare an attribute for the option number
   	string optdetail;  //declare an attribute for the option details

   public:
      Menu();         //default constructor
      Menu(int op, string opd);   //primary constructor
      ~Menu();                    //destructor

      int getopt() const;               //
      string getoptdetail() const;      //  Method prototypes
      int Popumenu(Menu **);            //

}; //close the class

#endif