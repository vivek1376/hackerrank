#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector <unsigned long int> X;
    unsigned int N, K;
    unsigned long int val, unfairness = -1; //max
    cin >> N >> K;

    while (N--)
    {
        cin >> val;
        X.push_back (val);
    }
    sort (X.begin(), X.end());

    vector<unsigned long int>::size_type i = 0;

    for (vector<unsigned long int>::size_type ix = K - 1; ix != X.size(); ++ix, ++i) //or ix!=N
    {
        if ( (X[ix] - X[i]) < unfairness)
            unfairness = X[ix] - X[i];
    }

    cout << unfairness;
    return 0;
}
