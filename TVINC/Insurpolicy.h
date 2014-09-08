/*################################################<
>>> *Authors: Nathaniel Nation                  <<<
>>>                                             <<<
>>> Lecture/Tutor: Mr. David White              <<<
***************************************************/

#ifndef INSURPOLICY_H
#define INSURPOLICY_H

#include <cstring>
#include "Date.h"


/**
  * class Insurpolicy
  * This is the parent/base class policy of policies Life insurance, Home insurance
  * and Motor Vehicle insurance.
  */

class Insurpolicy {

private:

	// Static Private attributes
	//

	// Store the number of policies on the system.
	static int polcount;
	// Private attributes
	//

	// Store the client policy number.
	long policyNum;
	// Store the client first name.
	string fnamepolholder;
	// Store the client last name.
	string lnamepolholder;
	// Store the client effective date.
	Date effectivedate;
	// Store the client policy expiry date.
	Date expirydate;

protected:
	// Store the client policy type.
	string policytype;
	// Store the client's premium.
	double insurpremium;

public:

	// Constructors/Destructors
	//

	/**
	 *Constructor
	 */
	Insurpolicy( );

	/**
	 *Destructor
	 */
	virtual ~Insurpolicy( );

	/**
	 * Set policy number.
	 * @param  polNum Incoming policy Number
	 */
	void setpolicyNum(long polNum );

	/**
	 * Set policy holder first name.
	 * @param  fname Incoming policy holder first name
	 */
	void setfnamepolholder(string fname );

	/**
	 * Set policy holder last name.
	 * @param  lname Incoming policy holder last name
	 */
	void setlnamepolholder(string lname );

	/**
	 * Pure virtual method that should set the policy type.
	 *
	 */
	virtual void setpolicytype( void ) = 0;

	/**
	 * Set policy effective date.
	 * @param  _effdate Incoming policy effective date.
	 */
	void seteffectivedate(Date &effdate );

	/**
	 * Set policy expiry date.
	 * @param  _expdate Incoming policy expiry date.
	 */
	void setexpirydate(Date &expdate );

	/**
	 * Pure virtual function that should set policy insurance premium.
	 *
	 */
	virtual void setinsurpremium( void ) = 0;

	/**
	 * Get policy number.
	 * @return long
	 */
	long getpolicyNum( ) const;

	/**
	 * Get policy holder first name.
	 * @return string
	 */
	string getfnamepolholder( ) const;

	/**
	 * Get policy holder last name.
	 * @return string
	 */
	string getlnamepolholder( ) const;

	/**
	 * Get policy effective date.
	 * @return Date
	 */
	Date geteffectivedate( );

	/**
	 * Get policy expiry day.
	 * @return Date
	 */
	Date getexpirydate( );

	/**
	 * Get total number of policies .
	 * @return int
	 */
	static int getpolcount( );


	/**
	 * Display parent class policy details.
	 */
	virtual void Display( );

};

#endif // INSURPOLICY_H
