/**
 * \brief brute force problem 1
 * \details compile and execute
 * $ clang++ -o picnic picnic.cpp
 * $ ./picnic < picnic_input.txt
 * You can change 'picnic_input.txt' yourself. 
 * \author Andrew Chang
 * \date 2020-09-27
 * \version 1.0.0
 */

#include <iostream>

#define MAX_TEST_CASE 50
#define MAX_STUDENT_COUNT 10
#define MAX_STUDENT_FRIEND_PAIR_COUNT ((MAX_STUDENT_COUNT) * ((MAX_STUDENT_COUNT) - 1) / 2)

using namespace std;

int n, m;
bool pair[MAX_STUDENT_FRIEND_PAIR_COUNT][MAX_STUDENT_FRIEND_PAIR_COUNT];

int set_pair(int index, bool check[]) {
    if(index >= n) {
        return 1;
    } else if (check[index] == true) {
        return 0;
    }
    int count = 0, i;
    for(i=index+1; i<n; ++i) {
        if(pair[index][i] == true && check[i] == false) {
	    check[index] = check[i] = true;
	    count += set_pair(index+1);
	    check[index] = check[i] = false;
	}	
    }
    return count;
}

int main(int argc, char *argv[])
{
    // Fast input/output speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j, test_count;
    cin >> test_count >> n >> m;

    for(i=0; i<test_count; ++i) {
        for(j=0; j<m; ++j) {
	    int friend1, friend2;
	    cin >> friend1 >> friend2;
	    pair[friend1][friend2] = pair[friend2][friend1] = true;
	}
	cout << set_pair(0) << "\n";
    }

    return 0;
}
