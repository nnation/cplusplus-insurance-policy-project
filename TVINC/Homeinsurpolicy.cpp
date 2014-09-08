/*################################################<
>>> *Authors: Nathaniel Nation                  <<<
>>>                                             <<<
>>> Lecture/Tutor: Mr. David White              <<<
***************************************************/

#include "Homeinsurpolicy.h"
#include "dbutility.h"
#include <iostream>
#include <iomanip>
#include <conio.h>


// Constructors/Destructors
//

Homeinsurpolicy::Homeinsurpolicy ( )
:Insurpolicy()
{
// Estimated valve of home.
	esthomeval = 0;
	// First line of address.
	firstlineadd = " ";
	// Second line of Address.
	seclineadd = " ";
	// Type of roof on the house.
	rooftype = " ";
	// Is a burgler alarm install?
	buralarm = " ";
	// Is a fire alarm installed?
	firealarm = " ";
}

Homeinsurpolicy::~Homeinsurpolicy ( ) { }

//
//  Mutator Methods
//


/**
 * Set the value of esthomeval
 * Estimated valve of home.
 * @param Hvalue the new value of esthomeval
 */
void Homeinsurpolicy::setesthomeval ( double Hvalue )	 {
		esthomeval = Hvalue;
}

/**
 * Set the value of firstlineadd
 * First line of address.
 * @param fladd the new value of firstlineadd
 */
void Homeinsurpolicy::setfirstlineadd ( string fladd )	 {
		firstlineadd = fladd;
}

/**
 * Set the value of seclineadd
 * Second line of Address.
 * @param sladd the new value of seclineadd
 */
void Homeinsurpolicy::setseclineadd ( string sladd )	 {
			seclineadd = sladd;
}

/**
 * Set the value of rooftype
 * Type of roof on the house.
 * @param rtype the new value of rooftype
 */
void Homeinsurpolicy::setrooftype ( string rtype )	 {
			rooftype = rtype;
}

/**
 * Set the value of buralarm
 * Is a burgler alarm install?
 * @param bAlarm the new value of buralarm
 */
void Homeinsurpolicy::setburalarm ( string bAlarm )	 {
			buralarm = bAlarm;
}

/**
 * Set the value of firealarm
 * Is a fire alarm installed?
 * @param fAlarm the new value of firealarm
 */
void Homeinsurpolicy::setfirealarm ( string fAlarm )	 {
			firealarm = fAlarm;
}

/**
 * Set the value of policytype
 * Store the client policy type.
 * @param poltype the new value of policytype
 */
void Homeinsurpolicy::setpolicytype( )	 {
		policytype = "Home Insurance Policy";
}

/**
 * Set the value of insurpremium
 * Store the client's premium.
 *
 */
void Homeinsurpolicy::setinsurpremium( )	 {

		insurpremium = esthomeval * 0.02;

      //if the house has a burglar alarm subtract 0.5% of the home insurance value from the premium
      if ( buralarm.compare("Yes") > 0) {

      	insurpremium = insurpremium - ( esthomeval * 0.005 );
      }

      //if the house has a firealarm subtract 0.5% of the home insurance value from the premium
      if ( firealarm.compare("Yes") > 0 ) {
      	insurpremium = insurpremium - ( esthomeval * 0.005 );
      }
}

//
//  Accessor Methods
//

/**
 * Get the value of esthomeval
 * Estimated valve of home.
 * @return the value of esthomeval
 */
double Homeinsurpolicy::getesthomeval ( ) const{
	return esthomeval;
}
/**
 * Get the value of firstlineadd
 * First line of address.
 * @return the value of firstlineadd
 */

string Homeinsurpolicy::getfirstlineadd ( ) const{
	return firstlineadd;
}

/**
 * Get the value of seclineadd
 * Second line of Address.
 * @return the value of seclineadd
 */
string Homeinsurpolicy::getseclineadd ( ) const{
		return seclineadd;
}

/**
 * Get the value of rooftype
 * Type of roof on the house.
 * @return the value of rooftype
 */
string Homeinsurpolicy::getrooftype ( ) const{
		return rooftype;
}

/**
 * Get the value of buralarm
 * Is a burgler alarm install?
 * @return the value of buralarm
 */
string Homeinsurpolicy::getburalarm ( ) const{
		return buralarm;
}

/**
 * Get the value of firealarm
 * Is a fire alarm installed?
 * @return the value of firealarm
 */
string Homeinsurpolicy::getfirealarm ( ) const{
		return firealarm;
}

/**
 * Get the value of policytype
 * Store the client policy type.
 * @return the value of policytype
 */
string Homeinsurpolicy::getpolicytype( ) const{
	return policytype;
}

