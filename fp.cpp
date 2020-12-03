#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip> //column
#include <cstdlib>
#include <cctype> //tolower
#include <ctime> //time
#include <fstream> //output file

#define max 5
using namespace std;

struct layanan{
	 int harga;
	 string nama;
};
// deklarasi struct untuk queue pelanggan
struct antrian_pelanggan{
	int awal;
	int akhir;
	string nama[max];
	string nohp[max];
}antrian;

// prototype function
void footerSub();
void footer();
void panggilAntrian();
void tampilPelanggan();
void init();
void header();
void registrasi();
void searchData();
bool isFull();
bool isEmpty();
string getLine();
void ascendingSort(layanan array[],int size);
void descendingSort(layanan array[],int size);
void showArray(layanan array[],int size);


int main()
{
	
	string pilihanUser;
	system("cls");
	init();
	do {
		system("cls");
		header();
	cout<<"\t\t\t\t\t| Menu Utama   :                                                |"<<endl;
	cout<<"\t\t\t\t\t|                                                               |"<<endl;
	cout<<"\t\t\t\t\t|    [1] Registrasi                                             |"<<endl;
	cout<<"\t\t\t\t\t|                                                               |"<<endl;
	cout<<"\t\t\t\t\t|    [2] Panggil Antrian                                        |"<<endl;
	cout<<"\t\t\t\t\t|                                                               |"<<endl;
	cout<<"\t\t\t\t\t|    [3] Cari Antrian                                           |"<<endl;
	cout<<"\t\t\t\t\t|                                                               |"<<endl;
	cout<<"\t\t\t\t\t|    [4] Print                                                  |"<<endl;
	cout<<"\t\t\t\t\t|                                                               |"<<endl;
	cout<<"\t\t\t\t\t|    [5] Keluar                                                 |"<<endl;
	cout<<"\t\t\t\t\t|                                                               |"<<endl;
	cout<<"\t\t\t\t\t|    [0] Clear                                                  |"<<endl;
	cout<<"\t\t\t\t\t|                                                               |"<<endl;
	cout<<"\t\t\t\t\t|===============================================================|"<<endl;
		pilihanUser:
		cout<<"\n\t\t\t\tMasukkan Pilihan Anda 	: ";
		cin>>pilihanUser;

		if (pilihanUser == "1"){
			registrasi();
		}else if (pilihanUser == "2"){
			panggilAntrian();
		}else if (pilihanUser == "3"){
			searchData();
		}else if (pilihanUser == "4"){
			tampilPelanggan();
		}else if (pilihanUser == "5"){
			footer();
		}else if(pilihanUser == "0"){
			init();
		}else{
			cout<<"\t\t\t\t Pilihan yang anda masukkan salah !!!";
			goto pilihanUser;
		}

	}while(pilihanUser!="5");

	cin.get();
	return 0;
}

// Membuat function menampilkan footer untuk setiap submenu 
void footerSub(){
	cout<<"\t\t\t\t\t|---------------------------------------------------------------|"<<endl;	
	cout<<"\t\t\t\t\t|                                                               |"<<endl;
	cout<<"\t\t\t\t\t|===============================================================|"<<endl;
	cout<<"\t\t\t\t\t|                                                               |"<<endl;
	cout<<"\t\t\t\t\t|                   https://ridwaneka.id/                       |"<<endl;
	cout<<"\t\t\t\t\t|                                                               |"<<endl;
	cout<<"\t\t\t\t\t|===============================================================|"<<endl;
	cout<<"\t\t\t\tTekan apapun yang kamu suka untuk kembali ke menu utama........."<<endl;
}

// Membuat function menampilkan footer 
void footer(){
	system("cls");
	header();
	cout<<"\t\t\t\t\t|                                                               |"<<endl;
	cout<<"\t\t\t\t\t|                                                               |"<<endl;
	cout<<"\t\t\t\t\t|               TERIMAKASIH ATAS KUNJUNGAN ANDA                 |"<<endl;
	cout<<"\t\t\t\t\t|         Mampir Lagi ya biar kami cepet naik haji :)           |"<<endl;
	cout<<"\t\t\t\t\t|                                                               |"<<endl;
	cout<<"\t\t\t\t\t|                                                               |"<<endl;
	cout<<"\t\t\t\t\t|                   https://ridwaneka.id/                       |"<<endl;
	cout<<"\t\t\t\t\t|===============================================================|"<<endl;

	getch();
}

