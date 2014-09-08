/*################################################<
>>> *Authors: Nathaniel Nation                  <<<
>>>                                             <<<
>>> Lecture/Tutor: Mr. David White              <<<
***************************************************/

#ifndef MVINSURPOLICY_H
#define MVINSURPOLICY_H
#include "Insurpolicy.h"
#include <fstream>
#include <cstring>


struct STRUCMotov {

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


	// This is the model of the vehicle.
	char vehiclemodel[19];
	// This is the make of the vehicle.
	char make[19];
	// This is the year of the vehicle.
	int year;
	// This is the license number of the vehicle.
	char licenseNum[19];
	// This is the chassis number of the vehicle.
	long chassisNum;
	// This is the estimated value of the vehicle.
	double estvalvehicle;
	// This is the fuel type of the vehicle.
	char fueltype[19];
	// This is the body type of the vehicle.
	char bodytype[19];
	// This is the CC Rating of the vehicle.
	double ccrating;
	// This is the seating capacity of the vehicle.
	int seatingcap;
	// This gives a yes or no response as to whether the vehicle has an accident during the last year.
	char involveacci[4];
	// This gives a yes or no response as to whether the vehicle has an alarm.
	char alarm[4];

};



/**
  * class MVinsurpolicy
  * The class that creates motor vehicle policies for clients and also a child class
  * or derived class of Insurance Policy.
  */

class MVinsurpolicy : public Insurpolicy
{

private:

	// Static Private attributes
	//

	// Private attributes
	//

	// This is the model of the vehicle.
	string vehiclemodel;
	// This is the make of the vehicle.
	string make;
	// This is the year of the vehicle.
	int year;
	// This is the license number of the vehicle.
	string licenseNum;
	// This is the chassis number of the vehicle.
	long chassisNum;
	// This is the estimated value of the vehicle.
	double estvalvehicle;
	// This is the fuel type of the vehicle.
	string fueltype;
	// This is the body type of the vehicle.
	string bodytype;
	// This is the CC Rating of the vehicle.
	double ccrating;
	// This is the seating capacity of the vehicle.
	int seatingcap;
	// This gives a yes or no response as to whether the vehicle has an accident during the last year.
	string involveacci;
	// This gives a yes or no response as to whether the vehicle has an alarm.
	string alarm;

public:

	// Constructors/Destructors
	//


	/**
	 * Constructor
	 */
	MVinsurpolicy ( );

	/**
	 * Destructor
	 */
	virtual ~MVinsurpolicy ( );

 	/**
	 * Set the model of the vehicle.
	 * @param  vmodel Incoming vehicle model
	 */
	void setvehiclemodel (string vmodel );

	/**
	 * Set the make of the vehicle.
	 * @param  mk Incoming make of vehicle
	 */
	void setmake (string mk );

	/**
	 * Set the year of the vehicle.
	 * @param  yr Incoming year of vehicle
	 */
	void setyear (int yr );

	/**
	 * Set the license number of the vehicle.
	 * @param  Lnum Incoming license number of vehicle
	 */
	void setlicenseNum (string Lnum );


	/**
	 * Set the chassis number of the vehicle.
	 * @param  cnum Incoming chassis number of vehicle
	 */
	void setchassisNum (long cnum );


	/**
	 * Set the estimated value of the vehicle.
	 * @param  evvehicle Incoming estimated value of vehicle
	 */
	void setestvalvehicle (double evvehicle );


	/**
	 * Set the fuel type of the vehicle.
	 * @param  fueltp Incoming fuel type of vehicle
	 */
	void setfueltype (string fueltp );


	/**
	 * Set the body type of the vehicle.
	 * @param  bodytp Incoming body type of vehicle
	 */
	void setbodytype (string bodytp );


	/**
	 * Set the CC Rating of the vehicle.
	 * @param  ccr Incoming CC Rating of vehicle
	 */
	void setccrating (double ccr );

   	/**
	 * Set the seating capacity of the vehicle.
	 * @param  seatcap Incoming seating capacity of vehicle
	 */
	void setseatingcap (int seatcap );


	/**
	 * Set response as to whether the vehicle has an accident during the last year.
	 * @param  involacci Incoming response to if the vehicle was involved in an
	 * accident
	 */
	void setinvolveacci (string involacci );


	/**
	 * Set response as to whether the vehicle has an alarm.
	 * @param  Balarm Incoming response to if a vechicle has a burgler alarm
	 */
	void setalarm (string Balarm );


	/**
	 * Set policy type to motor vehicle insurance
	 * @param  poltype Incoming string of policy type of vehicle
	 */
	void setpolicytype ( void );


	/**
	 * Set insurance premium of client
	 * @param  perofestval Incoming insurance premium of vehicle
	 */
	void setinsurpremium ( void );


	/**
	 * Get the model of the vehicle.
	 * @return string
	 */
	string getvehiclemodel ( ) const;


	/**
	 * Get the make of the vehicle.
	 * @return string
	 */
	string getmake ( ) const;

	/**
	 * Get the year of the vehicle.
	 * @return int
	 */
	int getyear ( ) const;

    /**
	 * Get the license number of the vehicle.
	 * @return long
	 */
	string getlicenseNum ( ) const;

	/**
	 * Get the chassis number of the vehicle.
	 * @return long
	 */
	long getchassisNum ( ) const;

	/**
	 * Get the estimated value of the vehicle.
	 * @return double
	 */
	double getestvalvehicle ( ) const;

	/**
	 * Get the fuel type of the vehicle.
	 * @return string
	 */
	string getfueltype ( ) const;


	/**
	 * Get the body type of the vehicle.
	 * @return string
	 */
	string getbodytype ( ) const;

	/**
	 * Get the CC Rating of the vehicle.
	 * @return double
	 */
	double getccrating ( ) const;

	/**
	 * Get the seating capacity of the vehicle.
	 * @return int
	 */
	int getseatingcap ( ) const;

	/**
	 * Get response as to whether the vehicle has an accident during the last year.
	 * @return string
	 */
	string getinvolveacci ( ) const;

	/**
	 * Get response as to whether the vehicle has an alarm.
	 * @return string
	 */
	string getalarm ( ) const;

	/**
	 * Get policy type to motor vehicle insurance
	 * @return string
	 */
	string getpolicytype ( ) const;

	/**
	 * Get insurance premium of client
	 * @return double
	 */
	double getinsurpremium ( ) const;


   //
   ///// Utility Methods
   //

   /**
	 * Add a Motor vehicle insurance policy
	 * @
	 */
   void addPolicy(fstream &MVFile );

	/**
 	* Delete Motor vehicle insurance policy to file
 	* @
 	*/
	void DeleteMotov( fstream &MVFile );

	/**
 	* Write Motor vehicle insurance policy to file
 	* @
 	*/
	void WriteToMVFile(fstream &MVFile, long location );

	/**
 	* Read Motor vehicle insurance policy from file
 	* @
 	*/
   void ReadMVFile(fstream &MVFile, long location );

	/**
 	* Display Screen for Motor vehicle insurance policy to file
 	* @
 	*/
	void AddMotovDisplayScreen( void );

	/**
 	 * View a person's Motor Vehicle insurance policy.
 	 */
	int ViewMotov( fstream &MVFile );

	/**
 	 * Edit a person's Motor Vehicle insurance policy.
 	 */
	void EditPolicy( fstream &MVFile );


   /**
	 * Display the contents of motor vehicle insurance policy
	 */
	void Display ( );

};

#endif // MVINSURPOLICY_H
