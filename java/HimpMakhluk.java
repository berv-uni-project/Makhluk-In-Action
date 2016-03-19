/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.util.*;
/**
 *
 * PIC Unit : @author Joshua
 */
public class HimpMakhluk {

    /**
     * @param args the command line arguments
     */
    private final int MaxMakhluk= 1;
    private List<Makhluk> al;
    
    /**
     *konstruktor kelas HimpMakhluk
     */
    public HimpMakhluk(){
        al = new ArrayList<Makhluk>();
    }
    
    /**
     *Sebuah prosedur untuk menambahkan sebuah Makhluk ke dalam ArrayList
     * @param M merupakan Makhluk yang akan ditambahkan ke dalam ArrayList
     */
    public void AddMakhluk(Makhluk M){
        al.add(M);
    }
    
    /**
     *Sebuah fungsi yang mengembalikan Makhluk yang dihapus dari ArrayList dimana Makhluk tersebut memiliki powerlevel yang lebih kecil
     * @return Makhluk, merupakan Makhluk yang dihapus dari ArrayList
     */
    public Makhluk SurvFight(){
        /*Makhluk M = null;
        if(al.get(0).powerlevel > al.get(1).powerlevel) {
			M = DeleteMakhluk(al.get(1));
		} else {
			M = DeleteMakhluk(al.get(1));
		}
		return M;*/
        
        int temppower=al.get(0).powerlevel;
        int id=al.get(0).type;
		int idxfound = 0;
        for(int j=0;j<al.size();++j){
            if(temppower<al.get(j).powerlevel){
                temppower=al.get(j).powerlevel;
                idxfound = j;
            }
        }
		
		return DeleteMakhluk(al.get(idxfound));
		
    }
    
    /**
     *Sebuah fungsi yang akan mencari Makhluk dan menghapus Makhluk tersebut dari ArrayList
     * @param M merupakan masukan sebuah Makhluk yang akan dihapus
     * @return Makhluk, merupakan makhluk yang dihapus
     */
    public Makhluk DeleteMakhluk(Makhluk M){
        boolean found  = false;
		if(al.size()!=0){
            int i =0;
            while(i<al.size() && !found){
                if(al.get(i).type == M.type )
                    found = true;
                 else
                    ++i;
            }
			if(found) {
				Makhluk S = al.get(i);
				al.remove(i); 
				return S;
			}
			else {
				return null;
			}
        }
		else {
			return null;
		}
    }   
    
    /**
     *sebuah fungsi yang mengembalikan boolean apakah ArrayList penuh atau tidak
     * @return true/false, boolean apakah true atau false
     */
    public boolean isFull(){
        if(al.size()==MaxMakhluk){
            return true;
        }
        else{
            return false;
        }
    }
    
    /**
     *sebuah fungsi yang mengembalikan Makhluk di indeks ke i
     * @param i merupakan posisi indeks 
     * @return al.get(i), Makhluk yang merupakan di cari
     */
    public Makhluk GetMakhlukin(int i) {
		return al.get(i);
	}
	
    /**
     *sebuah fungsi yang mengembalikan integer, banyaknya Makhluk dalam ArrayList
     * @return al.size(), size daripada ArrayList
     */
    public int GetnMakhluk(){
        return al.size();
    }
    
    /**
     *sebuah fungsi yang mengembalikan integer yaitu banyaknya Maksimum Makhluk yang dapat ditampung dalam satu ArrayList
     * @return MaxMakhluk
     */
    public int GetMaxMakhluk(){
        return MaxMakhluk;
    }
    
    /**
     *sebuah fungsi yang mengembalikan boolean apakah size dari ArrayList lebih besar dari Maksimum Makhluk yang dapat ditampungg
     * @return true/false 
     */
    public boolean isOver(){
        return al.size()>MaxMakhluk;
    }
    
    /**
     *sebuah fungsi yang mengembalikan boolean dan mengecek apakah ArrayList kosong atau tidak
     * @return true/false
     */
    public boolean isEmpty(){
        return al.size()==0;
    }
    
    /**
     *sebuah fungsi yang mengembalikan Makhluk dan menghapus Makhluk dari ArrayList jika Makhluk tersebut sudah pindah
     * @param x, absis posisi dari Makhluk
     * @param y, ordinat posisi dari Makhluk
     * @return Makhluk, yang sudah berpindah
     */
    public Makhluk checkMoveMakhluk(int x, int y){
        //dianggap dalam suatu array hanya terdapat 1 makhluk
        Makhluk M = null;
        int i=0;
        int px,py;
        boolean end =false;
        while(i<al.size() && !end){
            px = al.get(i).x;
            py = al.get(i).y;
            if(px!=x || py!=y){
                 M = DeleteMakhluk(al.get(i));
                end = true;
            }
            else{
              ++i;  
            } 
        }
        
        return M;
    }
    
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package himpmakhluk;

import java.util.*;
/**
 *
 * PIC Unit : @author Joshua
 */
public class HimpMakhluk {

