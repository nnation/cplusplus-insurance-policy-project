/*################################################<
>>> *Authors: Nathaniel Nation                  <<<
>>>                                             <<<
>>> Lecture/Tutor: Mr. David White              <<<
***************************************************/

#ifndef HOMEINSURPOLICY_H
#define HOMEINSURPOLICY_H
#include "Insurpolicy.h"
#include <fstream>

#include <cstring>

struct STRUCHome {

	// Store the client policy number.
	long policyNum;
	// Store the client first name.
	char fnamepolholder[18];
	// Store the client last name.
	char lnamepolholder[18];
	// Store the client effective date.
	Date effectivedate;
	// Store the client policy expiry date.
	Date expirydate;
	// Store the client policy type.
	char policytype[32];
	// Store the client's premium.
	double insurpremium;


	// Estimated valve of home.
	double esthomeval;
	// First line of address.
	char firstlineadd[30];
	// Second line of Address.
	char seclineadd[30];
	// Type of roof on the house.
	char rooftype[30];
	// Is a burgler alarm install?
	char buralarm[4];
	// Is a fire alarm installed?
	char firealarm[4];

};


/**
  * class Homeinsurpolicy
  * Home insurance policy class consist of people with home insurance. This is also
  * a child class of Insurpolicy.
  */

class Homeinsurpolicy : public Insurpolicy
{

private:

	// Static Private attributes
	//

	// Private attributes
	//

	// Estimated valve of home.
	double esthomeval;
	// First line of address.
	string firstlineadd;
	// Second line of Address.
	string seclineadd;
	// Type of roof on the house.
	string rooftype;
	// Is a burgler alarm install?
	string buralarm;
	// Is a fire alarm installed?
	string firealarm;

public:

	// Constructors/Destructors
	//


	/**
	 * Constructor
	 */
	Homeinsurpolicy ( );

	/**
	 * Destructor
	 */
	virtual ~Homeinsurpolicy ( );

   //
   //Mutator Methods
   //

	/**
	 * Set estimated value of home.
	 * @param  Hvalue Income home cost.
	 */
	void setesthomeval (double Hvalue );

	/**
	 * Set first line of address.
	 * @param  fladd Incoming first address
	 */
	void setfirstlineadd (string fladd );

	/**
	 * Set second line of address.
	 * @param  sladd Incoming second address
	 */
	void setseclineadd (string sladd );

	/**
	 * Set roof type of the house.
	 * @param  rtype Incoming roof type.
	 */
	void setrooftype (string rtype );

	/**
	 * Set Yes/No if the home have a burgler alarm.
	 * @param  bAlarm Incoming reponse to burgler alarm
	 */
	void setburalarm (string bAlarm );

	/**
	 * Set Yes/No if the house have a fire alarm installed.
	 * @param  fAlarm Incoming reponse to fire alarm
	 */
	void setfirealarm (string fAlarm );

	/**
	 * Set policy type to "Home insurance policy."
	 *
	 */
	void setpolicytype ( void );

	/**
	 * Set the insurance premium value.
	 *
	 */
	void setinsurpremium ( void );

   //
   //Accessor Methods
   //

	/**
	 * Get estimated value of home.
	 * @return double
	 */
	double getesthomeval ( ) const;

	/**
	 * Get first line of address.
	 * @return string
	 */
	string getfirstlineadd ( ) const;

	/**
	 * Get second line of address.
	 * @return string
	 */
	string getseclineadd ( ) const;

	/**
	 * Get roof type of the house.
	 * @return string
	 */
	string getrooftype ( ) const;

	/**
	 * Get Yes/No if the home have a burgler alarm.
	 * @return string
	 */
	string getburalarm ( ) const;

	/**
	 * Get Yes/No if the house have a fire alarm installed.
	 * @return string
	 */
	string getfirealarm ( ) const;

   /**
	 * Get policy type "Home insurance policy."
	 * @return string
	 */
	string getpolicytype ( ) const;

	/**
	 * Get the insurance premium value.
	 * @return double
	 */
	double getinsurpremium ( ) const;

   //
   ///// Utility Methods
   //

   /**
	 * Add a Home insurance policy
	 * @
	 */
   void addPolicy(fstream &HomFile );

	/**
 	 * Delete Home insurance policy to file
 	 * @
 	 */
	void DeleteHome( fstream &HomFile );

	/**
 	 * Write Home insurance policy to file
 	 * @
 	 */
	void WriteToHFile(fstream &HomFile, long location );

	/**
 	 * Read Home insurance policy from file
 	 * @
 	 */
   void ReadHFile(fstream &HomFile, long location );

	/**
 	 * Display Screen for Home insurance policy to file
 	 * @
 	 */
	void AddHomeDisplayScreen( void );

	/**
 	 * View a person's Home insurance policy.
 	 */
	int ViewHome( fstream &HomFile );

	/**
    * Edit a person's home insurance policy.
    */
	void Homeinsurpolicy::EditPolicy( fstream &HomFile );



	/**
	 * Display the data the home insurance policy.
	 */
	void Display ( );

};

#endif // HOMEINSURPOLICY_H
