#include<stdio.h>

#define TRUE    1
#define FALSE   0

// Array to store the number of days in each month
int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Array to store the names of the months
char *months[] =
{
	" ",
	"\n\n\n************ January ************",
	"\n\n\n************ February ***********",
	"\n\n\n************ March **************",
	"\n\n\n************ April **************",
	"\n\n\n************ May ****************",
	"\n\n\n************ June ***************",
	"\n\n\n************ July ***************",
	"\n\n\n************ August *************",
	"\n\n\n************ September **********",
	"\n\n\n************ October ************",
	"\n\n\n************ November ***********",
	"\n\n\n************ December ***********"
};

// Function to take input for the year
int inputyear(void)
{
	int year;
	printf("Please enter a year (example: 2023) => ");
	scanf("%d", &year);
	return year;
}

// Function to determine the day code for January 1st of a given year
int determinedaycode(int year)
{
	int daycode;
	int d1, d2, d3;
	
	d1 = (year - 1) / 4;
	d2 = (year - 1) / 100;
	d3 = (year - 1) / 400;
	daycode = (year + d1 - d2 + d3) % 7;
	return daycode;
}

// Function to determine if a year is a leap year and update the number of days in February accordingly
int determineleapyear(int year)
{
	if(year % 4 == FALSE && year % 100 != FALSE || year % 400 == FALSE)
	{
		days_in_month[2] = 29;
		return TRUE;
	}
	else
	{
		days_in_month[2] = 28;
		return FALSE;
	}
}

// Function to display the calendar for a given year and day code
void calendar(int year, int daycode)
{
	int month, day;
	for ( month = 1; month <= 12; month++ )
	{
		printf("%s", months[month]);
		printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );
		
		// Correct the position for the first date
		for ( day = 1; day <= 1 + daycode * 5; day++ )
		{
			printf(" ");
		}
		
		// Print all the dates for one month
		for ( day = 1; day <= days_in_month[month]; day++ )
		{
			printf("%2d", day );
			
			// Is day before Sat? Else start next line Sun.
			if ( ( day + daycode ) % 7 > 0 )
				printf("   " );
			else
				printf("\n " );
		}
		// Set position for next month
		daycode = ( daycode + days_in_month[month] ) % 7;
	}
}

// Main function
int main(void)
{
	int year, daycode, leapyear;
	
	// Input the year
	year = inputyear();
	
	// Determine the day code for January 1st of the given year
	daycode = determinedaycode(year);
	
	// Determine if it's a leap year and update the days in February
	determineleapyear(year);
	
	// Display the calendar for the given year and day code
	calendar(year, daycode);
	
	printf("\n");
}