/**
 * Get the value of insurpremium
 * Store the client's premium.
 * @return the value of insurpremium
 */
double Homeinsurpolicy::getinsurpremium( ) const{
	return insurpremium;
}


//
//// Utility Functions
//

/**
 * Add a Home Insurance policy
 * @
 */
void Homeinsurpolicy::addPolicy(fstream &HomFile)   {

	struct STRUCHome HOME; // Declare a structure of type Home
   long polNum = 1111;	   // Declare and initalizing Policy number to the value 1111
   string fname;		   // Declare First name as string
   string lname;		   // Declare Last name as string
   Date effdate;		   // Declare object to store Effective Date 
   Date expdate;		   // Declare object to store Expiry Date
   int day, month, year;   // Declare day, month and year as integers 

	/*Home Attributes*/

	double Esthomeval;    // Estimated valve of home.
	string Firstlineadd;  // First line of address.
	string Seclineadd;    // Second line of Address.
	string Rooftype;      // Type of roof on the house.
	string Buralarm;      // Is a burgler alarm install?
	string Firealarm;     // Is a fire alarm installed?

   string res;			  // Declare variable to store user response
   long location;		  // Deaclare variable to store offset in memory to read or write

   /**
    * Populate the Base class
    */

   fstream HFile;     //Declare an object file for Home Insurance   
   HFile.open("HomeFile.txt", ios::in | ios::out | ios::binary);    //Opening the Home File Insurance in read in /out/binary

   //Set position to read from file
   HFile.seekg((polNum - 1111) * sizeof(STRUCHome));				
   //Read from location
   HFile.read(reinterpret_cast <char *> (&HOME), sizeof(STRUCHome));

   //Loop though the file to fine a missing policy number
   while (HFile && !HFile.eof()) {
      //If a match is found the increament the polynum
      if (polNum == HOME.policyNum){
      	polNum++;
      }//endif

      //read the next file
   	HFile.read(reinterpret_cast <char *> (&HOME), sizeof(STRUCHome));
   }//endwhile

   gotoxy(18, 5);			//put cursor at specified location
   cout<<polNum;			//Display Policy Number 
   location = polNum;		//Set Policy Number to location
	setpolicyNum( polNum );	//Set Policy Number in Base Class

   fname = STinGinput(30 , 6, 18);	//Gets string input from user and assigns it to fname
   setfnamepolholder( fname );		//Set Policy Holder First Name in Base class

   													
   lname = STinGinput(30 , 7, 18);	//Gets string input from user and assigns it to lname
   setlnamepolholder( lname );		//Set Policy Holder Last Name in Base class


   day = Intinput(32, 8, 2);   month = Intinput(38, 8, 2);   year = Intinput(44, 8, 4); //Get day, month and year from user
   effdate.setDay(day);        effdate.setMonth(month);      effdate.setYear(year);		//Initialize day, month and year in Effdate 
   seteffectivedate( effdate );															//Set Effective Date in Base Class

   day = Intinput(32, 9, 2);   month = Intinput(38, 9, 2);   year = Intinput(44, 9, 4); //Get day, month and year from user
   expdate.setDay(day);        expdate.setMonth(month);      expdate.setYear(year);		//Initialize day, month and year in Expdate 
   setexpirydate( expdate );															//Set Expiry Date in Base Class


   /**
    * Populate the Base child class
    */

   Firstlineadd = STinGinput2(31 , 11, 29);     //Get first line of address from user 
   setfirstlineadd ( Firstlineadd );			//Set firstlineadd in child class	

   Seclineadd = STinGinput2(31 , 12, 29);		//Get second line of address from user  
   setseclineadd ( Seclineadd );				//Set seclineadd in child class	

   Rooftype = STinGinput(31 , 13, 18);			//Get roof type from user  
   setrooftype ( Rooftype );					//Set roof type in child class	

   Buralarm = YesNo(53, 15);					//Get Burgular alarm response from user 
   setburalarm ( Buralarm );					//Set Burgular alarm response in child class	

   Firealarm = YesNo(53, 16);					//Get Fire alarm response from user
   setfirealarm ( Firealarm );					//Set Fire alarm in response child class

   Esthomeval = Doubleinput(32, 18, 16);		//Get estimated home value from user  
   setesthomeval ( Esthomeval );				//Set estimated home value child class	

   setpolicytype( );			//Set policy type in the child class  
   setinsurpremium( );			//Set insurance premium in the child class 

   gotoxy( 32, 19 );			//Go to location	
   cout<<getinsurpremium( );	//Display Insurance Premium 															

   gotoxy(15, 21);				//Go to location																	
   cout<<"\"Is This correct?: Yes[ ] No[ ]\"";	//Prompt user for response

   res = YesNo(38, 21);		//Store user response

   if (res.compare("No") == 0) {//If user response is NO 
   	AddHomeDisplayScreen( );	//Display Home Screen again	
      addPolicy(HomFile);		//Call the add policy method and send the home file to it again	
   }//end if
   else {
   	WriteToHFile(HomFile, location);	//Else write to file
   }//end else

}//end method add policy																						

