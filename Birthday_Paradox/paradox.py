import os
import math
from random import randint


def prac(n,t):	
	a=[]
	
	#print z
	for i in range(0,int(n)):		
		z=randint(0,int(t))	
		a.append(z)		
		for j in range(0,i):
			if (a[j]==z):
				return 1
		
			

t=float(raw_input( "Enter the number of items/days : "))
n=float(raw_input("Enter the number of people : "))

x=n*(n-1)/(2*t)
#print x
pmatch=1-math.exp(-x)
print 'Theoratical probability of match is ',  pmatch

counter=0
m=int(raw_input("Enter the number of experiments to be performed : "))
for k in range(0,m):
	a=prac(n,t)
	if (a==1):
		counter=counter+1
prob=float(counter)/float(m)
print counter
print 'The practical probability is',prob
