class  ListNode{
    int val; 
    ListNode next; 
    ListNode(int x) {
        val = x;
    }
}

class AddTwoNumber{
    public static ListNode addTwoNumber(ListNode l1, ListNode l2){
        ListNode ret = new ListNode(0);
        ListNode p = ret;
        int carry = 0;
        int lval, rval;

        while(l1 != null || l2 != null || carry > 0 ){
            p.next = new ListNode(0);
            p = p.next;

            lval = (l1 == null)? 0:l1.val;
            rval = (l2 == null)? 0:l2.val;
            int s = lval + rval + carry;
            p.val = s%10;
            carry = (int)(s/10);
            
            l1 = (l1 == null)? l1:l1.next; 
            l2 = (l2 == null)? l2:l2.next;
        }

        return ret.next;
    }

    public static void main(String[] args){
        ListNode l1 = new ListNode(5);
        ListNode l2 = new ListNode(5);
        ListNode sum = new ListNode(0);
        sum.next = new ListNode(1);

        ListNode ret = addTwoNumber(l1, l2);

        //compare
        while(sum != null || ret != null){
            if(sum == null || ret == null){
                System.out.println("Failed to test case");
                break;
            }
            if(sum.val  != ret.val ){
                System.out.println("Failed to test case");
                break;
            }
            sum = (sum == null)? sum: sum.next;
            ret = (ret == null)? ret: ret.next;
        }
        if(sum == null && ret == null){
            System.out.println("passed test case!");
        }
    }
}