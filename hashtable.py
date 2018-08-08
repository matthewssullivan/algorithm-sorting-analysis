# -*- coding: utf-8 -*-
"""
Created on Wed Feb  7 21:52:07 2018

@author: oneey_000
"""

index=[0]*100
#while i <=100:
#    index[i]=0
#    i=i+1
a=[]
b = open("shuffled.txt", "r")
b.readline()
b.readline()
for line in b:
    a.append(int (line))
i=0
j=0
k=0
l=0
sortedList=[]
numOps=0
while i < len(a):
    index[a[i]]=index[a[i]]+1
    i=i+1
    numOps=numOps+1
while j < len(index):
    print("Index: " +str(j) + " Count: " + str(index[j]))
    j=j+1
while k<len(index):
    while l< index[k]:
        sortedList.append(k)
        l=l+1
        numOps+=1
    k=k+1
    l=0
#print (sortedList)
print ("Operations: " +str(numOps))