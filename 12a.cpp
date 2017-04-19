/*
Assignment No. 12	Roll No. 52
Title:	Implement the heap/shell sort alogorith implemented in java demonstrating 
	heap/shell data structure with modularity of programming language.
*/


import java.util.Random;
public class Shell_Sort 
{
    public static int N = 20;
    public static int[] sequence = new int[N];
    public static void shellSort() 
    {
        int increment = sequence.length / 2;
        while (increment > 0) 
        {
            for (int i = increment; i < sequence.length; i++) 
            {
                int j = i;
                int temp = sequence[i];
                while (j >= increment && sequence[j - increment] > temp) 
                {
                    sequence[j] = sequence[j - increment];
                    j = j - increment;
                }
                sequence[j] = temp;
            }
            if (increment == 2)
                increment = 1;
            else
                increment *= (5.0 / 11);
 
        }
    }

    static void printSequence(int[] sorted_sequence) 
    {
        for (int i = 0; i < sorted_sequence.length; i++)
            System.out.print(sorted_sequence[i] + " ");
    }
 
    public static void main(String args[]) 
    {
        System.out.println("Sorting of randomly generated numbers using SHELL SORT");
        Random random = new Random();
 
        for (int i = 0; i < N; i++)
            sequence[i] = Math.abs(random.nextInt(100));
 
        System.out.println("\nOriginal Sequence: ");
        printSequence(sequence);
 
        System.out.println("\nSorted Sequence: ");
        shellSort();
        printSequence(sequence);
    }
}

/**************************   OUTPUT   ***********************************

root@KALPESH:~/Desktop/ADS# javac Shell_Sort.java
root@KALPESH:~/Desktop/ADS# java Shell_Sort
Sorting of randomly generated numbers using SHELL SORT

Original Sequence: 
69 64 99 41 58 81 12 98 43 13 13 9 26 33 91 32 21 56 98 86 
Sorted Sequence: 
9 12 13 13 21 26 32 33 41 43 56 58 64 69 81 86 91 98 98 99

**************************************************************************/
