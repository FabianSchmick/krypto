/*krypto.c*/
/*
Projekt: krypto
*/
/*
History:
	FS 19.03.2014 erstellt
	FS 22.03.2014 weiter gearbeitet an Aufgabenteil 2
	FS 09.04.2014 verfeinerrungen
	FS 10.04.2014 Aufgabenteil 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void);

int main(void)
{
    /*
    Variablen deklarationen
    */

    int iEin;                   //Eingabe Variable
    int iZ;                     //Zähl Variable
    int iPos;                   //Positions Variable
    int iSchl;                  //Schlüssel Variable
    unsigned char ucEnt[255];   //Entschlüsselter Text
    unsigned char ucVer[255];   //Verschlüsselter Text
    FILE *pfDatei;              //Dateizeiger



    do
    {
        /*
        Nun folgt das Menü
        */

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 );
        printf("================================================================================\n");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 );                                                                                                               //Ändern der Farbe
        printf("1.  Druecken Sie die Taste 1, um das Lesen eines unverschluesselten Textes \n    aus einer Datei und anschliessenden Verschluesseln zu beginnen \n");                //Erste Auswahl

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 );
        printf("________________________________________________________________________________\n");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 );
        printf("2.  Druecken Sie die Taste 2, um das Lesen eines verschluesselten Textes \n    aus einer Datei und Ausgabe einens unverschluesselten Textes zu beginnen \n");        //Zweite Auswahl

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 );
        printf("________________________________________________________________________________\n");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 );
        printf("3.  Druecken Sie die Taste 3, um das Lesen eines Textes von der Tastatur und \n    anschliessenden verschluesselten und speichern in einer Datei zu beginnen \n");   //Dritte Auswahl

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 );
        printf("________________________________________________________________________________\n");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12 );
        printf("4.  Druecken Sie die Taste 4, um zu beenden \n");            //Beenden

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 );
        printf("\n================================================================================\n");


        fflush(stdin);                                                       //Tastaturpuffer leeren
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 );
        printf("\nGeben Sie jetzt ihre Wahl ein: ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 );
        scanf("%d", &iEin);                                                  //Einlesen der auszuführenden Aktion
        printf("\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 );



        /*
        Jetzt kommen die Menüpunkte je nach vorheriger gewünschter Auswahl
        */



        /*
        Die erste Mögichkeit, Lesen eines unverschlüsselten Textes aus einer Datei und anschliessenden Verschlüsseln
        */

        if (iEin == 1)                                      //Die erste Möglichkeit des Menüs
        {
            pfDatei = fopen("Text1.txt","rt");              //Öffnen der Datei


            if (pfDatei != NULL)
            {
                fseek(pfDatei, 0, SEEK_END);                //Setzt den Dateizeiger auf das Ende von pfDatei, um die Länge des Textes zu erfahren
                iPos = ftell(pfDatei);                      //Sagt die aktuelle Position von pfDatei
                rewind(pfDatei);                            //Zurück zum Anfang von pfDatei


                printf("In der Datei steht folgender Text: ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 );

                for (iZ = 0; iZ < iPos; iZ = iZ +1)
                {
                    ucEnt[iZ] = fgetc(pfDatei);             //Ausgabe eines Buchstaben aus pfDatei
                    printf("%c", ucEnt[iZ]);
                }

                printf("\n\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 );

                fclose(pfDatei);




                pfDatei = fopen("Text1.txt","wt");                                      //Erneutes Öffnen von pfDatei um die Verschlüsselung ins Programm zu schreiben

                printf("\nGeben Sie nun den Schluessel zum Verschluesseln ein: ");      //Eingabe des Schluüssel
                fflush(stdin);                                                          //Tastaturpuffer leeren
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 );
                scanf("%d", &iSchl);                                                    //Einlesen des Schlüssels

                printf("\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 );


                for (iZ = 0; iZ < iPos; iZ = iZ +1)                 //Verschlüsselung
                {
                    ucVer[iZ] = ucEnt[iZ] + iSchl;                  //Der Schlüssel verschiebt das Alphabet um den eingegeben Schlüssel
                }


                printf("Der Verschluesselte Text lautet jetzt: ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 );


                for (iZ = 0; iZ < iPos; iZ = iZ +1)
                {
                    fputc(ucVer[iZ], pfDatei);                    //Speichern in pfDatei
                    printf("%c", ucVer[iZ]);                      //Verschlüsselte Ausgabe auf dem Monitor
                }


                printf("\n\n\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 );

                fclose(pfDatei);                                 //Schließen von pfDatei
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12 );
                printf("Datei ist nicht vorhanden oder ein anderer Fehler ist aufgetreten!!\n");
                printf("Tipp: Erstellen Sie eine Textdatei namens Text1.txt im Programmordner\n\n\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 );
            }




        /*
        Die zweite Möglichkeit, Lesen eines unverschlüsselten Textes aus einer Datei und anschließenden Entschlüsseln
        */

        }
        else if (iEin == 2)                                 //Die zweite Möglichkeit des Menüs
        {
            pfDatei = fopen("Text1.txt","rt");              //Öffnen der Datei


            if (pfDatei != NULL)
            {
                fseek(pfDatei, 0, SEEK_END);                //Setzt den Dateizeiger auf das Ende von pfDatei, um die Länge des Textes zu erfahren
                iPos = ftell(pfDatei);                      //Sagt die aktuelle Position von pfDatei
                rewind(pfDatei);                            //Zurück zum Anfang von pfDatei


                printf("In der Datei steht folgender Text: ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 );


                for (iZ = 0; iZ < iPos; iZ = iZ +1)
                {
                    ucVer[iZ] = fgetc(pfDatei);             //Ausgabe eines Buchstaben aus pfDatei
                    printf("%c", ucVer[iZ]);
                }


                printf("\n\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 );


                fclose(pfDatei);




                printf("\nGeben Sie nun den Schluessel zum Entschluesseln ein: ");      //Eingabe des Schluüssel
                fflush(stdin);                                                          //Tastaturpuffer leeren
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 );
                scanf("%d", &iSchl);                                                    //Einlesen des Schlüssels
                printf("\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 );


                for (iZ = 0; iZ < iPos; iZ = iZ +1)                 //Entschlüsselung
                {
                    ucEnt[iZ] = ucVer[iZ] - iSchl;                  //Der Schlüssel verschiebt das Alphabet um den eingegeben Schlüssel
                }


                printf("Der Entschluesselte Text lautet jetzt: ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 );


                for (iZ = 0; iZ < iPos; iZ = iZ +1)
                {
                    printf("%c", ucEnt[iZ]);                      //Entschlüsselte Ausgabe auf dem Monitor
                }


                printf("\n\n\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 );


            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12 );
                printf("Datei ist nicht vorhanden oder ein anderer Fehler ist aufgetreten!\n");
                printf("Tipp: Erstellen Sie eine Textdatei namens Text1.txt im Programmordner\n\n\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 );
            }




        /*
        Die dritte Möglichekit, lesen eines Textes von der Tastatur und anschließenden verschlüsseln und speicher in einer Datei
        */

        }
        else if (iEin == 3)                                 //Die dritte Möglichkeit des Menüs
        {
            pfDatei = fopen("Text1.txt","wt");              //Öffnen von pfDatei um die Entschlüsselung ins Programm zu schreiben


            if (pfDatei != NULL)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 );
                printf("Geben Sie Ihren Satz zum Verschluesseln ein: ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 );
                fflush(stdin);                              //Tastaturpuffer leeren

                iZ = -1;

                do                                          //Einlesen des Textes von der Tastatur
                {
                    iZ = iZ +1;
                    ucEnt[iZ] = getchar();
                }while(ucEnt[iZ]!= 10);                     //Bis kein Return kommt



                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 );
                printf("\n\nGeben Sie nun den Schluessel zum Verschluesseln ein: ");    //Eingabe des Schluüssel
                fflush(stdin);                                                          //Tastaturpuffer leeren
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 );
                scanf("%d", &iSchl);                                                    //Einlesen des Schlüssels

                printf("\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 );

                iPos = iZ;           //Länge des Textes


                for (iZ = 0; iZ < iPos; iZ = iZ +1)
                {
                    ucVer[iZ] = ucEnt[iZ] + iSchl;
                }

                printf("Der Verschluesselte Text lautet jetzt: ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 );


                for (iZ = 0; iZ < iPos; iZ = iZ +1)
                {
                    fputc(ucVer[iZ], pfDatei);                    //Speichern in pfDatei
                    printf("%c", ucVer[iZ]);                      //Verschlüsselte Ausgabe auf dem Monitor
                }


                printf("\n\n\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 );

                fclose(pfDatei);
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12 );
                printf("Datei ist nicht vorhanden oder ein anderer Fehler ist aufgetreten!\n");
                printf("Tipp: Erstellen Sie eine Textdatei namens Text1.txt im Programmordner\n\n\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 );
            }
        }




        /*
        Die vierte Möglichkeit, beenden
        */

        else if (iEin == 4)                                 //Zum Beenden des Programmes (vierte Möglichkeit)
        {
            return 0;
        }
        else                                                //Wenn keine Auswahl getätigt wurde
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12 );
            printf("Keine eindeutige Zahl zur Auswahl eingegeben\n\n\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 );
        }

    }while (iEin != 5);


    return 0;
}
