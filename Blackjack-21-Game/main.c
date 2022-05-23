
#include <stdlib.h>
#include <stdio.h>								//Semih Engin 191180037 37. Grup Kart Oyunu
#include <math.h>				 
#include <locale.h>				 //türkçe karakter kullanmamýzý saðlar
#include <time.h>                //srand fonk kullanmak için gerekli kütüphane
#include <unistd.h>				 //sleep fonk kullanmak için gerekli kütüphane
#include <process.h>             //system("cls") "Önceki yazýlanlarý sildirme" komutunu kullanmamýzý saðlar.

#define kupa 03                 //kupa sembolü yazdýrmak için alt+3
#define karo 04                 //karo sembolü yazdýrmak için alt+4	
#define sinek 05                //Sinek sembolü yazdýrmak için alt+5
#define maca 06                 //Maça sembolü yazdýrmak için alt+6

int ksinek,kkaro,kkupa,kmaca,l,d,asdegeri,kazanilan,kaybedilen,bet,random_kart;
int scoin = 1000;
int oyuncu_total=0;
int bilgisayar_total;

int randkart();         //Rastgele kart oluþturma fonksiyonu
int betmiktari();       //Kulanýcýdan bet(bahis) istemek için kullanýlan fonk
void baslangic();       //Giriþ ekraný fonksiyonu
void hosgeldiniz();		//Ana menü fonksiyonu
void kurallar();        //Kurallarý gösteren fonksiyon
void oyun();            //Oyunun oynandýðý fonksiyon
void bilgisayar();      //Bilgisayarýn oynamasýný saðlayan fonksiyon
void bekle();            //Kullanýcý beklemek istediðinde kullanýlan fonk
void scoin_test();      //Bakiye testi için kullanýlan fonksiyon
void tekraroyna();         //AKullanýcýya tekrar oynamak isteyip istemediðini soran fonk


int main(void)
{
	
    int secim1;
	setlocale(LC_ALL, "Turkish"); //türkçe karakterler için 
    baslangic();

    system("pause");
    return(0);
} 

void baslangic() // Giriþ ekraný fonk
{
	char secim1;
	
    printf("\n	  	        O                                                     O                            \n");
	printf("  		   O   / \\   O                                           O   / \\   O                     \n");
	printf("	  	  | \\ /   \\ / |                                         | \\ /   \\ / |                  \n");
	printf("		__|___________|__                                     __|___________|__                    \n");
	printf("               /                 \\                                   /                 \\         \n");	 
	printf("          ____/			  \\____	                        ____/		        \\____             \n");
	printf("         /   |  ###   ___     ___  |   \\                       /   |  ___     ___    ### |   \\   \n");
	printf("             |  ##     *       *   |                               |   *       *      ## |         \n");
	printf("             |                     |                               |                     |         \n");
	printf("             |           ----  )   |       ------     /|           |    (  ----          |         \n");
	printf("             |---------------------|            |    / |           |---------------------|         \n");
    printf("              /                   \\             |      |           /                   \\         \n");
	printf("             /                     \\       ------      |          /                     \\        \n");
	printf("            /      _ _ _ _ _ _      \\      |           |         /      _ _ _ _ _ _      \\       \n");	
	printf("            \\                       /      |           |         \\                       /       \n");	
	printf("             \\                     /       ------    -----        \\                     /        \n");	
	printf("              \\                   /                                \\                   /         \n");	
	printf("                /               \\             BLACKJACK              /                \\          \n");	
	printf("               /                 \\                                  /                  \\         \n");	
	printf("              /                   \\                                /                    \\        \n");	
	printf("             /                     \\                              /                      \\       \n");	
	printf("            /                       \\                            /                        \\      \n");
	printf("           --------                 --------              --------                  --------       \n");	
	printf("\n                            OYUNUNA HOÞGELDÝNÝZ DEVAM ETMEK ÝÇÝN 'ENTER' BASINIZ ");
    printf("\n                                       --------------------------\n                                                   ");
    
	scanf("%c", &secim1);
    if (secim1 == 0x0A) //enter ile geçmemizi saðlar
	hosgeldiniz();
	
	return;
}