// Dequeue
void panggilAntrian(){
	if (isEmpty())
	{
		system("cls");
		header();
		cout<<"\t\t\t\t\t|                 MAAF,BELUM ADA PELANGGAN HARI INI             |"<<endl;
		cout<<"\t\t\t\t\t|                                                               |"<<endl;
	}else{
		order:
		system("cls");
		header();
		int keperluan,biaya,jumlahPrint;
		// deklarasi struct utk layanan
		const int size = 11;
		layanan values [size];

		values[0].harga = 4000;
		values[0].nama  = "Kertas BWS";
		values[1].harga = 2000;
		values[1].nama  = "HVS BW A3+";
		values[2].harga = 4500;
		values[2].nama  = "HVS FC A3+";
		values[3].harga = 4700;
		values[3].nama  = "Matte Paper 120gr";
		values[4].harga = 4900;
		values[4].nama  = "Matte Paper 150gr";
		values[5].harga = 4600;
		values[5].nama  = "Ivory 230gr";
		values[6].harga = 5000;
		values[6].nama  = "Ivory 260gr";
		values[7].harga = 5200;
		values[7].nama  = "Linen/Hammer";
		values[8].harga = 1900;
		values[8].nama  = "Cromo";
		values[9].harga = 1500;
		values[9].nama  = "Vinyl";
		values[10].harga = 1000;
		values[10].nama  = "Satin";

		
		cout<<"\t\t\t\t\t|                        Antrian No " << antrian.awal+2 <<"                           |"<<endl;
		cout<<"\t\t\t\t\t|                      Atas Nama " << antrian.nama[antrian.awal] <<"                         |"<<endl;
   		cout<<"\t\t\t\t\t|                       Silahkan Masuk                          |"<<endl;
   		cout<<"\t\t\t\t\t|                                                               |"<<endl;
   		cout<<"\t\t\t\t\t| Menu     :                                                    |"<<endl;
		cout<<"\t\t\t\t\t|                                                               |"<<endl;
		cout<<"\t\t\t\t\t|    [1] Print dan Design                                       |"<<endl;
		cout<<"\t\t\t\t\t|    [2] Hanya print                                            |"<<endl;
		cout<<"\t\t\t\t\t|                                                               |"<<endl;
   		cout<<"\t\t\t\t\t| Masukkan Keperluan Anda : ";
   		biaya = 0;
   		cin>>keperluan;
   		if (keperluan==1){	
   			system("cls");
			header();
   			int pil;
   			cout<<"\t\t\t\t\t|                                                               |"<<endl;
   			cout<<"\t\t\t\t\t|                        Daftar Harga                           |"<<endl;
   			cout<<"\t\t\t\t\t|---------------------------------------------------------------|"<<endl;
			cout<<"\t\t\t\t\t| No  |         Jenis Kertas          |          Harga          |"<<endl;
			cout<<"\t\t\t\t\t|---------------------------------------------------------------|"<<endl;

			// Menampilkan list harga
				showArray(values,size);

			cout<<"\t\t\t\t\t|                                                               |"<<endl;
			cout<<"\t\t\t\t\t|    [1] Urutkan dari yang termurah                             |"<<endl;
			cout<<"\t\t\t\t\t|    [2] Urutkan dari yang termahal                             |"<<endl;
			cout<<"\t\t\t\t\t|                                                               |"<<endl;
   			cout<<"\t\t\t\t\t| Masukkan pilihan : ";
   			cin>>pil;
   				if (pil == 1){
   					system("cls");
					header();
					cout<<"\t\t\t\t\t|                                                               |"<<endl;
		   			cout<<"\t\t\t\t\t|                        Daftar Harga                           |"<<endl;
		   			cout<<"\t\t\t\t\t|---------------------------------------------------------------|"<<endl;
					cout<<"\t\t\t\t\t| No  |         Jenis Kertas          |          Harga          |"<<endl;
					cout<<"\t\t\t\t\t|---------------------------------------------------------------|"<<endl;
					// memanggil function ascendingsort
					ascendingSort(values,size);
					// data setelah di sort 
					showArray(values,size);
					int pil;
					cout<<"\t\t\t\t\t|                                                               |"<<endl;
					cout<<"\t\t\t\t\t| Pilih kertas yang anda inginkan : ";
					cin>>pil;
					switch(pil){
						case 1 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[0].harga*jumlahPrint);
								break;
						case 2 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[1].harga*jumlahPrint);
								break;
						case 3 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[2].harga*jumlahPrint);
								break;
						case 4 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[3].harga*jumlahPrint);
								break;
						case 5 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[4].harga*jumlahPrint); 
								break;
						case 6 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[5].harga*jumlahPrint);
								break;
						case 7 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[6].harga*jumlahPrint);
								break;
						case 8 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[7].harga*jumlahPrint);
								break;
						case 9 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[8].harga*jumlahPrint);
								break;
						case 10 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[9].harga*jumlahPrint);
								break;
						case 11 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[10].harga*jumlahPrint);
								break;
					}
   				}else if (pil==2){
   					system("cls");
					header();
					cout<<"\t\t\t\t\t|                                                               |"<<endl;
		   			cout<<"\t\t\t\t\t|                        Daftar Harga                           |"<<endl;
		   			cout<<"\t\t\t\t\t|---------------------------------------------------------------|"<<endl;
					cout<<"\t\t\t\t\t| No  |         Jenis Kertas          |          Harga          |"<<endl;
					cout<<"\t\t\t\t\t|---------------------------------------------------------------|"<<endl;
					// memanggil function descending sort
					descendingSort(values,size);
					// data setelah di sort 
					showArray(values,size);
					int pil;
					cout<<"\t\t\t\t\t|                                                               |"<<endl;
					cout<<"\t\t\t\t\t| Pilih kertas yang anda inginkan : ";
					cin>>pil;
					switch(pil){
						case 1 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[0].harga*jumlahPrint);
								break;
						case 2 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[1].harga*jumlahPrint);
								break;
						case 3 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[2].harga*jumlahPrint);
								break;
						case 4 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[3].harga*jumlahPrint);
								break;
						case 5 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[4].harga*jumlahPrint); 
								break;
						case 6 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[5].harga*jumlahPrint);
								break;
						case 7 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[6].harga*jumlahPrint);
								break;
						case 8 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[7].harga*jumlahPrint);
								break;
						case 9 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[8].harga*jumlahPrint);
								break;
						case 10 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[9].harga*jumlahPrint);
								break;
						case 11 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[10].harga*jumlahPrint);
								break;
					}
   				}
   		}else if (keperluan==2){	
   			system("cls");
			header();
   			int pil;
   			cout<<"\t\t\t\t\t|                                                               |"<<endl;
   			cout<<"\t\t\t\t\t|                        Daftar Harga                           |"<<endl;
   			cout<<"\t\t\t\t\t|---------------------------------------------------------------|"<<endl;
			cout<<"\t\t\t\t\t| No  |         Jenis Kertas          |          Harga          |"<<endl;
			cout<<"\t\t\t\t\t|---------------------------------------------------------------|"<<endl;

			// Menampilkan list harga
				showArray(values,size);

			cout<<"\t\t\t\t\t|                                                               |"<<endl;
			cout<<"\t\t\t\t\t|    [1] Urutkan dari yang termurah                             |"<<endl;
			cout<<"\t\t\t\t\t|    [2] Urutkan dari yang termahal                             |"<<endl;
			cout<<"\t\t\t\t\t|                                                               |"<<endl;
   			cout<<"\t\t\t\t\t| Masukkan pilihan : ";
   			cin>>pil;
   				if (pil == 1){
   					system("cls");
					header();
					cout<<"\t\t\t\t\t|                                                               |"<<endl;
		   			cout<<"\t\t\t\t\t|                        Daftar Harga                           |"<<endl;
		   			cout<<"\t\t\t\t\t|---------------------------------------------------------------|"<<endl;
					cout<<"\t\t\t\t\t| No  |         Jenis Kertas          |          Harga          |"<<endl;
					cout<<"\t\t\t\t\t|---------------------------------------------------------------|"<<endl;
					// memanggil function sort
					ascendingSort(values,size);
					// data setelah di sort 
					showArray(values,size);
					int pil;
					cout<<"\t\t\t\t\t|                                                               |"<<endl;
					cout<<"\t\t\t\t\t| Pilih kertas yang anda inginkan : ";
					cin>>pil;
					switch(pil){
						case 1 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[0].harga*jumlahPrint);
								break;
						case 2 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[1].harga*jumlahPrint);
								break;
						case 3 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[2].harga*jumlahPrint);
								break;
						case 4 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[3].harga*jumlahPrint);
								break;
						case 5 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[4].harga*jumlahPrint); 
								break;
						case 6 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[5].harga*jumlahPrint);
								break;
						case 7 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[6].harga*jumlahPrint);
								break;
						case 8 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[7].harga*jumlahPrint);
								break;
						case 9 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[8].harga*jumlahPrint);
								break;
						case 10 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[9].harga*jumlahPrint);
								break;
						case 11 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[10].harga*jumlahPrint);
								break;
					}
   				}else if (pil==2){
   					system("cls");
					header();
					cout<<"\t\t\t\t\t|                                                               |"<<endl;
		   			cout<<"\t\t\t\t\t|                        Daftar Harga                           |"<<endl;
		   			cout<<"\t\t\t\t\t|---------------------------------------------------------------|"<<endl;
					cout<<"\t\t\t\t\t| No  |         Jenis Kertas          |          Harga          |"<<endl;
					cout<<"\t\t\t\t\t|---------------------------------------------------------------|"<<endl;
					// sort
					descendingSort(values,size);
					// data setelah di sort 
					showArray(values,size);
					int pil;
					cout<<"\t\t\t\t\t|                                                               |"<<endl;
					cout<<"\t\t\t\t\t| Pilih kertas yang anda inginkan : ";
					cin>>pil;
					switch(pil){
						case 1 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[0].harga*jumlahPrint);
								break;
						case 2 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[1].harga*jumlahPrint);
								break;
						case 3 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[2].harga*jumlahPrint);
								break;
						case 4 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[3].harga*jumlahPrint);
								break;
						case 5 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[4].harga*jumlahPrint); 
								break;
						case 6 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[5].harga*jumlahPrint);
								break;
						case 7 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[6].harga*jumlahPrint);
								break;
						case 8 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[7].harga*jumlahPrint);
								break;
						case 9 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[8].harga*jumlahPrint);
								break;
						case 10 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[9].harga*jumlahPrint);
								break;
						case 11 :
								cout<<"\t\t\t\t\t| Masukkan kuantitas yang anda butuhkan : ";
								cin>>jumlahPrint;
								biaya += (values[10].harga*jumlahPrint);
								break;
					}
   				}
   		}

   		char end;
   		end:
   		cout<<"\t\t\t\t Cetak invoice ? (Y/N) : ";
   		cin>>end;
   		if (tolower(end) == 'y' )
   		{
   			system("cls");
			header();
			time_t now = time(0);
  			tm *ltm    = localtime(&now);
  			int hari   = ltm->tm_mday;
  			int bulan  = 1+ltm->tm_mon;
  			int tahun  = 1900+ltm->tm_year;

   			int total;
			cout<<"\t\t\t\t\t|                      Invoice Pembayaran                       |"<<endl;	
			cout<<"\t\t\t\t\t|                  -------------------------                    |"<<endl;
			cout<<"\t\t\t\t\t|                                                               |"<<endl;
			srand(time(0));
			cout<<"\t\t\t\t\t| Kode Invoice     : MG" << setw(40) << left << rand()  << " |"<<endl;
			cout<<"\t\t\t\t\t| Tanggal          : " << hari <<"/"<<bulan<<"/"<<tahun<<"                                  |"<<endl;
			cout<<"\t\t\t\t\t| Nama Customer    : " << setw(40) << left << antrian.nama[antrian.awal] << "   |"<<endl;
			cout<<"\t\t\t\t\t| NoHP Customer    : " << setw(40) << left << antrian.nohp[antrian.awal] << "   |"<<endl;
			cout<<"\t\t\t\t\t| =================================                             |"<<endl;
			keperluan == 1 ? 
			cout<<"\t\t\t\t\t| Menggunakan Jasa Design                : Rp.           50000  |\n" :
			cout<<"\t\t\t\t\t| Tidak Menggunakan Jasa Design          : Rp.               0  |"<<endl;
			cout<<"\t\t\t\t\t| Biaya Print                            : Rp. " << setw(15) << right << biaya << "  |"<<endl;
			cout<<"\t\t\t\t\t|                                        ---------------------+ |"<<endl;
			keperluan == 1 ? total = biaya + 50000 : total = biaya + 0;
			cout<<"\t\t\t\t\t| Total Pembayaran                       : Rp. " << setw(15) << right << total << "  |"<<endl;
			cout<<"\t\t\t\t\t|                                                               |"<<endl;
			cout<<"\t\t\t\t\t|              Silahkan lakukan pembayaran di kasir             |"<<endl;
			cout<<"\t\t\t\t\t|                                                               |"<<endl;

			// Membuat file untuk cetak struk pembayaran 
			ofstream printInvoice;

			printInvoice.open("invoice.txt", ios::trunc);
			printInvoice <<"\t\t\t\t\t|===============================================================|"<<endl;
			printInvoice <<"\t\t\t\t\t|                                                               |"<<endl;
			printInvoice <<"\t\t\t\t\t|                      Invoice Pembayaran                       |"<<endl;	
			printInvoice <<"\t\t\t\t\t|                  -------------------------                    |"<<endl;
			printInvoice <<"\t\t\t\t\t|                                                               |"<<endl;
			srand(time(0));
			printInvoice <<"\t\t\t\t\t| Kode Invoice     : MG" << setw(40) << left << rand()  << " |"<<endl;
			printInvoice <<"\t\t\t\t\t| Tanggal          : " << hari <<"/"<<bulan<<"/"<<tahun<<"                                  |"<<endl;
			printInvoice <<"\t\t\t\t\t| Nama Customer    : " << setw(40) << left << antrian.nama[antrian.awal] << "   |"<<endl;
			printInvoice <<"\t\t\t\t\t| NoHP Customer    : " << setw(40) << left << antrian.nohp[antrian.awal] << "   |"<<endl;
			printInvoice <<"\t\t\t\t\t| =================================                             |"<<endl;
			keperluan == 1 ? 
			printInvoice <<"\t\t\t\t\t| Menggunakan Jasa Design                : Rp.           50000  |\n" :
			printInvoice <<"\t\t\t\t\t| Tidak Menggunakan Jasa Design          : Rp.               0  |"<<endl;
			printInvoice <<"\t\t\t\t\t| Biaya Print                            : Rp. " << setw(15) << right << biaya << "  |"<<endl;
			printInvoice <<"\t\t\t\t\t|                                        ---------------------+ |"<<endl;
			keperluan == 1 ? total = biaya + 50000 : total = biaya + 0;
			printInvoice <<"\t\t\t\t\t| Total Pembayaran                       : Rp. " << setw(15) << right << total << "  |"<<endl;
			printInvoice <<"\t\t\t\t\t|                                                               |"<<endl;
			printInvoice <<"\t\t\t\t\t|              Silahkan lakukan pembayaran di kasir             |"<<endl;
			printInvoice <<"\t\t\t\t\t|                                                               |"<<endl;
			printInvoice <<"\t\t\t\t\t|===============================================================|"<<endl;
			printInvoice.close();

			//Membuat output file utk rekap orderan ala ala biar keren yakan asiap santuy
			ofstream rekap;
			rekap.open("Rekap Transaksi.txt", ios::app);
			rekap << "==============================================================="<<endl;
			rekap <<" Kode Invoice     : MG" << setw(40) << left << rand()  << " "<<endl;
			rekap <<" Tanggal          : " << hari <<"/"<<bulan<<"/"<<tahun<<"                                  "<<endl;
			rekap <<" Nama Customer    : " << setw(40) << left << antrian.nama[antrian.awal] << "   "<<endl;
			rekap <<" NoHP Customer    : " << setw(40) << left << antrian.nohp[antrian.awal] << "   "<<endl;
			rekap <<" Total Pembayaran : Rp. " << setw(15) << left << total << "  "<<endl;
			rekap <<"==============================================================="<<endl;
			rekap <<"\n";
			rekap.close();

			// Proses dequeue 
   			for (int i = antrian.awal; i < antrian.akhir; i++)
   			antrian.nama[i] = antrian.nama[i+1];
   			antrian.akhir--;
   		}else if(tolower(end) == 'n'){
   			goto order;
   		}else{
   			cout<<"Pilihan yang anda masukan salah!!";
   			goto end;
   		}
	}
		footerSub();
		getch();
		system("cls");
}

