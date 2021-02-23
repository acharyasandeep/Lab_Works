import matplotlib.pyplot as plt
import numpy as np

#it's nothing but differential equation of e^x..
#you can play around with it to approximate the graph of any other function
def diffEquation(x,y):
    return y

h=0.1
x=0
xList=[0]
yList=[1]
y=0
for i in range(100):
    x=x+h
    xList.append(x)
    yList.append(yList[i]+h*diffEquation(xList[i],yList[i]))

n=np.linspace(1,10)
plt.plot(n,np.exp(n),label="e^x")
plt.plot(xList,yList,label="e^x using h = "+str(h))
plt.legend()
plt.show()
