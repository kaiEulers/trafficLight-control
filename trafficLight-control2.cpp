/*==============  Proforma : EEET2250 Lab Test 3 OUSB class and traffic light state machine ============

File version: 2016_v01.0

PURPOSE:
This file is a proforma for the EEET2250 Lab Test 3: OUSB class and traffic light state machine operations with the OUSB board.
This file defines the assignment - there is no other documentation. You must extend this C++ program to cope with the functionality identified below.

In the labs you will given OUSB boards to practice on. However if you may also want to purchase one for $60, the details are available on Blackboard.


BACKGROUND:
The assignment will be a command line program that reads parameters from the command line and prints out a well defined result, and nothing else.
No additional keyboard user input should be required for the process.


GOAL:
You are to write a program that implements access to the OUSB board using classes ('B' command).
Your program will implement a traffic light software state machine ('R', 'Y', 'G' commands), using PORTB of the OUSB board to indicate the current traffic light state.
The program should perform error checking.



General info:
Use debug mode and a breakpoint at the return statement prior to program finish in main.

To avoid losing 10% follow the instructions below:

Rename your file NOW to lab3_1234567.cpp, where 1234567 is your student number.
Your filename MUST NEVER EVER contain any spaces.  _under_score_is_Fine.
Do not include the 's' in front of your student number.

You MUST run this file as part of a Project.

DO NOT use system wide pre-defined variables because systems differ
and what is defined in your system may not be be defined in another system.


SPECIFICATIONS:
OUSB CLASS: Your program must access the OUSB board using a class (including read from/write to PORTB).
Ensure that you have private class variables to store the current value of PORTB. Include appropriate accessor functions and functions to read from and write to PORTB.

Your program should accept the following command line parameters:
- 'B' command: 'B' is the first parameter and the optional second parameter is the number to write to PORTB.
Print the current value (only the numeric value) read from PORTB to the command line.

e.g., 	lab3_1234567.exe B    // Read from PORTB and write the number read from PORTB to the console screen
lab3_1234567.exe B 10 // Write 10 to PORTB and write the number 10 to the console screen


TRAFFIC LIGHT STATE MACHINE: Your program must use the OUSB class to implement a single traffic light state machine, where the command line parameters indicate
the starting state of the traffic light and the number of state transitions the program should run for.

The traffic light is composed of three lamps: Red, Yellow, and Green. The only lamp sequence possible is
Green-->Yellow-->Red (then back to Green and repeat). Only one lamp can be on at a time.

Ensure that you have private class variables to store the current state of the traffic light (either as a single state to represent all three lamps, or three lamp states).
Include appropriate accessor functions and functions to change the traffic light state in the class.

Use PORTB to indicate the current state of the traffic light. Assume that the red, yellow and green lamps are represented by the
following PORTB combinations (only the first two bits of PORTB are used):
- Red ON: turn on bit 0 only (bit 1 off)
- Yellow ON: turn on both bits 0 and 1
- Green ON: turn on bit 1 only (bit 0 off)

Your program should accept the following command line parameters:
- 'R', 'Y' or 'G': one letter only as the first parameter to indicate which state to start the traffic light in
- The second parameter is a number to indicate the number of state transitions to run the traffic light for (not including the initial starting state)

e.g.,	lab3_1234567 R 3 // Start the traffic light on Red and run for three transitions  i.e., R-->G-->Y-->R
lab3_1234567 Y 2 // Start the traffic light on Yellow and run for two transitions i.e., Y-->R-->G
lab3_1234567 G 5 // Start the traffic light on Green and run for five transitions i.e., G-->Y-->R-->G-->Y-->R

Upon completing all the state transitions, the program should print out the last value of PORTB (i.e., the current state of the traffic light) and exit.


Your program MUST use pipes to communicate with the OUSB board, system calls are NOT allowed:
system("ousb -r io portb 127");   // not allowed

System calls take longer and automatically echo the result to the command shell window. If you use system calls in your code it is likely the code will not work properly.
You will most likely lose all marks for this lab.

Therefore, you MUST use the code using pipes. See the code fragments given to you and explained in lectures and on Blackboard.
Code to access the OUSB board will be provided in the Lab Test.

You MUST close the pipe using '_pclose(<pipename>); ' after every 'fgets()' command in your loop. Before exiting your program
call '_pclose(<pipename>); ' one last time. Failure to not do this will result in your code being highly unreliable and you could lose a lot of marks.

************  IMPORTANT !!!  *********   IMPORTANT !!!   *******************************
***
***  IN LAB TEST 3 YOU WILL AUTOMATICALLY LOSE 20% OF YOUR MARK IF YOU
***  DO NOT HAVE MATCHING _popen(...) and _pclose(...) - this will be checked!!!
***
***  IN LAB TEST 3 YOU MUST IMPLEMENT A CLASS to access the OUSB board - this
***  will be checked - your maximum score will be capped at 40% if you do not use
***  an OUSB class!!!
***
************  IMPORTANT !!!  *********   IMPORTANT !!!   *******************************

About pipes and _popen:
http://www.cplusplus.com/forum/windows/1341/
http://www.cplusplus.com/forum/windows/10766/

------------------------------

OUSB OUTPUT FORMATS: AS FOR A COMMAND SHELL WINDOW.

The OUSB board outputs commands sent to it in a default format. You will be required to change the default setting.

Testple: if the command given is: "ousb.exe io portb 128"
The DEFAULT response from the OUSB board is: PORTB = 128     this is NOT what you should produce.

Your code should display ONLY the number 128
The method of how to make the OUSB board respond with just the number as output can easily be found out by:
1) opening a command window in Windows: START -> RUN -> "cmd"
2) typing 'ousb' on the command line. This will bring up a help menu
3) see the option for 'raw (decimal)' output.

If you use _popen and a file pipeline do not add EXTRA newlines, do not add extra blank
spaces or any other characters. Output must be as it would be for a standard command line window.

The only text in the command shell window should be:
- text returned from the OUSB board in response to your code or an error condition
- NO debug code should appear in the command shell window. This means: any of your debug comments must be turned off for the final submitted copy.

------------------------------

ERRORS:
The following text lists errors you must detect and a priority of testing.  NB: order of testing is important. All outputs are a single character followed by a
newline ( endl or \n).

DO NOT add more than what is specified, do NOT add additional information, simply and only the output as required.

DO NOT use 'cin', do NOT ask for user input. All input MUST be read in from the command line and from file.

The closing } of the main statement must be the last closing brace in the file. The last line containing "main()" must be the main statement where execution is started.
In other words: ALL your functions MUST be between the start of the file and the
int main(int argc, char *argv[]) function. Do NOT put any functions after the main function, if you use functions add them BEFORE the 'main' function

You should use the Integrated debugging environment. In the lab tests the command line window will not be available.

When your code exits the 'main' function using the 'return' command then you MUST use zero as the return value. This requirement is for exiting the 'main' function ONLY.


ERROR CHECK 1:   NUMBER OF PARAMETERS
NB: the name of the program counts as the 1st parameter (0th value in the array).

If the number of parameters is 1: the program MUST print student ID string in CSV format and then exit. That is, when the
program is run without any operands i.e. simply the name of the executable such as:
lab3_1234567.exe

the program MUST print student ID string in Comma Separated Values (CSV)
format, Testple:
"studentNumber,student_email,student_name"
eg: "1234567,s1234567@student.rmit.edu.au,FirstName_LastName"
There are three fields in CSV strings: student number, email, name.
You need to output all THREE, separated by commas.

If the number of parameters is 2-3: the second parameter can only be 'B', 'R', 'Y' or 'G'. For any other letter, the output shall be 'I' which signals an input parameter
error and then exit.

If a number is not entered as the third parameter as required for all commands but 'B', the output shall be 'N' which signals a numerical parameter error and then exit.

That is, following the program name, the command line can take two or three parameters only:
ProgramName.exe  Operand1 Operand2
Testples:
lab3_1234567.exe B 128
lab3_1234567.exe B
lab3_1234567.exe R 16
lab3_1234567.exe Y 5
lab3_1234567.exe G 21

If the number of parameters is 4 or more: the output shall be 'P' which signals a parameter error and then exit.


ERROR CHECK 2:   VALID NUMBER RANGE
If the number entered as the third parameter on the command line is not within an accepted range or they are not numerical characters, then the  output shall be 'Y' and then exit. The accepted number ranges are:
- 'B' command: the number entered must be between 0 and 255 (inclusive)
- 'R', 'Y' or 'G' commands: the number entered must be between 0 and 50 (inclusive)


ERROR CHECK 3:   ANYTHING ELSE THAT CAN GO WRONG (MURPHY'S LAW TEST)
If there are any other kinds of errors not covered here, the output shall be 'Z'. That is:  anything else that can possibly go wrong and has not be explicitly tested for
or covered under the tests above, for Testple:
- no connection,                 (This will not be tested for by the auto-tester)
- disconnection during operation (This will not be tested for by the auto-tester)
- HW dead.
- ???? anything else Murphy can dream up.
- everything that has not been covered elsewhere is Murphy's domain.

Note: The OUSB.exe will give a message "Fatal Exception" if the board is not connected or is disconnected during normal operation. This message should NOT be returned by
your code. The only output your code should give is the single character: 'Z'

However: Murphy's laws are hard to test for. Very hard to test for with autotester.

Suggestion: only worry about this test if you have clearly covered ALL preceding tests !

Common error: Zero and the capital letter 'O' may look the same/similar but are not the same in ASCII.

ERROR CHECKING: The basic programming rules are simple (as covered in lectures):
1) check that the input is valid.
2) check that the output is valid.
3) if any library function returns an error code USE IT !!! CHECK FOR IT !!! If that means more than 50% of your code is error checking, then that's the way it has to be.


GENERAL REQUIREMENTS & INFORMATION
* This program must be in one file named lab3_1234567.cpp where 1234567 is your
student number.
For Testple : lab3_1234567.cpp or lab3_3987654.cpp

* The format of the student id line is CSV (Comma Separated Variables) with NO SPACES-
student_id,student_email,student_name
When the program is run without any operands i.e. simply the name of the executable such as:
lab3_1234567.exe
the program MUST print student ID string in Comma Separated Values (CSV)
format, Testple:  - NO spaces are allowed
"studentNumber,student_email,student_name"
eg: "1234567,s1234567@student.rmit.edu.au,FirstName_LastName"

REMEMBER: Do not include the 's' in front of the student number!

* A plagiarism detector will be used on all student code so don't bother copying.
The end of semester Test will focus on laboratory work so copying is a stupid idea because you wont be able to do the Test.

* What string conversion routines do you know (string to number)?
Look carefully as they will be needed to convert characters to a number and also check for errors.

* Your mark will result from testing your program against a whole range of inputs. The secret to getting a good mark is to carefully analyse all possible errors and odd
situations BEFORE you write the code so read the proforma VERY carefully.  Ensure in each circumstance you can detect the error or condition and report the appropriate result.
Hint: write test cases before you write any code.

* When text output is required you must generate EXACTLY that
output and no other output.  For Testple-
Specified output: "RX"    Actual program output: "rx"      Result: zero marks.
Specified output: "RX"    Actual program output: "Got RX"  Result: zero marks.
Specified output: "RX"    Actual program output: " RX"     Result: zero marks.

*	The following code is an Testple of the syntax required to open a pipe to the device.
It may / may not include all of the necessary code to complete the task.

//----Start of Testple standalone ccp file--------------------------------------------
#include "stdafx.h"
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
char command[256] = {};
strcpy_s(command, "ousb -r io PORTB 20"); // command to write 20 to OUSB board

FILE *fpipe;
char line[250] = {}; // size of Line should be smaller than command

fpipe = (FILE*)_popen(command,"r");    // attempt to open pipe and execute a command
if( fpipe != NULL )					   // check that the pipe opened correctly
{
while( fgets(line, sizeof(line), fpipe) )
{   // do nothing here, or print out debug data
cout << line; // print out OUSB data for debug purposes
}
_pclose(fpipe);   // close pipe
}
else cout << "Error, problems with pipe!\n";

// do something with the value returned by the OUSB board, eg:
unsigned short portb = (unsigned short)atoi(line); // convert from char array to unsigned short
cout << "value = " << portb << endl;

return 0;
}
//----End of Testple standalone ccp file----------------------------------------------
*/

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string.h>
#include <windows.h> // keep it here, just in case.
#include <cmath> // keep it here, just in case.