    /**
     * @param args the command line arguments
     */
    private final int MaxMakhluk= 1;
    private List<Makhluk> al;
    
    /**
     *konstruktor kelas HimpMakhluk
     */
    public HimpMakhluk(){
        al = new ArrayList<Makhluk>();
    }
    
    /**
     *Sebuah prosedur untuk menambahkan sebuah Makhluk ke dalam ArrayList
     * @param M merupakan Makhluk yang akan ditambahkan ke dalam ArrayList
     */
    public void AddMakhluk(Makhluk M){
        al.add(M);
    }
    
    /**
     *Sebuah fungsi yang mengembalikan Makhluk yang dihapus dari ArrayList dimana Makhluk tersebut memiliki powerlevel yang lebih kecil
     * @return Makhluk, merupakan Makhluk yang dihapus dari ArrayList
     */
    public Makhluk SurvFight(){
        /*Makhluk M = null;
        if(al.get(0).powerlevel > al.get(1).powerlevel) {
			M = DeleteMakhluk(al.get(1));
		} else {
			M = DeleteMakhluk(al.get(1));
		}
		return M;*/
        
        int temppower=al.get(0).powerlevel;
        int id=al.get(0).type;
		int idxfound = 0;
        for(int j=0;j<al.size();++j){
            if(temppower<al.get(j).powerlevel){
                temppower=al.get(j).powerlevel;
                idxfound = j;
            }
        }
		
		return DeleteMakhluk(al.get(idxfound));
		
    }
    
    /**
     *Sebuah fungsi yang akan mencari Makhluk dan menghapus Makhluk tersebut dari ArrayList
     * @param M merupakan masukan sebuah Makhluk yang akan dihapus
     * @return Makhluk, merupakan makhluk yang dihapus
     */
    public Makhluk DeleteMakhluk(Makhluk M){
        boolean found  = false;
		if(al.size()!=0){
            int i =0;
            while(i<al.size() && !found){
                if(al.get(i).type == M.type )
                    found = true;
                 else
                    ++i;
            }
			if(found) {
				Makhluk S = al.get(i);
				al.remove(i); 
				return S;
			}
			else {
				return null;
			}
        }
		else {
			return null;
		}
    }   
    
    /**
     *sebuah fungsi yang mengembalikan boolean apakah ArrayList penuh atau tidak
     * @return true/false, boolean apakah true atau false
     */
    public boolean isFull(){
        if(al.size()==MaxMakhluk){
            return true;
        }
        else{
            return false;
        }
    }
    
    /**
     *sebuah fungsi yang mengembalikan Makhluk di indeks ke i
     * @param i merupakan posisi indeks 
     * @return al.get(i), Makhluk yang merupakan di cari
     */
    public Makhluk GetMakhlukin(int i) {
		return al.get(i);
	}
	
    /**
     *sebuah fungsi yang mengembalikan integer, banyaknya Makhluk dalam ArrayList
     * @return al.size(), size daripada ArrayList
     */
    public int GetnMakhluk(){
        return al.size();
    }
    
    /**
     *sebuah fungsi yang mengembalikan integer yaitu banyaknya Maksimum Makhluk yang dapat ditampung dalam satu ArrayList
     * @return MaxMakhluk
     */
    public int GetMaxMakhluk(){
        return MaxMakhluk;
    }
    
    /**
     *sebuah fungsi yang mengembalikan boolean apakah size dari ArrayList lebih besar dari Maksimum Makhluk yang dapat ditampungg
     * @return true/false 
     */
    public boolean isOver(){
        return al.size()>MaxMakhluk;
    }
    
    /**
     *sebuah fungsi yang mengembalikan boolean dan mengecek apakah ArrayList kosong atau tidak
     * @return true/false
     */
    public boolean isEmpty(){
        return al.size()==0;
    }
    
    /**
     *sebuah fungsi yang mengembalikan Makhluk dan menghapus Makhluk dari ArrayList jika Makhluk tersebut sudah pindah
     * @param x, absis posisi dari Makhluk
     * @param y, ordinat posisi dari Makhluk
     * @return Makhluk, yang sudah berpindah
     */
    public Makhluk checkMoveMakhluk(int x, int y){
        //dianggap dalam suatu array hanya terdapat 1 makhluk
        Makhluk M = null;
        int i=0;
        int px,py;
        boolean end =false;
        while(i<al.size() && !end){
            px = al.get(i).x;
            py = al.get(i).y;
            if(px!=x || py!=y){
                 M = DeleteMakhluk(al.get(i));
                end = true;
            }
            else{
              ++i;  
            } 
        }
        
        return M;
    }
    
}
