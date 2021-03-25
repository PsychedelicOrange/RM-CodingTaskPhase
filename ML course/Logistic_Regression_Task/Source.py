import numpy as np
import pandas as pd
import math
# data formating

data = pd.read_csv("heartdisease.csv")
data = data.dropna(axis=0)
datay = data['TenYearCHD']
data = data.drop(['TenYearCHD'],axis = 1)
x = data.to_numpy()
y = datay.to_numpy()
x0= np.ones((x.shape[0],1))
x = np.hstack((x0,x))
# m is no of training examples (from 1 to m)
m = x.shape[0]
# n is no of inputs/features including x0
n = x.shape[1]
# normalizing features
for i in range(1,n):
    avg = np.sum(x[:,i])/m
    ranger = max(x[:,i])- min(x[:,i])
    for j in range(m):
      x[j,i] = (x[j,i]-avg)/ranger
# m is no of training examples (from 1 to m)  n is no of inputs/features including x0
m = x.shape[0]
n = x.shape[1]
para = np.ones((n))
alpha = pow(10,-3)
iterations = 10000

def sigmoid(z):
    z = np.divide(1.0,(1+np.exp(-z)))
    return z
# probab is probabailty of Y=1
for i in range(iterations):
    print(i)
    xtheta = np.dot(x,para)
    probab= sigmoid(xtheta)
#    print(probab)
#    print(y)
    diffrentiation = np.dot( np.transpose(x) , (probab-y)) 
    para = para - alpha * diffrentiation
# maximize cost function
                                        # cost = pow(m,-1)*(-np.transpose(y)*np.log(probab)-np.transpose(1-y)*np.log(1-probab))
#then the term differentiation will be very less
    print("d/dpara = ",diffrentiation)
# Predictor program as follows
#take inputs from user
#normalize input data
#Plug it in to calculate sigmoid(xi . para)
#if this is >0.5 output 1
#else if <0.5 , obviously >=0, ouput 0

