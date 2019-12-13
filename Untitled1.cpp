#include<bits/stdc++.h>
#include <windows.h>

using namespace std;




int tt=3600;
int pt=0,wd=0,ft,ck=0;
int wt[1000]={0};

void printer(int tp,int mnt,int n,int tn)
{

    int pp=n/60;
    int pgt=pp*tp;
    int wtt;
    wtt=pt-mnt;
    if(wtt<=0)
    {
        wtt=0;
    }
    pt=mnt+tp+wtt;
    if(pt<tt)
    {
        wd++;
        ft=pgt;
        wt[tn]=wtt;
    }
    else
    {
        ck=1;
    }
}


int main()
{
    cout<<"Enter How many page can print your printer within One munites (PPM) : ";
    int n,rnt[11],rnm[11],rnp[11];
    cin>>n;
    int min=1,max=15,mm=3600,mn=1;
    for(int i=1;i<=10;i++)
    {


        rnt[i] = rand()%(max-min+1) + min;
        rnm[i] = rand()%(mm-mn+1) + mn;
        rnp[i] = rand()%(max-min+1) + min;
        mn=rnm[i];
    }
    for(int i=1;i<=10;i++)
    {


        cout<<rnt[i]<<" "<<rnm[i]<<" "<<rnp[i]<<endl;
    }





    for(int i=n;i>0;i-=3)
    {
        int avg=0,avgts=0,avgt=0,avguts=0,uft=0;
        for(int c=1;c<=10;c++)
        {
            cout<<"Test : "<<c<<endl;

            wd=0;pt=0;ft=0;ck=0;


            wt[rnt[c]]={0};
            for(int j=1;j<=rnt[c];j++)
            {




                printer(rnp[j],rnm[j],i,j);

                if(ck==1)
                {
                    ck=0;

                    break;
                }
                else
                {
                    avg+=wt[j];

                    cout<<"\t \t Test Case "<<j<<" "<<"Input Time "<< rnm[j]<<" Page : "<<rnp[j]<<" "<<" wait time : "<<wt[j]<<endl;
                }
            }
            avgts+=rnt[c];
            avgt+=avg;
            uft=rnt[c]-wd;
            avguts+=uft;



                cout<<"Average for Test   "<<c<<" "<<"Total Tast : "<<rnt[c]<<" "<<" Average Wait time " <<avg/rnt[c]<<" Unfinised Task : "<<rnt[c]-wd<<endl;
        }
        //system("Color 1A");
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE));


        cout<<"\n\nTest for PPM : "<<i <<" "<<"Average  Tast : "<<avgts/10<<" "<<" Average Wait time " <<avgt/10<<" Unfinised Task : "<<avguts/10<<"\n\n";
       SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN));



    }
}