using namespace std;

//------------------------------CONSTANTS
const unsigned short min = 0;
const unsigned short max_B = 255;
const unsigned short max_RYG = 50;
const unsigned short line_arraySize = 256;
const unsigned short pauseTime = 500;

const unsigned short initial = 0;
const unsigned short redLight = 1;
const unsigned short yellowLight = 3;
const unsigned short greenLight = 2;

//------------------------------ERROR CHECKS
//Invalid character check for arg1
void errChk_arg1(char* a)
{
	if (*a != 'B' && *a != 'R' && *a != 'Y' && *a != 'G')
	{
		cerr << 'I' << endl;
		throw false;
	}
	if (*(a + 1) != '\0')
	{
		cerr << 'I' << endl;
		throw false;
	}
}
//Invalid character check for arg2
void errChk_arg2(char* a)
{
	for (char* p = a; *p != '\0'; p++)
	{
		if (
			*p != '1' && *p != '2' && *p != '3' && *p != '4' && *p != '5' &&
			*p != '6' && *p != '7' && *p != '8' && *p != '9' && *p != '0' &&
			*p != '+' && *p != '-'
			)
		{
			cerr << 'Y' << endl;
			throw false;
		}
	}
}
//------------------------------RANGE CHECKS
//Invalid range check for arg2_B
void rngChk_arg2_B(unsigned short x)
{
	if (x<min || x>max_B)
	{
		cerr << 'Y' << endl;
		throw false;
	}
}
//Invalid range check for arg2_RYG
void rngChk_arg2_RYG(unsigned short x)
{
	if (x<min || x>max_RYG)
	{
		cerr << 'Y' << endl;
		throw false;
	}
}

