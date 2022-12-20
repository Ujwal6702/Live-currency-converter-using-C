from bs4 import BeautifulSoup as bs
import requests as rs
source=rs.get('https://www.x-rates.com/table/?from=USD&amount=1')
content=bs(source.content, 'html.parser')
c1=content.find('table', class_='tablesorter ratesTable').tbody
US=1.00
countries=[]
currency_rates=[]
for i in c1.find_all('tr'):
    a=i.td.text
    countries.append(a)
    b=float(i.find('td', class_='rtRates').a.text)
    currency_rates.append(b)
file=open('countries.txt', 'w')
for i in range(len(countries)):
    file.write(countries[i]+'\n')
file.close()
file1=open("rates.txt", "w")
for i in range(len(countries)):
    file1.write(str(currency_rates[i])+'\n')
file1.close()
