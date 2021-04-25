#!/usr/bin/env python
## GroceryTracking.py by Dominic
## Functions for generating reports to track grocery purchases.

from collections import Counter

INFILE = 'CS210_Project_Three_Input_File'
OUTFILE = 'frequency.dat'


def getGroceries():
    '''Returns a Counter object containing a dict of groceries as keys
    and the number of times they appear in the purchase list as values.
    Returns -1 if there is an error opening the input file.
    '''
    try:
        with open(INFILE, 'r') as purchaseList:
            return Counter([item.strip() for item in purchaseList])
    except:
        return -1


def printDailyPurchases(funcParam):
    '''Prints a list of items purchased for a day, including the numbre of
    times each item was purchased. This list is sorted by quantity purchased.
    Returns -1 if the input file cannot be opened.
    '''
    groceries = getGroceries()
    if groceries == -1:
        return -1

    # list header
    print('\n### Purchased Item List ###\n')
    for item, count in groceries.most_common():
        print('[{}]\t{}'.format(count, item))
    
    return 0


def getNumPurchases(item):
    '''Returns the number of times a specified grocery item has been
    purchased for a day. If the input file cannot be opened, -1 will be
    returned. If the item is not found in the grocery list, -2 is returned.
    '''
    groceries = getGroceries()
    if groceries == -1:
        return -1

    # to support case insensitive searching
    groceries = {grocery.lower(): count for grocery, count in groceries.items()}

    if item.lower() in groceries:
        return groceries[item.lower()]
    else:
        return -2


def createHistogram(symbol = '*'):
    '''Creates a histogram for the list of items purchased for a day. This is
    the same list produced by printDailyPurchases, but it is written to as a
    histogram to a file, 'frequency.dat'. The symbol is an asterisk by default.
    Accepts an optional argument to define a symbol for the histogram.
    A value of -1 will be returned if the input file cannot be opened. A value
    of -2 will be returned if the output file cannot be opened.
    '''
    groceries = getGroceries()
    if groceries == -1:
        return -1

    try:
        with open(OUTFILE, 'w') as histogram:
            for item, count in groceries.most_common():
                histogram.write('{:>16} {}\n'.format(item, symbol * count))
    except:
        return -3
    
    return 0