// Print
void tampilPelanggan(){

	string pil;
	string min;

	if (isEmpty())
	{
		system("cls");
		header();
	cout<<"\t\t\t\t\t|                 MAAF,BELUM ADA PELANGGAN HARI INI             |"<<endl;
	cout<<"\t\t\t\t\t|                                                               |"<<endl;
	}
	else{
		system("cls");
		header();
			cout<<"\t\t\t\t\t|               ANTRIAN PELANGGAN MANGROVE PRINTING             |"<<endl;
			cout<<"\t\t\t\t\t|                                                               |"<<endl;
			cout<<"\t\t\t\t\t|---------------------------------------------------------------|"<<endl;
			cout<<"\t\t\t\t\t| No  |              Nama             |          No.HP          |"<<endl;
			cout<<"\t\t\t\t\t|---------------------------------------------------------------|"<<endl;

			for (int i = antrian.awal; i < antrian.akhir; ++i)
			{
				cout<<"\t\t\t\t\t| " << setw(4) << left <<i+2
				<<"|" << setw(31) << left << antrian.nama[i] 
				<<"|" << setw(25) << left << antrian.nohp[i]<< "|" <<endl;

			}
	}
	footerSub();
	getch();
}

// function init
void init(){
	antrian.awal = -1;
	antrian.akhir = -1;
}

