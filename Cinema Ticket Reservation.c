#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*
Kelompok 13, Proglan-2
Ghulam Izzul Fuad - 2006534953
Muhammad Farhan Haniftyaji - 2006468711
SIMPLE MOVIE TICKET BOOKING
*/

//Deklarasi modular function
int menu ();
int editfilm();
int daftarfilm();
int pembelian();
int cancelling();
void panduan();

//deklarasi structdetail reservasi untuk menyimpan data orang yang melakukan reservasi
struct detailreservasi1 {
	char nama [120][30];
	long int no_hp [120];
	int bangku[120];
	char judulfilm[120][30];
	char jadwalcust[120][25];
	int time[120];
	int id[120];
	int count;
};

//deklarasi hari1 untuk menyimpan data reservasi berdasarkan hari
struct hari1 {
	struct detailreservasi1 hari[7];
};

int main () {
	struct hari1 movie[3];
	int frekuensifilm[3] = {0};
	int frekuensihari[7] = {0};
	int frekuensijam[3];
	char judul[3][30];
	int kursi1[120];
	int	harga[3];
	char tanggal[7][25];
	int jam[3];
	int durasi [3];
	film9(judul, harga, tanggal, jam, durasi, kursi1,movie, frekuensifilm, frekuensihari);
	menu (judul, harga, tanggal, jam, durasi, kursi1, movie, frekuensifilm, frekuensihari, frekuensijam);
	return 0;
}

//MENGISI INFORMASI AWAL MENGENAI DETAIL 3 FILM YANG AKAN DITAYANGKAN
int film9 (char judul[3][30], int harga[3], char tanggal[7][25], int jam[3], int durasi[3], int kursi1[120], struct hari1 movie[3], int frekuensifilm[3], int frekuensihari[3]) {
	strcpy (judul[0], "GODZILLA VS KONG");
	strcpy (judul[1], "RAYA AND THE LAST DRAGON");
	strcpy (judul[2], "STAND BY ME 2");
	
	strcpy (tanggal[0],"SENIN, 4 April 2021");
	strcpy (tanggal[1], "SELASA, 5 April 2021");
	strcpy (tanggal[2], "RABU, 6 April 2021");
	strcpy (tanggal[3], "KAMIS, 7 April 2021");
	strcpy (tanggal[4], "JUMAT, 8 April 2021");
	strcpy (tanggal[5], "SABTU, 9 April 2021");
	strcpy (tanggal[6], "MINGGU, 10 April 2021");
	
	durasi[0] = 113;
	durasi[1] = 114;
	durasi[2] = 96;
	
	int i,j,k;
	
	jam[0] = 1345;
	jam[1] = 1615;
	jam[2] = 1815;
	
	
	for (i=0; i<3; i++) {
		harga[i] = 30000;
		frekuensifilm[i] = 0;
	}
	
	for (i=0; i<7; i++) {
		frekuensihari[i] = 0;
	}
	//Mengisi Array kursi1 Dengan Angka Dari 1 - 120
	for (i = 0; i< 120; i++) {
			kursi1[i] = 1+i;
		}
	//Untuk Menghitung Mundur Jumlah Reservasi
	for (i = 0; i<3; i++) {
		for (j=0; j<7; j++) {
			movie[i].hari[j].count = 120;
		}
	}
	for (i=0; i<3; i++) {
		for (j=0; j<7; j++) {
			for (k=0; k<120; k++) {
				movie[i].hari[j].bangku[k] = 0;
			}
		}
	}
	
}

//Funtion Menu Utama
int menu (char judul[3][30], int harga[3], char tanggal[7][25], int jam[3], int durasi[3], int kursi1[120], struct hari1 movie[3],int frekuensifilm[3],int frekuensihari[7],int frekuensijam[3]) {
	int select;
	do {
		fflush(stdin);
		system ("CLS");
	printf("                 Simple Movie Ticket Booking System\n");
	printf("||================================================================||\n");
	printf("||             1- Edit film dan harga tiket (only admin)          ||\n");
	printf("||             2- Daftar Film                                     ||\n");
	printf("||             3- Reservasi Tiket                                 ||\n");
	printf("||             4- cancel reservasi                                ||\n");
	printf("||             5- Panduan Pengguna                                ||\n");
	printf("||             6. Keluar system                                   ||\n");
	printf("||================================================================||\n");
	printf("  Masukkan Pilihan Anda: ");
	scanf("%d",&select);
	switch (select) {
		case 1 :
				editfilm (judul,harga,tanggal,jam,durasi);
				break;
		case 2 :
				daftarfilm (judul,tanggal,jam,durasi,frekuensifilm,frekuensihari);
				break;
		case 3 :
				pembelian (judul, harga,tanggal, jam, durasi, movie, kursi1, frekuensifilm, frekuensihari);
				break;		
		case 4 :
				cancelling (judul,harga,tanggal,jam,durasi,movie);
				break;
		case 5 :
				panduan();
				break;
		case 6 :
				printf ("TERIMA KASIH");
				break;
		default :
				printf ("input invalid");
				printf ("\n");
				system ("pause");
				getchar();
				break;
		}
	} while (select != 6);
}

