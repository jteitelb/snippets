#!/usr/bin/python

# could be more readable, but looks pretty :D
def isLeapYear(year):
    if year % 4 == 0:
        if year % 100 == 0:
            if year % 400 == 0:
                return True
            return False
        return True
    return False

# days up to and including a month
# assumes not a leap year
def daysToMonth(month):
    if month == 1:
        return 31
    
    t = 30 * month + month / 2 # integer division, drops 0.5 when month odd
    if month % 2 == 0 and month <= 6:
        return t - 2
    return t - 1


def getDay(year, month, day):
    # basic error checking (still allows for 02/30)
    if year < 0:
        return -1
    if month < 1 or month > 12:
        return -2
    if day < 1 or day > 31:
        return -3

    if month == 1:
        return 31

    l = 1 if isLeapYear(year) else 0

    return daysToMonth(month - 1) + day + l