/**
 * Display Screen for Home insurance policy to file
 * @
 */
void Homeinsurpolicy::AddHomeDisplayScreen( )   {	//Method to Display Home Insurance Policy

	ThemeStyle1( );		//Create program theme

   system("color 9F");	//Set program color 																
																	                     
  //Set text color
   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 46 );	 //set text color				
   gotoxy( 25, 2);     cout<<"] Add Home Insurance Policy [";		     //Displays the Header

   //Set text color
   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 159 ); //set text color
  
   /**
    * Prompt user to Populate the Base class
    */

   gotoxy(3, 5); cout<<"Policy Number: ";
   gotoxy(3, 6); cout<<"Policy Holder First Name: [                  ]";                     
   gotoxy(3, 7); cout<<"Policy Holder Last Name : [                  ]";
   gotoxy(3, 8); cout<<"Effective Date ---------: [D:    M:    Y:    ]";
   gotoxy(3, 9); cout<<"Expiry Date ------------: [D:    M:    Y:    ]";


   /**
    * Prompt user to Populate the Base child class
    */

	gotoxy(3, 11); cout<<"First Address -----------: [                             ]";
   gotoxy(3, 12); cout<<"Second Address ----------: [                             ]";
   gotoxy(3, 13); cout<<"Roof Type ---------------: [                  ]";

   gotoxy(3, 15); cout<<"Does house have a burglar alarm installed?    Yes[ ] No[ ]";
   gotoxy(3, 16); cout<<"Does house have a fire alarm installed?       Yes[ ] No[ ]";

   gotoxy(3, 18); cout<<"Estimated value of home -: [$               ]";
	gotoxy(3, 19); cout<<"The Insurance Premium is : [$               ]";        
}//End method Add Home Display Screen



/**
 * Write Home Insurance policy to file
 * @
 */
void Homeinsurpolicy::WriteToHFile(fstream &HomFile, long location) {		//Send Home and location to write data to file

   struct STRUCHome HOME;	//Declare a structure of type Home 

   //parent Data
   HOME.policyNum = getpolicyNum(  );											//Taking policy number from class and placing it in Home structrue
   strcpy(HOME.fnamepolholder, convertStringToChar(getfnamepolholder( ) ) );	//Taking policy holder first name from class and placing it in Home structrue
   strcpy(HOME.lnamepolholder, convertStringToChar(getlnamepolholder( ) ) );	//Taking policy holder last name from class and placing it in Home structrue
   HOME.effectivedate = geteffectivedate(  );									//Taking effective date from class and placing it in Home structrue
   HOME.expirydate = getexpirydate(  );											//Taking expiry date from class and placing it in Home structrue
   strcpy(HOME.policytype, convertStringToChar(getpolicytype( ) ) );			//Taking policy type name from class and placing it in Home structrue
   HOME.insurpremium = getinsurpremium( );										//Taking insurance premium from class and placing it in Home structrue

   //child Data

											
	HOME.esthomeval = getesthomeval ( );	//Taking Estimated value of home from class and placin git in Home class
	
	strcpy(HOME.firstlineadd, convertStringToChar(getfirstlineadd( ) ) );	//Taking first line of address from class and placing it in Home structrue
	
	strcpy(HOME.seclineadd, convertStringToChar(getseclineadd( ) ) );	//Taking Second line of Address and placing it in Home structrue
	
	strcpy(HOME.rooftype, convertStringToChar(getrooftype( ) ) );	//Taking roof type from class and placing it in Home structrue
	
	strcpy(HOME.buralarm, convertStringToChar(getburalarm( ) ) );	//Taking Burgular Alarm response and placing it in Home structrue
	
	strcpy(HOME.firealarm, convertStringToChar(getfirealarm( ) ) );	//Taking Fire Alarm response and placing it in Home structrue



   HomFile.close();	//Closing Home File
   HomFile.open("HomeFile.txt", ios::in | ios::out | ios::binary);//Reopening the Home File

   //Test if the file got opened
   if( !HomFile ) {
   	clrscr();
   	cout<<"\n\n\aThe HomFile pointer is not set!!!";
      getch();
   }//end if
   else {  //else File didnt open
		//move file-position pointer to the correct record in file
	   HomFile.seekp( ( location - 1111 ) * sizeof( STRUCHome ) );

	   //insert record to file
	   HomFile.write( reinterpret_cast< const char*> ( &HOME ), sizeof(STRUCHome ) );
   }//end else	

}//end method write to Home File	



