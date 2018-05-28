# -*- coding: utf-8 -*-
"""
Created on Mon May 28 17:32:17 2018

Given three integers t1, t2, and n, compute and print term  of a modified Fibonacci sequence.
tn = (tn-1)^2 + tn-2
link : https://www.hackerrank.com/challenges/fibonacci-modified/problem
@author: pkuntal
"""

#!/bin/python3

import math
import os
import random
import re
import sys



# Complete the fibonacciModified function below.
def fibonacciModified(t1, t2, n):
    A = []
    A.append(t1)
    A.append(t2)
    
    while len(A) < n:
        s = len(A)
        t = (A[s - 1] * A[s - 1]) + A[s - 2 ]        
        A.append(t)       
    
    return A[n - 1]

if __name__ == '__main__':
    
    t1 = 0
    t2 = 1
    n = 10

    result = fibonacciModified(t1, t2, n)

    print(result)