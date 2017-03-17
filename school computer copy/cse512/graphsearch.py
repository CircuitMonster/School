# graphsearch.py
# introducing the notion of costs associated with links; various forms of
# heuristic graphsearch: Dijkstra, Best-First, A*;

import random

# for each state, there are one or more successor states
net = {(20,20):[(460,20),(20,180)], (460,20):[(460,460)], (20,180):[(20,340),(160,180)],\
       (20,340):[(160,340)], (160,180):[(160,100),(160,340)], (160,100):[(320,100)],\
       (320,100):[(320,340)], (160,340):[(320,340),(160,440)], (160,440):[(80,440),(260,440)],\
       (320,340):[(380,340),(320,460)],(380,340):[(380,220),(380,460)], (380,460):[(460,460)],\
       (320,460):[(380,460)]}

# for each link, there is a cost
linkcost = {(None, (20,20)):0,((20,20),(460,20)):445,((20,20),(20,180)):170, ((460,20),(460,460)):440, ((20,180),(20,340)):165, ((20,180),(160,180)):155,\
       ((20,340),(160,340)): 160, ((160,180),(160,100)):85, ((160,180),(160,340)):180, ((160,100),(320,100)):165,\
       ((320,100),(320,340)):260, ((160,340),(320,340)):180, ((160,340),(160,440)):110, ((160,440),(80,440)):80,((160,440),(260,440)):100,\
       ((320,340),(380,340)):75, ((320,340),(320,460)):125, ((380,340),(380,220)):120, ((380,340),(380,460)):125, ((380,460),(460,460)):80,\
       ((320,460),(380,460)):65}
                                                                  
start = (20,20)
goals = [(460,460), (80,440),  (260,440), (380,220)]

def traverseA(start,net,mode="bfs"):
    open_lst = [start]
    closed_lst = []

    count = 1
    while open_lst != []:
        curr = open_lst[0]
        open_lst = open_lst[1:]
        # if curr is on closed, then it's a box that has already been opened
        # no need to record its opening again
        if not curr in closed_lst:
            closed_lst.append(curr)
        print "[step-%d] %s\n" % (count, curr)
        if net.has_key(curr):
            succ = net[curr]
            for  s in succ:
                # put on list of those boxes yet to be opened if
                # it not already lined up for opening, and not
                # already openend at an earlier time
                if not s in open_lst and not s in closed_lst:
                    if mode == "bfs":
                        open_lst.append(s)
                    elif mode == "dfs":
                        open_lst = [s] + open_lst
        #print "[open-%d] %s" % (count, open_lst)
        #print "[clos-%d] %s\n" % (count, closed_lst)
        count += 1

def traverseB(start,net,mode="bfs"):
    open_lst = [start]
    closed_lst = []

    count = 1
    while open_lst != []:
        curr = open_lst[0]
        open_lst = open_lst[1:]
        if not curr in closed_lst:
            closed_lst.append(curr)
        print "[step-%d] %s\n" % (count, curr)
        if net.has_key(curr):
            succ = net[curr]
            for  s in succ:
                if not s in open_lst: #and not s in closed_lst:
                    if mode == "bfs":
                        open_lst.append(s)
                    elif mode == "dfs":
                        open_lst = [s] + open_lst
        #print "[open-%d] %s" % (count, open_lst)
        #print "[clos-%d] %s\n" % (count, closed_lst)
        count += 1

# stop when first goal found;

def searchA(start,net,mode="bfs"):
    open_lst = [start]
    closed_lst = []

    count = 1
    while open_lst != []:
        curr = open_lst[0]
        open_lst = open_lst[1:]
        if not curr in closed_lst:
            closed_lst.append(curr)

        if curr in goals:
            print"Goal %d,%d found!\n" % (curr[0],curr[1])
            return curr
        
        print "[step-%d] %s\n" % (count, curr)
        if net.has_key(curr):
            succ = net[curr]
            for  s in succ:
                if not s in open_lst and not s in closed_lst:
                    if mode == "bfs":
                        open_lst.append(s)
                    elif mode == "dfs":
                        open_lst = [s] + open_lst
        print "[open-%d] %s" % (count, open_lst)
        print "[clos-%d] %s\n" % (count, closed_lst)
        count += 1


