/*
   varargsdemo.c
   Small sample with variable parameter list
   bap 19.07.2017
 */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>


/* Notation der "Ellipse" (= "...") fuer eine variable
   Parameterliste
 */
void Ausgabe(char *, ... );
void DrawLine(char, int);


int main(void)
{
    DrawLine('-',70);
    printf("%-51s   %10s\n","Kontostandsmitteilung","EUR");
    DrawLine('-',70);
    Ausgabe("Konto %k von %s  %f\n",12345,"Krause, Bernd",-2050.50);
    Ausgabe("Konto %k von %s  %f\n",303904951,"Krause, Gabi",12050.37);
    Ausgabe("Konto %k von %s  %f\n",1000302040,"Biersenner, Xaver",-20.25);
    Ausgabe("Konto %k [Kontoinhaber wird nicht gelistet]  %f\n",777,33902.11); 
    DrawLine('-',70);

    return EXIT_SUCCESS;
    
} /* end main */


void Ausgabe(char *spec, ... )
{
    va_list argptr;
    char *s=spec;
    
    va_start(argptr,spec);
    
    /* Hole die Spezifikation: %s fuer eine Zeichenkette,
     *                         %f fuer eine double-Zahl,
     *                         %k fuer eine 10stellige Kontonummer
     */
    while (*s)
    {
        if (*s == '%')
        {
            s++;
            switch(*s)
            {
                case 'f':
                    {
                        double tmp=va_arg(argptr,double);
                        if (tmp < 0)
                            printf(" %10.2f  Soll ",-tmp);
                        else
                            printf(" %10.2f Haben ",tmp);
                        break;
                    }
                case 'k':
                    printf("%10d",va_arg(argptr,long));
                    break;    
                case 's':
                    printf("%-30s",va_arg(argptr,char*));
                    break;
                default:
                    printf("%c",*s);
                    break;
            } /* end switch */
        }
        else
        {
            putchar(*s);
        }
        s++;
    } /* end while *s */

    /* Aufraeumen */
    va_end(argptr);
    
} /* end Ausgabe */


void DrawLine(char c, int anzahl)
{
    int i;
    for (i=0; i<anzahl; i++)
        putchar(c);
    putchar('\n');        
    
} /* end DrawLine */

/* end of file varargsdemo.c */

