#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

bool igra_traje = true;
char potez2;
string ploca1[8][8];
void PocetnaPloca(){
cout<<"    a  b  c  d  e  f  g  h";
     for(int i = 0; i<8;i++){
        for(int j = 0; j<8;j++){
            ploca1[i][j] = "  ";
        }
    }
    for(int i = 0; i<8;i++){
        ploca1[1][i] = "BP";
    }

    for(int i = 0; i<8;i++){
        ploca1[6][i] = "WP";
    }

    //kule
    ploca1[0][0] = "BR";
    ploca1[0][7] = "BR";
    ploca1[7][7] = "WR";
    ploca1[7][0] = "WR";
    //konji
    ploca1[0][1] = "BN";
    ploca1[0][6] = "BN";

   // ploca1[3][2] = "WN";
   // ploca1[5][2] = "WN";
   // ploca1[3][4] = "WN";
   // ploca1[5][4] = "WN";

    ploca1[7][6] = "WN";
    ploca1[7][1] = "WN";
    //lovci
    ploca1[0][2] = "BB";
    ploca1[0][5] = "BB";

    //ploca1[4][3] = "BB";

    ploca1[7][5] = "WB";
    ploca1[7][2] = "WB";
    //kraljice i kraljevi
    ploca1[0][3] = "BQ";
    ploca1[0][4] = "BK";
    ploca1[7][3] = "WQ";
    ploca1[7][4] = "WK";
    //printanje ploce

    int o = 8;
    cout<<endl<<"   -------------------------"<<endl;
    for(int i = 0; i<8;i++){
        cout<<" "<<o<<" ";
        for(int j = 0; j<8;j++){
            cout<<"|"<<ploca1[i][j]<<"";
        }
        cout<<"| "<<o;
        cout<<endl<<"   -------------------------"<<endl;
        o--;
    }
    cout<<"    a  b  c  d  e  f  g  h"<<endl;


}
void ploca(){
    cout<<"    a  b  c  d  e  f  g  h";

int o = 8;
    cout<<endl<<"   -------------------------"<<endl;
    for(int i = 0; i<8;i++){
        cout<<" "<<o<<" ";
        for(int j = 0; j<8;j++){
            cout<<"|"<<ploca1[i][j]<<"";
        }
        cout<<"| "<<o;
        cout<<endl<<"   -------------------------"<<endl;
        o--;
    }
    cout<<"    a  b  c  d  e  f  g  h"<<endl;

}
void MicanjeFigura(string poc,string kraj){
    //slova i broj koji su uneseni gledam koja je to pozicija u matrici
    int poz_red = abs((poc[1]-'0')-8);
    char poz_stu = poc[0];
    int poz_stu1 = int(poz_stu)-97;

    int zav_red = abs((kraj[1]-'0')-8);
    char zav_stu = kraj[0];
    int zav_stu1 = int(zav_stu)-97;
    ploca1[zav_red][zav_stu1] = ploca1[poz_red][poz_stu1];
    ploca1[poz_red][poz_stu1] = "  ";
}
bool IzvanGranica(string pocet_poz,string zav_poz){
    int pp = (pocet_poz[1]-'0');
    int zp = (zav_poz[1]-'0');
    if (pp == 9 || pocet_poz.length()>2 || zp == 9 || zav_poz.length()>2 ){
        return false;
    }else{
        return true;

    }

}
bool preskakanje(string poc,string kraj){
    int poz_red = abs((poc[1]-'0')-8);
    char poz_stu = poc[0];
    int poz_stu1 = int(poz_stu)-97;
    string pocetna_figura = ploca1[poz_red][poz_stu1];
    int zav_red = abs((kraj[1]-'0')-8);
    char zav_stu = kraj[0];
    int zav_stu1 = int(zav_stu)-97;
    string zavrsna_figura = ploca1[zav_red][zav_stu1];
    //jesu li figure iste boje
    if (potez2 != pocetna_figura[0]){
        return false;
    }
    if (pocetna_figura[0]==zavrsna_figura[0]){
        return false;
    }else if (pocetna_figura[1]== 'B' || pocetna_figura[1]== 'Q'){
        //ako je lovac
        //cout<<"pocetna figut "<<pocetna_figura;
        //cout<<"zav figut "<<zavrsna_figura;
        if (pocetna_figura[0]==zavrsna_figura[0]){
            return false;
            }
        if (zav_stu1>poz_stu1 && zav_red<poz_red){
            int x = poz_red;
            int y = poz_stu1;
            while( x>zav_red || y<zav_red ){
                x--;
                y++;
                string fig = ploca1[x][y];
                if (fig != "  " ){
                        if (fig == zavrsna_figura){
                            return true;
                        }else{
                            return false;
                        }}}

            }if (zav_stu1>poz_stu1 && poz_red<zav_red){
            int x = poz_red;
            int y = poz_stu1;
            while( x<zav_red || y<zav_red ){
                x++;
                y++;
                string fig = ploca1[x][y];
                if (fig != "  " ){
                        if (fig == zavrsna_figura){
                            return true;
                        }else{
                            return false;
                        }}}
            }
        if (zav_stu1<poz_stu1 && poz_red<zav_red){
            int x = poz_red;
            int y = poz_stu1;

            while( x<zav_red-1 || y>zav_red ){
                x++;
                y--;
                string fig = ploca1[x][y];
                if (fig != "  " ){
                        if (fig == zavrsna_figura){
                            return true;
                        }else{
                            return false;
                        }
                        }
                        }}
            if (zav_stu1<poz_stu1 && zav_red<poz_red){
            int x = poz_red;
            int y = poz_stu1;

            while( x>zav_red || y>zav_red ){
                x--;
                y--;
                string fig = ploca1[x][y];
                if (fig != "  " ){
                        if (fig == zavrsna_figura){
                            return true;
                        }else{
                            return false;
                        }}}

            }
        }else if (pocetna_figura[1]== 'N'){
            return true;
        }else if (pocetna_figura[1]== 'R'  || pocetna_figura[1]== 'Q'){
        if (poz_stu1<zav_stu1){
            int x = poz_red;
            int y = poz_stu1;
            while(y<zav_red ){
                y++;
                string fig = ploca1[x][y];
                if (fig != "  " ){
                        if (fig[0] == pocetna_figura[0]){
                                return false;
                        }
                }
            }
        }
        if (poz_stu1>zav_stu1){
            int x = poz_red;
            int y = poz_stu1;
            while(y<zav_red ){
                y--;
                string fig = ploca1[x][y];
                if (fig != "  " ){
                        if (fig[0] == pocetna_figura[0]){
                                return false;
                        }
                }
            }
        }
        if (zav_red<poz_red){
            int x = poz_red;
            int y = poz_stu1;
            while(x>zav_red ){
                x--;
                string fig = ploca1[x][y];
                if (fig != "  " ){
                        if (fig[0] == pocetna_figura[0]){
                                return false;
                        }
                }
            }
        }
        if (zav_red>poz_red){
            int x = poz_red;
            int y = poz_stu1;
            while(x<zav_red ){
                x++;
                string fig = ploca1[x][y];
                if (fig != "  " ){
                        if (fig[0] == pocetna_figura[0]){
                                return false;
                        }
                }
        }
        }else{
            return true;
    }

}

}

