#!/usr/bin/python
import os

def print_dir(path):
   for file in os.listdir(path):
       file_path = os.path.join(path,file)
       if os.path.isdir(file_path):
          print_dir(file_path)
       else:
          print file_path

print_dir(os.curdir)
