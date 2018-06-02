# -*- coding: utf-8 -*-
"""
Created on Tue May 29 07:06:26 2018

@author: pkuntal
"""

def knapsack(wt, val, total_sum):
    m = total_sum + 1
    n= len(wt)
    
    A=[0] * n
    
    for i in range(n):
        A[i] = [0] * m
    
    i = 0
    while i < len(wt):
        j = 1
        while j < m :
            if j < wt[i]:
                if i > 0:
                    A[i][j] = A[i-1][j]
            else:
                if i > 0:
                    A[i][j] = max(A[i-1][j], (A[i-1][j - wt[i]] + val[i]))
                else:
                    A[i][j] = val[i];
            j = j + 1
        i = i + 1
    #print(A)
    
    k = len(val) - 1
    l = total_sum
    selected = {}
    sel_wt = 0
    while k > 0:
        while A[k][l] <= A[k-1][l]:
            #if k ==
            k = k - 1
        #print(k,l)
    
        selected[wt[k]]=val[k]
        sel_wt = sel_wt + wt[k]
        l = l - wt[k]
        k = k - 1
        #print(k,l,sel_wt)
    
    print("Selected pair(s) is/are ", selected)
    return A[len(val)-1][total_sum]

if __name__ == '__main__':
    wt1 = [1, 3, 4, 5]
    val1 = [1, 4, 5, 7]
    total_sum1 = 7
    
    op1 = knapsack(wt1, val1, total_sum1)
    if op1 == 9:
        print("TESTCASE1:SUCCESS")
    else:
        print("TESTCASE1:FAILED")
    
    val2 = [22, 20, 15, 30, 24, 54, 21, 32, 18, 25]
    wt2 = [4, 2, 3, 5, 5, 6, 9, 7, 8, 10]
    total_sum2 = 30
    op2 = knapsack(wt2, val2, total_sum2)
    if op2 == 182:
        print("TESTCASE2:SUCCESS")
    else:
        print("TESTCASE2:FAILED")
    
    val3 = [57,95,13,29,1,99,34,77,61,23,24,70,73,88,33,61,43,5,41,63,8,67,20,72,98,59,46,58,64,94,97,70,46,81,42,7,1,52,20,54,81,3,73,78,81,11,41,45,18,94,24,82,9,19,59,48,2,72]
    wt3 = [83,84,85,76,13,87,2,23,33,82,79,100,88,85,91,78,83,44,4,50,11,68,90,88,73,83,46,16,7,35,76,31,40,49,65,2,18,47,55,38,75,58,86,77,96,94,82,92,10,86,54,49,65,44,77,22,81,52]
    total_sum3 = 41
    
    op3 = knapsack(wt3, val3, total_sum3)
    if op3 == 223:
        print("TESTCASE3:SUCCESS")
    else:
        print("TESTCASE3:FAILED")