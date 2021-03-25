# QUESTION : Implement linear regression to predict car prices. To be implemented using numpy (no other advanced external libraries). Given CSV.


import numpy as np
import pandas as pd
data = pd.read_csv("car_price.csv")
# deleted kmpl, CC, bhp , in microfodt excel
# and 
# converted fuel,seller_type,transmission,owner to numerical values
# CNG=10,   LPG=20,     Deisel=30,      Petrol=40
# Dealer=10,     Individual=20,     trustmark dealer=30
# automatic = 10,      Manual= 20
# testdrive=10    ,1owner=20,     2owner=30,      3owner=40,  4ownerandmore=50

data = pd.read_csv("car_price_edited.csv")
# deleted name column
data = data.drop(['name'],axis=1)
# deleted torque colimn cause rn i dont know how to deal with that
data = data.drop(['torque'],axis=1)
# drop all rows/training examples with some null values rn i dont know how to deal with that
data = data.dropna(axis=0)
#store selling price in datay and drop it from data
datay = data['selling_price']
data = data.drop(['selling_price'],axis =1)
#converting to numpy array
x = data.to_numpy()
y = datay.to_numpy()
x0= np.ones((x.shape[0],1))
x = np.hstack((x0,x))
# preparing for main loop for batch method
# m is no of training examples (from 1 to m)
m = x.shape[0]
# n is no of inputs/features including x0
n = x.shape[1]
# using direct formula


# using iterative method i learned in cs229
    # para is vector of size n initialized to ones
para = np.ones((n))
    # special(j) = sum this over i{    ( ( para[0]*x[i][0] + para[1]*x[i][1] + ...) - y[i] )  } * x[i][j]
    # JK is a vector such that JK[j] = special[j]
'''
alpha = pow(10,-1)
iterations = 1
print(m)
print(n)
for hello in range(iterations):
    JK = np.ones((n))
    for j in range(n):
        summ=0
        for i in range(m):
            summ = summ + np.sum(x[i]*para)*x[i][j]
        JK[j] = summ
    para = para - alpha * JK
    alpha = alpha * 0.001
    print(hello)
print(para)

def hypo(i):
    return np.sum(para*x[i])
alpha = pow(10,-5)
consterm = alpha / m
step = 0
epochs = 100
print("iterarions:", end = " ")
print(epochs)
print("alpha:", end = " ")
print(alpha)

for k in range(epochs):
    for j in range(0,n):
        for i in range(0,m):
            step = step + ((hypo(i)-y[i])*(x[i][j]))
        para[j] =para[j] - consterm*step
        step = 0
    consterm = consterm * 0.1
    print(k , end = " ")

print(" ")
print(para)
# Values were blowing up.. 
# This was para after three iteratinons !
# [-2.26913336e+27 -4.56691697e+30 -2.62684188e+32 -7.52267778e+28
# -4.37734333e+28 -4.36606272e+28 -5.92357781e+28 -4.27664913e+28
# -3.50330747e+30 -2.05291208e+29 -1.26962968e+28]
# it was suppossed to be heading towards 
# [-6.67499421e+07  3.35967141e+04 -1.06389502e+00 -4.51495153e+03
# -2.19126792e+04 -4.77882723e+04 -1.88765379e+03  1.16746207e+04
#  9.34935143e+01  1.26804145e+04 -3.81241777e+04]
# reducing alpha wasnt working....

'''
# normalizing features
for i in range(1,n):
    avg = np.sum(x[:,i])/m
    ranger = max(x[:,i])- min(x[:,i])
    for j in range(m):
      x[j,i] = (x[j,i]-avg)/ranger
#using direct formula
parameters = np.dot(np.dot(np.linalg.inv(np.dot(np.transpose(x),x)),np.transpose(x)),y)
print(parameters)
#using gradient descent
para = np.ones((n))
iterations = 100000
alpha = pow(10,-4)
costt = np.ones((iterations))
for i in range(iterations):
    hypo = np.dot(x,para)
    para = para - alpha * np.dot(np.transpose(x),(hypo - y))
    cost = np.sum(np.square(hypo-y))/(2*m)
    costt[i]=cost
print(costt)
#prints error
print(para-parameters)
#its working !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
#aight bye

# wait, for predicting, first take input from user ( UI PART I HATE TO TYPE OUT )
#Convert the strings into given codes from this

        # CNG=10,   LPG=20,     Deisel=30,      Petrol=40
        # Dealer=10,     Individual=20,     trustmark dealer=30
        # automatic = 10,      Manual= 20
        # testdrive=10    ,1owner=20,     2owner=30,      3owner=40,  4ownerandmore=50
# Normalize input data like before
# Feed it into hypothesis function , (which multiplies it with para matrix(which we already have calculate in this Source.py))
# the output is the predicted price