// function full
bool isFull(){
	if (antrian.akhir == max-1)
	{
		return true;
	}else{
		return false;
	}
}

// function cek kosong or not
bool isEmpty(){
	if (antrian.akhir==-1)
	{
		return true;
	}else{
		return false;
	}
}

// function agar inputan string bisa mendapatkan spasi atau membiarkan string menerima inputan "kalimat"
string getLine() {
  string txt;
  do {
    getline(cin, txt);
  } while (txt == "");
  return txt;
}

// function utk menampilkan header
void header(){
	// Menampilkan waktu ala ala
	time_t tt; 
    struct tm * ti; 
    time (&tt); 
    ti = localtime(&tt); 

    cout<<"\n\t\t\t\t\t"<<asctime(ti);
	cout<<"\t\t\t\t\t|===============================================================|"<<endl;
 	cout<<"\t\t\t\t\t|                                                               |"<<endl;
 	cout<<"\t\t\t\t\t|                  MANGROVE PRINTING LASER                      |"<<endl;
 	cout<<"\t\t\t\t\t|            Jalan Bougenvile CT X 2, Karang Gayam              |"<<endl;
 	cout<<"\t\t\t\t\t|      Kabupaten Sleman, Daerah Istimewa Yogyakarta 55288       |"<<endl;
 	cout<<"\t\t\t\t\t|                                                               |"<<endl;
	cout<<"\t\t\t\t\t|===============================================================|"<<endl;
 	cout<<"\t\t\t\t\t|                                                               |"<<endl;
}

