#!/usr/bin/python



import getpass

import telnetlib

import sys

import time

import commands



HOST = "10.24.85.83"

user = "root"

password = "fibranne"





(status, output) = commands.getstatusoutput("scp -oStrictHostKeyChecking=no if.c root@%s:/root/"%HOST)

time.sleep(1)

print "out of sleep"

sys.stdout.write("fibranne\n")

#tn.write("exit\n")