//Funtion Khusus Admin Untuk Merubah Informasi Film Yang Akan Ditayangkan
int editfilm (char judul[3][30],int harga[3], char tanggal[7][25], int jam[3], int durasi[3]) {
	system ("CLS");
	int i,j, pick, select2;
	char pass[10];
	char pass1[10] = "pass";
	char tanggalbaru[1][25];
	int jambaru = 0;
	int hargabaru;
	int edithari;
	int editjam;
	int editharga;
	printf ("EDIT FILM (ADMIN ONLY)\n");
	printf ("Masukkan Password : ");
	scanf ("%s", &pass);

	if (strcmp(pass,pass1)==0) {
		do {
				system ("CLS");
			printf ("Menu\n");
			printf ("1. Edit Judul Film\n");
			printf ("2. Edit Jadwal Film\n");
			printf ("3. Edit Jam Tayang Film\n");
			printf ("4. Edit Harga Tiket\n");
			printf ("5. Kembali ke menu utama\n");
			printf ("Select : ");
			scanf ("%d", &pick);
			
			switch (pick)  {
				case 1:
					system ("CLS");
					char gantijudul[1][30];
					printf ("EDIT JUDUL FILM\n\n");
					for (i=0; i<3; i++) {
						printf ("%d. %s\n", i+1, judul[i]);
					}
					printf ("Pilih film yang ingin diubah\nPilihan Anda : ");
					scanf ("%d", &select2);
					if (select2 == 1) {
						printf ("Masukkan Judul Baru :\n");
						getchar();
						scanf ("%[^\n]s", &gantijudul[0]);
						strcpy (judul[0], gantijudul[0]);
						printf ("Durasi Film :\n ");
						scanf ("%d", &durasi[0]);
					}
					else if (select2 == 2) {
						printf ("Masukkan Judul Baru : ");
						getchar();
						scanf ("%[^\n]s", &gantijudul[1]);
						strcpy (judul[1],gantijudul[1]);
						printf ("Durasi Film : ");
						scanf ("%d", &durasi[1]);
					}
					else if (select2 == 3) {
						printf ("Masukkan Judul Baru : ");
						getchar();
						scanf ("%[^\n]s", &gantijudul[2]);
						strcpy (judul[2], gantijudul[2]);
						printf ("Durasi Film : ");
						scanf ("%d", &durasi[2]);
					}
					else {
						printf ("input tidak valid\n");
						getchar();
			 		}
			 		break;
			
				case 2 :  
					system ("CLS");
					printf ("EDIT HARI / TANGGAL TAYANG\n");
					for (i=0; i<7; i++) {
						printf ("%d. %s\n", i+1, tanggal[i]);
					}
					gantihari :
					printf ("\nPilih Tanggal Yang Ingin Diubah (1-7) : ");
					scanf ("%d", &edithari);
					if (edithari<1 || edithari >7) {
						printf ("\nInput Tidak Valid\n");
						goto gantihari;
					}
					printf ("Masukkan Tanggal Tayang Baru\n");
						printf ("Contoh Input : Senin, 5 April 2021\n Tanggal Baru : ");
						getchar();
						scanf ("%[^\n]s", &tanggalbaru[0]);
						strcpy (tanggal[edithari-1], tanggalbaru[0]);
						break;
				case 3 :
					system ("CLS");
					printf ("EDIT JAM TAYANG\n");
					for (i=0; i<3; i++) {
						printf ("%d. Jam : %d\n", i+1, jam[i]);
					}
					gantijam :
					printf ("\nPilih Jam Tayang Yang Ingin Diubah (1-3) : ");
					scanf ("%d", &editjam);
					if (editjam < 1 || editjam > 3) {
						printf ("\nInput Tidak Valid\n");
						goto gantijam;
					}
					fflush(stdin); 		
					printf ("Masukkan Jam Tayang Baru\n ");
						printf ("Contoh input : 1815 (Gunakan format 24 Jam)\n Jam baru : ");
						getchar();
						scanf ("%d", &jam[editjam-1]);
					
					break;
				case 4 : 
					system ("CLS");
					printf ("EDIT HARGA TIKET\n");
					for (i=0; i<3; i++) {
						printf ("%d. Harga Tiket %d : %d\n", i+1, i+1, harga[i]);
					}
					gantiharga :
					printf ("\nPilih Harga Tiket Yang Ingin Diubah (1-3) : ");
					scanf ("%d", &editharga);
					if (editharga <1 || editharga > 3) {
						printf ("input tidak valid\n");
						goto gantiharga;
					}
					printf ("Masukkan Harga Tiket Baru\n");
						printf ("Masukkan Harga Tiket Film-%d : ", editharga);
						scanf ("%d", &hargabaru);
						harga[editharga-1] = hargabaru;
					break;
				case 5 :
					break;
			
				default :
					printf ("\ninput tidak valid\n");
					getchar();
					break;
			}
		}while (pick != 5);
	}
	else {
		printf ("\nPassword Salah\n");
		system ("pause\n");
		getchar();
	}
}

