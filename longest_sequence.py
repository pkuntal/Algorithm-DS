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
    
    #a = [1,2,3,4,1,5]
    #b = [1,3,2,3,5]
    a = [1,2,3,4,1]
    b = [3,4,1,2,1,3]
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
    print(seq)
    
   




