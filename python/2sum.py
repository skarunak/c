#!/usr/bin/python
import pprint

nums = [0,4,3,0]
target = 0

rslt = []
hashmap = {}

for idx,val in enumerate(nums):
    if not hashmap.has_key(val):
       hashmap[val] = [idx]
    else:
       hashmap[val].append(idx)

pprint.pprint(hashmap)        

for idx,val in enumerate(nums):
    if hashmap.has_key(target-val):
       for i in hashmap.get(target-val):
          if (i != idx):
             rslt.append(idx)
             rslt.append(i)
             print rslt
       exit(0)

