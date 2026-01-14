#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer = {1, 0};
    int larger = n > m ? n : m;
    int smaller = n + m - larger;
    for(int i = 2; i <= larger; i)
    {
        if(larger % i == 0 && smaller % i == 0)
        {
            larger /= i;
            smaller /= i;
            answer[0] *= i;
            i = 2;
            continue;
        }
        i++;
    }
    answer[1] = larger * smaller * answer[0];
    return answer;
}