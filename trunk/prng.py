#!/usr/bin/env python
# -*- coding: utf-8 -*-
'''
trab CPS
Jorge Pereira - 12063
MESI
'''
import math
import time
import random
global x

#http://www.openbookproject.net/thinkcs/python/english2e/ch11.html
def swap(a, b):
    temp = a
    a = b
    b = temp

x = time.clock() # seed for the PRNG

T=[]

for i in range(0,999):
    for i in range(0,9):
        r = random.randint(0,9) #http://docs.python.org/library/random.html
        T.append(r)
#print T
p=random.randint(0,999)
print p
#Nk
if(p<1000):
    z1=T[p]
else:
    z1=T[0]
swap(T[p], T[0])

if(p<999):
    z2=T[p+1]
else:
    z2=T[0]
swap(T[p+1], T[0])

if(p<998):
    z3=T[p+2]
else:
    z3=T[0]
swap(T[p+2], T[0])

if(p<997):
    z4=T[p+3]
else:
    z4=T[0]
swap(T[p+3], T[0])

#p = z1 × 102 + z2 × 101 + z3 × 10
p = z1 * pow(10, 2) + z2 * pow(10, 1) + z3 * 10

print p
