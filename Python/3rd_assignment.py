from collections import Counter
import csv
from datetime import datetime
#import dateutil.parser
from pathlib import Path


DATA_FILE = Path("C:/Users/Семья/PycharmProjects/data/crypto/bitcoin.csv")
# перегружен оператор деления Path('..') / 'data'/.../'bitcoin.csv'
with open(DATA_FILE) as f:
    reader = csv.DictReader(f) # обьект для итерации цсв файлов


    data = []

    # read and convert data

    for row in reader:   # ordered dict - отсортированый слова
        #row['Date'] = deteutil.parser.parse(row['Date'])
        row['Date'] = datetime.strptime(row['Date'], "%b %d, %Y") #!!!!!!!!
        for col in ('Open', 'High', 'Low', 'Close', 'Volume', 'Market Cap'):
            row[col] = float(row[col].replace(',', ''))\
                if row[col] != '-' else None

        if row['Open'] < row['Close']:
              row['Color'] = 'Green' # добавили в словарь новый элемент, row - словарь
        elif row['Open'] > row['Close']:
              row['Color']='Red'
        else:
              row['Color'] = None

        data.append(row)   # словари в списке

   # row['Open'] = float(row['open'])
 #data sort
data.sort(key=lambda row: row['Date']) # сортирует по возрастанию даты; лямбда функц сортировки
#data exploration
print(' '.join(str(r['Color'])[0] for r in data))
print(Counter(r['Color']) for r in data)
print((f"Lowest = {min(r['Low'] for r in data)} , "
       f"Highest={max(r['High'] for r in data)}"))

price_daily_avg =  [(r['Low'] + r['High'])/ 2 for r in data]
### avg = [(r['Low'] + r['High'])/ 2 for r in data]
volume_sum = sum(r['Volume'] or 0 for r in data)

price_daily_weight = [(r['Volume'] or 0) / volume_sum for r in data ]
price_total_avg = sum( p*w for p , w in
zip(price_daily_avg, price_daily_weight)) # посмотреть зип как создает картежи и попробовать использовать