#!/usr/bin/python



import my_telnet



ip = raw_input("Enter IP: ")



tp = my_telnet.TelnetToSw(ip, "root", "fibranne")



my_telnet.StartNos(tp)

my_telnet.NosCmd(tp, "config term")

my_telnet.NosCmd(tp, "overlay-gateway test")



for i in range(1,9):

        for j in range(1,251):

                site_idx = ((i-1) * 250) + j

                my_telnet.NosCmd(tp, "site %d" % site_idx)

                my_telnet.NosCmd(tp, "ip address 10.10.%d.%d" % (i,j))

