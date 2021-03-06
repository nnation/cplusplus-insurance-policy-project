/*################################################<
>>> *Authors: Nathaniel Nation                  <<<
>>>                                             <<<
>>> Lecture/Tutor: Mr. David White              <<<
***************************************************/

#include "MVinsurpolicy.h"
#include "dbutility.h"
#include <iomanip>
#include <iostream>
#include <conio.h>

// Constructors/Destructors
//

MVinsurpolicy::MVinsurpolicy ( )
:Insurpolicy()
{
// This is the model of the vehicle.
	 vehiclemodel = " ";
	// This is the make of the vehicle.
    make = " ";
	// This is the year of the vehicle.
	 year = 0;
	// This is the license number of the vehicle.
	 licenseNum = " ";
	// This is the chassis number of the vehicle.
	 chassisNum = 0;
	// This is the estimated value of the vehicle.
	 estvalvehicle = 0;
	// This is the fuel type of the vehicle.
    fueltype = " ";
	// This is the body type of the vehicle.
	 bodytype = " ";
	// This is the CC Rating of the vehicle.
	 ccrating = 0;
	// This is the seating capacity of the vehicle.
	 seatingcap = 0;
	// This gives a yes or no response as to whether the vehicle has an accident during the last year.
	 involveacci = " ";
	// This gives a yes or no response as to whether the vehicle has an alarm.
	 alarm = " ";
}

MVinsurpolicy::~MVinsurpolicy ( ) { }

//
// Mutator Methods
//

/**
* Set the value of vehiclemodel
 * This is the model of the vehicle.
 * @param vmodel the new value of vehiclemodel
 */
void MVinsurpolicy::setvehiclemodel ( string vmodel )	 {
		vehiclemodel = vmodel;
}

/**
 * Set the value of make
 * This is the make of the vehicle.
 * @param mk the new value of make
 */
void MVinsurpolicy::setmake ( string mk)	 {
		make = mk;
}

/**
 * Set the value of year
 * This is the year of the vehicle.
 * @param yr the new value of year
 */

void MVinsurpolicy::setyear ( int yr )	 {
		year = yr;
}

/**
 * Set the value of licenseNum
 * This is the license number of the vehicle.
 * @param Lnum the new value of licenseNum
 */
void MVinsurpolicy::setlicenseNum ( string Lnum )	 {
		licenseNum = Lnum;
}

/**
 * Set the value of chassisNum
 * This is the chassis number of the vehicle.
 * @param cnum the new value of chassisNum
 */
void MVinsurpolicy::setchassisNum ( long cnum )	 {
	chassisNum = cnum;
}

/**
 * Set the value of estvalvehicle
 * This is the estimated value of the vehicle.
 * @param evvehicle the new value of estvalvehicle
 */
void MVinsurpolicy::setestvalvehicle ( double evvehicle )	 {
		estvalvehicle = evvehicle;
}

/**
 * Set the value of fueltype
 * This is the fuel type of the vehicle.
 * @param fueltp the new value of fueltype
 */
void MVinsurpolicy::setfueltype ( string fueltp )	 {
		fueltype = fueltp;
}

/**
 * Set the value of bodytype
 * This is the body type of the vehicle.
 * @param bodytp the new value of bodytype
 */
void MVinsurpolicy::setbodytype ( string bodytp )	 {
		bodytype = bodytp;
}

/**
 * Set the value of ccrating
 * This is the CC Rating of the vehicle.
 * @param ccr the new value of ccrating
 */
void MVinsurpolicy::setccrating ( double ccr )	 {
		ccrating = ccr;
}

/**
 * Set the value of seatingcap
 * This is the seating capacity of the vehicle.
 * @param seatcap  the new value of seatingcap
 */
void MVinsurpolicy::setseatingcap ( int seatcap  )	 {
		seatingcap = seatcap ;
}

/**
 * Set the value of involveacci
 * This gives a yes or no response as to whether the vehicle has an accident during
 * the last year.
 * @param involacci the new value of involveacci
 */
void MVinsurpolicy::setinvolveacci ( string involacci )	 {
		involveacci = involacci;
}

/**
 * Set the value of alarm
 * This gives a yes or no response as to whether the vehicle has an alarm.
 * @param Balarm  the new value of alarm
 */
void MVinsurpolicy::setalarm ( string Balarm  )	 {
		alarm = Balarm ;
}

/**
 * Set the value of policytype
 * Store the client policy type.
 * @param poltype the new value of policytype
 */
void MVinsurpolicy::setpolicytype( )
{
		policytype = "Motor Vehicle Insurance Policy";
}

/**
 * Set the value of insurpremium
 * Store the client's premium.
 *
 */
void MVinsurpolicy::setinsurpremium( )	 {

		insurpremium = estvalvehicle * 0.1;

      /*If the vehicle was invloved in an accident during the last year,
      add 4% of the vehicle value to the premium */
      if( involveacci.compare("Yes") > 0) {

      	insurpremium = insurpremium + (estvalvehicle * 0.04);
      }

      /*If the vehicle has a burglar alarm installed then subtract 3%
      of the vehicle value from the premium */
      if( alarm.compare("Yes") > 0 ) {

      	insurpremium = insurpremium - (estvalvehicle * 0.03);
      }
}

//
// Accessor Methods
//

/**
 * Get the value of vehiclemodel
 * This is the model of the vehicle.
 * @return the value of vehiclemodel
 */
