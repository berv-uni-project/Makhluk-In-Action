import java.io.FileNotFoundException;
import java.util.Random;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * @author Bervianto Leo P - 13514047
 * */

public class ControlCommand {
	/**
	 * Cell sebagai penyimpan kumpulan makhluk, setiap sel dapat menyimpan banyak makhluk dan akan dipertarungkan
	 * nTotalMakhluk sebagai status jumlah makhluk yang sedang ada pada petak
	 * panjang sebagai status panjang petak
	 * lebar sebagai status lebar petak
	 * MaxTotalMakhluk sebagai status jumlah maksimum makhluk yang diperbolehkan (membatasi pertumbuhan makhluk)
	 * Creature sebagai status makhluk apa saja yang ada pada petak
	 * */
	private HimpMakhluk[][] Cell;
	private	int nTotalMakhluk;
	private int panjang;
	private int lebar;
	private static int MaxTotalMakhluk;
	private Makhluk[] Creature;
    
    /**
     * Sebagai status pause
     */
    public boolean Pause;

    /**
     * Sebagai status keluar
     */
    public boolean Exit;

    /**
     * Sebagai status screenshot
     */
    public boolean Screenshot;

    /**
     * Sebagai status step-by-step
     */
    public boolean Step;

    /**
     * Sebagai status spawn
     */
    public boolean Spawn;
        
	/**
	 * Konstruktor dengan nilai default
	 * panjang = 10
	 * lebar = 10
	 * Maksimum Makhluk = 30
	 * */
	public ControlCommand() {
		MaxTotalMakhluk = 30;
		this.panjang = 10;
		this.lebar = 10;
		
		Cell = new HimpMakhluk[panjang][lebar];
		for(int i=0;i<this.panjang;i++) { 
			for(int j =0;j<this.panjang;j++) {
				Cell[i][j] = new HimpMakhluk();
			}
		}
		Creature = new Makhluk[MaxTotalMakhluk];
                Pause = false;
                Exit = false;
                Screenshot= false;
                Step = false;
                Spawn = false;
	}
	
	/**
	 * Konstruktor
	 * @param _panjang sebagai inisialisasi panjang dari suatu petak
	 * @param _lebar sebagai inisialisasi lebar dari suatu petak
	 * Maksimum makhluk = panjang * lebar
	 * */
	public ControlCommand(int _panjang, int _lebar) {
		MaxTotalMakhluk = _panjang*_lebar;
		this.panjang = _panjang;
		this.lebar = _lebar;
		
		Cell = new HimpMakhluk[this.panjang][this.lebar];
		for(int i=0;i<this.panjang;i++) { 
			for(int j =0;j<this.panjang;j++) {
				Cell[i][j] = new HimpMakhluk();
			}
		}
		Creature = new Makhluk[MaxTotalMakhluk];
                Pause = false;
                Exit = false;
                Screenshot= false;
                Step = false;
                Spawn = false;
        }
	
	/**
	 * Konstruktor
	 * @param _panjang sebagai inisialisasi panjang dari suatu petak
	 * @param _lebar sebagai inisialisasi lebar dari suatu petak
	 * @param max sebagai maksimum makhluk yang boleh ada di petak
	 * */
	public ControlCommand(int _panjang, int _lebar, int max) {
		MaxTotalMakhluk = max;
		this.panjang = _panjang;
		this.lebar = _lebar;
		
		Cell = new HimpMakhluk[this.panjang][this.lebar];
		for(int i=0;i<this.panjang;i++) { 
			for(int j =0;j<this.panjang;j++) {
				Cell[i][j] = new HimpMakhluk();
			}
		}
		Creature = new Makhluk[MaxTotalMakhluk];
                Pause = false;
                Exit = false;
                Screenshot= false;
                Step = false;
                Spawn = false;
        }
	
	/**
	 * Sebagai fungsi mengembalikan nilai jumlah makhluk yang sedang ada di petak
	 * @return nTotalMakhluk sebagai nilai kembalian jumlah makhluk yang sedang ada di petak
	 * */
	public int TotalMakhlukinPetak() {
		return nTotalMakhluk;
	}
	