void hosgeldiniz() //Ana menü ekraný
{
	int secim2;
			
			system("cls");
			
			printf("\n\n\n\t\t\t=> ANA MENU <=\n");
	        printf("\n\n\t=> Hazýrsanýz '1' girerek oyuna baþlýyabiliriz.\n");
		    printf("\n\t=> Oyunun kurallarýna göz atmak için '2' giriniz.\n");
		    printf("\n\t=> Oyundan çýkmak için '3' giriniz.\n");
		    printf("\n\n    Lütfen seçiminizi giriniz : ");
		    scanf("%d", &secim2); 

			switch(secim2) 
            {   
                case 1:                   
                   oyun();
                              
                   break;
                   
                case 2: 
                   kurallar();
                   
                   break;
                   
                case 3: 
                   printf("\n       => Oynamak istememenize üzüldük");
                   printf("\n       => Baþka bir zaman görüþmek üzere...\n\n");
                   system("pause");
                   exit(0); //programdan çýkýþ yapar
                   break;
                default :
                	printf("\nGeçersiz deðer girdiniz. Lütfen 1, 2 yada 3 deðerlerinden birini giriniz.\n");
                	sleep(1);
                   	hosgeldiniz();
            }
}
void kurallar() //kurallar fonk yazdýrýr
{
    char secim1;
    int secim2;
    
	system("cls");
    printf("\n		-------BLACKJACK (21) NASIL BÝR OYUNDUR ?-------\n\n");
    
	printf(" => Blackjack, bir veya birden çok desteyle oynanan bir kart oyunudur..\n");
    printf(" => Amacýnýz, toplamda 21 puaný aþmadan krupiyeden(bilgisayardan) daha yüksek bir toplam puana ulaþmaktýr.\n");
    
	printf("\n		-------BLACKJACK (21) NASIL OYNANIR ?-------\n\n");
	
	printf(" => Blackjack oyunu kart deðerleri : \n\n");
    printf(" 	** 2 den 9 a kladar olan kartlarda üzerlerindeki rakam neyse puanlarý da odur.\n");
    printf("	** 10, J, Q, K – hepsi 10 puan deðerindedir.\n");
    printf(" 	** Blackjack A kaç puan, en sýk sorulan sorulardan biridir.\n" );
    printf("	** As kartlarý 1 veya 11 puan deðerinde olabilir; bunun seçimi oyuncuya aittir.\n");
    
	printf("\n => Blackjack oyunu nasýl oynanýr : \n\n");
    
	printf("	** Krupiyer yani bilgisayar, kendisine ve oyuncuya 1er kart verir.\n");
    printf("	** Daha sonra oyuncu oynamak istediði bahis miktarýný girer.\n");
    printf("	** Blackjack krupiye kurallarýna göre, krupiyenin sadece tek bir kartý oyuncu tarafýndan görülebilir.\n");
  	printf("	** Ýkinci kartý ise bahisden sonra gösterilir.\n");
    printf("	** llk kart sonrasýnda, þu seçeneklerden birini kullanabilirsiniz :\n");
    printf("\n   		 + Kart Ýste (Hit) – bir kart daha istemiþ olursunuz.");
    printf("\n    		 + Bekle (Stand) – baþka kart istemediðiniz anlamýna gelir.\n");
    printf("\n	** Kart daðýtýmý bitince eller karþýlaþtýrýlýr ve 21 puana en yakýn olan taraf oyunu kazanýr.\n");
	printf("\n =>  Kurallarý anladýysanýz oynuna baþlamak için 'E' basýnýz.\n");
	printf("\n =>  Oyunun ana menüsüne dönemk için 'H' basýnýz.\n");

	printf("\n                  		(E/H)\n				  ");
    scanf("\n%c",&secim1);
   
     
    while((secim1!='E') && (secim1!='H') && (secim1!='e') && (secim1!='h'))
	{                                                                           
		printf("\n");
		printf("Gecersiz secim. Lütfen 'E' veya 'H' den birisini seciniz : ");
		scanf("%c",&secim1);
	}

	switch(toupper(secim1)) //girilen karakteri büyük karaktere çevirir
	{
		
		case 'E':
		{ 
	        system("cls");
	        oyun();
		}
	   
		case 'H':
		{
			system("cls");
	    	hosgeldiniz();
	    }	
	}
}
void oyun() //Oyunun oynandýðý fonksiyon
{
     
    int p=0; // oyunucunun çektiði kartlarýn puaný
    int i=1; // kazanana kadar kart isteme döngüsünün sayacý
    char secim3;
    system("cls");//ekraný temizler 
    scoin_test(); //scoinin bitip bitmediðini denemek için ve ekrana bastýrmak için kullanýlan fonksiyon
    printf("\nSCoin: £%d\n",scoin); 
    betmiktari(); //bahis miktarýný girdirecek fonksiyon sahip olunandan fazla girilirse uyarý verir
	printf("\n");
	printf("\tKartlar Karýlýyor... \n\n");
	sleep(1); 		//fonksiyonu 1 saniye durdurmaya yarar
	randkart(); 	//kartlarý karar
    oyuncu_total = p + l; //oyuncunun çektiði kartlarýn toplam puanýný hesaplar
    p = oyuncu_total; //oyuncunun çektiði kartlarýn toplamýný yeni kart toplamý yapar
    printf("\nKartlarinizin toplam puaný = %d\n", p); 
    bilgisayar(); //bilgisayarýn oynunu oynatýr
       
    while(i<=21) //kazanana kadar kart isteme 
    {
        if(p==21) //oyuncu 21 olursa kazanýr
       {
         	
            printf("\n\t\tTEBRÝKLER Kazandýnýz!!\n");
            kazanilan = kazanilan+1;
            scoin = scoin+bet;
            printf("\nKazanýlan Oyunlar = %d\nKaybedilen Oyunlar = %d\n", kazanilan, kaybedilen);
            bilgisayar_total=0;
            tekraroyna();
        }
     
        if(p>21) 
        {
            printf("\n\t\tMalesef Kaybettiniz. Puanýnýz 21'i geçti.\n");
            kaybedilen = kaybedilen+1;
            scoin = scoin - bet;
            printf("\nKazanýlan Oyunlar = %d\nKaybedilen Oyunlar = %d\n", kazanilan, kaybedilen);
            bilgisayar_total=0;
            tekraroyna();
        }
     
        if(p<=21) //21 altýysa sorar h yada s
        {         
            printf("\n\n\tKart istemek için 'H' -- Beklemek için 'S' basýnýz.\n                              ");
            
            scanf("%c", &secim3);
    
            while((secim3!='H') && (secim3!='S') && (secim3!='s') && (secim3!= 'h')) 
	        {                                                                           
                printf("\n");
		        printf("Lütfen, 'H' yada 'S' basýnýz.\n");
		        scanf("%c",&secim3);
		        
	        }


	        if((secim3 == 'H') || (secim3 == 'h')) 
        	{ 
                randkart();
                oyuncu_total = p + l;
                p = oyuncu_total;
                printf("\nKartlarinizin toplam puaný = %d\n", p);
                bilgisayar();
                if(bilgisayar_total==21) 
                {
                    printf("\n\t\tKaybettiniz.\n");
                    kaybedilen = kaybedilen+1;
                    scoin = scoin - bet;
                    printf("\nKazanýlan Oyunlar = %d\nKaybedilen Oyunlar = %d\n", kazanilan, kaybedilen);
                    bilgisayar_total=0;
                    tekraroyna();
                } 
     
                if(bilgisayar_total>21)
                {                      
                    printf("\n\tKazandýnýz. Bilgisayarýn puaný 21'i geçti.!\n");
                    kazanilan = kazanilan+1;
                    scoin = scoin+bet;
                    printf("\nKazanýlan Oyunlar = %d\nKaybedilen Oyunlar = %d\n", kazanilan, kaybedilen);
                    bilgisayar_total=0;
                    tekraroyna();
                }
            }
            if((secim3 == 'S') || (secim3 == 's')) 
            {
      			printf("\n%d Puanda beklemeyi tercih ettiniz.\n", oyuncu_total);
            	bekle();
            }
        }
            i++;
    }
} 

