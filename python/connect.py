#!/usr/bin/python
import socket
import sys
import pprint
import os
import time
import errno
from scapy.all import *

try:
  from scapy.all import * 
except ImportError:
  print "Install scapy to use this script .."
  sys.exit(1)

__metaclass__ = type

class make_link:
   def __init__(self, **args):
     self.params = {}
     self.params[1] = {}
     self.params[1]['intf1'] = args['intf1']
     self.params[1]['intf2'] = args['intf2']

   def pkt_call_bk(self, pkt):
     print "Inside call back"
     sendp(pkt,iface=self.params[1]['intf2']) 

   def capture_replay(self):
     fd_list = []
     s1 = socket.socket(socket.AF_PACKET, socket.SOCK_RAW, socket.htons(ETH_P_ALL))
     s1.bind((self.params[1]['intf1'], ETH_P_ALL))

     s2 = socket.socket(socket.AF_PACKET, socket.SOCK_RAW, socket.htons(ETH_P_ALL))
     s2.bind((self.params[1]['intf2'],ETH_P_ALL))

     fd_list.append(s1)
     #sniff(iface=self.params[1]['intf1'], prn=self.pkt_call_bk, count=10)
     while True:
        try:
          fd_set = select([s1], [], [], 1)
          print "Select returned .."
          for fd in fd_set[0]: 
             #sniff(iface=self.params[1]['intf1'], prn=self.pkt_call_bk, count=10)
             pkt,sa = fd.recvfrom(MTU)
             print "read %d byte of pkt " % len(pkt)
             # TODO: Get FDs pair interface and send on that ..
             s2.sendall(pkt)
        except (OSError, error) as e:
          #if e.args[0] != errno.EINTR:
            raise
     
if __name__ == '__main__':
   user_params = {}
   user_params['intf1'] = 'wlan1'
   user_params['intf2'] = 'lo'

   link = make_link(**user_params)
   

   link.capture_replay()
