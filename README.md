# **Live currency converter using C**

## Objective

To create a program that uses the live value of the currency exchange rates in the market and gives out the exchange value output based on the input of currency chosen and the value given.

## Problems faced

1. C is an old language, so it did not have a web scraping option.
2. Creating a GUI-based application was hard to accomplish within the given time limit and in our experience.

## Solutions

1. We used python as a supporter code which scrapes the data from the Internet and stores the value in a text file which is later ready by the C program, and the desired output is then further presented.
2. For the GUI part, we just used command line codes to change the color and the way it looks.

## Summary

### Extracting data using beautifulsoup module

```python

source=rs.get('https://www.x-rates.com/table/?from=USD&amount=1')
content=bs(source.content, 'html.parser')

```
### Writing extracted content into a text file

```python

file=open('countries.txt', 'w')
for i in range(len(countries)):
    file.write(countries[i]+'\n')
file.close()
file1=open("rates.txt", "w")
for i in range(len(countries)):
    file1.write(str(currency_rates[i])+'\n')
file1.close()

```

### Running python code using system function and then opening output text file

```C

strcpy(python, "python currency_converter.py");
system(python);
FILE *ptr=fopen("countries.txt","r");

```

### Data Extraction from text file

```C

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

```


### Function to change color of terminal

```C

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

````