bool LegalniPotez(string poc,string kraj){

    int poz_red = abs((poc[1]-'0')-8);
    char poz_stu = poc[0];
    int poz_stu1 = int(poz_stu)-97;
    string pocetna_figura = ploca1[poz_red][poz_stu1];
    int zav_red = abs((kraj[1]-'0')-8);
    char zav_stu = kraj[0];
    int zav_stu1 = int(zav_stu)-97;
    string zavrsna_figura = ploca1[zav_red][zav_stu1];
    if (zavrsna_figura[1] == 'K'){
       igra_traje = false;
    }

    if (pocetna_figura[1]=='Q'){
        if(zav_red > poz_red && poz_stu1 == zav_stu1){
                return true;
        }else if (zav_red < poz_red && poz_stu1 == zav_stu1){
            return true;
        }else if (zav_stu1 < poz_stu1 && poz_red == zav_red){
            return true;
        }else if (zav_stu1 > poz_stu1 && poz_red == zav_red){
            return true;
        }else if (pocetna_figura[1] == 'B'){
        int raz_red = abs(poz_red-zav_red);
        int raz_stu = abs(poz_stu1-zav_stu1);
        if (raz_red == raz_stu){return true;}
        }
        if (pocetna_figura[1]=='K'){
        int raz_red = abs(poz_red-zav_red);
        int raz_stu = abs(poz_stu1-zav_stu1);
        if (raz_red <= 1 && raz_stu <= 1){
                return true;
            }else{
            return false;
        }
    }}

    if (pocetna_figura[1]=='R'){
        if(zav_red > poz_red && poz_stu1 == zav_stu1){
                return true;
        }else if (zav_red < poz_red && poz_stu1 == zav_stu1){
            return true;
        }else if (zav_stu1 < poz_stu1 && poz_red == zav_red){
            return true;
        }else if (zav_stu1 > poz_stu1 && poz_red == zav_red){
            return true;
        }else {
            return false;
        }
    }
    if (pocetna_figura[1]=='N'){
        if(zav_red<poz_red && poz_stu1>zav_stu1 && poz_red-zav_red == 2 && poz_stu1-zav_stu1 == 1){
            return true;
        }else if(zav_red<poz_red && poz_stu1>zav_stu1 && poz_red-zav_red == 1 && poz_stu1-zav_stu1 == 2){
            return true;
        }else if(zav_red<poz_red && poz_stu1<zav_stu1 && poz_red-zav_red == 1 && zav_stu1-poz_stu1 == 2){
            return true;
        }else if(zav_red<poz_red && poz_stu1<zav_stu1 && poz_red-zav_red == 2 && zav_stu1-poz_stu1 == 1){
            return true;
        }else if(zav_red>poz_red && poz_stu1>zav_stu1 && zav_red-poz_red == 2 && poz_stu1-zav_stu1 == 1){
            return true;
        }else if(zav_red>poz_red && poz_stu1>zav_stu1 && zav_red-poz_red == 1 && poz_stu1-zav_stu1 == 2){
            return true;
        }else if(zav_red>poz_red && poz_stu1<zav_stu1 && zav_red-poz_red == 1 && zav_stu1-poz_stu1 == 2){
            return true;
        }else if(zav_red>poz_red && poz_stu1<zav_stu1 && zav_red-poz_red == 2 && zav_stu1-poz_stu1 == 1){
            return true;
        }else {
            return false;
        }
    }
    if (pocetna_figura[1] == 'B'){
        int raz_red = abs(poz_red-zav_red);
        int raz_stu = abs(poz_stu1-zav_stu1);
        if (raz_red == raz_stu){
                return true;
        }
            }
        if (pocetna_figura[1]=='K'){
        int raz_red = abs(poz_red-zav_red);
        int raz_stu = abs(poz_stu1-zav_stu1);
        if (raz_red <= 1 && raz_stu <= 1){
                return true;
            }
        }else if (pocetna_figura[1]== 'P') {

        if (pocetna_figura[0]== 'W' && poz_red ==6 && abs(poz_red-zav_red) == 2 ){
                return true;
        }else if (pocetna_figura[0]== 'B' && poz_red == 1 && abs(poz_red-zav_red) == 2){
                return true;
        }else if (poz_stu1-zav_stu1!= 0 ){
            if (zavrsna_figura[0]!= pocetna_figura[0]){
              if (zavrsna_figura[0] != ' '){return true;}
            }else{
                return true;
            }

            }
        else if (abs(poz_red-zav_red) == 1){
            return true;
        }else {
            return false;
        }
return false;
}}
int main(){

    PocetnaPloca();
    int potez = 1;
int potez4 = 0;
    while (igra_traje) {
        if (potez4 == 0){
                cout<<endl<<"Bijeli je na potezu"<<endl;
                while (true){
                    cout<<"Unesi pocetnu poziciju figure koje zelis pomaknuti(malim slovom i brojem): ";
                    string pocetna_poz;
                    cin>>pocetna_poz;
                    cout<<"Unesi zavrsnu poziciju figure koje zelis pomaknuti(malim slovom i brojem): ";
                    string zavrsna_poz;
                    cin>>zavrsna_poz;
                    potez2 = 'W';
                    if (IzvanGranica(pocetna_poz,zavrsna_poz) &&  preskakanje(pocetna_poz,zavrsna_poz) && LegalniPotez(pocetna_poz,zavrsna_poz)){
                        system("cls");
                        MicanjeFigura(pocetna_poz,zavrsna_poz);
                        ploca();
                        potez4 = 1;
                        break;
                    }else{
                        system("cls");
                        ploca();
                        cout<<endl<< "Nedozvoljen potez"<<endl;;
                    }

                }

            }else {
                cout<<endl<<"Crni je na potezu"<<endl;
                while (true){
                    cout<<"Unesi pocetnu poziciju figure koje zelis pomaknuti(malim slovom i brojem): ";
                    string pocetna_poz;
                    cin>>pocetna_poz;
                    cout<<"Unesi zavrsnu poziciju figure koje zelis pomaknuti(malim slovom i brojem): ";
                    string zavrsna_poz;
                    cin>>zavrsna_poz;
                    potez2 = 'B';
                    if (IzvanGranica(pocetna_poz,zavrsna_poz) &&  preskakanje(pocetna_poz,zavrsna_poz) && LegalniPotez(pocetna_poz,zavrsna_poz)){
                        system("cls");
                        MicanjeFigura(pocetna_poz,zavrsna_poz);
                        ploca();
                        potez4 = 0;
                        break;
                    }else{
                        system("cls");
                        ploca();
                        cout<<endl<< "Nedozvoljen potez"<<endl;
                    }
            }
        potez++;
    }

}
cout<< "Igra je gotova"<<endl;
return 0;
}
