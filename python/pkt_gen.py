#!/usr/bin/python
import sys
import pprint
import os
import time

try:
  from scapy.all import * 
except ImportError:
  print "Install scapy to use this script .."
  sys.exit(1)

__metaclass__ = type

class Pktgen:
  def __init__(self, **args):
    self.pkt_list_intf1 = []
    self.pkt_list_intf2 = []
    print "Initialize pkt .."
    # Cache needed inputs
    self.iter_cnt = args['iter_cnt']
    self.count = args['count']
    self.rx_intf = args['rx_intf']


  def BuildPkt(self, **args):
    self.iter_cnt = args['iter_cnt']
    self.count = args['count']

    i = args['count']
    smac = args['smac']
    dmac = args['dmac']
    vlan_id = args['vlan']

    while i:
       i-=1
       if args['iter_vlan'] is 1:

          pkt = Ether(dst=args['dmac'], src=args['smac'])/Dot1Q(vlan=vlan_id)/IP(src='192.0.0.1', dst='193.0.0.1')/TCP(dport=12345)
          self.pkt_list_intf1.append(pkt)

          if args['2way'] is True:
             pkt = Ether(dst=args['smac'], src=args['dmac'])/Dot1Q(vlan=vlan_id)/IP(src='193.0.0.1', dst='192.0.0.1')/TCP(dport=12346)
             self.pkt_list_intf2.append(pkt)

          vlan_id+=1
          
    print "Len of tx pkts %d %d " % (len(self.pkt_list_intf1), len(self.pkt_list_intf2))
              

  def SendPkt(self, id, tx_intf, iter_cnt):
    i = iter_cnt
    if id is 1:
      pkt_list = self.pkt_list_intf1
    else:
      pkt_list = self.pkt_list_intf2

    print "Sending pkt on intf %s %d times" % (tx_intf, iter_cnt)
    while i:
      i-=1
      for pkt in pkt_list:
         sendp(pkt,iface=tx_intf,verbose=None) 

  def packet_callback(self): pass
    
  def CapPkt(self, rx_intf):
    wait_cnt = self.count * self.iter_cnt
    #wait_cnt = 22
    if rx_intf is self.rx_intf:
      tcp_port = "12345"
    else:
      tcp_port = "12346"

    pkts=sniff(filter="tcp port "+tcp_port, iface=rx_intf, count=wait_cnt+1, timeout=5)
    count = 1
    f = open("cap.txt", "w")
    for p in pkts:
       f.writelines("Pkt #%d : " % count)
       f.writelines(p.summary() + '\n')
       count+=1

    print "rcvd %d pkt on intf %s " % (len(pkts), rx_intf)

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

    pkt = Pktgen(**pkt_param)
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
      time.sleep(1)
      pkt.BuildPkt(**pkt_param)
      pkt.SendPkt(1, pkt_param['tx_intf'], pkt_param['iter_cnt'])
      os._exit(0)
