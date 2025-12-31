/*
class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}*/

class Solution {
    public boolean isPalindrome(Node head) {
        // code here
        Node slow = head;
        Node fast = head;
        
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        
        Node prev = null;
        Node curr = slow;
        
        while(curr != null){
            Node next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        
        Node head1 = head;
        Node head2 = prev;
        
        while(head1 != null && head2 != null){
            if(head1.data != head2.data){
                return false;
            }
            
            head1 = head1.next;
            head2 = head2.next;
        }
        
        return true;
        
    }
}