/*################################################<
>>> *Authors: Nathaniel Nation                  <<<
>>>                                             <<<
>>> Lecture/Tutor: Mr. David White              <<<
***************************************************/

#include "lifeinsurpolicy.h"
#include "dbutility.h"
#include <iostream>
#include <iomanip>
#include <conio.h>


// Constructors/Destructors
//

Lifeinsurpolicy::Lifeinsurpolicy( )
: Insurpolicy()
{
	// Person's first name.
	firstname =  " ";
	// Person's last name.
	lastname = " ";
	// Insured Person's age.
	AgeInsurPer = 0;
	// First Address.
	firstaddress = " ";
	// 2nd address.
	secaddress = " ";
	// Person's occupation.
	occupation = " ";
	// Is the person a smoker?
	InsurAsmoker = " ";
	// Is accidential death and dismemberment coverage required?
	ADDC = " ";
	// Estimated value of the person insured.
	EstValPer = 0;
}

Lifeinsurpolicy::~Lifeinsurpolicy( ) { }

//
// Mutator methods
//

/**
 * Set the value of firstname
 * Person's first name.
 * @param fname the new value of firstname
 */
void Lifeinsurpolicy::setfirstname( string fname )	 {
		firstname = fname;
}

/**
 * Set the value of lastname
 * Person's last name.
 * @param lname the new value of lastname
 */
void Lifeinsurpolicy::setlastname( string lname )	 {
		lastname = lname;
}

/**
 * Set the value of AgeInsurPer
 * Insured Person's age.
 * @param ageper the new value of AgeInsurPer
 */
void Lifeinsurpolicy::setAgeInsurPer( int ageper )	 {
		AgeInsurPer = ageper;
}

/**
 * Set the value of firstaddress
 * First Address.
 * @param faddress the new value of firstaddress
 */
void Lifeinsurpolicy::setfirstaddress( string faddress )	 {
		firstaddress = faddress;
}

/**
 * Set the value of secaddress
 * 2nd address.
 * @param saddress the new value of secaddress
 */
void Lifeinsurpolicy::setsecaddress( string saddress )	 {
		secaddress = saddress;
}

/**
 * Set the value of occupation
 * Person's occupation.
 * @param occup the new value of occupation
 */
void Lifeinsurpolicy::setoccupation( string occup )	 {
		occupation = occup;
}

/**
 * Set the value of InsurAsmoker
 * Is the person a smoker?
 * @param smoker the new value of InsurAsmoker
 */
void Lifeinsurpolicy::setIsPerAsmoker( string smoker )	 {
		InsurAsmoker = smoker;
}

/**
 * Set the value of ADDC
 * Is accidential death and dismemberment coverage required?
 * @param Accdc  the new value of ADDC
 */
void Lifeinsurpolicy::setaddc( string Accdc )	 {
		ADDC = Accdc;
}

/**
 * Set the value of EstValPer
 * Estimated value of the person insured.
 * @param value the new value of EstValPer
 */
void Lifeinsurpolicy::setestvalper( double value )	 {
		EstValPer = value;
}

/**
 * Set the value of policytype
 * Store the client policy type.
 * @param poltype the new value of policytype
 */
void Lifeinsurpolicy::setpolicytype( )
{
		policytype = "Life Insurance Policy";
}

/**
 * Set the value of insurpremium
 * Store the client's premium.
 *
 */
void Lifeinsurpolicy::setinsurpremium( )	 {

		insurpremium = EstValPer * 0.05;

      //If is the person to be insured is a smoker add 1% of the person's value to premium
      if ( InsurAsmoker.compare("Yes") > 0){
         insurpremium = insurpremium + ( EstValPer * 0.01 );
      }

      //If accidental death and dismemberment is required then add 2% of the person's value to premium
      if ( ADDC.compare("Yes") > 0){
         insurpremium = insurpremium + ( EstValPer * 0.02 );
      }
}

//
// Accessor methods
//

/**
 * Get the value of firstname
 * Person's first name.
 * @return the value of firstname
 */
string Lifeinsurpolicy::getfirstname( ) const{
	return firstname;
}

/**
 * Get the value of lastname
 * Person's last name.
 * @return the value of lastname
 */
string Lifeinsurpolicy::getlastname( ) const{
	return lastname;
}

/**
 * Get the value of AgeInsurPer
 * Insured Person's age.
 * @return the value of AgeInsurPer
 */
int Lifeinsurpolicy::getAgeInsurPer( ) const{
	return AgeInsurPer;
}

