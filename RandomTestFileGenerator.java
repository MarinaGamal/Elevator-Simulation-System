package general;
import java.util.*;

public class RandomTestFileGenerator {

    public static int randInt(int min, int max) 
    {
    Random rand = new Random();
    int randomNum = rand.nextInt((max - min) + 1) + min;

    return randomNum;
    }
    
    public static void main(String[] args)
    {
        System.out.println(randInt(0,10));
        for(int i=0 ; i < 10 ; i++)
        {
            System.out.println(randInt(1,2));
            System.out.println(randInt(0,10));
        }
            
        for(int i=0 ; i < randInt(2,6) ; i++)
            System.out.println(4);
        
        System.out.println(3);
        
        for(int i=0 ; i < 10 ; i++)
        {
            System.out.println(randInt(1,2));
            System.out.println(randInt(0,10));
        }
        
        for(int i=0 ; i < randInt(2,6) ; i++)
            System.out.println(4);
        
        System.out.println(3);
        System.out.println(6);
    }
    
}
