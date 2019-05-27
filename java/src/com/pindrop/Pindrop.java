package com.pindrop;

import java.util.ArrayList;

public class Pindrop {
// input [“DCA-SFO”, “DFW-DCA”, “LAX-ATL”, “SFO-LAX”]
// output ["DFW", "DCA", "SFO", "LAX", "ATL"]
// ASSUME FORMAT IS CORRECT
// ASSUME ITS A SINGLE CONT. TRIP
// ASSUME NO BRANCHES
// ASSUME NOT A CIRCLE
public static Object[] itinerary(String[] trips)
{
	ArrayList<String> output = new ArrayList<String>(trips.length + 1);
	ArrayList<Integer> mark = new ArrayList<Integer>();
	for( int i = 0; i < trips.length; i++)
	{
		if(!itineraryHelper(i, trips, output))
		{
			mark.add(i);
		}
	}
	while(mark.size() != 0)
	{
		Integer[] markArr = mark.toArray(new Integer[mark.size()]);
		for( int i = 0; i < mark.size(); i++)
		{
			if(itineraryHelper(markArr[i], trips, output))
			{
				mark.remove(i);
			}
		}
	}
	return output.toArray();
}

private static boolean itineraryHelper(int i, String[] trips, ArrayList<String> output)
{
	
		String[] nodes = trips[i].split("-");
		if(i == 0 && output.size() == 0)
		{
			output.add(nodes[0]);
			output.add(nodes[1]);
		}
		else if (output.get(0).equals(nodes[1]))
		{
			output.add(0, nodes[0]);
		}
		else if (output.get(output.size()-1).equals(nodes[0]))
		{
			output.add(nodes[1]);
		}
		else
		{
			return false;
		}
		return true;
}

}