/**
 * Get the value of firstaddress
 * First Address.
 * @return the value of firstaddress
 */
string Lifeinsurpolicy::getfirstaddress( ) const{
	return firstaddress;
}

/**
 * Get the value of secaddress
 * 2nd address.
 * @return the value of secaddress
 */
string Lifeinsurpolicy::getsecaddress( ) const{
	return secaddress;
}

/**
 * Get the value of occupation
 * Person's occupation.
 * @return the value of occupation
 */
string Lifeinsurpolicy::getoccupation( ) const{
	return occupation;
}

/**
 * Get the value of InsurAsmoker
 * Is the person a smoker?
 * @return the value of InsurAsmoker
 */
string Lifeinsurpolicy::getIsPerAsmoker( ) const{
	return InsurAsmoker;
}

/**
 * Get the value of ADDC
 * Is accidential death and dismemberment coverage required?
 * @return the value of ADDC
 */
string Lifeinsurpolicy::getaddc( ) const{
	return ADDC;
}

/**
 * Get the value of EstValPer
 * Estimated value of the person insured.
 * @return the value of EstValPer
 */
double Lifeinsurpolicy::getestvalper( ) const{
	return EstValPer;
}

/**
 * Get the value of policytype
 * Store the client policy type.
 * @return the value of policytype
 */
string Lifeinsurpolicy::getpolicytype( ) const{
	return policytype;
}

/**
 * Get the value of insurpremium
 * Store the client's premium.
 * @return the value of insurpremium
 */
double Lifeinsurpolicy::getinsurpremium( ) const{
	return insurpremium;
}

//
//// Utility Functions
//

/**
 * Add a Life insurance policy
 * @
 */
void Lifeinsurpolicy::addPolicy(fstream &FilFile)   {

   struct STRUCLife LIFE;	// Declare a structure of type life	
   long polNum = 1111;		// Declare and initalizing Policy number to the value 1111
   string fname;			// Declare First name as string
   string lname;			// Declare Last name as string
   Date effdate;			// Declare object to store Effective Date
   Date expdate;			// Declare object to store Expiry Date
   int day, month, year;	// Declare day, month and year as integers
   /**/
	int ageper;
   string faddress;			// First line of address.
   string saddress;			// Second line of Address.			
   string occup;			// Occupation 
   string smoker;			// Response if person is a smoker
   string Accdc;			// Response to if the person has very been in an accident
   double value;			// hold value

   string res;				// Declare variable to store user response
   long location;			// Deaclare variable to store offset in memory to read or write

   /**
    * Populate the Base class
    */
   fstream FFile;		//Declare an object file for life Insurance   
   FFile.open("LifeFile.txt", ios::in | ios::out | ios::binary);	//Opening the Life File Insurance in read in /out/binary

   //Set position to read from file
   FFile.seekg((polNum - 1111) * sizeof(STRUCLife));
   //Read from location
   FFile.read(reinterpret_cast <char *> (&LIFE), sizeof(STRUCLife));



   //Loop though the file to fine a missing policy number
   while (FFile && !FFile.eof()) {
      //If a match is found the increament the polynum
      if (polNum == LIFE.policyNum){
      	polNum++;
      }//endif

      //read the next file
   	FFile.read(reinterpret_cast <char *> (&LIFE), sizeof(STRUCLife));
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

   day = Intinput(32, 9, 2);   month = Intinput(38, 9, 2);   year = Intinput(44, 9, 4);	//Get day, month and year from user
   expdate.setDay(day);        expdate.setMonth(month);      expdate.setYear(year);		//Initialize day, month and year in Expdate
   setexpirydate( expdate );															//Set Expiry Date in Base Class


   /**
    * Populate the Base child class
    */

   fname = STinGinput(30 , 10, 18);	//Get first name from user
   setfirstname( fname );			//Set first name in child class

   lname = STinGinput(30 , 11, 18);	//Get last name from user
   setlastname( lname );			//Set last name in child class	

   ageper = Intinput(30, 12, 3);	//Get person's age from the user  
   setAgeInsurPer( ageper );		//Set person's age in child class

   faddress = STinGinput2(30 , 13, 29);	//Get first address from user
   setfirstaddress( faddress );			//Set firstaddress in child class

   saddress = STinGinput2(30 , 14, 29);	//Get second address from user
   setsecaddress( saddress );			//Set secaddress in child class	

   occup = STinGinput(30 , 15, 29);	//Get Occupation from user 
   setoccupation( occup );			//Set Occupation in child class

   smoker = YesNo(41 , 16);			//Get smoker response from user
   setIsPerAsmoker( smoker );		//Set smoker response in child class	

   Accdc = YesNo(68 , 17);			//Get accident response from user
   setaddc( Accdc );				//Set accident response in child class

   value = Doubleinput(40, 18, 16); //Get setestvalper from user
   setestvalper( value );			//Set setestvalper in child class

   setpolicytype( );	//Set policy type in the child class 
   setinsurpremium( );	//Set insurance premium in the child class

   gotoxy( 40, 19);		//Go to location
   cout<<getinsurpremium( );	//Display Insurance Premium 															

   gotoxy(15, 21);		//Go to location
   cout<<"\"Is This correct?: Yes[ ] No[ ]\""; //Prompt user for response

   res = YesNo(38, 21);		//Store user response

   if (res.compare("No") == 0) { //If user response is NO 
   	AddLifeDisplayScreen( );	 //Display Life Screen again
      addPolicy(FilFile);		//Call the add policy method and send the Life file to it again	
   }//end if
   else {
     WriteToLFile(FilFile, location); //Else write to file
   }//end else

}//end method add policy


/**
 * Display Screen for Add Life insurance policy to file
 * @
 */
void Lifeinsurpolicy::AddLifeDisplayScreen( )
{

	ThemeStyle1( );	//Create program theme

   system("color 9F");	//Set program color 
	
   //Set text color
   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 46 );
   gotoxy( 25, 2);     cout<<"] Add Life Insurance Policy [";		    //Displays the Header	

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 159 ); //set text color
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

   gotoxy(3, 10); cout<<"Insurer's First Name ---: [                  ]";
   gotoxy(3, 11); cout<<"Insurer's Last Name ----: [                  ]";
   gotoxy(3, 12); cout<<"Insurer's Age ----------: [   ]";
	gotoxy(3, 13); cout<<"First Address ----------: [                             ]";
   gotoxy(3, 14); cout<<"Second Address ---------: [                             ]";
   gotoxy(3, 15); cout<<"Person's occupation ----: [                             ]";
   gotoxy(3, 16); cout<<"Is the person a smoker?           Yes[ ] No[ ]";
   gotoxy(3, 17); cout<<"Is accidential death and dismemberment coverage required?    Yes[ ] No[ ]";

   gotoxy(3, 18); cout<<"Estimated value of person insured: [$               ]";
   gotoxy(3, 19); cout<<"The Insurance Premium is --------: [$               ]";

}//End method Add Life Display Screen

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Write Life insurance policy to file
 * @
 */