string MVinsurpolicy::getvehiclemodel ( ) const{
	return vehiclemodel;
}

/**
 * Get the value of make
 * This is the make of the vehicle.
 * @return the value of make
 */
string MVinsurpolicy::getmake ( ) const{
	return make;
}

/**
 * Get the value of year
 * This is the year of the vehicle.
 * @return the value of year
 */
int MVinsurpolicy::getyear ( ) const{
	return year;
}

/**
 * Get the value of licenseNum
 * This is the license number of the vehicle.
 * @return the value of licenseNum
 */
string MVinsurpolicy::getlicenseNum ( ) const{
	return licenseNum;
}

/**
 * Get the value of chassisNum
 * This is the chassis number of the vehicle.
 * @return the value of chassisNum
 */
long MVinsurpolicy::getchassisNum ( ) const{
	return chassisNum;
}

/**
 * Get the value of estvalvehicle
 * This is the estimated value of the vehicle.
 * @return the value of estvalvehicle
 */
double MVinsurpolicy::getestvalvehicle ( ) const{
	return estvalvehicle;
}

/**
 * Get the value of fueltype
 * This is the fuel type of the vehicle.
 * @return the value of fueltype
 */
string MVinsurpolicy::getfueltype ( ) const{
	return fueltype;
}

/**
 * Get the value of bodytype
 * This is the body type of the vehicle.
 * @return the value of bodytype
 */
string MVinsurpolicy::getbodytype ( ) const{
	return bodytype;
}

/**
 * Get the value of ccrating
 * This is the CC Rating of the vehicle.
 * @return the value of ccrating
 */
double MVinsurpolicy::getccrating ( ) const{
	return ccrating;
}

/**
 * Get the value of seatingcap
 * This is the seating capacity of the vehicle.
 * @return the value of seatingcap
 */
int MVinsurpolicy::getseatingcap ( ) const{
	return seatingcap;
}

/**
 * Get the value of involveacci
 * This gives a yes or no response as to whether the vehicle has an accident during
 * the last year.
 * @return the value of involveacci
 */
string MVinsurpolicy::getinvolveacci ( ) const{
	return involveacci;
}

/**
 * Get the value of alarm
 * This gives a yes or no response as to whether the vehicle has an alarm.
 * @return the value of alarm
 */
string MVinsurpolicy::getalarm ( ) const{
	return alarm;
}

/**
 * Get the value of policytype
 * Store the client policy type.
 * @return the value of policytype
 */
string MVinsurpolicy::getpolicytype( ) const{
	return policytype;
}

/**
 * Get the value of insurpremium
 * Store the client's premium.
 * @return the value of insurpremium
 */
double MVinsurpolicy::getinsurpremium( ) const{
	return insurpremium;
}


//
//// Utility Functions
//

/**
 * Add a Motor vehicle insurance policy
 * @
 */
