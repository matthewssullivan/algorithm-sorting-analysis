# -*- coding: utf-8 -*-
"""
Created on Sat Feb  3 23:11:57 2018

@author: oneey_000
"""

a=[]
b = open("one-million-randoms.txt", "r")
b.readline()
b.readline()
size =0
for line in b:
    a.append(int (line))
    size+=1
#    if (size == 100000):
#        break
#print ("Before Sorting: ")
#print (a)
def mergeSort(thisList):
    numberComp = 0
    if len(thisList) >1:
        middle = int(len(thisList)/2)
        left=thisList[:middle]
        right=thisList[middle:]
        leftResult =mergeSort (left)
        rightResult =mergeSort (right)
        numberComp +=1
        numberComp += leftResult[1]+rightResult[1]
        i=0
        j=0
        k=0
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                thisList[k] = left[i]
                i+=1
                numberComp +=1
            else:
                thisList[k] = right[j]
                j+=1
                numberComp +=1
            k+=1
        while i < len(left):
            thisList[k] = left[i]
            k+=1
            i+=1
            numberComp += 1
        while j < len(right):
            thisList[k] = right[j]
            k+=1
            j+=1
            numberComp += 1
    return thisList, numberComp
totalComp =mergeSort(a)[1]
#print ("After sorting" )
#print (a)
print ("Total operations: " + str(totalComp))