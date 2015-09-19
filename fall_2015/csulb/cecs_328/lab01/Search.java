import java.util.Random;
import java.util.Scanner;
import java.util.Arrays;

public class Search {
   public static Random random = new Random();
   
   public static int getArraySize() {
      Scanner sc = new Scanner(System.in);
      int n = 0;
      
      do {
         System.out.print("Please enter a positive integer: ");
         n = sc.nextInt();
      } while(n <= 0);
      
      return n;
   }
   
   public static int binarySearch(int[] a, int key) {
      return binarySearchHelpher(a, key, 0, a.length - 1);
   }
   
   private static int binarySearchHelpher(
      int[] a, int key, int left, int right) {
         
      int mid;
         
      while(left <= right) {
         mid = (left + right) / 2;
         if(a[mid] == key) {
            return mid;
         } else if(a[mid] < key) {
            left = mid + 1;
         } else {         
            right = mid - 1;
         }
      }
      
      return -1;
   }
   
   public static int linearSearch(int[] a, int key) {
      for(int i = 0; i < a.length; ++i) {
         if(a[i] == key) {
            return i;
         }
      }
      
      return -1;
   }
   
   public static void populateArray(int[] a, int min, int max) {
      int length = max - min + 1;
      
      for(int i = 0; i < a.length; ++i) {
         a[i] = random.nextInt(length) + min;
      }
   }
   
   public static int randomKey(int[] a) {
      return a[random.nextInt(a.length)];
   }
   
   public static void main(String[] args) {
      int n = getArraySize();
      
      int[] a = new int[n];
      populateArray(a, -100, 100);
      
      System.out.println("");
      
      int key = randomKey(a);
      
      System.out.format("Using Linear Search, %d was found at index: %d.\n",
         key, linearSearch(a, key));
         
      Arrays.sort(a);
         
      System.out.format("Using Binary Search, %d was found at index: %d.\n",
         key, binarySearch(a, key));
   }
}