// inqueue
void registrasi(){ 
	system("cls");
	header();
	if (isFull())
	{
		cout<<"\t\t\t\t\t|                       REGISTRASI ANTRIAN                      |"<<endl;
		cout<<"\t\t\t\t\t|                                                               |"<<endl;
		cout<<"\t\t\t\t\t|---------------------------------------------------------------|"<<endl;
		cout<<"\t\t\t\t\t|                                                               |"<<endl;
		cout<<"\t\t\t\t\t|                Mohon Maaf Antrian sedang penuh!               |"<<endl;
		cout<<"\t\t\t\t\t|                                                               |"<<endl;

	}else{
		
		int lastNumQ=antrian.akhir+2;
		int firstNumQ=lastNumQ-1;
		cout<<"\t\t\t\t\t|                       REGISTRASI ANTRIAN                      |"<<endl;
		cout<<"\t\t\t\t\t|                                                               |"<<endl;
		cout<<"\t\t\t\t\t|---------------------------------------------------------------|"<<endl;
		cout<<"\t\t\t\t\t|                   Nomor Antrian Anda Adalah " << lastNumQ <<"                 |"<<endl;
		
		// ala ala biar keren yakan
		if (firstNumQ==0)
		{
			cout<<"\t\t\t\t\t|       Sisa antrian kosong, anda adalah pelanggan pertama      |"<<endl;
			cout<<"\t\t\t\t\t|                                                               |"<<endl;
		} else{
		cout<<"\t\t\t\t\t|                          Sisa antrian " << firstNumQ <<"                       |"<<endl;
		}

		cout<<"\t\t\t\t\t|\tNama	: ";				 
		string nama= getLine();
		antrian.nama[antrian.akhir] = nama;
		
		cout<<"\t\t\t\t\t|\tNo HP	: ";
		string nohp = getLine();
		antrian.nohp[antrian.akhir] = nohp;
		antrian.akhir++;
	}
		footerSub();
		getch();
		system("cls");
}

