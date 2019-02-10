
public class undirectedEdge 
{
	public int Ni;
	public int Nj;
	public int edgeCost;
	public undirectedEdge next;
	
	public undirectedEdge() 
	{
		Ni = 0;
		Nj = 0;
		edgeCost = 0;
		next = null;
	}
	
	public undirectedEdge(int i, int j, int cost) 
	{
		Ni = i;
		Nj = j;
		edgeCost = cost;
		next = null;
	}
}