//funtion Untuk Menampilkan Dafta Film Berdasarkan Frekuensi Reservasi atau Menampilkan Daftar Hari Berdasarkan Frekuensi Reservasi 
int daftarfilm (char judul[3][30],char tanggal[7][25], int jam[3], int durasi[3],int frekuensifilm[3],int frekuensihari[7]) {
	system ("CLS");
	int i,j;
	int temp;
	int temp2;
	int terbesar;
	char judul2[3][30];
	char tanggal2[7][25];
	int frekuensifilm2[3];
	int frekuensihari2[7];
	char temp_judul[1][30];
	char temp_tanggal[1][25];
	int select1 = 0;
	printf ("1. Film Yang Paling Banyak Ditonton\n");
	printf ("2. Hari Tayang Yang Paling Banyak Dipilih\n");
	printf ("pilihan anda : ");
	scanf ("%d", &select1);
	switch (select1) {
		case 1 :
			system ("CLS");
			for (i=0; i<3; i++) {
				strcpy(judul2[i], judul[i]);
				frekuensifilm2[i] = frekuensifilm[i];
			}
			
			//Sorting berdasarkan frekuensi reservasi judul film
			for (i=0; i<3 -1; i++) {
				int swap = 0;
				for (j=0; j<3 - 1 - i; j++) {
					if (frekuensifilm2[j] < frekuensifilm2[j+1]) {
					temp = frekuensifilm2[j];
					frekuensifilm2[j] = frekuensifilm2[j+1];
					frekuensifilm2[j+1] = temp;
					strcpy (temp_judul[0],judul2[j]);
					strcpy (judul2[j], judul2[j+1]);
					strcpy (judul2[j+1], temp_judul[0]);
					swap = 1;
					}
				}
				if (swap == 0) {
					break;
				}
			}
			printf ("Daftar Film Yang Paling Banyak di Tonton\n");
			for (i=0; i<3; i++) {
				printf ("%d- %s\n", i+1, judul2[i]);
			}
			system ("pause");
			break;
	
		case 2 :
				system ("CLS");
				for (i=0; i<7; i++) {
					strcpy (tanggal2[i], tanggal[i]);
					frekuensihari2[i] = frekuensihari[i];
				}
				
				//Sorting Berdasarkan Frekuensi reservasi hari/tanggal tayang
				for (i=0; i<7 -1; i++) {
					int swap2 = 0;
					for (j=0; j<7-1-i; j++) {
						if (frekuensihari2[j] < frekuensihari2[j+1]) {
							temp2 = frekuensihari[j];
							frekuensihari2[j] = frekuensihari2[j+1];
							frekuensihari2[j+1] = temp2;
							strcpy (temp_tanggal[0], tanggal2[j]);
							strcpy (tanggal2[j], tanggal2[j+1]);
							strcpy (tanggal2[j+1], temp_tanggal[0]);
							swap2 = 1;
						}
					}
					if (swap2 == 0) {
						break;
					}
				}
				printf ("Urutan Hari Yang Paling Banyak Dipilih\n");
				for (i=0; i<7; i++) {
					printf ("%d- %s\n", i+1, tanggal2[i]);
				}
				system ("pause");
				break;
		default :
				system ("CLS");
				printf ("Input Invalid");
				getchar();
				system ("pause");
				break;
	}
}

