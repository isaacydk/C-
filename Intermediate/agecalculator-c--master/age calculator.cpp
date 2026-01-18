#include<iostream>
#include<ctime>
using namespace std;

int totaldays(int y , int m , int d)
{
    time_t now = time(0);
    
    
    tm *ltm = localtime(&now);
    
     
    int currentyear = 1900 + ltm->tm_year;
    int sum=0;

//day between the year afet you born and the current year

    for (int i = y+1 ; i<currentyear ; i++)
    {
       sum += 365;

    }

//leap year caclulator
int leap=0;
for (int i=y ; i<currentyear ; i++)
{
    if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
    {
        leap += 1;
    }

}

//for one-forth of the year.
int oneforth =0;
for (int i=y ; i< currentyear ; i++)
{
    if ((i % 4 == 0 && i % 100 != 0 || i % 400 == 0))
    {
        oneforth += 0;

    }
    else 
    {
        oneforth += 6 ;
    }
}

int hdays = oneforth / 24;
int leftover0 = oneforth % 24;




//days between the next month you born and final month of that year
    int sum1=0;
    for (int i=m+1 ; i <= 12 ; i++)
    {
        
        if (i<12) {
           sum1 += 30; }
        else {
            sum1 += 35;
        }

    }
//days between the next day and the final day in the month you are born in
    int sum2=0;
    for (int i = d+1 ; i<=30 ;i++)
    {
       sum2 += 1 ; 
    }

    int today = ltm->tm_mday;
    int thismonth = ltm->tm_mon + 1;
//days in the current month up to yesterday
    int sum3 =0; 
    for (int i =1 ; i < today ; i++)
    {
        sum3 +=1;
    }
//days in this year without this month
    int sum4 =0;
    for (int i = 1 ; i<thismonth ; i++)
    {
      sum4 += 30; 
    }
      
    int totalday = sum + sum1 + sum2 + sum3 + sum4 + leap + hdays;


    int totalyears = totalday / 365 ;
    int totalmonths= totalday / 30 ;
    int totalweeks = totalday / 7;

cout<<"----------------------------------------------------"<<endl<<endl;
    cout<<"total full years lived: "<<totalyears<<endl;
    cout<<"total full months lived: "<<totalmonths<<endl;
    cout<<"total full weeks lived: "<<totalweeks<<endl;
    cout<<"total full day lived: "<<totalday<<endl;
    return totalday;

  
}

int leftover_hours (int yrs )
{
    time_t now = time(0);
    
    
    tm *ltm = localtime(&now);
    
    
    int currentyear = 1900 + ltm->tm_year;
    int oneforth =0;

for (int i=yrs ; i< currentyear ; i++)
{
    if ((i % 4 == 0 && i % 100 != 0 || i % 400 == 0))
    {
        oneforth += 0;

    }
    else 
    {
        oneforth += 6 ;
    }
}

int hdays = oneforth / 24;
int leftover0 = oneforth % 24;

return leftover0;
}



