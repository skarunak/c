#!/usr/bin/python



import my_telnet



ip = raw_input("Enter IP: ")

filename = raw_input("Enter script filename : ")



tp = my_telnet.TelnetToSw(ip, "root", "fibranne")



my_telnet.startNos(tp)



fp = open(filename)



line = fp.readline()

while line:

        my_telnet.NosCmd(tp, line)

        line = fp.readline()



my_telnet.ExitSw(tp)

fp.close()


