#!/usr/bin/python

ver1_str = raw_input("Version 1:")
ver2_str = raw_input("Version 2:")

ver1 = map(int, ver1_str.strip().split('.'))
ver2 = map(int, ver2_str.strip().split('.'))

found = 0
for idx1,idx2 in zip(ver1, ver2):
   if (idx1 > idx2):
      print "Version 1 %s is latest", ver1_str
      found = 1
      break
   elif (idx1 < idx2):
      print "Version 2 %s is latest", ver2_str
      found = 1
      break

if found == 0:
  if len(ver1) > len(ver2):
      print "Version 1 %s is latest", ver1_str
  elif len(ver1) < len(ver2):
      print "Version 2 %s is latest", ver2_str
  else:
      print "Versions 1 & 2 are same"   
