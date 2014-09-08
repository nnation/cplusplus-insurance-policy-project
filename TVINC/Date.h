/*################################################<
>>> *Authors: Nathaniel Nation                  <<<
>>>                                             <<<
>>> Lecture/Tutor: Mr. David White              <<<
***************************************************/

#ifndef DATE_H
#define DATE_H

//using namespace std;

/**
  * class Date
  * A class that stores the date for the polices.
  */

class Date{

private:

	// Static Private attributes
	//

	// Private attributes
	//

	// The day.
	int day;
	// The month
	int month;
	// The  year
	int year;

public:

	// Constructors/Destructors
	//

	/**
	 *Constructor
	 */
	Date( );

	/**
	 *Destructor
	 */
	virtual ~Date( );

	/**
	 * <<primary constructor>>
	 * @param  _thisd
	 */
	 Date(Date &thisd );

	/**
	 * <<primary constructor>>
	 * @param  d The day coming in.
	 * @param  m The month coming in.
	 * @param  y The year coming in.
	 */
	 Date (int d, int m, int y );

   //
   //Mutator Methods
   //

	/**
	 * The day to be set.
	 * @param  d The day to be set.
	 */
	void setDay(int d );

	/**
	 * The month to be set.
	 * @param  m The month to be set.
	 */
	void setMonth (int m );

	/**
	 * The year to be set.
	 * @param  y The year to be set.
	 */
	void setYear(int y );

   //
   //Accessor Methods
   //

	/**
	 * Retrive day.
	 * @return int
	 */
	int getDay( ) const;

	/**
	 * Retrive month.
	 * @return int
	 */
	int getMonth( ) const;

	/**
	 * Retrive year
	 * @return int
	 */
	int getYear( ) const;

	/**
	 * Display the contents of the Date class.
	 */
	void Datedisplay( );

};

#endif // DATE_H
