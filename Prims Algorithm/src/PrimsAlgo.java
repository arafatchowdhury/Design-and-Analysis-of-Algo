
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
public class PrimsAlgo {
	
	public static void main(String[] args) 
	{
		try
		{
			Scanner inFile = new Scanner(new FileReader(args[0]));
			BufferedWriter outFile1, outFile2;
			outFile1 = new BufferedWriter(new FileWriter(new File(args[1])));
			outFile2 = new BufferedWriter(new FileWriter(new File(args[2])));
			if(args.length<1)
			{
				System.out.println("Error");
				System.exit(1);
			}
			
			int numNodes = inFile.nextInt();
			PrimMST pr = new PrimMST(numNodes);
			undirectedEdge newEdge;
			int Ni, Nj, edgeCost;
			pr.printSet(pr.inWhichSet, outFile2);

			while(inFile.hasNext())
			{
				Ni = inFile.nextInt();
				Nj = inFile.nextInt();
				edgeCost = inFile.nextInt();
				newEdge = new undirectedEdge(Ni,Nj, edgeCost);
				pr.insertEdge(newEdge, pr.edgeListHead);
				pr.printList(pr.edgeListHead, outFile2);
			}
			
			undirectedEdge nextEdge;
			while(pr.check())
			{
				do
				{
					nextEdge = pr.removedEdge(pr.edgeListHead);
					//System.out.println(nextEdge.Ni + " " + nextEdge.Nj + " "+ nextEdge.edgeCost + " remoeved");
					
				}
				while(pr.inWhichSet[nextEdge.Ni] == pr.inWhichSet[nextEdge.Nj]);
				pr.pushEdge(nextEdge, pr.MSTofG);
				pr.totalMSTCost += nextEdge.edgeCost;
				if(pr.inWhichSet[nextEdge.Ni] == 1)
				{
					pr.move2SetA(nextEdge.Nj);
				}
				else
				{
				pr.move2SetA(nextEdge.Ni);
				}
				pr.printSet(pr.inWhichSet, outFile2);
				pr.printList(pr.MSTofG, outFile2);
			}
			outFile1.write("Entire MSTofG with Respective Cost" + "\n");
			pr.printList(pr.MSTofG, outFile1);
			outFile1.write("Total Cost: "+ pr.totalMSTCost);
			inFile.close();
			outFile1.close();
			outFile2.close();
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
	}
}
