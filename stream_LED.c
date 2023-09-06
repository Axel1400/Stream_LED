#include <stdio.h>
#include <unistd.h>

int main()
{
    FILE *fin = fopen("/dev/urandom", "r");
    FILE *f_led = fopen("/sys/class/leds/gpio-led/brightness", "w+");

    if (fin == NULL || f_led == NULL)
    {
        perror("Error opening file");
        return 1;
    }
    while (1)
    {
        char c =  fgetc(fin);
        if(c>128)
        {
            c = 1 + '0';
        }
        else{
            c=0 + '0';
        }
        fputc(c, f_led);
        printf("%c\n", c + '0');
        fflush(f_led);
        sleep(1);
    }
}