//Funtion Untuk Reservasi Tiket Berdasarkan Judul Film dan Hari yang Dipilih Pengguna
//Data Reservasi Tergantung No. Bangku Yang Dipilih
int pembelian (char judul[3][30],int harga[3], char tanggal[7][25], int jam[3], int durasi[3], struct hari1 movie[7], int kursi1[120], int frekuensifilm[3], int frekuensihari[7]) {
	system ("CLS");
	int i, j, pickfilm, pickhari, pickjam;
	int jbangku;
	printf ("\t\t===============\n");
	printf ("\t\tRESERVASI TIKET\n");
	printf ("\t\t===============\n\n");
	printf ("Pilih judul film yang ingin anda lihat : \n\n");
	for (i=0; i<3; i++) {
		printf ("%d- %s\n", i+1, judul[i]);
		printf ("Tayang Setiap Hari Jam %d\n\n", jam[i]);
	}
	printf ("Pilihan Anda (1-3) : ");
	scanf ("%d", &pickfilm);
	
	switch (pickfilm) {
		case 1 :
				system ("CLS");
				printf ("%s\n", judul[0]);
				printf ("Durasi %d\n", durasi[0]);
				printf ("Jadwal Tayang\n");
				for (i=0; i<4; i++) {
					printf ("%d- %s		%d- %s\n",i+1, tanggal[i], i+5, tanggal[i+4]);
					printf ("Jam : %d			Jam : %d\n", jam[0], jam[0]);
					printf ("Harga : Rp %d		Harga : Rp %d\n", harga[0], harga[0]);
					printf ("\n");
				}
				pilihhari :
					printf ("Pilih Hari yang anda inginkan (1-7) : ");
					scanf ("%d", &pickhari);
					
					//error handling
					if (pickhari >=1 && pickhari <=7) {
						
						//Pengecekan Jumlah Reservasi
						if (movie[pickfilm-1].hari[pickhari-1].count != 0) {
							system ("CLS");
							
							//Menampilkan Urutan Bangku Penonton
							printf ("\t\t\t\t\t\tSCREEN\n\n\n");
							for (i = 0; i < 120; i++) {
								printf ("[%d]\t", kursi1[i]);
								if (i == 14 || i == 29 ||  i == 44 || i == 59 || i == 74 || i == 89 || i == 104) {
									printf("\n\n");
								}
							}
							printf ("\n\nJumlah Bangku Yang Ingin Anda Reservasi : ");
							scanf ("%d", &jbangku);
							int pickbangku[jbangku];
							for (i=0; i<jbangku; i++){
								pilihkursi :
								printf ("\nPilih Bangku yang anda inginkan (1-120) : ");
								scanf ("%d", &pickbangku[i]);
									if (pickbangku[i] >= 1 && pickbangku[i] <=120) {
										if (movie[pickfilm-1].hari[pickhari-1].bangku[pickbangku[i]] == 0) {			//Pengecekan Apakah Bangku Telah Direservasi Atau Belum
											movie[pickfilm-1].hari[pickhari-1].bangku[pickbangku[i]] = pickbangku[i];
										}	
										else {
											printf ("\nMaaf Kursi telah dipesan\n");
											getchar();
											goto pilihkursi;
										}
									}
									else {
										printf ("\nInput Tidak Valid\n");
										getchar();
										goto pilihkursi;
									}
							}
							printf ("\nMasukkan Nama Anda : ");
							scanf ("%s", &movie[pickfilm-1].hari[pickhari-1].nama[pickbangku[0]]);
							printf ("Masukkan No. HP Anda : ");
							scanf ("%ld", &movie[pickfilm-1].hari[pickhari-1].no_hp[pickbangku[0]]);
							for (i=0; i<jbangku; i++) {
								frekuensifilm[0] ++;
								frekuensihari[pickhari-1] ++;
								
								//Jika Transaksi Berhasil, Jumlah Reservasi Dikurang 1
								movie[pickfilm-1].hari[pickhari-1].count--;
								strcpy (movie[pickfilm-1].hari[pickhari-1].nama[pickbangku[i]],movie[pickfilm-1].hari[pickhari-1].nama[pickbangku[0]]);
								movie[pickfilm-1].hari[pickhari-1].no_hp[pickbangku[i]] = movie[pickfilm-1].hari[pickhari-1].no_hp[pickbangku[0]];
								movie[pickfilm-1].hari[pickhari-1].no_hp[pickbangku[i]] = movie[pickfilm-1].hari[pickhari-1].no_hp[pickbangku[0]];
								strcpy (movie[pickfilm-1].hari[pickhari-1].judulfilm[pickbangku[i]], judul[pickfilm-1]);
								strcpy (movie[pickfilm-1].hari[pickhari-1].jadwalcust[pickbangku[i]], tanggal[pickhari-1]);
								movie[pickfilm-1].hari[pickhari-1].time[pickbangku[i]] = jam[pickfilm-1];
							
								//Mengatur ID Reservasi Berdasarkan Hari/Tanggal Tayang dan Bangku Pilihan Pengguna
								if (pickhari == 1) {
									movie[pickfilm-1].hari[pickhari-1].id[pickbangku[i]] = 1000+pickbangku[i];
								}
								else if (pickhari == 2) {
									movie[pickfilm-1].hari[pickhari-1].id[pickbangku[i]] = 1120+pickbangku[i];
								}
								else if (pickhari == 3) {
									movie[pickfilm-1].hari[pickhari-1].id[pickbangku[i]] = 1240+pickbangku[i];
								}
								else if (pickhari == 4) {
									movie[pickfilm-1].hari[pickhari-1].id[pickbangku[i]] = 1360+pickbangku[i];
								}
								else if (pickhari == 5) {
									movie[pickfilm-1].hari[pickhari-1].id[pickbangku[i]] = 1480+pickbangku[i];
								}
								else if (pickhari == 6) {
									movie[pickfilm-1].hari[pickhari-1].id[pickbangku[i]] = 1600+pickbangku[i];
								}
								else if (pickhari == 7) {
									movie[pickfilm-1].hari[pickhari-1].id[pickbangku[i]] = 1720+pickbangku[i];
								}
							}
							system ("CLS");
							printf("\t-----------------THEATER BOOKING TICKET----------------\n");
	        				printf("\t============================================================\n");
	       					printf("\t Nama 		: %s\n",movie[pickfilm-1].hari[pickhari-1].nama[pickbangku[0]]);
	       					printf("\t No Handphone : %ld\n",movie[pickfilm-1].hari[pickhari-1].no_hp[pickbangku[0]]);
	       	 				printf("\t Judul Film 	: %s\n",movie[pickfilm-1].hari[pickhari-1].judulfilm[pickbangku[0]]);
	       	 				for (i=0; i<jbangku; i++) {
	       						printf("\t ID Pemesanan : %d\n",movie[pickfilm-1].hari[pickhari-1].id[pickbangku[i]]);
	       						printf("\t bangku       : %d  \n",movie[pickfilm-1].hari[pickhari-1].bangku[pickbangku[i]]);
	    					}
							printf("\t                   Tanggal   : %s\n", movie[pickfilm-1].hari[pickhari-1].jadwalcust[pickbangku[0]]);
	        				printf("\t                   Jam       : %d\n", movie[pickfilm-1].hari[pickhari-1].time[pickbangku[0]]);
	    					printf("\t                   Hall      : 01\n");
	        				printf("\t                   Harga     : Rp %d  \n\n",harga[pickfilm-1]);
	       			 		printf("\t============================================================\n");
	        				
							system ("pause");
							break;
							
						} else {
							printf ("\nMaaf Semua Bangku Untuk Film %s Hari %s Telah Direservasi\n", judul[pickfilm-1], tanggal[pickhari-1]);
							goto pilihhari;
						}
					}
					else {
						printf ("\nInput Anda Tidak valid\n");
						getchar();
						goto pilihhari;
					}
		case 2 :
				system ("CLS");
				printf ("%s\n", judul[1]);
				printf ("Durasi %d\n", durasi[1]);
				printf ("Jadwal Tayang\n");	
				for (i=0; i<4; i++) {
					printf ("%d- %s		%d- %s\n",i+1, tanggal[i], i+5, tanggal[i+4]);
					printf ("Jam : %d			Jam : %d\n",  jam[1], jam[1]);
					printf ("Harga : Rp %d		Harga : Rp %d\n", harga[1], harga[1]);
					printf ("\n");
				}
				pilihhari1 :
					printf ("Pilih Hari yang anda inginkan (1-7) : ");
					scanf ("%d", &pickhari);
					
					//error handling
					if (pickhari>=1 && pickhari <=7) {
						
						//Mengecek Jumlah Reservasi
						if (movie[pickfilm-1].hari[pickhari-1].count!=0) {	
							system ("CLS");
							
							//Menampilkan Urutan Bangku Penonton
							printf ("\t\t\t\t\t\tSCREEN\n\n\n");
							for (i = 0; i < 120; i++) {
								printf ("[%d]\t", kursi1[i]);
								if (i == 14 || i == 29 || i == 44 || i == 59 || i == 74 || i == 89 || i == 104) {
									printf("\n\n");
								}
							}
							printf ("\n\nJumlah Bangku Yang Ingin Anda Reservasi : ");
							scanf ("%d", &jbangku);
							int pickbangku[jbangku];
							for (i=0; i<jbangku; i++) {
							
								pilihkursi1 :
									printf ("\nPilih Bangku yang anda inginkan (1-120) : ");
									scanf ("%d", &pickbangku[i]);
									if (pickbangku[i] >=1 && pickbangku[i] <=120) {
										if (movie[pickfilm-1].hari[pickhari-1].bangku[pickbangku[i]] == 0) {			//Pengecekan Apakah Bangku Telah Direservasi Atau Belum
											movie[pickfilm-1].hari[pickhari-1].bangku[pickbangku[i]] = pickbangku[i];
										}
										else {
											printf ("\nMaaf Kursi telah dipesan\n");
											getchar();
											goto pilihkursi1;
										}
									}
									else {
										printf ("\nInput Tidak Valid\n");
										getchar();
										goto pilihkursi1;
									}
							}
							printf ("\nMasukkan Nama Anda : ");
							scanf ("%s", &movie[pickfilm-1].hari[pickhari-1].nama[pickbangku[0]]);
							printf ("Masukkan No. HP Anda : ");
							scanf ("%ld", &movie[pickfilm-1].hari[pickhari-1].no_hp[pickbangku[0]]);
							for (i=0; i<jbangku; i++) {
								frekuensifilm[1] += 1;
								frekuensihari[pickhari-1] += 1;
								
								//Jika Transaksi Berhasil Jumlah Reservasi Dikurang 1
								movie[pickfilm-1].hari[pickhari-1].count-=1;
								strcpy(movie[pickfilm-1].hari[pickhari-1].nama[pickbangku[i]],movie[pickfilm-1].hari[pickhari-1].nama[pickbangku[0]]);
								movie[pickfilm-1].hari[pickhari-1].no_hp[pickbangku[i]] = movie[pickfilm-1].hari[pickhari-1].no_hp[pickbangku[0]];
								strcpy (movie[pickfilm-1].hari[pickhari-1].judulfilm[pickbangku[i]], judul[pickfilm-1]);
								strcpy (movie[pickfilm-1].hari[pickhari-1].jadwalcust[pickbangku[i]], tanggal[pickhari-1]);
								movie[pickfilm-1].hari[pickhari-1].time[pickbangku[i]] = jam[pickfilm-1];
								
								//Mengatur ID Resrvasi Berdasarkan Hari/Tanggal Tayang dan Bangku Pilihan Pengguna
								if (pickhari == 1) {
									movie[pickfilm-1].hari[pickhari-1].id[pickbangku[i]] = 2000+pickbangku[i];
								}
								else if (pickhari == 2) {
									movie[pickfilm-1].hari[pickhari-1].id[pickbangku[i]] = 2120+pickbangku[i];
								}
								else if (pickhari == 3) {
									movie[pickfilm-1].hari[pickhari-1].id[pickbangku[i]] = 2240+pickbangku[i];
								}
								else if (pickhari == 4) {
									movie[pickfilm-1].hari[pickhari-1].id[pickbangku[i]] = 2360+pickbangku[i];
								}
								else if (pickhari == 5) {
									movie[pickfilm-1].hari[pickhari-1].id[pickbangku[i]] = 2480+pickbangku[i];
								}
								else if (pickhari == 6) {
									movie[pickfilm-1].hari[pickhari-1].id[pickbangku[i]] = 2600+pickbangku[i];
								}
								else if (pickhari == 7) {
									movie[pickfilm-1].hari[pickhari-1].id[pickbangku[i]] = 2720+pickbangku[i];
								}
							}
							system ("CLS");
							printf("\t-----------------THEATER BOOKING TICKET----------------\n");
		       	 			printf("\t============================================================\n");
		       				printf("\t Nama 		: %s\n",movie[pickfilm-1].hari[pickhari-1].nama[pickbangku[0]]);
		        			printf("\t No Handphone : %ld\n",movie[pickfilm-1].hari[pickhari-1].no_hp[pickbangku[0]]);
		        			printf("\t Judul Film 	: %s\n",movie[pickfilm-1].hari[pickhari-1].judulfilm[pickbangku[0]]);
		        			for (i=0; i<jbangku; i++) {
								printf("\t ID Pemesanan : %d\n",movie[pickfilm-1].hari[pickhari-1].id[pickbangku[i]]);
								printf("\t Bangku       : %d  \n",movie[pickfilm-1].hari[pickhari-1].bangku[pickbangku[i]]);
		        			}	
							printf("\t                   Tanggal   : %s\n", movie[pickfilm-1].hari[pickhari-1].jadwalcust[pickbangku[0]]);
		        			printf("\t                   Jam       : %d\n", movie[pickfilm-1].hari[pickhari-1].time[pickbangku[0]]);
		        			printf("\t                   Hall      : 01\n");
		        			printf("\t                   Harga     : Rp %d  \n\n",harga[pickfilm-1]);
		        			printf("\t============================================================\n");
		        			
							system ("pause");
							break;
						}
						else {
							printf ("\nMaaf Semua Bangku Untuk Film %s Hari %s Telah Direservasi\n", judul[pickfilm-1], tanggal[pickhari-1]);
							goto pilihhari1;
						}
					}
					else {
						printf ("\nInput Tidak Valid\n");
						getchar();
						goto pilihhari1;
					}
		case 3 :
				system ("CLS");
				printf ("%s\n", judul[2]);
				printf ("Durasi %d\n", durasi[2]);
				printf ("Jadwal Tayang\n\n\n");
				for (i=0; i<4; i++) {
					printf ("%d- %s		%d- %s\n",i+1, tanggal[i], i+5, tanggal[i+4]);
					printf ("Jam : %d			Jam : %d\n", jam[2],  jam[2]);
					printf ("Harga : Rp %d		Harga : Rp %d\n", harga[2], harga[2]);
					printf ("\n");
				}
				pilihhari2 :
					printf ("Pilih Hari yang anda inginkan (1-7) : ");
					scanf ("%d", &pickhari);
					
					//Error handling
					if (pickhari >= 1 && pickhari <=7 ) {
						
						//Pengecekan Jumlah Reservasi
						if (movie[pickfilm-1].hari[pickhari-1].count != 0) {
							system ("CLS");
							
							//Menampilka Urutan Bangku Penonton
							printf ("\t\t\t\t\t\tSCREEN\n");
							for (i = 0; i < 120; i++) {
								printf ("[%d]\t", kursi1[i]);
								if (i == 14 || i == 29 || i == 44 || i == 59 || i == 74 || i == 89 || i == 104) {
									printf("\n\n");
								}
							}
							printf ("\n\nJumlah Bangku Yang Ingin Anda Reservasi : ");
							scanf ("%d", &jbangku);
							int pickbangku[jbangku];
							for (i=0; i<jbangku; i++) {					
								pilihkursi2 :
									printf ("\nPilih Bangku yang anda inginkan (1-120) : ");
									scanf ("%d", &pickbangku[i]);
									if (pickbangku[i] >=1 && pickbangku[i] <=120) {
										if (movie[pickfilm-1].hari[pickhari-1].bangku[pickbangku[i]] == 0) {			//Pengecekan Apakah Bangku Telah Direservasi Atau Belum
											movie[pickfilm-1].hari[pickhari-1].bangku[pickbangku[i]] = pickbangku[i];
										}
										else {
											printf ("\nMaaf Kursi telah dipesan\n");
											getchar();
											goto pilihkursi2;
										}
									}
									else {
										printf ("Input Tidak Valid\n");
										getchar();
										goto pilihkursi2;
									}
							}
							printf ("\nMasukkan Nama Anda : ");
							scanf ("%s", &movie[pickfilm-1].hari[pickhari-1].nama[pickbangku[0]]);
							printf ("Masukkan No. HP Anda : ");
							scanf ("%ld", &movie[pickfilm-1].hari[pickhari-1].no_hp[pickbangku[0]]);
							for (i=0; i<jbangku; i++) {
								frekuensifilm[2] += 1;
								frekuensihari[pickhari-1] += 1;
							
								//Jika Transaksi Berhasil Jumlah Reservasi DIkurang 1
								movie[pickfilm-1].hari[pickhari-1].count-=1;
								strcpy (movie[pickfilm-1].hari[pickhari-1].nama[pickbangku[i]],movie[pickfilm-1].hari[pickhari-1].nama[pickbangku[0]]);
								movie[pickfilm-1].hari[pickhari-1].no_hp[pickbangku[i]] = movie[pickfilm-1].hari[pickhari-1].no_hp[pickbangku[0]];
								strcpy (movie[pickfilm-1].hari[pickhari-1].judulfilm[pickbangku[i]], judul[pickfilm-1]);
								strcpy (movie[pickfilm-1].hari[pickhari-1].jadwalcust[pickbangku[i]], tanggal[pickhari-1]);
								movie[pickfilm-1].hari[pickhari-1].time[pickbangku[i]] = jam[pickfilm-1];
								
								//Mengatur ID Reservasi Berdasarakn Hari/tanggal Tayang dan Bangku Pilihan Penonton
								if (pickhari == 1) {
									movie[pickfilm-1].hari[pickhari-1].id[pickbangku[i]] = 3000+pickbangku[i];
								}
								else if (pickhari == 2) {
									movie[pickfilm-1].hari[pickhari-1].id[pickbangku[i]] = 3120+pickbangku[i];
								}
								else if (pickhari == 3) {
									movie[pickfilm-1].hari[pickhari-1].id[pickbangku[i]] = 3240+pickbangku[i];
								}
								else if (pickhari == 4) {
									movie[pickfilm-1].hari[pickhari-1].id[pickbangku[i]] = 3360+pickbangku[i];
								}	
								else if (pickhari == 5) {
									movie[pickfilm-1].hari[pickhari-1].id[pickbangku[i]] = 3480+pickbangku[i];
								}
								else if (pickhari == 6) {
									movie[pickfilm-1].hari[pickhari-1].id[pickbangku[i]] = 3600+pickbangku[i];
								}
								else if (pickhari == 7) {
									movie[pickfilm-1].hari[pickhari-1].id[pickbangku[i]] = 3720+pickbangku[i];
								}
							}
							system ("CLS");
							printf("\t-----------------THEATER BOOKING TICKET----------------\n");
		        			printf("\t============================================================\n");
		        			printf("\t Nama 		: %s\n",movie[pickfilm-1].hari[pickhari-1].nama[pickbangku[0]]);
		       				printf("\t No Handphone : %ld\n",movie[pickfilm-1].hari[pickhari-1].no_hp[pickbangku[0]]);
		        			printf("\t Judul Film 	: %s\n",movie[pickfilm-1].hari[pickhari-1].judulfilm[pickbangku[0]]);
		       				for (i=0; i<jbangku; i++) {   
								printf("\t ID Pemesanan : %d\n",movie[pickfilm-1].hari[pickhari-1].id[pickbangku[i]]);
								printf("\t Bangku       : %d  \n",movie[pickfilm-1].hari[pickhari-1].bangku[pickbangku[i]]);
		       				}
							printf("\t                   Tanggal   : %s\n", movie[pickfilm-1].hari[pickhari-1].jadwalcust[pickbangku[0]]);
		        			printf("\t                   Jam       : %d\n", movie[pickfilm-1].hari[pickhari-1].time[pickbangku[0]]);
		        			printf("\t                   Hall      : 01\n");
		       				printf("\t                   Harga     : Rp %d  \n\n",harga[pickfilm-1]);
		       				printf("\t                   THANK YOU FOR CHOOSING US\n");
		        			printf("\t============================================================\n");
		        			
							system ("pause");
							break;	
						}
						else {
							printf ("\nMaaf Semua Kuris Untuk Film %s Hari %s Telah Direservasi\n", judul[pickfilm-1], tanggal[pickhari-1]);
							goto pilihhari2;
						}
					} 
					else {
						printf ("\nInput Tidak Valid\n");
						getchar();
						goto pilihhari2;
					}
			}
}

