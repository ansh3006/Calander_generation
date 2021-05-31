#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int first_day(int year,int M){   //function for finding first day of(i.e Sunday,Monday etc) month using  Zeller's rule  
     
    int D=year%100;          // M = Month no. ,D = Last two digits of the year, C = The first two digits of year , 
    int C=year/100;          // so for 2021 D=21  C=20 and
    int K=1;                 //according to Zeller calendar For March M=1 ,april M=2 and so on..hence for dec. M=10, Jan M=11, Feb M=12
    int F = K + (13*M - 1)/5 + D + D/4 + C/4 - 2*C;  
   
    
    if(F>=0)
     {
       return(F%7);
      }
    else
     {
        return(((F%7)+7)%7);  //this function will return nos 0-6 such tha for 0 first day of month is sunday, for 1 monday and so on till 6 for Saturday
      }
}

void display_calendar(char month[3], int Ist_day, int days){      //function to display calendar 
    
    printf("\n\n---------------%s-------------------\n",month);
    
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
    
    int weekDay;
    for( weekDay=0;weekDay<Ist_day;weekDay++){       
        printf("     "); }
    for(int day=1;day<=days;day++){
        
        printf("%5d",day);
        

        if(++weekDay>6){
            printf("\n");
            weekDay=0;
        }
        
      }}



int main()                  //Program execution starts from here .
{   system("Color 3E");
    int n,Ist_day;
    static int year;
    char month[3];
    printf("Enter year: ");
    scanf("%d",&year);
    
    printf("\nEnter first three letters of month (eg. for january enter 'jan') ");
    scanf("%s",month);
    char* arr[]={"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};
    for(int i=0;i<12;i++){     
        if (!strcmp(month,arr[i])){
           
            n=i;
            break;
        }
    } 
    switch(n){    
        case(0):                                // for Jan
            Ist_day=first_day(year-1,11);
            display_calendar("January",Ist_day,31);    

            break;
        
        case(1):                            //This is special case as this Feb and it can have 28 or 29 days 
           Ist_day=first_day(year-1,12);
           int days;
           
            if(year%400==0)                 //if else statements for checking leap year 
           {
             days=29;
           }
           else if(year%100==0)
           {
             days=28;
           }
           else if(year%4==0)
           {
             days=29;
           }
           else
           {
             days=28;}

            display_calendar("February",Ist_day,days);

            break;
        
        case(2):
            
            Ist_day=first_day(year,1);
            display_calendar("March",Ist_day,31);
            break;
       
        case(3):
            
            Ist_day=first_day(year,2);
            display_calendar("April",Ist_day,30);
            break;
       
        case(4):
            Ist_day=first_day(year,3);
            display_calendar("May",Ist_day,31);
            break;
       
        case(5):
            Ist_day=first_day(year,4);
            display_calendar("June",Ist_day,30);
            break;
       
        case(6):
            Ist_day=first_day(year,5);
            display_calendar("July",Ist_day,31);
            break;
        
        case(7):
            Ist_day=first_day(year,6);
            display_calendar("August",Ist_day,31);
            break;
        
        case(8):
            Ist_day=first_day(year,7);
            display_calendar("September",Ist_day,30);
            break;
        
        case(9):
            Ist_day=first_day(year,8);
            display_calendar("October",Ist_day,31);
            break;
        
        case(10):
            Ist_day=first_day(year,9);
            display_calendar("Novemver",Ist_day,30);
            break;
        
        case(11):
            Ist_day=first_day(year,10);
            display_calendar("December",Ist_day,31);
            break;

    }
    return 0;
}