	/**
	 * Sebagai fungsi mengembalikan nilai jumlah maksimum makhluk yang dibolehkan pada petak
	 * @return MaxTotalMakhluk sebagai nilai kembalian jumlah makhluk yang dibolehkan pada petak
	 * */
	public static int GetMaxTotalMakhluk() {
		return MaxTotalMakhluk;
	}
	
	/**
	 * Fungsi untuk menghidupkan sebuah makhluk dan memunculkan pada petak
	 * Makhluk akan diletakkan pada posisi acak
	 * @return M sebagai kembalian makhluk apa yang akan dimunculkan
	 * */
	public Makhluk spawn() {
		Random rnd = new Random();
		int baris = rnd.nextInt(panjang-1);
		int kolom = rnd.nextInt(lebar-1);
		int tipe = rnd.nextInt(5) + 1;
		Makhluk M;
		
		switch (tipe)
		{
		case 1:
			M = new MakhlukAntiAir(baris, kolom);
			break;
		case 2:
			M = new MakhlukBurukRupa(baris, kolom);
			break;
		case 3:
			M = new MakhlukMaling(baris, kolom);
			break;
		case 4:
			M = new MakhlukMonster(baris, kolom);
			break;
		case 5:
			M = new MakhlukTerbang(baris, kolom);
			break;
		default:
			M = new MakhlukAntiAir(baris, kolom);
		} 
		
		
		Cell[baris][kolom].AddMakhluk(M);
		nTotalMakhluk++;		
		return M;
	}
	
	/**
	 * Fungsi untuk menghidupkan sebuah makhluk dan memunculkan pada petak
	 * Makhluk akan diletakkan pada posisi acak
	 * @param i parameter untuk lokasi x dalam petak
	 * @param j parameter untuk lokasi y dalam petak
	 * @param t parameter tipe makhluk yang akan ditampilkan
	 * @return M sebagai kembalian makhluk apa yang akan dimunculkan
	 * */
	public Makhluk spawn(int i, int j, int t) {
		int baris = i;
		int kolom = j;
		int tipe = t;
		Makhluk M = null;
		switch (tipe)
		{
			case 1 :
				M = new MakhlukAntiAir(baris, kolom);
				break;
			case 2 :
				M = new MakhlukBurukRupa(baris, kolom);
				break;
			case 3 :
				M = new MakhlukMaling(baris, kolom);
				break;
			case 4 :
				M = new MakhlukMonster(baris, kolom);
				break;
			case 5 :
				M = new MakhlukTerbang(baris, kolom);
				break;
			default :
				M = new MakhlukAntiAir(baris, kolom);
		}
		Cell[baris][kolom].AddMakhluk(M);
		nTotalMakhluk++;
		return M;
	}
	
	/**
	 * Prosedur mengecek perpindahan suatu makhluk dan memperbarui status lokasi makhluk pada petak
	 * @param i lokasi yang ingin dipastikan (x) pada petak
	 * @param j lokasi yang ingin dipastikan (y) pada petak
	 * */
	public void MoveMakhluk(int i, int j) {
		boolean exit = false;
		if (!Cell[i][j].isEmpty())
		{
			while (Cell[i][j].isOver())
			{
				Makhluk N = Cell[i][j].SurvFight();
				deleteMakhluk(N);
			}
			Makhluk M;
			do
			{
				M = Cell[i][j].checkMoveMakhluk(i,j);
				if (M!=null)
				{
					int x = M.getX();
					int y = M.getY();
					int umur = M.getagenow();
					int umurmax = M.getage();

					if ((x < panjang) && (y < lebar) && (x >= 0) && (y >= 0) && (umur <= umurmax))
					{
						if (Cell[x][y].isFull())
						{
							Cell[x][y].AddMakhluk(M);
							Makhluk N = Cell[x][y].SurvFight();
							deleteMakhluk(N);
						}
						else
							Cell[x][y].AddMakhluk(M);
					}
					else
					{
						deleteMakhluk(M);
						M = Cell[i][j].checkMoveMakhluk(i,j);
						if (M==null)
							exit = true;
					}
				}
			} while ((M != null)&&(!exit));
		}	
	}
	
