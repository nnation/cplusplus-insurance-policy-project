/*################################################<
>>> *Authors: Nathaniel Nation                  <<<
>>>                                             <<<
>>> Lecture/Tutor: Mr. David White              <<<
***************************************************/

#include "Insurpolicy.h"
#include "Date.h"
#include <cstring>
#include <iostream>
#include <conio.h>

// Constructors/Destructors
//

Insurpolicy::Insurpolicy( )
:
  // Store the client effective date.
  expirydate(0,0,0),
  // Store the client policy expiry date.
  effectivedate(0,0,0)
{
	// Store the client policy number.
	policyNum = 0;
	// Store the client's premium.
	insurpremium = 0;
	// Store the client first name.
	fnamepolholder = " ";
	// Store the client last name.
	lnamepolholder = " ";
	// Store the client policy type.
	policytype = " ";

	polcount++;
}

Insurpolicy::~Insurpolicy( ) {
	polcount--;
}

/**
* initailize static variable .
* @set it to 0
*/
int Insurpolicy::polcount = 0;

//
// Mutator Methods
//

/**
 * Set the value of policyNum
 * Store the client policy number.
 * @param polNum the new value of policyNum
 */
void Insurpolicy::setpolicyNum( long polNum )	 {
	policyNum = polNum;
}

/**
 * Set the value of fnamepolholder
 * Store the client first name.
 * @param fname the new value of fnamepolholder
 */
void Insurpolicy::setfnamepolholder( string fname )	 {
	fnamepolholder = fname;
}

/**
 * Set the value of lnamepolholder
 * Store the client last name.
 * @param lname the new value of lnamepolholder
 */
void Insurpolicy::setlnamepolholder( string lname )	 {
		lnamepolholder = lname;
}

/**
 * Set the value of effectivedate
 * Store the client effective date.
 * @param effdate the new value of effectivedate
 */
void Insurpolicy::seteffectivedate( Date &effdate )	 {
		effectivedate = effdate;
}

/**
 * Set the value of expirydate
 * Store the client policy expiry date.
 * @param expdate the new value of expirydate
 */
void Insurpolicy::setexpirydate( Date &expdate ) {
		expirydate = expdate;
}

//
// Accessor Methods
//

/**
 * Get the value of polcount
 * Store the number of policies on the system.
 * @return the value of polcount
 */
int Insurpolicy::getpolcount( ) {
	return polcount;
}

/**
 * Get the value of policyNum
 * Store the client policy number.
 * @return the value of policyNum
 */
long Insurpolicy::getpolicyNum( ) const{
	return policyNum;
}

/**
 * Get the value of fnamepolholder
 * Store the client first name.
 * @return the value of fnamepolholder
 */
string Insurpolicy::getfnamepolholder( ) const{
	return fnamepolholder;
}

/**
 * Get the value of lnamepolholder
 * Store the client last name.
 * @return the value of lnamepolholder
 */
string Insurpolicy::getlnamepolholder( ) const{
	return lnamepolholder;
}

/**
 * Get the value of effectivedate
 * Store the client effective date.
 * @return the value of effectivedate
 */
Date Insurpolicy::geteffectivedate( ) {
	return effectivedate;
}

/**
 * Get the value of expirydate
 * Store the client policy expiry date.
 * @return the value of expirydate
 */
Date Insurpolicy::getexpirydate( ) {
	return expirydate;
}


/**
 * Display parent class policy details.
 */
void Insurpolicy::Display( ){

   system("color 9F");

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 46 );
   // Display the client policy type.
   gotoxy(23, 2); cout<<"] "<<policytype<<" [";

   SetConsoleTextAttribute ( GetStdHandle ( STD_OUTPUT_HANDLE ) , 159 );

	// Display the client policy number.
   gotoxy(3, 4); cout<<"Policy Number: "<<policyNum;

	// Display the client first name.
   gotoxy(3, 5); cout<<"Policy Holder First Name: ["<<fnamepolholder<<" ]";

	// Display the client last name.
	gotoxy(3, 6); cout<<"Policy Holder Last Name : ["<<lnamepolholder<<" ]";

   // Display the client effective date.
   gotoxy(3, 7); cout<<"Effective Date ---------: [D:"<<effectivedate.getDay( )<<" M:"<<effectivedate.getMonth( )<<" Y:"<<effectivedate.getYear( )<<" ]";

   // Display the client policy expiry date.
   gotoxy(3, 8); cout<<"Expiry Date ------------: [D:"<<expirydate.getDay( )<<" M:"<<expirydate.getMonth( )<<" Y:"<<expirydate.getYear( )<<" ]";

	// Display the client's premium.
   gotoxy(3, 9); cout<<"The Insurance Premium is : [$"<<insurpremium<<" ]";

}