//Function Untuk Pembatalan Resrvasi Berdasarkan ID Resrvasi
int cancelling (char judul[3][30],int harga[3], char tanggal[7][25], float jam[3], int durasi[3], struct hari1 movie[7], int n, int o, int p) {
	system ("CLS");
	int film22, i,j,k, id2;
	int benar = 0;
	printf ("CANCELLING BOOKING TICKET\n\n");
	printf ("Masukkan id reservasi anda : ");
	scanf ("%d", &id2);
	
	//searching id reservasi
	for (i=0; i<3; i++) {
		for (j=0; j<7; j++) {
			for (k=0; k<120; k++) {
				if (id2 == movie[i].hari[j].id[k]) {
					system ("CLS");
					printf ("Anda Membatalan Reservasi Tiket Film : \n");
					printf ("ID      : %d\n", id2);
					printf ("Nama    : %s\n", movie[i].hari[j].nama[k]);
					printf ("Judul   : %s\n", movie[i].hari[j].judulfilm[k]);
					printf ("Bangku  : %d\n", movie[i].hari[j].bangku[k]);
					printf ("Tanggal : %s\n", movie[i].hari[j].jadwalcust[k]);
					printf ("Jam     : %d\n", movie[i].hari[j].time[k]);
					printf ("\n===Pembatalan Reservasi Tiket Berhasil===\n");
					
					//Jika Transaksi Berhasil, Bangku Yang Dibatalkan Akan Direset Menjadi 0 (Belum Ada Reservasi)
					movie[i].hari[j].bangku[k] = 0;
					benar = 1;
					fflush(stdin);
					system ("pause");
					break;
				}
			}
		}
	}
	if (benar == 0) {
		printf ("\nID Reservasi Tidak Ditemukan\n");
		fflush(stdin);
	}
}

