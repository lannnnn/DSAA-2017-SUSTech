import java.util.Scanner;
import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;

public class LAB3_3 {
	public static void main(String[] args) {
		LinkedList<Integer> list = new LinkedList();
		LinkedList<Integer> list1 = new LinkedList();
		Scanner scan =  new Scanner(System.in);
		int cases = scan.nextInt();
		for(int i=0;i<cases;i++) {
			int num = scan.nextInt();
			list.clear();
			list1.clear();
			for(int j=0;j<num;j++) {
				int cv = scan.nextInt();
				list.addLast(cv);
			}
			num = scan.nextInt();
			for(int j = 0;j<num;j++) {
				int op = scan.nextInt();
				int pos,sol;
				Iterator it;
				switch(op){
					case 1 :  pos = scan.nextInt();
							  sol = scan.nextInt();
							  list.add(pos, sol);
							  it = list.iterator();
							  while(it.hasNext()) {
								  System.out.print(it.next()+" ");
							  }
							  System.out.println();
							  break;
					case 2 :  pos = scan.nextInt();
							  list.remove(pos);
							  it = list.iterator();
							  while(it.hasNext()) {
								  System.out.print(it.next()+" ");
							  }
							  System.out.println();
							  break;
					case 3 :  pos = scan.nextInt();
							  sol = scan.nextInt();
					          list.set(pos, sol);
					          it = list.iterator();
							  while(it.hasNext()) {
								  System.out.print(it.next()+" ");
							  }
							  System.out.println();
					          break;
					case 4 :  while(list.size() != 0) {
								  System.out.print(list.getLast() + " ");
								  list1.addLast(list.getLast());
								  list.removeLast();
							  }
							  list.addAll(list1);
							  list1.clear();
							  System.out.println();
							  break;
				}
			}

		}
	}
}
