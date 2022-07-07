import matplotlib.pyplot as plt 
import numpy as np 
import math

x=np.linspace(-2,2,100)
y=math.e**(-abs(x)+abs(x-1))
fig = plt.figure(figsize = (10, 5)) 
plt.plot(x,y)
plt.grid()
plt.xlabel("x")
plt.ylabel("P(x|w1)/P(x|w2)")
plt.axis()
plt.title("Likelihood Ratio vs x (Fig 1)")
plt.show()