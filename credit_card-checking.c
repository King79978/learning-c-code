#include<stdio.h>
#include<cs50.h>
#include<math.h>
string get_card_type(long n);
bool luhn_check(long n);
int main()
{
    long card_number;
    do
    {
        card_number=get_long("Numbers:");
    }
    while(card_number<0);
    string check =get_card_type(card_number);
    if(check!=NULL&&luhn_check(card_number))
    {
        printf("%s\n",check);
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}
string get_card_type(long n)
{
   long number=n;
   long start;
   int length=0;
   while(number>0)
   {
    number/=10;
    length++;
   }
    start=n/(long)pow(10, length - 2);

   if(length==15&&(start==34||start==37))
   {
    return "AMEX";
   }
   else if(length==16&&(start==51||start==52||start==53||start==54||start==55))
   {
    return "MASTERCARD";
   }
   else if((length==13||length==16)&&start/10==4)
   {
    return "VISA";
   }
   return NULL;
}
bool luhn_check(long n)
{
    int sum = 0;
    for (int i = 0; n > 0; i++, n /= 10)
    {
        int digit = n % 10;
        if (i % 2 == 1)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9;
            }
        }
        sum += digit;
    }
    return sum % 10 == 0;
}