/**
 * Read Home insurance policy from file
 * @
 */
void Homeinsurpolicy::ReadHFile(fstream &HomFile, long location)	//Send Home file and location to be read 		
{
	struct STRUCHome HOME;	//Declare a structure of type Home															
   string Holdstr;			//Declare a variable to temporarily hold a string

   //Test if the file got opened
   if( HomFile ) {
		//move file-position pointer to the correct record in file
	   HomFile.seekg( ( location - 1111 ) * sizeof( STRUCHome ) );

	   //insert record to file
	   HomFile.read( reinterpret_cast< char*> ( &HOME ), sizeof(STRUCHome ) );
   }//end if
   else {  //else File didnt open
   	clrscr();
   	cout<<"\n\n\aThe FilFile pointer is not set!!!";
      getch();
      return;
   }//end else

   if (HOME.policyNum == 0 ) {	//If Policy number is equal to zero then return 
      return;
   }//end if

   /*parent*/

   setpolicyNum( HOME.policyNum ) ;		//Taking Home Policy Number and setting it inside Parent class

   Holdstr = HOME.fnamepolholder;       //Assigns first name of policy holder to a temporary string
   setfnamepolholder( Holdstr );		//Passing the temporary string to  set policy holder method

   Holdstr = HOME.lnamepolholder;		//Assigns last name of policy holder to a temporary string																				
   setlnamepolholder( Holdstr );		//Passing the temporary string to  set policy holder method

   seteffectivedate( HOME.effectivedate );		//Taking Home effective date and setting it inside Parent class
   setexpirydate( HOME.expirydate );			//Taking Home expiry date and setting it inside Parent class

   setpolicytype( );			//Set policy type


   /*child*/

	
	Holdstr = HOME.firstlineadd;	//Assigns first line of address in home class to a temporary string
   setfirstlineadd( Holdstr );		//Passing the temporary string to the set first line of address method
			
	Holdstr = HOME.seclineadd;		//Assigns second line of address in home class to a temporary string
   setseclineadd( Holdstr );		//Passing the temporary string to the set second line of address method
	
	Holdstr = HOME.rooftype;		//Assigns type of roof in home class to a temporary string
   setrooftype( Holdstr );			//Passing the temporary string to the set roof type method
	
	Holdstr = HOME.buralarm;		//Assigns Burgular Alarm type in home class to a temporary string																
   setburalarm( Holdstr );			//Passing the temporary string to set burgular alarm method
	
	Holdstr = HOME.firealarm;		//Assigns Fire Alarm type in home class to a temporary string
   setfirealarm ( Holdstr );		//Passing the temporary string to Fire Alarm method

   setesthomeval ( HOME.esthomeval );	    //Passing home estimated value  to set estimated home value method
														
   setinsurpremium(  );		//Calling Insurance Premium method

}//end ReadHFile 	



/////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Delete Home insurance policy to file
 * @
 */