void MVinsurpolicy::addPolicy( fstream &MVFile )   {

   struct STRUCMotov MOTOV; // Declare a structure of type Motor vehicle
   long polNum = 1111;		// Declare and initalizing Policy number to the value 1111
   string fname;			// Declare First name as string
   string lname;			// Declare Last name as string
   Date effdate;			// Declare object to store Effective Date
   Date expdate;			// Declare object to store Expiry Date
   int day, month, year;	// Declare day, month and year as integers

   /* Motor Vehicle */

	string Vehiclemodel;     // This is the model of the vehicle.
	string Make;             // This is the make of the vehicle.
	int Year;                // This is the year of the vehicle.
	string LicenseNum;       // This is the license number of the vehicle.
	long ChassisNum;         // This is the chassis number of the vehicle.
	double Estvalvehicle;    // This is the estimated value of the vehicle.
	string Fueltype;         // This is the fuel type of the vehicle.
	string Bodytype;         // This is the body type of the vehicle.
	double Ccrating;         // This is the CC Rating of the vehicle.
	int Seatingcap;          // This is the seating capacity of the vehicle.
	string Involveacci;      // This gives a yes or no response as to whether the vehicle has an accident during the last year.
	string Alarm;            // This gives a yes or no response as to whether the vehicle has an alarm.

   string res;				 // Declare variable to store user response
   long location;			 // Deaclare variable to store offset in memory to read or write

   /**
    * Populate the Base class
    */
   fstream MotoVFile;	//Declare an object file for Motor vehicle Insurance 
   MotoVFile.open("MVFile.txt", ios::in | ios::out | ios::binary);

   //Set position to read from file
   MotoVFile.seekg((polNum - 1111) * sizeof(STRUCMotov));
   //Read from location
   MotoVFile.read(reinterpret_cast <char *> (&MOTOV), sizeof(STRUCMotov)); //Opening the Motor vehicle File Insurance in read in /out/binary

   //Loop though the file to fine a missing policy number
   while (MotoVFile && !MotoVFile.eof()) {
      //If a match is found the increament the polynum
      if (polNum == MOTOV.policyNum){
      	polNum++;
      }//endif

      //read the next file
   	MotoVFile.read(reinterpret_cast <char *> (&MOTOV), sizeof(STRUCMotov));
   }//endwhile

   gotoxy(18, 5);				//put cursor at specified location
   cout<<polNum;				//Display Policy Number
   location = polNum;			//Set Policy Number to location
	setpolicyNum( polNum );		//Set Policy Number in Base Class	

   fname = STinGinput(30 , 6, 18); //Gets string input from user and assigns it to fname
   setfnamepolholder( fname );	   //Set Policy Holder First Name in Base class

   lname = STinGinput(30 , 7, 18);	//Gets string input from user and assigns it to lname
   setlnamepolholder( lname );		//Set Policy Holder Last Name in Base class

   day = Intinput(32, 8, 2);   month = Intinput(38, 8, 2);   year = Intinput(44, 8, 4);	//Get day, month and year from user
   effdate.setDay(day);        effdate.setMonth(month);      effdate.setYear(year);		//Initialize day, month and year in Effdate
   seteffectivedate( effdate );															//Set Effective Date in Base Class

   day = Intinput(32, 9, 2);   month = Intinput(38, 9, 2);   year = Intinput(44, 9, 4);	//Get day, month and year from user
   expdate.setDay(day);        expdate.setMonth(month);      expdate.setYear(year);		//Initialize day, month and year in Expdate
   setexpirydate( expdate );															//Set Expiry Date in Base Class


   /**
    * Populate the Base child class
    */
   Vehiclemodel = STinGinput2(41 , 10, 18); //Get Vehicle model from user
   setvehiclemodel ( Vehiclemodel );		//Set Vehicle model in child class

   Make = STinGinput(41 , 11, 18);			//Get Make from user
   setmake ( Make );						//Set Make in child class

   Year = Intinput(41, 12, 4);				//Get Year from user
   setyear ( Year );						//Set Year in child class

   LicenseNum = STinGinput2(41 , 13, 18);	//Get License Num from user
   setlicenseNum ( LicenseNum );			//Set License Num in child class

   ChassisNum = Longinput( 41, 14, 18);		//Get Chassis Num from user
   setchassisNum ( ChassisNum );			//Set Chassis Num in child class

   Fueltype = STinGinput(41 , 15, 18);		//Get Fuel type from user
   setfueltype ( Fueltype );				//Set Fuel type in child class

   Bodytype = STinGinput2(41 , 16, 18);		//Get Body type from user
   setbodytype ( Bodytype );				//Set Body type in child class

   Ccrating = Intinput( 41,17, 4);			//Get CC rating from user
   setccrating ( Ccrating );				//Set CC rating in child class

   Seatingcap = Intinput( 41,18, 2);		//Get Seating capacity from user
   setseatingcap ( Seatingcap );			//Set Seating capacity in child class

   Involveacci =  YesNo(47,19);				//Get Involveacci response from user
   setinvolveacci ( Involveacci );			//Set Involveacci response in child class

   Alarm = YesNo(47,20);					//Get Alarm response from user
   setalarm ( Alarm );						//Set Alarm response in child class

   Estvalvehicle = Doubleinput( 39, 22, 16);	//Get estimated value from user
   setestvalvehicle ( Estvalvehicle );			//Set estimated value in child class

   setpolicytype( );		//Set policy type in child class
   setinsurpremium( );		//Set insurance premium in child class

   gotoxy( 39, 23);  //Go to location
   cout<<getinsurpremium( );	//Display Insurance Premium

   gotoxy(15, 24);  //Go to location
   cout<<"\"Is This correct?: Yes[ ] No[ ]\"";  //Prompt user for response

   res = YesNo(38, 24);		//Store user response

   if (res.compare("No") == 0) {	//If user response is NO 
   	AddMotovDisplayScreen( );		//Display Motor vehicle Screen again
      addPolicy( MVFile );			//Call the add policy method and send the Motor vehicle file to it again	
   }//end if
   else {
   	WriteToMVFile( MVFile, location );  //Else write to file
   }//end if

} //end method add policy


/**
 * Display Screen for Add Motor vehicle insurance policy to file
 * @
 */
void MVinsurpolicy::AddMotovDisplayScreen( )   {

	ThemeStyle1( );		//Create program theme

   system("color 9F");	//Set program color 

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 46 );	 //Set text color
   gotoxy(23, 2); cout<<"] Add Motor Vehicle Insurance Police [";		//Displays the Header

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 159 );	 //Set text color
   /**
    * Populate the Base class
    */

   gotoxy(3, 5); cout<<"Policy Number: ";
   gotoxy(3, 6); cout<<"Policy Holder First Name: [                  ]";
   gotoxy(3, 7); cout<<"Policy Holder Last Name : [                  ]";
   gotoxy(3, 8); cout<<"Effective Date ---------: [D:    M:    Y:    ]";
   gotoxy(3, 9); cout<<"Expiry Date ------------: [D:    M:    Y:    ]";


   /**
    * Populate the Base child class
    */

   gotoxy(3, 10); cout<<"Motor Vehicle model ---------------: [                  ]";
   gotoxy(3, 11); cout<<"Motor Vehicle make ----------------: [                  ]";
   gotoxy(3, 12); cout<<"Motor Vehicle year ----------------: [    ]";
	gotoxy(3, 13); cout<<"Motor Vehicle license number ------: [                  ]";
   gotoxy(3, 14); cout<<"Motor Vehicle chassis number ------: [                  ]";
   gotoxy(3, 15); cout<<"Fuel type of Motor Vehicle --------: [                  ]";
   gotoxy(3, 16); cout<<"Body type of Motor Vehicle --------: [                  ]";
   gotoxy(3, 17); cout<<"CC Rating type of Motor Vehicle ---: [    ]";
   gotoxy(3, 18); cout<<"Seating Cappacity of Motor Vehicle : [  ]";
   gotoxy(3, 19); cout<<"Any Vehicular accidents last year?      Yes[ ] No[ ]";
   gotoxy(3, 20); cout<<"Does the vehicle have an alarm system?  Yes[ ] No[ ]";

	gotoxy(3, 22); cout<<"Estimated value of Motor Vehicle: [$               ]";
   gotoxy(3, 23); cout<<"The Insurance Premium is -------: [$               ]";

}//End method Add Motor vehicle Display Screen

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Write Motor vehicle insurance policy to file
 * @
 */
