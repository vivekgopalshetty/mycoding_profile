 #include<bits/stdc++.h>
using namespace std;


int zero_one(int weights[],int profits[],int capacity,int n)
{
    if(capacity<0)
    {
        return 0;
    }
    int numberOfRows = n + 1;// adding a dummy row to avoid array index issues
    int dp[numberOfRows][capacity + 1];// Create a 2D Array to store all the results

    for (int i = 0; i < numberOfRows; i++) { // Insert 0 in 1st column as it is dummy column to avoid array index issues
			dp[i][0] = 0;
		}

		for (int i = 0; i <= capacity; i++) {// Insert 0 in last row as it is dummy column to avoid array index issues
			dp[numberOfRows - 1][i] = 0;
		}

		for (int row = numberOfRows - 2; row >= 0; row--) {
			for (int column = 1; column <= capacity; column++) {
				int profit1 = 0, profit2 = 0;
				if (weights[row] <= column) { // column represents current capacity
					profit1 = profits[row] + dp[row + 1][column - weights[row]];  // Taking current element
				}
				profit2 = dp[row + 1][column]; // Not taking current element
				dp[row][column] = max(profit1, profit2);
			}
		}//end of loop
		return dp[0][capacity];
}

int main()
{
    int n;
    cin>> n;

    int weights[n];
    int profits[n];

    for(int i=0;i<n;i++)
    {
        cin >> weights[i];
    }

    for(int i=0;i<n;i++)
    {
        cin >> profits[i];
    }

    int x;
    cin >> x;

    cout << zero_one(weights,profits,x,n);
}