//------------------------------OUSB CLASS
class OUSB 			// Do not change class name
{
private:
	//Private Attributes
	unsigned short portB;

	//Private Methods
	unsigned short read_write(const char* a)
	{
		FILE *fpipe;
		char line[line_arraySize] = {};

		fpipe = (FILE*)_popen(a, "r");
		if (fpipe != NULL)
		{
			while (fgets(line, sizeof(line), fpipe))
			{ 
				//cout << line;
				if (line[0] == 'F')
				{
					cerr << 'Z' << endl;
					_pclose(fpipe);
					throw false;
				}
			}
			_pclose(fpipe);
		}
		else
		{
			cerr << 'Z' << endl;
			throw false;
		}

		return (unsigned short)atoi(line);
	}

public:
	//Constructor
	OUSB()
	{
		portB = get_portB();
	}

	//Methods
	unsigned short get_portB()
	{
		return read_write("ousb -r io PORTB");
	}
	unsigned short set_portB(unsigned short x)
	{
		stringstream cmdStream;
		cmdStream << "ousb -r io PORTB " << x;
		string cmdString = cmdStream.str();

		return read_write(cmdString.c_str());
	}
	// you may choose to implement operator overloaded funcitons for read and write functions for portb
	// void operator<<(const unsigned short &val); // write portb
	// void operator>>(unsigned short &val);       // read portb
};

