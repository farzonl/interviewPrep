from random import shuffle
import sys 

def is_sorted(A):
    sorted = True
    i = 1
    while i < len(A) :
        if( A[i] < A[i-1]):
            sorted = False
        i += 1
    return sorted

def unsort(A):
    shuffle(A)
    return A

def closest(A, element):
    i = 0
    closest = sys.maxsize
    closestIndex = -1
    while i < len(A):
        temp = abs(A[i] - element)
        if temp < closest:
            closest = temp
            closestIndex = i
        i += 1
    
    return A[closestIndex]