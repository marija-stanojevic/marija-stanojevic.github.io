package assign4;


/** LinkedListRecTest.java
 *  The client class of LinkedListRec.
 *  Used to test the implementation of class LinkedListRec.
 */
public class LinkedListRecTest {

    public static void main(String[] args) {
        LinkedListRec<Integer> numbers = new LinkedListRec<>();
            
        // testing if it works for empty list
//        System.out.println(numbers.peekFront());
        System.out.println(numbers.peekEnd());
        numbers.removeFront();
        System.out.println(numbers);
        numbers.removeEnd();
        System.out.println(numbers);
        System.out.println(numbers.empty());
        numbers.insertBefore(100, 150);
        System.out.println(numbers);
        numbers.insertAfter(100, 175);
        System.out.println(numbers);
        numbers.addAtHead(100);
        System.out.println(numbers);
        numbers.removeFront(); //testing removal when there is only 1 element
        System.out.println(numbers);
        numbers.addAtEnd(100);
        System.out.println(numbers);
        numbers.removeEnd();  //testing removal when there is only 1 element
        System.out.println(numbers);
        
        numbers.addAtHead(100);
        System.out.println(numbers);
        numbers.insertAfter(100, 101); // when only 1 element
        System.out.println(numbers);
        numbers.insertAfter(101, 102); //after last element
        System.out.println(numbers);
        numbers.insertAfter(100, 105); // after first element
        System.out.println(numbers);
        numbers.insertBefore(100, 110); // before 1st element
        System.out.println(numbers);
        numbers.insertBefore(102, 112); // before last element
        System.out.println(numbers);
        numbers.insertBefore(105, 115); // before element in the middle
        System.out.println(numbers);
//        numbers.insertAfter(200, 150); // when target not in the list
//        System.out.println(numbers);
//        numbers.insertBefore(200, 150); // when target not in the list 
//        System.out.println(numbers);
        System.out.println(numbers.empty()); // empty when not empty
        
        System.out.println(numbers.peekFront()); // peekFront when many elements
        System.out.println(numbers.peekEnd()); // peekEnd when many elements
        numbers.removeEnd(); // remove end when many elements
        System.out.println(numbers);
        numbers.removeFront();  // remove front when many elements
        System.out.println(numbers);
        numbers.addAtHead(150); // when list has elements
        System.out.println(numbers);
        numbers.addAtEnd(151); // when list has elements
        System.out.println(numbers);
    }
}
