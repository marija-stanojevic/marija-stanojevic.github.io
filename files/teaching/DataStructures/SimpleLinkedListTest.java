/*
 * Marija Stanojevic - TA at Data Structures Class, Temple University
 */
package assign2;

public class SimpleLinkedListTest {

    public static void main(String[] arg) {
        SimpleLinkedList list = new SimpleLinkedList();
        System.out.println(list.getHowMany());
        System.out.println(list.belongs(0));
        System.out.println(list.get(0));
        list.add(0, 10);
        System.out.println(list);
        System.out.println(list.get(0));
        System.out.println(list.getHowMany());
        list.add(0, 20);
        System.out.println(list);
        System.out.println(list.getHowMany());
        list.add(1, 30);
        System.out.println(list);
        System.out.println(list.get(-1));
        System.out.println(list.get(1));
        System.out.println(list.get(2));
        System.out.println(list.get(4));
        System.out.println(list.belongs(0));
        System.out.println(list.belongs(10));
        System.out.println(list.belongs(20));
        System.out.println(list.belongs(30));
        System.out.println(list.equals(null));
        SimpleLinkedList other = new SimpleLinkedList();
        System.out.println(list.equals(other));
        other.add(0, 10);
        System.out.println(list.equals(other));
        other.add(0, 20);
        other.add(1, 30);
        System.out.println(list.equals(other));
        System.out.println(list.removeByIndex(-1));
        System.out.println(list);
        System.out.println(list.removeByIndex(4));
        System.out.println(list);
        System.out.println(list.removeByIndex(2));
        System.out.println(list);
        System.out.println(list.removeByIndex(0));
        System.out.println(list);
        System.out.println(list.removeByValue(5));
        System.out.println(list);
        System.out.println(list.removeByValue(20));
        System.out.println(list);
        System.out.println(list.removeByValue(30));
        System.out.println(list);
        System.out.println(list.removeByValue(10));
        System.out.println(list);
        System.out.println(list.removeByIndex(0));
        System.out.println(list);
    }
}
