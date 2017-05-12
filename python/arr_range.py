#!/usr/bin/python
import random

''' Refer sort.c in c folder for another way of partitioning '''
def partition(arr, arr_size, num):
   p_idx = arr_size
   itr = 0

   if (p_idx < 0) :
      return 0
   # Position the p_idx with element smaller than num
   while (p_idx >= 0 and arr[p_idx] > num):
      if p_idx == 0 :
         return p_idx 
      else :
         p_idx -= 1

   while (itr < p_idx and itr <= arr_size):

       if (arr[itr] > num):
          # Swap with smallest element from the end
          tmp = arr[itr]
          arr[itr] = arr[p_idx]
          arr[p_idx] = tmp

          # Position the p_idx with element smaller than num, this is the key operation. p_idx from the end needs to be repositioned once again
          while (p_idx >= 0 and arr[p_idx] > num):
             if p_idx == 0 :
                return p_idx 
             else :
                p_idx -= 1
          
       itr += 1 

   return p_idx+1
  
print "Enter number of elements "
arr_count = eval(raw_input().strip())
print "Entered elements " , arr_count

print "Enter low, mid, high values"
low, mid, high = map(int, raw_input().strip().split())

print "Ranges %d / %d / %d " % (low ,mid, high)

arr = range(arr_count)
print "Generated array " , arr
random.shuffle(arr)
#arr = [26, 6, 15, 13, 11, 10, 0, 21, 8, 23, 14, 28, 22, 7, 1, 24, 18, 4, 17, 20, 16, 12, 25, 9, 3, 19, 27, 29, 5, 2]
print "Randomized array " , arr
high_pos = partition(arr, arr_count-1, high)
#print "Grouped array .. " , arr[:high_pos], arr[high_pos:]
mid_pos = partition(arr, high_pos-1, mid)
#print "Grouped array .. " , arr[:mid_pos] , arr[mid_pos:high_pos], arr[high_pos:]
low_pos = partition(arr, mid_pos-1, low)

print "Positions are %d . %d . %d " % (low_pos , mid_pos, high_pos)
print "Grouped array .. " , arr[:low_pos], arr[low_pos:mid_pos] , arr[mid_pos:high_pos], arr[high_pos:]
