# -*- coding: utf-8 -*-
"""
Created on Tue May 22 11:05:24 2018

@author: pkuntal
"""

import math
import os
import random
import re
import sys
from array import *

if __name__ == '__main__':
    
    #a = [1,2,3,4,1]
    #b = [3, 4, 1, 2, 1, 3]
    a = [16,27,89,79,60,76,24,88,55,94,57,42,56,74,24,95,55,33,69,29,14,7,94,41,8,71,12,15,43,3,23,49,84,78,73,63,5,46,98,26,40,76,41,89,24,20,68,14,88,26]
    b = [27,76,88,0,55,99,94,70,34,42,31,47,56,74,69,46,93,88,89,7,94,41,68,37,8,71,57,15,43,89,43,3,23,35,49,38,84,98,47,89,73,24,20,14,88,75]
    m = len(a) + 1
    n = len(b) + 1
    A = [0] * n
    seq = 0
    for i in range(n):
        A[i] = [0] * m
        
    i = 1
    while i <= len(b):
        j =1
        while j <= len(a):
            if (b[i - 1] == a[j - 1]) :
                A[i][j] = A[i-1][j-1] + 1
            else:
                A[i][j] = max(A[i-1][j], A[i][j-1])
            if seq < A[i][j]:
                seq = A[i][j]
                
            j = j + 1
        i = i + 1
    print (A)
    #print(seq)
    
    val = A[1][m -1 ]
    #print(val)
    
    k = 1
    l = m - 1
    ls = []
    if val == 1:
        ls.append(b[0])
    while val < seq:
        if A[k + 1][l] > val:
            ls.append( b[k])
            val = A[k+1][l]
        k = k + 1
    print(ls)
        
        
        
        
    
   




