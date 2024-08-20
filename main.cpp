/*
������� 1. ���������� ����������
��� ����� �������
�������� ��������� ����������� ����������.
�� ���� ��������� ��������� ������� ��� �����:
69-70-30 Ivanov � �������� ������� � ������� �������� � ����������
69-70-30 � ������ ������� �������� �� ������ ��������
Ivanov � ������ ������� �������� �� �������
���������� �������� � ������� ����� �� ������� 2 � 3. �������� ��������, ��� �������� �� ������ ������� ����� ����� ���������� �������. 
� ����� ������ �� ������ 3 ���������� ������ ��� ������ ����� �������.
�������� �������� ������ �������� �� O(logn) ��� O(logn ? ���������� ������� � ���� ��������).

���-���� ��� �������� ������
� ��������� ��������� ������� ������� � ������ �������.
� ��������� ���������� ������ ������������ ����� <iostream>, <string>, <map> �, ��������, ������.

��� ��������� ������� �� ��������
�������� ������ �� repl.it ��� ���� .��� � �������� ����� ����� ��� ����� ��������� �������.
*/

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");

    map<string,string> telephone_book;

    
    cout << "������� ������:" << endl;
    string request;
    getline(cin, request);

    while (request != "stop"){

        if (request[0] >='0' && request[0] <='9'){
            if (request[request.size()-1] >= '0' && request[request.size()-1] <='9'){
                if (telephone_book.count(request))
                    cout << telephone_book[request] << endl;
                else {
                    cout << "� ����������� ��� ������ ������" << endl;
                }
            }
            else {
                string number = "", surname = "";
                int index = 0;
                while (request[index] != ' '){
                    number += request[index];
                    ++index;
                }
                surname = request.substr(index+1);
                telephone_book.insert(pair<string,string>(number,surname));
                cout << "����� � ������� ���������" << endl;
            }
        }
        else {
            vector<string> find_surnames;
            for (map<string,string>::iterator it = telephone_book.begin(); it != telephone_book.end(); ++it){
                if (it->second == request){
                    find_surnames.push_back(it->first);
                }
            }
            if (find_surnames.size() == 0){
                cout << "� ����������� ��� ����� �������" << endl;
            }
            else {
                for (int i=0; i<find_surnames.size(); ++i){
                    cout << find_surnames[i] << endl;
                }
            }
        }
    cout << "������� ������ (��� \"stop\" ��� ������):" << endl;
    getline(cin, request);

    }
}