//Funtion Panduan
void panduan () {
	system ("CLS");
	printf ("\t\t======================\n");
	printf ("\t\tPANDUAN UNTUK PENGGUNA\n");
	printf ("\t\t======================\n\n");
	printf ("1. Pilih Menu No. 2 (Daftar Film Untuk Melihat Film Yang Ramai Ditonton atau Hari Yang Paling Banyak Dipilih\n\n");
	printf ("2. Pilih Menu No. 3 (Reservasi Tiket) Untuk Melakukan Reservasi Tiket\n");
	printf ("   Didalam Menu Reservasi Tiket, Pilih Film Yang Ingin Anda Tonton\n");
	printf ("   Selanjutnya Pilih Hari/Tanggal Tayang Film Yang Anda Inginkan\n");
	printf ("   Selanjutnya Masukkan Jumlah Bangku Yang Ingin Anda reservasi\n");
	printf ("   Pilih Urutan Bangku Yang Ingin Anda Reservasi\n");
	printf ("   Masukkan Nama dan No. Hp Anda\n");
	printf ("   Tiket Reservasi Anda Akan Dicetak Diakhir Transaksi dan Simpan ID Reservasi Anda!\n\n");
	printf ("3. Pilih Menu No. 4 (Cancel Reservasi) Untuk Membatalkan Reservasi Anda\n");
	printf ("   Masukkan ID Reservasi Anda Dengan Benar!\n");
	printf ("   Bukti Pembatalan Reservasi Akan Ditampilkan Diakhir Transaksi\n\n");
	system ("pause");	
}
