#!/usr/bin/python

import my_telnet

import pprint

tn = my_telnet.TelnetToSw("10.24.85.83", "root", "fibranne")

my_telnet.startNos(tn)

output = my_telnet.NosCmd(tn, "show ip inter brief")

#print output
output_list = output.split('\r\n')

#print output_list

port_db = {}
for line in output_list[1:-1]:

   line_split = line.split();

   if len(line_split):

     if 'Ethernet' in line_split[0]:

       port = line_split[1]

       port_db[port] = dict([('admin', line_split[-2]), ('oper', line_split[-1])]);

       #port_db[port].update([('oper', line_split[-1])]);



# print only the ports that are oper up

'''

for port in port_db:

   if 'up' in port_db[port]['oper']:

      pprint.pprint(port)

      pprint.pprint(port_db[port])

'''

pprint.pprint(port_db)



