#meandata=reduce(lambda x, y: x + y, g_ppm) / len(g_ppm)
from numpy import *
import math
import numpy as np
print ' '
print ' '
print '........................'
print 'Begin dataAnalysis.py'
print '........................'
print ' '
print ' '
t, g_ppm =loadtxt('./tmp/Data.txt',unpack=True,usecols=[0,1])
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
sum_Data=np.sum(g_ppm)
avhour_Data=sum_Data/24;
print '.....................................................'
print 'Analysis Calculated'
print '.....................................................'
print ' '
print ' '
print "The mean/Average of data on Data.txt is " + str(mean_Data)
print "The variance of data on Data.txt is " + str(var_Data)
print "The Maximun value of data on Data.txt is " + str(max_Data)
print "The Minimun value of data on Data.txt is " + str(min_Data)
print "The Summatory of data data on Data.txt is " + str(sum_Data)
print "The Average per Hour of data data on Data.txt is " + str(avhour_Data)
print ' '
print ' '
print ' '
print ' '
output_file = file('./tmp/data_values.dat', 'w') 
output_file.write(str(mean_Data)+'} \n')
output_file.write(str(var_Data)+'} \n')
output_file.write(str(max_Data)+'} \n')
output_file.write(str(min_Data)+'} \n')
output_file.write(str(sum_Data)+'} \n')
output_file.write(str(avhour_Data)+'} \n')