//------------------------------TRAFFICLIGHT CLASS
class TrafficLight // Do not change class name
{
private:
	//Private Attributes
	unsigned short state;
	OUSB board;

public:
	//Contructor
	TrafficLight()
	{
		state = initial;
	}

	//Methods
	void set_red()
	{
		state = board.set_portB(redLight);
	}
	void set_yellow()
	{
		state = board.set_portB(yellowLight);
	}
	void set_green()
	{
		state = board.set_portB(greenLight);
	}
	void trans()
	{
		switch (state)
		{
		case redLight:
			set_green();
			break;

		case yellowLight:
			set_red();
			break;

		case greenLight:
			set_yellow();
			break;
		}
	}

	unsigned short get_state()
	{
		state = board.get_portB();
		return state;
	}
};


int main(int argc, char *argv[])
{
	try
	{
		if (argc == 1)
		{
			// no parameters on command line just the program name
			//---  edit string below: eg: "studentNumber,student_email,student_name"

			cout << "3452165,s3452165@student.rmit.edu.au,Kai_Soon" << endl;

			//--- When run with just the program name, meaning without parameters
			// your code  MUST print student ID string in CSV format.
			// i.e. simply running "lab1_1234567.exe
			// the output MUST print student ID string in Comman Separated Version (CSV)
			// format, such as:                  (NOTE the two commas !)
			//          "studentNumber,student_email,student_name"
			//      eg: "1234567,s1234567@student.rmit.edu.au,Tara-Louise_Brown"


			return(0); 	// The convention is to return Zero to signal NO ERRORS, if you change it the AutoTester will 
			// assume you have made some major error.  Leave it as zero.
		}
		else if (argc == 2)
		{
			//Check for invalid character in arg1
			errChk_arg1(argv[1]);

			if (argv[1][0] == 'B')
			{
				OUSB board;
				cout << board.get_portB() << endl;
				return 0;

			}
			else
			{
				cerr << 'N' << endl;
				throw false;
			}
		}
		else if (argc == 3)
		{
			//Check for invalid character in arg1
			errChk_arg1(argv[1]);
			//Check for invalid character in arg1
			errChk_arg2(argv[2]);

			if (argv[1][0] == 'B')
			{
				unsigned short bNum = atoi(argv[2]);
				//Check for invalid range for arg2_B
				rngChk_arg2_B(bNum);

				OUSB board;
				cout << board.set_portB(bNum) << endl;
				return 0;
			}
			else
			{
				unsigned short transNum = atoi(argv[2]);
				//Check for invalid range for arg2_RYG
				rngChk_arg2_RYG(transNum);

				//Declare a TraffiLight
				TrafficLight light;
				if (argv[1][0] == 'R')
				{
					light.set_red();
				}
				else if (argv[1][0] == 'Y')
				{
					light.set_yellow();
				}
				else if (argv[1][0] == 'G')
				{
					light.set_green();
				}

				for (int i = 0; i < transNum; i++)
				{
					light.trans();
					//Sleep(pauseTime);
				}
				cout << light.get_state() << endl;
				
				return 0;
			}
		}
		else
		{
			cerr << 'P' << endl;
			throw false;
		}
	}
	catch (...)
	{
		//Caught an error
		return 0;
	}
	
	return(0); 	// The convention is to return Zero to signal NO ERRORS, if you change it the AutoTester will 
	// assume you have made some major error. Leave it as zero.
}

// do NOT put any functions after this closing bracket, if you use functions add them before main


// End of File