void MVinsurpolicy::WriteToMVFile(fstream &MVFile, long location) {

	struct STRUCMotov MOTOV;	//Declare a structure of type Motor vehicle

   //Base data
   MOTOV.policyNum = getpolicyNum(  );											//Taking policy number from class and placing it in Motor vehicle structrue
   strcpy(MOTOV.fnamepolholder, convertStringToChar(getfnamepolholder( ) ) );	//Taking policy holder first name from class and placing it in Motor vehicle structrue
   strcpy(MOTOV.lnamepolholder, convertStringToChar(getlnamepolholder( ) ) );	//Taking policy holder last name from class and placing it in Motor vehicle structrue
   MOTOV.effectivedate = geteffectivedate(  );									//Taking effective date from class and placing it in Motor vehicle structrue
   MOTOV.expirydate = getexpirydate(  );										//Taking expiry date from class and placing it in Motor vehicle structrue
   strcpy(MOTOV.policytype, convertStringToChar(getpolicytype( ) ) );			//Taking policy type name from class and placing it in Motor vehicle structrue
   MOTOV.insurpremium = getinsurpremium( );										//Taking insurance premium from class and placing it in Motor vehicle structrue									
	
   //derived data
   //Taking vehiclemodel Motor vehicle from class and placing it in Motor vehicle structrue
	strcpy(MOTOV.vehiclemodel, convertStringToChar(getvehiclemodel( ) ) );		

	//Taking make Motor vehicle from class and placing it in Motor vehicle structrue
	strcpy(MOTOV.make, convertStringToChar(getmake( ) ) );						

	//Taking year Motor vehicle from class and placing it in Motor vehicle structrue
	MOTOV.year = getyear (  );													

	//Taking licenseNum Motor vehicle from class and placing it in Motor vehicle structrue
	strcpy(MOTOV.licenseNum, convertStringToChar(getlicenseNum( ) ) );			

	//Taking chassisNum Motor vehicle from class and placing it in Motor vehicle structrue
	MOTOV.chassisNum = getchassisNum (  );										

	//Taking estvalvehicle Motor vehicle from class and placing it in Motor vehicle structrue
	MOTOV.estvalvehicle = getestvalvehicle (  );								

	//Taking fueltype Motor vehicle from class and placing it in Motor vehicle structrue
	strcpy(MOTOV.fueltype, convertStringToChar(getfueltype( ) ) );				

	//Taking bodytype Motor vehicle from class and placing it in Motor vehicle structrue
	strcpy(MOTOV.bodytype, convertStringToChar(getbodytype( ) ) );				

	//Taking ccrating Motor vehicle from class and placing it in Motor vehicle structrue
	MOTOV.ccrating = getccrating (  );											

	//Taking seatingcap Motor vehicle from class and placing it in Motor vehicle structrue
	MOTOV.seatingcap = getseatingcap (  );

	//Taking involveacci Motor vehicle from class and placing it in Motor vehicle structrue
	strcpy(MOTOV.involveacci, convertStringToChar(getinvolveacci( ) ) );

	//Taking alarm Motor vehicle from class and placing it in Motor vehicle structrue
	strcpy(MOTOV.alarm, convertStringToChar(getalarm( ) ) );


   MVFile.close();		//Closing Motor vehicle File
   MVFile.open("MVFile.txt", ios::in | ios::out | ios::binary);  //Reopening the Motor vehicle File

   //Test if the file got opened
   if( !MVFile ) {
   	clrscr();
   	cout<<"\n\n\aThe FilFile pointer is not set!!!";
      getch();
   }//end if
   else {  //else File didnt open
		//move file-position pointer to the correct record in file
	   MVFile.seekp( ( location - 1111 ) * sizeof( STRUCMotov ) );

	   //insert record to file
	   MVFile.write( reinterpret_cast< const char*> ( &MOTOV ), sizeof( STRUCMotov ) );
   }//end else

}//end method write to Motor vehicle File


/**
 * Read Motor Vehicle insurance policy from file
 * @
 */
