/**
 * @author uknown - 13514000
 * */

public class View {
	/**
	 * Prosedur menampilkan bentuk dengan suatu parameter
	 * @param a, sebagai parameter untuk menampilkan sesuatu
	 * */
	public void ShowBentuk(int a) {
		if(a == 1){
			System.out.print('*');
		}
		else if(a == 2){
			System.out.print('%');
		}
		else if(a == 3) {
			System.out.print('$');
		}
		else if(a == 4 ){
			System.out.print('@');
		}
		else if ( a==5){
			System.out.print('~');
		} else {
			System.out.print(' ');
		}
	}
	
	/**
	 * fungsi mendapatkan indikator suatu bentuk dan mengembalikan suatu bentuk
	 * @param a, sebagai indikator untuk memberikan bentuk
     * @return 
	 * */
	public char GetBentuk(int a) {
		if (a == 1){
			return '*';
		}
		else if (a == 2){
			return '%';
		}
		else if (a == 3) {
			return '$';
		}
		else if (a == 4){
			return '@';
		}
		else if (a == 5){
			return '~';
		} else {
			return ' ';
		}
	}
}