void Lifeinsurpolicy::WriteToLFile(fstream &FilFile, long location) {


	struct STRUCLife LIFE;	//Declare a structure of type Life

	//parent Data
   LIFE.policyNum = getpolicyNum(  );											//Taking policy number from class and placing it in Life structrue
   strcpy(LIFE.fnamepolholder, convertStringToChar(getfnamepolholder( ) ) );	//Taking policy holder first name from class and placing it in Life structrue
   strcpy(LIFE.lnamepolholder, convertStringToChar(getlnamepolholder( ) ) );	//Taking policy holder last name from class and placing it in Life structrue
   LIFE.effectivedate = geteffectivedate(  );									//Taking effective date from class and placing it in Life structrue
   LIFE.expirydate = getexpirydate(  );											//Taking expiry date from class and placing it in Life structrue
   strcpy(LIFE.policytype, convertStringToChar(getpolicytype( ) ) );			//Taking policy type name from class and placing it in Life structrue
   LIFE.insurpremium = getinsurpremium( );										//Taking insurance premium from class and placing it in Life structrue

	//child Data
   strcpy(LIFE.firstname, convertStringToChar(getfirstname( ) ) );	//Taking first name Life from class and placing it in Life structrue
   strcpy(LIFE.lastname, convertStringToChar(getlastname( ) ) );	//Taking second name from class and placing it in Life structrue
   LIFE.AgeInsurPer = getAgeInsurPer( );							//Taking age from class and placing it in Life structrue
   strcpy(LIFE.firstaddress, convertStringToChar(getfirstaddress( ) ) );	//Taking first address from class and placing it in Life structrue
   strcpy(LIFE.secaddress, convertStringToChar(getsecaddress( ) ) );		//Taking second address from class and placing it in Life structrue
   strcpy(LIFE.occupation, convertStringToChar(getoccupation( ) ) );		//Taking Occupation class and placing it in Life structrue
   strcpy(LIFE.InsurAsmoker, convertStringToChar(getIsPerAsmoker(  ) ) );	//Taking smoker response from class and placing it in Life structrue
   strcpy(LIFE.ADDC, convertStringToChar(getaddc(  ) ) );					//Taking accident response from class and placing it in Life structrue
   LIFE.EstValPer = getestvalper(  );										//Taking estimates value from class and placing it in Life structrue



   FilFile.close();	//Closing Life File
   FilFile.open("LifeFile.txt", ios::in | ios::out | ios::binary);	//Reopening the Life File

   //Test if the file got opened
   if( !FilFile ) {
   	clrscr();
   	cout<<"\n\n\aThe FilFile pointer is not set!!!";
      getch();
   }//end if 
   else {  //else File didnt open
		//move file-position pointer to the correct record in file
	   FilFile.seekp( ( location - 1111 ) * sizeof( STRUCLife ) );

	   //insert record to file
	   FilFile.write( reinterpret_cast< const char*> ( &LIFE ), sizeof(STRUCLife ) );
   }//end else

}//end method write to Life File


