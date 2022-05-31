#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int issubstr (string s1, string s2){
    int m = s1.length();
    int n = s2.length();
    for (int i = 0; i <= n - m; i++){
        int j;
        for (j = 0; j < m; j++){
            if(s2[i + j] != s1[j]){
                break;
            }
        }
        if (j == m){
            return i;
        }
    }
    return -1;
}

int main() {
    string line, filename, f;
    filename.clear();
    int n = 0, t = 0, l = 0, size = 100;
    string str[size];
    char ch;
    
    cout << " Enter the full path to the file: " << endl;
    //cin >> filename;
    filename = "/Users/ehet/Desktop/xcode projects/10labttp/10labttp/text.txt";
    cout << filename << endl;
    l = filename.length();
    fstream file(filename);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            str[n] = line;
            n++;
        }
    }
    file.close();
    
    cout << "|-------------------------------------------------------------|" << endl;
    cout << "|If you want to open the file, enter '1'.                     |" << endl;
    cout << "|-------------------------------------------------------------|" << endl;
    cout << "|If you want to see file extension, enter '2'.                |" << endl;
    cout << "|-------------------------------------------------------------|" << endl;
    cout << "|If you want to save file, enter '3'.                         |" << endl;
    cout << "|-------------------------------------------------------------|" << endl;
    cout << "|If you want to find symbol(s) in file, enter '4'.            |" << endl;
    cout << "|-------------------------------------------------------------|" << endl;
    cout << "|If you want to paste to the beginning of the file, enter '5'.|" << endl;
    cout << "|-------------------------------------------------------------|" << endl;
    cout << "|If you want to paste to the ending of the file, enter '6'.   |" << endl;
    cout << "|-------------------------------------------------------------|" << endl;
    cout << "|If you want to end this programm, enter '0'.                 |" << endl;
    cout << "|-------------------------------------------------------------|" << endl;
    
    cin >> ch;
    
    while(ch != '0'){
        if (ch == '1'){
            file.open(filename);
            cout << "File is open." << endl;
            for (int i = 0; i <= n; i++){
                cout << str[i] << endl;
            }
            cout << "Enter the number again:" << endl;
            cin >> ch;
        }
        else if (ch == '2'){
            string ext;
            ext = filename.substr(l - 4);
            cout << "File extension: '" << ext << "'." << endl;
            cout << "Enter the number again:" << endl;
            cin >> ch;
        }
        else if (ch == '3'){
            if (file.is_open()){
                
                file.open(filename, ios::out | ios::trunc);// очистка содержимого перед сохранением, чтобы текст не дублировался
                file.close();
                
                file.open(filename);
                for (int i = 0; i <= n; i++){
                    file << str[i] << endl;
                }
                cout << "File is saved!" << endl;
            }
            else {
                cout << "File is not open, please firstly open the file." << endl;
            }
            cout << "Enter the number again:" << endl;
            cin >> ch;
        }
        else if (ch == '4'){
            cout << "Enter the symbol(s), you'd like to find:" << endl;
            cin >> f;
            int count = 0;
            
            for (int k = 0; k < n; k ++){
                if (issubstr(f, str[k]) > 0){
                    count ++;
                }
            }
            if (count > 0){
                cout << "'" << f << "' is in the text" << endl;
            }
            else {
                cout << "'" << f << "' is not in the text" << endl;
            }
            
            f.clear();
            
            cout << "Enter the number again:" << endl;
            cin >> ch;
        }
        else if (ch == '5'){
            if (file.is_open()){
                string beg;
                cout << "Enter the phrase you want to past int the begining:" << endl;
                cin >> beg;
                n += 1;
                for (int i = n; i >= 1; i--){
                    str[i] = str[i-1];
                }
                str[0] = beg;
            }
            else {
                cout << "File is not open, please firstly open the file." << endl;
            }
            cout << "Enter the number again:" << endl;
            cin >> ch;
        }
        else if (ch == '6'){
            if (file.is_open()){
                string end;
                cout << "Enter the phrase you want to past int the ending:" << endl;
                cin >> end;
                n += 1;
                str[n] = end;
            }
            else {
                cout << "File is not open, please firstly open the file." << endl;
            }
            cout << "Enter the number again:" << endl;
            cin >> ch;
        }
        else if (ch == '0'){
            exit(0);
        }
        else {
            cout << "Wrong input! Enter the number again:" << endl;
            cin >> ch;
        }
    }
    
    file.close();
    return 0;
}
