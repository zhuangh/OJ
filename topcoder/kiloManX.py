
import heapq
import math
class node(object):
    def __init__(self, weapons, shots):
        self.weapons = weapons
        self.shots = shots
    def __lt__(self,other): # Note this for heapq in python
        return (self.shots < other.shots)

class KiloManX(object):
    def leastShots(self, damageChart, bossHealth):
        pq = []
        node_it = node(0,0)
        heapq.heappush(pq, node_it)
        visit = []
        m = len(damageChart)
        n = len(damageChart[0])
        nn = 1 << 15 
        for i in range(nn):
            visit.append(False)

        while pq:
            node_it = heapq.heappop(pq)
            if visit[node_it.weapons ] == True:
                pass 
            if (node_it.weapons == (1<<n)-1) : return node_it.shots
            visit[ node_it.weapons ] == True
            
            for itm in range(0,m):
                if ((node_it.weapons >> itm) & 1 ) == 1 : pass 
                best = bossHealth[itm]
                for itn in range(0,n):
                     if itm == itn : pass
                     if ((node_it.weapons >> itn) & 1 == 1 ) and damageChart[itn][itm] != '0' :
                         harm = int( damageChart[itn][itm]) - int('0')
                         #print(damageChart[itm][itn])
                         #print(harm)
                         shot = math.floor(bossHealth[itm]/harm)
                         if bossHealth[itm] %  harm  != 0 :
                             shot += 1
                         best = min(best, shot)
                #print(node_it.weapons | (1<<itn))
                node_itt = node( (node_it.weapons | (1<<itm)) , node_it.shots+best)
                #print(node_itt.shots)
                heapq.heappush(pq, node_itt)
            #print(len(pq))
        return -1
                         
                    

#damageChart = ["070","500","140"]
#bossHealth = [150,150,150]
damageChart = ["198573618294842", "159819849819205", "698849290010992", "000000000000000", "139581938009384", "158919111891911", "182731827381787", "135788359198718", "187587819218927", "185783759199192", "857819038188122", "897387187472737", "159938981818247", "128974182773177", "135885818282838"]
bossHealth = [157, 1984, 577, 3001, 2003, 2984, 5988, 190003, 9000, 102930, 5938, 1000000, 1000000, 5892, 38]

#damageChart = ["1542", "7935", "1139", "8882"]
#bossHealth = [150,150,150,150]

a = KiloManX()
print(a.leastShots(damageChart, bossHealth))


"""

Problem Statement
    
The KiloMan series has always had a consistent pattern: you start off with one (rather weak) default weapon, and then defeat some number of bosses. When you defeat a boss, you then acquire his weapon, which can then be used against other bosses, and so on. Usually, each boss is weak against some weapon acquired from another boss, so there is a recommended order in which to tackle the bosses. You have been playing for a while and wonder exactly how efficient you can get at playing the game. Your metric for efficiency is the total number of weapon shots fired to defeat all of the bosses.
You have a chart in front of you detailing how much damage each weapon does to each boss per shot, and you know how much health each boss has. When a boss's health is reduced to 0 or less, he is defeated. You start off only with the Kilo Buster, which does 1 damage per shot to any boss. The chart is represented as a vector <string>, with the ith element containing N one-digit numbers ('0'-'9'), detailing the damage done to bosses 0, 1, 2, ..., N-1 by the weapon obtained from boss i, and the health is represented as a vector <int>, with the ith element representing the amount of health that boss i has.
Given a vector <string> damageChart representing all the weapon damages, and a vector <int> bossHealth showing how much health each boss has, your method should return an int which is the least number of shots that need to be fired to defeat all of the bosses.
Definition
    
Class:
KiloManX
Method:
leastShots
Parameters:
vector <string>, vector <int>
Returns:
int
Method signature:
int leastShots(vector <string> damageChart, vector <int> bossHealth)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
damageChart will contain between 1 and 15 elements, inclusive.
-
each element of damageChart will be of the same length, which will be the same as the number of elements in damageChart.
-
each element of damageChart will contain only the characters '0'-'9'.
-
bossHealth will contain between 1 and 15 elements, inclusive.
-
damageChart and bossHealth will contain the same number of elements.
-
each element in bossHealth will be between 1 and 1000000, inclusive.
Examples
0)

    
{"070","500","140"}
{150,150,150}
Returns: 218
The best way to go is to use the KiloBuster to defeat boss 2 (indexed from 0), then use the weapon from boss 2 to defeat boss 1, and then use the weapon from boss 1 to defeat boss 0. This leads to total damage of 150 + 38 + 30 = 218.
1)

    
{"1542", "7935", "1139", "8882"}
{150,150,150,150}
Returns: 205
Defeat boss 2, use his weapon to defeat boss 3, and then use boss 3's weapon to defeat both bosses 0 and 1, for a total shot count of 150 + 17 + 19 + 19 = 205. It would be more efficient to defeat boss 1 with his own weapon, but it would be cheating to get his weapon before defeating him.
2)

    
{"07", "40"}
{150,10}
Returns: 48

3)

    
{"198573618294842",
 "159819849819205",
 "698849290010992",
 "000000000000000",
 "139581938009384",
 "158919111891911",
 "182731827381787",
 "135788359198718",
 "187587819218927",
 "185783759199192",
 "857819038188122",
 "897387187472737",
 "159938981818247",
 "128974182773177",
 "135885818282838"}
{157, 1984, 577, 3001, 2003, 2984, 5988, 190003,
9000, 102930, 5938, 1000000, 1000000, 5892, 38}
Returns: 260445

4)

    
{"02111111", "10711111", "11071111", "11104111",
 "41110111", "11111031", "11111107", "11111210"}
{28,28,28,28,28,28,28,28}
Returns: 92

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
"""