void MVinsurpolicy::ReadMVFile(fstream &MVFile, long location)
{
	struct STRUCMotov MOTOV;	//Declare a structure of type Motor vehicle
   string Holdstr;				//Declare a variable to temporarily hold a string

   //Test if the file got opened
   if( MVFile ) {
		//move file-position pointer to the correct record in file
	   MVFile.seekg( ( location - 1111 ) * sizeof( STRUCMotov ) );

	   //insert record to file
	   MVFile.read( reinterpret_cast< char*> ( &MOTOV ), sizeof( STRUCMotov ) );
   }//end if
   else {  //else File didnt open
   	clrscr();
   	cout<<"\n\n\aThe FilFile pointer is not set!!!";
      getch();
      return;
   }// end else

   if (MOTOV.policyNum == 0 ) {	//If Policy number is equal to zero then return 
      return;
   }//end if

   setpolicyNum( MOTOV.policyNum ) ;	//Taking Motor vehicle Policy Number and setting it inside Parent class

   Holdstr = MOTOV.fnamepolholder;		//Assigns first name of policy holder to a temporary string
   setfnamepolholder( Holdstr );		//Passing the temporary string to  set policy holder method

   Holdstr = MOTOV.lnamepolholder;		//Assigns last name of policy holder to a temporary string																				
   setlnamepolholder( Holdstr );		//Passing the temporary string to  set policy holder method

   seteffectivedate( MOTOV.effectivedate ); //Taking Motor vehicle effective date and setting it inside Parent class
   setexpirydate( MOTOV.expirydate );		//Taking Motor vehicle expiry date and setting it inside Parent class

   setpolicytype( );			//Set policy type

   /*child*/

   Holdstr = MOTOV.vehiclemodel;	//Get Vehicle model
   setvehiclemodel ( Holdstr );		//Set Vehicle model in child class

   Holdstr = MOTOV.make;			//Get Make
   setmake ( Holdstr );				//Set Make in child class

   setyear ( MOTOV.year );			//Get Year and Set Year in child class

   Holdstr = MOTOV.licenseNum;		//Get License Num
   setlicenseNum ( Holdstr );		//Set License Num in child class

   setchassisNum ( MOTOV.chassisNum ); //Get Chassis Num and Set Chassis Num in child class

   Holdstr = MOTOV.fueltype;		//Get Fuel type
   setfueltype ( Holdstr );			//Set Fuel type in child class

   Holdstr = MOTOV.bodytype;		//Get Body type
   setbodytype ( Holdstr );			//Set Body type in child class

   setccrating ( MOTOV.ccrating );		//Get CC rating and Set CC rating in child class

   setseatingcap ( MOTOV.seatingcap );	//Get Seating capacity and Set Seating capacity in child class

   Holdstr =  MOTOV.involveacci;		//Get Involveacci response
   setinvolveacci ( Holdstr );			//Set Involveacci response in child class

   Holdstr = MOTOV.alarm;				//Get Alarm response
   setalarm ( Holdstr );				//Set Alarm response in child class

   setestvalvehicle ( MOTOV.estvalvehicle );	//Get estimated value and Set estimated value in child class
   setinsurpremium( );	//Set insurance premium in child class

}//end ReadMVFile


///////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * Delete Motor vehicle insurance policy to file
 * @
 */
void MVinsurpolicy::DeleteMotov( fstream &MVFile )
{
   struct STRUCMotov MOTOV;
   long location;
   Date effdate;
   Date expdate;
   string res;


	ThemeStyle1( ); //create screen theme

   system("color 9F");

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 46 );
   gotoxy( 23, 2);     cout<<"] Delete Motor Vehicle Insurance Police [";

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 159 );
   /**
    * Populate the Base class
    */

   gotoxy(3, 5); cout<<"Please enter Policy Number: ";
   location = Longinput(31, 5, 4);

   //Set position to read from file
   MVFile.seekg((location - 1111) * sizeof(STRUCMotov));
   //Read from location
   MVFile.read(reinterpret_cast <char *> (&MOTOV), sizeof(STRUCMotov));

   //Test if the location is the same as the policy number
   if (location != MOTOV.policyNum){

     	gotoxy( 3, 6); cout<<"\aSorry! But that policy number is not in the database!!!";

  	   gotoxy( 25, 9); system("PAUSE");
      return;

   }//endif
   
   //read file from location
	ReadMVFile(MVFile, location);

   effdate = geteffectivedate(  );
   expdate = getexpirydate(  );

   /**
    * Display the Base child class
    */

   gotoxy(3, 6);   cout<<"Policy Holder First Name: [                  ]";
   gotoxy(30 , 6); cout<<getfnamepolholder(  );

   gotoxy(3, 7);   cout<<"Policy Holder Last Name : [                  ]";
   gotoxy(30 , 7); cout<<getlnamepolholder(  );

   gotoxy(3, 8);   cout<<"Effective Date ---------: [D:    M:    Y:    ]";
   gotoxy(32, 8);  cout<<effdate.getDay(  );
   gotoxy(38, 8);  cout<<effdate.getMonth(  );
   gotoxy(44, 8);  cout<<effdate.getYear(  );


   gotoxy(3, 9);   cout<<"Expiry Date ------------: [D:    M:    Y:    ]";
   gotoxy(32, 9);  cout<<expdate.getDay(  );
   gotoxy(38, 9);  cout<<expdate.getMonth(  );
   gotoxy(44, 9);  cout<<expdate.getYear(  );


      /**
    * Populate the Base child class
    */

   gotoxy(3, 10);  cout<<"Motor Vehicle model ---------------: [                  ]";
   gotoxy(41, 10); cout<<getvehiclemodel( );

   gotoxy(3, 11);  cout<<"Motor Vehicle make ----------------: [                  ]";
   gotoxy(41, 11); cout<<getmake( );

   gotoxy(3, 12);  cout<<"Motor Vehicle year ----------------: [    ]";
   gotoxy(41, 12); cout<<getyear (  );

	gotoxy(3, 13);  cout<<"Motor Vehicle license number ------: [                  ]";
   gotoxy(41, 13); cout<<getlicenseNum( );

   gotoxy(3, 14);  cout<<"Motor Vehicle chassis number ------: [                  ]";
   gotoxy(41, 14); cout<<getchassisNum (  );

   gotoxy(3, 15);  cout<<"Fuel type of Motor Vehicle --------: [                  ]";
   gotoxy(41, 15); cout<<getfueltype( );

   gotoxy(3, 16);  cout<<"Body type of Motor Vehicle --------: [                  ]";
   gotoxy(41, 16); cout<<getbodytype( );

   gotoxy(3, 17);  cout<<"CC Rating type of Motor Vehicle ---: [    ]";
   gotoxy(41, 17); cout<<getccrating (  );

   gotoxy(3, 18);  cout<<"Seating Cappacity of Motor Vehicle : [  ]";
   gotoxy(41, 18); cout<<getseatingcap (  );

   gotoxy(3, 19);  cout<<"Any Vehicular accidents last year?         [    ]";
   gotoxy(47, 19); cout<<getinvolveacci( );

   gotoxy(3, 20);  cout<<"Does the vehicle have an alarm system?     [    ]";
   gotoxy(47, 20); cout<<getalarm( );

  	gotoxy(3, 21);  cout<<"Estimated value of Motor Vehicle: [$               ]";
   gotoxy(39, 21); cout<<getestvalvehicle (  );

   gotoxy(3, 22);  cout<<"The Insurance Premium is -------: [$               ]";
   gotoxy(39, 22); cout<<getinsurpremium( );

   gotoxy(15, 24);
   cout<<"\"If This is correct choose 'Yes' to delete: Yes[ ] No[ ]\"";

   res = YesNo(63, 24);

   if (res.compare("Yes") == 0) {    //If the response is yes

   	//Copy a blank Object the Motor vehicle object
   	struct STRUCMotov MOTOV;
      MOTOV.policyNum = 0;

      //Overwrite the Motor vehicle object in the file to blank
      MVFile.seekp( (location - 1111) * sizeof(STRUCMotov) );
      MVFile.write(reinterpret_cast<const char*> (&MOTOV), sizeof(STRUCMotov) );

   } //end if


}


