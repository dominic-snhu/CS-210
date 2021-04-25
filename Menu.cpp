/* Menu.cpp by Dominic
 *
 * This is the main menu for the Corner Grocer's Grocery Tracking Program.
 * The program has the following options:
 *      1. Produce a list of items purchased for a given day (incl quantity).
 *      2. Show how many times a specific item was purchased in a given day.
 *      3. Create a text-based histogram listing all items purchased in a
 *          given day along with a representation of quantities purchased.
 */
#include <cctype>
#include <fstream>
#include <iostream>
#include <python2.7/Python.h>
#include <string>

#include "Menu.h"

using namespace std;

int main(){
    /* parameter to pass to python functions */
    string funcParam = "";
    /* the menu number indicated by userInput */
    int menuNumber = 0;
    /* value returned by python functions */
    int retVal = 0;
    /* for obtaining user input */
    string userInput = "";

    /* initialize tasks for the python interpreter */
    PyObject* myModule = initPython();

    for(;;){
        /* main menu */
        cout << "\n\n1. Print a list of items purchased for a day\n"
            << "2. Show number of purchases for a specific item in a day\n"
            << "3. Print a histogram for items purchased in a given day\n"
            << "4. Exit\n"
            << "Enter your selection as a number 1, 2, 3, or 4." << endl;
        
        cin >> userInput;

        /* convert user input from string to int */
        menuNumber = convertToNumeric(userInput);

        switch(menuNumber){
            /* print a list of purchases for the day ordered by quantity */
            case 1:
                runPythonFunction(myModule, "printDailyPurchases", funcParam);
                break;

            /* get the number of times a particular item was purchased */
            case 2:
                cout << "\nEnter a grocery item: ";
                cin >> funcParam;

                retVal = runPythonFunction(myModule, "getNumPurchases", funcParam);

                if(retVal > 0)
                    printf("%s purchase count: %d\n", funcParam.c_str(), retVal);

                break;

            /* print ordered list of purchases as a histogram */
            case 3:
                /* this value will be used for the histogram purchase count */
                funcParam = "#";
                printHistogram(myModule, funcParam);
                break;

            /* exit */
            case 4:
                /* cleanup all python initializations */
                Py_Finalize();
                return 0;

            /* bad option */
            default:
                cout << "Selection must be a number 1, 2, 3, or 4." << endl;
                continue;
        }
    }
}

/* Checks whether the user's input is a digit. If it is, the input is converted
 * to an integer and returned. If it is not, -1 is returned.
 *
 * @param userInput -- the string to convert to an integer
 * @return -- the converted input or -1 on failure
 */
int convertToNumeric(string userInput){
    if(isdigit(userInput[0]))
        return stoi(userInput);
    else
        return CONVERSION_FAIL;
}

/* Initializes the python interpreter and adds the current working directory
 * to sys.path. This allows the python module in the CWD to be called.
 *
 * @return -- the imported python module
 */
PyObject* initPython(){
    /* initialize the python interpreter */
    Py_Initialize();

    /* appen CWD to sys.path */
    PyList_Append(PySys_GetObject((char*)"path"), PyString_FromString("."));

    /* import the python code */
    PyObject* myModule = PyImport_ImportModule(PY_MODULE);

    return myModule;
}

/* Runs the selected python function from GroceryTracking.py Handles intializing
 * the python interpreter and instantiating the appropriate python objects.
 *
 * @param myModule -- the python module returned during initialization
 * @param chosenFunction -- the python function to run from GroceryTracking.py
 * @param funcParam -- the value to pass to the chosen function as a parameter
 * @return -- the value returned by the python function
 */
int runPythonFunction(PyObject* myModule, string chosenFunction, string funcParam){
    /* return the attribute (function to be executed) */
    PyObject* myFunction = PyObject_GetAttrString(myModule, chosenFunction.c_str());
    /* the value returned from the python function */
    long int retVal = 0;

    /* parameter to pass to the function */
    PyObject* parameter = Py_BuildValue("(s)", funcParam.c_str());

    /* call object */
    retVal = PyLong_AsLong(PyObject_CallObject(myFunction, parameter));

    if(retVal == IN_FILE_FAIL)
        cout << "Error opening input file!" << endl;
    else if(retVal == ITEM_NOT_FOUND)
        cout << funcParam << " not found in list!" << endl;
    else if(retVal == OUT_FILE_FAIL)
        cout << "Error opening output file!" << endl;

    return retVal;
}

/* Reads the HISTOGRAM file, "frequency.dat", and prints the histogram
 * generated by the python function, createHistogram.
 *
 * @param myModule -- the python module returned during initialization
 * @param funcParam -- the symbol to use when generating the histogram
 */
void printHistogram(PyObject* myModule, string funcParam){
    /* holds the item name read from the histogram file */
    string item = "";
    /* the value returned from the python function */
    int retVal = 0;
    /* the line of symbol representing the purchase count */
    string symbolLine = "";
    
    retVal = runPythonFunction(myModule, "createHistogram", funcParam);

    if(retVal >= 0){
        ifstream inFile(HISTOGRAM);

        /* histogram header */
        cout << "\n### Purchased Item Histogram ###\n" << endl;

        /* file format: item [symbol count]
         * ex (3 cheese pruchases):
         * Cheese ###
         */
        while(getline(inFile, item, ' ')){
            getline(inFile, symbolLine, '\n');
            cout << item << symbolLine << endl;
        }

        inFile.close();
    }
}
