#!/usr/bin/python
import sys
import heapq

class GetMedian():

  def __init__(self, **args):
    self.min_heap = []
    self.max_heap = []
    self.min_count = 0
    self.max_count = 0

  def add_to_min_heap(self, num):
    self.min_count += 1
    heapq.heappush(self.min_heap, num)
    heapq._heapify_max(self.min_heap)
    #print "add_to_min_heap %f cnt %d" % (num, self.min_count)
    print " add to min heap " , self.min_heap
    #if len(self.min_heap) > 5:
       #self.min_heap = heapq.nlargest(5, self.min_heap)

  def add_to_max_heap(self, num):
    self.max_count += 1
    heapq.heappush(self.max_heap, num)
    #print "add_to_max_heap %f cnt %d " % (num , self.max_count)
    print " add to max heap " , self.max_heap
    #if len(self.max_heap) > 5:
       #self.max_heap = heapq.nsmallest(5, self.max_heap)

  def median(self, nums):
    for i in nums:

      if self.min_count == 0:
          self.add_to_min_heap(i)
          continue
      elif self.min_heap[0] < i:
          self.add_to_max_heap(i)
      else:
          self.add_to_min_heap(i)

      if self.min_count > self.max_count:
         large = self.min_heap
         small = self.max_heap
         diff = self.min_count - self.max_count
      else:
         large = self.max_heap
         small = self.min_heap
         diff = self.max_count - self.min_count
   
      if (diff > 1):
         # Remove from larger heap and push to smaller 
         val = heapq.heappop(large)
         heapq.heappush(small, val)
         if large is self.max_heap:
            self.max_count -= 1
            self.min_count += 1
            heapq._heapify_max(self.min_heap)
         else:
            self.min_count -= 1
            self.max_count += 1
         if len(self.min_heap) > 3:
            self.min_heap = heapq.nlargest(3, self.min_heap)
         if len(self.max_heap) > 3:
            self.max_heap = heapq.nsmallest(3, self.max_heap)
         #print "Diff > 1 , so moving value %f \n" % val

    print "Heap counts Min %d Max %d \n" % (self.min_count, self.max_count)

    if self.min_count > self.max_count:
       median = self.min_heap[0]
    elif self.min_count < self.max_count:
       median = self.max_heap[0]
    else:
       print "values %f %f \n" % (self.max_heap[0], self.min_heap[0])
       median =  (float)(self.max_heap[0] + self.min_heap[0])/2   

    #print "Median is %f \n" % median
    return median


if __name__ == '__main__':
  for nums in sys.stdin:
   if not nums: break;
   nums = map(int, nums.strip().split())

  #nums = range(20)
  print "Input : " , nums

  obj = GetMedian()
  print "Median is %d " % obj.median(nums)
