#!/usr/bin/python

def getMutual(friendsA, friendsB):
    mutual = {}
    result = []
    for friend in friendsA:
        mutual[friend] = False
    for friend in friendsB:
        if mutual.has_key(friend):
            result.append(friend)
    return result

print getMutual(["John","Steve", "Jake", "Sarah"],["Jake","Walter", "John","Ian", "Sarah"])
