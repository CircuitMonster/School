# tictactoe.py
# by Kerstin Voigt, Feb 2012

import random

class T3():
    def __init__(self):
        self.ttt = {'a': 0, 'b': 0, 'c':0, 'd': 0,'e': 0, 'f':0,
               'g': 0, 'h': 0, 'i': 0}
        self.row1 = ['a','b','c']
        self.row2 = ['d','e','f']
        self.row3 = ['g','h','i']
        self.col1 = ['a','d','g']
        self.col2 = ['b','e','h']
        self.col3 = ['c','f','i']
        self.dia1 = ['a','e','i']
        self.dia2 = ['c','e','g']

    def reset(self):
        self.ttt = {'a': 0, 'b': 0, 'c':0, 'd': 0,'e': 0, 'f':0,
               'g': 0, 'h': 0, 'i': 0}

    # row, col, or diag values
    def rcd_values(self,rcd):
        return [self.ttt[x] for x in rcd]

    def __str__(self):
        return " %s %s %s" % (self.rcd_values(self.row1),
                                   self.rcd_values(self.row2),
                                   self.rcd_values(self.row3))
    # a way to display the board
    def present(self):
        self.present_row(self.row1)
        self.present_row(self.row2)
        self.present_row(self.row3)
        print("\n")


    def present_row(self,row):
        for i in range(3):
            if self.ttt[row[i]] == 0:
                if i < 2:
                    print(row[i]),
                else:
                    print(row[i])
            else:
                if i < 2:
                    print(self.ttt[row[i]]),
                else:
                    print(self.ttt[row[i]])
        

    # prompt for and put X
    def put_X(self):
        self.present()
        while(True):
            pick = raw_input('Choose place for X: ')
            if self.ttt[pick] == 0:
                self.ttt[pick] = 'X'
                break
            else:
                print "Can't do; choose again:"

    # place a random O (the games current response)
    def random_O(self):
        self.present()
        print "Playing an @ ..."
        ko= self.two_in_any('@')
        if ko:
            self.ttt[ko] = '@'  # to win
        else:
            kx = self.two_in_any('X')
            #print "kx: %s" % kx
            if kx:
                self.ttt[kx] = '@' # to block
            else:
                rest=[]
                for k in self.ttt.keys():
                    if self.ttt[k] == 0:
                        rest.append(k)
                pick = random.choice(rest)
                self.ttt[pick] = '@'

    # True if there is a full row of symbol 'symb'    
    def full_row(self,symb):
        rs = list(3*symb)
        return rs==self.rcd_values(self.row1) or\
               rs==self.rcd_values(self.row2) or\
               rs==self.rcd_values(self.row3)

    # True if there is a full col of symbol 'symb'
    def full_col(self,symb):
        rs = list(3*symb)
        return rs==self.rcd_values(self.col1) or\
               rs==self.rcd_values(self.col2) or\
               rs==self.rcd_values(self.col3)

    # True if there is a full diag of symbol 'symb'
    def full_diag(self,symb):
        rs = list(3*symb)
        return rs==self.rcd_values(self.dia1) or\
               rs==self.rcd_values(self.dia2)

    # True if X wins
    def winX(self):
        return self.full_row('X') or\
               self.full_col('X') or\
               self.full_diag('X')

    # True if O wins
    def winO(self):
        return self.full_row('@') or\
               self.full_col('@') or\
               self.full_diag('@')

    # full board;
    def full(self):
        return not 0 in self.rcd_values(self.row1) and\
               not 0 in self.rcd_values(self.row2) and\
               not 0 in self.rcd_values(self.row3)


    # returns key of any row, col, diag with
    # two symbols where key needs to be blocked/set with @
    # returns False if no two symbols in any row,col,diag
    
    def two_in_any(self,symb):
        r1 = self.two_in_row1(symb)
        r2 = self.two_in_row2(symb)
        r3 = self.two_in_row3(symb)
        c1 = self.two_in_col1(symb)
        c2 = self.two_in_col2(symb)
        c3 = self.two_in_col3(symb)
        d1 = self.two_in_dia1(symb)
        d2 = self.two_in_dia2(symb)
        all = [r1,r2,r3,c1,c2,c3,d1,d2]
        while False in all:
            all.remove(False)
            #print"all: %s" % all
        if all == []:
            return False
        return random.choice(all)
        
    # finds row with two symbs; returns key to block with opposite symbol
    def two_in_row1(self, symb):
        vals = self.rcd_values(self.row1)
        if (vals.count(symb) == 2):
            for k in self.row1:
                if self.ttt[k] == 0:
                    return k
            return False
        else:
            return False

    def two_in_row2(self, symb):
        vals = self.rcd_values(self.row2)
        if (vals.count(symb) == 2):
            for k in self.row2:
                if self.ttt[k] == 0:
                    return k
            return False
        else:
            return False
        
    def two_in_row3(self, symb):
        vals = self.rcd_values(self.row3)
        if (vals.count(symb) == 2):
            for k in self.row3:
                if self.ttt[k] == 0:
                    return k
            return False
        else:
            return False

    def two_in_col1(self, symb):
        vals = self.rcd_values(self.col1)
        if (vals.count(symb) == 2):
            for k in self.col1:
                if self.ttt[k] == 0:
                    return k
            return False
        else:
            return False
                
    def two_in_col2(self, symb):
        vals = self.rcd_values(self.col2)
        if (vals.count(symb) == 2):
            for k in self.col2:
                if self.ttt[k] == 0:
                    return k
            return False
        else:
            return False            

    def two_in_col3(self, symb):
        vals = self.rcd_values(self.col3)
        if (vals.count(symb) == 2):
            for k in self.col3:
                if self.ttt[k] == 0:
                    return k
            return False
        else:
            return False
                
    def two_in_dia1(self, symb):
        vals = self.rcd_values(self.dia1)
        if (vals.count(symb) == 2):
            for k in self.dia1:
                if self.ttt[k] == 0:
                    return k
            return False
        else:
            return False
                
    def two_in_dia2(self, symb):
        vals = self.rcd_values(self.dia2)
        if (vals.count(symb) == 2):
            for k in self.dia2:
                if self.ttt[k] == 0:
                    return k
            return False
        else:
            return False


    # the game loop
    def play(self):
        self.reset()
        print "\n\n"
        print "Starting a new game of tictactoe. X begins ...\n"
        while True:
            self.put_X()
            if self.winX():
                self.present()
                print "X, you win  :-))\n\n"
                break
            if self.full():
                self.present()
                print "It is a tie :-|\n\n"
                break
            
            self.random_O()
            if self.winO():
                self.present()
                print "O wins, you loose  :-((\n\n"
                break
            if self.full():
                self.present()
                print "Its a tie :-|\n\n"
                break

            
# global; set up for testing

#game=T3()
#game.put_X()
#game.put_X()
#game.put_X()
#game.put_X()
    

    
            

            

    
               
   
                                   
