/*

Cat Got Bored <@_@>

*/

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;
//import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main{
	
	static int dp[];
	static int m;
	static int n;
	static int t;
	
	static int rec(int t)
	{
		
		int mn = Math.min(m, n);
		int mx = Math.max(m, n);
		dp[mn] = dp[mx] = 1;
		for(int x = mn;x<=t;x++)
		{
			if(dp[x]>0)
			{
			if(mn+x<=t)dp[mn+x] = Math.max(dp[mn+x], dp[x]+1);
			if(mx+x<=t)dp[mx+x] = Math.max(dp[mx+x], dp[x]+1);
			}
		}
		int ans = 0;
		if(dp[t]>0){
			System.out.println(dp[t]);
			return ans=dp[t];
		}
		for(int i = 1;i<=t;i++)
		{
			if(i==t){
				System.out.println(0+" "+t);
				return 0;
				
			}
			if(dp[t-i]>0)
			{
				System.out.println(dp[t-i]+" "+i);
				return ans = dp[t-i];
			}
		}
		
		return 1;
		
	}
	 public static void main(String[] args) {
	      //fastScanner fs = new fastScanner();
	      //To simulate EOF
	      out = new PrintWriter(new BufferedOutputStream(System.out));

	      // Usage-------------------------------------

	      /**
	      int n      = fs.nextInt();        // read input as integer
	      long k     = fs.nextLong();       // read input as long
	      double d   = fs.nextDouble();     // read input as double
	      String str = fs.next();           // read input as String
	      String s   = fs.nextLine();       // read whole line as String




	      out.println();                    // print from PrintWriter
	      **/
	      Scanner sc = new Scanner(System.in);
	      
	      dp = new int[10009];
	      
	      //Non DP solution Trial
	      while(sc.hasNext())
	      {
	    	  
	    	  m = sc.nextInt();
	    	  n = sc.nextInt();
	    	  t = sc.nextInt();
	    	  
	    	  for(int i = 0;i<10009;i++)
	    		  dp[i]=0;
	 
	    	  
	    	 
	    	   rec(t);
	    
	    	  
	    	  
	      }
	      
	      




	      // Stop writing your solution here. -------------------------------------
	      out.close();
	   }



	   //-----------PrintWriter for faster output---------------------------------
	   public static PrintWriter out;

	   //-----------FastScanner class for faster input----------
	   public static class fastScanner {
	      BufferedReader BuffRead;
	      StringTokenizer StrToc;

	      public fastScanner() {
	         BuffRead = new BufferedReader(new InputStreamReader(System.in));
	      }

	      String next() {
	          while (StrToc == null || !StrToc.hasMoreElements()) {
	              try {
	                  StrToc = new StringTokenizer(BuffRead.readLine());
	              } catch (IOException e) {
	                  e.printStackTrace();
	              }
	          }
	          return StrToc.nextToken();
	      }

	      int nextInt() {
	          return Integer.parseInt(next());
	      }

	      long nextLong() {
	          return Long.parseLong(next());
	      }

	      double nextDouble() {
	          return Double.parseDouble(next());
	      }
	      /*
	      BigInteger nextBigInteger(){
	    	  return new BigInteger(next().toString());
	      }
	      */
	      String nextLine(){
	          String str = "";
		  try {
		     str = BuffRead.readLine();
		  } catch (IOException e) {
		     e.printStackTrace();
		  }
		  return str;
	      }

	   }
	   //--------------------------------------------------------

}
