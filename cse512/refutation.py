# refutation.py
# by Kerstin Voigt, Nov 2014, for lab 8 of CSE 512

# resolution refutation in propositional logic
import random
import copy

MAXNODES = 10000

# too hard
S1 = [['A', 'C'], ['A', 'notC', 'B'], ['A', 'notC', 'notB'],\
      ['notA', 'B'], ['notA','noB']]

# to0 hard
S2 = [['notMgO','notH2O','Mg'],['notMgO','notH2O','H2O'],\
      ['notC', 'notO2', 'CO2'], ['notCO2','notH2O','H2CO3'],\
      ['MgO'], ['H2'], ['O2'], ['C'], ['notH2CO3']]

# too hard
S3 = [['notMgO','notH2O','Mg'],['notMgO','notH2O','H2O'],\
      ['notC', 'notO2', 'CO2'], ['MgO'], ['H2'], ['O2'], ['C'],\
      ['notMg', 'notH2O']]

# doable
S4 = [['notC', 'notO2', 'CO2'],['H2'], ['O2'], ['C'],\
      ['notCO2']]

# doable 
S5 = [['BAT_OK'], ['LIFTABLE'], ['notBAT_OK', 'notLIFTABLE', 'MOVES'],
      ['notMOVES']]

# global to give each Clause object a unique running number
CLAUSENO = 1

# clause in propositional logic consists of a list of literals
# (positive or negated); a unique number, and (if applicable) the
# numbers two Clauses which produced it via resolution; 

class Clause:
    def __init__(self,cl, k, pars = None):
        self.theclause = cl  # the list literals
        self.parents = pars  # the numbers of both parent clauses, or None
        self.no = k          # the number of this clause

    def __str__  (self):
        if self.parents == None:
            return "[%d]<*,*> %s" % (self.no, self.theclause)
        return "[%d]<%d,%d> %s" % (self.no, self.parents[0],\
                                   self.parents[1],self.theclause)

    # two Clauses are equal if their .theclause data members are equal
    def _eq__(self,other):
        if len(self.theclause) != len(other.theclause):
            return False
        for x in self.theclause:
            if not x in other.theclause:
                return  False
        return True


# stand-along functions

# from a list of sublists of literals (e.b., S1, S2, S3) produces a list
# of clauses

def clausify(s):
    global CLAUSENO
    setcl = []
    i = 1
    for x in s:
        setcl.append(Clause(x,i))
        i += 1
    CLAUSENO = len(setcl) + 1
    return setcl

# x and y are "literals"; here: strings with or without prefix 'not';
# x and y are opposites iff one has prefix 'not', the other does not,
# and x and y, stripped of prefix, are the same; e.g., 'notA' and 'A'
# are opposites;

def is_opposite (x,y):
    if x == y:
        return  False
    if x[:3] == 'not' and y[:3] == 'not':
        return False
    if x[:3] == 'not' and x[3:] == y or\
       y[:3] == 'not' and y[3:] == x:
        return  True
    return False

# two lists of literals, lst1 and lst2; is there an element ("literal")
# one list whose opposite appears in the other? if so, return a tuple of
# both opposite literals, else None; 

# LAB: implement this function

def has_opposites(lst1, lst2):
    for x in lst1:
        for y in lst2:
            # ... complete 

# combine two lists of literals, lst1 and lst2, while excluding the
# opposite literals in opps; return a new combined lists which does not
# have duplicate  literals; should the combination of lst1 and lst2
# result in a list that contains opposite literals, this function will
# return None; otherwise, returns the new list;
# Example:
#         [A, notB] and [A, B, notC] combine to [A, notC]
#         [A, notB] and [notA, B, notC] combine to None
#
# ... because [A, notA, notC] contains complementary A and notA
# ... theory behind this should be covered in class
#                               

# LAB: implement this funtion

def combine_without_opps(lst1, lst2, opps):
    l1 = lst1[:]
    l2 = lst2[:]
    # after having made copies of lst1 and lst2 to safeguard against
    # changes; mutable container structures are passed by reference (!)

    # .. complete ... use function has_opposites 
    
    return l3

# given literal x, return its opposite;
def oppos(x):
    if len(x) > 3 and x[:3] == 'not':
        return x[3:]
    else:
        return 'not'+x
         
# domain-specific function to solve the resolution refutatin problem by
# for graphsearch

# s is a set of Clauses; return True if s contains an empty clause; that is
# a Clause with [] as its .theclause data members;

def pl_solved (s):
    return [] in map(lambda x: x.theclause, s)

# s1 and s2 are two sets of Clauses; each clause one set, also occurrs in the
# other;

def pl_equal (s1,s2):
    if len(s1) != len(s2):
        return False
    for c1 in map(lambda x: x.theclause, s1):
        if not c1 in map(lambda x: x.theclause, s2):
            return False
    return True

# evaluation function: estimates remaining effort to obtain [] clause
# in s; here: the smallest number of literals among all Clauses in s;

def pl_eval(s):
    return len(min(s, key = lambda x: len(x.theclause)).theclause)

# given s, a set of Clauses, produce all successor sets of Clauses, each
# successor produced by adding all possible resolvents of two clauses to set
# s; 

