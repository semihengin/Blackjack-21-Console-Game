
#include <stdlib.h>
#include <stdio.h>								//Semih Engin 191180037 37. Grup Kart Oyunu
#include <math.h>				 
#include <locale.h>				 //t�rk�e karakter kullanmam�z� sa�lar
#include <time.h>                //srand fonk kullanmak i�in gerekli k�t�phane
#include <unistd.h>				 //sleep fonk kullanmak i�in gerekli k�t�phane
#include <process.h>             //system("cls") "�nceki yaz�lanlar� sildirme" komutunu kullanmam�z� sa�lar.

#define kupa 03                 //kupa sembol� yazd�rmak i�in alt+3
#define karo 04                 //karo sembol� yazd�rmak i�in alt+4	
#define sinek 05                //Sinek sembol� yazd�rmak i�in alt+5
#define maca 06                 //Ma�a sembol� yazd�rmak i�in alt+6

int ksinek,kkaro,kkupa,kmaca,l,d,asdegeri,kazanilan,kaybedilen,bet,random_kart;
int scoin = 1000;
int oyuncu_total=0;
int bilgisayar_total;

int randkart();         //Rastgele kart olu�turma fonksiyonu
int betmiktari();       //Kulan�c�dan bet(bahis) istemek i�in kullan�lan fonk
void baslangic();       //Giri� ekran� fonksiyonu
void hosgeldiniz();		//Ana men� fonksiyonu
void kurallar();        //Kurallar� g�steren fonksiyon
void oyun();            //Oyunun oynand��� fonksiyon
void bilgisayar();      //Bilgisayar�n oynamas�n� sa�layan fonksiyon
void bekle();            //Kullan�c� beklemek istedi�inde kullan�lan fonk
void scoin_test();      //Bakiye testi i�in kullan�lan fonksiyon
void tekraroyna();         //AKullan�c�ya tekrar oynamak isteyip istemedi�ini soran fonk


int main(void)
{
	
    int secim1;
	setlocale(LC_ALL, "Turkish"); //t�rk�e karakterler i�in 
    baslangic();

    system("pause");
    return(0);
} 

void baslangic() // Giri� ekran� fonk
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
	printf("\n                            OYUNUNA HO�GELD�N�Z DEVAM ETMEK ���N 'ENTER' BASINIZ ");
    printf("\n                                       --------------------------\n                                                   ");
    
	scanf("%c", &secim1);
    if (secim1 == 0x0A) //enter ile ge�memizi sa�lar
	hosgeldiniz();
	
	return;
}

