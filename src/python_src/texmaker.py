from numpy import *
import numpy as np
def replace_line(file_name, line_num, text):
    lines = open(file_name, 'r').readlines()
    lines[line_num] = text
    out = open(file_name, 'w')
    out.writelines(lines)
    out.close()
print ' '
print ' '
print '........................'
print 'Begin texmaker.py'
print '........................'
print ' '
print ' '
file_in=open('./tmp/data_values.dat','rw+')
mean=file_in.readline();
print str(mean)
var=file_in.readline();
print str(var)
nmax=file_in.readline();
print str(var)
nmin=file_in.readline();
print str(var)
nsum=file_in.readline();
print str(var)
navhour=file_in.readline();
print str(var)
print ' '
print ' '
print '.....................................................'
print 'File .txt imported to python'
print '.....................................................'
print ' '
print ' '
print '.....................................................'
print 'Editing .tex file'
print '.....................................................'
print ' '
print ' '
strname='\\newcommand{\dataname}{'+'Data1.txt'+'} \n'
strdate='\\newcommand{\datadate}{'+'10/12/2013'+'} \n'
strmean='\\newcommand{\datamean}{'+mean
strvar='\\newcommand{\datavar}{'+var
strmax='\\newcommand{\datamax}{'+nmax
strmin='\\newcommand{\datamin}{'+nmin
strsum='\\newcommand{\datasum}{'+nsum
stravhour='\\newcommand{\datahouraverage}{'+navhour


replace_line('./tmp/report.tex',0,strname)
replace_line('./tmp/report.tex',1,strdate)
replace_line('./tmp/report.tex',2,strmean)
replace_line('./tmp/report.tex',3,strvar)
replace_line('./tmp/report.tex',4,strmax)
replace_line('./tmp/report.tex',5,strmin)
replace_line('./tmp/report.tex',6,strsum)
replace_line('./tmp/report.tex',7,stravhour)


