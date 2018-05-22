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

    n = 166
    c = [5, 37, 8, 39, 33, 17, 22, 32, 13, 7, 10, 35, 40, 2, 43, 49, 46, 19, 41, 1, 12, 11, 28]
    #n = 10
    #c = [2, 3 , 5, 6]
    # Print the number of ways of making change for 'n' units using coins having the values given by 'c'

    #ways = getWays(n, c)

    c.sort();
    A = [[0 for x in range(n+1)] for y in range(len(c))] 
    #print('Sorted list:', A)

    for i in range(0, len(c)) :
        val = c[i]
     #   print("val",val)
        for j in range(0, n+1):
            sum = j;
      #      print("sum = ",sum)
            if j == 0:
                A[i][j] = 0
            else:
                if sum > val:
                    if sum % val == 0:
                        A[i][j] = A[i][j] + 1
                    if i != 0:
                        k = 1
                        A[i][j] = A[i][j] + A[i - 1][j]
                        while (sum >= k*val):
                            A[i][j] = A[i][j] + A[i - 1][sum - (k * val)]
                            k = k + 1
                elif sum == val:
                        if i != 0:
                            A[i][j] = A[i - 1][j] + 1
                        else:
                            A[i][j] = 1
                else:
                        if i != 0:
                            A[i][j] = A[i - 1][j]
                        else:
                            A[i][j] = 0
    
    print("no of ways is " , A[len(c)-1][n])
       