/**
 * Read Life insurance policy from file
 * @
 */
void Lifeinsurpolicy::ReadLFile(fstream &FilFile, long location) //Send Life file and location to be read
{
	struct STRUCLife LIFE;	//Declare a structure of type Life
   string Holdstr;		//Declare a variable to temporarily hold a string

   //Test if the file got opened
   if( FilFile ) {
		//move file-position pointer to the correct record in file
	   FilFile.seekg( ( location - 1111 ) * sizeof( STRUCLife ) );

	   //insert record to file
	   FilFile.read( reinterpret_cast< char*> ( &LIFE ), sizeof(STRUCLife ) );
   }// end if 
   else {  //else File didnt open
   	clrscr();
   	cout<<"\n\n\aThe FilFile pointer is not set!!!";
      getch();
      return;
   }//end else

   if (LIFE.policyNum == 0 ) {	//If Policy number is equal to zero then return 
      return;
   }//end if

   /*parent*/

   setpolicyNum( LIFE.policyNum ); //Taking Life Policy Number and setting it inside Parent class

   Holdstr = LIFE.fnamepolholder;	//Assigns first name of policy holder to a temporary string
   setfnamepolholder( Holdstr );	//Passing the temporary string to  set policy holder method

   Holdstr = LIFE.lnamepolholder;	//Assigns last name of policy holder to a temporary string																				
   setlnamepolholder( Holdstr );	//Passing the temporary string to  set policy holder method

   seteffectivedate( LIFE.effectivedate );	//Taking Life effective date and setting it inside Parent class
   setexpirydate( LIFE.expirydate );		//Taking Life expiry date and setting it inside Parent class

   setpolicytype( );		//Set policy type

   /*child*/

   Holdstr = LIFE.firstname;		//Get first name from LIFE structure
   setfirstname( Holdstr );			//Set first name in child class

   Holdstr = LIFE.lastname;			//Get last name from LIFE structure
   setlastname( Holdstr );			//Set last name in child class

   setAgeInsurPer( LIFE.AgeInsurPer ); //Get person's age from LIFE structure and Set person's age in child class

   Holdstr = LIFE.firstaddress;		//Get first address from LIFE structure
	setfirstaddress( Holdstr );		//Set firstaddress in child class

   Holdstr = LIFE.secaddress;		//Get second address from LIFE structure
   setsecaddress( Holdstr );		//Set secaddress in child class

   Holdstr = LIFE.occupation;		//Get Occupation from LIFE structure		
   setoccupation( Holdstr );		//Set Occupation in child class

   Holdstr = LIFE.InsurAsmoker;		//Get smoker response from LIFE structure
   setIsPerAsmoker( Holdstr );		//Set smoker response in child class

   Holdstr = LIFE.ADDC;				//Get accident response from LIFE structure
   setaddc( Holdstr );				//Set accident response in child class

   setestvalper( LIFE.EstValPer );	//Get and Set policy type in the child class
   setinsurpremium(  );			//Get and Set insurance premium in the child class

}//end ReadLFile


/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Delete Life insurance policy to file
 * @
 */