void bilgisayar() //bilgisayarýn oynuyacaðý oyunun fonksiyonu
{
    int z;
     
    if(bilgisayar_total<17)
    {
    	srand(time(NULL) + 20); //random sayý üretir
    	z=rand()%13+1;
        if(z<=10) // rastegele 10 ve altý üretirse o sayýyý kabul eder
    	{
        	d=z;
        }
     
      	if(z>11)
      	{
        	d=10;
      	}
     
      	if(z==11) // as geldiðinde 10 ve altý ise 11 i seçer
      	{
        	if(bilgisayar_total<=10)
        	{
            	d=11;
        	}
        	else
        	{
            	d=1;
        	}
        }
    bilgisayar_total = bilgisayar_total + d;
    }
          
    printf("\nBilgisayarýn elindeki kartlarýn toplam puaný = %d", bilgisayar_total); 
     
} 

void bekle() //kart almamayý seçerlerse
{
    bilgisayar();
    if(bilgisayar_total>=17)
    {
    	if(oyuncu_total>=bilgisayar_total) 
    	{
        printf("\n\t\tKazandýnýz!!\n");
        kazanilan = kazanilan+1;
        scoin = scoin+bet;
        printf("\nKazanýlan Oyunlar = %d\nKaybedilen Oyunlar = %d\n", kazanilan, kaybedilen);
        bilgisayar_total=0;
        tekraroyna();
   	    }
    	if(oyuncu_total<bilgisayar_total) 
        {
        printf("\n\t\tKaybettiniz!!\n");
        kaybedilen = kaybedilen+1;
        scoin = scoin - bet;
        printf("\nKazanýlan Oyunlar = %d\nKaybedilen Oyunlar = %d\n", kazanilan, kaybedilen);
        bilgisayar_total=0;
        tekraroyna();
      	}
 	    if(bilgisayar_total>21) 
        {
        printf("\n\t\tKazandýnýz!!\n");
        kazanilan = kazanilan+1;
        scoin = scoin+bet;
        printf("\nKazanýlan Oyunlar = %d\nKaybedilen Oyunlar = %d\n", kazanilan, kaybedilen);
        bilgisayar_total=0;
        tekraroyna();
        }
    }
    	else
    	{
        	bekle();
     	}
     
}

