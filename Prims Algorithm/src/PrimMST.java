
import java.io.BufferedWriter;
import java.io.IOException;

public class PrimMST 
{
	public int numNodes;
	public int inWhichSet[];
	public undirectedEdge edgeListHead;
	public undirectedEdge MSTofG;
	public int totalMSTCost;
	
	public PrimMST(int n)
	{
		numNodes = n;
		inWhichSet = new int [n+1];
		for(int i=1; i < n+1; i++)
		{
		if(i==1)
		{
		inWhichSet[i] = 1;
		}
		else
		{
		inWhichSet[i] = 2;
		}
		}
		totalMSTCost = 0;
		edgeListHead = new undirectedEdge();
		MSTofG = new undirectedEdge();
	}
	
	public void insertEdge(undirectedEdge edge, undirectedEdge edgeListHead)
	{
		undirectedEdge current = edgeListHead;
		if(current.next == null)
		{
		current.next = edge;
		}
		else
		{
		while(current.next != null && current.next.edgeCost < edge.edgeCost)
		{
		current = current.next;
		}
		undirectedEdge swap = current.next;
		current.next = edge;
		edge.next = swap;
		}
	}
	
	public undirectedEdge removedEdge(undirectedEdge edge)
	{
		undirectedEdge current = edgeListHead;
		undirectedEdge remEdge;
		while(current.next != null && inWhichSet[current.Ni]==inWhichSet[current.Nj])
		{
		current = current.next;
		}
		remEdge = new undirectedEdge(current.Ni, current.Nj, current.edgeCost);
		return remEdge;
	}
	
	public void pushEdge(undirectedEdge edge, undirectedEdge MSTofG)
	{
		undirectedEdge current = MSTofG;
		while(current.next != null)
		{
		current = current.next;
		}
		edge.next = current.next;
		current.next = edge;
	}
	
	public void move2SetA(int node)
	{
		inWhichSet[node] = 1;
	}
	
	public void printSet(int[] inWhichSet, BufferedWriter outFile)
	{
		try
		{
			outFile.write("(Debug) inWhichSet: " + "\n");
			for(int i=1; i< numNodes+1; i++)
			{
			//outFile.write("inWhichSet["+i+"]" + inWhichSet[i] +
				
			//"\n" 
				//);
				outFile.write(inWhichSet[i] + " ");
			}
			outFile.write("\n");
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
		
	}
	
	public void printList(undirectedEdge edgeListHead, BufferedWriter outFile)
	{
		try
		{
			undirectedEdge current = edgeListHead;
			while(current != null)
			{
				if(current.next == null)
				{
					outFile.write("<" + current.Ni + "," +
					current.Nj + "," + current.edgeCost + ">" + "\n" );
				}
				else
				{
					outFile.write("<" + current.Ni + "," +
					current.Nj + "," + current.edgeCost + ">" + "\n" );
				}
				current = current.next;
			}
			outFile.write("\n");
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
	}
	
	public boolean check()
	{
		for(int i =1;i<numNodes+1;i++)
		{
			if(inWhichSet[i] == 2)
			{
				return true;
			}
		}
		return false;
	}
}