void Lifeinsurpolicy::DeleteLife( fstream &FilFile )
{
   struct STRUCLife LIFE;	//Declare structure of type Life
   long location;			//Declare variable location
   Date effdate;			//Declare object to store Effective Date
   Date expdate;			//Declare object to store Expiry Date
   string res;				//Declare variable to store user response


	ThemeStyle1( ); //create screen theme

   system("color 9F");  //Set program color

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 46 );	//Set text color
   gotoxy( 25, 2);     cout<<"] Delete Life Insurance Policy [";		//Displays the Header

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 159 ); //Set text color
   
   /**
    * Populate the Base class
    */

   gotoxy(3, 5); cout<<"Please enter Policy Number: ";	//prompt user for policy number
   location = Longinput(31, 5, 4);			//get policy number

   //Set position to read from file
   FilFile.seekg((location - 1111) * sizeof(STRUCLife));
   //Read from location
   FilFile.read(reinterpret_cast <char *> (&LIFE), sizeof(STRUCLife));

   //Test if the location is the same as the policy number
   if (location != LIFE.policyNum){

     	gotoxy( 3, 6); cout<<"\aSorry! But that policy number is not in the database!!!";

  	   gotoxy( 25, 9); system("PAUSE");
      return;

   }//endif

   naviHelp( ); //display navigation help

   //read file from location
	ReadLFile(FilFile, location);

   effdate = geteffectivedate(  );  //Get Effective Date from class and assign it to the variable effdate
   expdate = getexpirydate(  );		//Get Expiry Date from class and assign it to the variable expdate

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
	
   //Go to location and display Insurer's First Name
   gotoxy(3, 10);    cout<<"Insurer's First Name ---: [                  ]";
   gotoxy(30 , 10);  cout<<getfirstname(  );
	
   //Go to location and display Insurer's Last Name
   gotoxy(3, 11);    cout<<"Insurer's Last Name ----: [                  ]";
   gotoxy(30 , 11);  cout<<getlastname(  );
	
   //Go to location and display Insurer's Age
   gotoxy(3, 12);    cout<<"Insurer's Age ----------: [   ]";
   gotoxy(30, 12);   cout<<getAgeInsurPer(  );

   //Go to location and display First Address
	gotoxy(3, 13);    cout<<"First Address ----------: [                             ]";
   gotoxy(30 , 13);  cout<<getfirstaddress(  );

   //Go to location and display Second Address
   gotoxy(3, 14);    cout<<"Second Address ---------: [                             ]";
   gotoxy(30 , 14);  cout<<getsecaddress(  );

   //Go to location and display occupation
   gotoxy(3, 15);    cout<<"Person's occupation ----: [                             ]";
   gotoxy(30 , 15);  cout<<getoccupation(  );

   //Go to location and display smoker response
   gotoxy(3, 16);    cout<<"Is the person a smoker?              [   ]";
   gotoxy(41 , 16);  cout<<getIsPerAsmoker(  );

   //Go to location and display accidential response
   gotoxy(3, 17);    cout<<"Is accidential death and dismemberment coverage required?       [   ]";
   gotoxy(68 , 17);  cout<<getaddc(  );

   //Go to location and display Estimated value
   gotoxy(3, 18);    cout<<"Estimated value of person insured: [$               ]";   gotoxy(40, 18);   cout<<getestvalper(  );
   //Go to location and display getinsurpremium   gotoxy(3, 19);    cout<<"The Insurance Premium is --------: [$               ]";   gotoxy(40, 19);   cout<<getinsurpremium( );

   gotoxy(15, 21); //goto location   cout<<"\"If This is correct choose 'Yes' to delete: Yes[ ] No[ ]\""; //Prompt user to confirm delete

   res = YesNo(63, 21);	//Store user response

   if (res.compare("Yes") == 0) {    //If the response is yes

   	//Copy a blank Object the life object
   	struct STRUCLife LIFE;
      LIFE.policyNum = 0;

      //Overwrite the life object in the file to blank
      FilFile.seekp( (location - 1111) * sizeof(STRUCLife) );
      FilFile.write(reinterpret_cast<const char*> (&LIFE), sizeof(STRUCLife) );

   } //end if

}//end method DeleteLife

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * View a person's life insurance policy.
 */