def pl_successors(s):
    global CLAUSENO
    indeces = range(len(s))
    random.shuffle(s)
    s.sort(key = lambda x: len(x.theclause))
    nexts = copy.deepcopy(s)
    succs = []
    for i in indeces:
        for j in indeces[i+1:]:
            opps = has_opposites(s[i].theclause, s[j].theclause)
            if opps != None:
                si = s[i].theclause[:]
                sj = s[j].theclause[:]

                # LAB-fyi: here is your functions from above used
                
                sij = combine_without_opps(si, sj, opps)
                
                if sij != None and not sij in\
                   map(lambda x: x.theclause, s):
                    nexts = copy.deepcopy(s)
                    random.shuffle(sij)
                    newcl = Clause(sij,CLAUSENO,(s[i].no,s[j].no))
                    nexts.append(newcl)

                    #print "%s  +  %s => %s\n" % (s[i],s[j],newcl)
                    
                    CLAUSENO += 1
                    succs.append(nexts)
    #return [nexts]
    print "successors generated: %d" % len(succs)
    return succs
    
    

def pl_print(s):
    for x in s:
        print x
    print "\n"
    
# test all functions by loading them into idle and make functions calls
# that will demonstrate that correctness of the code; 

# mode = 1 -- sort by length of path (= depth of node); uniform-cost search
# mode = 2 -- sort by evalfct; best-first search
# mode = 3 -- sort by depth + evalfct; A* if evalfct is "admissible"

# print_info = 0 (default) -- minimal printing of info
# print_info = 1 -- 0 + prints current state as come from open
# print_info = 2 -- 1 + prints contents of open_lst

# "no path" version

def graphsearch_np(start,mode, equal_fct, solved_fct, eval_fct, succ_fct,\
                print_fct, print_info = 0):

    open_lst = [[0,start]]
    closed_lst = []
    nodecount = 0
    
    while open_lst != [] and nodecount < MAXNODES:
        curr0 = open_lst[0]
        curr = curr0[1]
        depth = curr0[0]
        open_lst = open_lst[1:]
        closed_lst.append(curr0)
        nodecount += 1

        if solved_fct(curr):
            if print_info > 0:
                print "\n\n Goal found!!" 
                #print_fct(curr)
            return curr

        succ = succ_fct(curr)
        for  s in succ:
            if not_on_lst(open_lst,s,equal_fct) and\
               not_on_lst(closed_lst,s,equal_fct):
                open_lst.append([depth+1,s])

        random.shuffle(open_lst)
        # sort open_lst according to mode
        if mode == 1:
            open_lst.sort(key = lambda x: x[0])
        elif mode == 2:
            open_lst.sort(key = lambda x: eval_fct(x[1]))
        else:
            open_lst.sort(key = lambda x: x[0] +eval_fct(x[1]))

    if print_info > 0:
        if nodecount >= MAXNODES:
            print "\n\nSearch exceeds maximum of %d nodes" % MAXNODES
        else:
            print "\n\nUnsolvable problem!"
            
    return False

def not_on_lst(lst,s,equal_fct):
    for x in lst:
        if equal_fct(x[1],s):
            return False
    return True


# s is assumed to be the list of clauses at the end of successful resolution
# refutation; at least one empty clause (a Clause object with .theclause equal
# to []) will exist in s;
# this function will extract all those clause in s that have led to the
# generation of the Clause with [];

# LAB: complete by filling in missing code

def extract_proof(s):
    proof = []
    # find the/Clause with .theclause == []; add this Clause to proof
    # and store this Clause's parent numbers; 
    for cl in s:
        
        # ... complete ...
        
    if pars != None:
        p1 = pars[0]
        p2 = pars[1]
        extract_clauses(s,p1,proof)
        extract_clauses(s,p2, proof)
    return proof

# this function is used by extract_proof; is is to accumulate into
# "output list" proof, all Clauses in s that have directly or indirectly
# led to the generation of the Clause with number no. 

# LAB: complete the function 

def extract_clauses(s,no,proof):
    if no == None:
        return
    
    found = None
    for cl in s:
        # find the Clause with number no
        # ... complete ... 
        
    proof.append(found)
    
    if found.parents  != None:
        # continue to extract and accumulate into proof, the parent
        # and ancester clauses that led to the generation of Clause found
        # hint: this can be done with CLEVER RECURSIVE FUNCTION CALLING
        # ... complete ... 

    return

def find_by_no(no,cls):
    for cl in cls:
        if cl.no == no:
            return cl
    return None

def show_proof(cls):
    show_proof_aux(cls[0],0,cls)

def show_proof_aux(cl,indent,cls):
    if cl == None:
        return
    for i in range(indent):
        print "__",
    print cl
    if cl.parents == None:
        return
    clp1 = find_by_no(cl.parents[0],cls)
    clp2 = find_by_no(cl.parents[1],cls)
    show_proof_aux(clp1,indent+1, cls)
    show_proof_aux(clp2,indent+1, cls)
    return


# set up for testing; selections 4 and 5 for initial sets S4 and S5
# are preferred; 

select = int(raw_input("RUNNING FOR WHICH SET: S1,S2,S3,S4,S5? [number] "))

myS = None

if select == 1:
    myS = S1
elif select == 2:
    myS = S2
elif select == 3:
    myS = S3
elif select == 4:
    myS = S4
else:
    myS = S5
    
mycls = clausify(myS)

print "\n\n"
for x in mycls:
    print x
print "\n\n"

# employ graphsearch to search through the space of possible refutations
# until the goal, a set of clauses with empty clause, is found

mysoln = graphsearch_np(mycls,3, pl_equal, pl_solved, pl_eval,\
                        pl_successors,pl_print, 1)

# extract the proof from mysoln (the clausal set with empty clause) and
# show is readable ASCII-text form;

show_proof(extract_proof(mysoln))
















                
        