void Homeinsurpolicy::DeleteHome( fstream &HomFile )										
{
   struct STRUCHome HOME;		//Declare structure of type Home
   long location;				//Declare variable location
   Date effdate;				//Declare object to store Effective Date
   Date expdate;				//Declare object to store Expiry Date
   string res;					//Declare variable to store user response


	ThemeStyle1( );				//create screen theme

   system("color 9F");			//Set program color

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 46 );     //Set text color
   gotoxy( 25, 2);     cout<<"] Delete Home Insurance Policy [";			//Displays the Header
   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 159 );	//Set text color
   /**
    * Promt user to Populate the Base class
    */

   gotoxy(3, 5); cout<<"Please enter Policy Number: ";  //prompt user for policy number
   location = Longinput(31, 5, 4);				//get policy number

   //Set position to read from file
   HomFile.seekg((location - 1111) * sizeof(STRUCHome));
   //Read from location
   HomFile.read(reinterpret_cast <char *> (&HOME), sizeof(STRUCHome));

   //Test if the location is the same as the policy number
   if (location != HOME.policyNum){

     	gotoxy( 3, 6); cout<<"\aSorry! But that policy number is not in the database!!!";

  	   gotoxy( 25, 9); system("PAUSE");
      return;

   }//endif

   naviHelp( ); //display navigation help
   
   //read file from location
	ReadHFile(HomFile, location);			

   effdate = geteffectivedate(  );	  //Get Effective Date from class and assign it to the variable effdate
   expdate = getexpirydate(  );		  //Get Expiry Date from class and assign it to the variable expdate

   /**
    * Display the Base child class
    */

  //Go to location and display policy holder first name	
   gotoxy(3, 6);   cout<<"Policy Holder First Name: [                  ]";
   gotoxy(30 , 6); cout<<getfnamepolholder(  );											   

  //Go to location and display policy holder last name	
   gotoxy(3, 7);   cout<<"Policy Holder Last Name : [                  ]";
   gotoxy(30 , 7); cout<<getlnamepolholder(  );

  //Go to location and display day, month and year of policy Effective date	
   gotoxy(3, 8);   cout<<"Effective Date ---------: [D:    M:    Y:    ]";
   gotoxy(32, 8);  cout<<effdate.getDay(  );
   gotoxy(38, 8);  cout<<effdate.getMonth(  );
   gotoxy(44, 8);  cout<<effdate.getYear(  );

  //Go to location and display day, month and year of policy Expiry date	
   gotoxy(3, 9);   cout<<"Expiry Date ------------: [D:    M:    Y:    ]";
   gotoxy(32, 9);  cout<<expdate.getDay(  );
   gotoxy(38, 9);  cout<<expdate.getMonth(  );
   gotoxy(44, 9);  cout<<expdate.getYear(  );


   /**
    * Display the Base child class
    */
   //Go to location and display policy holder First Address
	gotoxy(3, 11);  cout<<"First Address -----------: [                             ]";
   gotoxy(31, 11); cout<<getfirstlineadd (  );
  //Go to location and display policy holder Second Address
   gotoxy(3, 12);  cout<<"Second Address ----------: [                             ]";
   gotoxy(31, 12); cout<<getseclineadd (  );
  //Go to location and display policy holder Roof Type
   gotoxy(3, 13);  cout<<"Roof Type ---------------: [                  ]";
   gotoxy(31, 13); cout<<getrooftype (  );
  //Go to location and display policy holder response to burgular alarm
   gotoxy(3, 15);  cout<<"Does house have a burglar alarm installed?       [    ]";
   gotoxy(53, 15); cout<<getburalarm (  );
  //Go to location and display policy holder response to fire alarm
   gotoxy(3, 16);  cout<<"Does house have a fire alarm installed?          [    ]";
   gotoxy(53, 16); cout<<getfirealarm (  );
  //Go to location and display policy holder Estimated value of home 
   gotoxy(3, 18);  cout<<"Estimated value of home -: [$               ]";
   gotoxy(32, 18); cout<<getesthomeval (  );
  //Go to location and display policy holder Insurance Premium
	gotoxy(3, 19);  cout<<"The Insurance Premium is : [$               ]";
   gotoxy(32, 19); cout<<getinsurpremium( );


   gotoxy(15, 21); //goto location   cout<<"\"If This is correct choose 'Yes' to delete: Yes[ ] No[ ]\"";  //Prompt user to confirm delete

   res = YesNo(63, 21);		//Store user response

   if (res.compare("Yes") == 0) {    //If the response is yes

   	//Copy a blank Object the life object
   	struct STRUCHome HOME;		//Declare structure of type Home                                    
      HOME.policyNum = 0;		//Initialize Policy Number from Home to  be zero

      //Overwrite the life object in the file to blank
      HomFile.seekp( (location - 1111) * sizeof(STRUCHome) );
      HomFile.write(reinterpret_cast<const char*> (&HOME), sizeof(STRUCHome) );

   }//end if

}//end method DeleteHome


////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * View a person's Home insurance policy.
 */
int Homeinsurpolicy::ViewHome( fstream &HomFile )
{
   struct STRUCHome HOME;	//Declare structure of type Home
   long location;			//Declare variable location													

	ThemeStyle1( );		//create screen theme

   system("color 9F");	//Set program color 

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 46 ); //Set text color
   gotoxy( 25, 2);     cout<<"] View Home Insurance Policy [";			//Displays the Header

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 159 ); //Set text color
   /**
    * Prompt user to Populate the Base class
    */

   gotoxy(3, 5); cout<<"Please enter Policy Number: ";    //prompt user to enter data
   location = Longinput(31, 5, 4);						  //get location 

   HomFile.close();   //close home file
   HomFile.open("HomeFile.txt", ios::in | ios::out | ios::binary); //reopen file

   //Set position to read from file
   HomFile.seekg((location - 1111) * sizeof(STRUCHome));
   //Read from location
   HomFile.read(reinterpret_cast <char *> (&HOME), sizeof(STRUCHome));

   //Test if the location is the same as the policy number
   if (location != HOME.policyNum){																		

     	gotoxy( 3, 6); cout<<"\aSorry! But that policy number is not in the database!!!";  //Go to location and out the message
      return 0;

   }//endif

   //read file from location
	ReadHFile(HomFile, location);

	return 1;

}//end view method

