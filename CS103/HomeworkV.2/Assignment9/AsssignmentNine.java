/*Cameron Showalter
 * 4-15-2015
 * Assignment 7
 * All the problems inside one project. just comment in and out the methods inside the "+---+---+" for which queston
 * you're grading. All the methods are in order under it.
 * 
 * The "Warnings" are from some arrays not getting used in other questions.
 */

import java.util.*;
public class AsssignmentNine{
    public static void main(String[] args){                                            //Answers:
        int[] numbersOne = {74, 85, 102, 99, 101, 85, 56};                             //85
        int[] numbersTwo = {36, 12, 19, 46, 31, 22};                                   //35
        int[] numbersThree = {14, 1, 22, 17, 36, 7, -43, 5};                           //4
        double[] numbersFour1 = {16.1, 12.3, 22.2, 44.4};                              //false
        double[] numbersFour2 = {1.5, 4.3, 7.0, 19.5, 25.1, 46.2};                     //true
        int[] numbersSeven = {74, 85, 102, 99, 101, 56, 84};                           //99
        int[] numbersEight1 = {5, 2, 4, 17, 55, 4, 3, 26,18, 2, 17};                   //5
        int[] numbersEight2 = {42, 37, 1, 97, 1, 2, 7, 42, 3, 25, 89, 15, 10, 29, 27}; //25
        int[] numbersEleven1 = {3, 8, 12, 2, 9, 17, 43, -8, 46};                       //true
        int[] numbersEleven2 = {4, 7, 3, 9, 12, -47, 3, 74};                           //false
        int[] numbersFifteen1 = {7, 2, 8, 9, 4, 13, 7, 1, 9, 10};                      // 9 17 17 8 19
        int[] numbersFifteen2 = {1, 2, 3, 4, 5};                                       // 3 7 5
        int[] numbersSeventeen1 = {1, 2, 3, 4};                                        // 1 2 3 4 2 4 6
        int[] numbersSeventeen2 = {2, 4, 6};                                           // 2 4 6 1 2 3 4 
   
        int valueIndex = 5; //used in question 1
        int min = 4;        //used in question 3
        int max = 17;       //used in question 3
        int k = 2;          //used in question 7
        
   //Start here:
          //+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
        //System.out.println("Value at index " + valueIndex + ": " + valueAt(numbersOne, valueIndex));                //question 7.1
        //System.out.println("Range of Array: " + range(numbersTwo));                                                 //question 7.2
        //System.out.println("values inside " + min + " and " + max + ": " + valuesInside(numbersThree, min, max));   //question 7.3
        //System.out.println("Array one: " + isSorted(numbersFour1));                                                 //question 7.4.1
        //System.out.println("Array two: " + isSorted(numbersFour2));                                                 //question 7.4.2
        //System.out.println("The " + (k+1)  + " largest number is: " + largestMinusK(numbersSeven, k));              //question 7.7
        //System.out.println("Median of this array is: " + median(numbersEight1));                                    //question 7.8.1
        //System.out.println("Median of this array is: " + median(numbersEight2));                                    //question 7.8.2
        //System.out.println("Any values repeat?: " + isUnique(numbersEleven1));                                      //question 7.11.1
        //System.out.println("Any values repeat?: " + isUnique(numbersEleven2));                                      //question 7.11.2
        //System.out.println("Array crunched: " + crunch(numbersFifteen1));                                           //question 7.15.1
        //System.out.println("Array crunched: " + crunch(numbersFifteen2));                                           //question 7.15.2
        //System.out.println("Merged arrays: " + merge(numbersSeventeen1, numbersSeventeen2));                        //qusetion 7.16.1
        //System.out.println("Merged arrays: " + merge(numbersSeventeen2, numbersSeventeen1));                        //question 7.16.2
          //+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
    }
    
    //7.1 Returns a value at index of your choice if the choice is withen bounds
    public static int valueAt(int[] numbers, int valueIndex){
        if(numbers.length -1 >= valueIndex && valueIndex >= 0){
            return numbers[valueIndex];
        }
        else{
            return -1;
        }
    }
    
    //7.2 returns the range (Biggest value - Smallest value + 1)
    public static int range(int[] numbers){
        Arrays.sort(numbers);
        return numbers[numbers.length-1] - numbers[0] + 1;
    }
    
    //7.3 when a value is between min and max of the array, increment count
    public static int valuesInside(int[] numbers, int min, int max){
        int count = 0;
        for(int i = 0; i<numbers.length; i++){
            if(numbers[i] <= max && numbers[i] >= min){
                count++;
            }
        }
        return count;
    }
    
    //7.4 checks to see if array is sorted in assending order. if so return true else return false
    public static boolean isSorted(double[] numbers){
        double sorter = numbers[0];
        for(int i = 1; i<numbers.length; i++){
            if(sorter <= numbers[i]){
                sorter = numbers[i];
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    //7.7 returns the largest value in the array - indexOf K (assuming k is a "good imput" and wont break)
    public static int largestMinusK(int[] numbers, int k){
        Arrays.sort(numbers);
        return numbers[numbers.length-1-k];
    }
    
    //7.8 returns the median of the array (assuming array is odd)
    public static int median(int[] numbers){
        Arrays.sort(numbers);
        return numbers[numbers.length/2];
    }
    
    //7.11 makes sure there are no coppies of a value inside a array
    public static boolean isUnique(int[] numbers){
        for(int i=0; i<numbers.length; i++){
            for(int j=0; j<numbers.length; j++){
                if(i != j){
                    if(numbers[i] == numbers[j]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    //7.15 crunches the array by making [a, b, c, d, e] becoming [a+b, c+d, e]
    public static String crunch(int[] numbers){
        int last = numbers.length;
        int count = 0;
        int temp = 0;
        String itsTooLate = "";
        if(numbers.length%2==0){
            temp = last/2;
        }
        else{
            temp = last/2+1;
        }
        int[] crunch = new int[temp];
        for(int i=0; i<numbers.length; i+=2){
            if(numbers.length > i+1){
                crunch[count] = numbers[i] + numbers[i+1];
                count++;
            }
            else if(numbers.length == i+1){
                crunch[count] = numbers[i];
                count++;
            }
        }
        for(int i=0; i<crunch.length; i++){
            itsTooLate = itsTooLate + " " + crunch[i];
        }
     return itsTooLate;
    }
    
    //7.16 merges two arrays [a, b, d] + [c, e] = [a, b, d, c, e]
    public static String merge(int[] numbersOne, int[] numbersTwo){
        int temp = numbersOne.length + numbersTwo.length;
        int[] merged = new int[temp];
        String newArray = "";
        for(int i=0; i<numbersOne.length; i++){
            merged[i] = numbersOne[i];
        }
        for(int i=numbersOne.length; i<merged.length; i++){
            merged[i] = numbersTwo[i - numbersOne.length];
        }
        for(int i=0; i<merged.length; i++){
            newArray = newArray + " " + merged[i];
        }
        return newArray;
    }
}