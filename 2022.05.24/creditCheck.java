import java.util.Scanner;
public class creditCheck {


	static public void main(String[] args){
		Scanner input = new Scanner(System.in);
		int datas = input.nextInt();
		for (int i = 0; i < datas; i++){
			String a = input.next();
			String b = input.next();
			String c = input.next();
			String d = input.next();
			int sum = 0;
			sum += Character.getNumericValue(a.charAt(1));
			sum += Character.getNumericValue(a.charAt(3));
			sum += Character.getNumericValue(b.charAt(1));
			sum += Character.getNumericValue(b.charAt(3));
			sum += Character.getNumericValue(c.charAt(1));
			sum += Character.getNumericValue(c.charAt(3));
			sum += Character.getNumericValue(d.charAt(1));
			sum += Character.getNumericValue(d.charAt(3));
			sum = sum + Character.getNumericValue(a.charAt(0)) * 2 % 10 + Character.getNumericValue(a.charAt(0)) * 2 / 10;
			sum = sum + Character.getNumericValue(a.charAt(2)) * 2 % 10 + Character.getNumericValue(a.charAt(2)) * 2 / 10;
			sum = sum + Character.getNumericValue(b.charAt(0)) * 2 % 10 + Character.getNumericValue(b.charAt(0)) * 2 / 10;
			sum = sum + Character.getNumericValue(b.charAt(2)) * 2 % 10 + Character.getNumericValue(b.charAt(2)) * 2 / 10;
			sum = sum + Character.getNumericValue(c.charAt(0)) * 2 % 10 + Character.getNumericValue(c.charAt(0)) * 2 / 10;
			sum = sum + Character.getNumericValue(c.charAt(2)) * 2 % 10 + Character.getNumericValue(c.charAt(2)) * 2 / 10;
			sum = sum + Character.getNumericValue(d.charAt(0)) * 2 % 10 + Character.getNumericValue(d.charAt(0)) * 2 / 10;
			sum = sum + Character.getNumericValue(d.charAt(2)) * 2 % 10 + Character.getNumericValue(d.charAt(2)) * 2 / 10;
			// System.out.println(sum);
			if(sum % 10 == 0){
				System.out.println("Valid");
			}else{
				System.out.println("Invalid");
			}


		}
	}




}