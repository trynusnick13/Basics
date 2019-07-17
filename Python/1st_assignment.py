def average(*args,s=0,k=0):
    for i in args:
        s+=i
        k+=1
    return s/k
positive_vibes=False #due to early wake up(alarm is set at 6 a.m.)
j=0
stats=['Points', 'Assists']
stats1=['Points', 'Assists']
stats2=['Points', 'Assists']
players = {'name': {'Kemba': stats1, 'Irving': stats2}}
while j<len(players['name']['Kemba']):
    players['name']['Kemba'][j]=int(input(f'Enter amount of Kemba\'s {stats1[j]} : '))
    j += 1

for j in range(len(players['name']['Irving'])):
    players['name']['Irving'][j] = int(input( f'Enter amount of Irving\'s {stats2[j]} : '))

print(average(players['name']['Kemba'][0],players['name']['Irving'][0]))
if players['name']['Kemba'][0]>25 and players['name']['Irving'][0]>25 :
    positive_vibes=True
    print("Great efforts from the outstanding athletes!!!")
elif players['name']['Kemba'][0]>25 or players['name']['Irving'][0]>25:
    positive_vibes = True
    print("Well, at least somebody put up decent numbers")
else :
    print("Get out of the court! I'd played better! Why on earth they get such money??")

while True:
    j=0
    games = 2
    while j < len(players['name']['Kemba']):
        players['name']['Kemba'][j] = int(input(f'Enter amount of Kemba\'s {stats[j]} : '))
        players['name']['Irving'][j] = int(input(f'Enter amount of Irving\'s {stats[j]} : '))
        j += 1
    if average(stats1[0],stats2[0])>=10 and average(stats1[1],stats2[1])>=10:
        print("It took", games,"games to average a double-double for both")
        break

if positive_vibes:
    print("Day is going to be nice")
else :
    print("I hope Python courses will make my day better")