int totaltime (int h , int mi , int s , int ap , int totd , int leftover0)
{
//to change the time of born into sec.
    int hinsec = 3600 * h;
    int mininsec = 60 * mi;
    int totsec = hinsec + mininsec + s;
//the time you spent on the day you are born
int  seconds;
  if (ap == 1)
  {
     seconds = 86400 - totsec;
  }
  else if (ap == 2)
  {
    seconds = 43200 - totsec;
  }
  else
  {
    cout<<"enter 1 or 2 please?";
  }
 
//the time spend on this day

time_t now = time(0);  
tm *ltm = localtime(&now);
 

int nowhinsec = ltm->tm_hour * 3600;
int nowminsec = ltm->tm_min * 60;
int seconds2 = nowhinsec + nowminsec + ltm->tm_sec ;


//turning the full days into seconds

 long fullsec =  totd * 86400 ;

//turning lefthours from half days in a year into seconds

int leftoversec = leftover0 * 3600;


//the total seconds you lived

 long totalseconds = fullsec + seconds2 + seconds + leftoversec;


//the total hour you lived
int totalhours = totalseconds / 3600;
int totalminutes = totalseconds / 60;

cout<<"Total full hours lived: "<<totalhours<<endl;
cout<<"total full minutes lived: "<<totalminutes<<endl;
cout<<"Total full seconds lived: "<<totalseconds<<endl;


int exactyear = totalseconds / 31560000 ;
int leftover = totalseconds % 31560000 ;
int exactmonth = leftover / 2628000;
int leftover1 = leftover % 2628000;
int exactweek= leftover1 / 604800;
int leftover2= leftover1 % 604800;
int exactdays = leftover2 / 86400;
int leftover3 = leftover2 % 86400;
int exacthours = leftover3 / 3600;
int leftover4 = leftover3 % 3600;
int exactminutes = leftover4 / 60;
int exactsecond = leftover4 % 60;

cout<<"----------------------------------------"<<endl;
cout<<"exact year lived: "<<exactyear<<endl;
cout<<"exact month lived: "<<exactmonth<<endl;
cout<<"exact week lived: "<<exactweek<<endl;
cout<<"exact day lived: "<<exactdays<<endl;
cout<<"exact hour lived: "<<exacthours<<endl;
cout<<"exact minutes lived: "<<exactminutes<<endl;
cout<<"exact secounds lived: "<<exactsecond<<endl;







  return 0;
}

bool isLeapYear(int year) {
    int i;
    return ( (i % 4 == 0 && i % 100 != 0) || (i % 400 == 0));
}

int main()
{

    int year , month,  day , hour , min , sec , midday ;

    time_t now = time(0);
    tm *ltm = localtime(&now);
    int currentyear = 1900 + ltm->tm_year;

    cout<<"AGE CALCULATOR"<<endl;
    do{
       cout<<"Enter the year you are born : ";
       cin>>year;
       if (year <= 0 || year > currentyear  )
        {
           cout<<"INVAlID INPUT ,please  enter less or equal to 2025 ?"<<endl;
        }
    }while (year <= 0 || year > currentyear );

   
  
   int daysInMonth;
   while (true) {
    cout << "Enter the month you ar born (1-12): ";
    cin >> month;
    
    if (month < 1 || month > 12) {
        cout << "Invalid month! Please enter a value between 1 and 12.\n";
        continue;
    }
    
    if (month == 2) {
        daysInMonth = (isLeapYear(year) ? 29 : 28);
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    } else {
        daysInMonth = 31;
    }
    
    while (true) {
        cout << "Enter day (1-" << daysInMonth << "): ";
        cin >> day;
        
        if (day >= 1 && day <= daysInMonth) {
            break;
        } else {
            cout << "Invalid day! Please enter a valid day for this month.\n";
        }
    }
    
    break;
}





   do{
    cout<<"Enter the hour you are born: ";
    cin>>hour;
    if (hour <= 0 || hour > 12)
    {
        cout<<"INVALID input , please enter in 12 hours format"<<endl;
    }
    } while(hour <= 0 || hour > 12);

   do{
    cout<<"Enter the minute you are born : ";
    cin>>min;
    if (min<0 || min>=60)
    {
        cout<<"INVALID INPUT , please enter between 0 and 59"<<endl;
    }
    }while(min<0 || min>=60);

    do{
    cout<<"Enter the second you are born: ";
    cin>>sec;
    if ( sec<0 || sec>=60)
    {
        cout<<"INVALID INPUT , please enter between 0 and 59"<<endl;
    }
     }while(sec<0 || sec>=60);

     do{
    cout<<"Enter '1'- for AM and '2' - or PM : ";
    cin>>midday;
    if (midday < 1 || midday > 2)
        {
           cout<<"INVALID INPUT , please enter 1 and 2"<<endl;
        }
     }while (midday < 1 || midday > 2);

    
    int leftoverhours = leftover_hours(year);
    int totalday = totaldays(year , month, day);
    totaltime(hour , min, sec , midday , totalday , leftoverhours);

    

}


