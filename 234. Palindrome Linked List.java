/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    // create find middle function
    public ListNode findMiddle(ListNode head) {
        // find middle by hare and turtle formula
        ListNode hare = head;
        ListNode turtle = head;

        while (hare.next != null && hare.next.next != null) {
            hare = hare.next.next;
            turtle = turtle.next;
        }

        // finally return the turtle position thats the first half last index
        return turtle;
    }

    // create reverse function
    public ListNode reverse(ListNode head){
        ListNode prev = null;
        ListNode curr = head;

        while(curr != null){
            ListNode next = curr.next;
            curr.next = prev; // reverse the link

            //update
            prev = curr;
            curr = next;
            
        }

        //return previous new head of the linked list
        return prev;
    }

    public boolean isPalindrome(ListNode head) {
        // base case:if no element thats palindrome
        if (head == null) {
            return true;
        }
        // base case:if one element that's palindrome
        if (head.next == null) {
            return true;
        }

        // find the middle
        ListNode middle = findMiddle(head);

        // find second half start node
        ListNode secondHalfStart = reverse(middle.next);

        // start first half head to end
        ListNode firstHalfStart = head;

        while (secondHalfStart != null) {
            // compare
            if (firstHalfStart.val != secondHalfStart.val) {
                return false;
            }
            firstHalfStart = firstHalfStart.next;
            secondHalfStart = secondHalfStart.next;
        }

        // if both are same
        return true;
    }
}
