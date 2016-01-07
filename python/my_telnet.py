#!/usr/bin/python



import getpass

import telnetlib

import sys



def FosCmd(tn, command):

    print "Exec %s" % command

    print tn.read_until('root>', .01)

    #write the command

    tn.write(command + '\n')

    #read all data returned

    raw = str(tn.read_until('root>'))

    #removing garbage i don't want

    #raw = raw.replace('\n\r>>>','')

    raw = raw.replace('\r','')

    #rawArr = raw.split('\n')

    #cleanArr =

    return raw



def startNos(tn):

        print "Starting NOS ..."

        print tn.read_until('root>', 0.01)

        tn.write("noscli\n")

        print tn.read_until("sw0#")



def NosCmd(tn, command):

    command = command.strip('\n')

    print tn.read_until('#', .01)

    #write the command

    if 'sh' in command:

       command = command + ' | nomore '

    tn.write(command + '\n')

    #read all data returned

    resp = str(tn.read_until('*'))

    print resp

    if '?' in resp:

       print "Respond with yes for any query\n"

       tn.write("y\n")

       resp = str(tn.read_util('#', 0.1))

    return resp

def TelnetToSw(host, user , password):

        print "Logging into host %s" % (host)

        tn = telnetlib.Telnet(host)

        print tn.read_until("login: ")

        tn.write(user + "\n")

        if password:

            print tn.read_until("Password: ")

            tn.write(password + "\n")



        print tn.read_until("proceed.")



        tn.write("\n")

        print tn.read_until("password:")

        tn.write("\n")

        print tn.read_until("manipulation error")

        return tn



def ExitSw(tn):

        tn.write(' \n')

        prompt = tn.read_until('*', 0.1)

        if '#' in prompt:

                tn.write("end\n")

                print tn.read_until("#")

                tn.write("exit\n")

        print tn.read_until('root>', 0.1)

        tn.write("exit\n")

if __name__ == "__main__":

        HOST = "10.24.85.83"

        user = raw_input("Enter your remote account: ")

        password = getpass.getpass()



        tn = TelnetToSw("10.24.85.83", "root", "fibranne")



        print FosCmd(tn, "hsl ifm show if")

        startNos(tn)

        print NosCmd(tn, "show ip inter brief | nomore")

        tn.close()


