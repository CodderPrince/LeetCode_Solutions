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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // base case
        if (head == null) {
            return null;

        }

        // size
        int size = 0;
        ListNode currNode = head;
        while (currNode != null) {
            size++;
            currNode = currNode.next;
        }

        // anothe base case
        if (size == n) {
            return head.next;
        }
        // previous Node
        int previousNodeIndex = size - n;
        ListNode prev = head;
        int i = 1;
        while (i < previousNodeIndex) {
            prev = prev.next;
            i += 1;
        }

        // break the condition
        prev.next = prev.next.next;
        return head;
    }
}
