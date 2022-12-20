#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void clear()
{
    char clean[10];
    strcpy(clean, "cls");
    system(clean);
}


typedef struct a
{
    char country[100];
    float currency_rate;
}data;

char *black()
{
    return "0";
}

char *blue()
{
    return "1";
}

char *green()
{
    return "2";
}

char *aqua()
{
    return "3";
}

char *red()
{
    return "4";
}

char *purple()
{
    return "5";
}

char *yellow()
{
    return "6";
}

char *white()
{
    return "7";
}

char *gray()
{
    return "8";
}

char *light_blue()
{
    return "9";
}

char *light_green()
{
    return "a";
}

char *light_aqua()
{
    return "b";
}

char *light_red()
{
    return "c";
}

char *light_purple()
{
    return "d";
}

char *light_yellow()
{
    return "e";
}

char *bright_white()
{
    return "f";
}

char change_color(char fg[], char bg[])
{
    char foreground[2];
    char background[2];
    char combined[10];
    strcpy(combined, "color ");
    strcpy(foreground, fg);
    strcpy(background, bg);
    strcat(background, foreground);
    strcat(combined, background);
    system(combined);
}

void frontpage()
{
    change_color(blue(), bright_white());
    printf("############################################################\n\n");
    printf("          Mini C project -> currency converter              \n\n");
    printf("          By: C Ujwal             (PES2UG21CS131)           \n");
    printf("              Rasagnya Choppa     (PES2UG21CS148)           \n");
    printf("              Chava Govardhan Rao (PES2UG21CS141)           \n\n");
    printf("############################################################\n\n");
    printf("Press Enter to Continue ");getchar();
    clear();

}

void loading_page()
{
    change_color(red(), light_yellow());
    printf("############################################################\n\n\n");
    printf("                  Loading..........                         \n\n\n");
    printf("############################################################");
}

void mainmenu()
{
    change_color(light_aqua(), black());
    printf("############################################################\n\n");
    printf("1. Currency Converter\n");
    printf("2. Current currency Rates\n\n");
    printf("############################################################");
}

int choice()
{
    int a;
    printf("\n\nEnter your choice: ");
    scanf("%d", &a);
    return a;
}

void print(data *a, int b)
{
    change_color(green(), bright_white());
    printf("#############################################################\n\n");
    printf("Considering USD as 1, we have currency rates as: \n\n");
    for (int i=0; i<b; i++)
    {
        printf("%d. %s -> %.2f\n", i+1, a[i].country, a[i].currency_rate);
    }
    printf("\n\n#############################################################\n\n");
    printf("1. Go to main menu\n\n");
    printf("Enter any other number to EXIT.");
}

void print1(data *a, int b)
{
    int r=1;
    change_color(bright_white(), purple());
    printf("#############################################################################\n\n");
    printf("1. United States Dollars   ");
    for (int i=0; i<b; i++)
    {
        if (r==3)
        {
            printf("\n\n");
            r=0;
            printf("%d. %s   ", i+2, a[i].country);
            r++;
        }
        else
        {
            printf("%d. %s   ", i+2, a[i].country);
            r++;
        }
    }
    printf("\n\n#############################################################################\n\n");
}

