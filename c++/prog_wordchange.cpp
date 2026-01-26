#include <string>
#include <vector>

using namespace std;
bool visited[50];
int min_answer = 50;

bool check(string cur, string word) {
    int count = 0;
    for (int i = 0; i < cur.size(); i++) {
        if (cur[i] != word[i]) count++;
    }
    if (count == 1) {
        return true;
    } else {
        return false;
    }
}

void dfs(string start, string target, vector<string> words, int count) {
    if (start == target) {
        min_answer = min(min_answer, count);
        return;
    }
    for (int i = 0; i < words.size(); i++) {
        if (!visited[i] && check(start ,words[i])) {
            visited[i] = true;
            dfs(words[i], target, words, count+1);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int no_answer = 0;
    for (string a : words) {
        if (target == a) no_answer = 1;
    }
    if (no_answer == 0) {
        return 0;
    }
    dfs(begin, target, words, 0);
    
    if (min_answer == 50) {
        return 0;
    } else {
        answer = min_answer;
    }
    return answer;
}