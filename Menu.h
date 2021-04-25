#include <string>

using namespace std;

/* constants */
/* the histogram will be written to this file */
#define HISTOGRAM       "frequency.dat"
/* python functions are defined here */
#define PY_MODULE       "GroceryTracking"
/* error opening input file */
#define IN_FILE_FAIL    -1
/* grocery item not found in list */
#define ITEM_NOT_FOUND  -2
/* error opening output file */
#define OUT_FILE_FAIL   -3
/* failure to convert menu option to an int */
#define CONVERSION_FAIL -4

/* function prototypes */
/* helper function to convert user input to integer */
int convertToNumeric(string menuChoice);
/* starts python interpreter and initializes variables */
PyObject* initPython();
/* reads the HISTOGRAM file and prints to stdout */
void printHistogram(PyObject* myModule, string funcParam);
/* helper function for running python functions */
int runPythonFunction(PyObject*, string chosenFunction, string funcParam);
