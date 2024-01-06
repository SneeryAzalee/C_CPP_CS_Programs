#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int x, w_count = 0, d_count = 0, deci_mode = 0;
    double y, whole, decimal;
    
    scanf("%s", str);
    
    for(int i = 0; i < strlen(str); i++)
    {
        if(deci_mode == 0)
        {
            if(str[i] == '.')
            {
                deci_mode = 1;
            }
            else
            {
                w_count++;
            }
        }
        else if(deci_mode == 1)
        {
            d_count++;
        }
    }
    
    sscanf(str, "%lf", &y);
    
    whole = (int)y;
    decimal = y - whole;
    
    int temp = w_count;
    
    while(w_count > 0)
    {
        whole /= 10;
        w_count--;
    }
    
    while(d_count > 0)
    {
        decimal *= 10;
        d_count--;
    }
    
    int final = whole + decimal;
    
    
    printf("\n%.*lf", temp, final);
}