	/**
	 * Prosedur mengperbarui tampilan
	 * @param V sebagai pengontrol tampilan
	 * */
	public void updateWorld(View V) {
		for (int i = 0; i < panjang; i++)
		{
			for (int j = 0; j < lebar; j++)
			{
				MoveMakhluk(i, j);
			}
		}

		for (int i=0; i < panjang; i++)
		{
			for (int j=0; j < lebar; j++)
			{
				for(int k=0;k<Cell[i][j].GetnMakhluk();++k){
						Makhluk R = Cell[i][j].GetMakhlukin(k);
						V.ShowBentuk(R.gettype());
					}
				int n = Cell[i][j].GetnMakhluk();
				int max = Cell[i][j].GetMaxMakhluk();
				for (int k = n; k<max; k++)
					 System.out.print(" ");
				System.out.print("|");
			}
			System.out.println();
		}
	}
	
	/**
	 * Prosedur menghapus makhluk pada suatu petak
	 * @param M untuk identifikasi makhluk yang ingin dihapus
	 * */
	public void deleteMakhluk(Makhluk M){
		for (int i = 0; i < this.MaxTotalMakhluk; i++)
		{
			if (M == Creature[i])
			{
				Creature[i] = null;
				this.nTotalMakhluk--;
			}
		}
		M = null;
	}
	
	/**
	 * Prosedur untuk secara otomatis membangkitkan makhluk baru
	 * */
	public void AutoSpawn() {
		int i=0;
		while ((Creature[i]!=null)&&(i<MaxTotalMakhluk))
			i++;

		if (Creature[i]==null)
			Creature[i] = spawn();
	}
	
    /**
     * Memulai sebuah program
     * @throws IOException
     * @throws InterruptedException
     */
    public void start() throws IOException,InterruptedException {
		View V = new View();
		int delT = 0;
		Random rnd = new Random();
		int t =  rnd.nextInt(MaxTotalMakhluk/4) + (MaxTotalMakhluk/6);
		for(int i = 0;i<t;i++) {
			this.Creature[i] = this.spawn();
			try {
				Thread.sleep(250);
			} catch (InterruptedException ex) {
				Thread.currentThread().interrupt();
			}
			new ProcessBuilder("cmd","/c","cls").inheritIO().start().waitFor();
			float load = 100*i/(float)t;
			System.out.println("Now loading " + load + " %");
		}
		new ProcessBuilder("cmd","/c","cls").inheritIO().start().waitFor();
		System.out.println("Now loading " + 100 + " %");
		boolean stop = false;
		while ((TotalMakhlukinPetak()) > 0 && !stop )
		{	//pause
			Pause();
			//Exit
            Exit();
			//screenshot
			Screenshot(V);
			//spawn
			Spawn(V);
			//step by step execution 
			while(Step){
				int z=0;
				while(z<10) {
					if (delT == 10000)
						delT = 0;
						delT++;
                        Step(delT);
                        ++z;
					}
                    new ProcessBuilder("cmd","/c","cls").inheritIO().start().waitFor();
                    updateWorld(V);
                    System.out.println ();
                    System.out.println("Step-by step execution 0.1 second");
                    Step = false;
                    Pause = true;
                    Pause();
                }
			new ProcessBuilder("cmd","/c","cls").inheritIO().start().waitFor();
			updateWorld(V);
			System.out.println();
			if (delT == 10000)
				delT = 0;
			delT++;
			try {
				Thread.sleep(250);
			} catch (InterruptedException ex) {
				Thread.currentThread().interrupt();
			}
			Step(delT);
		}
	new ProcessBuilder("cmd","/c","cls").inheritIO().start().waitFor();
	System.out.println();
	System.out.println("========================");
	System.out.println("Semua makhluk telah mati");
	System.out.println("      GAME OVER");
	System.out.println("========================");
	System.out.println();
	System.out.println("Press any key to exit");
	//Runtime.getRuntime().exec("pause>nul");
	}
	