void scoin_test() //scoinin bitip bitmediðini denemek için ve ekrana bastýrmak için kullanýlan fonksiyon
{
    if (scoin <= 0)
    {
		printf("\n\tBakiyenizde scoin kalmadý\n\n\tGAME OVER\n\n\tKAYBETTÝNÝZ!!");
		scoin = 1000;
        tekraroyna();
    }
}

int betmiktari() //oynamak istenilen bahis miktarý
{
	printf("\n\nBahis miktarý belirleyiniz : £");
	scanf("%d", &bet);

	if (bet > scoin)
	{
		printf("\nBakiyenizde bulunan miktardan fazla bahis giremezsiniz.");
		printf("\nBahis miktarý belirleyiniz: ");
        scanf("%d", &bet);
        return bet;
	}
	else return bet;
}

void tekraroyna() // Oyuncuya tekar oynamak isteyip istemediðini soran fonk
{
	char secim1;
        
	printf("\nTekrar oynamak ister misiniz?");
    printf("\nEvet için 'E' -- Hayýr için 'H' basýnýz.\n");
    scanf("\n%c", &secim1);

	while((secim1!='E') && (secim1!='H') && (secim1!='e') && (secim1!='h'))
	{                                                                           
		printf("\n");
		printf("Gecersiz secim. Lütfen 'E' veya 'H' den birisini seciniz.\n");
		scanf("%c",&secim1);		
	}


	if((secim1 == 'E') || (secim1 == 'e')) 
	{ 
            system("cls");
            oyun();
	}
 
  	else if((secim1 == 'H') || (secim1 == 'h'))
	{
        printf("\n\t\tÝyi Günler.\nBaþka bir gün tekrar görüþmek dileðiyle...\n\n");
        system("pause");
        exit(0);
	}
	return;
}