# random permute the nodes on open_lst
# stop when first goal is found

def searchB(start,net,mode="bfs"):
    open_lst = [start]
    closed_lst = []

    count = 1
    while open_lst != []:
        curr = open_lst[0]
        open_lst = open_lst[1:]
        random.shuffle(open_lst)
        if not curr in closed_lst:
            closed_lst.append(curr)

        if curr in goals:
            print"Goal %d,%d found!\n" % (curr[0],curr[1])
            return curr
        
        print "[step-%d] %s\n" % (count, curr)
        if net.has_key(curr):
            succ = net[curr]
            for  s in succ:
                if not s in open_lst and not s in closed_lst:
                    if mode == "bfs":
                        open_lst.append(s)
                    elif mode == "dfs":
                        open_lst = [s] + open_lst
        print "[open-%d] %s" % (count, open_lst)
        print "[clos-%d] %s\n" % (count, closed_lst)

        count += 1

# stop when first goal is found;
# also provide solution path, extracted from closed_lst
# store node as [parent,state]

def searchC(start,net,mode="bfs"):
    open_lst = [[None,start]]
    closed_lst = []

    count = 1
    while open_lst != []:
        curr0 = open_lst[0]
        curr = curr0[1]
        open_lst = open_lst[1:]
        random.shuffle(open_lst)
        if not curr in map(lambda x: x[1], closed_lst):
            closed_lst.append(curr0)

        if curr in goals:
            print"Goal %d,%d found!\n" % (curr[0],curr[1])
            return search_path(curr0,closed_lst)
        
        print "[step-%d] %s\n" % (count, curr)
        if net.has_key(curr):
            succ = net[curr]
            for  s in succ:
                if not s in open_lst and not s in closed_lst:
                    if mode == "bfs":
                        open_lst.append([curr,s])
                    elif mode == "dfs":
                        open_lst = [[curr,s]] + open_lst
        print "[open-%d] %s" % (count, open_lst)
        print "[clos-%d] %s\n" % (count, closed_lst)
        count += 1


# given goal state and closed list generated by
# search, reconstruct the path to the goal from
# the starting state

def search_path(goal,closed):
    parent = goal[0]
    state = goal[1]
    path = [goal[1]]
    cost = linkcost[(parent,state)]
    while parent != None:
        for [p,x] in closed:
            if parent == x:
                path = [x] + path
                cost += linkcost[(p,x)]
                parent = p
                break
    return (path,cost)


# search to reach all goals along all possible paths
# store node as [path,state]
# observe the order in which paths are emerge

def searchD(start,net,mode="bfs"):
    open_lst = [[[start],start]]
    closed_lst = []
    count = 1
    pathcount = 0
    while open_lst != []:
        curr0 = open_lst[0]
        curr = curr0[1]
        pth = curr0[0]
        open_lst = open_lst[1:]
        closed_lst.append(curr0)

        if curr in goals:
            pathcount += 1
            pcost = path_cost(pth)
            print "%d. Goal %d,%d found!\n" % (pathcount,curr[0],curr[1])
            print "Path: %s [len=%d, cost=%d]" % (pth,len(pth),pcost)
            print "\n\n"
        
        #print "[step-%d] %s ->%s\n" % (count, pth, curr)

        if net.has_key(curr):
            succ = net[curr]
            for  s in succ:
                newpth = pth[:] + [s]
                if mode == "bfs":
                    open_lst.append([newpth,s])
                elif mode == "dfs":
                    open_lst = [[newpth,s]] + open_lst
        
        #print "[open-%d]" % count
        #for x in open_lst:
        #    print x
        #print "\n"
        #print "[clos-%d]" % count
        #for x in closed_lst:
        #    print x
        #print "\n\n"
        count += 1    

 # given a path (= sequence of states), compute the
 # total  cost of the path a sum of all links between states
 
def path_cost(path):
    if path == [] or len(path) == 1:
        return 0
    frm = path[0]
    to = path[1]
    return linkcost[(frm,to)] + path_cost(path[1:])


