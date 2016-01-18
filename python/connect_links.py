#!/usr/bin/python
import socket
import sys
import pprint
import os
import time
import errno
from select import *

__metaclass__ = type

class connect_link:
   def __init__(self, **args):
     self.links = {} # Pair of devices
     self.fd_list = [] # List of FDs 
     self.peer_fd = {} # Peer FD for a given interface

   # Open socket and build necessary DBs 
   def build_links(self, **args):
     i = 1;
     no_intfs = 0
     while i<=args['no_links']: 
       self.links[i] = {}
       self.links[i]['intf1'] = args['intf'+str(no_intfs+1)]
       self.links[i]['intf2'] = args['intf'+str(no_intfs+2)]

       s1 = socket.socket(socket.AF_PACKET, socket.SOCK_RAW, socket.htons(0x0003))
       s1.bind((self.links[i]['intf1'], 0x0003))
       self.fd_list.append(s1)

       s2 = socket.socket(socket.AF_PACKET, socket.SOCK_RAW, socket.htons(0x0003))
       s2.bind((self.links[i]['intf2'],0x0003))
       self.fd_list.append(s2)

       self.peer_fd[self.links[i]['intf1']] = s2
       self.peer_fd[self.links[i]['intf2']] = s1

       i+=1
       no_intfs +=2

   # Capture and replay on already built fds
   def connect_links(self):
     while True:
        try:
          fd_set = select(self.fd_list, [], [], 1)
          for fd in fd_set[0]: 
             pkt,sa = fd.recvfrom(9999)
             peer_fd = self.peer_fd[fd.getsockname()[0]]
             peer_fd.sendall(pkt)
             print "%s->%s: read %d byte of pkt " % (fd.getsockname()[0], peer_fd.getsockname()[0], len(pkt))
        except (OSError, error) as e:
          if e.args[0] != errno.EINTR:
            raise
     
if __name__ == '__main__':
   if len(sys.argv) < 4:
      print "Usage: ./connect_link <#ofLinks> <List of netdevices separated by space> \n For Eg. ./connect_link 2 eth0 eth1 eth10 eth11"
      sys.exit(1)
   else:
      user_params = {}
      pos = 0
      for i in sys.argv[1:]:
         if pos is 0: 
            user_params['no_links'] = int(i)
         else:
            user_params['intf'+str(pos)] = i
         pos += 1

   link = connect_link()
   link.build_links(**user_params)
   link.connect_links()