    /**
     * Memberhentikan sementara program
     * @throws InterruptedException
     */
    public void Pause() throws InterruptedException{
            if(Pause){
                System.out.println("Paused..... Press R in KeyListener to resume");
            }
            while(Pause){
                Thread.sleep(1);
            }
        }
        
    /**
     * Keluar dari program
     * @throws InterruptedException
     */
    public void Exit() throws InterruptedException{
            if(Exit){    
                System.out.println();
                System.out.println("===================================");
                System.out.println("Anda Telah Menekan ESC Untuk Keluar");
                System.out.println("            GAME OVER");
                System.out.println("===================================");
                System.out.println();
                //System.out.println("Press any key to exit");
                Pause = true;
                // C.Pause = true;
                Pause();
                System.exit(0);
            }
        }
        
    /**
     * Menyimpan tampilan pada saat tertentu
     * @param V sebagai viewer
     * @throws InterruptedException
     * @throws FileNotFoundException
     */
    public void Screenshot(View V) throws InterruptedException, FileNotFoundException{
            if(Screenshot){
                System.out.println("Screenshot telah disimpan!" );
		PrintToFile(V);
		System.out.println("Press any key to continue");
		Pause = true;
                Pause();
                Screenshot = false;
            }
        }
        
    /**
     * Menulis isi matriks ke dalam file
     * @param V sebagai viewer
     * @throws FileNotFoundException
     */
    public void PrintToFile(View V) throws FileNotFoundException{
            PrintWriter f = new PrintWriter("screenshot.txt");
            for(int i=0;i<panjang;i++) {
                for(int j=0;j<lebar;j++) {
                    for(int k=0;k<Cell[i][j].GetnMakhluk();++k){
				Makhluk R = Cell[i][j].GetMakhlukin(k);
				f.print(V.GetBentuk(R.gettype()));
                    }
                    int n = Cell[i][j].GetnMakhluk();
                    int max = Cell[i][j].GetMaxMakhluk();
                    for (int k = n; k<max; k++)
			 f.print(" ");
                         f.print("|");
                    }
                    f.println();
            }
            f.close();
        }
        
    /**
     * Memunculkan berbagai makhluk
     * @param V sebagai viewer
     * @throws IOException
     * @throws InterruptedException
     */
    public void Spawn(View V) throws IOException, InterruptedException{
            while(Spawn){
                
                if (nTotalMakhluk < MaxTotalMakhluk)
                {
                        new ProcessBuilder("cmd","/c","cls").inheritIO().start().waitFor();
                        AutoSpawn();
                        updateWorld(V);
                        System.out.println( " Telah Muncul Satu Makhluk Baru!" );
                        System.out.println ("Press any key to continue" );
                        
                }else{
                    System.out.println("Map Is FULL");
                }
                Spawn = false;
                Pause = true;
                Pause();
            }
        }
        
    /**
     * Menggerakan step by step
     * @param delT sebagai masukan deltaT saat itu
     */
    public void Step(int delT)
	{	
		for (int i = 0; i < MaxTotalMakhluk; i++)
		{
			if (Creature[i] != null)
			{
				Creature[i].move();
			}
		}
		if (nTotalMakhluk<MaxTotalMakhluk)
		{
			Random rand = new Random();
			if ( delT % 2 == 0)
			{
				int x1 = rand.nextInt(20);
				int x2 = rand.nextInt(5);
				if (x1 < x2)
					AutoSpawn();
			}
			else
			{
				int x1 = rand.nextInt(5);
				int x2 = rand.nextInt(10) + 2;
				if (x1 >= x2)
					AutoSpawn();
			}
		}
	}	
}

	