int randkart() //Rastgele kart oluþturan fonksiyon
{
    srand(time(NULL)); //rastgele sayýlar oluþturmak için seed belirler
    random_kart = rand()%4+1; // sinek,kupa,maça,karo seçimi
     
switch(random_kart){

     case 1:	//Sinek
     {   
        srand(time(NULL)+1); //rastgele sayýlar oluþturmak için seed belirler +1 de diðer seedlerle ayný olmamasýný saðlar
        int olasilik[13] = {1,1,1,1,1,1,1,1,1,2,3,4,5};  //olasýlýklarý eþitleme
   		ksinek=rand()%13;	//Sinek kartlarýndan birinin seçimi olasýlýk dizisi içinden rastgele sayý
   		
   		switch(olasilik[ksinek]) //olasýlýk dizisi 
		{
		   
    	case 1:
    		srand(time(NULL)+14);
    		
			ksinek=rand()%10+1;
    		{
   			
				printf("\t\t\t|#######|\n");
   		 		printf("\t\t\t||%c    ||\n", sinek);
    			printf("\t\t\t||  %d  ||\n", ksinek);
   		 		printf("\t\t\t||    %c||\n", sinek);
   		 		printf("\t\t\t|#######|\n");
    				l=ksinek;
    				break;
    		}
    
    
    	case 2:
    		{
   			
				printf("\t\t\t|#######|\n");
   		 		printf("\t\t\t||%c    ||\n", sinek);
    			printf("\t\t\t||  J  ||\n");
   		 		printf("\t\t\t||    %c||\n", sinek);
   		 		printf("\t\t\t|#######|\n");
    				l=10;
    				break;
    		}
    
    
   		case 3:
   			{
   		
				printf("\t\t\t|#######|\n");
   		 		printf("\t\t\t||%c    ||\n", sinek);
    			printf("\t\t\t||  A  ||\n");
   		 		printf("\t\t\t||    %c||\n", sinek);
   		 		printf("\t\t\t|#######|\n");
   			 		printf("'A' degerinini <<'1' veya '11'>> olarak belirleyiniz : ");
   			 		scanf("%d", &asdegeri);
   			 		l=asdegeri;
   			 			break;
   			}
    
    
    	case 4:
   		 	{
   		
				printf("\t\t\t|#######|\n");
   		 		printf("\t\t\t||%c    ||\n", sinek);
    			printf("\t\t\t||  Q  ||\n");
   		 		printf("\t\t\t||    %c||\n", sinek);
   		 		printf("\t\t\t|#######|\n");
   		 			l=10; 
  		 				break;
    		}
    
    	case 5:
    		{
    	
				printf("\t\t\t|#######|\n");
   		 		printf("\t\t\t||%c    ||\n", sinek);
    			printf("\t\t\t||  K  ||\n");
   		 		printf("\t\t\t||    %c||\n", sinek);
   		 		printf("\t\t\t|#######|\n");
   			 		l=10; 
   			 			break;
    		}
     	}
         
		 break;
    }
     
     case 2:	//karo 
     {
	 
        srand(time(NULL)+2); 
   		int olasilik[13] = {1,1,1,1,1,1,1,1,1,2,3,4,5};
   		kkaro=rand()%13;	//Karo kartlarýndan birinin seçimi
   		
   		switch(olasilik[kkaro])
		{
		   
    
    	case 1:
    		srand(time(NULL)+13);
			kkaro=rand()%10+1; 
    		{
   			 
				printf("\t\t\t|#######|\n");
   		 		printf("\t\t\t||%c    ||\n", karo);
    			printf("\t\t\t||  %d  ||\n", kkaro);
   		 		printf("\t\t\t||    %c||\n", karo);
   		 		printf("\t\t\t|#######|\n");
    				l=kkaro;
    				break;
    		}
    
    
    	case 2:
    		{
   			 
				printf("\t\t\t|#######|\n");
   		 		printf("\t\t\t||%c    ||\n", karo);
    			printf("\t\t\t||  J  ||\n");
   		 		printf("\t\t\t||    %c||\n", karo);
   		 		printf("\t\t\t|#######|\n");
    				l=10;
    				break;
    		}
    
    
   		case 3:
   			{
   			 
				printf("\t\t\t|#######|\n");
   		 		printf("\t\t\t||%c    ||\n", karo);
    			printf("\t\t\t||  A  ||\n");
   		 		printf("\t\t\t||    %c||\n", karo);
   		 		printf("\t\t\t|#######|\n");
   			 		printf("'A' degerinini <<'1' veya '11'>> olarak belirleyiniz : ");
   			 		scanf("%d", &asdegeri);
   			 		l=asdegeri;
   			 			break;
   			}
    
    
    	case 4:
   		 	{
   			 
				printf("\t\t\t|#######|\n");
   		 		printf("\t\t\t||%c    ||\n", karo);
    			printf("\t\t\t||  Q  ||\n");
   		 		printf("\t\t\t||    %c||\n", karo);
   		 		printf("\t\t\t|#######|\n");
   		 			l=10; 
   		 				break;
    		}
    
    
    	case 5:
    		{
    		
				printf("\t\t\t|#######|\n");
   		 		printf("\t\t\t||%c    ||\n", karo);
    			printf("\t\t\t||  K  ||\n");
   		 		printf("\t\t\t||    %c||\n", karo);
   		 		printf("\t\t\t|#######|\n");
   			 		l=10; 
   			 			break;
    		}
     	}
         
		 break;
     }
     
     case 3:	//Kupa
	{
        srand(time(NULL)+3); 
   		int olasilik[13] = {1,1,1,1,1,1,1,1,1,2,3,4,5};
   		kkupa=rand()%13;	//Kupa kartlarýndan birinin seçimi
   		
   		switch(olasilik[kkupa])
		{
		   
    
    	case 1:
    		srand(time(NULL)+12);
			kkupa=rand()%10+1; 
    		{
   			 
				printf("\t\t\t|#######|\n");
   		 		printf("\t\t\t||%c    ||\n", kupa);
    			printf("\t\t\t||  %d  ||\n", kkupa);
   		 		printf("\t\t\t||    %c||\n", kupa);
   		 		printf("\t\t\t|#######|\n");
    				l=kkupa;
    				break;
    		}
    
    
    	case 2:
    		{
   			 
				printf("\t\t\t|#######|\n");
   		 		printf("\t\t\t||%c    ||\n", kupa);
    			printf("\t\t\t||  J  ||\n");
   		 		printf("\t\t\t||    %c||\n", kupa);
   		 		printf("\t\t\t|#######|\n");
    				l=10;
    				break;
    		}
    
    
   		case 3:
   			{
   			 
				printf("\t\t\t|#######|\n");
   		 		printf("\t\t\t||%c    ||\n", kupa);
    			printf("\t\t\t||  A  ||\n");
   		 		printf("\t\t\t||    %c||\n", kupa);
   		 		printf("\t\t\t|#######|\n");
   			 		printf("'A' degerinini <<'1' veya '11'>> olarak belirleyiniz : ");
   			 		scanf("%d", &asdegeri);
   			 		l=asdegeri;
   			 			break;
   			}
    
    
    	case 4:
   		 	{
   			 
				printf("\t\t\t|#######|\n");
   		 		printf("\t\t\t||%c    ||\n", kupa);
    			printf("\t\t\t||  Q  ||\n");
   		 		printf("\t\t\t||    %c||\n", kupa);
   		 		printf("\t\t\t|#######|\n");
   		 			l=10; 
   		 				break;
    		}
    
    
    	case 5:
    		{
    		
				printf("\t\t\t|#######|\n");
   		 		printf("\t\t\t||%c    ||\n", kupa);
    			printf("\t\t\t||  K  ||\n");
   		 		printf("\t\t\t||    %c||\n", kupa);
   		 		printf("\t\t\t|#######|\n");
   			 		l=10; 
   			 			break;
    		}
     	}
         
		 break;
     }
         
     case 4:	//maca
     {
        srand(time(NULL)+4); 
   		int olasilik[13] = {1,1,1,1,1,1,1,1,1,2,3,4,5};
   		kmaca=rand()%13;	//Maça kartlarýndan birinin seçimi
   		
   		switch(olasilik[kmaca])
		{
		   
    
    	case 1:
    		srand(time(NULL)+11);
			kmaca=rand()%10+1; 
    		{
   			 
				printf("\t\t\t|#######|\n");
   		 		printf("\t\t\t||%c    ||\n", maca);
    			printf("\t\t\t||  %d  ||\n", kmaca);
   		 		printf("\t\t\t||    %c||\n", maca);
   		 		printf("\t\t\t|#######|\n");
    				l=kmaca;
    				break;
    		}
    
    
    	case 2:
    		{
   			 
				printf("\t\t\t|#######|\n");
   		 		printf("\t\t\t||%c    ||\n", maca);
    			printf("\t\t\t||  J  ||\n");
   		 		printf("\t\t\t||    %c||\n", maca);
   		 		printf("\t\t\t|#######|\n");
    				l=10;
    				break;
    		}
    
    
   		case 3:
   			{
   			 
				printf("\t\t\t|#######|\n");
   		 		printf("\t\t\t||%c    ||\n", maca);
    			printf("\t\t\t||  A  ||\n");
   		 		printf("\t\t\t||    %c||\n", maca);
   		 		printf("\t\t\t|#######|\n");
   			 		printf("'A' degerinini <<'1' veya '11'>> olarak belirleyiniz : ");
   			 		scanf("%d", &asdegeri);
   			 		l=asdegeri;
   			 			break;
   			}
    
    
    	case 4:
   		 	{
   			 
				printf("\t\t\t|#######|\n");
   		 		printf("\t\t\t||%c    ||\n", maca);
    			printf("\t\t\t||  Q  ||\n");
   		 		printf("\t\t\t||    %c||\n", maca);
   		 		printf("\t\t\t|#######|\n");
   		 			l=10; 
   		 				break;
    		}
    
    
    	case 5:
    		{
    		
				printf("\t\t\t|#######|\n");
   		 		printf("\t\t\t||%c    ||\n", maca);
    			printf("\t\t\t||  K  ||\n");
   		 		printf("\t\t\t||    %c||\n", maca);
   		 		printf("\t\t\t|#######|\n");
   			 		l=10; 
   			 			break;
    		}
     	}
         
		 break;
     } 
}
     return l; //seçilen kartýn deðerini döndürür
}
