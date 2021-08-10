#include <iostream>
using namespace std;

int knapsack(int W, int wt[], int ben[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w]
                        = max(ben[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int max(int a, int b)
{
    if(a>b)
            return a;
    else
            return b;
}

int recKnapsack(int W, int wt[], int ben[], int n)
{


if (n == 0 || W == 0)
    return 0;


if (wt[n-1] > W)
    return recKnapsack(W, wt, ben, n-1);


else return max( ben[n-1] + recKnapsack(W-wt[n-1], wt, ben, n-1),
                    recKnapsack(W, wt, ben, n-1) );
}


void main()
{
    cout << "Enter the number of objects :";
    int n, W;
    cin >> n;
    int ben[n], wt[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter benefit then weight for object " << i << ":";
        cin >> ben[i];
        cin >> wt[i];
    }
    cout << "Enter the maximum capacity of the knapsack:";
    cin >> W;
    cout << knapsack(W, wt, ben, n);
    //cout << recKnapsack(W, wt, ben, n);

}

