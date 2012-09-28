

import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class Solution {
	public static int getMultiplicity(int i,int N){
		int duplicate=N,multiplictiy=0;
		while(duplicate!=0){
			multiplictiy+=duplicate/i;
			duplicate=duplicate/i;
		}
		return (2*multiplictiy+1);
	}
	public static void computeNoOfFactors(int multiplicity[]){
		BigInteger result= new BigInteger("1");
		String str[]= new String[multiplicity.length];
		Arrays.fill(str," ");
		for(int i=2;i<multiplicity.length;i++){
			str[i]= Integer.toString(multiplicity[i]);
		}
		BigInteger b[]= new BigInteger[multiplicity.length];
		Arrays.fill(b,new BigInteger("1"));
		for(int i=2;i<str.length;i++){
			b[i]= new BigInteger(str[i]);
		}
		for( int i=2;i<b.length;i++){
			if(b[i].equals(new BigInteger("-1")));
			else{
				result= result.multiply(b[i]).mod(new BigInteger("1000007"));
		
			}
		}
		System.out.println(result.mod(new BigInteger("1000007")));
	}
	public static void computePrimeMultiplicity(int primes[],int N){
		int multiplicity[]= new int[primes.length];
		Arrays.fill(multiplicity,-1);
		for(int i=2;i<primes.length;i++){
			if(primes[i]==1){
				multiplicity[i]= getMultiplicity(i,N);
			}
		}

		computeNoOfFactors(multiplicity);
	}
	public static int[] generatePrimes(int N){
		int primes[]= new int[N+1];
		//int primes[]= new int[((int)Math.ceil(N/2))+1];
		Arrays.fill(primes,1);
		for(int i=2;i*i<=N;i++){
			if(primes[i]==1){
				for(int j=i;j*i<=N;j++){
					primes[j*i]=0;
				}
			}
		}

		return primes;
	}
	public static void main(String args[]) throws Exception{
		Scanner sc= new Scanner(System.in);
		int N=sc.nextInt();
		int primes[]=generatePrimes(N);
		computePrimeMultiplicity(primes,N);
	}
}
