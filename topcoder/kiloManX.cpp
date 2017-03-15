

#include<iostream>
#include<queue>
#include<vector>
#include<string>

class node {
public:
  node(int w, int s):weapons(w),shots(s){}
  int weapons;
  int shots;
 
};

// TODO: priority_queue's comparison function
bool operator<( const node & n1, const node & n2){ 
  if ( n1.shots < n2.shots) return false;
  return true;
}


class KiloManX{
public:
  
  int leastShots(std::vector<std::string> damageChart, std::vector<int> bossHealth) {
    std::priority_queue<node > pq;
    std::vector<bool> visited (32768, false);
    int numWeapons = damageChart[0].size();
    pq.push(node(0, 0)); // construct a pseudo node as a starting point, with 0 shot and edges with weight 1
    while (pq.empty() == false) {
      node top = pq.top();
      pq.pop();

      if (visited[top.weapons]) continue; // the weapon is used
      visited[top.weapons] = true;

      if (top.weapons == (1 << numWeapons) - 1) return top.shots; // base case, all the weapons are used

      for (int i = 0; i < damageChart.size(); i++) {
	if ((top.weapons >> i) & 1) continue; 
	int best = bossHealth[i];
	for (int j = 0; j < damageChart.size(); j++) {
	  if (i == j) continue;
	  if (((top.weapons >> j) & 1) && damageChart[j][i] != '0') {
	    int shotsNeeded = bossHealth[i] / (damageChart[j][i] - '0');
	    if (bossHealth[i] % (damageChart[j][i] - '0') != 0) shotsNeeded++; // one more shot to end the boss 
	    best = std::min(best, shotsNeeded);
	  }
	}
	pq.push(node(top.weapons | (1 << i), top.shots + best));
      }
    }
    return -1;
  }
};

int main(){
  std::vector<std::string> dc = {"070","500","140"};
  std::vector<int> bh =  {150,150,150};
  KiloManX a ;
  std::cout<<a.leastShots(dc, bh)<<std::endl;
  return 0;
}




/*


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


*/
