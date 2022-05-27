import java.util.Scanner;

public class Pzckets{




   public static void main(String[] args){
      Scanner input = new Scanner(System.in);
      
      while(true){
         int one = input.nextInt();
         int two = input.nextInt();
         int three = input.nextInt();
         int four = input.nextInt();
         int five = input.nextInt();
         int six = input.nextInt();
         int boxes = 0;
         int sum = 0;
         if(one == 0 && two == 0 && three == 0 && four == 0 && five == 0 && six == 0)
            break;
         if(six > 0){
            boxes += six;
         }
         if(five > 0){
            boxes += five;
            one -= five * 11;   
         }
         if(four >  0){
            boxes += four;
            two -= four * 5;
         }
         if(three > 0){
            int tmp = three % 4;
            boxes += three / 4;
            if(tmp != 0){
               boxes += 1;
               if(tmp == 1){
                  two -= 5;
                  one -= 7;
               }else if(tmp == 2){
                  two -= 3;
                  one -= 6;
               }else if(tmp == 3){
                  two -= 1;
                  one -= 5;
               }

            }
         }
         if(two > 0){
            int tmp = two * 4;
            int remain = 36 * (tmp / 36 + 1) - tmp;
            if(tmp % 36 != 0){
               boxes += tmp / 36;
               boxes += 1;
            }else{
               boxes += tmp / 36;
            }
            one -= remain;
         }
         while(one > 0){
            one -= 36;
            boxes += 1;
         }
         
         System.out.println(boxes);
         
      }

   }
}