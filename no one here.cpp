#include <iostream>
#include <string>
using namespace std;

string encrypt(string text, int key) {
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if (isupper(c))
            text[i] = ((c - 'A' + key) % 26) + 'A';
        else if (islower(c))
            text[i] = ((c - 'a' + key) % 26) + 'a';
    }
    return text;
}

string decrypt(string text, int key) {
    return encrypt(text, 26 - key);
}

int main() {
    int choice, key;
    string message;
    
    do {
        system("cls");
        
        // MASUKA ????? ??????
        cout << "\n";
        cout << "  =======================================\n";
        cout << "  |                                     |\n";
        cout << "  |     M   M   AAA   SSSS   U   U      |\n";
        cout << "  |     MM MM  A   A  S      U   U      |\n";
        cout << "  |     M M M  AAAAA   SSS   U   U      |\n";
        cout << "  |     M   M  A   A      S  U   U      |\n";
        cout << "  |     M   M  A   A  SSSS    UUU       |\n";
        cout << "  |                                     |\n";
        cout << "  |         C A E S A R   C I P H E R   |\n";
        cout << "  =======================================\n";
        cout << "\n";
        cout << "  1. Encrypt\n";
        cout << "  2. Decrypt\n";
        cout << "  3. Exit\n";
        cout << "  Choose (1-3): ";
        cin >> choice;
        
        if (choice == 3) break;
        
        cout << "  Key (1-25): ";
        cin >> key;
        if (key < 1 || key > 25) {
            cout << "  Key must be 1-25\n";
            system("pause");
            continue;
        }
        
        cin.ignore();
        cout << "  Message: ";
        getline(cin, message);
        
        if (choice == 1)
            cout << "\n  Result: " << encrypt(message, key) << endl;
        else if (choice == 2)
            cout << "\n  Result: " << decrypt(message, key) << endl;
        
        cout << "\n  Press Enter...";
        cin.ignore();
        cin.get();
        
    } while (true);
    
    return 0;
}
