class Solution {

    // Reverse a linked list
    private Node reverse(Node head) {
        Node prev = null;
        while (head != null) {
            Node next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    private Node removeLeadingZeros(Node head) {
    while (head != null && head.data == 0 && head.next != null) {
        head = head.next;
    }
    return head;
}


    public Node addTwoLists(Node head1, Node head2) {

        // 1. Reverse both lists
        head1 = reverse(head1);
        head2 = reverse(head2);

        int carry = 0;
        Node dummy = new Node(0);
        Node cur = dummy;

        // 2. Add digits
        while (head1 != null || head2 != null || carry != 0) {

            int sum = carry;

            if (head1 != null) {
                sum += head1.data;
                head1 = head1.next;
            }

            if (head2 != null) {
                sum += head2.data;
                head2 = head2.next;
            }

            cur.next = new Node(sum % 10);
            carry = sum / 10;
            cur = cur.next;
        }

        // 3. Reverse result back
        Node x=reverse(dummy.next);
        return removeLeadingZeros(x);
    }
}
