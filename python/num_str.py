#!/usr/bin/python

n = int(raw_input())
l = range(1, n+1)

out = ''
for i in l:
   out += repr(i)

print out