int main()
{
    clear();
    frontpage();
    char python[100];
    int flag=0;
    int flag1=0;
    int flag2=0;
    int flag3=0;
    int opinion;
    while (flag!=1)
    {
        while(flag1!=1)
        {
            clear();
            loading_page();
            strcpy(python, "python currency_converter.py");
            system(python);
            FILE *ptr=fopen("countries.txt","r");
            char ch;
            int count=0;
            ch=fgetc(ptr);
            while(ch!=EOF)
            {
                if (ch=='\n')
                count++;
                ch=fgetc(ptr);
            }
            data current[count-1];
            rewind(ptr);
            ch=fgetc(ptr);
            int i=0, j=0;
            char temporary[100], refernce[100];
            while(ch!=EOF)
            {                         
                if(ch=='\n')
                {
                    strcpy(current[i].country, temporary);
                    i++;
                    j=0;
                    strcpy(temporary, refernce);
                    ch=fgetc(ptr);
                }
                else
                {
                    temporary[j]=ch;
                    ch=fgetc(ptr);
                    j++;
                    if(ch=='\n')
                    temporary[j]='\0';
                }
            }
            i=0;
            j=0;
            fclose(ptr);
            FILE *ptr1=fopen("rates.txt", "r");
            char tempo_rate[50];
            ch=fgetc(ptr1);
            while(ch!=EOF)
            {
                if(ch=='\n')
                {
                    current[i].currency_rate=atof(tempo_rate);
                    i++;
                    j=0;
                    strcpy(tempo_rate, refernce);
                    ch=fgetc(ptr1);
                }
                else
                {
                    tempo_rate[j]=ch;
                    j++;
                    ch=fgetc(ptr1);
                    if(ch=='\n')
                    tempo_rate[j]='\0';
                }
            }
            fclose(ptr1);
            flag1=1;
            clear();
            if(flag3==1)
            {
                print(current, count);
                opinion=choice();
                if (opinion==1)
                {
                    flag2=0;
                    flag3=1;
                    clear();
                }
                else
                {
                    flag=1;
                    flag2=1;
                    clear();
                }
            }
            while(flag2!=1)
            {
                mainmenu();
                opinion=choice();
                if (opinion==1)
                {
                    int flag4=0;
                    clear();
                    while (flag4 != 1)
                    {
                        print1(current, count);
                        printf("Enter the currency sl no. you wanna convert from: ");
                        int opinion1, opinion2;
                        scanf("%d", &opinion1);
                        printf("Enter the currency sl no. you wanna convert to: ");
                        scanf("%d", &opinion2);
                        if (opinion1<count+2 && opinion2<count+2 && opinion1>0 && opinion2>0)
                        {
                            if (opinion1!=1 && opinion2!=1)
                            printf("\n\nChosen Currency conversion: %s -> %s \n\n To confirm enter 1 or press any other number to retry.", current[opinion1-2].country, current[opinion2-2].country);
                            else if(opinion1!=1)
                            printf("\n\nChosen Currency conversion: %s -> USD \n\n To confirm enter 1 or press any other number to retry.", current[opinion1-2].country);
                            else if(opinion2!=1)
                            printf("\n\nChosen Currency conversion: USD -> %s \n\n To confirm enter 1 or press any other number to retry.", current[opinion2-2].country);
                            else
                            printf("\n\nChosen Currency conversion: USD -> USD \n\n To confirm enter 1 or press any other number to retry.");
                            opinion=choice();
                            if (opinion==1)
                            {
                                clear();
                                change_color(black(), bright_white());
                                float value;
                                if (opinion1==1)
                                {
                                    printf("\n\n Enter the value of USD: ");
                                    scanf("%f", &value);
                                    if (opinion2 == 1)
                                    printf("\n\nThe Value in USD is %.2f", value);
                                    else
                                    {
                                        printf("\n\nThe value in %s is %.2f", current[opinion2-2].country, current[opinion2-2].currency_rate*value);
                                    }
                                }
                                else
                                {
                                    printf("\n\n Enter the value of %s: ", current[opinion1-2].country);
                                    scanf("%f", &value);
                                    if (opinion2==1)
                                    {
                                        printf("\n\n The Value in USD is %.2f", (1/current[opinion1-2].currency_rate)*value);
                                    }
                                    else
                                    {
                                        printf("\n\n The value in %s is %.2f", current[opinion2-2].country, (current[opinion2-2].currency_rate/current[opinion1-2].currency_rate)*value);
                                    }
                                }
                                printf("\n\nPress 1 to go to main menu\nPress 2 to go to currency converetr\nAny other number to EXIT.");
                                opinion=choice();
                                if (opinion==1)
                                {
                                    flag4=1;
                                    flag2=0;
                                    clear();
                                }
                                else if (opinion==2)
                                {
                                    flag4=0;
                                    clear();
                                }
                                else
                                {
                                    flag=1;
                                    flag1=1;
                                    flag2=1;
                                    flag3=0;
                                    flag4=1;
                                }
                            }
                            else
                            {
                                clear();
                                flag4=0;
                            }
                        }
                        else
                        {
                            clear();
                            printf("\n\n ERROR: INVALID CHOICE | TRY AGAIN \n\n");
                            flag4=0;
                        }
                    }
                }
                else if(opinion==2)
                {
                    flag3=1;
                    flag2=1;
                    flag1=0;
                }
                else
                {
                    clear();
                    printf("\n\n ERROR: INVALID CHOICE | TRY AGAIN \n\n");
                    flag2=0;
                }
            }
        }
    }
    clear();
    return 0;
}