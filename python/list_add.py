#!/usr/bin/python
# Definition for singly-linked list.

class ListNode(object):

     def __init__(self, x):

         self.val = x

         self.next = None

class Solution:

    def addTwoNumbers(self, l1, l2):

        """

        :type l1: ListNode

        :type l2: ListNode

        :rtype: ListNode

        """

        if (l1 is None or l2 is None):

            return ListNode(0)

        if (l1 == None and l2 != None):

            return l2

        if (l1 != None and l2 == None):

            return l1

            

        carry = 0

        main_ret = ListNode(-1) # List head

        ret = main_ret

        while ((l1 != None) or (l2 != None)):

            rslt = 0

            if ((l1 != None) and (l2 != None)):

                rslt = l1.val + l2.val + carry

                carry = 0

                if (rslt >= 10):

                    carry = 1

                    rslt = rslt - 10

                

                l1 = l1.next

                l2 = l2.next

            elif (l1 is not None):

                rslt = l1.val + carry

                carry = 0

                if (rslt >= 10):

                    carry = 1

                    rslt = rslt - 10
                    l1 = l1.next
                else:

                    ret.next = ListNode(rslt)

                    ret.next.next = l1.next

                    break

            else:

                rslt = l2.val + carry

                carry = 0

                if (rslt >= 10):

                    carry = 1

                    rslt = rslt - 10
                    l2 = l2.next
                else:

                    ret.next = ListNode(rslt)

                    ret.next.next = l2.next

                    break

                  

            if (ret.val == -1):

                ret.val = rslt

            else:

                ret.next = ListNode(rslt)

                ret = ret.next

            

                

        if (carry != 0):

            ret.next = ListNode(carry)

        

        return main_ret

l1 = ListNode(1)
l2 = ListNode(9)
l2.next = ListNode(9)

C = Solution()
l3 = C.addTwoNumbers(l1, l2)

while (l3 != None):
   print "%d " % l3.val
   l3 = l3.next