///////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * View a person's Motor Vehicle insurance policy.
 */
int MVinsurpolicy::ViewMotov( fstream &MVFile )  {

   struct STRUCMotov MOTOV;
   long location;


	ThemeStyle1( ); //create screen theme

   system("color 9F");

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 46 );
   gotoxy( 20, 2);     cout<<"] View Motor Vehicle Insurance Police [";

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 159 );
   /**
    * Populate the Base class
    */

   gotoxy(3, 5); cout<<"Please enter Policy Number: ";
   location = Longinput(31, 5, 4);

   MVFile.close();
   MVFile.open("MVFile.txt", ios::in | ios::out | ios::binary);

   //Set position to read from file
   MVFile.seekg((location - 1111) * sizeof(STRUCMotov));
   //Read from location
   MVFile.read(reinterpret_cast <char *> (&MOTOV), sizeof(STRUCMotov));

   //Test if the location is the same as the policy number
   if (location != MOTOV.policyNum){

     	gotoxy( 3, 6); cout<<"\aSorry! But that policy number is not in the database!!!";
      return 0;

   }//endif

   //read file from location
	ReadMVFile(MVFile, location);

	return 1;

}

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Edit a person's Motor Vehicle insurance policy.
 */
void MVinsurpolicy::EditPolicy( fstream &MVFile )
{
   struct STRUCMotov MOTOV;
   long location;
   
   string fname;
   string lname;
   Date effdate;
   Date expdate;
   int day, month, year;

   /* Motor Vehicle */
	string Vehiclemodel;     // This is the model of the vehicle.
	string Make;             // This is the make of the vehicle.
	int Year;                // This is the year of the vehicle.
	string LicenseNum;       // This is the license number of the vehicle.
	long ChassisNum;         // This is the chassis number of the vehicle.
	double Estvalvehicle;    // This is the estimated value of the vehicle.
	string Fueltype;         // This is the fuel type of the vehicle.
	string Bodytype;         // This is the body type of the vehicle.
	double Ccrating;         // This is the CC Rating of the vehicle.
	int Seatingcap;          // This is the seating capacity of the vehicle.
	string Involveacci;      // This gives a yes or no response as to whether the vehicle has an accident during the last year.
	string Alarm;            // This gives a yes or no response as to whether the vehicle has an alarm.


	ThemeStyle1( ); //create screen theme

   system("color 9F");

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 46 );
   gotoxy( 18, 2);     cout<<"] Edit Motor Vehicle Insurance Police [";

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 159 );
   /**
    * Populate the Base class
    */

   gotoxy(3, 5); cout<<"Please enter Policy Number: ";
   location = Longinput(31, 5, 4);

   fstream MFile;
   MFile.open ("MVFile.txt", ios::in | ios::out | ios::binary );

   //Set position to read from file
   MFile.seekg((location - 1111) * sizeof(STRUCMotov));
   //Read from location
   MFile.read(reinterpret_cast <char *> (&MOTOV), sizeof(STRUCMotov));

   //Test if the location is the same as the policy number
   if (location != MOTOV.policyNum){

     	gotoxy( 3, 6); cout<<"\aSorry! But that policy number is not in the database!!!";

  	   gotoxy( 25, 9); system("PAUSE");
      return;

   }//endif

   //read file from location
	ReadMVFile(MVFile, location);

   effdate = geteffectivedate(  );
   expdate = getexpirydate(  );

   /**
    * Display the Base child class
    */

   gotoxy(3, 6);   cout<<"Policy Holder First Name: [                  ]";
   gotoxy(30 , 6); cout<<getfnamepolholder(  );

   gotoxy(3, 7);   cout<<"Policy Holder Last Name : [                  ]";
   gotoxy(30 , 7); cout<<getlnamepolholder(  );

   gotoxy(3, 8);   cout<<"Effective Date ---------: [D:    M:    Y:    ]";
   gotoxy(32, 8);  cout<<effdate.getDay(  );
   gotoxy(38, 8);  cout<<effdate.getMonth(  );
   gotoxy(44, 8);  cout<<effdate.getYear(  );

   gotoxy(3, 9);   cout<<"Expiry Date ------------: [D:    M:    Y:    ]";
   gotoxy(32, 9);  cout<<expdate.getDay(  );
   gotoxy(38, 9);  cout<<expdate.getMonth(  );
   gotoxy(44, 9);  cout<<expdate.getYear(  );


   /**
    * Display the Base child class
    */

   gotoxy(3, 10); cout<<"Motor Vehicle model ---------------: [                  ]";
   gotoxy(41, 10); cout<<getvehiclemodel( );

   gotoxy(3, 11); cout<<"Motor Vehicle make ----------------: [                  ]";
   gotoxy(41, 11); cout<<getmake( );

   gotoxy(3, 12); cout<<"Motor Vehicle year ----------------: [    ]";
   gotoxy(41, 12); cout<<getyear (  );

	gotoxy(3, 13); cout<<"Motor Vehicle license number ------: [                  ]";
   gotoxy(41, 13); cout<<getlicenseNum( );

   gotoxy(3, 14); cout<<"Motor Vehicle chassis number ------: [                  ]";
   gotoxy(41, 14); cout<<getchassisNum (  );

   gotoxy(3, 15); cout<<"Fuel type of Motor Vehicle --------: [                  ]";
   gotoxy(41, 15); cout<<getfueltype( );

   gotoxy(3, 16); cout<<"Body type of Motor Vehicle --------: [                  ]";
   gotoxy(41, 16); cout<<getbodytype( );

   gotoxy(3, 17); cout<<"CC Rating type of Motor Vehicle ---: [    ]";
   gotoxy(41, 17); cout<<getccrating (  );

   gotoxy(3, 18); cout<<"Seating Cappacity of Motor Vehicle : [  ]";
   gotoxy(41, 18); cout<<getseatingcap (  );

   gotoxy(3, 19); cout<<"Any Vehicular accidents last year?         [    ]";
   gotoxy(47, 19); cout<<getinvolveacci( );

   gotoxy(3, 20); cout<<"Does the vehicle have an alarm system?     [    ]";
   gotoxy(47, 20); cout<<getalarm( );

  	gotoxy(3, 21);  cout<<"Estimated value of Motor Vehicle: [$               ]";
   gotoxy(39, 21); cout<<getestvalvehicle (  );


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

   gotoxy(2,6);   cout<<"\335";

   gotoxy(3,23); cout<<"-->"<<setw(2)<<count; //display count

   input = getch();

   while ( input != 0x4f ) {

   	//navigate up if the up or left arrow key is pressed
      if (input == 0x48 || input == 0x4b ) {

         gotoxy( 2, y_axis); cout<<" ";
      	count--;

         if (count == 0 ) {
            count = 1;
            y_axis = 6;
            gotoxy( 2, y_axis); cout<<"\335";
         }
         else {
         	y_axis--;
         	gotoxy( 2, y_axis); cout<<"\335";
         }

      }
   	//navigate down if the down or right arrow key is pressed
      if (input == 0x50 || input == 0x4d ) {

      	gotoxy(2, y_axis); cout<<" ";
         count++;

         if (count == 17 ) {
            count = 16;
            y_axis = 21;
            gotoxy( 2, y_axis); cout<<"\335";
         }
         else {
         	y_axis++;
         	gotoxy( 2, y_axis); cout<<"\335";
         }
      }

      gotoxy(3,23); cout<<"-->"<<setw(2)<<count; //display count

      if ( input == 0x0d) {

         gotoxy( 47, 24); cout<<"\376"; //goto location xy and show that edit mode is on
         gotoxy( 52, 24); cout<<" ";    //goto location xy and show that edit mode is off
         gotoxy( 24, 24); cout<<" ";    //goto location xy and show empty space for Yes
         gotoxy( 29, 24); cout<<"\376"; //goto location xy and show that its currently not saved
         switch ( count ) {

   			/**
             * Edit the Base class
             */
         	case 1:
					gotoxy(3, 6);   cout<<"Policy Holder First Name: [                  ]";
               fname = STinGinput(30 , 6, 18);
   				setfnamepolholder( fname );
               break;

            case 2:
   				gotoxy(3, 7);   cout<<"Policy Holder Last Name : [                  ]";
 				   lname = STinGinput(30 , 7, 18);
  					setlnamepolholder( lname );
               break;

            case 3:
   				gotoxy(3, 8);   cout<<"Effective Date ---------: [D:    M:    Y:    ]";
				   day = Intinput(32, 8, 2);   month = Intinput(38, 8, 2);   year = Intinput(44, 8, 4);
   				effdate.setDay(day);        effdate.setMonth(month);      effdate.setYear(year);
   				seteffectivedate( effdate );
               break;

            case 4:
   				gotoxy(3, 9);   cout<<"Expiry Date ------------: [D:    M:    Y:    ]";
				   day = Intinput(32, 9, 2);   month = Intinput(38, 9, 2);   year = Intinput(44, 9, 4);
  					expdate.setDay(day);        expdate.setMonth(month);      expdate.setYear(year);
   				setexpirydate( expdate );
               break;

   			/**
             * Edit the Base child class
             */
            case 5:
   				gotoxy(3, 10); cout<<"Motor Vehicle model ---------------: [                  ]";
				   Vehiclemodel = STinGinput2(41 , 10, 18);
				   setvehiclemodel ( Vehiclemodel );
               break;

            case 6:
   				gotoxy(3, 11); cout<<"Motor Vehicle make ----------------: [                  ]";
				   Make = STinGinput(41 , 11, 18);
   				setmake ( Make );
               break;

            case 7:
   				gotoxy(3, 12); cout<<"Motor Vehicle year ----------------: [    ]";
				   Year = Intinput(41, 12, 4);
				   setyear ( Year );
               break;

            case 8:
					gotoxy(3, 13); cout<<"Motor Vehicle license number ------: [                  ]";
				   LicenseNum = STinGinput2(41 , 13, 18);
				   setlicenseNum ( LicenseNum );
               break;

            case 9:
   				gotoxy(3, 14); cout<<"Motor Vehicle chassis number ------: [                  ]";
				   ChassisNum = Longinput( 41, 14, 18);
				   setchassisNum ( ChassisNum );
               break;

            case 10:
               gotoxy(3, 15); cout<<"Fuel type of Motor Vehicle --------: [                  ]";
				   Fueltype = STinGinput(41 , 15, 18);
				   setfueltype ( Fueltype );
               break;

            case 11:
   				gotoxy(3, 16); cout<<"Body type of Motor Vehicle --------: [                  ]";
				   Bodytype = STinGinput2(41 , 16, 18);
				   setbodytype ( Bodytype );
               break;

            case 12:
   				gotoxy(3, 17); cout<<"CC Rating type of Motor Vehicle ---: [    ]";
				   Ccrating = Intinput( 41,17, 4);
				   setccrating ( Ccrating );
               break;

            case 13:
   				gotoxy(3, 18); cout<<"Seating Cappacity of Motor Vehicle : [  ]";
				   Seatingcap = Intinput( 41,18, 2);
				   setseatingcap ( Seatingcap );
               break;

            case 14:
   				gotoxy(3, 19); cout<<"Any Vehicular accidents last year?      Yes[ ] No[ ]";
				   Involveacci =  YesNo(47,19);
				   setinvolveacci ( Involveacci );
               break;

            case 15:
   				gotoxy(3, 20); cout<<"Does the vehicle have an alarm system?  Yes[ ] No[ ]";
				   Alarm = YesNo(47,20);
				   setalarm ( Alarm );
               break;

            case 16:
					gotoxy(3, 21); cout<<"Estimated value of Motor Vehicle: [$               ]";
				   Estvalvehicle = Doubleinput( 39, 21, 16);
				   setestvalvehicle ( Estvalvehicle );
               break;

         }//end switch

         gotoxy( 47, 24); cout<<" ";     //goto location xy and show empty space
         gotoxy( 52, 24); cout<<"\376";  //goto location xy and show that edit mode is off

      }//end if

      if ( input == 0x3b)  {  // F1 to Save to file
       	WriteToMVFile(MVFile, location );
         gotoxy( 29, 24); cout<<" ";    //goto location xy and show empty space
         gotoxy( 24, 24); cout<<"\376"; //goto location xy and show that its currently saved
      }//end if

      input = getch();
   }// end while

}// end function edit

