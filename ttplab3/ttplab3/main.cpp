#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool enter(string& k){
    bool f = true;
    while (f == true) {
        cout << "Enter the phone number: " << endl;
        cin >> k;
        if (k.length() == 15 ) f = false;
    }
    return true;
}


int pow (int n, int k){
    for (int i = 2; i < k; i ++){
        n *= n;
    }
    if (k == 0) n = 1;
    if (k == 1) n = n;
    return n;
}

int my_hash (string s){
    int t = 0;
    int p = 31;
    for (int i = 0; i < s.length(); i ++){
        t += s[i] * pow(p, i);
    }
    return t;
}

int main() {
    string line;
    ifstream in("/Users/ehet/Desktop/xcode projects/ttplab3/ttplab3/text.txt");
    int n = 7, t = 0, count = 0;
    int hash_k;
    string str0, str2, str3, str1, k;
    string str[n], string[n];
    
    int hash_num[n];
    
    if (in.is_open())
    {
        while (getline(in, line))
        {
            string[t] = line;
            str[t] = line.substr(57, 15);
            t++;
        }
    }
    in.close();
    
    for (int i = 0; i < n; i ++){
        hash_num[i] = my_hash(str[i]);
    }
    
    cout << "You should enter the phone number in format: +XXXX-XXX-XX-XX" << endl;
    enter(k);
    hash_k = my_hash(k);

    for (int i = 0; i < n; i ++){
        count++;
        if (hash_k == hash_num[i]){
            cout << string[i] << endl;
            count = 0;
        }
    }
    
    if (count == n) cout << "There's no people with this phone number" << endl;
    
    return 0;
}
