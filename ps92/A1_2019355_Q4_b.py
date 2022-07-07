import matplotlib.pyplot as plt 
import numpy as np 
import math
x=np.linspace(-2,2,100)
y1=(math.e**(-abs(x)))/(math.e**(-abs(x))+math.e**(-abs(x-1)))
y2=(math.e**(-abs(x-1)))/(math.e**(-abs(x))+math.e**(-abs(x-1)))
fig = plt.figure(figsize = (10, 5)) 
plt.plot(x,y1,'b',label="P(w1|x)")
plt.plot(x,y2,'r',label="P(w2|x)")
x2=1/2;
y3=1/2
plt.ylim([0,1])
plt.axvline([1/2],c='g',label="Decision boundary")
plt.grid()
plt.xlabel("x")
plt.ylabel("Probability")
plt.axis()
plt.legend()
plt.title("Posterior Densities and Decision Boundary (Fig 2)")
plt.show()