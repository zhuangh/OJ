/*
   Problem Statement
    
You've reached one of the last bosses in the new hit 2-D side-scrolling action game, KiloMan. The boss has a large gun that can shoot projectiles at various heights. For each shot, KiloMan can either stand still or jump. If he stands still and the shot is at height 1 or 2, then he gets hit. If he jumps and the shot is at a height above 2, then he is also hit. Otherwise, he is not hit. Given the height of each shot and a sequence of jumps, how many hits will KiloMan take?
The input vector <int> pattern is the pattern of heights at which the shots are being fired. Each element of pattern will be between 1 and 7, inclusive. The input string jumps is the sequence of jumps that KiloMan will attempt; 'J' means he will jump and 'S' means he will stand still. For example, if element 0 of pattern is 3 and character 0 of jumps is 'J', then KiloMan will jump right as a shot is fired at height 3 (and thus he will be hit).
Your method should return an int representing the number of times KiloMan is hit.
Definition
    
Class:
KiloMan
Method:
hitsTaken
Parameters:
vector <int>, string
Returns:
int
Method signature:
int hitsTaken(vector <int> pattern, string jumps)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
pattern will contain between 1 and 50 elements, inclusive.
-
each number in pattern will be between 1 and 7, inclusive.
-
the number of characters in jumps will be the same as the number of elements in pattern
-
each character of jumps will be either 'S' or 'J'.
Examples
0)

    
{1,3,2,3,3,1,2,2,1}
"JJSSSJSSJ"
Returns: 4
The first shot is at height 1, and KiloMan jumps it successfully. Then he jumps into a shot at height 3. KiloMan takes three more hits while standing against shots at height 2.
1)

    
{1,1,1,1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,3,3,3,4,4,4,4,
 4,4,4,5,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7}
"SSSSSSSSSSSSSSJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ"
Returns: 49
KiloMan stands still at all the wrong times and jumps at all the wrong times, taking all 49 hits.
2)

    
{1,2,2,1}
"SJJS"
Returns: 2
Since everything was shot at height 2 or less, he should have jumped everything.
3)

    
{1}
"J"
Returns: 0

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */


