#include<bits/stdc++.h>


using namespace std;

int shiftTable[150],comp=0;

void ShiftTableGeneration(char st[],int n)
{
    for(int i=0;i<130;i++)
    {
        shiftTable[i] = n-1;
    }
    for(int i=n-2,j=1;i>=0;i--,j++)
    {
       if(shiftTable[st[i]]==n-1)
         shiftTable[st[i]] = j;
    }

}

void HorseSpool(char Text[],int n,char Patter[],int m)
{
    ShiftTableGeneration(Patter,m);
    if(n<m)
    {
        cout << endl << "Pattern is not found due to n<m \a\n\n ";
        return;
    }
    int i=m-1,r;
    while(i<n-m)
    {  comp++;
        r=0;
       while(r<m&& Patter[m-1-r]==Text[i-r])
        r++;
       if(r==m)
       {
           cout << "The Pattern found at the position " << i+2-m << endl << endl ;
        return ;
       }else
            i = i+ shiftTable[Text[i]];
    }

    cout <<"The pattern not found int the given text.";
}

 int main()
 {
     char text[10000],Pattern[10000];
     cout << "Write text : " << endl;
     cin.getline(text,10000);
     int n = strlen(text);
     cout << "Write the pattern : ";
     cin.getline(Pattern,10000);
     int m= strlen(Pattern);
     HorseSpool(text,n,Pattern,m);
     cout << "\n \n And the number of comparision is : " << comp << endl ;
     return 0;
 }
