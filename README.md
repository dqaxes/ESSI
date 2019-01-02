Consider a city with buildings shown in two dimensional space. 
The x axis denotes the left and right wall co-ordinate of each building.
And y axis denotes the height of the building.
A building is represented by triplet left wall x-cordinat#right wall x-cordinate#height. For example, first building in the map attached
is given as 1#3#10.
Buildings are overlapping and our job is to find out outline of the buildings two dimensional map. There will be walls of 
some buildings overlapped by other buildings making them invisible.
This program calculates the co-ordinates of outline formed by building edges when triplets of buildings are input in any order.
For example, considering the map attached, 
Buildings are input to program as:
1#10#3
4#4#10
6#11#8
2#15#5
7#8#9
The buldings need not be in order from left to right as per their left wall co-ordinates. They can be input in any order.

The outline coordinates output by progam will be:
1#0
1#10
2#15
5#4
6#11
8#8
9#4
10#0

TO TEST THE PROGRAM:
first line of input: no of buildings
second line: left wall co-ord#right wall coord#height of first building (Not necessarily leftmost building.. it can be in any order)
thrid line:  left wall co-ord#right wall coord#height of second building.
and so on..

eg.
INPUT:
5
1#10#3
4#4#10
6#11#8
2#15#5
7#8#9

OUTPUT:
1#0 
1#10
2#15
5#4
6#11
8#8
9#4
10#0
