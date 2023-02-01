#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

char pomocni1 [20];
char pomocni2 [20];
char pomocni3 [3];
char pomocni4 [3];
char pomocni5 [3];
char pomocni6 [3];
char pass [8];
char pass1 [8];

class RezervacijaAK
{
      public:
             char* ime;
             char* prezime;
             char* sifra;
             int satiP;
             int minutiP;
             int satiS;
             int minutiS;
             bool kasni;
             
             RezervacijaAK ()
             {
             }
             RezervacijaAK( char*, char*, char* );
             
             void postaviTrenutno();
             friend istream& operator >> (istream &, RezervacijaAK &);
             void ispisi();
             
             friend bool operator < (RezervacijaAK& r1, RezervacijaAK& r2);
             
             char* vratiIme ()
             {
                   return ime;
             }
             char* vratiPrezime ()
             {
                   return prezime;
             }
             char* vratiSifru ()
             {
                   return sifra;
             }
             int vratiSateP()
             {
                 return satiP;
             }
             int vratiMinuteP()
             {
                 return minutiP;
             }
             int vratiSateS()
             {
                 return satiS;
             }
             int vratiMinuteS()
             {
                 return minutiS;
             }
             
      
      
};

RezervacijaAK::RezervacijaAK( char* name, char* tp, char* ts )
{
     int i=0;
     while (*(name+i) != ',' )
     {
          pomocni1[i]=*(name+i); 
          i++;
     }
     pomocni1[i+1]='\0';
     char *pok1=&pomocni1[0];
     ime=pok1;
     i++;
     int j=0;
     while (*(name+i) != '\0' )
     {
          pomocni2[j]=*(name+i); 
          i++; j++;
     }
     pomocni2[j+1]='\0';
     char *pok2=&pomocni2[0];
     prezime=pok2;
     
     i=0;
     while (*(tp+i) != ':' )
     {
          pomocni3[i]=*(tp+i); 
          i++;
     }
     char *vr=pomocni3;

     
     if(i==1)
     {
         int pom= (*vr-'0');
         if (pom >=0 && pom <=24)
         {
             satiP=pom;
         }
         else
         {
             postaviTrenutno();
            
         }
     }
     else
     {
         int pom= (*vr-'0')*10+ (*(vr+1)-'0');
         if (pom >=0 && pom <=24)
         {
             satiP=pom;
         }
         else
         {
             postaviTrenutno();
             
         }
     }
    
     
     
     i++;
     j=0;
     while (*(tp+i) != '\0' )
     {
          pomocni4[j]=*(tp+i); 
          i++; j++;
     }
     
     char *vr1=pomocni4;
     
     if(j==1)
     {
         int pom=(*vr1-'0');
         if(pom>=0 && pom <=59)
         {
             minutiP=pom;
         }
         else
         {
             postaviTrenutno();
         }
     }
     else
     {
         int pom=(*vr1-'0')*10+ (*(vr1+1)-'0');
         if(pom>=0 && pom <=59)
         {
             minutiP=pom;
         }
         else
         {
             postaviTrenutno();
         }
     }
     
     
     
     //--------------------------------------
     
     
     i=0;
     while (*(ts+i) != ':' )
     {
          pomocni5[i]=*(ts+i); 
          i++;
     }
     char *vs=pomocni5;
     if(i==1)
     {
         int pom= (*vs-'0');
         if(pom>=0 && pom <=59)
         {
             satiS=pom;
         }
         else
         {
             postaviTrenutno();
         }
     }
     else
     {
          int pom= (*vs-'0')*10+ (*(vs+1)-'0');
          if(pom>=0 && pom <=59)
         {
             satiS=pom;
         }
         else
         {
             postaviTrenutno();
         }
     }
    
     
     
     i++;
     j=0;
     while (*(ts+i) != '\0' )
     {
          pomocni6[j]=*(ts+i); 
          i++; j++;
     }
     
     char *vs1=pomocni6;
     
     if(j==1)
     {
         int pom=(*vs1-'0');
         if(pom>=0 && pom <=24)
         {
             minutiS=pom;
         }
         else
         {
             postaviTrenutno();
         }
     }
     else
     {
         int pom=(*vs1-'0')*10+ (*(vs1+1)-'0');
         if(pom>=0 && pom <=59)
         {
             minutiS=pom;
         }
         else
         {
             postaviTrenutno();
         }
     }
     
     srand (time(NULL));
     rand ();
     int poz=0;
     for(int k=0; k<3; k++)
     {
         int pom=rand()%26;
         char c='A'+pom;
         pass[poz]=c;
         poz+=3;    
     }
     poz=1;
     for(int k=0; k<2; k++)
     {
         int pom=rand()%10;
         char c='0'+pom;
         pass[poz]=c;
         poz+=3;    
     }
     
     poz=2;
     for(int k=0; k<2; k++)
     {
         int pom=rand()%26;
         char c='a'+pom;
         pass[poz]=c;
         poz+=3;    
     }
     
     sifra=pass;
     
     kasni=false;
     
  /*   cout << sifra << endl;
     
     cout << ime << endl << prezime << endl << satiP << endl << minutiP << endl << satiS << endl << minutiS << endl;
  */   
}

void RezervacijaAK::postaviTrenutno()
{
     time_t vrijeme;
     vrijeme=time(NULL);
     tm *pok=gmtime(&vrijeme);
     int h=pok->tm_hour+1;
     int min=pok->tm_min;
     
     satiP=h;
     satiS=h;
     minutiP=min;
     minutiS=min;  
}

istream& operator >> (istream & upis, RezervacijaAK & r)
{
    cout << "Unesite ime: ";
    upis >> r.ime;
    cout << "Unesite prezime: ";
    upis >> r.prezime;
    r.kasni=false;
    
    
    
     srand (time(NULL));
     rand ();
     int poz=0;
     for(int k=0; k<3; k++)
     {
         int pom=rand()%26;
         char c='A'+pom;
         pass1[poz]=c;
         poz+=3;    
     }
     poz=1;
     for(int k=0; k<2; k++)
     {
         int pom=rand()%10;
         char c='0'+pom;
         pass1[poz]=c;
         poz+=3;    
     }
     
     poz=2;
     for(int k=0; k<2; k++)
     {
         int pom=rand()%26;
         char c='a'+pom;
         pass1[poz]=c;
         poz+=3;    
     }
     
     r.sifra=pass1;
     
     r.satiP=rand()%25;
     r.minutiP=rand()%60;
     
     int s1=r.satiP+2;
     int m1=r.minutiP+30;
     
     if(m1>=60)
     {
         s1++;
         m1-=60;
         r.satiS=s1;
         r.minutiS=m1;
     }
     else
     {
         r.satiS=s1;
         r.minutiS=m1;
     }
     
  /*   cout << r.sifra << endl;
     
     cout << r.ime << endl << r.prezime << endl << r.satiP << endl << r.minutiP << endl << r.satiS << endl << r.minutiS << endl;
     */
     
     return upis;            
}


void RezervacijaAK::ispisi()
{
    cout << "Sifra leta: " << sifra << endl
         << "Ime putinika: " << ime << endl 
         << "Prezime putnika: " << prezime << endl
         << "Vreme poletanja: " << satiP << ":" << minutiP << "h" << endl
         << "Vreme sletanja: " << satiS << ":" << minutiS << "h" << endl;
         
         if(kasni)
         {
             cout << "Let kasni" << endl;
         }
         else
         {
             cout << "Na vrijeme" << endl;
         }
         cout << endl;
}


bool operator < (RezervacijaAK& r1, RezervacijaAK& r2)
{
    bool p=false;
    
    if(r1.satiP < r2.satiP)
    {
        p=true;
    }
    else if(r1.satiP == r2.satiP)
    {
        if(r1.minutiP < r2.minutiP)
        {
            p=true;
        } 
    }
    else if (r1.satiS < r2.satiS)
    {
        p=true;
    }
    else if(r1.satiS == r2.satiS)
    {
        if(r1.minutiS < r2.minutiS)
        {
            p=true;
        } 
    }
    else
    {
        int i=0;
        while (*(r1.sifra+i) != '\0' )
        {
             if ( *(r1.sifra+i) < *(r2.sifra+i) )
             {
                  p=true;
             }
             i++;
        }
    }
    return p;
}

int main()
{
    RezervacijaAK r("Marko,Markovic", "25:95", "15:35");
	RezervacijaAK r1("perko,merko", "2:56", "23:05");
    
    
    r.ispisi();
    r1.ispisi();
    
    system("pause");
}