// search
void searchData(){
	system("cls");
	int i,data,get;
	bool ketemu = false;
	string x;

	header();
	cout<<"\t\t\t\t\t|                          CARI ANTRIAN                         |"<<endl;
	cout<<"\t\t\t\t\t|                                                               |"<<endl;
	cout<<"\t\t\t\t\t|---------------------------------------------------------------|"<<endl;
	cout<<"\t\t\t\t\t|             Masukkan nama yang ingin dicari : ";
	cin>>x;
	

	for(i = -1; i<antrian.akhir; i++){
        if(x == antrian.nama[i]){
            ketemu = true;
            get = i; 
        }
     }
    if(!ketemu){
    cout<<"\t\t\t\t\t|                                                               |"<<endl;
	cout<<"\t\t\t\t\t|               Maaf nama yang dicari tidak ditemukan           |"<<endl;
	cout<<"\t\t\t\t\t|                                                               |"<<endl;
    }else{
	cout<<"\t\t\t\t\t|                                                               |"<<endl;
	cout<<"\t\t\t\t\t|                        ANTRIAN DITEMUKAN                      |"<<endl;
	cout<<"\t\t\t\t\t|---------------------------------------------------------------|"<<endl;
	cout<<"\t\t\t\t\t| No  |              Nama             |          No.HP          |"<<endl;
	cout<<"\t\t\t\t\t|---------------------------------------------------------------|"<<endl;
    	for (i = -1; i < antrian.akhir; ++i)
    	{
    		if (x == antrian.nama[i])
    		{
				cout<<"\t\t\t\t\t| " << setw(4) << left <<i+2
				<<"|" << setw(31) << left << antrian.nama[i] 
				<<"|" << setw(25) << left << antrian.nohp[i]<< "|" <<endl;
    		}
    	}
    }

// 	while (i<antrian.akhir && antrian.nama[i]!=x){
// 		i++;
// 	if (antrian.nama[i]!=x)
// 	{
// 	cout<<"\t\t\t\t\t|                                                               |"<<endl;
// 	cout<<"\t\t\t\t\t|               Maaf nama yang dicari tidak ditemukan           |"<<endl;
// 	cout<<"\t\t\t\t\t|                                                               |"<<endl;
// 	}else if (antrian.nama[i] == x)  
// 	{

// 	cout<<"\t\t\t\t\t|                                                               |"<<endl;
// 	cout<<"\t\t\t\t\t|                        ANTRIAN DITEMUKAN                      |"<<endl;
// 	cout<<"\t\t\t\t\t|---------------------------------------------------------------|"<<endl;
// 	cout<<"\t\t\t\t\t| No  |              Nama             |          No.HP          |"<<endl;
// 	cout<<"\t\t\t\t\t|---------------------------------------------------------------|"<<endl;

// 	cout<<"\t\t\t\t\t| " << setw(4) << left <<i+2
// 	<<"|" << setw(31) << left << antrian.nama[i] 
// 	<<"|" << setw(25) << left << antrian.nohp[i]<< "|" <<endl;
// 	}
// }
		footerSub();
		getch();
		system("cls");
}

// ascendingsort
void ascendingSort(layanan array[], int size){

	bool tukar;
	do
	{
		tukar = false;
		for (int i = 0; i < size-1; ++i)
		{
			if (array[i].harga > array[i+1].harga)
			{
				swap(array[i],array[i+1]);
				tukar = true;
			}
		}
	} while (tukar);

}

// descending sort
void descendingSort(layanan array[], int size){

	bool tukar;
	do
	{
		tukar = false;
		for (int i = 0; i < size-1; ++i)
		{
			if (array[i].harga < array[i+1].harga)
			{
				swap(array[i],array[i+1]);
				tukar = true;
			}
		}
	} while (tukar);

}

// menampilkan array yang telah di sort
void showArray(layanan array[], int size){
		for (int i = 0; i < size; ++i)
			{
				cout<<"\t\t\t\t\t|" << setw(4) << right << i+1
				    <<" | " << setw(29) << left << array[i].nama
				    <<" | " << setw(23) << left << array[i].harga << " | " << endl;
			}
}

/*
								               (c) badc0der ./rep 
*/