////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * Edit a person's home insurance policy.
 */
void Homeinsurpolicy::EditPolicy( fstream &HomFile )
{
   struct STRUCHome HOME;	//Declare structure of type Home							                                           
   long location;			//Declare variable location

   string fname;			// Declare First name as string
   string lname;			// Declare Last name as string
   Date effdate;			// Declare object to store Effective Date 
   Date expdate;			// Declare object to store Expiry Date
   int day, month, year;	// Declare day, month and year as integers 
   /**/
	double Esthomeval;		// Estimated valve of home.
	string Firstlineadd;	// First line of address.
	string Seclineadd;		// Second line of Address.
	string Rooftype;		// Type of roof on the house.
	string Buralarm;		// Is a burgler alarm install?
	string Firealarm;		// Is a fire alarm installed?


	ThemeStyle1( );			//create screen theme

   system("color 9F");		//Set program color 

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 46 ); //Set text color
   gotoxy( 27, 2);     cout<<"] Edit Home Insurance Policy [";			//Displays the Header

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 159 ); //Set text color
   /**
    * Populate the Base class
    */

   gotoxy(3, 5); cout<<"Please enter Policy Number: ";	//Go to location and Prompt user to enter policy number
   location = Longinput(31, 5, 4);						//Store policy number in location									

   fstream HFile;			//declare a object file for home											
   HFile.open ("HomeFile.txt", ios::in | ios::out | ios::binary ); //reopen the file

   //Set position to read from file
   HFile.seekg((location - 1111) * sizeof(STRUCHome));
   //Read from location
   HFile.read(reinterpret_cast <char *> (&HOME), sizeof(STRUCHome));

   //Test if the location is the same as the policy number
   if (location != HOME.policyNum){

     	gotoxy( 3, 6); cout<<"\aSorry! But that policy number is not in the database!!!";

  	   gotoxy( 25, 9); system("PAUSE");
      return;

   }//endif

   //read file from location
	ReadHFile(HomFile, location);

   effdate = geteffectivedate(  );
   expdate = getexpirydate(  );

   /**
    * Display the Base child class
    */
	
   //Go to location and display policy holder First Address
   gotoxy(3, 6);   cout<<"Policy Holder First Name: [                  ]";
   gotoxy(30 , 6); cout<<getfnamepolholder(  );
	//Go to location and display policy holder Second Address
   gotoxy(3, 7);   cout<<"Policy Holder Last Name : [                  ]";
   gotoxy(30 , 7); cout<<getlnamepolholder(  );
	//Go to location and display day, month and year of policy Effective date
   gotoxy(3, 8);   cout<<"Effective Date ---------: [D:    M:    Y:    ]";
   gotoxy(32, 8);  cout<<effdate.getDay(  );
   gotoxy(38, 8);  cout<<effdate.getMonth(  );
   gotoxy(44, 8);  cout<<effdate.getYear(  );
	//Go to location and display day, month and year of policy Expiry date
   gotoxy(3, 9);   cout<<"Expiry Date ------------: [D:    M:    Y:    ]";
   gotoxy(32, 9);  cout<<expdate.getDay(  );
   gotoxy(38, 9);  cout<<expdate.getMonth(  );
   gotoxy(44, 9);  cout<<expdate.getYear(  );


   /**
    * Display the Base child class
    */
	//Go to location and display policy holder First Address
	gotoxy(3, 11);  cout<<"First Address -----------: [                             ]";
   gotoxy(31, 11); cout<<getfirstlineadd (  );
	//Go to location and display policy holder Second Address
   gotoxy(3, 12);  cout<<"Second Address ----------: [                             ]";
   gotoxy(31, 12); cout<<getseclineadd (  );
	//Go to location and display policy holder Roof Type
   gotoxy(3, 13);  cout<<"Roof Type ---------------: [                  ]";
   gotoxy(31, 13); cout<<getrooftype (  );
	//Go to location and display policy holder response to burgular alarm
   gotoxy(3, 15);  cout<<"Does house have a burglar alarm installed?       [    ]";
   gotoxy(53, 15); cout<<getburalarm (  );
	//Go to location and display policy holder response to fire alarm
   gotoxy(3, 16);  cout<<"Does house have a fire alarm installed?          [    ]";
   gotoxy(53, 16); cout<<getfirealarm (  );
	//Go to location and display policy holder Estimated value of home 
   gotoxy(3, 18);  cout<<"Estimated value of home -: [$               ]";
   gotoxy(32, 18); cout<<getesthomeval (  );



   //// The Navigation and editing of the file ////

	int input;     //set the navigation for correction
   int count = 1; //set the location for correction in the object
   int y_axis = 6;


   gotoxy(68,23); cout<<"\273";            /////////////////////
                                           //
   gotoxy(32,25); cout<<"\312";            //
   gotoxy(55, 25); cout<<"\312";           //
                                           //    Create
   gotoxy(12,23);                          //       a
   for (int cnt = 12; cnt < 68; cnt++){    //        design
   	cout<<"\315";                        //            for
   }                                       //              -->
   gotoxy(12,23); cout<<"\311";            //                 saving / editing / end
   gotoxy(12, 25); cout<<"\312";           //
   gotoxy(68, 25); cout<<"\312";           //
                                           //
   gotoxy(55, 23); cout<<"\313";           //
   gotoxy(32, 23); cout<<"\313";           //////////////////////

   gotoxy( 12, 24); cout<<"\272F1: Save-Y[ ] N[ ] \272 EDIT MODE: Y[ ] N[ ] \272 END -->Exit\272";

   gotoxy( 52, 24); cout<<"\376"; //goto location xy and show that its not in edit mode
   gotoxy( 24, 24); cout<<"\376"; //goto location xy and show that its currently saved

   gotoxy(2,6);   cout<<"\335";   //scroll bar

   gotoxy(3,22); cout<<"-->"<<setw(2)<<count; //display count

   input = getch();  // get user input

   //do condition while the you doesn't press END
   while ( input != 0x4f ) {

   	//navigate up if the up or left arrow key is pressed
      if (input == 0x48 || input == 0x4b ) {

         gotoxy( 2, y_axis); cout<<" "; //goto location and display blank
      	count--;				//decrement count

		//if count is zero
         if (count == 0 ) {		
            count = 1;		//initialize count to 1
            y_axis = 6;		// set y-axis to 6
            gotoxy( 2, y_axis); cout<<"\335"; //goto location and display
         }//end if
		 //else count is 4, 7, 9 do the following
         else if (count == 4 || count == 7 || count == 9) {
         	y_axis -= 2;	//decrement y-axis by 2
         	gotoxy( 2, y_axis); cout<<"\335";   //goto location and display
         }//end else if
         else {
         	y_axis--;		//decrement y-axis
         	gotoxy( 2, y_axis); cout<<"\335";  //goto location and display
         }//

      }//end if
   	//navigate down if the down or right arrow key is pressed
      if (input == 0x50 || input == 0x4d ) {

      	gotoxy(2, y_axis); cout<<" "; //goto location and display blank
         count++;	//increment count

		//if count is 11
         if (count == 11 ) {
            count = 10;		//initialize count to 10
            y_axis = 18;	// set y-axis to 18
            gotoxy( 2, y_axis); cout<<"\335";  //goto location and display
         }// end if 
         else if (count == 5 || count == 8 || count == 10) {
         	y_axis += 2;
         	gotoxy( 2, y_axis); cout<<"\335";  //goto location and display
         }//end else if
         else {
         	y_axis++;  //increment y-axis
         	gotoxy( 2, y_axis); cout<<"\335";  //goto location and display
         }// end else
      }//end if

      gotoxy(3,22); cout<<"-->"<<setw(2)<<count; //display count

	 //if the user press ENTER
      if ( input == 0x0d) {

         gotoxy( 47, 24); cout<<"\376"; //goto location xy and show that edit mode is on
         gotoxy( 52, 24); cout<<" ";    //goto location xy and show that edit mode is off
         gotoxy( 24, 24); cout<<" ";    //goto location xy and show empty space for Yes
         gotoxy( 29, 24); cout<<"\376"; //goto location xy and show that its currently not saved
         
		 //do a switch on the count
		 switch ( count ) {

   			/**
             * Edit the Base class
             */
         	case 1: //if case 1
				// goto location and redisplay the following blank
				gotoxy(3, 6);   cout<<"Policy Holder First Name: [                  ]";
                
				fname = STinGinput(30 , 6, 18);	//Gets string input from user and assigns it to fname
   				setfnamepolholder( fname );		//Set Policy Holder First Name in Base class
               break;

            case 2:	//if case 2
				// goto location and redisplay the following blank
   				gotoxy(3, 7);   cout<<"Policy Holder Last Name : [                  ]";
 				
				lname = STinGinput(30 , 7, 18);	//Gets string input from user and assigns it to lname
  				setlnamepolholder( lname );		//Set Policy Holder Last Name in Base class
               break;

            case 3:	//if case 3
				// goto location and redisplay the following blank
   				gotoxy(3, 8);   cout<<"Effective Date ---------: [D:    M:    Y:    ]";
				
				day = Intinput(32, 8, 2);   month = Intinput(38, 8, 2);   year = Intinput(44, 8, 4); //Get day, month and year from user
   				effdate.setDay(day);        effdate.setMonth(month);      effdate.setYear(year);	 //Initialize day, month and year in Effdate 
				seteffectivedate( effdate );  //Set Effective Date in Base Class
               break;

            case 4:	//if case 4
				// goto location and redisplay the following blank
   				gotoxy(3, 9);   cout<<"Expiry Date ------------: [D:    M:    Y:    ]";
				
				day = Intinput(32, 9, 2);   month = Intinput(38, 9, 2);   year = Intinput(44, 9, 4); //Get day, month and year from user
  				expdate.setDay(day);        expdate.setMonth(month);      expdate.setYear(year);	 //Initialize day, month and year in Expdate
				setexpirydate( expdate );	//Set Expiry Date in Base Class
               break;

   			/**
             * Edit the Base child class
             */
			case 5:	//if case 5
					// goto location and redisplay the following blank
				gotoxy(3, 11); cout<<"First Address -----------: [                             ]";
				
				Firstlineadd = STinGinput2(31 , 11, 29);	//Get first line of address from user 
   				setfirstlineadd ( Firstlineadd );			//Set firstlineadd in child class		
               break;

            case 6:	//if case 6
				// goto location and redisplay the following blank
   				gotoxy(3, 12); cout<<"Second Address ----------: [                             ]";
				
				Seclineadd = STinGinput2(31 , 12, 29);		//Get second line of address from user
   				setseclineadd ( Seclineadd );				//Set seclineadd in child class	
               break;

            case 7:	//if case 7
				// goto location and redisplay the following blank
   				gotoxy(3, 13); cout<<"Roof Type ---------------: [                  ]";
				
				Rooftype = STinGinput(31 , 13, 18);	//Get roof type from user 
   				setrooftype ( Rooftype );			//Set roof type in child class
               break;

            case 8:	//if case 8
				// goto location and redisplay the following blank
   				gotoxy(3, 15); cout<<"Does house have a burglar alarm installed?    Yes[ ] No[ ]";
   				
				Buralarm = YesNo(53, 15);	//Get Burgular alarm response from user
	   			setburalarm ( Buralarm );	//Set Burgular alarm response in child class
               break;

            case 9:	//if case 9
				// goto location and redisplay the following blank
   				gotoxy(3, 16); cout<<"Does house have a fire alarm installed?       Yes[ ] No[ ]";
				
				Firealarm = YesNo(53, 16);		//Get Fire alarm response from user
   				setfirealarm ( Firealarm );		//Set Fire alarm in response child class
               break;

            case 10:	//if case 10
				// goto location and redisplay the following blank
   				gotoxy(3, 18); cout<<"Estimated value of home -: [$               ]";
				
				Esthomeval = Doubleinput(32, 18, 16);	//Get estimated home value from user
   				setesthomeval ( Esthomeval );			//Set estimated home value child class
               break;

         }//end switch

         gotoxy( 47, 24); cout<<" ";     //goto location xy and show empty space
         gotoxy( 52, 24); cout<<"\376";  //goto location xy and show that edit mode is off

      }//end if

      if ( input == 0x3b)  {  // F1 to Save to file
       	WriteToHFile(HomFile, location );
         gotoxy( 29, 24); cout<<" ";    //goto location xy and show empty space
         gotoxy( 24, 24); cout<<"\376"; //goto location xy and show that its currently saved
      }//end if

      input = getch(); //get input again
   }// end while

}// end function edit
//////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * Display the data the home insurance policy.
 */
void Homeinsurpolicy::Display ( ){

	// First line of address.
   gotoxy(3, 11); cout<<"First Address -----------: ["<<firstlineadd<<" ]";
	// Second line of Address.
   gotoxy(3, 12); cout<<"Second Address ----------: ["<<seclineadd<<" ]";
	// Type of roof on the house.
   gotoxy(3, 13); cout<<"Roof Type ---------------: ["<<rooftype<<" ]";
	// Is a burgler alarm install?
   gotoxy(3, 15); cout<<"Does house have a burglar alarm installed?       ["<<buralarm<<" ]";
	// Is a fire alarm installed?
   gotoxy(3, 16); cout<<"Does house have a fire alarm installed?          ["<<firealarm<<" ]";

   // Estimated valve of home.
   gotoxy(3, 18); cout<<"Estimated value of home -: [$"<<esthomeval<<" ]";

}

