from pathlib import Path
from telegram.ext import Updater, CommandHandler, MessageHandler, Filters
import json
import urllib.request

OWNER = '@PayPy'
TOKEN_FILE = 'token.txt'
TOKEN = Path(TOKEN_FILE).read_text().strip()
DATA_URL = 'http://resources.finance.ua/ru/public/currency-cash.json'


def start(update, context):
    """"Command handler for command /start"""
    print('Command /start')
    print("Hi, my master", {OWNER})
    update.message.reply_text("Hi")


def buy_usd(update, context):
    """"
    Message handler buy dollars

    """
    update.message.bot.send_message(
        update.message.chat_id,
        "What do you want, my Lord"
    )
    print("Money is here")
    text = urllib.request.urlopen(DATA_URL).read()
    data = json.loads(text)
    #mport pdb; pdb.set_trace()
    sellers = [o for o in data['organizations']
               if 'USD' in o['currencies']]
    sellers.sort(key=lambda  o: float(o['currencies']['USD']['ask']))
    best = sellers[0]
    update.message.bot.send_message(
        update.message.chat_id,
        f'Best course: {best["currencies"]["USD"]["ask"]}\n'
        f'Where to buy: {best["link"]}')


def main():
    updater = Updater(token=TOKEN, use_context=True)
    dp = updater.dispatcher
    dp.add_handler(CommandHandler('start', start))
    dp.add_handler(MessageHandler(Filters.regex('Buy dollars'),buy_usd))
    updater.start_polling()
    updater.idle()


if __name__ == '__main__':
    main()
