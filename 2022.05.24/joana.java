import java.util.Scanner;

public class joana{


	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		int datas = input.nextInt();
		for (int i = 0; i < datas; i++){
			int row = input.nextInt();
			row = row / 2 + 1;
			int lastNum = row * row * 2 - 1;
			long num = 1;
			num *= lastNum;
			num *= (lastNum - 2);
			num *= (lastNum - 4);
			System.out.println(num);
		}
	}
}