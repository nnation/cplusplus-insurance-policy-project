/*################################################<
>>> *Authors: Nathaniel Nation                  <<<
>>>                                             <<<
>>> Lecture/Tutor: Mr. David White              <<<
***************************************************/

#include "Date.h"
#include <iostream>

// Constructors/Destructors
//

Date::Date( ) {
   // The day
	day = 0;
	// The month
	month = 0;
	// The  year
	year = 0;
}

Date::~Date( ) { }

/**
* <<primary constructor>>
* @param  _thisd
*/
Date::Date(Date &thisd )
{
   // The day
	day = thisd.getDay();
	// The month
	month = thisd.getMonth();
	// The  year
	year = thisd.getYear();
}

/**
* <<primary constructor>>
* @param  d The day coming in.
* @param  m The month coming in.
* @param  y The year coming in.
*/
Date::Date(int d, int m, int y )
{
   // The day
	day = d;
	// The month
	month = m;
	// The  year
	year = y;
}

//
// Mutator Methods
//

/**
 * Set the value of day
 * The day.
 * @param new_var the new value of day
 */
void Date::setDay( int d )	 {
		day = d;
}

/**
 * Set the value of month
 * The month
 * @param new_var the new value of month
 */
void Date::setMonth( int m ) {
		month = m;
}

/**
 * Set the value of year
 * The  year
 * @param new_var the new value of year
 */
void Date::setYear( int y ) {
		year = y;
}

//
// Accessor Methods
//

/**
 * Get the value of day
 * The day.
 * @return the value of day
 */
int Date::getDay( ) const {
	return day;
}

/**
 * Get the value of month
 * The month
 * @return the value of month
 */
int Date::getMonth( ) const {
	return month;
}

/**
 * Get the value of year
 * The  year
 * @return the value of year
 */
int Date::getYear( ) const {
	return year;
}

/**
* Display the contents of the Date class.
*/
void Date::Datedisplay( ){
	cout<<day<<"/"<<month<<"/"<<year;
}