void hosgeldiniz() //Ana men� ekran�
{
	int secim2;
			
			system("cls");
			
			printf("\n\n\n\t\t\t=> ANA MENU <=\n");
	        printf("\n\n\t=> Haz�rsan�z '1' girerek oyuna ba�l�yabiliriz.\n");
		    printf("\n\t=> Oyunun kurallar�na g�z atmak i�in '2' giriniz.\n");
		    printf("\n\t=> Oyundan ��kmak i�in '3' giriniz.\n");
		    printf("\n\n    L�tfen se�iminizi giriniz : ");
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
                   printf("\n       => Oynamak istememenize �z�ld�k");
                   printf("\n       => Ba�ka bir zaman g�r��mek �zere...\n\n");
                   system("pause");
                   exit(0); //programdan ��k�� yapar
                   break;
                default :
                	printf("\nGe�ersiz de�er girdiniz. L�tfen 1, 2 yada 3 de�erlerinden birini giriniz.\n");
                	sleep(1);
                   	hosgeldiniz();
            }
}
void kurallar() //kurallar fonk yazd�r�r
{
    char secim1;
    int secim2;
    
	system("cls");
    printf("\n		-------BLACKJACK (21) NASIL B�R OYUNDUR ?-------\n\n");
    
	printf(" => Blackjack, bir veya birden �ok desteyle oynanan bir kart oyunudur..\n");
    printf(" => Amac�n�z, toplamda 21 puan� a�madan krupiyeden(bilgisayardan) daha y�ksek bir toplam puana ula�makt�r.\n");
    
	printf("\n		-------BLACKJACK (21) NASIL OYNANIR ?-------\n\n");
	
	printf(" => Blackjack oyunu kart de�erleri : \n\n");
    printf(" 	** 2 den 9 a kladar olan kartlarda �zerlerindeki rakam neyse puanlar� da odur.\n");
    printf("	** 10, J, Q, K � hepsi 10 puan de�erindedir.\n");
    printf(" 	** Blackjack A ka� puan, en s�k sorulan sorulardan biridir.\n" );
    printf("	** As kartlar� 1 veya 11 puan de�erinde olabilir; bunun se�imi oyuncuya aittir.\n");
    
	printf("\n => Blackjack oyunu nas�l oynan�r : \n\n");
    
	printf("	** Krupiyer yani bilgisayar, kendisine ve oyuncuya 1er kart verir.\n");
    printf("	** Daha sonra oyuncu oynamak istedi�i bahis miktar�n� girer.\n");
    printf("	** Blackjack krupiye kurallar�na g�re, krupiyenin sadece tek bir kart� oyuncu taraf�ndan g�r�lebilir.\n");
  	printf("	** �kinci kart� ise bahisden sonra g�sterilir.\n");
    printf("	** llk kart sonras�nda, �u se�eneklerden birini kullanabilirsiniz :\n");
    printf("\n   		 + Kart �ste (Hit) � bir kart daha istemi� olursunuz.");
    printf("\n    		 + Bekle (Stand) � ba�ka kart istemedi�iniz anlam�na gelir.\n");
    printf("\n	** Kart da��t�m� bitince eller kar��la�t�r�l�r ve 21 puana en yak�n olan taraf oyunu kazan�r.\n");
	printf("\n =>  Kurallar� anlad�ysan�z oynuna ba�lamak i�in 'E' bas�n�z.\n");
	printf("\n =>  Oyunun ana men�s�ne d�nemk i�in 'H' bas�n�z.\n");

	printf("\n                  		(E/H)\n				  ");
    scanf("\n%c",&secim1);
   
     
    while((secim1!='E') && (secim1!='H') && (secim1!='e') && (secim1!='h'))
	{                                                                           
		printf("\n");
		printf("Gecersiz secim. L�tfen 'E' veya 'H' den birisini seciniz : ");
		scanf("%c",&secim1);
	}

	switch(toupper(secim1)) //girilen karakteri b�y�k karaktere �evirir
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
void oyun() //Oyunun oynand��� fonksiyon
{
     
    int p=0; // oyunucunun �ekti�i kartlar�n puan�
    int i=1; // kazanana kadar kart isteme d�ng�s�n�n sayac�
    char secim3;
    system("cls");//ekran� temizler 
    scoin_test(); //scoinin bitip bitmedi�ini denemek i�in ve ekrana bast�rmak i�in kullan�lan fonksiyon
    printf("\nSCoin: �%d\n",scoin); 
    betmiktari(); //bahis miktar�n� girdirecek fonksiyon sahip olunandan fazla girilirse uyar� verir
	printf("\n");
	printf("\tKartlar Kar�l�yor... \n\n");
	sleep(1); 		//fonksiyonu 1 saniye durdurmaya yarar
	randkart(); 	//kartlar� karar
    oyuncu_total = p + l; //oyuncunun �ekti�i kartlar�n toplam puan�n� hesaplar
    p = oyuncu_total; //oyuncunun �ekti�i kartlar�n toplam�n� yeni kart toplam� yapar
    printf("\nKartlarinizin toplam puan� = %d\n", p); 
    bilgisayar(); //bilgisayar�n oynunu oynat�r
       
    while(i<=21) //kazanana kadar kart isteme 
    {
        if(p==21) //oyuncu 21 olursa kazan�r
       {
         	
            printf("\n\t\tTEBR�KLER Kazand�n�z!!\n");
            kazanilan = kazanilan+1;
            scoin = scoin+bet;
            printf("\nKazan�lan Oyunlar = %d\nKaybedilen Oyunlar = %d\n", kazanilan, kaybedilen);
            bilgisayar_total=0;
            tekraroyna();
        }
     
        if(p>21) 
        {
            printf("\n\t\tMalesef Kaybettiniz. Puan�n�z 21'i ge�ti.\n");
            kaybedilen = kaybedilen+1;
            scoin = scoin - bet;
            printf("\nKazan�lan Oyunlar = %d\nKaybedilen Oyunlar = %d\n", kazanilan, kaybedilen);
            bilgisayar_total=0;
            tekraroyna();
        }
     
        if(p<=21) //21 alt�ysa sorar h yada s
        {         
            printf("\n\n\tKart istemek i�in 'H' -- Beklemek i�in 'S' bas�n�z.\n                              ");
            
            scanf("%c", &secim3);
    
            while((secim3!='H') && (secim3!='S') && (secim3!='s') && (secim3!= 'h')) 
	        {                                                                           
                printf("\n");
		        printf("L�tfen, 'H' yada 'S' bas�n�z.\n");
		        scanf("%c",&secim3);
		        
	        }


	        if((secim3 == 'H') || (secim3 == 'h')) 
        	{ 
                randkart();
                oyuncu_total = p + l;
                p = oyuncu_total;
                printf("\nKartlarinizin toplam puan� = %d\n", p);
                bilgisayar();
                if(bilgisayar_total==21) 
                {
                    printf("\n\t\tKaybettiniz.\n");
                    kaybedilen = kaybedilen+1;
                    scoin = scoin - bet;
                    printf("\nKazan�lan Oyunlar = %d\nKaybedilen Oyunlar = %d\n", kazanilan, kaybedilen);
                    bilgisayar_total=0;
                    tekraroyna();
                } 
     
                if(bilgisayar_total>21)
                {                      
                    printf("\n\tKazand�n�z. Bilgisayar�n puan� 21'i ge�ti.!\n");
                    kazanilan = kazanilan+1;
                    scoin = scoin+bet;
                    printf("\nKazan�lan Oyunlar = %d\nKaybedilen Oyunlar = %d\n", kazanilan, kaybedilen);
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

void bilgisayar() //bilgisayar�n oynuyaca�� oyunun fonksiyonu
{
    int z;
     
    if(bilgisayar_total<17)
    {
    	srand(time(NULL) + 20); //random say� �retir
    	z=rand()%13+1;
        if(z<=10) // rastegele 10 ve alt� �retirse o say�y� kabul eder
    	{
        	d=z;
        }
     
      	if(z>11)
      	{
        	d=10;
      	}
     
      	if(z==11) // as geldi�inde 10 ve alt� ise 11 i se�er
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
          
    printf("\nBilgisayar�n elindeki kartlar�n toplam puan� = %d", bilgisayar_total); 
     
} 

void bekle() //kart almamay� se�erlerse
{
    bilgisayar();
    if(bilgisayar_total>=17)
    {
    	if(oyuncu_total>=bilgisayar_total) 
    	{
        printf("\n\t\tKazand�n�z!!\n");
        kazanilan = kazanilan+1;
        scoin = scoin+bet;
        printf("\nKazan�lan Oyunlar = %d\nKaybedilen Oyunlar = %d\n", kazanilan, kaybedilen);
        bilgisayar_total=0;
        tekraroyna();
   	    }
    	if(oyuncu_total<bilgisayar_total) 
        {
        printf("\n\t\tKaybettiniz!!\n");
        kaybedilen = kaybedilen+1;
        scoin = scoin - bet;
        printf("\nKazan�lan Oyunlar = %d\nKaybedilen Oyunlar = %d\n", kazanilan, kaybedilen);
        bilgisayar_total=0;
        tekraroyna();
      	}
 	    if(bilgisayar_total>21) 
        {
        printf("\n\t\tKazand�n�z!!\n");
        kazanilan = kazanilan+1;
        scoin = scoin+bet;
        printf("\nKazan�lan Oyunlar = %d\nKaybedilen Oyunlar = %d\n", kazanilan, kaybedilen);
        bilgisayar_total=0;
        tekraroyna();
        }
    }
    	else
    	{
        	bekle();
     	}
     
}

void scoin_test() //scoinin bitip bitmedi�ini denemek i�in ve ekrana bast�rmak i�in kullan�lan fonksiyon
{
    if (scoin <= 0)
    {
		printf("\n\tBakiyenizde scoin kalmad�\n\n\tGAME OVER\n\n\tKAYBETT�N�Z!!");
		scoin = 1000;
        tekraroyna();
    }
}

int betmiktari() //oynamak istenilen bahis miktar�
{
	printf("\n\nBahis miktar� belirleyiniz : �");
	scanf("%d", &bet);

	if (bet > scoin)
	{
		printf("\nBakiyenizde bulunan miktardan fazla bahis giremezsiniz.");
		printf("\nBahis miktar� belirleyiniz: ");
        scanf("%d", &bet);
        return bet;
	}
	else return bet;
}

void tekraroyna() // Oyuncuya tekar oynamak isteyip istemedi�ini soran fonk
{
	char secim1;
        
	printf("\nTekrar oynamak ister misiniz?");
    printf("\nEvet i�in 'E' -- Hay�r i�in 'H' bas�n�z.\n");
    scanf("\n%c", &secim1);

	while((secim1!='E') && (secim1!='H') && (secim1!='e') && (secim1!='h'))
	{                                                                           
		printf("\n");
		printf("Gecersiz secim. L�tfen 'E' veya 'H' den birisini seciniz.\n");
		scanf("%c",&secim1);		
	}


	if((secim1 == 'E') || (secim1 == 'e')) 
	{ 
            system("cls");
            oyun();
	}
 
  	else if((secim1 == 'H') || (secim1 == 'h'))
	{
        printf("\n\t\t�yi G�nler.\nBa�ka bir g�n tekrar g�r��mek dile�iyle...\n\n");
        system("pause");
        exit(0);
	}
	return;
}

int randkart() //Rastgele kart olu�turan fonksiyon
{
    srand(time(NULL)); //rastgele say�lar olu�turmak i�in seed belirler
    random_kart = rand()%4+1; // sinek,kupa,ma�a,karo se�imi
     
switch(random_kart){

     case 1:	//Sinek
     {   
        srand(time(NULL)+1); //rastgele say�lar olu�turmak i�in seed belirler +1 de di�er seedlerle ayn� olmamas�n� sa�lar
        int olasilik[13] = {1,1,1,1,1,1,1,1,1,2,3,4,5};  //olas�l�klar� e�itleme
   		ksinek=rand()%13;	//Sinek kartlar�ndan birinin se�imi olas�l�k dizisi i�inden rastgele say�
   		
   		switch(olasilik[ksinek]) //olas�l�k dizisi 
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
   		kkaro=rand()%13;	//Karo kartlar�ndan birinin se�imi
   		
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
   		kkupa=rand()%13;	//Kupa kartlar�ndan birinin se�imi
   		
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
   		kmaca=rand()%13;	//Ma�a kartlar�ndan birinin se�imi
   		
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
     return l; //se�ilen kart�n de�erini d�nd�r�r
}