int Lifeinsurpolicy::ViewLife( fstream &FilFile )
{
   struct STRUCLife LIFE;  //Declare structure of type Life
   long location;	//Declare variable location


	ThemeStyle1( ); //create screen theme

   system("color 9F"); //Set program color 

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 46 );	//Set text color
   gotoxy( 25, 2);     cout<<"] View Life Insurance Policy [";			//Displays the Header

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 159 );	//Set text color
   /**
    * Populate the Base class
    */

   gotoxy(3, 5); cout<<"Please enter Policy Number: ";	//prompt user to enter data
   location = Longinput(31, 5, 4);			//get location

   FilFile.close(); //close Life file
   FilFile.open("LifeFile.txt", ios::in | ios::out | ios::binary); //reopen file

   //Set position to read from file
   FilFile.seekg((location - 1111) * sizeof(STRUCLife));
   //Read from location
   FilFile.read(reinterpret_cast <char *> (&LIFE), sizeof(STRUCLife));

   //Test if the location is the same as the policy number
   if (location != LIFE.policyNum){

     	gotoxy( 3, 6); cout<<"\aSorry! But that policy number is not in the database!!!"; //Go to location and out the message
      return 0;

   }//endif

   //read file from location
	ReadLFile(FilFile, location);

	return 1;
}


//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Edit a person's life insurance policy.
 */
