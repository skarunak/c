#!/usr/bin/python
import sys
no_tcs = map(int, raw_input().strip().split())
cnt = no_tcs[0]
top_sum_arrayLen = []
top_array_inp = []
while (cnt > 0) :
   top_sum_arrayLen.append(map(int, raw_input().strip().split()))
   top_array_inp.append(map(int, raw_input().strip().split()))
   cnt -= 1

#sum_arrayLen = map(int, raw_input().strip().split())
#array_inp = map(int, raw_input().strip.().split())
#sum_arrayLen_list = sum_arrayLen.split()
#array_inp_list = array_inp.split()


start = []
end = []
for (sum_arrayLen,array_inp) in zip(top_sum_arrayLen,top_array_inp):

  print sum_arrayLen 
  print array_inp 
  sum_num = sum_arrayLen[1]
  subarray_len = sum_arrayLen[0]
  print "Sum_num %d , subarray_len %d" % (sum_num, subarray_len)
  #validate input

  if subarray_len != len(array_inp):
     print "Input array length mismatch"
     sys.exit(1)

  i = 0
  found = 0
  iter_array = 0
# Efficient logic
  temp_sum = 0
  while (i < len(array_inp)) :
     temp_sum += array_inp[i]
     if (temp_sum == sum_num):
       #start.append(iter_array)
       #end.append(i)
       found = 1
       break
     elif (temp_sum > sum_num):
       while ((temp_sum >= sum_num) and (iter_array < i)):
          temp_sum -= array_inp[iter_array]
          iter_array += 1
          if (temp_sum == sum_num):
             found = 1
             break
     if found == 1:
        break
     i += 1
  if (found == 0) : 
       start.append(-1)
       end.append(-1)
  else:
       start.append(iter_array)
       end.append(i)
# Commented inefficient logic
'''
  while i < len(array_inp):
    j = i
    temp_sum = 0
    if (array_inp[j] == sum_num):
      start.append(j)
      end.append(j)
      break
    while (j < len(array_inp)):
      temp_sum += array_inp[j]
      if (temp_sum == sum_num):
        start.append(i)
        end.append(j)
        found = 1
        break;
      j += 1
    i += 1
    if (found == 1):
       break;
  if (found == 0):
    start.append(-1)
    end.append(-1)
''' 
for (i,j) in zip(start,end):
   if i == -1 : 
      print i, j
   else :
      print i+1,j+1

