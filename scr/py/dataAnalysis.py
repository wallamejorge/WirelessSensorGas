#meandata=reduce(lambda x, y: x + y, g_ppm) / len(g_ppm)
from numpy import *
import numpy as np
print ' '
print ' '
print '........................'
print 'Begin dataAnalysis.py'
print '........................'
print ' '
print ' '
t, g_ppm =loadtxt('Data.txt',unpack=True,usecols=[0,1])
print ' '
print ' '
print '.....................................................'
print 'Data imported to python from Data.txt colums 0 and 1'
print '.....................................................'
print ' '
print ' '
var_Data=g_ppm.var()
mean_Data=g_ppm.mean()
max_Data=np.amax(g_ppm)
min_Data=np.amin(g_ppm)
print '.....................................................'
print 'Analysis Calculated'
print '.....................................................'
print ' '
print ' '
print "The mean/Average of data on Data.txt is " + str(mean_Data)
print "The variance of data on Data.txt is " + str(var_Data)
print "The Maximun value of data on Data.txt is " + str(max_Data)
print "The Minimun value of data on Data.txt is " + str(min_Data)