void Lifeinsurpolicy::EditPolicy( fstream &FilFile )
{
   struct STRUCLife LIFE;	//Declare structure of type Life
   long location;			//Declare variable location
   
   string fname;			// Declare First name as string
   string lname;			// Declare Last name as string
   Date effdate;			// Declare object to store Effective Date 
   Date expdate;			// Declare object to store Expiry Date	
   int day, month, year;	// Declare day, month and year as integers 
   /**/
	int ageper;				// Declare variable for age
   string faddress;			// Declare variable for first address
   string saddress;			// Declare variable for second address
   string occup;			// Declare variable for occupation
   string smoker;			// Declare variable for smoker
   string Accdc;			// Declare variable for accident response
   double value;			// Declare variable for double values


	ThemeStyle1( ); //create screen theme

   system("color 9F");	//Set program color 

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 46 );	//Set text color
   gotoxy( 27, 2);     cout<<"] Edit Life Insurance Policy [";			//Displays the Header
	
   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 159 ); //Set text color
   /**
    * Populate the Base class
    */

   gotoxy(3, 5); cout<<"Please enter Policy Number: ";	//Go to location and Prompt user to enter policy number
   location = Longinput(31, 5, 4);						//Store policy number in location

   fstream FFile;	//declare a object file for Life
   FFile.open ("LifeFile.txt", ios::in | ios::out | ios::binary ); //reopen the file

   //Set position to read from file
   FFile.seekg((location - 1111) * sizeof(STRUCLife));
   //Read from location
   FFile.read(reinterpret_cast <char *> (&LIFE), sizeof(STRUCLife));

   //Test if the location is the same as the policy number
   if (location != LIFE.policyNum){

     	gotoxy( 3, 6); cout<<"\aSorry! But that policy number is not in the database!!!";

  	   gotoxy( 25, 9); system("PAUSE");
      return;

   }//endif

   //read file from location
	ReadLFile(FilFile, location);

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

	//Go to location and display Insurer's First Name	
   gotoxy(3, 10);    cout<<"Insurer's First Name ---: [                  ]";
   gotoxy(30 , 10);  cout<<getfirstname(  );

	//Go to location and display Insurer's Last Name
   gotoxy(3, 11);    cout<<"Insurer's Last Name ----: [                  ]";
   gotoxy(30 , 11);  cout<<getlastname(  );

	//Go to location and display Insurer's Age
   gotoxy(3, 12);    cout<<"Insurer's Age ----------: [   ]";
   gotoxy(30, 12);   cout<<getAgeInsurPer(  );

   //Go to location and display First Address
	gotoxy(3, 13);    cout<<"First Address ----------: [                             ]";
   gotoxy(30 , 13);  cout<<getfirstaddress(  );

   //Go to location and display Second Address
   gotoxy(3, 14);    cout<<"Second Address ---------: [                             ]";
   gotoxy(30 , 14);  cout<<getsecaddress(  );

   //Go to location and display occupation
   gotoxy(3, 15);    cout<<"Person's occupation ----: [                             ]";
   gotoxy(30 , 15);  cout<<getoccupation(  );

   //Go to location and display smoker response
   gotoxy(3, 16);    cout<<"Is the person a smoker?              [   ]";
   gotoxy(41 , 16);  cout<<getIsPerAsmoker(  );

	//Go to location and display accidential response
   gotoxy(3, 17);    cout<<"Is accidential death and dismemberment coverage required?       [   ]";
   gotoxy(68 , 17);  cout<<getaddc(  );

	//Go to location and display Estimated value
   gotoxy(3, 18);    cout<<"Estimated value of person insured: [$               ]";   gotoxy(40, 18);   cout<<getestvalper(  );

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

   gotoxy(2,6);   cout<<"\335";		//scroll bar

   gotoxy(3,22); cout<<"-->"<<setw(2)<<count; //display count

   input = getch();		// get user input

   //do condition while the you doesn't press END
   while ( input != 0x4f ) {

   	//navigate up if the up or left arrow key is pressed
      if (input == 0x48 || input == 0x4b ) {

         gotoxy( 2, y_axis); cout<<" "; //goto location and display blank
      	count--;			//decrement count

		//if count is zero
         if (count == 0 ) {
            count = 1;	//initialize count to 1
            y_axis = 6;	// set y-axis to 6
            gotoxy( 2, y_axis); cout<<"\335";	//goto location and display
         }//end if 
         else {
         	y_axis--;
         	gotoxy( 2, y_axis); cout<<"\335";	//goto location and display
         }//end else

      }//end if
   	//navigate down if the down or right arrow key is pressed
      if (input == 0x50 || input == 0x4d ) {

      	gotoxy(2, y_axis); cout<<" ";	//goto location and display blank
         count++;			//increment count
			
		 //if count is 14
         if (count == 14 ) {
            count = 13;		//initialize count to 13
            y_axis = 18;	// set y-axis to 18	
            gotoxy( 2, y_axis); cout<<"\335";	//goto location and display
         }//end if
         else {
         	y_axis++;  //increment y-axis
         	gotoxy( 2, y_axis); cout<<"\335";	//goto location and display
         }//end else
      }//end if

      gotoxy(3,22); cout<<"-->"<<setw(2)<<count; //display count

      //if the user press enter
      if ( input == 0x0d) {

         gotoxy( 47, 24); cout<<"\376"; //goto location xy and show that edit mode is on
         gotoxy( 52, 24); cout<<" ";    //goto location xy and show that edit mode is off
         gotoxy( 24, 24); cout<<" ";    //goto location xy and show empty space for Yes
         gotoxy( 29, 24); cout<<"\376"; //goto location xy and show that its currently not saved
         switch ( count ) {

   			/**
             * Edit the Base class
             */
         	case 1:  //if case 1
				// goto location and redisplay the following blank
				gotoxy(3, 6);   cout<<"Policy Holder First Name: [                  ]";
				
				fname = STinGinput(30 , 6, 18);		//Gets string input from user and assigns it to fname
   				setfnamepolholder( fname );			//Set Policy Holder First Name in Base class
               break;

            case 2:  //if case 2
				// goto location and redisplay the following blank
   				gotoxy(3, 7);   cout<<"Policy Holder Last Name : [                  ]";
 				
				lname = STinGinput(30 , 7, 18);			//Gets string input from user and assigns it to lname		
				setlnamepolholder( lname );				//Set Policy Holder Last Name in Base class
               break;

            case 3:  //if case 3
				// goto location and redisplay the following blank
   				gotoxy(3, 8);   cout<<"Effective Date ---------: [D:    M:    Y:    ]";
				
				day = Intinput(32, 8, 2);   month = Intinput(38, 8, 2);   year = Intinput(44, 8, 4);    //Get day, month and year from user
   				effdate.setDay(day);        effdate.setMonth(month);      effdate.setYear(year);		//Initialize day, month and year in Effdate
   				seteffectivedate( effdate );															//Set Effective Date in Base Class
               break;

            case 4:  //if case 4
				// goto location and redisplay the following blank
   				gotoxy(3, 9);   cout<<"Expiry Date ------------: [D:    M:    Y:    ]";
				
				day = Intinput(32, 9, 2);   month = Intinput(38, 9, 2);   year = Intinput(44, 9, 4);	//Get day, month and year from user
  				expdate.setDay(day);        expdate.setMonth(month);      expdate.setYear(year);		//Initialize day, month and year in Expdate
   				setexpirydate( expdate );																//Set Expiry Date in Base Class
               break;

   			/**
             * Edit the Base child class
             */
   			case 5:  //if case 5
				// goto location and redisplay the following blank
   				gotoxy(3, 10);    cout<<"Insurer's First Name ---: [                  ]";
				
				fname = STinGinput(30 , 10, 18);		//Get first name from user
   				setfirstname( fname );					//Set first name in child class
               break;

            case 6:  //if case 6
				// goto location and redisplay the following blank
   				gotoxy(3, 11);    cout<<"Insurer's Last Name ----: [                  ]";
				lname = STinGinput(30 , 11, 18);		//Get last name from user
   				setlastname( lname );					//Set last name in child class	
               break;

            case 7:  //if case 7
				// goto location and redisplay the following blank
   				gotoxy(3, 12);    cout<<"Insurer's Age ----------: [   ]";
				ageper = Intinput(30, 12, 3);		//Get person's age from the user 
				setAgeInsurPer( ageper );			//Set person's age in child class
               break;

            case 8:  //if case 8
				gotoxy(3, 13);    cout<<"First Address ----------: [                             ]";
				faddress = STinGinput2(30 , 13, 29);	//Get first address from user
				setfirstaddress( faddress );			//Set firstaddress in child class
               break;

            case 9:  //if case 9
				// goto location and redisplay the following blank
   				gotoxy(3, 14);    cout<<"Second Address ---------: [                             ]";
   				saddress = STinGinput2(30 , 14, 29);	//Get Occupation from user 
   				setsecaddress( saddress );				//Set Occupation in child class
               break;

            case 10:  //if case 10
				// goto location and redisplay the following blank
   				gotoxy(3, 15);    cout<<"Person's occupation ----: [                             ]";
	   			occup = STinGinput(30 , 15, 29);		//Get smoker response from user
   				setoccupation( occup );					//Set smoker response in child class
               break;	

            case 11:  //if case 11
				// goto location and redisplay the following blank
   				gotoxy(3, 16);    cout<<"Is the person a smoker?           Yes[ ] No[ ]";
	   			
				smoker = YesNo(41 , 16);		//Get smoker response from user	
   				setIsPerAsmoker( smoker );		//Set smoker response in child class
               break;

            case 12:  //if case 12
				// goto location and redisplay the following blank
   				gotoxy(3, 17);    cout<<"Is accidential death and dismemberment coverage required?    Yes[ ] No[ ]";
	   			
				Accdc = YesNo(68 , 17);			//Get accident response from user
   				setaddc( Accdc );				//Set accident response in child class
               break;

            case 13:  //if case 13
				// goto location and redisplay the following blank
   				gotoxy(3, 18); cout<<"Estimated value of person insured: [$               ]";		   						value = Doubleinput(40, 18, 16);	//Get setestvalper from user   				setestvalper( value );				//Set setestvalper in child class
               break;

         }//end switch

         gotoxy( 47, 24); cout<<" ";     //goto location xy and show empty space
         gotoxy( 52, 24); cout<<"\376";  //goto location xy and show that edit mode is off

      }//end if

      if ( input == 0x3b)  {  // F1 to Save to file
       	WriteToLFile(FilFile, location );
         gotoxy( 29, 24); cout<<" ";    //goto location xy and show empty space
         gotoxy( 24, 24); cout<<"\376"; //goto location xy and show that its currently saved
      }//end if

      input = getch(); //ge input again from keyboard
   }// end while

}// end function edit

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Display person's life insurance policy.
 */
