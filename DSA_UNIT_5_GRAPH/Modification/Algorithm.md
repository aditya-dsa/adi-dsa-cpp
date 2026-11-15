Start the program.



Read the number of substations n.



Create an adjacency list of size n + 1.



Read the number of power lines m.



Read each power line (u, v) and add the connection in both directions:
- Add v to adj[u].
- Add u to adj[v].



Ask the user whether they want to add a new substation.



If the choice is Y:
- Increase n by 1.
- Resize the adjacency list.
- Display the new substation number.
- Read the number of power lines to add.
- Read each connection and validate the substation numbers.
- If valid and u != v, add the connection in both directions.
- Otherwise, display an invalid connection message and ask again.



Display the updated graph representation.



Identify isolated substations:
- Check whether each adjacency list is empty.
- If empty, display that the substation has no connections.



Calculate the degree of each substation using adj[i].size().



Sort the substations in descending order of degree.
- If two substations have equal degrees, arrange them in ascending order of substation number.



Display the sorted substations with their degrees.



Stop the program.
