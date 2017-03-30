class matrixChainMultiplication {
	//matrices are 4X10 10X3 3X12 12X20 20X7
	static int p[] = {20, 10, 5, 35, 45, 5, 10, 15};
	//length of the p array
	static int n=p.length;
	//table of multiplication values
	static int M[][] = new int[n][n];
	//auxillary table to hold choosen k values
	static int B[][] = new int[n][n];
 
	//helper method to rpint brackets
	static void print(int i, int j){
		if(j-i == 1){
			System.out.print("("+i+"*"+j+")");
			return ;
		}
		else if(j-i ==0){
			System.out.print(i);
			return ;
		}
		int k = B[i][j];
		System.out.print("(");
		print(i,k);
		print(k+1,j);
		System.out.print(")");
	}
 
 
	public static void main(String[] args) {
 
		//no need to initialise M[i][i] = 0 
		//because by default the whole array 
		//is filled with zeros
 
		//chain size
		for(int l=2;l<n;l++)
			//start index
			for(int i=1;i<n-l+1;i++){
				//end index
				int j=i+l-1;
				int min = Integer.MAX_VALUE;
				//k value where we will split the matrices
				//(i... k)(k+1... j)
				for(int k=i;k<j;k++){
					//cost of  left mult. + right mult.
					int current = M[i][k]+M[k+1][j]
							//cost of multiplaying left by right
							+p[i-1]*p[k]*p[j];
					if(current < min){
						min = current;
						B[i][j]= k;
					}
				}
				M[i][j] = min;
			}
		//print the result of multiplaying matrices from 1 to n
		System.out.println(M[1][n-1]);
		//print the bracketed values
		print(1, n-1);
	}
}