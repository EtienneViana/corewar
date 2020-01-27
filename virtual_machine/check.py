import sys
import filecmp
import difflib
import subprocess

champ1 = "champs/helltrain.cor"
champ2 = "champs/Bazou.cor"

class ProgressBar:
    def __init__ (self, valmax, maxbar, title):
        if valmax == 0:  valmax = 1
        if maxbar > 200: maxbar = 200
        self.valmax = valmax
        self.maxbar = maxbar
        self.title  = title
    
    def update(self, val):
        if val > self.valmax: val = self.valmax
        perc  = round((float(val) / float(self.valmax)) * 100)
        scale = 100.0 / float(self.maxbar)
        bar   = int(perc / scale)
        out = '\r%s [%s%s] %3d %%' % (self.title, '=' * bar, ' ' * (self.maxbar - bar), perc)
        sys.stdout.write(out)

def set_ouputs(cycle):
    with open("dumps/zaz.txt", 'w') as fzaz: # Pour output la version de zaz
            subprocess.call([".././corewar_zaz", "-d", str(cycle), champ1, champ2], stdout=fzaz)
    with open('dumps/zaz.txt', 'r') as fin: # Pour retirer les lignes de declaration des champions
        data = fin.read().splitlines(True)
    with open('dumps/zaz.txt', 'w') as fout: # Pour retirer les lignes de declaration des champions
        fout.writelines(data[3:])

    with open("dumps/nous.txt", 'w') as fnous: # Pour output notre version
        subprocess.call([".././corewar", "-dump", str(cycle), champ1, champ2], stdout=fnous)

def get_diff():

    file1 = open("dumps/zaz.txt", 'r')
    file2 = open("dumps/nous.txt", 'r')

    filecmp.clear_cache()
    if filecmp.cmp("dumps/zaz.txt", "dumps/nous.txt", False) == False:
        text1 = file1.readlines()
        text2 = file2.readlines()
        for line in difflib.unified_diff(text1, text2):
            print(line)
        file1.close()
        file2.close()
        return 1

    file1.close()
    file2.close()
    return 0

if __name__ == "__main__":

    if len(sys.argv[1:]) < 1 or len(sys.argv[1:]) > 2:
        print("Usage 1 : python check.py [start] [end]\nstart et end sont des entiers correspondant aux cycles a tester\n")
        print("Usage 2 : python check.py [cycle]\npour checker a un cycle precis s'il y a une diff")
        exit(0)

    if len(sys.argv[1:]) == 1:
        cycle = int(sys.argv[1])
        set_ouputs(cycle)
        get_diff()
        exit(0)
    elif len(sys.argv[1:]) == 2: 
        start = int(sys.argv[1]) 
        end = int(sys.argv[2])
        Bar = ProgressBar(100, 60, 'Checking : ')
        for i in range(start, end + 1):
            Bar.update(round(((start + i) / (end + 1 - start)) * 100) + 1)
            set_ouputs(i)
            if get_diff():
                print("\033[93m----- LA DIFFERENCE SE TROUVE AU CYCLE {} -----".format(i))
                exit(0)
        print("\033[92m\n✓✓✓ Tout est OK")
