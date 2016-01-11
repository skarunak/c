#!/usr/bin/python
import sys
import pprint
import os

try:
  from scapy.all import * 
except ImportError:
  print "Install scapy to use this script .."
  sys.exit(1)
finally:
  print "Cleaning up .."

print "Executing script .."

__metaclass__ = type

class Pktgen:
  def __init__(self):
    self.pkt_list_intf1 = []
    self.pkt_list_intf2 = []
    print "Initialize pkt .."

  def BuildPkt(self, **args):
    pkt = Ether(dst=args['dmac'], src=args['smac'])/Dot1Q(vlan=args['vlan'])/IP(src='192.0.0.1', dst='193.0.0.1')/TCP(dport=12345)
    self.pkt_list_intf1.append(pkt)

    if args['2way'] is True:
       pkt = Ether(dst=args['smac'], src=args['dmac'])/Dot1Q(vlan=args['vlan'])/IP(src='193.0.0.1', dst='192.0.0.1')/TCP(dport=12345)
       self.pkt_list_intf2.append(pkt)

    i = args['count']
    smac = args['smac']
    dmac = args['dmac']
    vlan = args['vlan']

    while i:
       i-=1
       vlan = args['vlan']
       if args['iter_vlan'] is 1:

          pkt = Ether(dst=args['dmac'], src=args['smac'])/Dot1Q(vlan=vlan)/IP(src='192.0.0.1', dst='193.0.0.1')/TCP(dport=12345)
          self.pkt_list_intf1.append(pkt)

          if args['2way'] is True:
             pkt = Ether(dst=args['smac'], src=args['dmac'])/Dot1Q(vlan=vlan)/IP(src='193.0.0.1', dst='192.0.0.1')/TCP(dport=12345)
             self.pkt_list_intf2.append(pkt)

          vlan+=1
          
    print "Len of tx pkts %d %d " % (len(self.pkt_list_intf1), len(self.pkt_list_intf2))
              

  def SendPkt(self, tx_intf, iter_cnt):
    i = iter_cnt
    print "Sending pkt on intf %s %d times" % (tx_intf, iter_cnt)
    while i:
      i-=1
      for pkt in self.pkt_list_intf1:
         sendp(pkt,iface=tx_intf,verbose=None) 

  def CapPkt(self, rx_intf):
    sniff()

if __name__ == '__main__':
    pkt_param = {}
    pkt_param['dmac'] = '00:aa:00:00:00:aa'
    pkt_param['smac'] = '00:bb:00:00:00:bb'
    pkt_param['vlan'] = 100
    pkt_param['iter_vlan'] = 1
    pkt_param['count'] = 10
    pkt_param['tx_intf'] = 'lo'
    pkt_param['rx_intf'] = 'lo'
    pkt_param['2way'] = True
    pkt_param['iter_cnt'] = 2

    pid = os.fork()
    if pid:
      # Parent process - Use for Rx
      print "In parent process .."
      pkt.CapPkt(pkt_param['rx_intf'])
      os._exit(0)
    else:
      # Child process - Use for Tx
      print "In Child process .."
      # Todo : Wait for receiver to init then send frames
      pkt = Pktgen()
      pkt.BuildPkt(**pkt_param)
      pkt.SendPkt(pkt_param['tx_intf'], pkt_param['iter_cnt'])
      os._exit(0)
