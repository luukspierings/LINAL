#include "Graph.h"
#include <map>


void Graph::aStarTo(Vertex * start, Vertex * end)
{

	//map<Vertex*, int> queue; // Open list
	//map<Vertex*, Vertex*> visited; // Closed list

	//queue[start] = 0;

	//while (queue.size() != 0)
	//{
	//	var sortedQueue = queue.OrderBy(x = > x.Value).ToDictionary(pair = > pair.Key, pair = > pair.Value);
	//	Room pivot = sortedQueue.Keys.First();
	//	int weight = sortedQueue.Values.First();
	//	queue.Remove(pivot);
	//	pivot.searched = true;


	//	if (pivot.roomType == 'E')
	//	{
	//		String path = "";
	//		while (currentRoom != pivot)
	//		{

	//			if (pivot == visited[pivot].northRoom) path = " - Noord" + path;
	//			if (pivot == visited[pivot].eastRoom) path = " - Oost" + path;
	//			if (pivot == visited[pivot].southRoom) path = " - Zuid" + path;
	//			if (pivot == visited[pivot].westRoom) path = " - West" + path;

	//			pivot.cheapestRoute = true;
	//			pivot = visited[pivot];

	//		}

	//		if (path.Length > 0) path = path.Substring(3, path.Length - 3);
	//		return path;
	//	}

	//	if (pivot.northRoom != null && !pivot.collapsedNorth && !visited.ContainsKey(pivot.northRoom))
	//	{
	//		visited.Add(pivot.northRoom, pivot);
	//		queue.Add(pivot.northRoom, weight + pivot.northRoom.enemies);
	//	}
	//	if (pivot.eastRoom != null && !pivot.collapsedEast && !visited.ContainsKey(pivot.eastRoom))
	//	{
	//		visited.Add(pivot.eastRoom, pivot);
	//		queue.Add(pivot.eastRoom, weight + pivot.eastRoom.enemies);

	//	}
	//	if (pivot.southRoom != null && !pivot.collapsedSouth && !visited.ContainsKey(pivot.southRoom))
	//	{
	//		visited.Add(pivot.southRoom, pivot);
	//		queue.Add(pivot.southRoom, weight + pivot.southRoom.enemies);
	//	}
	//	if (pivot.westRoom != null && !pivot.collapsedWest && !visited.ContainsKey(pivot.westRoom))
	//	{
	//		visited.Add(pivot.westRoom, pivot);
	//		queue.Add(pivot.westRoom, weight + pivot.westRoom.enemies);
	//	}
	//}

	//return "";






}
