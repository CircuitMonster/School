# puzzle8.py

from graphics import *

win = GraphWin("Puzzle", 600, 600)


# starting state from Nils Nilsson, p. 140

start = {(1,1):1, (1,2):2, (1,3):3, (2,1):4, (2,2):'B', (2,3):5,\
         (3,1):6, (3,2):7, (3,3):8}\

# what is your goal state?
goal = {(1,1):1, (1,2):2, (1,3):3, (2,1):6, (2,2):4, (2,3):5, (3,1):7, (3,2):'B', (3,3):8}

blank_at = (2,2)


def print_puzz8(puzz):
    print "\n"
    for i in range(3):
        for j in range(3):
            print "%s " % puzz[(i+1,j+1)],
        print "\n"
    print "\n"

# returns True or False

# puzz8_equal(puzz1, puzz2):
#.....


# returns a positive integer;
# number of tiles out of place in puzz relative to the goal (global)

#def puzz8_eval(puzz):
#    #.....


# returns a list of puzzle states that can be reached by a single
# move of the blank;



#def puzz8_successors(puzz):
# ....



def move_blank_down(puzz):
    global blank_at
    blanktile_no = puzz[blank_at]
    brow = blank_at[0]
    bcol = blank_at[1]

    if brow >= 3:
        return -1

    tilebelow_no = puzz[brow+1,bcol]

    temp = blanktile_no
    puzz[(brow,bcol)] = tilebelow_no
    puzz[(brow+1,bcol)] = temp

    blank_at = (brow+1, bcol)
    return


    

    
    
    
# test all functions by loading them into idle and make functions calls
# that will demonstrate that correctness of the code; 


rectangle1 = Rectangle(Point(0,0), Point(200,200)) #top left
rectangle1.draw(win)
text1 = Text(Point(100,100), start[(1,1)])
text1.draw(win)
rectangle2 = Rectangle(Point(200,0), Point(400,200)) #top mid
rectangle2.draw(win)
text2 = Text(Point(300,100), start[(1,2)])
text2.draw(win)
rectangle3 = Rectangle(Point(400,0), Point(600,200)) #top right
rectangle3.draw(win)
text3 = Text(Point(500,100), start[(1,3)])
text3.draw(win)
rectangle4 = Rectangle(Point(0,200), Point(200,400)) #mid left
rectangle4.draw(win)
text4 = Text(Point(100,300), start[(2,1)])
text4.draw(win)
rectangle5 = Rectangle(Point(200,200), Point(400,400)) #mid mid
rectangle5.draw(win)
text5 = Text(Point(300,300), start[(2,2)])
text5.draw(win)
rectangle6 = Rectangle(Point(400,200), Point(600,400)) #mid right
rectangle6.draw(win)
text6 = Text(Point(500,300), start[(2,3)])
text6.draw(win)
rectangle7 = Rectangle(Point(0,400), Point(200,600)) #btm left
rectangle7.draw(win)
text7 = Text(Point(100,500), start[(3,1)])
text7.draw(win)
rectangle8 = Rectangle(Point(200,400), Point(400,600)) #btm mid
rectangle8.draw(win)
text8 = Text(Point(300,500), start[(3,2)])
text8.draw(win)
rectangle9 = Rectangle(Point(400,400), Point(600,600)) #btm right
rectangle9.draw(win)
text9 = Text(Point(500,500), start[(3,3)])
text9.draw(win)