//////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Display the contents of motor vehicle insurance policy
 */
void MVinsurpolicy::Display ( ) {

	// This is the model of the vehicle.
   gotoxy(3, 10); cout<<"Motor Vehicle model ---------------: ["<<vehiclemodel<<" ]";

	// This is the make of the vehicle.
   gotoxy(3, 11); cout<<"Motor Vehicle make ----------------: ["<<make<<" ]";

	// This is the year of the vehicle.
   gotoxy(3, 12); cout<<"Motor Vehicle year ----------------: ["<<year<<" ]";

	// This is the license number of the vehicle.
   gotoxy(3, 13); cout<<"Motor Vehicle license number ------: ["<<licenseNum<<" ]";

	// This is the chassis number of the vehicle.
   gotoxy(3, 14); cout<<"Motor Vehicle chassis number ------: ["<<chassisNum<<" ]";

	// This is the fuel type of the vehicle.
	gotoxy(3, 15); cout<<"Fuel type of Motor Vehicle --------: ["<<fueltype<<" ]";

	// This is the body type of the vehicle.
   gotoxy(3, 16); cout<<"Body type of Motor Vehicle --------: ["<<bodytype<<" ]";

	// This is the CC Rating of the vehicle.
   gotoxy(3, 17); cout<<"CC Rating type of Motor Vehicle ---: ["<<ccrating<<" ]";

	// This is the seating capacity of the vehicle.
   gotoxy(3, 18); cout<<"Seating Cappacity of Motor Vehicle : ["<<seatingcap<<" ]";

	// This gives a yes or no response as to whether the vehicle has an accident during the last year.
   gotoxy(3, 19); cout<<"Any Vehicular accidents last year?         ["<<involveacci<<" ]";

	// This gives a yes or no response as to whether the vehicle has an alarm.
   gotoxy(3, 20); cout<<"Does the vehicle have an alarm system?     ["<<alarm<<" ]";

	// This is the estimated value of the vehicle.
   gotoxy(3, 22); cout<<"Estimated value of Motor Vehicle: [$"<<estvalvehicle<<" ]";

}
