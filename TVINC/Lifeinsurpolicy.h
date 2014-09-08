/*################################################<
>>> *Authors: Nathaniel Nation                  <<<
>>>                                             <<<
>>> Lecture/Tutor: Mr. David White              <<<
***************************************************/

#ifndef LIFEINSURPOLICY_H
#define LIFEINSURPOLICY_H
#include "Insurpolicy.h"
#include <fstream>

#include <cstring>


struct STRUCLife {

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


	// Person's first name.
	char firstname[19];
	// Person's last name.
	char lastname[19];
	// Insured Person's age.
	int AgeInsurPer;
	// First Address.
	char firstaddress[30];
	// 2nd address.
	char secaddress[30];
	// Person's occupation.
	char occupation[30];
	// Is the person a smoker?
	char InsurAsmoker[4];
	// Is accidential death and dismemberment coverage required?
	char ADDC[4];
	// Estimated value of the person insured.
	double EstValPer;

};




/**
  * class Lifeinsurpolicy
  * A class that consist of all the people that have life insurance policy. Also a
  * derived/child class of Insurpolicy class.
  */

class Lifeinsurpolicy : public Insurpolicy
{
private:

	// Static Private attributes
	//

	// Private attributes
	//

	// Person's first name.
	string firstname;
	// Person's last name.
	string lastname;
	// Insured Person's age.
	int AgeInsurPer;
	// First Address.
	string firstaddress;
	// 2nd address.
	string secaddress;
	// Person's occupation.
	string occupation;
	// Is the person a smoker?
	string InsurAsmoker;
	// Is accidential death and dismemberment coverage required?
	string ADDC;
	// Estimated value of the person insured.
	double EstValPer;

public:

	// Constructors/Destructors
	//


	/**
	 * Constructor
	 */
	Lifeinsurpolicy ( );

	/**
	 * Destructor
	 */
	virtual ~Lifeinsurpolicy ( );

	//
	// Mutator methods
	//

	/**
	 * Set Person's first name.
	 * @param  fname Incoming first name.
	 */
	void setfirstname (string fname );


	/**
	 * set Person's last name.
	 * @param  lname Incoming last name.
	 */
	void setlastname (string lname );


	/**
	 * set Insured Person's age.
	 * @param  ageper Incoming person's age.
	 */
	void setAgeInsurPer (int ageper );


	/**
	 * set First Address.
	 * @param  faddress Incoming person's first addess.
	 */
	void setfirstaddress (string faddress );


	/**
	 * set 2nd address.
	 * @param  saddress Incoming person's 2nd address.
	 */
	void setsecaddress (string saddress );


	/**
	 * Set Person's occupation.
	 * @param  occup Incoming person's occupation.
	 */
	void setoccupation (string occup );


	/**
	 * Set Yes/No If the person a smoker?
	 * @param  smoker Incoming person's response for smoking.
	 */
	void setIsPerAsmoker (string smoker );


	/**
	 * Set Yes/No If accidential death and dismemberment coverage required?
	 * @param  Accdc Incoming person's response to "is accident death and dismemberment
	 * coverage."
	 */
	void setaddc (string Accdc );


	/**
	 * set Estimated value of the person insured.
	 * @param  value Incoming person's estimated value.
	 */
	void setestvalper (double value );


	/**
	 * set policy type to life insurance
	 * @param  poltype This is the incoming policy type
	 */
	void setpolicytype ( void );


	/**
	 * set insurance premium of person
	 *
	 */
	void setinsurpremium ( void );

	//
	// Accessor methods
	//

	/**
	 * Get Person's first name
	 * @return string
	 */
	string getfirstname ( ) const;

	/**
	 * Get Person's last name.
	 * @return string
	 */
	string getlastname ( ) const;

	/**
	 * Get Insured Person's age.
	 * @return int
	 */
	int getAgeInsurPer ( ) const;

	/**
	 * Get First Address.
	 * @return string
	 */
	string getfirstaddress ( ) const;

	/**
	 * Get 2nd address.
	 * @return string
	 */
	string getsecaddress ( ) const;

	/**
	 * Get Person's occupation.
	 * @return string
	 */
	string getoccupation ( ) const;

	/**
	 * Get Yes/No If the person a smoker?
	 * @return string
	 */
	string getIsPerAsmoker ( ) const;

	/**
	 * Get Yes/No If accidential death and dismemberment coverage required?
	 * @return string
	 */
	string getaddc ( ) const;

	/**
	 * Get Estimated value of the person insured.
	 * @return double
	 */
	double getestvalper ( ) const;

	/**
	 * Get policy type to life insurance
	 * @return string
	 */
	string getpolicytype ( ) const;

	/**
	 * Get insurance premium of person
	 * @return double
	 */
	double getinsurpremium ( ) const;

   //
   ///// Utility Methods
   //

   /**
	 * Add a Life insurance policy
	 * @
	 */
   void addPolicy(fstream &FilFile );

	/**
 	* Delete Life insurance policy to file
 	* @
 	*/
	void DeleteLife( fstream &FilFile );

	/**
 	* Write Life insurance policy to file
 	* @
 	*/
	void WriteToLFile(fstream &FilFile, long location );

	/**
 	* Read Life insurance policy from file
 	* @
 	*/
   void ReadLFile(fstream &FilFile, long location );

	/**
 	* View a person's life insurance policy.
 	*/
	int ViewLife( fstream &FilFile );

	/**
 	* Display Screen for Life insurance policy to file
 	* @
 	*/
	void AddLifeDisplayScreen( void );

   /**
 	* Edit a person's life insurance policy.
 	*/
	void Lifeinsurpolicy::EditPolicy( fstream &FilFile );

	/**
	 * Display person's life insurance policy.
	 */
	void Display ( );

};

#endif // LIFEINSURPOLICY_H
