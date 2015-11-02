#!/usr/bin/python

def christ(n):

    x=1

    y=n-1

    for i in range(0,n):

       print ' '*y + '+' * x + ' ' * y

       x+=2

       y-=1



    y=n-1

    for i in range(0,n/2):

       print ' '*y + '#' + ' ' *y



christ(5)