void Lifeinsurpolicy::Display( ) {
   
	// display Person's first name.
   gotoxy(3, 10);    cout<<"Insurer's First Name ---: ["<<firstname<<" ]";
	// display Person's last name.
   gotoxy(3, 11);    cout<<"Insurer's Last Name ----: ["<<lastname<<" ]";
	// display Insured Person's age.
   gotoxy(3, 12);    cout<<"Insurer's Age ----------: ["<<AgeInsurPer<<" ]";
	// display First Address.
   gotoxy(3, 13);    cout<<"First Address ----------: ["<<firstaddress<<" ]";
	// display 2nd address.
   gotoxy(3, 14);    cout<<"Second Address ---------: ["<<secaddress<<" ]";
	// display Person's occupation.
   gotoxy(3, 15);    cout<<"Person's occupation ----: ["<<occupation<<" ]";
	// display Is the person a smoker?
   gotoxy(3, 16);    cout<<"Is the person a smoker?              ["<<InsurAsmoker<<" ]";
	// display Is accidential death and dismemberment coverage required?
   gotoxy(3, 17); cout<<"Is accidential death and dismemberment coverage required?       ["<<ADDC<<" ]";
	// display Estimated value of the person insured.
   gotoxy(3, 18); cout<<"Estimated value of person insured: [$"<<EstValPer<<" ]";

}



